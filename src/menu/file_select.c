#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "audio/external.h"
#include "behavior_data.h"
#include "dialog_ids.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "eu_translation.h"
#include "file_select.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/ingame_menu.h"
#include "game/object_helpers.h"
#include "game/object_list_processor.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/segment2.h"
#include "game/segment7.h"
#include "game/spawn_object.h"
#include "gfx_dimensions.h"
#include "sm64.h"
#include "text_strings.h"

/**
 * @file file_select.c
 * This file implements how the file select and it's menus render and function.
 * That includes button IDs rendered as object models, strings, hand cursor,
 * special menu messages and phases, button states and button clicked checks.
 */

// NOTE: While EU multilanguage is fully decompiled, Isabelle 64 1.3 already has multilanguage
// working before it happened, and even then, some EU code seems like devs over complicated themselves
// while other code is useful (like soundMode), so my permutation is somewhat better

#ifdef VERSION_US
// The current sound mode is automatically centered on US due to
// the large length difference between options.
// sSoundTextY unused (EU supports its existance).
s16 sSoundTextX;
s16 sSoundTextY;
#endif

//! @Bug (UB Array Access) For PAL, more buttons were added than the array was extended.
//! This causes no currently known issues on console (as the other variables are not changed
//! while this is used) but can cause issues with other compilers.
#ifdef MULTILANGUAGE
    #ifdef AVOID_UB
        #define NUM_BUTTONS 40
    #else
        #define NUM_BUTTONS 34
    #endif
#else
#define NUM_BUTTONS 32
#endif

#ifdef VERSION_EU
// The current sound mode is automatically centered on US due to
// the large length difference between options.
// sSoundTextY unused
s16 sSoundTextX;
s16 sSoundTextY;
#endif
    
// Used to defined yes/no fade colors after a file is selected in the erase menu.
// sYesNoColor[0]: YES | sYesNoColor[1]: NO
u8 sYesNoColor[2];

// Unused variable that is written to for the centered X value for some strings.
#ifdef VERSION_EU
s16 sCenteredX;
#endif


// The button that is selected when it is clicked.
s8 sFileSelectMenuID = MENU_BUTTON_NONE;

// Used for text opacifying. If it is below 250, it is constantly incremented.
u8 sTextBaseAlpha = 0;

// 2D position of the cursor on the screen.
// sCursorPos[0]: X | sCursorPos[1]: Y
f32 sCursorPos[] = {0, 0};

// Determines which graphic to use for the cursor.
s16 sCursorClickingTimer = 0;

// Used for determining which file has been selected during copying and erasing.
s8 sSelectedFileIndex = -1;

// Whether to fade out text or not.
s8 sFadeOutText = FALSE;

// The message currently being displayed at the top of a menu.
s8 sStatusMessageID = 0;

s8 sStatusMessagePhase = -1;

// Used for text fading. The alpha value of text is calculated as
// sTextBaseAlpha - sTextFadeAlpha.
u8 sTextFadeAlpha = 0;

// File select timer that keeps counting until it reaches 1000.
// Used to prevent buttons from being clickable as soon as a menu loads.
// Gets reset when you click an empty save, existing saves in copy and erase menus
// and when you click yes/no in the erase confirmation prompt.
s16 sMainMenuTimer = 0;

// Sound mode menu buttonID, has different values compared to gSoundMode in audio.
// 0: gSoundMode = 0 (Stereo) | 1: gSoundMode = 3 (Mono) | 2: gSoundMode = 1 (Headset)
s8 sSoundMode = 0;

// PAL changes most text to arrays for each language. This define allows these
// differences to be combined.
#ifdef VERSION_EU
    #define LANGUAGE_ARRAY(cmd) cmd[sLanguageMode]
#else
    #define LANGUAGE_ARRAY(cmd) cmd
#endif

// Active language for PAL arrays.
#ifdef MULTILANGUAGE
s8 sLanguageMode = LANGUAGE_ENGLISH;
#endif

// Tracks which button will be pressed in the erase confirmation prompt (yes/no).
s8 sEraseYesNoHoverState = MENU_ERASE_HOVER_NONE;

// Used for the copy menu, defines if the game as all 4 save slots with data.
// if TRUE, it doesn't allow copying more files.
s8 sAllFilesExist = FALSE;

// Defines the value of the save slot selected in the menu.
// Mario A: 1 | Mario B: 2 | Mario C: 3 | Mario D: 4
s8 sSelectedFileNum = 0;

// Which coin score mode to use when scoring files. 0 for local
// coin high score, 1 for high score across all files.
s8 sScoreFileCoinScoreMode = 0;

// If no save file exists, open the language menu so the user can find it.
#ifdef MULTILANGUAGE
s8 sOpenLangSettings = FALSE;
#endif

#ifndef MULTILANGUAGE
unsigned char textReturn[] = { TEXT_RETURN };
#else 
unsigned char textReturn[][10]  = {{ TEXT_RETURN }, { TEXT_RETURN_FR }, { TEXT_RETURN_DE }, { TEXT_RETURN_IT }, { TEXT_RETURN_ES }};
#define textReturn textReturn[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textViewScore[] = { TEXT_CHECK_SCORE };
#else
unsigned char textViewScore[][13] = {{ TEXT_CHECK_SCORE }, { TEXT_CHECK_SCORE_FR }, { TEXT_CHECK_SCORE_DE }, { TEXT_CHECK_SCORE_IT }, { TEXT_CHECK_SCORE_ES }};
#define textViewScore textViewScore[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textCopyFileButton[] = { TEXT_COPY_FILE_BUTTON };
#else
unsigned char textCopyFileButton[][11] = {{ TEXT_COPY_FILE_BUTTON }, { TEXT_COPY_FILE_BUTTON_FR }, { TEXT_COPY_FILE_BUTTON_DE }, { TEXT_COPY_FILE_BUTTON_IT }, { TEXT_COPY_FILE_BUTTON_ES }};
#define textCopyFileButton textCopyFileButton[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textEraseFileButton[] = { TEXT_ERASE_FILE_BUTTON };
#else
unsigned char textEraseFileButton[][12] = { { TEXT_ERASE_FILE_BUTTON }, {TEXT_ERASE_FILE_BUTTON_FR}, { TEXT_ERASE_FILE_BUTTON_DE }, { TEXT_ERASE_FILE_BUTTON_IT }, { TEXT_ERASE_FILE_BUTTON_ES }};
#define textEraseFileButton textEraseFileButton[sLanguageMode]
#endif


#ifdef MULTILANGUAGE
unsigned char textSoundModes[][10] = {
    { TEXT_STEREO }, { TEXT_MONO }, { TEXT_HEADSET },
    { TEXT_STEREO_FR }, { TEXT_MONO_FR }, { TEXT_HEADSET_FR },
    { TEXT_STEREO_DE }, { TEXT_MONO_DE }, { TEXT_HEADSET_DE },
    { TEXT_STEREO_IT }, { TEXT_MONO_IT }, { TEXT_HEADSET_IT },
    { TEXT_STEREO_ES }, { TEXT_MONO_ES }, { TEXT_HEADSET_ES }
};
#else
unsigned char textSoundModes[][8] = { { TEXT_STEREO }, { TEXT_MONO }, { TEXT_HEADSET } };
#endif

#ifndef MULTILANGUAGE
unsigned char textMario[] = { TEXT_MARIO };
#else
unsigned char textMario[][9] = {{ TEXT_MARIO }, { TEXT_MARIO_FR }, { TEXT_MARIO_DE }, { TEXT_MARIO_IT }, { TEXT_MARIO_ES }};
#define textMario textMario[sLanguageMode]
#endif

unsigned char textFileLetter[] = { TEXT_ZERO };

