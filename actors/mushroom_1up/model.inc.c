// Mushroom 1-Up & Chocolate

static const Vtx mushroom_1up_seg3_vertex_030295E8[] = {
    {{{    31,     31,      0}, 0, {   990,     0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -30,     31,      0}, 0, {     0,     0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -30,    -30,      0}, 0, {     0,   990}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    31,    -30,      0}, 0, {   990,   990}, {0xff, 0xff, 0xff, 0xff}}},
};

ALIGNED8 static const u8 mushroom_1up_seg3_texture_03029628[] = {
#include "actors/mushroom_1up/1-up_mushroom.rgba16.inc.c"
};

const Gfx mushroom_1up_texture_load[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mushroom_1up_seg3_texture_03029628),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPVertex(mushroom_1up_seg3_vertex_030295E8, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

ALIGNED8 static const u8 mushroom_1up_seg3_texture_chocolate[] = {
#include "actors/mushroom_1up/chocolate.rgba16.inc.c"
};

const Gfx mushroom_1up_tex_chocolate_load[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, mushroom_1up_seg3_texture_chocolate),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPVertex(mushroom_1up_seg3_vertex_030295E8, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

const Gfx mushroom_1up_dl_start[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

const Gfx mushroom_1up_dl_end[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};

const Gfx mushroom_1up_main_dl[] = {
    gsSPDisplayList(mushroom_1up_dl_start),
    gsSPDisplayList(mushroom_1up_texture_load),
    gsSPDisplayList(mushroom_1up_dl_end),
    gsSPEndDisplayList(),
};

const Gfx mushroom_1up_chocolate_dl[] = {
    gsSPDisplayList(mushroom_1up_dl_start),
    gsSPDisplayList(mushroom_1up_tex_chocolate_load),
    gsSPDisplayList(mushroom_1up_dl_end),
    gsSPEndDisplayList(),
};
