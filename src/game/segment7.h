#ifndef SEGMENT7_H
#define SEGMENT7_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

// from main menu segment 7
extern u8 dl_menu_idle_hand[];
extern u8 dl_menu_grabbing_hand[];
extern u8 menu_hud_lut[];
extern u8 menu_font_lut[];
extern u8 dl_menu_ia8_text_begin[];
extern u8 dl_menu_ia8_text_end[];
extern u8 dl_menu_rgba16_wood_course[];
#ifdef VERSION_EU
extern u8 dl_menu_rgba16_wood_course_end[];
extern u8 dl_menu_texture_course_upper[];
extern u8 dl_menu_texture_niveau_upper[];
extern u8 dl_menu_texture_kurs_upper[];
#endif

#ifdef MULTILANGUAGE
extern const u8 eu_course_strings_en_table[];
extern const u8 eu_course_strings_fr_table[];
extern const u8 eu_course_strings_de_table[];
extern const u8 eu_course_strings_it_table[];
extern const u8 eu_course_strings_es_table[];
#endif

// from intro_segment7
extern Gfx *dl_intro_n64_logo;
extern u8 texture_nintendo_words_pallete[];
extern u8 texture_nintendo_words_ci4[];
extern u8 texture_64_words_pallete[];
extern u8 texture_64_words_ci4[];
extern Gfx *dl_main_aloxado_intro;

#endif // SEGMENT7_H
