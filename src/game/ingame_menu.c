#include <ultra64.h>

#include "sm64.h"
#include "memory.h"
#include "types.h"
#include "audio/external.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "game_init.h"
#include "save_file.h"
#include "level_update.h"
#include "camera.h"
#include "text_strings.h"
#include "segment2.h"
#include "segment7.h"
#include "game/eu_translation.h"
#include "ingame_menu.h"
#include "print.h"
#include "engine/math_util.h"
#include "course_table.h"
#include "menu/level_select_menu.h"
#include "alternate_costume.h"

extern Gfx *gDisplayListHead;
extern s16 gCurrCourseNum;
extern s16 gCurrSaveFileNum;

extern u8 main_menu_seg7_table_0700ABD0[];
extern Gfx castle_grounds_seg7_dl_0700EA58[];

u16 gDialogColorFadeTimer;
s8 gLastDialogLineNum;
s32 gDialogVariable;
u16 gDialogTextAlpha;
s16 gDialogX;
s16 gDialogY;
s16 gCutsceneMsgXOffset;
s16 gCutsceneMsgYOffset;
s8 gRedCoinsCollected;
u16 gDialogCharDisplay;

extern u8 gLastCompletedCourseNum;
extern u8 gLastCompletedStarNum;

enum DialogBoxState {
    DIALOG_STATE_OPENING,
    DIALOG_STATE_VERTICAL,
    DIALOG_STATE_HORIZONTAL,
    DIALOG_STATE_CLOSING
};

enum DialogBoxPageState {
    DIALOG_PAGE_STATE_NONE,
    DIALOG_PAGE_STATE_SCROLL,
    DIALOG_PAGE_STATE_END
};

enum DialogBoxType {
    DIALOG_TYPE_ROTATE, // used in NPCs and level messages
    DIALOG_TYPE_ZOOM    // used in signposts and wall signs and etc
};

enum DialogMark { DIALOG_MARK_NONE = 0, DIALOG_MARK_DAKUTEN = 1, DIALOG_MARK_HANDAKUTEN = 2 };

#define DEFAULT_DIALOG_BOX_ANGLE 90.0f
#define DEFAULT_DIALOG_BOX_SCALE 19.0f

#if !defined(VERSION_JP) && !defined(VERSION_SH)
u8 gDialogCharWidths[256] = {
    9,  7,  9,  9,  9,  9,  9,  9,  9,  9, // 0 - 9
    10,  10,  10,  11,  9,  9,  10,  10,   4,   7, // A - J
    9,  9,  12,  10,  11,  10,  11,  10,  9,  10, // K - T
    10,  10,  13,  10,  10,  9,   8,   9,   8,   8, // U - Z / a - d
     8,   6,   8,  8,   4,   4,   8,   4,  12,   8, // e - n
     9,  9,   8,   6,   7,   6,   8,   8,  12,   8, // o - x
    8,  7, /* y - z */ 4,  4, /* misc symbols */ 0,  0, /* menu mario face */  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    16,  16,  16,  16,  16,  16,  16,  16,  16,  0,  0,  0,  0,  0,  0,  0, // 0x50 - 0x5F - buttons
#ifdef MULTILANGUAGE // multilanguage chars
    8,  8,  8,  8,  10,  10,  10,  10,  0,  0,  0,  0,  0,  0,  0,  5, // A group (3 minus & 3 mayus) - comma
    8,  8,  8,  8,  9,  9,  9,  9,  0,  0,  0,  0,  0,  0,  0,  0, // E group (4 minus & 4 mayus)
    8,  8,  8,  8,  10,  10,  10,  10,  0,  0,  0,  0,  0,  0,  0,  0, // U group (3 minus & 3 mayus)
    9,  9,  9,  9,  11,  11,  11,  11,  0,  0,  0,  0,  0,  0,  5,  5, // O group (2 minus & 2 mayus) - 0x9E, 0x9F space and hyphen
    0,  4,  4,  4,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0, // I group (2 minus & 2 mayus)
#else
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5, // 0x6F -comma
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  6, // 0x9E, 0x9F space and hyphen
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#endif
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  4,  10,  10,  8, // 0xD0 - 0xDF
    14,  8, 14,  8,  8,  13,  6,  0,  0,  0,  0,  4, /* i without dot */ 8, /* beta */ 10,  8,  /* cedilla */ 0, // 0xE0 - 0xE6 - 0xEB - 0xEF (multi)
    8, /* de quote */ 0,  6,  13,  10,  8,  8,  8,  0,  15, 15,  15,  6, 15,  0,  0 // 0xF0 - 0xFD
};

u8 gDialogMenuCharWidths[256] = { // TODO: Is there a way to auto generate this?
    7,  7,  7,  7,  7,  7,  7,  7,  7,  7, // 0 - 9
    6,  6,  6,  6,  6,  6,  6,  6,  3,  6, // A - J
    6,  5,  7,  8,  6,  6,  6,  6,  6,  5, // K - T
    6,  6,  8,  7,  6,  6,  6,  5,  5,  6, // U - Z / a - d
    5,  5,  6,  5,  4,  5,  5,  3,  7,  5, // e - n
    5,  5,  6,  5,  5,  5,  5,  5,  7,  7, // o - x
    5,  5, /* y - z */ 4,  4, /* misc symbols */ 8,  6,  /* menu mario face */ 0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    8,  8,  8,  8,  7,  7,  6,  7,  7,  0,  0,  0,  0,  0,  0,  0, // 0x50 - 0x5F - buttons
#ifdef MULTILANGUAGE
    6,  6,  6,  0,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  4,
    5,  5,  5,  5,  6,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,
    5,  5,  5,  0,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  5,  5,  0,  0,  6,  6,  0,  0,  0,  0,  0,  0,  0,  5,  6,
    0,  4,  4,  0,  0,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#else
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  6,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#endif
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#ifdef MULTILANGUAGE
    7,  5, 10,  5,  9,  8,  4,  0,  0,  0,  0,  5,  5,  6,  5,  0,
#else
    7,  5, 10,  5,  9,  8,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#endif
    0,  0,  5,  7,  7,  6,  6,  8,  0,  8, 10,  6,  4, 10,  0,  0
};
#endif

s8 gDialogBoxState = DIALOG_STATE_OPENING;
f32 gDialogBoxOpenTimer = DEFAULT_DIALOG_BOX_ANGLE;
f32 gDialogBoxScale = DEFAULT_DIALOG_BOX_SCALE;
s16 gDialogScrollOffsetY = 0;
s8 gDialogBoxType = DIALOG_TYPE_ROTATE;
s16 gDialogID = -1;
s16 gLastDialogPageStrPos = 0;
s16 gDialogTextPos = 0;
#ifdef MULTILANGUAGE
s32 gInGameLanguage = 0;
#endif
s8 gDialogLineNum = 1;
s8 gLastDialogResponse = 0;
u8 gMenuHoldKeyIndex = 0;
u8 gMenuHoldKeyTimer = 0;
s32 gDialogResponse = 0;
s8 gSkipTypewriteEffect = FALSE;
s8 gAllTextinPageRendered = FALSE;

#define JP_X_SPACING 12

void create_dl_identity_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guMtxIdent(matrix);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
}

void create_dl_translation_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guTranslate(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);

    if (pushOp == MENU_MTX_NOPUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
}

void create_dl_rotation_matrix(s8 pushOp, f32 a, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guRotate(matrix, a, x, y, z);

    if (pushOp == MENU_MTX_PUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);

    if (pushOp == MENU_MTX_NOPUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
}

void create_dl_scale_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guScale(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);

    if (pushOp == MENU_MTX_NOPUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
}

void create_dl_ortho_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    create_dl_identity_matrix();

    guOrtho(matrix, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);

    // Should produce G_RDPHALF_1 in Fast3D
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH)
}

void create_aio_matrix(Gfx *displaylist, f32 xPos, f32 yPos, f32 scale, f32 aRot, f32 xRot, f32 yRot, f32 zPosRot) {
       
    create_dl_translation_matrix(MENU_MTX_PUSH, xPos, yPos, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, scale, scale, 1.0f);
    
    create_dl_translation_matrix(MENU_MTX_PUSH, xPos, yPos, zPosRot);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, aRot, xRot, yRot, 1.0f);
    
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    
    gSPDisplayList(gDisplayListHead++, displaylist);

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void render_rotating_model(Gfx *displaylist, f32 xPos, f32 yPos, f32 scale, f32 rotSpeed) {
    f32 rotation;
            
    rotation = gGlobalTimer * rotSpeed;
        
    // 200.0f extends the z range in n64 so the model doesn't get cutoff while rotating
    create_aio_matrix(displaylist, xPos, yPos, scale, rotation, 0, rotation, 200.0f);
}

/**
static u8 *alloc_ia8_text_from_i1(u16 *in, s16 width, s16 height) {
    s32 inPos;
    u16 bitMask;
    u8 *out;
    s16 outPos = 0;

    out = alloc_display_list((u32) width * (u32) height);

    if (out == NULL) {
        return NULL;
    }

    for (inPos = 0; inPos < (width * height) / 16; inPos++) {
        bitMask = 0x8000;

        while (bitMask != 0) {
            if (in[inPos] & bitMask) {
                out[outPos] = 0xFF;
            } else {
                out[outPos] = 0x00;
            }

            bitMask /= 2;
            outPos++;
        }
    }

    return out;
}

void render_generic_char(u8 c) {
    void **fontLUT;
    void *packedTexture;

    fontLUT = segmented_to_virtual(main_font_lut);
    packedTexture = segmented_to_virtual(fontLUT[c]);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
#ifdef VERSION_EU
    gSPTextureRectangleFlip(gDisplayListHead++, gDialogX << 2, (gDialogY - 16) << 2,
                            (gDialogX + 8) << 2, gDialogY << 2, G_TX_RENDERTILE, 8 << 6, 4 << 6, 1 << 10, 1 << 10);
#endif
}


#ifdef VERSION_EU
u8 *alloc_ia4_tex_from_i1(u8 *in, s16 width, s16 height) {
    u32 size = (u32) width * (u32) height;
    u8 *out;
    s32 inPos;
    s16 outPos;
    u8 bitMask;

    outPos = 0;
    out = (u8 *) alloc_display_list(size);

    if (out == NULL) {
        return NULL;
    }

    for (inPos = 0; inPos < (width * height) / 4; inPos++) {
        bitMask = 0x80;
        while (bitMask != 0) {
            out[outPos] = (in[inPos] & bitMask) ? 0xF0 : 0x00;
            bitMask /= 2;
            out[outPos] = (in[inPos] & bitMask) ? out[outPos] + 0x0F : out[outPos];
            bitMask /= 2;
            outPos++;
        }
    }

    return out;
}
#endif
*/
void render_generic_char_at_pos(s16 xPos, s16 yPos, u8 c) {
    void **fontLUT;
    void *packedTexture;

    fontLUT = segmented_to_virtual(main_font_lut);
    packedTexture = segmented_to_virtual(fontLUT[c]);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
    gSPScisTextureRectangle(gDisplayListHead++, xPos << 2, (yPos - 16) << 2, (xPos + 16) << 2, yPos << 2,
                            G_TX_RENDERTILE, 0 << 6, 0 << 6, 1 << 10, 1 << 10);
}

#ifdef MULTILANGUAGE
void render_lowercase_diacritic(s16 *xPos, s16 *yPos, u8 letter, u8 diacritic) {
    render_generic_char_at_pos(*xPos, *yPos, letter);
    render_generic_char_at_pos(*xPos - 2, *yPos, diacritic + 0xE7);
    *xPos += gDialogCharWidths[letter];
}

void render_uppercase_diacritic(s16 *xPos, s16 *yPos, u8 letter, u8 diacritic) {
    render_generic_char_at_pos(*xPos, *yPos, letter);
    render_generic_char_at_pos(*xPos, *yPos - 4, diacritic + 0xE3);
    *xPos += gDialogCharWidths[letter];
}
#endif

#if !defined(VERSION_JP) && !defined(VERSION_SH)
struct MultiTextEntry {
    u8 length;
    u8 str[4];
};

#define TEXT_THE_RAW ASCII_TO_DIALOG('t'), ASCII_TO_DIALOG('h'), ASCII_TO_DIALOG('e'), 0x00
#define TEXT_YOU_RAW ASCII_TO_DIALOG('y'), ASCII_TO_DIALOG('o'), ASCII_TO_DIALOG('u'), 0x00

enum MultiStringIDs { STRING_THE, STRING_YOU };

/*
 * Place the multi-text string according to the ID passed. (US, EU)
 * 0: 'the'
 * 1: 'you'
 */
void render_multi_text_string(s16 *xPos, s16 *yPos, s8 multiTextID) // EU: 802AD650
{
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

    for (i = 0; i < textLengths[multiTextID].length; i++) {
        render_generic_char_at_pos(*xPos, *yPos, textLengths[multiTextID].str[i]);
        *xPos += gDialogCharWidths[textLengths[multiTextID].str[i]];
    }
}

#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
#define MAX_STRING_WIDTH 18
#else
#define MAX_STRING_WIDTH 16
#endif

/**
 * Prints a generic white string.
 * In JP/EU a IA1 texture is used but in US a IA4 texture is used.
 */