#ifndef MULTILANGUAGE
unsigned char textMarioA[] = { TEXT_FILE_MARIO_A };
unsigned char textMarioB[] = { TEXT_FILE_MARIO_B };
unsigned char textMarioC[] = { TEXT_FILE_MARIO_C };
unsigned char textMarioD[] = { TEXT_FILE_MARIO_D };
#else
unsigned char textMarioA[][11] = {{ TEXT_FILE_MARIO_A }, { TEXT_FILE_MARIO_A_FR }, { TEXT_FILE_MARIO_A_DE }, { TEXT_FILE_MARIO_A_IT }, { TEXT_FILE_MARIO_A_ES }};
unsigned char textMarioB[][11] = {{ TEXT_FILE_MARIO_B }, { TEXT_FILE_MARIO_B_FR }, { TEXT_FILE_MARIO_B_DE }, { TEXT_FILE_MARIO_B_IT }, { TEXT_FILE_MARIO_B_ES }};
unsigned char textMarioC[][11] = {{ TEXT_FILE_MARIO_C }, { TEXT_FILE_MARIO_C_FR }, { TEXT_FILE_MARIO_C_DE }, { TEXT_FILE_MARIO_C_IT }, { TEXT_FILE_MARIO_C_ES }};
unsigned char textMarioD[][11] = {{ TEXT_FILE_MARIO_D }, { TEXT_FILE_MARIO_D_FR }, { TEXT_FILE_MARIO_D_DE }, { TEXT_FILE_MARIO_D_IT }, { TEXT_FILE_MARIO_D_ES }};    
#define textMarioA textMarioA[sLanguageMode]
#define textMarioB textMarioB[sLanguageMode]
#define textMarioC textMarioC[sLanguageMode]
#define textMarioD textMarioD[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textNew[] = { TEXT_NEW };
#else
unsigned char textNew[][6] = {{ TEXT_NEW }, { TEXT_NEW_FR }, { TEXT_NEW_DE }, { TEXT_NEW_IT }, { TEXT_NEW_ES }};
#define textNew textNew[sLanguageMode]
#endif

unsigned char starIcon[] = { GLYPH_STAR, GLYPH_SPACE };
unsigned char xIcon[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

#ifndef MULTILANGUAGE
unsigned char textSelectFile[] = { TEXT_SELECT_FILE };
#else
unsigned char textSelectFile[][17] = {{ TEXT_SELECT_FILE }, { TEXT_SELECT_FILE_FR }, { TEXT_SELECT_FILE_DE }, { TEXT_SELECT_FILE_IT }, { TEXT_SELECT_FILE_ES }};
#define textSelectFile textSelectFile[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textScore[] = { TEXT_SCORE };
#else
unsigned char textScore[][10] = {{ TEXT_SCORE }, { TEXT_SCORE_FR }, { TEXT_SCORE_DE }, { TEXT_SCORE_IT }, { TEXT_SCORE_ES }};
#define textScore textScore[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textCopy[] = { TEXT_COPY };
#else
unsigned char textCopy[][10] = {{ TEXT_COPY }, { TEXT_COPY_FR }, { TEXT_COPY_DE }, { TEXT_COPY_IT }, { TEXT_COPY_ES }};
#define textCopy textCopy[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textErase[] = { TEXT_ERASE };
#else
unsigned char textErase[][9] = {{ TEXT_ERASE }, { TEXT_ERASE_FR }, { TEXT_ERASE_DE }, { TEXT_ERASE_IT }, { TEXT_ERASE_ES }};
#define textErase textErase[sLanguageMode]
#endif

#ifndef MULTILANGUAGE
unsigned char textCheckFile[] = { TEXT_CHECK_FILE };
#else
unsigned char textOption[][10] = {{ TEXT_OPTION }, { TEXT_OPTION_FR }, { TEXT_OPTION_DE }, { TEXT_OPTION_IT }, { TEXT_OPTION_ES }};
unsigned char textOptionMenu[][19] = {{ TEXT_OPTIONS_MENU }, { TEXT_OPTIONS_MENU_FR }, { TEXT_OPTIONS_MENU_DE }, { TEXT_OPTIONS_MENU_IT }, { TEXT_OPTIONS_MENU_ES }};

unsigned char textCheckFile[][18] = {{ TEXT_CHECK_FILE }, { TEXT_CHECK_FILE_FR }, { TEXT_CHECK_FILE_DE }, { TEXT_CHECK_FILE_IT }, { TEXT_CHECK_FILE_ES }};
#define textOption textOption[sLanguageMode]
#define textCheckFile textCheckFile[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textNoSavedDataExists[] = { TEXT_NO_SAVED_DATA_EXISTS };
#else
unsigned char textNoSavedDataExists[][29] = {{ TEXT_NO_SAVED_DATA_EXISTS }, { TEXT_NO_SAVED_DATA_EXISTS_FR }, { TEXT_NO_SAVED_DATA_EXISTS_DE }, { TEXT_NO_SAVED_DATA_EXISTS_IT }, { TEXT_NO_SAVED_DATA_EXISTS_ES }};
#define textNoSavedDataExists textNoSavedDataExists[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textCopyFile[] = { TEXT_COPY_FILE };
#else
unsigned char textCopyFile[][16] = {{ TEXT_COPY_FILE }, { TEXT_COPY_FILE_FR }, { TEXT_COPY_FILE_DE }, { TEXT_COPY_FILE_IT }, { TEXT_COPY_FILE_ES }};
#define textCopyFile textCopyFile[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textCopyItToWhere[] = { TEXT_COPY_IT_TO_WHERE };
#else
unsigned char textCopyItToWhere[][19] = {{ TEXT_COPY_IT_TO_WHERE }, { TEXT_COPY_IT_TO_WHERE_FR }, { TEXT_COPY_IT_TO_WHERE_DE }, { TEXT_COPY_IT_TO_WHERE_IT }, { TEXT_COPY_IT_TO_WHERE_ES }};
#define textCopyItToWhere textCopyItToWhere[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textCopyCompleted[] = { TEXT_COPYING_COMPLETED };
#else
unsigned char textCopyCompleted[][18] = {{ TEXT_COPYING_COMPLETED }, { TEXT_COPYING_COMPLETED_FR }, { TEXT_COPYING_COMPLETED_DE }, { TEXT_COPYING_COMPLETED_IT }, { TEXT_COPYING_COMPLETED_ES }};
#define textCopyCompleted textCopyCompleted[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textSavedDataExists[] = { TEXT_SAVED_DATA_EXISTS };
#else
unsigned char textSavedDataExists[][23] = {{ TEXT_SAVED_DATA_EXISTS }, { TEXT_SAVED_DATA_EXISTS_FR }, { TEXT_SAVED_DATA_EXISTS_DE }, { TEXT_SAVED_DATA_EXISTS_IT }, { TEXT_SAVED_DATA_EXISTS_ES }};
#define textSavedDataExists textSavedDataExists[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textNoFileToCopyFrom[] = { TEXT_NO_FILE_TO_COPY_FROM };
#else
unsigned char textNoFileToCopyFrom[][21] = {{ TEXT_NO_FILE_TO_COPY_FROM }, { TEXT_NO_FILE_TO_COPY_FROM_FR }, { TEXT_NO_FILE_TO_COPY_FROM_DE }, { TEXT_NO_FILE_TO_COPY_FROM_IT }, { TEXT_NO_FILE_TO_COPY_FROM_ES }};
#define textNoFileToCopyFrom textNoFileToCopyFrom[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textEraseFile[] = { TEXT_ERASE_FILE };
#else
unsigned char textEraseFile[][17] = {{ TEXT_ERASE_FILE }, { TEXT_ERASE_FILE_FR }, { TEXT_ERASE_FILE_DE }, { TEXT_ERASE_FILE_IT }, { TEXT_ERASE_FILE_ES }};    
#define textEraseFile textEraseFile[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textYes[] = { TEXT_YES };
#else
unsigned char textYes[][4] = {{ TEXT_YES }, { TEXT_YES_FR }, { TEXT_YES_DE }, { TEXT_YES_IT }, { TEXT_YES_ES }};
#define textYes textYes[sLanguageMode] 
#endif

#ifndef MULTILANGUAGE
unsigned char textNo[] = { TEXT_NO };
#else
unsigned char textNo[][5] = {{ TEXT_NO }, { TEXT_NO_FR }, { TEXT_NO_DE }, { TEXT_NO_IT }, { TEXT_NO_ES }};
#define textNo textNo[sLanguageMode] 
#endif

#ifdef MULTILANGUAGE

unsigned char textSure[][9] = {{ TEXT_SURE }, { TEXT_SURE_FR }, { TEXT_SURE_DE }, { TEXT_SURE_IT }, { TEXT_SURE_ES }};
unsigned char textMarioAJustErased[][23] = {{ TEXT_FILE_MARIO_A_JUST_ERASED }, { TEXT_FILE_MARIO_A_JUST_ERASED_FR }, { TEXT_FILE_MARIO_A_JUST_ERASED_DE }, { TEXT_FILE_MARIO_A_JUST_ERASED_IT }, { TEXT_FILE_MARIO_A_JUST_ERASED_ES }};

// print_options_mode_menu_strings():
unsigned char textSoundSelect[][14] = {{ TEXT_SOUND_SELECT }, { TEXT_SOUND_SELECT_FR }, { TEXT_SOUND_SELECT_DE }, { TEXT_SOUND_SELECT_IT }, { TEXT_SOUND_SELECT_ES }};
unsigned char textLanguageSelect[][18] = {{ TEXT_LANGUAGE_SELECT }, { TEXT_LANGUAGE_SELECT_FR }, { TEXT_LANGUAGE_SELECT_DE }, { TEXT_LANGUAGE_SELECT_IT }, { TEXT_LANGUAGE_SELECT_ES }};

unsigned char textLanguage[][9] = {{ TEXT_ENGLISH }, { TEXT_FRENCH }, { TEXT_GERMAN }, { TEXT_ITALIAN }, { TEXT_ESPANOL }};

// print_save_file_scores():
unsigned char textHiScore[][15] = {{ TEXT_HI_SCORE }, { TEXT_HI_SCORE_FR }, { TEXT_HI_SCORE_DE }, { TEXT_HI_SCORE_IT }, { TEXT_HI_SCORE_ES }};
unsigned char textMyScore[][11] = {{ TEXT_MY_SCORE }, { TEXT_MY_SCORE_FR }, { TEXT_MY_SCORE_DE }, { TEXT_MY_SCORE_IT }, { TEXT_MY_SCORE_ES }};
#define textSure textSure[sLanguageMode] 
#define textMarioAJustErased textMarioAJustErased[sLanguageMode]
#define textSoundSelect textSoundSelect[sLanguageMode]
#define textLanguageSelect textLanguageSelect[sLanguageMode] 
#define textHiScore textHiScore[sLanguageMode] 
#define textMyScore textMyScore[sLanguageMode] 
#else
unsigned char textSure[] = { TEXT_SURE };
unsigned char textMarioAJustErased[] = { TEXT_FILE_MARIO_A_JUST_ERASED };
unsigned char textSoundSelect[] = { TEXT_SOUND_SELECT };
unsigned char textHiScore[] = { TEXT_HI_SCORE };
unsigned char textMyScore[] = { TEXT_MY_SCORE };
#endif

#define FADEOUT_TIMER 20

/**
 * Prints a hud string depending of the hud table list defined with text fade properties.
 */
void print_hud_lut_string_fade(s8 hudLUT, s16 x, s16 y, const u8 *text) {
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha - sTextFadeAlpha);
    print_hud_lut_string(hudLUT, x, y, text);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

/**
 * Prints a generic white string with text fade properties.
 */
void print_generic_string_fade(s16 x, s16 y, const u8 *text) {
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha - sTextFadeAlpha);
    print_generic_string(x, y, text);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

/**
 * Updates text fade at the top of a menu.
 */
s32 update_text_fade_out(void) {
    if (sFadeOutText == TRUE) {
        sTextFadeAlpha += 50;
        if (sTextFadeAlpha == 250) {
            sFadeOutText = FALSE;
            return TRUE;
        }
    } else {
        if (sTextFadeAlpha > 0) {
            sTextFadeAlpha -= 50;
        }
    }
    return FALSE;
}

extern Gfx dl_alo_file_select_save_slot[];

/**
 * Prints the amount of stars of a save file.
 * If a save doesn't exist, print "NEW" instead.
 */
void print_save_file_star_count(s8 fileIndex, s16 x, s16 y) {
    u8 starCountText[4];
    s16 starCount;
    s16 xNew;

    if (save_file_exists(fileIndex) == TRUE) {
        starCount = save_file_get_total_star_count(fileIndex, 0, 24);
        // Print star icon
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, starIcon);
        // If star count is less than 100, print x icon and move
        // the star count text one digit to the right.
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, xIcon);
        // Print star count
        int_to_str(starCount, starCountText);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, starCountText);
    } else {
        // Print "new" text
        xNew = get_str_x_pos_from_center_custom_hex(LUT_TYPE_STR_HEX, SCREEN_WIDTH / 2, textNew, 2);
        print_hud_lut_string(HUD_LUT_GLOBAL, xNew, y, textNew);
    }
}

