#include <ultra64.h>

#include "sm64.h"
#include "game_init.h"
#include "ingame_menu.h"
#include "audio/external.h"
#include "segment2.h"
#include "memory.h"
#include "hud.h"
#include "print.h"
#include "alternate_costume.h"
#include "save_file.h"
#include "text_strings.h"

// Original code by devwizard, heavily edited by AloXado320

#define NUM_ALT_CUSTOMES 8

#define MENU_BORDER 4
#define TEXT_HEIGHT 16
#define MENU_X 24
#define MENU_Y 198
#define TITLE_X   (MENU_X + MENU_BORDER)
#define TITLE_Y   (MENU_Y - MENU_BORDER - TEXT_HEIGHT)
#define OPTIONS_X (MENU_X + MENU_BORDER + 24)
#define OPTIONS_Y (TITLE_Y - TEXT_HEIGHT - MENU_BORDER)

#define MENU_R 0xFF
#define MENU_G 0xFF
#define MENU_B 0xFF
#define MENU_A 0xFF
#define MENUBG_R 0x00
#define MENUBG_G 0x00
#define MENUBG_B 0x00
#define MENUBG_A 0xFF

extern Gfx isabelle_tex_extra_colors_loadblock_dl[];
extern Gfx isabelle_tex_tshirt_pallete_dl[];
extern Gfx isabelle_tex_ears_loadblock_dl[];
extern Gfx isabelle_tex_hair_tail_loadblock_dl[];

// Ears
extern u8 ears_pallete[];
extern u8 ears_pallete_pink[];
extern u8 ears_pallete_red[];
extern u8 ears_pallete_teal[];
extern u8 ears_pallete_gray[];

// Hair Tail
extern u8 hair_tail_pallete[];
extern u8 hair_tail_pallete_pink[];
extern u8 hair_tail_pallete_red[];
extern u8 hair_tail_pallete_teal[];
extern u8 hair_tail_pallete_gray[];

// Default (Green) Outfit
extern u8 shz_extra_colors_green[];
extern u8 shz_tshirt_pal_green[];
// Yellow Outfit
extern u8 shz_extra_colors_yellow[];
extern u8 shz_tshirt_pal_yellow[];
// Pink Outfit
extern u8 shz_extra_colors_pink[];
extern u8 shz_tshirt_pal_pink[];
// Red Outfit
extern u8 shz_extra_colors_red[];
extern u8 shz_tshirt_pal_red[];
// Purple Outfit
extern u8 shz_extra_colors_purple[];
extern u8 shz_tshirt_pal_purple[];
// Teal Outfit
extern u8 shz_extra_colors_teal[];
extern u8 shz_tshirt_pal_teal[];
// Gray Outfit
extern u8 shz_extra_colors_grey[];
extern u8 shz_tshirt_pal_grey[];
// Blue Outfit
extern u8 shz_extra_colors_blue[];
extern u8 shz_tshirt_pal_blue[];

s8 sAltCustomMenuOpt = 0;
s16 sAltCostumeSelectedID = 0;

// In Isabelle 64 1.2, only her T-Shirt and Extra colors are changed but looking again
// at the Smash Wiki, her hair color changes too depending of the outfit (saturation and lightness)
// These new changes are applied since Isabelle 64 1.3
struct AltCostumeEntry {
    u8 *texEarColor;
    u8 *texHairTailColor; 
    u8 *texExtraColor;
    u8 *texTshirtColor;
};

// TODO: Fix JP (strings)

const struct AltCostumeEntry sAltCostumeEntries[NUM_ALT_CUSTOMES] = {
    { ears_pallete,         hair_tail_pallete,      shz_extra_colors_green,   shz_tshirt_pal_green  },
    { ears_pallete,         hair_tail_pallete,      shz_extra_colors_yellow,  shz_tshirt_pal_yellow },
	{ ears_pallete_pink,    hair_tail_pallete_pink, shz_extra_colors_pink,    shz_tshirt_pal_pink   },
	{ ears_pallete_red,     hair_tail_pallete_red,  shz_extra_colors_red,     shz_tshirt_pal_red    },
	{ ears_pallete,         hair_tail_pallete,      shz_extra_colors_purple,  shz_tshirt_pal_purple },
	{ ears_pallete_teal,    hair_tail_pallete_teal, shz_extra_colors_teal,    shz_tshirt_pal_teal   },
	{ ears_pallete_gray,    hair_tail_pallete_gray, shz_extra_colors_grey,    shz_tshirt_pal_grey   },
	{ ears_pallete,         hair_tail_pallete,      shz_extra_colors_blue,    shz_tshirt_pal_blue   },
};

void set_alternate_costume(const struct AltCostumeEntry *entry) {
    // Ears
    gDPSetTextureImage(segmented_to_virtual(isabelle_tex_ears_loadblock_dl), G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, entry->texEarColor);
    // Hair Tail
    gDPSetTextureImage(segmented_to_virtual(isabelle_tex_hair_tail_loadblock_dl), G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, entry->texHairTailColor);
    // Extra Colors (Skirt and Hair Tail Base)
    gDPSetTextureImage(segmented_to_virtual(isabelle_tex_extra_colors_loadblock_dl), G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, entry->texExtraColor);
    // T-Shirt
    gDPSetTextureImage(segmented_to_virtual(isabelle_tex_tshirt_pallete_dl), G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, entry->texTshirtColor);
}

