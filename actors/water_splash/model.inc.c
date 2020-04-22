// Water Splash

// 0x0402A588
static const Vtx water_splash_seg4_vertex_0402A588[] = {
    {{{   -64,      0,      0}, 0, {     0,   2016}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    64,      0,      0}, 0, {   992,   2016}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    64,    256,      0}, 0, {   992,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   -64,    256,      0}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}},
};

ALIGNED8 static const u8 water_splash_textures_pallete[] = {
#include "actors/water_splash/water_splash_pallete.rgba16.inc.c"
};

ALIGNED8 static const u8 water_splash_textures_ci4[] = {
#include "actors/water_splash/water_splash_textures_ci4.inc.c"
};

// 0x040325C8 - 0x04032640
const Gfx water_splash_seg4_dl_040325C8[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadNonTextureBlock_4b(G_IM_FMT_CI, 32, 64, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadTLUT_pal16(0, water_splash_textures_pallete),
    gsSPVertex(water_splash_seg4_vertex_0402A588, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};

// 0x400 is how long is a ci4 32x64 texture

// 0x04032640 - 0x04032658
const Gfx water_splash_seg4_dl_04032640[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 0]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};

// 0x04032658 - 0x04032670
const Gfx water_splash_seg4_dl_04032658[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 1]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};

// 0x04032670 - 0x04032688
const Gfx water_splash_seg4_dl_04032670[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 2]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};

// 0x04032688 - 0x040326A0
const Gfx water_splash_seg4_dl_04032688[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 3]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};

// 0x040326A0 - 0x040326B8
const Gfx water_splash_seg4_dl_040326A0[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 4]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};

// 0x040326B8 - 0x040326D0
const Gfx water_splash_seg4_dl_040326B8[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 5]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};

// 0x040326D0 - 0x040326E8
const Gfx water_splash_seg4_dl_040326D0[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 6]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};

// 0x040326E8 - 0x04032700
const Gfx water_splash_seg4_dl_040326E8[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &water_splash_textures_ci4[0x400 * 7]),
    gsSPBranchList(water_splash_seg4_dl_040325C8),
};