/**
 * Prints main menu strings that shows on the yellow background menu screen.
 */
void print_main_menu_strings(void) {
    s16 xPos;

    // Print "SELECT FILE" text
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);

    print_hud_lut_string(HUD_LUT_DIFF, GFX_DIMENSIONS_FROM_LEFT_EDGE(8), 8, textSelectFile);

    // Print file star counts
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    
    // Print menu names
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);
    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(6);
    print_generic_string(xPos, 8, textScore);
    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(10 + get_string_width(textScore));
    print_generic_string(xPos, 8, textCopy);
    xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE((get_string_width(textOption) + get_string_width(textErase)) + 10);
    print_generic_string(xPos, 8, textErase);
    xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE(get_string_width(textOption) + 6);
    print_generic_string(xPos, 8, textOption);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define CHECK_FILE_X 90
#define NOSAVE_DATA_X1 90
#else
#define CHECK_FILE_X 95
#define NOSAVE_DATA_X1 99
#endif

/**
 * Defines IDs for the top message of the score menu and displays it if the ID is called in messageID.
 */
void score_menu_display_message(s8 messageID) {
    s16 xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(8);

    switch (messageID) {
        case SCORE_MSG_CHECK_FILE:
            print_hud_lut_string_fade(HUD_LUT_DIFF, xPos, 8, textCheckFile);
            break;
        case SCORE_MSG_NOSAVE_DATA:
            print_generic_string_fade(xPos, 216, textNoSavedDataExists);
            break;
    }
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define RETURN_X 45
#define COPYFILE_X1 128
#define ERASEFILE_X1 228
#else
#define RETURN_X 44
#define COPYFILE_X1 135
#define ERASEFILE_X1 231
#endif

/**
 * Prints score menu strings that shows on the green background menu screen.
 */
void print_score_menu_strings(void) {
    s16 xPos;

    // Update and print the message at the top of the menu.
    if (sMainMenuTimer == FADEOUT_TIMER) {
        sFadeOutText = TRUE;
    }

    if (update_text_fade_out() == TRUE) {
        if (sStatusMessageID == SCORE_MSG_CHECK_FILE) {
            sStatusMessageID = SCORE_MSG_NOSAVE_DATA;
        } else {
            sStatusMessageID = SCORE_MSG_CHECK_FILE;
        }
    }

    // Print messageID called above
    score_menu_display_message(sStatusMessageID);
    // Print menu names
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);
    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(6);
    print_generic_string(xPos, 8, textCopyFileButton);
    xPos = get_str_x_pos_from_center_custom_hex(LUT_TYPE_STR_HEX, (SCREEN_WIDTH / 2), textEraseFileButton, 2);
    print_generic_string(xPos, 8, textEraseFileButton);
    xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE(get_string_width(textReturn) + 6);
    print_generic_string(xPos, 8, textReturn);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define NOFILE_COPY_X 90
#define COPY_FILE_X 90
#define COPYIT_WHERE_X 90
#define NOSAVE_DATA_X2 90
#define COPYCOMPLETE_X 90
#define SAVE_EXISTS_X1 90
#else
#define NOFILE_COPY_X 119
#define COPY_FILE_X 104
#define COPYIT_WHERE_X 109
#define NOSAVE_DATA_X2 101
#define COPYCOMPLETE_X 110
#define SAVE_EXISTS_X1 110
#endif

/**
 * Defines IDs for the top message of the copy menu and displays it if the ID is called in messageID.
 */
void copy_menu_display_message(s8 messageID) {
    s16 xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(8);

    switch (messageID) {
        case COPY_MSG_MAIN_TEXT:
            if (sAllFilesExist == TRUE) {
                print_generic_string_fade(xPos, 216, textNoFileToCopyFrom);
            } else {
                print_hud_lut_string_fade(HUD_LUT_DIFF, xPos, 8, textCopyFile);
            }
            break;
        case COPY_MSG_COPY_WHERE:
            print_generic_string_fade(xPos, 216, textCopyItToWhere);
            break;
        case COPY_MSG_NOSAVE_EXISTS:
            print_generic_string_fade(xPos, 216, textNoSavedDataExists);
            break;
        case COPY_MSG_COPY_COMPLETE:
            print_generic_string_fade(xPos, 216, textCopyCompleted);
            break;
        case COPY_MSG_SAVE_EXISTS:
            print_generic_string_fade(xPos, 216, textSavedDataExists);
            break;
    }
}

/**
 * Updates messageIDs of the copy menu depending of the copy phase value defined.
 */
void copy_menu_update_message(void) {
    switch (sStatusMessagePhase) {
        case COPY_PHASE_MAIN:
            if (sMainMenuTimer == FADEOUT_TIMER) {
                sFadeOutText = TRUE;
            }
            if (update_text_fade_out() == TRUE) {
                if (sStatusMessageID == COPY_MSG_MAIN_TEXT) {
                    sStatusMessageID = COPY_MSG_NOSAVE_EXISTS;
                } else {
                    sStatusMessageID = COPY_MSG_MAIN_TEXT;
                }
            }
            break;
        case COPY_PHASE_COPY_WHERE:
            if (sMainMenuTimer == FADEOUT_TIMER && sStatusMessageID == COPY_MSG_SAVE_EXISTS) {
                sFadeOutText = TRUE;
            }
            if (update_text_fade_out() == TRUE) {
                if (sStatusMessageID != COPY_MSG_COPY_WHERE) {
                    sStatusMessageID = COPY_MSG_COPY_WHERE;
                } else {
                    sStatusMessageID = COPY_MSG_SAVE_EXISTS;
                }
            }
            break;
        case COPY_PHASE_COPY_COMPLETE:
            if (sMainMenuTimer == FADEOUT_TIMER) {
                sFadeOutText = TRUE;
            }
            if (update_text_fade_out() == TRUE) {
                if (sStatusMessageID != COPY_MSG_COPY_COMPLETE) {
                    sStatusMessageID = COPY_MSG_COPY_COMPLETE;
                } else {
                    sStatusMessageID = COPY_MSG_MAIN_TEXT;
                }
            }
            break;
    }
}

/**
 * Prints copy menu strings that shows on the blue background menu screen.
 */
void print_copy_menu_strings(void) {
    s16 xPos;
    // Update and print the message at the top of the menu.
    copy_menu_update_message();
    // Print messageID called inside a copy_menu_update_message case
    copy_menu_display_message(sStatusMessageID);
    // Print menu names
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);
    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(6);
    print_generic_string(xPos, 8, textViewScore);
    xPos = get_str_x_pos_from_center_custom_hex(LUT_TYPE_STR_HEX, (SCREEN_WIDTH / 2), textEraseFileButton, 2);
    print_generic_string(xPos, 8, textEraseFileButton);
    xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE(get_string_width(textReturn) + 6);
    print_generic_string(xPos, 8, textReturn);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

/**
 * Prints the "YES NO" prompt and checks if one of the prompts are hovered to do it's functions.
 */
void print_erase_menu_prompt(s16 x, s16 y) {
    s16 xArrow;
    s16 colorFade = gGlobalTimer << 12;

    handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, &sEraseYesNoHoverState, MENU_ERASE_HOVER_YES, MENU_ERASE_HOVER_NO);

    if (sEraseYesNoHoverState == MENU_ERASE_HOVER_YES) {
        // Fade "YES" string color but keep "NO" gray
        sYesNoColor[0] = sins(colorFade) * 50.0f + 205.0f;
        sYesNoColor[1] = 150;
        xArrow = x + 42;
    } else if (sEraseYesNoHoverState == MENU_ERASE_HOVER_NO) {
        // Fade "NO" string color but keep "YES" gray
        sYesNoColor[0] = 150;
        sYesNoColor[1] = sins(colorFade) * 50.0f + 205.0f;
        xArrow = x + 82;
    } else {
        xArrow = -16;
    }
    // If button is pressed...
    if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
        // ..and is hovering "YES", delete file
        if (sEraseYesNoHoverState == MENU_ERASE_HOVER_YES) {
            play_sound(SOUND_MARIO_WAAAOOOW, gDefaultSoundArgs);
            sStatusMessagePhase = ERASE_PHASE_MARIO_ERASED;
            sFadeOutText = TRUE;
            sMainMenuTimer = 0;
            save_file_erase(sSelectedFileIndex);
            // ..and is hovering "NO", return back to main phase
        } else if (sEraseYesNoHoverState == MENU_ERASE_HOVER_NO) {
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
            sStatusMessagePhase = ERASE_PHASE_MAIN;
            sFadeOutText = TRUE;
            sMainMenuTimer = 0;
            sEraseYesNoHoverState = MENU_ERASE_HOVER_NONE;
        }
    }
    // Print "YES NO" strings
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, sYesNoColor[0], sYesNoColor[0], sYesNoColor[0], sTextBaseAlpha);
    print_generic_string(x + 60, y, textYes);
    gDPSetEnvColor(gDisplayListHead++, sYesNoColor[1], sYesNoColor[1], sYesNoColor[1], sTextBaseAlpha);
    print_generic_string(x + 100, y, textNo);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    
    render_arrow_texture_menu(TRUE, ARROW_TEXTURE_SELECT, xArrow, 8);
}

