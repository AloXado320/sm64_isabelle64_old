#ifndef INGAME_MENU_H
#define INGAME_MENU_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#define ASCII_TO_DIALOG(asc)                                       \
    (((asc) >= '0' && (asc) <= '9') ? ((asc) - '0') :              \
     ((asc) >= 'A' && (asc) <= 'Z') ? ((asc) - 'A' + 0x0A) :       \
     ((asc) >= 'a' && (asc) <= 'z') ? ((asc) - 'a' + 0x24) : 0x00)


#define MENU_MTX_PUSH   1
#define MENU_MTX_NOPUSH 2

#define MENU_SCROLL_VERTICAL   1
#define MENU_SCROLL_HORIZONTAL 2

// Japanese File Select uses an unique table
// to print specific Japanese HUD chars
#define HUD_LUT_JPMENU 1
#define HUD_LUT_GLOBAL 2

// For file select JP HUD difference
#ifdef VERSION_JP
#define HUD_LUT_DIFF HUD_LUT_JPMENU
#else
#define HUD_LUT_DIFF HUD_LUT_GLOBAL
#endif

#define RENDER_PAUSE_SCREEN       1
#define RENDER_COURSE_DONE_SCREEN 2

enum npcNameIDList {
    NPCNAME_NONE,
    NPCNAME_SIGN,
    NPCNAME_BOMBBUDDY,
    NPCNAME_KTQ,
    NPCNAME_KINGBOMB,
    NPCNAME_BOWSER,
    NPCNAME_LAKITU,
    NPCNAME_HOOT,
    NPCNAME_PENGUIN,
    NPCNAME_TOAD,
    NPCNAME_UKIKI,
    NPCNAME_MIPS,
    NPCNAME_SNOWMAN,
    NPCNAME_WHOMP,
    NPCNAME_EYEROK,
    NPCNAME_WIGGLER,
    NPCNAME_YOSHI
};

extern s8 gDialogCourseActNum;
extern s8 gHudFlash;

struct DialogEntry
{
 /*0x00*/ u8 npcNameID;
 /*0x04*/ s8 linesPerBox;
 /*0x06*/ const u8 *str;
};

// EU only
enum HudSpecialHUDChars {
    HUD_CHAR_A_UMLAUT = 0x3A,
    HUD_CHAR_O_UMLAUT = 0x3B,
    HUD_CHAR_U_UMLAUT = 0x3C
};

enum SpecialFontChars {
    GLOBAL_CHAR_SPACE = 0x9E,
    GLOBAL_CHAR_TERMINATOR = 0xFF
};