void print_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    u8 lineNum = 1;
    s16 xCoord = x;
    s16 yCoord;


//    if (gIsYTextInverted == 1) {
        yCoord = 240 - y;
//    } else {
//        yCoord = y;
//    }

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case DIALOG_CHAR_SPACE:
                xCoord += 5;
                break;
            case DIALOG_CHAR_NEWLINE:
                yCoord += 16;
                xCoord = x;
                lineNum++;
                break;
#ifdef MULTILANGUAGE
            case DIALOG_CHAR_LOWER_A_GRAVE:
            case DIALOG_CHAR_LOWER_A_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_A_UMLAUT:
            case DIALOG_CHAR_LOWER_A_ACUTE:
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('a'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_UPPER_A_GRAVE:
            case DIALOG_CHAR_UPPER_A_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_A_UMLAUT:
            case DIALOG_CHAR_UPPER_A_ACUTE:
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('A'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_LOWER_E_GRAVE:
            case DIALOG_CHAR_LOWER_E_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_E_UMLAUT:
            case DIALOG_CHAR_LOWER_E_ACUTE:
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('e'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_UPPER_E_GRAVE:
            case DIALOG_CHAR_UPPER_E_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_E_UMLAUT:
            case DIALOG_CHAR_UPPER_E_ACUTE:
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('E'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_LOWER_U_GRAVE:
            case DIALOG_CHAR_LOWER_U_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_U_UMLAUT:
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('u'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_UPPER_U_GRAVE:
            case DIALOG_CHAR_UPPER_U_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_U_UMLAUT:
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('U'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_LOWER_O_GRAVE:
            case DIALOG_CHAR_LOWER_O_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_O_UMLAUT:
            case DIALOG_CHAR_LOWER_O_ACUTE:
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('o'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_UPPER_O_GRAVE:
            case DIALOG_CHAR_UPPER_O_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_O_UMLAUT:
            case DIALOG_CHAR_UPPER_O_ACUTE:
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('O'), str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_LOWER_I_GRAVE:
            case DIALOG_CHAR_LOWER_I_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_I_UMLAUT:
            case DIALOG_CHAR_LOWER_I_ACUTE:
                render_lowercase_diacritic(&xCoord, &yCoord, DIALOG_CHAR_I_NO_DIA, str[strPos] & 0xF);
                break;
            case DIALOG_CHAR_UPPER_I_GRAVE:
            case DIALOG_CHAR_UPPER_I_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_I_UMLAUT:
            case DIALOG_CHAR_UPPER_I_ACUTE:
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('I'), str[strPos] & 0xF);
                break;
#endif
#if !defined(VERSION_JP) && !defined(VERSION_SH)
            case DIALOG_CHAR_SLASH:
                xCoord += gDialogCharWidths[DIALOG_CHAR_SPACE] * 2;
                break;
            case DIALOG_CHAR_MULTI_THE:
                render_multi_text_string(&xCoord, &yCoord, STRING_THE);
                break;
            case DIALOG_CHAR_MULTI_YOU:
                render_multi_text_string(&xCoord, &yCoord, STRING_YOU);
                break;
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
            case DIALOG_CHAR_DAKUTEN:
                render_generic_char_at_pos(xCoord, yCoord - 1, DIALOG_CHAR_DAKUTEN);
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                render_generic_char_at_pos(xCoord, yCoord - 1, DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);
                break;
#endif
            default:
                render_generic_char_at_pos(xCoord, yCoord, str[strPos]);
#ifndef VERSION_JP
                xCoord += gDialogCharWidths[str[strPos]];
#else
                xCoord += JP_X_SPACING;
#endif
                break;
        }

        strPos++;
    }
}

#ifdef MULTILANGUAGE
void print_hud_char_umlaut(s16 x, s16 y, u8 chr) {
    void **fontLUT = segmented_to_virtual(main_hud_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[chr]);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[GLYPH_UMLAUT]);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, (y - 4) << 2, (x + 16) << 2, (y + 12) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
}
#endif

/**
 * Prints a hud string depending of the hud table list defined.
 */
void print_hud_lut_string(s8 hudLUT, s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **hudLUT1 = segmented_to_virtual(menu_hud_lut); // Japanese Menu HUD Color font
    void **hudLUT2 = segmented_to_virtual(main_hud_lut); // 0-9 A-Z HUD Color Font
    u32 curX = x;
    u32 curY = y;

    u32 xStride; // X separation

    if (hudLUT == HUD_LUT_JPMENU) {
        xStride = 16;
    } else { // HUD_LUT_GLOBAL
#if defined(VERSION_JP)
        xStride = 14;
#else
        xStride = 12; //? Shindou uses this.
#endif
    }

    while (str[strPos] != GLOBAR_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case GLOBAL_CHAR_SPACE:
                curX += xStride / 2;
                break;
#ifdef MULTILANGUAGE
            case HUD_CHAR_A_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('A'));
                curX += xStride;
                break;
            case HUD_CHAR_O_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('O'));
                curX += xStride;
                break;
            case HUD_CHAR_U_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('U'));
                curX += xStride;
                break;
#endif
        default:
            gDPPipeSync(gDisplayListHead++);

            if (hudLUT == HUD_LUT_JPMENU)
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT1[str[strPos]]);

            if (hudLUT == HUD_LUT_GLOBAL)
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT2[str[strPos]]);

            gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
            gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 16) << 2,
                                (curY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

            curX += xStride;
            break;
        }
    strPos++;
    }
}

#ifdef MULTILANGUAGE
void print_menu_char_umlaut(s16 x, s16 y, u8 chr) {
    void **fontLUT = segmented_to_virtual(menu_font_lut);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[chr]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 8) << 2, (y + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[DIALOG_CHAR_UMLAUT]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, (y - 4) << 2, (x + 8) << 2, (y + 4) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
}
#endif

void print_menu_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    s32 curX = x;
    s32 curY = y;
    void **fontLUT = segmented_to_virtual(menu_font_lut);

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        switch (str[strPos]) {
#ifdef MULTILANGUAGE
            case DIALOG_CHAR_UPPER_A_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('A'));
                curX += gDialogMenuCharWidths[str[strPos]];
                break;
            case DIALOG_CHAR_UPPER_U_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('U'));
                curX += gDialogMenuCharWidths[str[strPos]];
                break;
            case DIALOG_CHAR_UPPER_O_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('O'));
                curX += gDialogMenuCharWidths[str[strPos]];
                break;
#else
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
#endif
            case DIALOG_CHAR_SPACE:
                curX += 4;
                break;
            default:
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

#ifndef VERSION_EU
                if (mark != DIALOG_MARK_NONE) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[mark + 0xEF]);
                    gDPLoadSync(gDisplayListHead++);
                    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                    gSPTextureRectangle(gDisplayListHead++, (curX + 6) << 2, (curY - 7) << 2,
                                        (curX + 14) << 2, (curY + 1) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                    mark = DIALOG_MARK_NONE;
                }
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
                curX += 9;
#else
                curX += gDialogMenuCharWidths[str[strPos]];
#endif
        }
        strPos++;
    }
}
/**
void print_credits_string(s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **fontLUT = segmented_to_virtual(main_credits_font_lut);
    u32 curX = x;
    u32 curY = y;

    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);

    while (str[strPos] != GLOBAR_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case GLOBAL_CHAR_SPACE:
                curX += 4;
                break;
            default:
                gDPPipeSync(gDisplayListHead++);
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                curX += 7;
                break;
        }
        strPos++;
    }
}
 */

static u8 ascii_to_font_char(u8 c) {
    if (c >= '0' && c <= '9')
        return (c - '0' + 0x00);
    if (c >= 'A' && c <= 'Z')
        return (c - 'A' + 0x0A);

    if (c >= 'a' && c <= 'z')
#if defined(VERSION_JP) || defined(VERSION_SH)
        return (c - 'A' + 0x0A);
#else
        return (c - 'a' + 0x24);
#endif

    if (c == '\'') return 0x3E;
    if (c == '.')  return 0x3F;
    if (c == ',')  return 0x6F;
    if (c == ' ')  return 0x9E;
    if (c == '-')  return 0x9F;
    if (c == '(')  return 0xE1;
    if (c == ')')  return 0xE3;
    if (c == '+')  return 0xE4;
    if (c == '&')  return 0xE5;
    if (c == ':')  return 0xE6;
    if (c == '!')  return 0xF2;
    if (c == '%')  return 0xF3;
    if (c == '?')  return 0xF4;
    if (c == '~')  return 0xF7;
    if (c == '$')  return 0xF9;
    if (c == '*')  return 0xFA;
    if (c == '#')  return 0xFD;
    if (c == '\n') return 0xFE;

    return 0x9E;
}

void print_generic_str_ascii(s16 x, s16 y, const char *str) {
    s16 i;
    u8  buf[32];
    for (i = 0; str[i] != 0; i++)
        buf[i] = ascii_to_font_char(str[i]);
    buf[i] = 0xFF;

    print_generic_string(x, y, buf);
}

void print_generic_string_shadow(s8 isAscii, s16 x, s16 y, u8 r, u8 g, u8 b, u8 alpha, u8 spacing, const char *strAscii, const u8 *strDefault) {

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    // Shadow Part
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, alpha);
    isAscii ? print_generic_str_ascii(x, y, strAscii) : print_generic_string(x, y, strDefault);

    // Front Part
    gDPSetEnvColor(gDisplayListHead++, r, g, b, alpha);

    isAscii ? print_generic_str_ascii(x - spacing, y + spacing, strAscii) : print_generic_string(x - spacing, y + spacing, strDefault);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

void handle_menu_scrolling(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex) {
    u8 index = 0;

    if (scrollDirection == MENU_SCROLL_VERTICAL) {
        if (gPlayer3Controller->rawStickY > 60) {
            index++;
        }

        if (gPlayer3Controller->rawStickY < -60) {
            index += 2;
        }
    } else if (scrollDirection == MENU_SCROLL_HORIZONTAL) {
        if (gPlayer3Controller->rawStickX > 60) {
            index += 2;
        }

        if (gPlayer3Controller->rawStickX < -60) {
            index++;
        }
    }

    if (((index ^ gMenuHoldKeyIndex) & index) == 2) {
        if (currentIndex[0] == maxIndex) {
            //! Probably originally a >=, but later replaced with an == and an else statement.
            currentIndex[0] = maxIndex;
        } else {
            play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
            currentIndex[0]++;
        }
    }

    if (((index ^ gMenuHoldKeyIndex) & index) == 1) {
        if (currentIndex[0] == minIndex) {
            // Same applies to here as above
        } else {
            play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
            currentIndex[0]--;
        }
    }

    if (gMenuHoldKeyTimer == 10) {
        gMenuHoldKeyTimer = 8;
        gMenuHoldKeyIndex = 0;
    } else {
        gMenuHoldKeyTimer++;
        gMenuHoldKeyIndex = index;
    }

    if ((index & 3) == 0) {
        gMenuHoldKeyTimer = 0;
    }
}

// EU has both get_str_x_pos_from_center and get_str_x_pos_from_center_scale
// US and JP only implement one or the other
s16 get_str_x_pos_from_center(s16 centerPos, u8 *str, UNUSED f32 scale) {
    s16 strPos = 0;
    f32 spacesWidth = 0.0f;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        spacesWidth += gDialogCharWidths[str[strPos]];
        strPos++;
    }
    // return the x position of where the string starts as half the string's
    // length from the position of the provided center.
    return (s16)(centerPos - (s16)(spacesWidth / 2.0));
}

s16 get_str_x_pos_from_center_scale(s16 centerPos, u8 *str, f32 scale) {
    s16 strPos = 0;
    f32 charsWidth = 0.0f;
    f32 spacesWidth = 0.0f;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        //! EU checks for dakuten and handakuten despite dialog code unable to handle it
        if (str[strPos] == DIALOG_CHAR_SPACE) {
            spacesWidth += 1.0;
        } else if (str[strPos] != DIALOG_CHAR_DAKUTEN
                   && str[strPos] != DIALOG_CHAR_PERIOD_OR_HANDAKUTEN) {
            charsWidth += 1.0;
        }
        strPos++;
    }
    // return the x position of where the string starts as half the string's
    // length from the position of the provided center.
    return (f32) centerPos - (scale * (charsWidth / 2.0)) - ((scale / 2.0) * (spacesWidth / 2.0));
}

s16 get_string_width(u8 *str) {
    s16 strPos = 0;
    s16 width = 0;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        width += gDialogCharWidths[str[strPos]];
        strPos++;
    }
    return width;
}

s16 get_string_width_ascii(const char *str) {
    s16 i;
    u8  buf[32];
    s16 bufPos = 0;
    s16 width = 0;
    
    for (i = 0; str[i] != 0; i++)
        buf[i] = ascii_to_font_char(str[i]);
    buf[i] = DIALOG_CHAR_TERMINATOR;

    while (buf[bufPos] != DIALOG_CHAR_TERMINATOR) {
        width += gDialogCharWidths[buf[bufPos]];
        bufPos++;
    }
    
    return width;
}

u8 gHudSymCoin[] = { GLYPH_COIN, GLYPH_SPACE };
u8 gHudSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