/**
 * Defines IDs for the top message of the erase menu and displays it if the ID is called in messageID.
 */
void erase_menu_display_message(s8 messageID) {
    u8 letterIdx;
    s16 xPos;

    switch (sLanguageMode) {
        case LANGUAGE_ENGLISH:
            letterIdx = 9; // Isabelle A
            break;
        case LANGUAGE_FRENCH:
            letterIdx = 6; // Marie A
            break;
        case LANGUAGE_GERMAN:
            letterIdx = 8; // Melinda A
            break;
        case LANGUAGE_ITALIAN:
            letterIdx = 6; // Fuffi A
            break;
        case LANGUAGE_SPANISH:
            letterIdx = 7; // Canela A
            break;
    }

    switch (messageID) {
        case ERASE_MSG_MAIN_TEXT:
            xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(8);
            print_hud_lut_string_fade(HUD_LUT_DIFF, xPos, 8, textEraseFile);
            break;
        case ERASE_MSG_PROMPT:
            xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(32);
            print_generic_string_fade(xPos, 216, textSure);
            xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE(160);
            print_erase_menu_prompt(xPos, 216); // YES NO, has functions for it too
            break;
        case ERASE_MSG_NOSAVE_EXISTS:
            xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(8);
            print_generic_string_fade(xPos, 216, textNoSavedDataExists);
            break;
        case ERASE_MSG_MARIO_ERASED:
            xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(8);
            textMarioAJustErased[letterIdx] = sSelectedFileIndex + ASCII_TO_DIALOG('A');
            print_generic_string_fade(xPos, 216, textMarioAJustErased);
            break;
    }
}

/**
 * Updates messageIDs of the erase menu depending of the erase phase value defined.
 */
void erase_menu_update_message(void) {
    switch (sStatusMessagePhase) {
        case ERASE_PHASE_MAIN:
            if (sMainMenuTimer == FADEOUT_TIMER && sStatusMessageID == ERASE_MSG_NOSAVE_EXISTS) {
                sFadeOutText = TRUE;
            }
            if (update_text_fade_out() == TRUE) {
                if (sStatusMessageID == ERASE_MSG_MAIN_TEXT) {
                    sStatusMessageID = ERASE_MSG_NOSAVE_EXISTS;
                } else {
                    sStatusMessageID = ERASE_MSG_MAIN_TEXT;
                }
            }
            break;
        case ERASE_PHASE_PROMPT:
            if (update_text_fade_out() == TRUE) {
                if (sStatusMessageID != ERASE_MSG_PROMPT) {
                    sStatusMessageID = ERASE_MSG_PROMPT;
                }
            }
            break;
        case ERASE_PHASE_MARIO_ERASED:
            if (sMainMenuTimer == FADEOUT_TIMER) {
                sFadeOutText = TRUE;
            }
            if (update_text_fade_out() == TRUE) {
                if (sStatusMessageID != ERASE_MSG_MARIO_ERASED) {
                    sStatusMessageID = ERASE_MSG_MARIO_ERASED;
                } else {
                    sStatusMessageID = ERASE_MSG_MAIN_TEXT;
                }
            }
            break;
    }
}

/**
 * Prints erase menu strings that shows on the red background menu screen.
 */
void print_erase_menu_strings(void) {
    s16 xPos;
    // Update and print the message at the top of the menu.
    erase_menu_update_message();
    // Print messageID called inside a erase_menu_update_message case
    erase_menu_display_message(sStatusMessageID);
    // Print menu names
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);
    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(6);
    print_generic_string(xPos, 8, textViewScore);
    xPos = get_str_x_pos_from_center_custom_hex(LUT_TYPE_STR_HEX, (SCREEN_WIDTH / 2), textCopyFileButton, 2);
    print_generic_string(xPos, 8, textCopyFileButton);
    xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE(get_string_width(textReturn) + 6);
    print_generic_string(xPos, 8, textReturn);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

/**
 * Prints sound mode menu strings that shows on the purple background menu screen.
 */