// definitions for some of the special characters defined in charmap.txt
enum DialogSpecialChars {
#ifdef MULTILANGUAGE
    DIALOG_CHAR_LOWER_A_GRAVE = 0x60,      // 'a' grave
    DIALOG_CHAR_LOWER_A_CIRCUMFLEX = 0x61, // 'a' circumflex
    DIALOG_CHAR_LOWER_A_UMLAUT = 0x62,     // 'a' umlaut
    DIALOG_CHAR_LOWER_A_ACUTE = 0x63,     // 'a' acute
    DIALOG_CHAR_UPPER_A_GRAVE = 0x64,      // 'A' grave
    DIALOG_CHAR_UPPER_A_CIRCUMFLEX = 0x65, // 'A' circumflex
    DIALOG_CHAR_UPPER_A_UMLAUT = 0x66,     // 'A' umlaut
    DIALOG_CHAR_UPPER_A_ACUTE = 0x67,     // 'A' acute
    DIALOG_CHAR_LOWER_E_GRAVE = 0x70,      // 'e' grave
    DIALOG_CHAR_LOWER_E_CIRCUMFLEX = 0x71, // 'e' circumflex
    DIALOG_CHAR_LOWER_E_UMLAUT = 0x72,     // 'e' umlaut
    DIALOG_CHAR_LOWER_E_ACUTE = 0x73,      // 'e' acute
    DIALOG_CHAR_UPPER_E_GRAVE = 0x74,      // 'E' grave
    DIALOG_CHAR_UPPER_E_CIRCUMFLEX = 0x75, // 'E' circumflex
    DIALOG_CHAR_UPPER_E_UMLAUT = 0x76,     // 'E' umlaut
    DIALOG_CHAR_UPPER_E_ACUTE = 0x77,      // 'E' acute
    DIALOG_CHAR_LOWER_U_GRAVE = 0x80,      // 'u' grave
    DIALOG_CHAR_LOWER_U_CIRCUMFLEX = 0x81, // 'u' circumflex
    DIALOG_CHAR_LOWER_U_UMLAUT = 0x82,     // 'u' umlaut
    DIALOG_CHAR_LOWER_U_ACUTE = 0x83,     // 'u' acute
    DIALOG_CHAR_UPPER_U_GRAVE = 0x84,      // 'U' grave
    DIALOG_CHAR_UPPER_U_CIRCUMFLEX = 0x85, // 'U' circumflex
    DIALOG_CHAR_UPPER_U_UMLAUT = 0x86,     // 'U' umlaut
    DIALOG_CHAR_UPPER_U_ACUTE = 0x87,     // 'U' acute
    DIALOG_CHAR_LOWER_O_GRAVE = 0x90, // 'o' grave
    DIALOG_CHAR_LOWER_O_CIRCUMFLEX = 0x91, // 'o' circumflex
    DIALOG_CHAR_LOWER_O_UMLAUT = 0x92,     // 'o' umlaut
    DIALOG_CHAR_LOWER_O_ACUTE = 0x93,     // 'o' acute
    DIALOG_CHAR_UPPER_O_GRAVE = 0x94, // 'O' grave
    DIALOG_CHAR_UPPER_O_CIRCUMFLEX = 0x95, // 'O' circumflex
    DIALOG_CHAR_UPPER_O_UMLAUT = 0x96,     // 'O' umlaut
    DIALOG_CHAR_UPPER_O_ACUTE = 0x97,     // 'O' acute
    DIALOG_CHAR_LOWER_I_GRAVE = 0xA0, // 'i' grave
    DIALOG_CHAR_LOWER_I_CIRCUMFLEX = 0xA1, // 'i' circumflex
    DIALOG_CHAR_LOWER_I_UMLAUT = 0xA2,     // 'i' umlaut
    DIALOG_CHAR_LOWER_I_ACUTE = 0xA3,     // 'i' acute
    DIALOG_CHAR_UPPER_I_GRAVE = 0xA4, // 'I' grave
    DIALOG_CHAR_UPPER_I_CIRCUMFLEX = 0xA5, // 'I' circumflex
    DIALOG_CHAR_UPPER_I_UMLAUT = 0xA6,     // 'I' umlaut
    DIALOG_CHAR_UPPER_I_ACUTE = 0xA7,     // 'I' acute
    DIALOG_CHAR_I_NO_DIA = 0xEB,           // 'i' without diacritic
    DIALOG_CHAR_DOUBLE_LOW_QUOTE = 0xF0,   // German opening quotation mark
#endif
#if defined(VERSION_US) || defined(MULTILANGUAGE)
    DIALOG_CHAR_SLASH = 0xD0,
    DIALOG_CHAR_MULTI_THE = 0xD1, // 'the'
    DIALOG_CHAR_MULTI_YOU = 0xD2, // 'you'
#endif
    DIALOG_C_UP_BUTTON = 0x50,
    DIALOG_C_DOWN_BUTTON = 0x51,
    DIALOG_C_LEFT_BUTTON = 0x52,
    DIALOG_C_RIGHT_BUTTON = 0x53,
    DIALOG_A_BUTTON = 0x54,
    DIALOG_B_BUTTON = 0x55,
    DIALOG_Z_BUTTON = 0x57,
    DIALOG_R_BUTTON = 0x58,
    DIALOG_CHAR_PERIOD = 0x6E,
    DIALOG_CHAR_COMMA = 0x6F,
    DIALOG_CHAR_SPACE = 0x9E,
    DIALOG_CHAR_STAR_COUNT = 0xE0, // number of stars
    DIALOG_CHAR_UMLAUT = 0xE9,
    DIALOG_CHAR_DAKUTEN = 0xF0, // prefix for kana or hira with dakuten
    DIALOG_CHAR_PERIOD_OR_HANDAKUTEN = 0xF1, // prefix for kana or hira with handakuten
    DIALOG_CHAR_COIN = 0xF9,
    DIALOG_CHAR_STAR_FILLED = 0xFA,
    DIALOG_CHAR_X_SYMBOL = 0xFB,
    DIALOG_CHAR_STAR_OPEN = 0xFD,
    DIALOG_CHAR_NEWLINE = 0xFE,
    DIALOG_CHAR_TERMINATOR = 0xFF
};