void print_hud_my_score_coins(s32 useCourseCoinScore, s8 fileNum, s8 courseNum, s16 x, s16 y) {
    u8 strNumCoins[4];
    s16 numCoins;

    if (!useCourseCoinScore) {
        numCoins = (u16)(save_file_get_max_coin_score(courseNum) & 0xFFFF);
    } else {
        numCoins = save_file_get_course_coin_score(fileNum, courseNum);
    }

    if (numCoins != 0) {
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, gHudSymCoin);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, gHudSymX);
        int_to_str(numCoins, strNumCoins);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, strNumCoins);
    }
}

void print_hud_my_score_stars(s8 fileNum, s8 courseNum, s16 x, s16 y) {
    u8 strStarCount[4];
    s16 starCount;
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
    UNUSED u16 unused;
    u8 textSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

    starCount = save_file_get_course_star_count(fileNum, courseNum);

    if (starCount != 0) {
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, textSymStar);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, textSymX);
        int_to_str(starCount, strStarCount);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, strStarCount);
    }
}

void int_to_str(s32 num, u8 *dst) {
    s32 digit1;
    s32 digit2;
    s32 digit3;

    s8 pos = 0;

    if (num > 999) {
        dst[0] = 0x00; dst[1] = DIALOG_CHAR_TERMINATOR;
        return;
    }

    digit1 = num / 100;
    digit2 = (num - digit1 * 100) / 10;
    digit3 = (num - digit1 * 100) - (digit2 * 10);

    if (digit1 != 0) {
        dst[pos++] = digit1;
    }

    if (digit2 != 0 || digit1 != 0) {
        dst[pos++] = digit2;
    }

    dst[pos++] = digit3;
    dst[pos] = DIALOG_CHAR_TERMINATOR;
}

s16 get_dialog_id(void) {
    return gDialogID;
}

void create_dialog_box(s16 dialog) {
    if (gDialogID == -1) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
    }
}

void create_dialog_box_with_var(s16 dialog, s32 dialogVar) {
    if (gDialogID == -1) {
        gDialogID = dialog;
        gDialogVariable = dialogVar;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
    }
}

void create_dialog_inverted_box(s16 dialog) {
    if (gDialogID == -1) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ZOOM;
    }
}

void create_dialog_box_with_response(s16 dialog) {
    if (gDialogID == -1) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TYPE_ROTATE;
        gLastDialogResponse = 1;
    }
}

void reset_dialog_render_state(void) {
    level_set_transition(0, 0);

    if (gDialogBoxType == DIALOG_TYPE_ZOOM) {
        trigger_cutscene_dialog(2);
    }

    gDialogBoxScale = 19.0f;
    gDialogBoxOpenTimer = 90.0f;
    gDialogBoxState = DIALOG_STATE_OPENING;
    gDialogID = -1;
    gDialogTextPos = 0;
    gLastDialogResponse = 0;
    gLastDialogPageStrPos = 0;
    gDialogResponse = 0;
}

#define AC_DIALOG_ALPHA (220 - gDialogBoxOpenTimer * 2)

struct ACTopBalloonRender {
    u8 r, g, b;
    u8 isTextBlack;
};

static unsigned char sACTopBalloonText[][16] = {
    // English Group
    {NO_NPCTEXT}, {NO_NPCTEXT}, {NPCTEXT_BUDDY}, {NPCTEXT_KTQ}, {NPCTEXT_KBB}, {NPCTEXT_BOWSER}, {NPCTEXT_LAKITU}, {NPCTEXT_HOOT}, {NPCTEXT_PENGUIN}, 
    {NPCTEXT_TOAD}, {NPCTEXT_UKIKI}, {NPCTEXT_MIPS}, {NPCTEXT_SNOWMAN}, {NPCTEXT_WHOMP}, {NPCTEXT_EYEROK}, {NPCTEXT_WIGGLER}, {NPCTEXT_YOSHI},
    // French Group
    {NO_NPCTEXT}, {NO_NPCTEXT}, {NPCTEXT_BUDDY_FR}, {NPCTEXT_KTQ_FR}, {NPCTEXT_KBB_FR}, {NPCTEXT_BOWSER_FR}, {NPCTEXT_LAKITU_FR}, {NPCTEXT_HOOT_FR}, {NPCTEXT_PENGUIN_FR}, 
    {NPCTEXT_TOAD_FR}, {NPCTEXT_UKIKI_FR}, {NPCTEXT_MIPS_FR}, {NPCTEXT_SNOWMAN_FR}, {NPCTEXT_WHOMP_FR}, {NPCTEXT_EYEROK_FR}, {NPCTEXT_WIGGLER_FR}, {NPCTEXT_YOSHI_FR},
    // German Group
    {NO_NPCTEXT}, {NO_NPCTEXT}, {NPCTEXT_BUDDY_DE}, {NPCTEXT_KTQ_DE}, {NPCTEXT_KBB_DE}, {NPCTEXT_BOWSER_DE}, {NPCTEXT_LAKITU_DE}, {NPCTEXT_HOOT_DE}, {NPCTEXT_PENGUIN_DE}, 
    {NPCTEXT_TOAD_DE}, {NPCTEXT_UKIKI_DE}, {NPCTEXT_MIPS_DE}, {NPCTEXT_SNOWMAN_DE}, {NPCTEXT_WHOMP_DE}, {NPCTEXT_EYEROK_DE}, {NPCTEXT_WIGGLER_DE}, {NPCTEXT_YOSHI_DE},
    // Italian Group
    {NO_NPCTEXT}, {NO_NPCTEXT}, {NPCTEXT_BUDDY_IT}, {NPCTEXT_KTQ_IT}, {NPCTEXT_KBB_IT}, {NPCTEXT_BOWSER_IT}, {NPCTEXT_LAKITU_IT}, {NPCTEXT_HOOT_IT}, {NPCTEXT_PENGUIN_IT}, 
    {NPCTEXT_TOAD_IT}, {NPCTEXT_UKIKI_IT}, {NPCTEXT_MIPS_IT}, {NPCTEXT_SNOWMAN_IT}, {NPCTEXT_WHOMP_IT}, {NPCTEXT_EYEROK_IT}, {NPCTEXT_WIGGLER_IT}, {NPCTEXT_YOSHI_IT},
    // Spanish Group
    {NO_NPCTEXT}, {NO_NPCTEXT}, {NPCTEXT_BUDDY_ES}, {NPCTEXT_KTQ_ES}, {NPCTEXT_KBB_ES}, {NPCTEXT_BOWSER_ES}, {NPCTEXT_LAKITU_ES}, {NPCTEXT_HOOT_ES}, {NPCTEXT_PENGUIN_ES}, 
    {NPCTEXT_TOAD_ES}, {NPCTEXT_UKIKI_ES}, {NPCTEXT_MIPS_ES}, {NPCTEXT_SNOWMAN_ES}, {NPCTEXT_WHOMP_ES}, {NPCTEXT_EYEROK_ES}, {NPCTEXT_WIGGLER_ES}, {NPCTEXT_YOSHI_ES},
};

// First 2 are generic dialog and signpost, they aren't defined because top balloon doesn't render with their npcNameID
struct ACTopBalloonRender sACTopBalloonDefines[] = {
    {   0,   0,   0, FALSE},
    {   0,   0,   0, FALSE},
    { 240,   0,  80, FALSE},
    {  24, 216,  24,  TRUE},
    {   0,   0,   0, FALSE},
    {   0, 144,   0, FALSE},
    { 222, 139,  24,  TRUE},
    {  96,   0,   0, FALSE},
    {   8,  16,  88, FALSE},
    {  64,  38, 175, FALSE},
    { 152,  64,  32, FALSE},
    { 248, 192,   0,  TRUE},
    { 168, 200, 248,  TRUE},
    { 160, 176, 192, FALSE},
    { 160, 104,  16, FALSE},
    { 200, 128,   8,  TRUE},
    {   0, 246,   0,  TRUE},
};

void render_balloon_dialog_top_name(struct DialogEntry *dialog, s16 x, s16 y) {

    struct ACTopBalloonRender *topBalloon = &sACTopBalloonDefines[dialog->npcNameID];
    gInGameLanguage = eu_get_language();
    
    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);

    gDPSetEnvColor(gDisplayListHead++, topBalloon->r, topBalloon->g, topBalloon->b, 20 + AC_DIALOG_ALPHA);
    gSPDisplayList(gDisplayListHead++, dl_balloon_dialog_top_name_texblock);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 128) << 2, (y + 32) << 2, G_TX_RENDERTILE, 0, 0, (1 << 10), (1 << 10));

    if (topBalloon->isTextBlack == TRUE) {
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, AC_DIALOG_ALPHA);
    } else {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, AC_DIALOG_ALPHA);
    }

    print_generic_string(get_str_x_pos_from_center_scale(98, sACTopBalloonText[gInGameLanguage * 17 + dialog->npcNameID], 10.0f), y + 36, 
        sACTopBalloonText[gInGameLanguage * 17 + dialog->npcNameID]);
    
    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

void render_balloon_dialog_texture(struct DialogEntry *dialog) {

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, AC_DIALOG_ALPHA);
    gSPDisplayList(gDisplayListHead++, dl_balloon_dialog_bg);

    if (dialog->npcNameID == NPCNAME_SIGN) {
        gDPSetEnvColor(gDisplayListHead++, 181, 107, 41, AC_DIALOG_ALPHA);
    }
    
    gSPDisplayList(gDisplayListHead++, dl_balloon_dialog_texrect);

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

void render_generic_dialog_char_at_pos(struct DialogEntry *dialog, s16 x, s16 y, u8 c) {
    s16 width;  // sp26
    s16 height; // sp24
    s16 tmpX;
    s16 tmpY;
    s16 xCoord; // sp1E
    s16 yCoord; // sp1C
    void **fontLUT;
    void *packedTexture;

    width = (16.0 - (gDialogBoxScale * 0.8));
    height = (17.0 - (gDialogBoxScale * 0.8)); // 16 + 1
    tmpX = (dialog->leftOffset + (65.0 - (65.0 / gDialogBoxScale)));
    tmpY = ((240 - dialog->width) - ((40.0 / gDialogBoxScale) - 40));
    xCoord = (tmpX + (x / gDialogBoxScale));
    yCoord = (tmpY + (y / gDialogBoxScale));

    fontLUT = segmented_to_virtual(main_font_lut);
    packedTexture = segmented_to_virtual(fontLUT[c]);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);


    switch (c) {
#ifndef VERSION_JP // these chars don't exist in JP
        case DIALOG_C_UP_BUTTON:
        case DIALOG_C_DOWN_BUTTON:
        case DIALOG_C_LEFT_BUTTON:
        case DIALOG_C_RIGHT_BUTTON:
            gDPSetEnvColor(gDisplayListHead++, 255, 194, 14, AC_DIALOG_ALPHA);
            break;
        case DIALOG_A_BUTTON:
            gDPSetEnvColor(gDisplayListHead++, 77, 109, 243, AC_DIALOG_ALPHA);
            break;
        case DIALOG_B_BUTTON:
            gDPSetEnvColor(gDisplayListHead++, 34, 177, 76, AC_DIALOG_ALPHA);
            break;
        case DIALOG_Z_BUTTON:
        case DIALOG_R_BUTTON:
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, AC_DIALOG_ALPHA);
            break;
#endif
        case DIALOG_CHAR_COIN:
            gDPSetEnvColor(gDisplayListHead++, 253, 221, 96, AC_DIALOG_ALPHA);
            break;
        case DIALOG_CHAR_STAR_FILLED:
            gDPSetEnvColor(gDisplayListHead++, 232, 209, 22, AC_DIALOG_ALPHA);
            break;
        case DIALOG_CHAR_STAR_OPEN:
            gDPSetEnvColor(gDisplayListHead++, 97, 186, 70, AC_DIALOG_ALPHA);
            break;
        default:
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, AC_DIALOG_ALPHA);
            break;
    }

    gSPTextureRectangle(gDisplayListHead++, xCoord << 2, (yCoord - height) << 2,
                            (xCoord + width) << 2, yCoord << 2, G_TX_RENDERTILE, 0 << 6, 0 << 6, 1 << 10, 1 << 10);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define X_VAL3 5.0f
#define Y_VAL3 20
#else
#define X_VAL3 0.0f
#define Y_VAL3 16
#endif

void handle_dialog_scroll_page_state(s8 lineNum, s8 totalLines, s8 *pageState) {

    if (lineNum == totalLines) {
        pageState[0] = DIALOG_PAGE_STATE_SCROLL;
        return;
    }

    gDialogY += 15;
}

void render_star_count_dialog_text(struct DialogEntry *dialog)
{
    s8 tensDigit = gDialogVariable / 10;
    s8 onesDigit = gDialogVariable - (tensDigit * 10); // remainder

    if (tensDigit != 0) {
        render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, tensDigit);
#ifndef VERSION_JP
        gDialogX += gDialogCharWidths[tensDigit];
#else
        gDialogX += JP_X_SPACING;
#endif
    }

    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, onesDigit);
#ifndef VERSION_JP
    gDialogX += gDialogCharWidths[onesDigit];
#else
    gDialogX += JP_X_SPACING;
#endif
}

#if !defined(VERSION_JP) && !defined(VERSION_SH)
void render_multi_text_string_lines(s8 multiTextId, struct DialogEntry *dialog)
{
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

        for (i = 0; i < textLengths[multiTextId].length; i++) {
            render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, textLengths[multiTextId].str[i]);
            gDialogX += gDialogCharWidths[textLengths[multiTextId].str[i]];
        }
}
#endif