void print_options_mode_menu_strings(void) {
    s16 sound;
    s16 lang;
    s16 xPos;
    u8 r, g, b;
    s16 yPos;

    // Print "SOUND SELECT" text
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);

    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(8);
    print_hud_lut_string(HUD_LUT_DIFF, xPos, 8, textOptionMenu[sLanguageMode]);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    // Print mode names
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE(get_string_width(textReturn) + 6);
    print_generic_string(xPos, 8, textReturn);
    
    // Sound Strings
    yPos = 158;
    for (sound = 0; sound < 3; sound++) {
        if (sound == sSoundMode) {
            r = 52; g = 166; b = 52;
        } else {
            r = 255; g = 255; b = 255;
        }
        print_generic_string_shadow(HEX_PRINT_CHR, 48, yPos, r, g, b, 255, NULL, textSoundModes[sLanguageMode * 3 + sound]);
        yPos -= 16;
    }
    
    print_generic_string_shadow(HEX_PRINT_CHR, 28, 178, 255, 255, 255, 255, NULL, textSoundSelect);
    
    // Language Strings
    yPos = 158;
    for (lang = 0; lang < 5; lang++) {
        if (lang == sLanguageMode) {
            r = 52; g = 166; b = 52;
        } else {
            r = 255; g = 255; b = 255;
        }
        print_generic_string_shadow(HEX_PRINT_CHR, 148, yPos, r, g, b, 255, NULL, textLanguage[lang]);
        yPos -= 16;
    }

    print_generic_string_shadow(HEX_PRINT_CHR, 128, 178, 255, 255, 255, 255, NULL, textLanguageSelect);
    
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

unsigned char textStarX[] = { TEXT_STAR_X };

/**
 * Prints castle secret stars collected in a score menu save file.
 */
void print_score_file_castle_secret_stars(s8 fileIndex, s16 x, s16 y) {
    unsigned char secretStarsText[20];
    // Print "[star] x"
    print_menu_generic_string(x, y, textStarX);
    // Print number of castle secret stars
    int_to_str(save_file_get_total_star_count(fileIndex, 15, 24), secretStarsText);
    print_menu_generic_string(x + 16, y, secretStarsText);
}

/**
 * Prints course coins collected in a score menu save file.
 */
void print_score_file_course_coin_score(s8 fileIndex, s16 courseIndex, s16 x, s16 y) {
    unsigned char coinScoreText[20];
    u8 stars = save_file_get_star_flags(fileIndex, courseIndex);
    unsigned char textCoinX[] = { TEXT_COIN_X };
    unsigned char textStar[] = { TEXT_STAR };

    // MYSCORE
    if (sScoreFileCoinScoreMode == 0) {
        // Print "[coin] x"
        print_menu_generic_string(x + 35, y, textCoinX);
        // Print coin score
        int_to_str(save_file_get_course_coin_score(fileIndex, courseIndex), coinScoreText);
        print_menu_generic_string(x + 51, y, coinScoreText);
        // If collected, print 100 coin star
        if (stars & (1 << 6)) {
            print_menu_generic_string(x + 80, y, textStar);
        }
    }
    // HISCORE
    else {
        // Print "[coin] x"
        print_menu_generic_string(x + 35, y, textCoinX);
        // Print coin highscore
        int_to_str((u16) save_file_get_max_coin_score(courseIndex) & 0xFFFF, coinScoreText);
        print_menu_generic_string(x + 51, y, coinScoreText);
    }
}

/**
 * Prints stars collected in a score menu save file.
 */
void print_score_file_star_score(s8 fileIndex, s16 courseIndex, s16 x, s16 y) {
    s16 i = 0;
    unsigned char starScoreText[20]; // unknown length
    u8 stars = save_file_get_star_flags(fileIndex, courseIndex);
    s8 starCount = save_file_get_course_star_count(fileIndex, courseIndex);
    // Don't count 100 coin star
    if (stars & (1 << 6)) {
        starCount--;
    }
    // Add 1 star character for every star collected
    for (i = 0; i < starCount; i++) {
        starScoreText[i] = DIALOG_CHAR_STAR_FILLED;
    }
    // Terminating byte
    starScoreText[i] = DIALOG_CHAR_TERMINATOR;
    print_menu_generic_string(x, y, starScoreText);
}

/**
 * Prints save file score strings that shows when a save file is chosen inside the score menu.
 */
void print_save_file_scores(s8 fileIndex) {
    s16 xPos;
    s16 courseNum;
    s8 tensDigPad;
    void **levelNameTable;
    
#ifdef MULTILANGUAGE
    switch (sLanguageMode) {
        case LANGUAGE_ENGLISH:
            levelNameTable = segmented_to_virtual(eu_course_strings_en_table);
            break;
        case LANGUAGE_FRENCH:
            levelNameTable = segmented_to_virtual(eu_course_strings_fr_table);
            break;
        case LANGUAGE_GERMAN:
            levelNameTable = segmented_to_virtual(eu_course_strings_de_table);
            break;
        case LANGUAGE_ITALIAN:
            levelNameTable = segmented_to_virtual(eu_course_strings_it_table);
            break;
        case LANGUAGE_SPANISH:
            levelNameTable = segmented_to_virtual(eu_course_strings_es_table);
            break;
    }
#else
    levelNameTable = segmented_to_virtual(seg2_course_name_table);
#endif

    textFileLetter[0] = fileIndex + ASCII_TO_DIALOG('A'); // get letter of file selected
    // Print file name at top
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);

    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(8);
    print_hud_lut_string(HUD_LUT_DIFF, xPos, 8, textMario);
    xPos = GFX_DIMENSIONS_FROM_LEFT_EDGE(get_hud_str_width(textMario) + 16);
    print_hud_lut_string(HUD_LUT_GLOBAL, xPos, 8, textFileLetter);
    // Print save file star count at top
    xPos = SCREEN_WIDTH / 2;
    print_save_file_star_count(fileIndex, xPos, 8);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    // Print course scores
    gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);

    for (courseNum = 1; courseNum < 16; courseNum++) { // BOB to RR
        courseNum >= 10 ? (tensDigPad = 0) : (tensDigPad = 1);

        print_menu_generic_string(GFX_DIMENSIONS_FROM_LEFT_EDGE(8) + (tensDigPad * 3), 
            23 + 11 * courseNum, segmented_to_virtual(levelNameTable[courseNum - 1]));
            
        print_score_file_star_score(fileIndex, courseNum - 1, 170, 22 + 11 * courseNum); 
        print_score_file_course_coin_score(fileIndex, courseNum - 1, GFX_DIMENSIONS_FROM_RIGHT_EDGE(100), 23 + 11 * courseNum);
    }

    // Print level name
    print_menu_generic_string(GFX_DIMENSIONS_FROM_LEFT_EDGE(8), 199, segmented_to_virtual(levelNameTable[25]));
    // Print castle secret stars
    print_score_file_castle_secret_stars(fileIndex, 171, 199);
    // Print current coin score mode
    if (sScoreFileCoinScoreMode == 0) {
        xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE((get_string_width(textMyScore) / 2) + 24);
        print_menu_generic_string(xPos, 24, textMyScore);
    } else {
        xPos = GFX_DIMENSIONS_FROM_RIGHT_EDGE((get_string_width(textHiScore) / 2) + 24);
        print_menu_generic_string(xPos, 24, textHiScore);
    }

    gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_end);
}

u8 sTexSaveSlotColor[3];
u8 sFileSelectBgColor[4];
u8 sIsMenuButtonSelected = FALSE;
s16 sBgMainMenuTimer = 0;

s8 sMenuSaveSlotOption = 0;
s8 sIsTitleScreenActive = TRUE;
s8 sShowSaveSlots = TRUE;

void set_save_slot_color(u8 r, u8 g, u8 b) {
    sTexSaveSlotColor[0] = r;
    sTexSaveSlotColor[1] = g;
    sTexSaveSlotColor[2] = b;
}


void set_file_select_bg_color(u8 r, u8 g, u8 b) {
    if (sBgMainMenuTimer == 8) {
        sFileSelectBgColor[0] = r;
        sFileSelectBgColor[1] = g;
        sFileSelectBgColor[2] = b;
    }

    if (sIsMenuButtonSelected != FALSE) {
        if (sBgMainMenuTimer >= 0 && sBgMainMenuTimer < 9) {
            sFileSelectBgColor[3] -= 25;
        } else if (sBgMainMenuTimer >= 9 && sBgMainMenuTimer < 18) {
            sFileSelectBgColor[3] += 25;
        } else if (sBgMainMenuTimer == 18) {
            sIsMenuButtonSelected = FALSE;
        }
    }
}
/**
 * Prints file select strings depending on the menu selected.
 * Also checks if all saves exists and defines text and main menu timers.
 */
