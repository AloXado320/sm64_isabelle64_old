#ifndef _PRINT_H
#define _PRINT_H

#include "types.h"

#define TEXRECT_MIN_X 10
#define TEXRECT_MAX_X 300
#define TEXRECT_MIN_Y 5
#define TEXRECT_MAX_Y 220

#define GLYPH_SPACE           -1
#define GLYPH_U               30
#define GLYPH_EXCLAMATION_PNT 36
#define GLYPH_TWO_EXCLAMATION 37
#define GLYPH_QUESTION_MARK   38
#define GLYPH_AMPERSAND       39
#define GLYPH_PERCENT         40
#define GLYPH_MULTIPLY        50
#define GLYPH_COIN            51
#define GLYPH_MARIO_HEAD      52
#define GLYPH_STAR            53
#define GLYPH_PERIOD          54
#define GLYPH_BETA_KEY        55
#define GLYPH_COLON      56
//#define GLYPH_DOUBLE_QUOTE    57
#define GLYPH_UMLAUT          58

extern void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n);
extern void print_text(s32 x, s32 y, const char *str);
extern void print_text_centered(s32 x, s32 y, const char *str);
extern void render_custom_texrect(Gfx *dltexture, s16 filtering, s16 usesCi, u16 ttCiType, s16 x, s16 y, s16 width, s16 height);
extern void render_text_labels(void);

#endif /* _PRINT_H */