#ifdef MULTILANGUAGE
void render_dialog_lowercase_diacritic(struct DialogEntry *dialog, u8 chr, u8 diacritic) {
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, chr);
    render_generic_dialog_char_at_pos(dialog, gDialogX - 2, gDialogY, diacritic + 0xE7);
    gDialogX += gDialogCharWidths[chr];
}

void render_dialog_uppercase_diacritic(struct DialogEntry *dialog, u8 chr, u8 diacritic) {
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, chr);
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY - 4, diacritic + 0xE3);
    gDialogX += gDialogCharWidths[chr];
}
#endif

u32 ensure_nonnegative(s16 value) {
    if (value < 0) {
        value = 0;
    }

    return value;
}


void handle_dialog_text_and_pages(struct DialogEntry *dialog) {

    u8 strChar;

    u8 *str = segmented_to_virtual(dialog->str);
    s8 lineNum = 1;

    s8 totalLines;

    s8 pageState = DIALOG_PAGE_STATE_NONE;

    s8 linesPerBox = dialog->linesPerBox;

    s16 strIdx;

    strIdx = gDialogTextPos;

    gDialogX = 0;
    gDialogY = 14;


    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);

    if (gDialogBoxState == DIALOG_STATE_HORIZONTAL) {
        totalLines = linesPerBox * 2 + 1;
        //gDialogY -= gDialogScrollOffsetY;
    } else {
        totalLines = linesPerBox + 1;
    }

    while (pageState == DIALOG_PAGE_STATE_NONE) {

        strChar = str[strIdx];

        switch (strChar) {
            case DIALOG_CHAR_TERMINATOR:
                pageState = DIALOG_PAGE_STATE_END;
                break;
            case DIALOG_CHAR_NEWLINE:
                lineNum++;
                handle_dialog_scroll_page_state(lineNum, totalLines, &pageState);
                gDialogX = 0;
                break;
#ifdef MULTILANGUAGE
            case DIALOG_CHAR_LOWER_A_GRAVE:
            case DIALOG_CHAR_LOWER_A_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_A_UMLAUT:
            case DIALOG_CHAR_LOWER_A_ACUTE:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('a'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_A_GRAVE:
            case DIALOG_CHAR_UPPER_A_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_A_UMLAUT:
            case DIALOG_CHAR_UPPER_A_ACUTE:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('A'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_E_GRAVE:
            case DIALOG_CHAR_LOWER_E_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_E_UMLAUT:
            case DIALOG_CHAR_LOWER_E_ACUTE:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('e'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_E_GRAVE:
            case DIALOG_CHAR_UPPER_E_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_E_UMLAUT:
            case DIALOG_CHAR_UPPER_E_ACUTE:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('E'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_U_GRAVE:
            case DIALOG_CHAR_LOWER_U_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_U_UMLAUT:
            case DIALOG_CHAR_LOWER_U_ACUTE:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('u'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_U_GRAVE:
            case DIALOG_CHAR_UPPER_U_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_U_UMLAUT:
            case DIALOG_CHAR_UPPER_U_ACUTE:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('U'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_O_GRAVE:
            case DIALOG_CHAR_LOWER_O_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_O_UMLAUT:
            case DIALOG_CHAR_LOWER_O_ACUTE:
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('o'), strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_O_GRAVE:
            case DIALOG_CHAR_UPPER_O_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_O_UMLAUT:
            case DIALOG_CHAR_UPPER_O_ACUTE:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('O'), strChar & 0xF);
                break;
            case DIALOG_CHAR_LOWER_I_GRAVE:
            case DIALOG_CHAR_LOWER_I_CIRCUMFLEX:
            case DIALOG_CHAR_LOWER_I_UMLAUT:
            case DIALOG_CHAR_LOWER_I_ACUTE:
                render_dialog_lowercase_diacritic(dialog, DIALOG_CHAR_I_NO_DIA, strChar & 0xF);
                break;
            case DIALOG_CHAR_UPPER_I_GRAVE:
            case DIALOG_CHAR_UPPER_I_CIRCUMFLEX:
            case DIALOG_CHAR_UPPER_I_UMLAUT:
            case DIALOG_CHAR_UPPER_I_ACUTE:
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('I'), strChar & 0xF);
                break;
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
            case DIALOG_CHAR_DAKUTEN:
                render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY - 1, DIALOG_CHAR_DAKUTEN);
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY - 1, DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);
                break;
#endif
            case DIALOG_CHAR_SPACE:
#ifndef VERSION_JP
                gDialogX += gDialogCharWidths[DIALOG_CHAR_SPACE];
#else
                gDialogX += JP_X_SPACING;
#endif
                break;
#if defined(VERSION_JP) || defined(VERSION_SH)
            case DIALOG_CHAR_PERIOD:
                render_generic_dialog_char_at_pos(dialog, gDialogX - 6, gDialogY + 9, DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);
                break;
#else
            case DIALOG_CHAR_SLASH:
                gDialogX += gDialogCharWidths[DIALOG_CHAR_SPACE] * 2;
                break;
            case DIALOG_CHAR_MULTI_THE:
                render_multi_text_string_lines(STRING_THE, dialog);
                break;
            case DIALOG_CHAR_MULTI_YOU:
                render_multi_text_string_lines(STRING_YOU, dialog);
                break;
#endif
            case DIALOG_CHAR_STAR_COUNT:
                render_star_count_dialog_text(dialog);
                break;
            default: // any other character
                render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, strChar);
#ifndef VERSION_JP
                gDialogX += gDialogCharWidths[strChar];
#else
                gDialogX += JP_X_SPACING;
#endif
        }

        strIdx++;
        
        // Typewritter code, thanks to Pidgey (MCBoy) for helping me
        if (strIdx >= gDialogCharDisplay) {
            if (gDialogBoxState == DIALOG_STATE_VERTICAL && gSkipTypewriteEffect == FALSE) {
                if (gGlobalTimer % 1 == 0) {
                    gAllTextinPageRendered = FALSE; // all text in a page isn't rendered because is still writing, enforce it until it's done
                    play_sound(SOUND_MENU_BALLOON_CLICK, gDefaultSoundArgs);
                    gDialogCharDisplay++;

                }
                break;
            }
        }
        // After text rendering is done, tell dialogs that all text in a page is rendered
        gAllTextinPageRendered = TRUE;
    } // this is where the while loop ends

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    if (gDialogBoxState == DIALOG_STATE_VERTICAL) {
        if (pageState == DIALOG_PAGE_STATE_END) {
            gLastDialogPageStrPos = -1;
        } else {
            gLastDialogPageStrPos = strIdx;
        }
    }

    // If A or B button is pressed, render all chars in that page and enforce that all text in a page is rendered
    if (gSkipTypewriteEffect == TRUE && strIdx >= gDialogCharDisplay) {
        gDialogCharDisplay = strIdx;
        gAllTextinPageRendered = TRUE;
    // If all text in a page is rendered without pressing any button (aka you let it go to the end)
    } else if (gSkipTypewriteEffect == FALSE && gAllTextinPageRendered == TRUE && gDialogCharDisplay >= strIdx) {
        gSkipTypewriteEffect = TRUE;
    }

    gLastDialogLineNum = lineNum;
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define X_VAL1 -5.0f
#define Y_VAL1 2.0
#define Y_VAL2 4.0f
#define X_VAL4_1 50
#define X_VAL4_2 25
#define Y_VAL4_1 1
#define Y_VAL4_2 20
#else
#define X_VAL1 -7.0f
#define Y_VAL1 5.0
#define Y_VAL2 5.0f
#define X_VAL4_1 74
#define X_VAL4_2 60
#define Y_VAL4_1 2
#define Y_VAL4_2 16
#endif

void render_dialog_triangle_choice(struct DialogEntry *dialog, s8 linesPerBox) {

    create_dl_translation_matrix(MENU_MTX_NOPUSH, dialog->leftOffset, dialog->width, 0);
    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL1, Y_VAL1, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.1f, ((f32) linesPerBox / Y_VAL2) + 0.1, 1.0f);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    if (gDialogBoxState == DIALOG_STATE_VERTICAL) {
        handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, &gDialogLineNum, 1, 2);
    }

    create_dl_translation_matrix(MENU_MTX_NOPUSH, (gDialogLineNum * X_VAL4_1) - X_VAL4_2, Y_VAL4_1 - (gLastDialogLineNum * Y_VAL4_2), 0);

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, AC_DIALOG_ALPHA);

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
}

#ifdef VERSION_EU
#define X_VAL5 122.0f
#define Y_VAL5_1 -16
#define Y_VAL5_2 3
#define X_Y_VAL6 0.5f
#elif defined(VERSION_US)
#define X_VAL5 118.0f
#define Y_VAL5_1 -16
#define Y_VAL5_2 5
#define X_Y_VAL6 0.8f
#elif defined(VERSION_JP) || defined(VERSION_SH)
#define X_VAL5 123.0f
#define Y_VAL5_1 -20
#define Y_VAL5_2 2
#define X_Y_VAL6 0.8f
#endif

// Renders the blue arrow for the next dialog page, texture from Animal Forest
void render_dialog_arrow_next_page(void) {
    
    s16 x = 250;
    s16 y = 196;
    
    s32 timer = gGlobalTimer;

    if (timer & 0x08) {
        y++;
    } else {
        y--;
    }

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);

    gDPSetEnvColor(gDisplayListHead++, 193, 125, 32, 255);
    gSPDisplayList(gDisplayListHead++, dl_balloon_dialog_arrow_down_texblock);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, (1 << 10), (1 << 10));

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

void handle_special_dialog_text(s16 dialogID) { // dialog ID tables, in order
    // King Bob-omb (Start), Whomp (Start), King Bob-omb (throw him out), Eyerock (Start), Wiggler (Start)
    s16 dialogBossStart[] = { 17, 114, 128, 117, 150 };
    // Koopa the Quick (BOB), Koopa the Quick (THI), Penguin Race, Fat Penguin Race (120 stars)
    s16 dialogRaceSound[] = { 5, 9, 55, 164 };
    // Red Switch, Green Switch, Blue Switch, 100 coins star, Bowser Red Coin Star
    s16 dialogStarSound[] = { 10, 11, 12, 13, 14 };
    // King Bob-omb (Start), Whomp (Defeated), King Bob-omb (Defeated, missing in JP), Eyerock (Defeated), Wiggler (Defeated)
#if BUGFIX_KING_BOB_OMB_FADE_MUSIC
    s16 dialogBossStop[] = { 17, 115, 116, 118, 152 };
#else
    //! @bug JP misses King Bob-omb defeated dialog "116", meaning that the boss music will still
    //! play after King Bob-omb is defeated until BOB loads it's music after the star cutscene
    s16 dialogBossStop[] = { 17, 115, 118, 152 };
#endif
    s16 i;

    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStart); i++) {
        if (dialogBossStart[i] == dialogID) {
            sequence_player_unlower(SEQ_PLAYER_LEVEL, 60);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_BOSS), 0);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogRaceSound); i++) {
        if (dialogRaceSound[i] == dialogID && gDialogLineNum == 1) {
            play_race_fanfare();
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogStarSound); i++) {
        if (dialogStarSound[i] == dialogID && gDialogLineNum == 1) {
            play_sound(SOUND_MENU_STAR_SOUND, gDefaultSoundArgs);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStop); i++) {
        if (dialogBossStop[i] == dialogID) {
            sequence_player_fade_out(SEQ_PLAYER_LEVEL, 1);
            return;
        }
    }
}

s16 gMenuMode = -1;

u8 gEndCutsceneStrEn0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrEn1[] = { TEXT_POWER_STARS_RESTORED };
u8 gEndCutsceneStrEn2[] = { TEXT_THANKS_TO_YOU };
u8 gEndCutsceneStrEn3[] = { TEXT_THANK_YOU_MARIO };
u8 gEndCutsceneStrEn4[] = { TEXT_SOMETHING_SPECIAL };
u8 gEndCutsceneStrEn5[] = { TEXT_LISTEN_EVERYBODY };
u8 gEndCutsceneStrEn6[] = { TEXT_LETS_HAVE_CAKE };
u8 gEndCutsceneStrEn7[] = { TEXT_FOR_MARIO };
u8 gEndCutsceneStrEn8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsEn[] = {
    gEndCutsceneStrEn0,
    gEndCutsceneStrEn1,
    gEndCutsceneStrEn2,
    gEndCutsceneStrEn3,
    gEndCutsceneStrEn4,
    gEndCutsceneStrEn5,
    gEndCutsceneStrEn6,
    gEndCutsceneStrEn7,
    // This [8] string is actually unused. In the cutscene handler, the developers do not
    // set the 8th one, but use the first string again at the very end, so Peach ends up
    // saying "Mario!" twice. It is likely that she was originally meant to say "Mario?" at
    // the end but the developers changed their mind, possibly because the line recorded
    // sounded more like an exclamation than a question.
    gEndCutsceneStrEn8,
    NULL
};