void print_file_select_strings(void) {
    
    textScore[0] = DIALOG_C_UP_BUTTON;
    textCopy[0] = DIALOG_C_DOWN_BUTTON;
    textErase[0] = DIALOG_C_LEFT_BUTTON;
    textOption[0] = DIALOG_C_RIGHT_BUTTON;
    textReturn[0] = DIALOG_B_BUTTON;
    textViewScore[0] = DIALOG_C_UP_BUTTON;
    textCopyFileButton[0] = DIALOG_C_DOWN_BUTTON;
    textEraseFileButton[0] = DIALOG_C_LEFT_BUTTON;
    
    if (sShowSaveSlots == TRUE) {
        gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);
        // Print file star counts
        print_save_file_star_count(SAVE_FILE_A, 212, 56);
        print_save_file_star_count(SAVE_FILE_B, 212, 96);
        print_save_file_star_count(SAVE_FILE_C, 212, 136);
        print_save_file_star_count(SAVE_FILE_D, 212, 176);
        
        gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

        // Print file names
        gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_begin);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextBaseAlpha);
        print_menu_generic_string(38, 50, textMarioA);
        print_menu_generic_string(38, 90, textMarioB);
        print_menu_generic_string(38, 130, textMarioC);
        print_menu_generic_string(38, 170, textMarioD);
        gSPDisplayList(gDisplayListHead++, dl_menu_ia8_text_end);
}

    switch (sFileSelectMenuID) {
        case MENU_BUTTON_NONE:
            print_main_menu_strings();
            set_file_select_bg_color(255, 255, 0);
            break;
        case MENU_BUTTON_SCORE:
            print_score_menu_strings();
            set_file_select_bg_color(0, 255, 0);
            sScoreFileCoinScoreMode = 0;
            break;
        case MENU_BUTTON_COPY:
            print_copy_menu_strings();
            set_file_select_bg_color(0, 0, 255);
            break;
        case MENU_BUTTON_ERASE:
            print_erase_menu_strings();
            set_file_select_bg_color(255, 0, 0);
            break;
        case MENU_BUTTON_SCORE_FILE_A:
            print_save_file_scores(SAVE_FILE_A);
            break;
        case MENU_BUTTON_SCORE_FILE_B:
            print_save_file_scores(SAVE_FILE_B);
            break;
        case MENU_BUTTON_SCORE_FILE_C:
            print_save_file_scores(SAVE_FILE_C);
            break;
        case MENU_BUTTON_SCORE_FILE_D:
            print_save_file_scores(SAVE_FILE_D);
            break;
        case MENU_BUTTON_OPTION_MODE:
            print_options_mode_menu_strings();
            set_file_select_bg_color(255, 0, 128);
            break;
    }
}

extern u8 alo_ac_bg_menus_gray_pal[];
extern u8 alo_ac_bg_menus_ci4[];

// With scrolling - Scrolling background code used in Pyoro64 by buu342
void render_file_select_tex_background(void) {
    static float time = 0;
    time += 0.5;

    gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);

    gDPSetEnvColor(gDisplayListHead++, sFileSelectBgColor[0], sFileSelectBgColor[1], sFileSelectBgColor[2], sFileSelectBgColor[3]);

    gDPLoadTLUT_pal16(gDisplayListHead++, 0, alo_ac_bg_menus_gray_pal);
    gDPLoadTextureBlock_4b(gDisplayListHead++, alo_ac_bg_menus_ci4, G_IM_FMT_CI, 64, 64, 0,
        G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 6, G_TX_NOLOD, G_TX_NOLOD);

    gSPScisTextureRectangle(gDisplayListHead++, GFX_DIMENSIONS_FROM_LEFT_EDGE(0) * 4, 0 << 2, GFX_DIMENSIONS_FROM_RIGHT_EDGE(0) * 4, SCREEN_HEIGHT << 2, G_TX_RENDERTILE,
            ((int)(64-time))%64 << 5, ((int)(64-time))%64 << 5, (1 << 10), (1 << 10));
    
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
}

extern u8 alo_file_select_border[];

void render_file_select_tex_borders(s16 x, s16 y, s16 scale) {
    s16 yPos;
    
    // top part
    yPos = y;
    gDPLoadTextureBlock(gDisplayListHead++, alo_file_select_border, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
            G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
#ifndef TARGET_N64
    gSPTextureRectangle(gDisplayListHead++, x << 2, yPos << 2, (x + (GFX_DIMENSIONS_FROM_RIGHT_EDGE(0) * 4) * scale) * 4, (yPos + 32 * scale) << 2,
#else
    gSPTextureRectangle(gDisplayListHead++, x << 2, yPos << 2, (x + GFX_DIMENSIONS_FROM_RIGHT_EDGE(0) * scale) << 2, (yPos + 32 * scale) << 2,
#endif
            G_TX_RENDERTILE, 0 << 6, 0 << 6, (1 << 10) / scale, (1 << 10) / scale);
    // bottom part - rotated with mirror
    yPos = (y + (SCREEN_HEIGHT - 32) * scale);
    gDPLoadTextureBlock(gDisplayListHead++, alo_file_select_border, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
            G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
#ifndef TARGET_N64
    gSPTextureRectangle(gDisplayListHead++, x << 2, yPos << 2, (x + (GFX_DIMENSIONS_FROM_RIGHT_EDGE(0) * 4) * scale) * 4, (yPos + 32 * scale) << 2,
#else
    gSPTextureRectangle(gDisplayListHead++, x << 2, yPos << 2, (x + GFX_DIMENSIONS_FROM_RIGHT_EDGE(0) * scale) << 2, (yPos + 32 * scale) << 2,
#endif
            G_TX_RENDERTILE, (16 << 6), (16 << 6), (1 << 10) / scale, (1 << 10) / scale);
}
                
void render_file_select_tex_save_slots(s16 x, s16 y) {
    s16 fileIdx;
    s16 yPos;
    
    for (fileIdx = 0, yPos = y; fileIdx < 4; yPos += 40, fileIdx++) {
        if (save_file_exists(fileIdx) == TRUE) {
            if (sSelectedFileIndex == fileIdx && sStatusMessagePhase == COPY_PHASE_COPY_WHERE && sFileSelectMenuID == MENU_BUTTON_COPY) {
                set_save_slot_color(0, 0, 255);
            } else if (sSelectedFileIndex == fileIdx && sStatusMessagePhase == ERASE_PHASE_PROMPT && sFileSelectMenuID == MENU_BUTTON_ERASE) {
                set_save_slot_color(255, 0, 0);
            } else {
                set_save_slot_color(0, 255, 0);    
            }
        } else {
            set_save_slot_color(255, 255, 255);
        }

        render_custom_texrect(dl_alo_file_select_save_slot, FALSE, TRUE, G_TT_IA16, x, yPos, 
            256, 32, sTexSaveSlotColor[0], sTexSaveSlotColor[1], sTexSaveSlotColor[2], 255);
    }   
}

void handle_main_menu_actions(void) {
    if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
        play_sound(SOUND_MENU_CLICK_ACNH, gDefaultSoundArgs);
        sSelectedFileNum = sMenuSaveSlotOption + 1;
    }

    switch (gPlayer1Controller->buttonPressed & (C_BUTTONS)) {
        case U_CBUTTONS:
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
            sFileSelectMenuID = MENU_BUTTON_SCORE;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
            break;
        case D_CBUTTONS:
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
            sFileSelectMenuID = MENU_BUTTON_COPY;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
            break;
        case L_CBUTTONS:
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
            sFileSelectMenuID = MENU_BUTTON_ERASE;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
            break;
        case R_CBUTTONS:
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
            sFileSelectMenuID = MENU_BUTTON_OPTION_MODE;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
            break;
    }
}

void handle_score_menu_save_file_actions(void) {
    if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
        play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
        sScoreFileCoinScoreMode ^= 1;
    }

    if (gPlayer1Controller->buttonPressed & (B_BUTTON)) {
        play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
        sFileSelectMenuID = MENU_BUTTON_SCORE;
    }
}

#define SCORE_TIMER 31
void handle_score_menu_actions(void) {
    if (sMainMenuTimer >= SCORE_TIMER) {

        if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
            if (save_file_exists(sMenuSaveSlotOption) == TRUE) {
                play_sound(SOUND_MENU_CLICK_ACNH, gDefaultSoundArgs);
                sFileSelectMenuID = MENU_BUTTON_SCORE_FILE_A + sMenuSaveSlotOption;
            } else {
                if (sMainMenuTimer >= SCORE_TIMER) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gDefaultSoundArgs);
                    sFadeOutText = TRUE;
                    sMainMenuTimer = 0;
                }
            }
        }

        if (gPlayer1Controller->buttonPressed & (B_BUTTON)) {
            play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
            sFileSelectMenuID = MENU_BUTTON_NONE;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
        }

        switch (gPlayer1Controller->buttonPressed & (C_BUTTONS)) {
            case D_CBUTTONS:
                play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
                sFileSelectMenuID = MENU_BUTTON_COPY;
                sBgMainMenuTimer = 0;
                sIsMenuButtonSelected = TRUE;
                break;
            case L_CBUTTONS:
                play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
                sFileSelectMenuID = MENU_BUTTON_ERASE;
                sBgMainMenuTimer = 0;
                sIsMenuButtonSelected = TRUE;
                break;
        }
    }
}
#undef SCORE_TIMER

