#ifndef MENU_HEADER_H
#define MENU_HEADER_H

#include "types.h"

// geo
extern const GeoLayout geo_menu_file_select_strings_and_menu_cursor[];
extern const GeoLayout geo_menu_act_selector_strings[];

// leveldata
extern const Gfx dl_menu_idle_hand[];
extern const Gfx dl_menu_grabbing_hand[];
extern const u8 *const menu_hud_lut[];
extern const u8 *const menu_font_lut[];
extern const Gfx dl_menu_ia8_text_begin[];
extern const Gfx dl_menu_ia8_text_end[];
extern const Gfx dl_menu_rgba16_wood_course[];
extern const Gfx dl_menu_texture_course_upper[];
extern const Gfx dl_menu_texture_niveau_upper[];
extern const Gfx dl_menu_texture_kurs_upper[];
extern const Collision main_menu_seg7_collision[];

#ifdef MULTILANGUAGE
extern const u8 *const eu_course_strings_en_table[];
extern const u8 *const eu_course_strings_fr_table[];
extern const u8 *const eu_course_strings_de_table[];
extern const u8 *const eu_course_strings_it_table[];
extern const u8 *const eu_course_strings_es_table[];
#endif

// script
extern const LevelScript level_main_menu_entry_1[];
extern const LevelScript level_main_menu_entry_2[];

#endif