#ifdef MULTILANGUAGE
u8 gEndCutsceneStrFr0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrFr1[] = { TEXT_POWER_STARS_RESTORED_FR };
u8 gEndCutsceneStrFr2[] = { TEXT_THANKS_TO_YOU_FR };
u8 gEndCutsceneStrFr3[] = { TEXT_THANK_YOU_MARIO_FR };
u8 gEndCutsceneStrFr4[] = { TEXT_SOMETHING_SPECIAL_FR };
u8 gEndCutsceneStrFr5[] = { TEXT_COME_ON_EVERYBODY_FR };
u8 gEndCutsceneStrFr6[] = { TEXT_LETS_HAVE_CAKE_FR };
u8 gEndCutsceneStrFr7[] = { TEXT_FOR_MARIO_FR };
u8 gEndCutsceneStrFr8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsFr[] = {
    gEndCutsceneStrFr0,
    gEndCutsceneStrFr1,
    gEndCutsceneStrFr2,
    gEndCutsceneStrFr3,
    gEndCutsceneStrFr4,
    gEndCutsceneStrFr5,
    gEndCutsceneStrFr6,
    gEndCutsceneStrFr7,
    gEndCutsceneStrFr8,
    NULL
};

u8 gEndCutsceneStrDe0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrDe1[] = { TEXT_POWER_STARS_RESTORED_DE };
u8 gEndCutsceneStrDe2[] = { TEXT_THANKS_TO_YOU_DE };
u8 gEndCutsceneStrDe3[] = { TEXT_THANK_YOU_MARIO_DE };
u8 gEndCutsceneStrDe4[] = { TEXT_SOMETHING_SPECIAL_DE };
u8 gEndCutsceneStrDe5[] = { TEXT_COME_ON_EVERYBODY_DE };
u8 gEndCutsceneStrDe6[] = { TEXT_LETS_HAVE_CAKE_DE };
u8 gEndCutsceneStrDe7[] = { TEXT_FOR_MARIO_DE };
u8 gEndCutsceneStrDe8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsDe[] = {
    gEndCutsceneStrDe0,
    gEndCutsceneStrDe1,
    gEndCutsceneStrDe2,
    gEndCutsceneStrDe3,
    gEndCutsceneStrDe4,
    gEndCutsceneStrDe5,
    gEndCutsceneStrDe6,
    gEndCutsceneStrDe7,
    gEndCutsceneStrDe8,
    NULL
};

u8 gEndCutsceneStrIt0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrIt1[] = { TEXT_POWER_STARS_RESTORED_IT };
u8 gEndCutsceneStrIt2[] = { TEXT_THANKS_TO_YOU_IT };
u8 gEndCutsceneStrIt3[] = { TEXT_THANK_YOU_MARIO_IT };
u8 gEndCutsceneStrIt4[] = { TEXT_SOMETHING_SPECIAL_IT };
u8 gEndCutsceneStrIt5[] = { TEXT_COME_ON_EVERYBODY_IT };
u8 gEndCutsceneStrIt6[] = { TEXT_LETS_HAVE_CAKE_IT };
u8 gEndCutsceneStrIt7[] = { TEXT_FOR_MARIO_IT };
u8 gEndCutsceneStrIt8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsIt[] = {
    gEndCutsceneStrIt0,
    gEndCutsceneStrIt1,
    gEndCutsceneStrIt2,
    gEndCutsceneStrIt3,
    gEndCutsceneStrIt4,
    gEndCutsceneStrIt5,
    gEndCutsceneStrIt6,
    gEndCutsceneStrIt7,
    gEndCutsceneStrIt8,
    NULL
};

u8 gEndCutsceneStrEs0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrEs1[] = { TEXT_POWER_STARS_RESTORED_ES };
u8 gEndCutsceneStrEs2[] = { TEXT_THANKS_TO_YOU_ES };
u8 gEndCutsceneStrEs3[] = { TEXT_THANK_YOU_MARIO_ES };
u8 gEndCutsceneStrEs4[] = { TEXT_SOMETHING_SPECIAL_ES };
u8 gEndCutsceneStrEs5[] = { TEXT_COME_ON_EVERYBODY_ES };
u8 gEndCutsceneStrEs6[] = { TEXT_LETS_HAVE_CAKE_ES };
u8 gEndCutsceneStrEs7[] = { TEXT_FOR_MARIO_ES };
u8 gEndCutsceneStrEs8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsEs[] = {
    gEndCutsceneStrEs0,
    gEndCutsceneStrEs1,
    gEndCutsceneStrEs2,
    gEndCutsceneStrEs3,
    gEndCutsceneStrEs4,
    gEndCutsceneStrEs5,
    gEndCutsceneStrEs6,
    gEndCutsceneStrEs7,
    gEndCutsceneStrEs8,
    NULL
};
#endif

u16 gCutsceneMsgFade = 0;
s16 gCutsceneMsgIndex = -1;
s16 gCutsceneMsgDuration = -1;
s16 gCutsceneMsgTimer = 0;
s8 gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
s8 gDialogCourseActNum = 1;

#if defined(VERSION_JP) || defined(VERSION_SH)
#define DIAG_VAL1 1
#define DIAG_VAL3 320
#define DIAG_VAL4 5
#else
#define DIAG_VAL1 1
#define DIAG_VAL3 320 // US & EU - expand text rendering
#define DIAG_VAL4 5
#endif
#ifdef VERSION_EU
#define DIAG_VAL2 238
#else
#define DIAG_VAL2 238 // JP & US
#endif

void render_dialog_entries(void) {
    void **dialogTable;
    struct DialogEntry *dialog;
#ifdef MULTILANGUAGE
    gInGameLanguage = eu_get_language();
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            dialogTable = segmented_to_virtual(dialog_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_de);
            break;
        case LANGUAGE_ITALIAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_it);
            break;
        case LANGUAGE_SPANISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_es);
            break;
    }
#else
    dialogTable = segmented_to_virtual(seg2_dialog_table);
#endif
    dialog = segmented_to_virtual(dialogTable[gDialogID]);

    // if the dialog entry is invalid, set the ID to -1.
    if (segmented_to_virtual(NULL) == dialog) {
        gDialogID = -1;
        return;
    }

    gDialogX = 0;
    gDialogY = 0;

    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            if (gDialogBoxOpenTimer == DEFAULT_DIALOG_BOX_ANGLE) {
                play_dialog_sound(gDialogID);
                play_sound(SOUND_MENU_MESSAGE_APPEAR, gDefaultSoundArgs);
            }

            if (gDialogBoxType == DIALOG_TYPE_ROTATE) {
                gDialogBoxOpenTimer -= 7.5;
                gDialogBoxScale -= 1.5;
            } else {
                gDialogBoxOpenTimer -= 10.0;
                gDialogBoxScale -= 2.0;
            }

            if (gDialogBoxOpenTimer == 0.0f) {
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                gDialogLineNum = 1;
            }
            break;
        case DIALOG_STATE_VERTICAL:
            gDialogBoxOpenTimer = 0.0f;

            if (gPlayer3Controller->buttonPressed & (A_BUTTON | B_BUTTON)) {
                if (gSkipTypewriteEffect == TRUE && gAllTextinPageRendered == TRUE) {
                    if (gLastDialogPageStrPos == -1) {
                        handle_special_dialog_text(gDialogID);
                        gDialogBoxState = DIALOG_STATE_CLOSING;
                    } else {
                        gDialogBoxState = DIALOG_STATE_HORIZONTAL;
//                        play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gDefaultSoundArgs);
                    }
                    gSkipTypewriteEffect = FALSE;
                } else {
                    gSkipTypewriteEffect = TRUE;
                    gAllTextinPageRendered = TRUE;
                }
            }
            break;
        case DIALOG_STATE_HORIZONTAL:
            gDialogScrollOffsetY += dialog->linesPerBox * 2;

            if (gDialogScrollOffsetY >= dialog->linesPerBox * DIAG_VAL1) {
                gDialogTextPos = gLastDialogPageStrPos;
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                gDialogScrollOffsetY = 0;
            }
            break;
        case DIALOG_STATE_CLOSING:
            if (gDialogBoxOpenTimer == 20.0f) {
                level_set_transition(0, 0);
                play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);

                if (gDialogBoxType == DIALOG_TYPE_ZOOM) {
                    trigger_cutscene_dialog(2);
                }

                gDialogResponse = gDialogLineNum;
            }

            gDialogBoxOpenTimer = gDialogBoxOpenTimer + 10.0f;
            gDialogBoxScale = gDialogBoxScale + 2.0f;

            if (gDialogBoxOpenTimer == DEFAULT_DIALOG_BOX_ANGLE) {
                gDialogBoxState = DIALOG_STATE_OPENING;
                gDialogID = -1;
                gDialogTextPos = 0;
                gLastDialogResponse = 0;
                gLastDialogPageStrPos = 0;
                gDialogResponse = 0;
                gDialogCharDisplay = 0;
                gSkipTypewriteEffect = FALSE;
                gAllTextinPageRendered = FALSE;
            }
            break;
    }


    render_balloon_dialog_texture(dialog);

    // don't print top name if is a generic dialog or a sign
    if (dialog->npcNameID != NPCNAME_NONE && dialog->npcNameID != NPCNAME_SIGN) {
        render_balloon_dialog_top_name(dialog, 30, 90);
    }

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE,
                ensure_nonnegative(dialog->leftOffset),
                ensure_nonnegative(DIAG_VAL2 - dialog->width),
                ensure_nonnegative(dialog->leftOffset + DIAG_VAL3 / gDialogBoxScale),
                ensure_nonnegative((236 - dialog->width) + ((dialog->linesPerBox * 80) / DIAG_VAL4) / gDialogBoxScale));

    handle_dialog_text_and_pages(dialog);

    if (gLastDialogPageStrPos == -1 && gLastDialogResponse == 1) {
        render_dialog_triangle_choice(dialog, dialog->linesPerBox);
    }
    
    #ifdef VERSION_EU
    #undef BORDER_HEIGHT
    #define BORDER_HEIGHT 8
    #endif
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 2, 2, SCREEN_WIDTH - BORDER_HEIGHT/2, SCREEN_HEIGHT - BORDER_HEIGHT/2);
    #ifdef VERSION_EU
    #undef BORDER_HEIGHT
    #define BORDER_HEIGHT 1
    #endif
    
    if (gLastDialogPageStrPos != -1 && gDialogBoxState == DIALOG_STATE_VERTICAL && gSkipTypewriteEffect == TRUE && gAllTextinPageRendered == TRUE) {
        render_dialog_arrow_next_page();
    }
}

// Calls a gMenuMode value defined by render_menus_and_dialogs cases
void set_menu_mode(s16 mode) {
    if (gMenuMode == -1) {
        gMenuMode = mode;
    }
}

void reset_cutscene_msg_fade(void) {
    gCutsceneMsgFade = 0;
}

void dl_rgba16_begin_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
}

void dl_rgba16_stop_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    if (gCutsceneMsgFade < 250) {
        gCutsceneMsgFade += 25;
    } else {
        gCutsceneMsgFade = 255;
    }
}

/**
u8 ascii_to_credits_char(u8 c) {
    if (c >= 'A' && c <= 'Z') {
        return (c - ('A' - 0xA));
    }

    if (c >= 'a' && c <= 'z') { // remap lower to upper case
        return (c - ('a' - 0xA));
    }

    if (c == ' ') {
        return GLOBAL_CHAR_SPACE;
    }
    if (c == '.') {
        return 0x24;
    }
    if (c == '3') {
        return ASCII_TO_DIALOG('3');
    }
    if (c == '4') {
        return ASCII_TO_DIALOG('4');
    }
    if (c == '6') {
        return ASCII_TO_DIALOG('6');
    }

    return GLOBAL_CHAR_SPACE;
}

void print_credits_str_ascii(s16 x, s16 y, const char *str) {
    s32 pos = 0;
    u8 c = str[pos];
    u8 creditStr[100];

    while (c != 0) {
        creditStr[pos++] = ascii_to_credits_char(c);
        c = str[pos];
    }

    creditStr[pos] = GLOBAR_CHAR_TERMINATOR;

    print_credits_string(x, y, creditStr);
}
*/

void set_cutscene_message(s16 xOffset, s16 yOffset, s16 msgIndex, s16 msgDuration) {
    // is message done printing?
    if (gCutsceneMsgIndex == -1) {
        gCutsceneMsgIndex = msgIndex;
        gCutsceneMsgDuration = msgDuration;
        gCutsceneMsgTimer = 0;
        gCutsceneMsgXOffset = xOffset;
        gCutsceneMsgYOffset = yOffset;
        gCutsceneMsgFade = 0;
    }
}

void do_cutscene_handler(void) {
    s16 x;

    // is a cutscene playing? do not perform this handler's actions if so.
    if (gCutsceneMsgIndex == -1) {
        return;
    }

    create_dl_ortho_matrix();

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);