void handle_alternate_costume_menu(void) {

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, &sAltCustomMenuOpt, 0, NUM_ALT_CUSTOMES - 1);
    
    render_custom_texrect(dl_balloon_arrow_side_choose_texblock, FALSE, G_TT_NONE, TITLE_X - 8, (sAltCustomMenuOpt * TEXT_HEIGHT) + 64, 16, 16);

    if (gPlayer1Controller->buttonPressed & (A_BUTTON | B_BUTTON)) {
        play_sound(SOUND_MENU_CLICK_ACNH, gDefaultSoundArgs);
        set_alternate_costume(&sAltCostumeEntries[sAltCustomMenuOpt]);
        sAltCostumeSelectedID = sAltCustomMenuOpt;
        save_file_set_alt_costume(sAltCostumeSelectedID);      
    }
}

u8 sAltCostumeTitleText[][21] = {
    { TEXT_ALT_COSTUME_TITLE },
    { TEXT_ALT_COSTUME_TITLE_FR },
    { TEXT_ALT_COSTUME_TITLE_DE },
    { TEXT_ALT_COSTUME_TITLE_IT },
    { TEXT_ALT_COSTUME_TITLE_ES }
};

u8 sAltCostumeColorListText[][10] = {
    // English Group
    {TEXT_ALT_COSTUME_GREEN}, {TEXT_ALT_COSTUME_YELLOW}, {TEXT_ALT_COSTUME_PINK}, {TEXT_ALT_COSTUME_RED}, 
    {TEXT_ALT_COSTUME_PURPLE}, {TEXT_ALT_COSTUME_TEAL}, {TEXT_ALT_COSTUME_GRAY}, {TEXT_ALT_COSTUME_BLUE},
    // French Group
    {TEXT_ALT_COSTUME_GREEN_FR}, {TEXT_ALT_COSTUME_YELLOW_FR}, {TEXT_ALT_COSTUME_PINK_FR}, {TEXT_ALT_COSTUME_RED_FR}, 
    {TEXT_ALT_COSTUME_PURPLE_FR}, {TEXT_ALT_COSTUME_TEAL_FR}, {TEXT_ALT_COSTUME_GRAY_FR}, {TEXT_ALT_COSTUME_BLUE_FR},
    // German Group
    {TEXT_ALT_COSTUME_GREEN_DE}, {TEXT_ALT_COSTUME_YELLOW_DE}, {TEXT_ALT_COSTUME_PINK_DE}, {TEXT_ALT_COSTUME_RED_DE}, 
    {TEXT_ALT_COSTUME_PURPLE_DE}, {TEXT_ALT_COSTUME_TEAL_DE}, {TEXT_ALT_COSTUME_GRAY_DE}, {TEXT_ALT_COSTUME_BLUE_DE},
    // Italian Group
    {TEXT_ALT_COSTUME_GREEN_IT}, {TEXT_ALT_COSTUME_YELLOW_IT}, {TEXT_ALT_COSTUME_PINK_IT}, {TEXT_ALT_COSTUME_RED_IT}, 
    {TEXT_ALT_COSTUME_PURPLE_IT}, {TEXT_ALT_COSTUME_TEAL_IT}, {TEXT_ALT_COSTUME_GRAY_IT}, {TEXT_ALT_COSTUME_BLUE_IT},
    // Spanish Group
    {TEXT_ALT_COSTUME_GREEN_ES}, {TEXT_ALT_COSTUME_YELLOW_ES}, {TEXT_ALT_COSTUME_PINK_ES}, {TEXT_ALT_COSTUME_RED_ES}, 
    {TEXT_ALT_COSTUME_PURPLE_ES}, {TEXT_ALT_COSTUME_TEAL_ES}, {TEXT_ALT_COSTUME_GRAY_ES}, {TEXT_ALT_COSTUME_BLUE_ES},
};

void print_alternate_costume_strings(void) {
    s16 i;
    u8 r, g, b;
    s16 y = OPTIONS_Y;
    s16 lang = eu_get_language();
    
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    
    print_generic_string_shadow(HEX_PRINT_CHR, TITLE_X, TITLE_Y, 230, 230, 230, 255, NULL, sAltCostumeTitleText[lang]);
    
    for (i = 0; i < NUM_ALT_CUSTOMES; i++) {
        
        if (i == sAltCostumeSelectedID) {
            r = 52; g = 166; b = 52;
        } else {
            r = 230; g = 230; b = 230;  
        }
        
        print_generic_string_shadow(HEX_PRINT_CHR, OPTIONS_X, y, r, g, b, 255, NULL, sAltCostumeColorListText[lang * 8 + i]);
        y -= TEXT_HEIGHT;
    }
    
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

extern u8 *shz_outfit_icon_lut[];

void print_alternate_costume_icons(void) {
    u8* (*shzIconLut)[];
    s16 i;
    
    shzIconLut = segmented_to_virtual(&shz_outfit_icon_lut);
    
    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    
    for (i = 0; i < NUM_ALT_CUSTOMES; i++) {
        render_hud_tex_lut(MENU_X + TEXT_HEIGHT - 6, (i * TEXT_HEIGHT) + 64, (*shzIconLut)[i]);
    }
    
    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

void init_saved_alternate_costume(u16 costume) {
   
    sAltCostumeSelectedID = costume;

    set_alternate_costume(&sAltCostumeEntries[costume]);
}

// main function
s32 render_alternate_costume_menu(void) {
    handle_alternate_costume_menu();
    print_alternate_costume_strings();
    print_alternate_costume_icons();
}