#define BUZZ_TIMER 21
/**
 * Copy Menu phase actions that handles what to do when a file button is clicked.
 */
void copy_menu_a_button_actions(s16 saveSlot) {
    switch (sStatusMessagePhase) {
        case COPY_PHASE_MAIN: // Copy Menu Main Phase
            if (sAllFilesExist == TRUE) { // Don't enable copy if all save files exists
                return;
            }

            if (save_file_exists(saveSlot) == TRUE) {
                // If clicked in a existing save file, ask where it wants to copy
                play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
                sSelectedFileIndex = saveSlot;
                sStatusMessagePhase = COPY_PHASE_COPY_WHERE;
                sFadeOutText = TRUE;
                sMainMenuTimer = 0;
            } else {
                // If clicked in a non-existing save file, play buzz sound
                play_sound(SOUND_MENU_CAMERA_BUZZ, gDefaultSoundArgs);
                if (sMainMenuTimer >= BUZZ_TIMER) {
                    sFadeOutText = TRUE;
                    sMainMenuTimer = 0;
                }
            }
            break;
        case COPY_PHASE_COPY_WHERE: // Copy Menu "COPY IT TO WHERE?" Phase (after a file is selected)
            if (save_file_exists(saveSlot) == FALSE && sMainMenuTimer >= BUZZ_TIMER) {
                // If clicked in a non-existing save file, copy the file
                play_sound(SOUND_MENU_STAR_SOUND, gDefaultSoundArgs);
                sStatusMessagePhase = COPY_PHASE_COPY_COMPLETE;
                sFadeOutText = TRUE;
                sMainMenuTimer = 0;
                save_file_copy(sSelectedFileIndex, saveSlot);
            } else {
                if (sMainMenuTimer >= BUZZ_TIMER) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gDefaultSoundArgs);
                    sFadeOutText = TRUE;
                    sMainMenuTimer = 0;
                }
            }
            break;
    }
}

void copy_menu_b_button_actions(void) {
    switch (sStatusMessagePhase) {
        case COPY_PHASE_MAIN: // Copy Menu Main Phase
            play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
            sFileSelectMenuID = MENU_BUTTON_NONE;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
            break;
        case COPY_PHASE_COPY_WHERE: // Copy Menu "COPY IT TO WHERE?" Phase (after a file is selected)
            play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
            sStatusMessagePhase = COPY_PHASE_MAIN;
            sFadeOutText = TRUE;
            break;
    }
}

#define ACTION_TIMER      31
#define MAIN_RETURN_TIMER 31

void handle_copy_menu_actions(void) {
    if (sMainMenuTimer >= ACTION_TIMER) {

        if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
            copy_menu_a_button_actions(sMenuSaveSlotOption);
        }

        if (gPlayer1Controller->buttonPressed & (B_BUTTON)) {
            copy_menu_b_button_actions();
        }

        
        if (sStatusMessagePhase == COPY_PHASE_MAIN) {
            switch (gPlayer1Controller->buttonPressed & (C_BUTTONS)) {
                case U_CBUTTONS:
                    play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
                    sFileSelectMenuID = MENU_BUTTON_SCORE;
                    sBgMainMenuTimer = 0;
                    sIsMenuButtonSelected = TRUE;
                    break;
                case L_CBUTTONS:
                    play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
                    sFileSelectMenuID = MENU_BUTTON_ERASE;
                    sBgMainMenuTimer = 0;
                    sIsMenuButtonSelected = TRUE;
                    break;
            }
        }
    }
    
    if (sStatusMessagePhase == COPY_PHASE_COPY_COMPLETE && sMainMenuTimer >= MAIN_RETURN_TIMER) {
        sStatusMessagePhase = COPY_PHASE_MAIN;
    }
}

/**
 * Erase Menu phase actions that handles what to do when a file button is clicked.
 */
void erase_menu_a_button_actions(s16 saveSlot) {
    switch (sStatusMessagePhase) {
        case ERASE_PHASE_MAIN: // Erase Menu Main Phase
            if (save_file_exists(saveSlot) == TRUE) {
                // If clicked in a existing save file, ask if it wants to delete it
                play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
                sSelectedFileIndex = saveSlot;
                sStatusMessagePhase = ERASE_PHASE_PROMPT;
                sEraseYesNoHoverState = MENU_ERASE_HOVER_YES;
                sFadeOutText = TRUE;
                sMainMenuTimer = 0;
            } else {
                // If clicked in a non-existing save file, play buzz sound
                play_sound(SOUND_MENU_CAMERA_BUZZ, gDefaultSoundArgs);

                if (sMainMenuTimer >= BUZZ_TIMER) {
                    sFadeOutText = TRUE;
                    sMainMenuTimer = 0;
                }
            }
            break;
        case ERASE_PHASE_PROMPT: // Erase Menu "SURE? YES NO" Phase (after a file is selected)
            if (sSelectedFileIndex == saveSlot) {
                // If clicked in a existing save file, play click sound and zoom out button
                // Note: The prompt functions are actually called when the ERASE_MSG_PROMPT
                // message is displayed with print_erase_menu_prompt
                play_sound(SOUND_MENU_CLICK_FILE_SELECT, gDefaultSoundArgs);
                sStatusMessagePhase = ERASE_PHASE_MAIN;
                sFadeOutText = TRUE;
            }
            break;
    }
}

void erase_menu_b_button_actions(void) {
    switch (sStatusMessagePhase) {
        case ERASE_PHASE_MAIN: // Copy Menu Main Phase
            play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
            sFileSelectMenuID = MENU_BUTTON_NONE;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
            break;
        case ERASE_PHASE_PROMPT: // Erase Menu "SURE? YES NO" Phase (after a file is selected)
            play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
            sEraseYesNoHoverState = MENU_ERASE_HOVER_NONE;
            sStatusMessagePhase = ERASE_PHASE_MAIN;
            sFadeOutText = TRUE;
            break;
    }
}

void handle_erase_menu_actions(void) {
    if (sMainMenuTimer >= ACTION_TIMER) {
        
        if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
            erase_menu_a_button_actions(sMenuSaveSlotOption);
        }

        if (gPlayer1Controller->buttonPressed & (B_BUTTON)) {
            erase_menu_b_button_actions();
        }

        if (sStatusMessagePhase == ERASE_PHASE_MAIN) {
            switch (gPlayer1Controller->buttonPressed & (C_BUTTONS)) {
                case U_CBUTTONS:
                    sFileSelectMenuID = MENU_BUTTON_SCORE;
                    sBgMainMenuTimer = 0;
                    sIsMenuButtonSelected = TRUE;
                    break;
                case D_CBUTTONS:
                    sFileSelectMenuID = MENU_BUTTON_COPY;
                    sBgMainMenuTimer = 0;
                    sIsMenuButtonSelected = TRUE;
                    break;
            }
        }
    }

    if (sStatusMessagePhase == ERASE_PHASE_MARIO_ERASED && sMainMenuTimer >= MAIN_RETURN_TIMER) {
        sEraseYesNoHoverState = MENU_ERASE_HOVER_NONE;
        sStatusMessagePhase = ERASE_PHASE_MAIN;
    }
}

#undef ACTION_TIMER
#undef MAIN_RETURN_TIMER
#undef BUZZ_TIMER

s8 sOptionMenuSelection = 0;
s8 sOptionMenuSoundHover;
s8 sOptionMenuLangHover;

