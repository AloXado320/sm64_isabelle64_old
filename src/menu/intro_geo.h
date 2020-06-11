#ifndef INTRO_GEO_H
#define INTRO_GEO_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "types.h"

void render_initial_intro_message(void);
void render_nintendo_64_textures(void);

Gfx *geo_shz_init_intro_message(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]);
Gfx *geo_intro_n64_logo(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]);
Gfx *geo_aloxado_logo_screen(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]);
Gfx *intro_backdrop_one_image(s32 index, s8 *backdrop_table);
Gfx *geo_intro_backdrop(s32 a0, struct GraphNode *a1, UNUSED void *context);
Gfx *geo_game_over_tile(s32 a0, struct GraphNode *a1, UNUSED void *context);

#endif // INTRO_GEO_H
