// SM64DS Coin
// 32 vtx model, will only work on F3DEX and F3DEX2

static const Lights1 sm64ds_coin_lights = gdSPDefLights1(
    0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x28, 0x28, 0x28
);

// 0x0302AEF0
ALIGNED8 static const u8 sm64ds_coin_cipallete[] = {
#include "actors/coin/0_pal.rgba16.inc.c"
};

ALIGNED8 static const u8 sm64ds_yellow_coin[] = {
#include "actors/coin/1_ci8yellowcoin.inc.c"
};

ALIGNED8 static const u8 sm64ds_red_coin[] = {
#include "actors/coin/2_ci8redcoin.inc.c"
};

ALIGNED8 static const u8 sm64ds_blue_coin[] = {
#include "actors/coin/3_ci8bluecoin.inc.c"
};

const Vtx sm64ds_coin_vertex[] = {
    {{{      0,     42,      6}, 0, {    508,  -1050},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{     29,     13,      6}, 0, {    904,  -1840},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{     42,     42,      6}, 0, {   1068,  -1050},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{      0,      0,      6}, 0, {    508,  -2166},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{    -29,     13,      6}, 0, {    116,  -1840},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{    -42,     42,      6}, 0, {    -48,  -1050},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{    -29,     71,      6}, 0, {    116,   -260},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{      0,     84,      6}, 0, {    508,     66},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{    -29,     71,     -6}, 0, {    116,   -260},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{      0,     84,     -6}, 0, {    508,     66},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{     29,     71,      6}, 0, {    904,   -260},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{    -42,     42,     -6}, 0, {    -48,  -1050},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{      0,     42,     -6}, 0, {    508,  -1050},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{     29,     71,     -6}, 0, {    904,   -260},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{     42,     42,     -6}, 0, {   1068,  -1050},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{     29,     13,     -6}, 0, {    904,  -1840},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{      0,      0,     -6}, 0, {    508,  -2166},  {0xFF, 0xFF, 0xFF, 0xFF}}},
    {{{    -29,     13,     -6}, 0, {    116,  -1840},  {0xFF, 0xFF, 0xFF, 0xFF}}},
};

const Gfx sm64ds_coin_dl_init[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsSPLight(&sm64ds_coin_lights.l, 1),
    gsSPLight(&sm64ds_coin_lights.a, 2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, G_ON),
    gsDPLoadTLUT_pal256(sm64ds_coin_cipallete),
    gsSPEndDisplayList(),
};

const Gfx sm64ds_coin_dl_model[] = {
    gsSPVertex(sm64ds_coin_vertex, 18, 0),
    gsSP2Triangles (0,  3,  1, 0x0,  0,  6,  5, 0x0),
    gsSP2Triangles (1,  2,  0, 0x0,  3,  0,  4, 0x0),
    gsSP2Triangles (5,  4,  0, 0x0,  6,  0,  7, 0x0),
    gsSP2Triangles (8,  6,  7, 0x0,  8,  7,  9, 0x0),
    gsSP2Triangles (9,  7, 10, 0x0,  9, 10, 13, 0x0),
    gsSP2Triangles (9, 12,  8, 0x0,  9, 13, 12, 0x0),
    gsSP2Triangles(10,  0,  2, 0x0, 10,  7,  0, 0x0),
    gsSP2Triangles(11,  5,  6, 0x0, 11,  6,  8, 0x0),
    gsSP2Triangles(11,  8, 12, 0x0, 11, 12, 17, 0x0),
    gsSP2Triangles(12, 14, 15, 0x0, 13,  2, 14, 0x0),
    gsSP2Triangles(13, 10,  2, 0x0, 14,  1, 15, 0x0),
    gsSP2Triangles(14,  2,  1, 0x0, 14, 12, 13, 0x0),
    gsSP2Triangles(15,  1,  3, 0x0, 15,  3, 16, 0x0),
    gsSP2Triangles(15, 16, 12, 0x0, 16,  3,  4, 0x0),
    gsSP2Triangles(16,  4, 17, 0x0, 16, 17, 12, 0x0),
    gsSP2Triangles(17,  4,  5, 0x0, 17,  5, 11, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, G_OFF),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

const Gfx sm64ds_yellow_coin_dl[] = {
    gsSPDisplayList(sm64ds_coin_dl_init),
    gsDPLoadTextureBlock(sm64ds_yellow_coin, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 64, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 4, 6, G_TX_NOMASK, G_TX_NOLOD),
    gsSPBranchList(sm64ds_coin_dl_model),
};

const Gfx sm64ds_red_coin_dl[] = {
    gsSPDisplayList(sm64ds_coin_dl_init),
    gsDPLoadTextureBlock(sm64ds_red_coin, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 64, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 4, 6, G_TX_NOMASK, G_TX_NOLOD),
    gsSPBranchList(sm64ds_coin_dl_model),
};

const Gfx sm64ds_blue_coin_dl[] = {
    gsSPDisplayList(sm64ds_coin_dl_init),
    gsDPLoadTextureBlock(sm64ds_blue_coin, G_IM_FMT_CI, G_IM_SIZ_8b, 16, 64, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 4, 6, G_TX_NOMASK, G_TX_NOLOD),
    gsSPBranchList(sm64ds_coin_dl_model),
};