// print_generic_string_shadow
#define HEX_PRINT_CHR   0x00
#define ASCII_PRINT_CHR 0x01

// get_str_x_pos_from_center_custom_hex
enum xPosCenterCustomTypesHex {
    LUT_TYPE_HUD_HEX,
    LUT_TYPE_STR_HEX
};

// get_str_x_pos_from_center_custom_ascii
enum xPosCenterCustomTypesAscii {
    LUT_TYPE_HUD_ASCII,
    LUT_TYPE_STR_ASCII
};

// render_arrow_texture_menu
#define ARROW_TEXTURE_SELECT    0x00
#define ARROW_TEXTURE_NEXT_PAGE 0x01

extern s32 gDialogResponse;
extern u16 gDialogColorFadeTimer;
extern s8 gLastDialogLineNum;
extern s32 gDialogVariable;
extern u16 gDialogTextAlpha;
extern s16 gCutsceneMsgXOffset;
extern s16 gCutsceneMsgYOffset;
extern s8 gRedCoinsCollected;

void create_dl_identity_matrix(void);
void create_dl_translation_matrix(s8 pushOp, f32 x, f32 y, f32 z);
void create_dl_rotation_matrix(s8 pushOp, f32 a, f32 x, f32 y, f32 z);
void create_dl_scale_matrix(s8 pushOp, f32 x, f32 y, f32 z);
void create_dl_ortho_matrix(void);
void render_rotating_model(Gfx *displaylist, f32 xPos, f32 yPos, f32 scale, f32 rotSpeed);
void print_generic_string(s16 x, s16 y, const u8 *str);
void print_hud_lut_string(s8 fontLut, s16 x, s16 y, const u8 *str);
void print_menu_generic_string(s16 x, s16 y, const u8 *str);
void print_generic_string_shadow(s8 isAscii, s16 x, s16 y, u8 r, u8 g, u8 b, u8 alpha, const char *strAscii, const u8 *strHex);
void handle_menu_scrolling(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex);
void handle_menu_scrolling_slots(u8 slot, s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex);

#if defined(VERSION_US) || defined(VERSION_EU)
s16 get_str_x_pos_from_center(s16 centerPos, u8 *str, f32 scale);
#endif

#ifdef VERSION_JP
#define get_str_x_pos_from_center get_str_x_pos_from_center_scale
#endif

#if defined(VERSION_JP) || defined(VERSION_EU)
s16 get_str_x_pos_from_center_scale(s16 centerPos, u8 *str, f32 scale);
#endif
 
s16 get_hud_str_width(u8 *str);
s16 get_string_width(u8 *str);

s16 get_hud_str_width_ascii(char *str);
s16 get_string_width_ascii(char *str);

s16 get_str_x_pos_from_center_custom_hex(s16 lutType, s16 centerPos, u8 *strHex, u8 scale);
s16 get_str_x_pos_from_center_custom_ascii(s16 lutType, s16 centerPos, char *strAscii, u8 scale);

void print_hud_my_score_coins(s32 useCourseCoinScore, s8 fileNum, s8 courseNum, s16 x, s16 y);
void int_to_str(s32 num, u8 *dst);
s16 get_dialog_id(void);
void create_dialog_box(s16 dialog);
void create_dialog_box_with_var(s16 dialog, s32 dialogVar);
void create_dialog_inverted_box(s16 dialog);
void create_dialog_box_with_response(s16 dialog);
void reset_dialog_render_state(void);
void render_arrow_texture_menu(s16 move, s16 arrowType, s16 x, s16 y);
void set_menu_mode(s16 mode);
void reset_cutscene_msg_fade(void);
void dl_rgba16_begin_cutscene_msg_fade(void);
void dl_rgba16_stop_cutscene_msg_fade(void);
void print_credits_str_ascii(s16 x, s16 y, const char *str);
void print_generic_str_ascii(s16 x, s16 y, const char *str);
void set_cutscene_message(s16 xOffset, s16 yOffset, s16 msgIndex, s16 msgDuration);
void do_cutscene_handler(void);
void render_title_screen_textures(void);
s32 lvl_render_cake_screen_strings(s16, s32);
void render_hud_cannon_reticle(void);
void reset_red_coins_collected(void);
s16 render_menus_and_dialogs(void);

#endif// INGAME_MENU_H