#ifdef MULTILANGUAGE
    switch (eu_get_language()) {
        case LANGUAGE_ENGLISH:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_FRENCH:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsFr[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsFr[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_GERMAN:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsDe[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsDe[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_ITALIAN:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsIt[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsIt[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_SPANISH:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEs[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEs[gCutsceneMsgIndex]);
            break;
    }
#else
    // get the x coordinate of where the cutscene string starts.
    x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex], 10.0f);

    print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex]);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    // if the timing variable is less than 5, increment
    // the fade until we are at full opacity.
    if (gCutsceneMsgTimer < 5) {
        gCutsceneMsgFade += 50;
    }

    // if the cutscene frame length + the fade-in counter is
    // less than the timer, it means we have exceeded the
    // time that the message is supposed to remain on
    // screen. if (message_duration = 50) and (msg_timer = 55)
    // then after the first 5 frames, the message will remain
    // on screen for another 50 frames until it starts fading.
    if (gCutsceneMsgDuration + 5 < gCutsceneMsgTimer) {
        gCutsceneMsgFade -= 50;
    }

    // like the first check, it takes 5 frames to fade out, so
    // perform a + 10 to account for the earlier check (10-5=5).
    if (gCutsceneMsgDuration + 10 < gCutsceneMsgTimer) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0;
        gCutsceneMsgTimer = 0;
        return;
    }

    gCutsceneMsgTimer++;
}

void render_ac_base_logo_titlescreen(void) {

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);

    gSPDisplayList(gDisplayListHead++, dl_alo_ac_logo_base_titlescreen);

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
u8 textShizue64[] = { JP_SHIZUE64_TXT };
u8 textPressStartJP[] = { JP_PRESS_START_TXT };
u8 textNoControllerJP[] = { JP_NO_CONTROLLER_TEXT };
#else

//u8 textMiNinaBonita[] = { TEXT_MI_NINA_BONITA };

struct ShzTitleScreen {
    Gfx *shzTexture;
    char *pressStartStr;
    char *noControllerStr;
};

struct ShzTitleScreen sShzTitleScreenDefines[] = {
    { dl_alo_isabelle_logo_titlescreen, "Press Start Button", "No Controller" },
    { dl_alo_marie_logo_titlescreen, "Appuyez sur Start", "Manette debranchee" },
    { dl_alo_melinda_logo_titlescreen, "Drücke den Startknopf", "Controller fehlt" },
    { dl_alo_fuffi_logo_titlescreen, "Premi il pulsante Start", "Nessun controller" },
    { dl_alo_canela_logo_titlescreen, "Pulsa el boton Start", "No hay controlador" },
};
#endif
void render_title_screen_textures(void) {
#ifndef VERSION_JP
    struct ShzTitleScreen *titleScreen = &sShzTitleScreenDefines[gInGameLanguage];
#endif
    gInGameLanguage = eu_get_language();

    render_custom_texrect(dl_alo_pixel_shz_titlescreen, FALSE, TRUE, G_TT_RGBA16, 80, 18, 32, 32);
    render_ac_base_logo_titlescreen();
    render_custom_texrect(dl_alo_leaf64_titlescreen, TRUE, TRUE, G_TT_RGBA16, 186, 26, 32, 32);

#ifndef VERSION_JP
    render_custom_texrect(titleScreen->shzTexture, TRUE, FALSE, G_TT_NONE, 92, 59, 128, 32);
#else
    render_custom_texrect(dl_alo_shizue_logo_titlescreen, TRUE, FALSE, G_TT_NONE, 92, 59, 128, 32);
#endif
    render_custom_texrect(dl_alo_year_name_titlescreen, FALSE, FALSE, G_TT_NONE, 32, 200, 256, 16);

    if ((gGlobalTimer & 0x1F) < 20) {
        if (gControllerBits == 0) {
            print_generic_string_shadow(ASCII_PRINT_CHR, 90, 52, 230, 230, 230, 255, 1, titleScreen->noControllerStr, NULL);
        } else {
            //print_generic_string_shadow(DEF_PRINT_CHR, 90, 52, 230, 230, 230, 255, 1, NULL, textMiNinaBonita);
            print_generic_string_shadow(ASCII_PRINT_CHR, 90, 52, 230, 230, 230, 255, 1, titleScreen->pressStartStr, NULL);
        }
    }

    print_generic_string_shadow(ASCII_PRINT_CHR, 256, 4, 230, 230, 230, 255, 1, "Ver. 1.3", NULL);
#if defined(VERSION_JP) || defined(VERSION_SH)
    print_generic_string_shadow(DEF_PRINT_CHR, 80, 120, 230, 230, 230, 255, 1, NULL, textShizue64);
#endif
}

#ifndef VERSION_JP
extern Gfx castle_grounds_seg7_us_dl_0700F2E8[];
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
#define PEACH_MESSAGE_TIMER 170
#else
#define PEACH_MESSAGE_TIMER 250
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
#define STR_X 53
#define STR_Y 136
#else
#define STR_X 38
#define STR_Y 142
#endif

// "Dear Mario" message handler
void print_peach_letter_message(void) {
    void **dialogTable;
    struct DialogEntry *dialog;
    u8 *str;
#ifdef MULTILANGUAGE
    gInGameLanguage = eu_get_language();
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            dialogTable = segmented_to_virtual(dialog_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_de);
            break;
        case LANGUAGE_ITALIAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_it);
            break;
        case LANGUAGE_SPANISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_es);
            break;
    }
#else
    dialogTable = segmented_to_virtual(seg2_dialog_table);
#endif
    dialog = segmented_to_virtual(dialogTable[gDialogID]);

    str = segmented_to_virtual(dialog->str);

    create_dl_translation_matrix(MENU_MTX_PUSH, 97.0f, 118.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_dl_0700EA58);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 20, 20, 20, gCutsceneMsgFade);

    print_generic_string(STR_X, STR_Y, str);
#if defined(VERSION_JP) || defined(VERSION_SH)
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
#endif
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
#ifndef VERSION_JP
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    gDPSetEnvColor(gDisplayListHead++, 200, 80, 120, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_us_dl_0700F2E8);
#endif

    // at the start/end of message, reset the fade.
    if (gCutsceneMsgTimer == 0) {
        gCutsceneMsgFade = 0;
    }

    // we're less than 20 increments, so increase the fade.
    if (gCutsceneMsgTimer < 20) {
        gCutsceneMsgFade += 10;
    }

    // we're after PEACH_MESSAGE_TIMER increments, so decrease the fade.
    if (gCutsceneMsgTimer > PEACH_MESSAGE_TIMER) {
        gCutsceneMsgFade -= 10;
    }

    // 20 increments after the start of the decrease, we're
    // back where we are, so reset everything at the end.
    if (gCutsceneMsgTimer > (PEACH_MESSAGE_TIMER + 20)) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0; //! uselessly reset since the next execution will just set it to 0 again.
        gDialogID = -1;
        gCutsceneMsgTimer = 0;
        return; // return to avoid incrementing the timer
    }

    gCutsceneMsgTimer++;
}

/**
 * Renders the cannon reticle when Mario is inside a cannon.
 * Formed by four triangles.
 */
void render_hud_cannon_reticle(void) {
    create_dl_translation_matrix(MENU_MTX_PUSH, 160.0f, 120.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 50, 50, 50, 180);
    create_dl_translation_matrix(MENU_MTX_PUSH, -20.0f, -8.0f, 0);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 20.0f, 8.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 180.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 8.0f, -20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, -8.0f, 20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void reset_red_coins_collected(void) {
    gRedCoinsCollected = 0;
}

void change_dialog_camera_angle(void) {
    if (cam_select_alt_mode(0) == CAM_SELECTION_MARIO) {
        gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
    } else {
        gDialogCameraAngleIndex = CAM_SELECTION_FIXED;
    }
}

// With scrolling - Scrolling background code used in Pyoro64 by buu342
void background_scene(void) {
    
    static float time = 0;
    
    time += 0.5;

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);
    
    gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
    
    gSPDisplayList(gDisplayListHead++, dl_alo_ac_bg_menus);
    
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    gSPScisTextureRectangle(gDisplayListHead++, 0 << 2, 0 << 2, (0 + SCREEN_WIDTH) << 2, (0 + SCREEN_HEIGHT) << 2, G_TX_RENDERTILE, 
            ((int)(64-time))%64 << 5, ((int)(64-time))%64 << 5, (1 << 10), (1 << 10));

    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

/**
void print_animated_red_coin(s16 x, s16 y) {
    s32 timer = gGlobalTimer;

    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.2f, 0.2f, 1.0f);
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    switch (timer & 6) {
        case 0:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_03007940);
            break;
        case 2:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_03007968);
            break;
        case 4:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_03007990);
            break;
        case 6:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_030079B8);
            break;
    }

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void render_pause_red_coins(void) {
    s8 x;

    for (x = 0; x < gRedCoinsCollected; x++) {
        print_animated_red_coin(290 - x * 20, 16);
    }
}
 */
 
#ifdef MULTILANGUAGE
u8 gTextCourseArr[][7] = { // D_802FDA10
    { TEXT_COURSE },
    { TEXT_COURSE_FR },
    { TEXT_COURSE_DE },
    { TEXT_COURSE_IT },
    { TEXT_COURSE_ES }
};
#endif

#if defined(VERSION_JP) || defined(VERSION_SH)
#define CRS_NUM_X1 93
#else
#define CRS_NUM_X1 100
#endif
#ifdef VERSION_EU
#define TXT_STAR_X 89
#define ACT_NAME_X 107
#define LVL_NAME_X 108
#define MYSCORE_X  48
#else
#define TXT_STAR_X 98
#define ACT_NAME_X 116
#define LVL_NAME_X 117
#define MYSCORE_X  62
#endif

void render_pause_my_score_coins(void) {
#ifdef MULTILANGUAGE
    u8 textMyScore[][11] = {
        { TEXT_MY_SCORE },
        { TEXT_MY_SCORE_FR },
        { TEXT_MY_SCORE_DE },
        { TEXT_MY_SCORE_IT },
        { TEXT_MY_SCORE_ES }
    };
#define textMyScore textMyScore[gInGameLanguage]
#else
    u8 textCourse[] = { TEXT_COURSE };
    u8 textMyScore[] = { TEXT_MY_SCORE };
#endif
    u8 textStar[] = { TEXT_STAR };
    u8 textUnfilledStar[] = { TEXT_UNFILLED_STAR };

    u8 strCourseNum[4];
    void **courseNameTbl;
    u8 *courseName;
    void **actNameTbl;
    u8 *actName;
    u8 courseIndex;
    u8 starFlags;

#ifndef MULTILANGUAGE
    //courseNameTbl = segmented_to_virtual(seg2_course_name_table);
    //actNameTbl = segmented_to_virtual(seg2_act_name_table);
#endif

    courseIndex = gCurrCourseNum - 1;
    starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);

#ifdef MULTILANGUAGE
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_en);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_fr);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_de);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
        case LANGUAGE_ITALIAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_it);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_it);
            break;
        case LANGUAGE_SPANISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_es);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_es);
            break;
    }
