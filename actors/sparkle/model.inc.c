// Sparkles

// 0x04027450
static const Vtx sparkles_seg4_vertex_04027450[] = {
    {{{   -32,      0,      0}, 0, {     0,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,      0,      0}, 0, {  1984,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,     64,      0}, 0, {  1984,      0}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{   -32,     64,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0x00}}},
};

ALIGNED8 static const u8 sparkles_textures_pallete[] = {
#include "actors/sparkle/sparkle_pallete.rgba16.inc.c"
};

ALIGNED8 static const u8 sparkles_textures_ci4[] = {
#include "actors/sparkle/sparkle_textures_ci4.inc.c"
};

// 0x0402A490 - 0x0402A4F8
const Gfx sparkles_seg4_dl_0402A490[] = {
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadNonTextureBlock_4b(G_IM_FMT_CI, 32, 32, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadTLUT_pal16(0, sparkles_textures_pallete),
    gsSPVertex(sparkles_seg4_vertex_04027450, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};

// 0x0402A4F8 - 0x0402A510
const Gfx sparkles_seg4_dl_0402A4F8[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &sparkles_textures_ci4[CI4_TEXTURE_SIZE(32, 32) * 0]),
    gsSPBranchList(sparkles_seg4_dl_0402A490),
};

// 0x0402A510 - 0x0402A528
const Gfx sparkles_seg4_dl_0402A510[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &sparkles_textures_ci4[CI4_TEXTURE_SIZE(32, 32) * 1]),
    gsSPBranchList(sparkles_seg4_dl_0402A490),
};

// 0x0402A528 - 0x0402A540
const Gfx sparkles_seg4_dl_0402A528[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &sparkles_textures_ci4[CI4_TEXTURE_SIZE(32, 32) * 2]),
    gsSPBranchList(sparkles_seg4_dl_0402A490),
};

// 0x0402A540 - 0x0402A558
const Gfx sparkles_seg4_dl_0402A540[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &sparkles_textures_ci4[CI4_TEXTURE_SIZE(32, 32) * 3]),
    gsSPBranchList(sparkles_seg4_dl_0402A490),
};

// 0x0402A558 - 0x0402A570
const Gfx sparkles_seg4_dl_0402A558[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &sparkles_textures_ci4[CI4_TEXTURE_SIZE(32, 32) * 4]),
    gsSPBranchList(sparkles_seg4_dl_0402A490),
};

// 0x0402A570 - 0x0402A588
const Gfx sparkles_seg4_dl_0402A570[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &sparkles_textures_ci4[CI4_TEXTURE_SIZE(32, 32) * 5]),
    gsSPBranchList(sparkles_seg4_dl_0402A490),
};