void handle_options_menu_actions(void) {
    if (gPlayer1Controller->buttonPressed & (B_BUTTON)) {
        sFileSelectMenuID = MENU_BUTTON_NONE;
        sBgMainMenuTimer = 0;
        sIsMenuButtonSelected = TRUE;
    }

    switch (sOptionMenuSelection) {                        
        case 0: // Sound
            handle_menu_scrolling(MENU_SCROLL_VERTICAL, &sOptionMenuSoundHover, 0, 2); // 3 sound modes - index
            render_arrow_texture_menu(TRUE, ARROW_TEXTURE_SELECT, 28, (sOptionMenuSoundHover * 16) + 64);
            
            if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
                sSoundMode = sOptionMenuSoundHover;
                save_file_set_sound_mode(sSoundMode);
            }

            if (gPlayer3Controller->buttonPressed & R_TRIG) {
                play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
                sOptionMenuSelection += 1;
            }              
            break;
        case 1: // Language 
            handle_menu_scrolling(MENU_SCROLL_VERTICAL, &sOptionMenuLangHover, 0, 4); // 5 languages - index
            render_arrow_texture_menu(TRUE, ARROW_TEXTURE_SELECT, 128, (sOptionMenuLangHover * 16) + 64);
            
            if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
                sLanguageMode = sOptionMenuLangHover;
                eu_set_language(sLanguageMode);
            }

            if (gPlayer3Controller->buttonPressed & L_TRIG) {
                play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
                sOptionMenuSelection -= 1;
            }            
            break;
    }
} 

void handle_file_select_sanity_checks(void) {

    // Timers for menu alpha text, main menu and background
    if (sTextBaseAlpha < 250) {
        sTextBaseAlpha += 10;
    }
    if (sMainMenuTimer < 1000) {
        sMainMenuTimer += 1;
    }
    if (sBgMainMenuTimer < 100) {
        sBgMainMenuTimer += 1;
    }

    // Render Save Slots
    if (sFileSelectMenuID != MENU_BUTTON_OPTION_MODE && sFileSelectMenuID != MENU_BUTTON_SCORE_FILE_A
        && sFileSelectMenuID != MENU_BUTTON_SCORE_FILE_B && sFileSelectMenuID != MENU_BUTTON_SCORE_FILE_C
        && sFileSelectMenuID != MENU_BUTTON_SCORE_FILE_D) {
        sShowSaveSlots = TRUE;
    } else {
        sShowSaveSlots = FALSE;
    }
    
    // If all 4 save file exists, define true to sAllFilesExist to prevent more copies in copy menu
    if (save_file_exists(SAVE_FILE_A) == TRUE && save_file_exists(SAVE_FILE_B) == TRUE && save_file_exists(SAVE_FILE_C) == TRUE
        && save_file_exists(SAVE_FILE_D) == TRUE) {
        sAllFilesExist = TRUE;
    } else {
        sAllFilesExist = FALSE;
    }
}
    
void handle_file_select_general_actions(void) {
    if (sShowSaveSlots == TRUE && sEraseYesNoHoverState == MENU_ERASE_HOVER_NONE) {
        handle_menu_scrolling(MENU_SCROLL_VERTICAL, &sMenuSaveSlotOption, 0, 3); // 4 saves
    }

#ifdef MULTILANGUAGE
        // Open Options Menu if sOpenLangSettings is TRUE (It's TRUE when there's no saves)
        if (sOpenLangSettings == TRUE) {
            sFileSelectMenuID = MENU_BUTTON_OPTION_MODE;
            sBgMainMenuTimer = 0;
            sIsMenuButtonSelected = TRUE;
            sOpenLangSettings = FALSE;
        }
#endif

    if (sBgMainMenuTimer >= 18) {
        switch (sFileSelectMenuID) {
            case MENU_BUTTON_NONE:
                handle_main_menu_actions();
                break;
            case MENU_BUTTON_SCORE:
                handle_score_menu_actions();
                break;
            case MENU_BUTTON_COPY:
                handle_copy_menu_actions();
                break;
            case MENU_BUTTON_ERASE:
                handle_erase_menu_actions();
                break;
            case MENU_BUTTON_SCORE_FILE_A:
            case MENU_BUTTON_SCORE_FILE_B:
            case MENU_BUTTON_SCORE_FILE_C:
            case MENU_BUTTON_SCORE_FILE_D:
                handle_score_menu_save_file_actions();
                break;
            case MENU_BUTTON_OPTION_MODE:
                handle_options_menu_actions();
                break;
        }
    }
}

extern u8 alo_file_select_select_hover[];
 
void render_file_select_hover_select(s16 x, s16 y) {
    s16 xPos;
    s16 yPos;
    s16 alpha;
    s16 colorFade = gGlobalTimer << 12;
    
    alpha = (sins(colorFade) * 60.0f + 165.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 0, alpha);

    yPos = (y * (sMenuSaveSlotOption + 1)) + 4;
    // left part
    xPos = x;
    gDPLoadTextureBlock(gDisplayListHead++, alo_file_select_select_hover, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0,
            G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, xPos << 2, yPos << 2, (xPos + 16) << 2, (yPos + 32) << 2,
        G_TX_RENDERTILE, 0 << 6, 0 << 6, (1 << 10), (1 << 10));
    // right part - rotated with mirror
    xPos = SCREEN_WIDTH - (x + 16);
    gDPLoadTextureBlock(gDisplayListHead++, alo_file_select_select_hover, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0,
            G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, xPos << 2, yPos << 2, (xPos + 16) << 2, (yPos + 32) << 2,
            G_TX_RENDERTILE, (8 << 6), (0 << 6), (1 << 10), (1 << 10));
            
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
}
  
void print_file_select_texrects(void) {
    
    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);

    render_file_select_tex_background();

    render_file_select_tex_borders(GFX_DIMENSIONS_FROM_LEFT_EDGE(0), 0, 1);
    
    if (sShowSaveSlots == TRUE) {
        render_file_select_tex_save_slots(32, 44);
        render_file_select_hover_select(32, 40);
    }
    
    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

/**
 * Geo function that prints file select strings and the cursor.
 */
Gfx *geo_file_select_strings_and_menu_cursor(s32 callContext, UNUSED struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        print_file_select_texrects();
        
        handle_file_select_sanity_checks();
    
        if (sIsTitleScreenActive != FALSE) {
            handle_file_select_general_actions();
        }

        print_file_select_strings();    
    }
    return NULL;
}

/**
 * Initiates file select values after Mario Screen.
 * Relocates cursor position of the last save if the game goes back to the Mario Screen
 * either completing a course choosing "SAVE & QUIT" or having a game over.
 */
s32 lvl_init_menu_values_and_cursor_pos(UNUSED s32 arg, UNUSED s32 unused) {
#ifdef MULTILANGUAGE
    s8 fileIdx;
#endif
    sFileSelectMenuID = MENU_BUTTON_NONE;
    sTextBaseAlpha = 0;
    sFileSelectBgColor[0] = 255;
    sFileSelectBgColor[1] = 255;
    sFileSelectBgColor[2] = 0;
    sFileSelectBgColor[3] = 250;
    // Place the cursor over the save file that was being played.
    // gCurrSaveFileNum is 1 by default when the game boots, as such
    // the cursor will point on Mario A save file.
    switch (gCurrSaveFileNum) {
        case 1: // File A
            sMenuSaveSlotOption = 0;
            break;
        case 2: // File B
            sMenuSaveSlotOption = 1;
            break;
        case 3: // File C
            sMenuSaveSlotOption = 2;
            break;
        case 4: // File D
            sMenuSaveSlotOption = 3;
            break;
    }
    sCursorClickingTimer = 0;
    sSelectedFileNum = 0;
    sSelectedFileIndex = 0;
    sFadeOutText = FALSE;
    sStatusMessageID = 0;
    sStatusMessagePhase = 0;
    sTextFadeAlpha = 0;
    sMainMenuTimer = 0;
    sEraseYesNoHoverState = MENU_ERASE_HOVER_NONE;
    sSoundMode = save_file_get_sound_mode();
#ifdef MULTILANGUAGE
    sLanguageMode = eu_get_language();

    for (fileIdx = 0; fileIdx < 4; fileIdx++) {
        if (save_file_exists(fileIdx) == TRUE) {
            sOpenLangSettings = FALSE;
            break;
        } else {
            sOpenLangSettings = TRUE;
        }
    }
#endif
    //! no return value
#ifdef AVOID_UB
    return 0;
#endif
}

/**
 * Updates file select menu button objects so they can be interacted.
 */
s32 lvl_update_obj_and_load_file_selected(UNUSED s32 arg, UNUSED s32 unused) {
    area_update_objects();
    return sSelectedFileNum;
}