#endif

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    if (courseIndex < COURSE_STAGES_COUNT) {
        print_hud_my_score_coins(1, gCurrSaveFileNum - 1, courseIndex, 178, 103);
        print_hud_my_score_stars(gCurrSaveFileNum - 1, courseIndex, 118, 103);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    if (courseIndex < COURSE_STAGES_COUNT && save_file_get_course_star_count(gCurrSaveFileNum - 1, courseIndex) != 0) {
        print_generic_string(MYSCORE_X, 121, textMyScore);
    }

    courseName = segmented_to_virtual(courseNameTbl[courseIndex]);

    if (courseIndex < COURSE_STAGES_COUNT) {
#ifdef MULTILANGUAGE
        print_generic_string(48, 157, gTextCourseArr[gInGameLanguage]);
#else
        print_generic_string(63, 157, textCourse);
#endif
        int_to_str(gCurrCourseNum, strCourseNum);
#ifdef MULTILANGUAGE
        print_generic_string(get_string_width(gTextCourseArr[gInGameLanguage]) + 51, 157, strCourseNum);
#else
        print_generic_string(CRS_NUM_X1, 157, strCourseNum);
#endif

        actName = segmented_to_virtual(actNameTbl[(gCurrCourseNum - 1) * 6 + gDialogCourseActNum - 1]);

        if (starFlags & (1 << (gDialogCourseActNum - 1))) {
            print_generic_string(TXT_STAR_X, 140, textStar);
        } else {
            print_generic_string(TXT_STAR_X, 140, textUnfilledStar);
        }
        print_generic_string(ACT_NAME_X, 140, actName);
#ifndef VERSION_JP
        print_generic_string(LVL_NAME_X, 157, &courseName[3]);
#endif
    }
#ifndef VERSION_JP
    else {
#ifdef VERSION_US
        print_generic_string(94, 157, &courseName[3]);
#elif defined(VERSION_EU)
        print_generic_string(get_str_x_pos_from_center(159, &courseName[3], 10.0f), 157, &courseName[3]);
#endif
    }
#else
    print_generic_string(117, 157, &courseName[3]);
#endif
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define TXT1_X 4
#define TXT2_X 116
#define Y_VAL7 0
#else
#define TXT1_X 3
#define TXT2_X 119
#define Y_VAL7 2
#endif

void render_pause_camera_options(s16 x, s16 y, s8 *index, s16 xIndex) {
    u8 textLakituMario[] = { TEXT_LAKITU_MARIO };
    u8 textLakituStop[] = { TEXT_LAKITU_STOP };
#ifdef MULTILANGUAGE
    u8 textNormalUpClose[][23] = {
        { TEXT_NORMAL_UPCLOSE },
        { TEXT_NORMAL_UPCLOSE_FR },
        { TEXT_NORMAL_UPCLOSE_DE },
        { TEXT_NORMAL_UPCLOSE_IT },
        { TEXT_NORMAL_UPCLOSE_ES }
    };
    u8 textNormalFixed[][17] = {
        { TEXT_NORMAL_FIXED },
        { TEXT_NORMAL_FIXED_FR },
        { TEXT_NORMAL_FIXED_DE },
        { TEXT_NORMAL_FIXED_IT },
        { TEXT_NORMAL_FIXED_ES }
    };
#define textNormalUpClose textNormalUpClose[gInGameLanguage]
#define textNormalFixed   textNormalFixed[gInGameLanguage]
#else
    u8 textNormalUpClose[] = { TEXT_NORMAL_UPCLOSE };
    u8 textNormalFixed[] = { TEXT_NORMAL_FIXED };
#endif

    handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, index, 1, 2);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(x + 14, y + 2, textLakituMario);
    print_generic_string(x + TXT1_X, y - 13, textNormalUpClose);
    print_generic_string(x + 124, y + 2, textLakituStop);
    print_generic_string(x + TXT2_X, y - 13, textNormalFixed);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    create_dl_translation_matrix(MENU_MTX_PUSH, ((index[0] - 1) * xIndex) + x, y + Y_VAL7, 0);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    switch (index[0]) {
        case 1:
            cam_select_alt_mode(1);
            break;
        case 2:
            cam_select_alt_mode(2);
            break;
    }
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define X_VAL8 0
#define Y_VAL8 4
#else
#define X_VAL8 4
#define Y_VAL8 2
#endif

void render_pause_course_options(s16 x, s16 y, s8 *index, s16 yIndex) {
#ifdef MULTILANGUAGE
    u8 textContinue[][10] = {
        { TEXT_CONTINUE },
        { TEXT_CONTINUE_FR },
        { TEXT_CONTINUE_DE },
        { TEXT_CONTINUE_IT },
        { TEXT_CONTINUE_ES }
    };
    u8 textExitCourse[][16] = {
        { TEXT_EXIT_COURSE },
        { TEXT_EXIT_COURSE_FR },
        { TEXT_EXIT_COURSE_DE },
        { TEXT_EXIT_COURSE_IT },
        { TEXT_EXIT_COURSE_ES }
    };
    u8 textCameraAngleR[][24] = {
        { TEXT_CAMERA_ANGLE_R },
        { TEXT_CAMERA_ANGLE_R_FR },
        { TEXT_CAMERA_ANGLE_R_DE },
        { TEXT_CAMERA_ANGLE_R_IT },
        { TEXT_CAMERA_ANGLE_R_ES }
    };
#define textContinue     textContinue[gInGameLanguage]
#define textExitCourse   textExitCourse[gInGameLanguage]
#define textCameraAngleR textCameraAngleR[gInGameLanguage]
#else
    u8 textContinue[] = { TEXT_CONTINUE };
    u8 textExitCourse[] = { TEXT_EXIT_COURSE };
    u8 textCameraAngleR[] = { TEXT_CAMERA_ANGLE_R };
#endif

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, 3);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(x + 10, y - 2, textContinue);
    print_generic_string(x + 10, y - 17, textExitCourse);

    if (index[0] != 3) {
        print_generic_string(x + 10, y - 33, textCameraAngleR);
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

        create_dl_translation_matrix(MENU_MTX_PUSH, x - X_VAL8, (y - ((index[0] - 1) * yIndex)) - Y_VAL8, 0);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    if (index[0] == 3) {
        render_pause_camera_options(x - 42, y - 42, &gDialogCameraAngleIndex, 110);
    }
}

void render_pause_castle_menu_box(s16 x, s16 y) {
    create_dl_translation_matrix(MENU_MTX_PUSH, x - 78, y - 32, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.2f, 0.8f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 105);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x + 6, y - 28, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, DEFAULT_DIALOG_BOX_ANGLE, 0, 0, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x - 9, y - 101, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 270.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void highlight_last_course_complete_stars(void) {
    u8 courseDone;

    if (gLastCompletedCourseNum == COURSE_NONE) {
        courseDone = 0;
    } else {
        courseDone = gLastCompletedCourseNum - 1;

        if (courseDone >= COURSE_STAGES_COUNT) {
            courseDone = COURSE_STAGES_COUNT;
        }
    }

    gDialogLineNum = courseDone;
}

void print_hud_pause_colorful_str(void) {

    u8 textPause[][6] = {
        { TEXT_PAUSE },
        { TEXT_PAUSE },
        { TEXT_PAUSE },
        { TEXT_PAUSA },
        { TEXT_PAUSA }
    }; 
    
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_hud_lut_string(HUD_LUT_GLOBAL, get_str_x_pos_from_center_scale(SCREEN_WIDTH / 2, textPause[gInGameLanguage], 12.0f), 32, textPause[gInGameLanguage]);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void render_pause_castle_course_stars(s16 x, s16 y, s16 fileNum, s16 courseNum) {
    s16 hasStar = 0;

    u8 str[COURSE_STAGES_COUNT * 2];

    u8 textStar[] = { TEXT_STAR };

    u8 starFlags = save_file_get_star_flags(fileNum, courseNum);
    u16 starCount = save_file_get_course_star_count(fileNum, courseNum);

    u16 nextStar = 0;

    if (starFlags & 0x40) {
        starCount--;
        print_generic_string(x + 89, y - 5, textStar);
    }

    while (hasStar != starCount) {
        if (starFlags & (1 << nextStar)) {
            str[nextStar * 2] = DIALOG_CHAR_STAR_FILLED;
            hasStar++;
        } else {
            str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
        }

        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
        nextStar++;
    }

    if (starCount == nextStar && starCount != 6) {
        str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
        nextStar++;
    }

    str[nextStar * 2] = DIALOG_CHAR_TERMINATOR;

    print_generic_string(x + 14, y + 13, str);
}

void render_pause_castle_main_strings(s16 x, s16 y) {
#ifdef MULTILANGUAGE
    void **courseNameTbl;
#else
    void **courseNameTbl = segmented_to_virtual(seg2_course_name_table);
#endif

#ifdef VERSION_EU
    u8 textCoin[] = { TEXT_COIN };
    u8 textX[] = { TEXT_VARIABLE_X };
#else
    u8 textCoin[] = { TEXT_COIN_X };
#endif

    void *courseName;

    u8 strVal[8];
    s16 starNum = gDialogLineNum;

#ifdef MULTILANGUAGE
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
        case LANGUAGE_ITALIAN:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_it);
            break;
        case LANGUAGE_SPANISH:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_es);
            break;
    }
#endif

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, &gDialogLineNum, -1, COURSE_STAGES_COUNT + 1);

    if (gDialogLineNum == COURSE_STAGES_COUNT + 1) {
        gDialogLineNum = 0;
    }

    if (gDialogLineNum == -1) {
        gDialogLineNum = COURSE_STAGES_COUNT;
    }

    if (gDialogLineNum != COURSE_STAGES_COUNT) {
        while (save_file_get_course_star_count(gCurrSaveFileNum - 1, gDialogLineNum) == 0) {
            if (gDialogLineNum >= starNum) {
                gDialogLineNum++;
            } else {
                gDialogLineNum--;
            }

            if (gDialogLineNum == COURSE_STAGES_COUNT || gDialogLineNum == -1) {
                gDialogLineNum = COURSE_STAGES_COUNT;
                break;
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    if (gDialogLineNum < COURSE_STAGES_COUNT) {
        courseName = segmented_to_virtual(courseNameTbl[gDialogLineNum]);
        render_pause_castle_course_stars(x, y, gCurrSaveFileNum - 1, gDialogLineNum);
        print_generic_string(x + 34, y - 5, textCoin);
#ifdef VERSION_EU
        print_generic_string(x + 44, y - 5, textX);
#endif
        int_to_str(save_file_get_course_coin_score(gCurrSaveFileNum - 1, gDialogLineNum), strVal);
        print_generic_string(x + 54, y - 5, strVal);
#ifdef VERSION_EU
        print_generic_string(x - 17, y + 30, courseName);
#endif
    } else {
        u8 textStarX[] = { TEXT_STAR_X };
        courseName = segmented_to_virtual(courseNameTbl[COURSE_MAX]);
        print_generic_string(x + 40, y + 13, textStarX);
        int_to_str(save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_BONUS_STAGES - 1, COURSE_MAX - 1), strVal);
        print_generic_string(x + 60, y + 13, strVal);
#ifdef VERSION_EU
        print_generic_string(get_str_x_pos_from_center(x + 51, courseName, 10.0f), y + 30, courseName);
#endif
    }

#ifndef VERSION_EU
    print_generic_string(x - 9, y + 30, courseName);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

s8 gCourseCompleteCoinsEqual = 0;
s32 gCourseDoneMenuTimer = 0;
s32 gCourseCompleteCoins = 0;
s8 gHudFlash = 0;
s8 gPauseScreenPage = 0;

s16 render_pause_courses_and_castle(void) {
    s16 num;

#ifdef MULTILANGUAGE
    gInGameLanguage = eu_get_language();
#endif

    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            gDialogLineNum = 1;
            gDialogTextAlpha = 0;
            level_set_transition(-1, 0);

            play_sound(SOUND_MENU_APPOPEN_ACNH, gDefaultSoundArgs);

            if (gCurrCourseNum >= COURSE_MIN && gCurrCourseNum <= COURSE_MAX) {
                change_dialog_camera_angle();
                gDialogBoxState = DIALOG_STATE_VERTICAL;
            } else {
                highlight_last_course_complete_stars();
                gDialogBoxState = DIALOG_STATE_HORIZONTAL;
            }
            break;
        case DIALOG_STATE_VERTICAL:
            background_scene();

            switch (gPauseScreenPage) {
                case 0:
                    render_pause_my_score_coins();

                    if (gMarioStates[0].action & ACT_FLAG_PAUSE_EXIT) {
                    render_pause_course_options(99, 93, &gDialogLineNum, 15);
                    }

                    if (gPlayer3Controller->buttonPressed & R_TRIG) {
                        play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
                        gPauseScreenPage += 1;
                    }

                    if (gPlayer3Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
                        level_set_transition(0, 0);
                        play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
                        gDialogBoxState = DIALOG_STATE_OPENING;
                        gMenuMode = -1;
                        gPauseScreenPage = 0; // return to main pause page

                        if (gDialogLineNum == 2) {
                            num = gDialogLineNum;
                        } else {
                            num = 1;
                        }

                        return num;
                    }
                    break;
                case 1:
                        render_alternate_costume_menu();

                        if (gPlayer3Controller->buttonPressed & START_BUTTON) {
                            level_set_transition(0, 0);
                            play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
                            gMenuMode = -1;
                            gDialogBoxState = DIALOG_STATE_OPENING;
                            gPauseScreenPage = 0; // return to main pause page

                            return 1;
                        }

                        if (gPlayer3Controller->buttonPressed & L_TRIG) {
                            play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
                            gPauseScreenPage -= 1;
                        }
                        break;
                }
                break;
        case DIALOG_STATE_HORIZONTAL:
            background_scene();

            switch (gPauseScreenPage) {
                case 0:
                    print_hud_pause_colorful_str();
                    render_pause_castle_main_strings(104, 60);

                    if (gPlayer3Controller->buttonPressed & R_TRIG) {
                        play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
                        gPauseScreenPage += 1;
                    }

                    if (gPlayer3Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
                        level_set_transition(0, 0);
                        play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
                        gMenuMode = -1;
                        gDialogBoxState = DIALOG_STATE_OPENING;
                        gPauseScreenPage = 0; // return to main pause page

                        return 1;
                    }
                    break;
                case 1:
                    render_alternate_costume_menu();

                    if (gPlayer3Controller->buttonPressed & START_BUTTON) {
                        level_set_transition(0, 0);
                        play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gDefaultSoundArgs);
                        gMenuMode = -1;
                        gDialogBoxState = DIALOG_STATE_OPENING;
                        gPauseScreenPage = 0; // return to main pause page

                        return 1;
                    }

                    if (gPlayer3Controller->buttonPressed & L_TRIG) {
                        play_sound(SOUND_MENU_HOVER_ACNH, gDefaultSoundArgs);
                        gPauseScreenPage -= 1;
                    }

                    break;
                }
                break;
        }

    if (gDialogTextAlpha < 250) {
        gDialogTextAlpha += 25;
    }

    return 0;
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define TXT_HISCORE_X 112
#define TXT_HISCORE_Y 48
#define TXT_CONGRATS_X 60
#else
#define TXT_HISCORE_X 109
#define TXT_HISCORE_Y 36
#define TXT_CONGRATS_X 70
#endif

#define HUD_PRINT_HISCORE         0
#define HUD_PRINT_CONGRATULATIONS 1

void print_hud_course_complete_string(s8 str) {
#ifdef MULTILANGUAGE
    u8 textHiScore[][15] = {
        { TEXT_HUD_HI_SCORE },
        { TEXT_HUD_HI_SCORE_FR },
        { TEXT_HUD_HI_SCORE_DE },
        { TEXT_HUD_HI_SCORE_IT },
        { TEXT_HUD_HI_SCORE_ES }
    };
    u8 textCongratulations[][16] = {
        { TEXT_HUD_CONGRATULATIONS },
        { TEXT_HUD_CONGRATULATIONS_FR },
        { TEXT_HUD_CONGRATULATIONS_DE },
        { TEXT_HUD_CONGRATULATIONS_IT },
        { TEXT_HUD_CONGRATULATIONS_ES }
    };
#else
    u8 textHiScore[] = { TEXT_HUD_HI_SCORE };
    u8 textCongratulations[] = { TEXT_HUD_CONGRATULATIONS };
#endif

    u8 colorFade = sins(gDialogColorFadeTimer) * 50.0f + 200.0f;

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, colorFade, colorFade, colorFade, 255);

    if (str == HUD_PRINT_HISCORE) {
#ifdef MULTILANGUAGE
        print_hud_lut_string(HUD_LUT_GLOBAL, get_str_x_pos_from_center_scale(160, textHiScore[gInGameLanguage], 12.0f),
                  36, textHiScore[gInGameLanguage]);
#else
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_HISCORE_X, TXT_HISCORE_Y, textHiScore);
#endif
    } else { // HUD_PRINT_CONGRATULATIONS
#ifdef MULTILANGUAGE
        print_hud_lut_string(HUD_LUT_GLOBAL, get_str_x_pos_from_center_scale(160, textCongratulations[gInGameLanguage], 12.0f),
                  67, textCongratulations[gInGameLanguage]);
#else
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_CONGRATS_X, 67, textCongratulations);
#endif
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void print_hud_course_complete_coins(s16 x, s16 y) {
    u8 courseCompleteCoinsStr[4];
    u8 hudTextSymCoin[] = { GLYPH_COIN, GLYPH_SPACE };
    u8 hudTextSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    print_hud_lut_string(HUD_LUT_GLOBAL, x, y, hudTextSymCoin);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, hudTextSymX);

    int_to_str(gCourseCompleteCoins, courseCompleteCoinsStr);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, courseCompleteCoinsStr);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    if (gCourseCompleteCoins >= gHudDisplay.coins) {
        gCourseCompleteCoinsEqual = 1;
        gCourseCompleteCoins = gHudDisplay.coins;

        if (gGotFileCoinHiScore != 0) {
            print_hud_course_complete_string(HUD_PRINT_HISCORE);
        }
    } else {
        if ((gCourseDoneMenuTimer & 1) || gHudDisplay.coins > 70) {
            gCourseCompleteCoins++;
            play_sound(SOUND_MENU_YOSHI_GAIN_LIVES, gDefaultSoundArgs);

            if (gCourseCompleteCoins == 50 || gCourseCompleteCoins == 100 || gCourseCompleteCoins == 150) {
                play_sound(SOUND_GENERAL_COLLECT_1UP, gDefaultSoundArgs);
                gMarioState[0].numLives++;
            }
        }

        if (gHudDisplay.coins == gCourseCompleteCoins && gGotFileCoinHiScore != 0) {
            play_sound(SOUND_MENU_MARIO_CASTLE_WARP2, gDefaultSoundArgs);
        }
    }
}

void play_star_fanfare_and_flash_hud(s32 arg, u8 starNum) {
    if (gHudDisplay.coins == gCourseCompleteCoins && (gCurrCourseStarFlags & starNum) == 0 && gHudFlash == 0) {
        play_star_fanfare();
        gHudFlash = arg;
    }
}

#ifdef MULTILANGUAGE
#define TXT_NAME_X1 centerX
#define TXT_NAME_X2 centerX - 1
#else
#define TXT_NAME_X1 71
#define TXT_NAME_X2 69
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
#define CRS_NUM_X2 95
#define CRS_NUM_X3 93
#define TXT_CLEAR_X1 205
#define TXT_CLEAR_X2 203
#else
#define CRS_NUM_X2 104
#define CRS_NUM_X3 102
#define TXT_CLEAR_X1 get_string_width(name) + 81
#define TXT_CLEAR_X2 get_string_width(name) + 79
#endif

void render_course_complete_lvl_info_and_hud_str(void) {
#if defined(VERSION_JP) || defined(VERSION_SH)
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
    u8 textCourse[] = { TEXT_COURSE };
    u8 textCatch[] = { TEXT_CATCH };
    u8 textClear[] = { TEXT_CLEAR };
#else
    UNUSED u8 textCourse[] = { TEXT_COURSE };
    UNUSED u8 textCatch[] = { TEXT_CATCH }; // unused in US
    UNUSED u8 textClear[] = { TEXT_CLEAR };
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
#endif

#ifdef MULTILANGUAGE
#define textCourse gTextCourseArr[gInGameLanguage]
#endif

    void **actNameTbl;
    void **courseNameTbl;
    u8 *name;

    u8 strCourseNum[4];

#ifdef MULTILANGUAGE
    s16 centerX;
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_en);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_fr);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_de);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
        case LANGUAGE_ITALIAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_it);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_it);
            break;
        case LANGUAGE_SPANISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_es);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_es);
            break;
    }
#else
    actNameTbl = segmented_to_virtual(seg2_act_name_table);
    courseNameTbl = segmented_to_virtual(seg2_course_name_table);
#endif

    if (gLastCompletedCourseNum <= COURSE_STAGES_MAX) {
        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(1, 1 << (gLastCompletedStarNum - 1));

        if (gLastCompletedStarNum == 7) {
            name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * 6 + 1]);
        } else {
            name = segmented_to_virtual(actNameTbl[(gLastCompletedCourseNum - 1) * 6 + gLastCompletedStarNum - 1]);
        }

        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
        int_to_str(gLastCompletedCourseNum, strCourseNum);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
        print_generic_string(65, 165, textCourse);
        print_generic_string(CRS_NUM_X2, 165, strCourseNum);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        print_generic_string(63, 167, textCourse);
        print_generic_string(CRS_NUM_X3, 167, strCourseNum);
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    } else if (gLastCompletedCourseNum == COURSE_BITDW || gLastCompletedCourseNum == COURSE_BITFS) {
        name = segmented_to_virtual(courseNameTbl[gLastCompletedCourseNum - 1]);
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
#ifdef MULTILANGUAGE
        centerX = get_str_x_pos_from_center(153, name, 12.0f);
#endif
        print_generic_string(TXT_NAME_X1, 130, name);
#ifndef VERSION_EU
        print_generic_string(TXT_CLEAR_X1, 130, textClear);
#endif
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
        print_generic_string(TXT_NAME_X2, 132, name);
#ifndef VERSION_EU
        print_generic_string(TXT_CLEAR_X2, 132, textClear);
#endif
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
        print_hud_course_complete_string(HUD_PRINT_CONGRATULATIONS);
        print_hud_course_complete_coins(118, 111);
        play_star_fanfare_and_flash_hud(2, 0); //! 2 isn't defined, originally for key hud?
        return;
    } else {
        name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * 6]);
        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(1, 1 << (gLastCompletedStarNum - 1));
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    print_hud_lut_string(HUD_LUT_GLOBAL, 55, 77, textSymStar);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gDialogTextAlpha);
    print_generic_string(76, 145, name);
#if defined(VERSION_JP) || defined(VERSION_SH)
    print_generic_string(220, 145, textCatch);
#endif
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    print_generic_string(74, 147, name);
#if defined(VERSION_JP) || defined(VERSION_SH)
    print_generic_string(218, 147, textCatch);
#endif
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_JP) || defined(VERSION_SH)
#define TXT_SAVEOPTIONS_X x + 10
#elif defined(VERSION_US)
#define TXT_SAVEOPTIONS_X x + 12
#elif defined(VERSION_EU)
#define TXT_SAVEOPTIONS_X xOffset
#endif
#if defined(VERSION_JP) || defined(VERSION_SH)
#define TXT_SAVECONT_Y 2
#define TXT_SAVEQUIT_Y 18
#define TXT_CONTNOSAVE_Y 38
#else
#define TXT_SAVECONT_Y 0
#define TXT_SAVEQUIT_Y 20
#define TXT_CONTNOSAVE_Y 40
#endif

#ifdef VERSION_EU
#define X_VAL9 xOffset - 12
void render_save_confirmation(s16 y, s8 *index, s16 sp6e)
#else
#define X_VAL9 x
void render_save_confirmation(s16 x, s16 y, s8 *index, s16 sp6e)
#endif
{
#ifdef MULTILANGUAGE
    u8 textSaveAndContinueArr[][24] = {
        { TEXT_SAVE_AND_CONTINUE },
        { TEXT_SAVE_AND_CONTINUE_FR },
        { TEXT_SAVE_AND_CONTINUE_DE },
        { TEXT_SAVE_AND_CONTINUE_IT },
        { TEXT_SAVE_AND_CONTINUE_ES }
    };
    u8 textSaveAndQuitArr[][22] = {
        { TEXT_SAVE_AND_QUIT },
        { TEXT_SAVE_AND_QUIT_FR },
        { TEXT_SAVE_AND_QUIT_DE },
        { TEXT_SAVE_AND_QUIT_IT },
        { TEXT_SAVE_AND_QUIT_ES }
    };
    u8 textContinueWithoutSaveArr[][27] = {
        { TEXT_CONTINUE_WITHOUT_SAVING },
        { TEXT_CONTINUE_WITHOUT_SAVING_FR },
        { TEXT_CONTINUE_WITHOUT_SAVING_DE },
        { TEXT_CONTINUE_WITHOUT_SAVING_IT },
        { TEXT_CONTINUE_WITHOUT_SAVING_ES }
    };
#define textSaveAndContinue textSaveAndContinueArr[gInGameLanguage]
#define textSaveAndQuit textSaveAndQuitArr[gInGameLanguage]
#define textContinueWithoutSave textContinueWithoutSaveArr[gInGameLanguage]
    //s16 xOffset = get_str_x_pos_from_center(160, textContinueWithoutSaveArr[gInGameLanguage], 12.0f);
#else
    u8 textSaveAndContinue[] = { TEXT_SAVE_AND_CONTINUE };
    u8 textSaveAndQuit[] = { TEXT_SAVE_AND_QUIT };
    u8 textContinueWithoutSave[] = { TEXT_CONTINUE_WITHOUT_SAVING };
#endif

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, 3);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);

    print_generic_string(TXT_SAVEOPTIONS_X, y + TXT_SAVECONT_Y, textSaveAndContinue);
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_SAVEQUIT_Y, textSaveAndQuit);
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_CONTNOSAVE_Y, textContinueWithoutSave);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL9, y - ((index[0] - 1) * sp6e), 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gDialogTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

s16 render_course_complete_screen(void) {
    s16 num;
#ifdef MULTILANGUAGE
    gInGameLanguage = eu_get_language();
#endif

    switch (gDialogBoxState) {
        case DIALOG_STATE_OPENING:
            render_course_complete_lvl_info_and_hud_str();
            if (gCourseDoneMenuTimer > 100 && gCourseCompleteCoinsEqual == 1) {
                gDialogBoxState = DIALOG_STATE_VERTICAL;
                level_set_transition(-1, 0);
                gDialogTextAlpha = 0;
                gDialogLineNum = 1;
            }
            break;
        case DIALOG_STATE_VERTICAL:
            background_scene();
            render_course_complete_lvl_info_and_hud_str();
#ifdef VERSION_EU
            render_save_confirmation(86, &gDialogLineNum, 20);
#else
            render_save_confirmation(100, 86, &gDialogLineNum, 20);
#endif

            if (gCourseDoneMenuTimer > 110
                && (gPlayer3Controller->buttonPressed & A_BUTTON
                 || gPlayer3Controller->buttonPressed & START_BUTTON
#ifdef VERSION_EU
                 || gPlayer3Controller->buttonPressed & Z_TRIG
#endif
                )) {
                level_set_transition(0, 0);
                play_sound(SOUND_MENU_STAR_SOUND, gDefaultSoundArgs);
                gDialogBoxState = DIALOG_STATE_OPENING;
                gMenuMode = -1;
                num = gDialogLineNum;
                gCourseDoneMenuTimer = 0;
                gCourseCompleteCoins = 0;
                gCourseCompleteCoinsEqual = 0;
                gHudFlash = 0;

                return num;
            }
            break;
    }

    if (gDialogTextAlpha < 250) {
        gDialogTextAlpha += 25;
    }

    gCourseDoneMenuTimer++;

    return 0;
}

// Only case 1 and 2 are used
s16 render_menus_and_dialogs() {
    s16 mode = 0;

    create_dl_ortho_matrix();

    if (gMenuMode != -1) {
        switch (gMenuMode) {
            case 0:
                mode = render_pause_courses_and_castle();
                break;
            case 1:
                mode = render_pause_courses_and_castle();
                break;
            case 2:
                mode = render_course_complete_screen();
                break;
            case 3:
                mode = render_course_complete_screen();
                break;
        }

        gDialogColorFadeTimer = (s16) gDialogColorFadeTimer + 0x1000;
    } else if (gDialogID != -1) {
        // Peach message "Dear Mario" new game dialog
        if (gDialogID == 20) {
            print_peach_letter_message(); // the peach message needs to be
                                          // repositioned seperately
            return mode;
        }

        render_dialog_entries();
        gDialogColorFadeTimer = (s16) gDialogColorFadeTimer + 0x1000;
    }
    return mode;
}
