const Lights1 mat_isaTail_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 mat_IsaClothingBack_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 mat_IsaClothingFront_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_shz_extra_colors_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_mouth_closed_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_eye_open_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_ears_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_hair_tail_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_hair_tail_bells_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_mouth_happy_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_mouth_dying_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_eye_halfclosed_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_eye_closed_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

const Lights1 isabelle_tex_face_eye_surprised_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);
    
const Lights1 isabelle_tex_wings_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xA4);

// Tail
ALIGNED8 const u8 tail_pallete[] = {
	#include "actors/isabelle/tail_pallete.rgba16.inc.c"
};

ALIGNED8 const u8 tail_ci4[] = {
	#include "actors/isabelle/tail_ci4.bin.inc.c"
};

// Outfit Palletes
ALIGNED8 const u8 shz_tshirt_pal_green[] = {
	#include "actors/isabelle/outfit_pal_green.rgba16.inc.c"
};

ALIGNED8 const u8 shz_tshirt_pal_yellow[] = {
	#include "actors/isabelle/outfit_pal_yellow.rgba16.inc.c"
};

ALIGNED8 const u8 shz_tshirt_pal_pink[] = {
	#include "actors/isabelle/outfit_pal_pink.rgba16.inc.c"
};

ALIGNED8 const u8 shz_tshirt_pal_red[] = {
	#include "actors/isabelle/outfit_pal_red.rgba16.inc.c"
};

ALIGNED8 const u8 shz_tshirt_pal_purple[] = {
	#include "actors/isabelle/outfit_pal_purple.rgba16.inc.c"
};

ALIGNED8 const u8 shz_tshirt_pal_teal[] = {
	#include "actors/isabelle/outfit_pal_teal.rgba16.inc.c"
};

ALIGNED8 const u8 shz_tshirt_pal_grey[] = {
	#include "actors/isabelle/outfit_pal_grey.rgba16.inc.c"
};

ALIGNED8 const u8 shz_tshirt_pal_blue[] = {
	#include "actors/isabelle/outfit_pal_blue.rgba16.inc.c"
};

// Outfit Texture
ALIGNED8 const u8 outfit_back_ci4[] = {
	#include "actors/isabelle/outfit_back_ci4.bin.inc.c"
};

ALIGNED8 const u8 outfit_front_ci4[] = {
	#include "actors/isabelle/outfit_front_ci4.bin.inc.c"
};

// Extras (Hair tail base, Skirt)
ALIGNED8 const u8 shz_extra_colors_green[] = {
	#include "actors/isabelle/extras_green.rgba16.inc.c"
};

ALIGNED8 const u8 shz_extra_colors_yellow[] = {
	#include "actors/isabelle/extras_yellow.rgba16.inc.c"
};

ALIGNED8 const u8 shz_extra_colors_pink[] = {
	#include "actors/isabelle/extras_pink.rgba16.inc.c"
};

ALIGNED8 const u8 shz_extra_colors_red[] = {
	#include "actors/isabelle/extras_red.rgba16.inc.c"
};

ALIGNED8 const u8 shz_extra_colors_purple[] = {
	#include "actors/isabelle/extras_purple.rgba16.inc.c"
};

ALIGNED8 const u8 shz_extra_colors_teal[] = {
	#include "actors/isabelle/extras_teal.rgba16.inc.c"
};

ALIGNED8 const u8 shz_extra_colors_grey[] = {
	#include "actors/isabelle/extras_gray.rgba16.inc.c"
};

ALIGNED8 const u8 shz_extra_colors_blue[] = {
	#include "actors/isabelle/extras_blue.rgba16.inc.c"
};

// Ear Palletes
ALIGNED8 const u8 ears_pallete[] = {
	#include "actors/isabelle/ears_pallete.rgba16.inc.c"
};

ALIGNED8 const u8 ears_pallete_pink[] = {
	#include "actors/isabelle/ears_pallete_pink.rgba16.inc.c"
};

ALIGNED8 const u8 ears_pallete_red[] = {
	#include "actors/isabelle/ears_pallete_red.rgba16.inc.c"
};

ALIGNED8 const u8 ears_pallete_teal[] = {
	#include "actors/isabelle/ears_pallete_teal.rgba16.inc.c"
};

ALIGNED8 const u8 ears_pallete_gray[] = {
	#include "actors/isabelle/ears_pallete_gray.rgba16.inc.c"
};

// Ear Texture
ALIGNED8 const u8 ears_ci4[] = {
	#include "actors/isabelle/ears_ci4.bin.inc.c"
};

// Hair Tail Palletes
ALIGNED8 const u8 hair_tail_pallete[] = {
	#include "actors/isabelle/hair_tail_pallete.rgba16.inc.c"
};

ALIGNED8 const u8 hair_tail_pallete_pink[] = {
	#include "actors/isabelle/hair_tail_pallete_pink.rgba16.inc.c"
};

ALIGNED8 const u8 hair_tail_pallete_red[] = {
	#include "actors/isabelle/hair_tail_pallete_red.rgba16.inc.c"
};

ALIGNED8 const u8 hair_tail_pallete_teal[] = {
	#include "actors/isabelle/hair_tail_pallete_teal.rgba16.inc.c"
};

ALIGNED8 const u8 hair_tail_pallete_gray[] = {
	#include "actors/isabelle/hair_tail_pallete_gray.rgba16.inc.c"
};

// Hair Tail Texture
ALIGNED8 const u8 hair_tail_ci4[] = {
	#include "actors/isabelle/hair_tail_ci4.bin.inc.c"
};

// Hair Tail Bells
ALIGNED8 const u8 bells_pallete[] = {
	#include "actors/isabelle/bells_pallete.rgba16.inc.c"
};

ALIGNED8 const u8 bells_ci4[] = {
	#include "actors/isabelle/bells_ci4.bin.inc.c"
};

// Face Eyes
ALIGNED8 const u8 eye_pallete[] = {
	#include "actors/isabelle/eye_pallete.rgba16.inc.c"
};

ALIGNED8 const u8 eye_open_ci4[] = {
	#include "actors/isabelle/eye_1_open_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_halfclosed_ci4[] = {
	#include "actors/isabelle/eye_2_halfclosed_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_closed_ci4[] = {
	#include "actors/isabelle/eye_3_closed_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_angry_ci4[] = {
	#include "actors/isabelle/eye_4_angry_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_sad_ci4[] = {
	#include "actors/isabelle/eye_5_sad_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_happy_ci4[] = {
	#include "actors/isabelle/eye_6_happy_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_surprised_ci4[] = {
	#include "actors/isabelle/eye_7_surprised_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_worried_ci4[] = {
	#include "actors/isabelle/eye_8_worried_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_verysurprised_ci4[] = {
	#include "actors/isabelle/eye_9_verysurprised_ci4.bin.inc.c"
};

ALIGNED8 const u8 eye_dizzy_ci4[] = {
	#include "actors/isabelle/eye_10_dizzy_ci4.bin.inc.c"
};

// Face Mouth
ALIGNED8 const u8 mouth_pallete[] = {
	#include "actors/isabelle/mouth_pallete.rgba16.inc.c"
};

ALIGNED8 const u8 mouth_closed_ci4[] = {
	#include "actors/isabelle/mouth_1_closed_ci4.bin.inc.c"
};

ALIGNED8 const u8 mouth_smile_ci4[] = {
	#include "actors/isabelle/mouth_2_smile_ci4.bin.inc.c"
};

ALIGNED8 const u8 mouth_bigsmile_ci4[] = {
	#include "actors/isabelle/mouth_3_bigsmile_ci4.bin.inc.c"
};

ALIGNED8 const u8 mouth_sad_ci4[] = {
	#include "actors/isabelle/mouth_4_sad_ci4.bin.inc.c"
};

ALIGNED8 const u8 mouth_open_ci4[] = {
	#include "actors/isabelle/mouth_5_open_ci4.bin.inc.c"
};

ALIGNED8 const u8 mouth_veryopen_ci4[] = {
	#include "actors/isabelle/mouth_6_veryopen_ci4.bin.inc.c"
};

// Power ups
ALIGNED8 const u8 isabelle_texture_metal_pal[] = {
#include "actors/isabelle/7_pallete.rgba16.inc.c"
};

ALIGNED8 const u8 isabelle_texture_goldmetal_pal[] = {
#include "actors/isabelle/7_goldpallete.rgba16.inc.c"
};

ALIGNED8 const u8 isabelle_texture_metal[] = {
#include "actors/isabelle/7_ci4.inc.c"
};

ALIGNED8 const u8 isabelle_texture_wings_half_1[] = {
#include "actors/isabelle/8.rgba16.inc.c"
};

ALIGNED8 const u8 isabelle_texture_wings_half_2[] = {
#include "actors/isabelle/9.rgba16.inc.c"
};

ALIGNED8 const u8 isabelle_texture_metal_wings_half_1[] = {
#include "actors/isabelle/10.rgba16.inc.c"
};

ALIGNED8 const u8 isabelle_texture_metal_wings_half_2[] = {
#include "actors/isabelle/11.rgba16.inc.c"
};

ALIGNED8 const u8 shz_outfit_icon_texture_lut[] = {
#include "actors/isabelle/shz_head_texture_lut.rgba16.inc.c"
};

Gfx isabelle_metal_pallete_block_dl[] = {
    gsDPLoadTLUT_pal16(0, isabelle_texture_metal_pal),
    gsSPEndDisplayList(),
};

const Gfx isabelle_metal_shared_dl[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsSPDisplayList(isabelle_metal_pallete_block_dl),
    gsDPLoadTextureBlock_4b(isabelle_texture_metal, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(3968, 3968, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

// Tail - CI Texture
const Gfx isabelle_tex_tail[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, tail_pallete),
    gsDPLoadTextureBlock_4b(tail_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(mat_isaTail_lights),
	gsSPEndDisplayList(),
};

Gfx isabelle_tex_tshirt_pallete_dl[] = {
    gsDPLoadTLUT_pal16(0, shz_tshirt_pal_green),
    gsSPEndDisplayList(),
};

// Outfit back - CI Texture
const Gfx isabelle_tex_outfit_back[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsSPDisplayList(isabelle_tex_tshirt_pallete_dl),
    gsDPLoadTextureBlock_4b(outfit_back_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(mat_IsaClothingBack_lights),
	gsSPEndDisplayList(),
};

// Outfit front - CI Texture
const Gfx isabelle_tex_outfit_front[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsSPDisplayList(isabelle_tex_tshirt_pallete_dl),
    gsDPLoadTextureBlock_4b(outfit_front_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(mat_IsaClothingFront_lights),
	gsSPEndDisplayList(),
};

Gfx isabelle_tex_extra_colors_loadblock_dl[] = {
    gsDPLoadTextureBlock(shz_extra_colors_green, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 4, 0, G_TX_CLAMP, G_TX_CLAMP, 3, 2, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

// Extras - RGBA16 8x4 Texture
const Gfx isabelle_tex_extras[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsSPDisplayList(isabelle_tex_extra_colors_loadblock_dl),
	gsSPSetLights1(isabelle_tex_shz_extra_colors_lights),
	gsSPEndDisplayList(),
};

Gfx isabelle_tex_ears_loadblock_dl[] = {
    gsDPLoadTLUT_pal16(0, ears_pallete),
    gsSPEndDisplayList(),
};

// Ears - CI texture
const Gfx isabelle_tex_face_ears[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsSPDisplayList(isabelle_tex_ears_loadblock_dl),
    gsDPLoadTextureBlock_4b(ears_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_ears_lights),
	gsSPEndDisplayList(),
};

Gfx isabelle_tex_hair_tail_loadblock_dl[] = {
    gsDPLoadTLUT_pal16(0, hair_tail_pallete),
    gsSPEndDisplayList(),
};

// Hair tail - CI texture
const Gfx isabelle_tex_hair_tail[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsSPDisplayList(isabelle_tex_hair_tail_loadblock_dl),
    gsDPLoadTextureBlock_4b(hair_tail_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_hair_tail_lights),
	gsSPEndDisplayList(),
};

// Hair tail bells - CI texture
const Gfx isabelle_tex_hair_tail_bells[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, bells_pallete),
    gsDPLoadTextureBlock_4b(bells_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_hair_tail_bells_lights),
	gsSPEndDisplayList(),
};

// Mouth - CI textures
const Gfx isabelle_tex_face_mouth_closed[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, mouth_pallete),
    gsDPLoadTextureBlock_4b(mouth_closed_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_mouth_closed_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_mouth_smile[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, mouth_pallete),
    gsDPLoadTextureBlock_4b(mouth_smile_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_mouth_happy_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_mouth_bigsmile[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, mouth_pallete),
    gsDPLoadTextureBlock_4b(mouth_bigsmile_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_mouth_happy_lights),
	gsSPEndDisplayList(),
};


const Gfx isabelle_tex_face_mouth_sad[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, mouth_pallete),
    gsDPLoadTextureBlock_4b(mouth_sad_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_mouth_dying_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_mouth_open[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, mouth_pallete),
    gsDPLoadTextureBlock_4b(mouth_open_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_mouth_dying_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_mouth_veryopen[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, mouth_pallete),
    gsDPLoadTextureBlock_4b(mouth_veryopen_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_mouth_dying_lights),
	gsSPEndDisplayList(),
};

// Eyes - CI textures
const Gfx isabelle_tex_face_eye_open[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_open_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_open_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_halfclosed[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_halfclosed_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_halfclosed_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_closed[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_closed_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_closed_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_angry[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_angry_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_closed_lights), // same as before
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_sad[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_sad_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_closed_lights), // same as before
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_happy[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_happy_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_closed_lights), // same as before
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_surprised[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_surprised_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_surprised_lights),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_worried[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_worried_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_closed_lights), // same as before
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_verysurprised[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_verysurprised_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_closed_lights), // same as before
	gsSPEndDisplayList(),
};

const Gfx isabelle_tex_face_eye_dizzy[] = {
	gsDPPipeSync(),
	gsDPSetCombineMode(G_CC_MODULATERGBFADEA, G_CC_MODULATERGBFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
	gsDPTileSync(),
    gsDPLoadTLUT_pal16(0, eye_pallete),
    gsDPLoadTextureBlock_4b(eye_dizzy_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
	gsSPSetLights1(isabelle_tex_face_eye_closed_lights), // same as before
	gsSPEndDisplayList(),
};

const Vtx _000_offset_mesh_vtx[] = {
{{{    -4,    -70,    -23}, 0, {   -32,    992},  {0xF0, 0xA9, 0x5B, 0xFF}}},
{{{   -24,    -66,      0}, 0, {    96,   1632},  {0x3F, 0x92, 0x00, 0xFF}}},
{{{    -3,    -53,      0}, 0, {    32,   1312},  {0xFC, 0x81, 0x00, 0xFF}}},
{{{    14,    -65,      0}, 0, {   -32,    992},  {0xA2, 0xAB, 0x00, 0xFF}}},
{{{    -4,    -70,    -23}, 0, {    96,   1632},  {0xF0, 0xA9, 0x5B, 0xFF}}},
{{{   -24,    -66,      0}, 0, {   -32,    992},  {0x3F, 0x92, 0x00, 0xFF}}},
{{{    -4,    -70,     23}, 0, {    96,   1632},  {0xF0, 0xA9, 0xA5, 0xFF}}},
{{{    -4,    -70,     23}, 0, {   -32,    992},  {0xF0, 0xA9, 0xA5, 0xFF}}},
{{{    14,    -65,      0}, 0, {    96,   1632},  {0xA2, 0xAB, 0x00, 0xFF}}},
{{{   -48,    -88,     20}, 0, {   352,   1952},  {0x64, 0xD0, 0xC2, 0xFF}}},
{{{    -4,    -70,     23}, 0, {    32,   1312},  {0xF0, 0xA9, 0xA5, 0xFF}}},
{{{   -12,    -98,     41}, 0, {   544,   1440},  {0x06, 0xDF, 0x85, 0xFF}}},
{{{   -24,   -163,     32}, 0, {  1760,   1632},  {0x3A, 0x4F, 0xB0, 0xFF}}},
{{{   -48,   -133,      0}, 0, {  1120,   1952},  {0x79, 0x27, 0x00, 0xFF}}},
{{{   -48,    -88,    -20}, 0, {   352,   1952},  {0x64, 0xD0, 0x3E, 0xFF}}},
{{{    -4,    -70,    -23}, 0, {    32,   1312},  {0xF0, 0xA9, 0x5B, 0xFF}}},
{{{   -12,    -98,    -41}, 0, {   544,   1440},  {0x06, 0xDF, 0x7B, 0xFF}}},
{{{    30,   -111,    -22}, 0, {   800,    800},  {0xB6, 0xC1, 0x51, 0xFF}}},
{{{    30,   -111,     22}, 0, {   800,    800},  {0xB6, 0xC1, 0xAF, 0xFF}}},
{{{    25,   -150,     36}, 0, {  1504,    864},  {0xCC, 0x2D, 0x95, 0xFF}}},
{{{    17,   -180,      0}, 0, {  2016,    992},  {0xDE, 0x7A, 0x00, 0xFF}}},
{{{   -24,   -163,    -32}, 0, {  1760,   1632},  {0x3A, 0x4F, 0x50, 0xFF}}},
{{{    25,   -150,    -36}, 0, {  1504,    864},  {0xCC, 0x2D, 0x6B, 0xFF}}},
{{{    78,   -118,      0}, 0, {   928,     32},  {0x86, 0xDC, 0x00, 0xFF}}},
};

const Gfx isabelle_tail_tris[] = {
	gsSPVertex(_000_offset_mesh_vtx + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
	gsSP2Triangles(5, 6, 2, 0, 7, 8, 2, 0),
	gsSP2Triangles(9, 10, 1, 0, 9, 11, 10, 0),
	gsSP2Triangles(12, 11, 9, 0, 12, 9, 13, 0),
	gsSP2Triangles(9, 14, 13, 0, 9, 1, 14, 0),
	gsSP2Triangles(1, 15, 14, 0, 16, 14, 15, 0),
	gsSP2Triangles(16, 15, 17, 0, 3, 17, 15, 0),
	gsSP2Triangles(18, 17, 3, 0, 18, 3, 10, 0),
	gsSP2Triangles(11, 18, 10, 0, 19, 18, 11, 0),
	gsSP2Triangles(12, 19, 11, 0, 12, 20, 19, 0),
	gsSP2Triangles(12, 21, 20, 0, 12, 13, 21, 0),
	gsSP2Triangles(13, 14, 21, 0, 21, 14, 16, 0),
	gsSP2Triangles(21, 16, 22, 0, 16, 17, 22, 0),
	gsSP2Triangles(23, 22, 17, 0, 18, 23, 17, 0),
	gsSP2Triangles(19, 23, 18, 0, 19, 20, 23, 0),
	gsSP2Triangles(20, 22, 23, 0, 20, 21, 22, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_tail[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_tail_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_tail[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_tail),
	gsSPDisplayList(isabelle_tail_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_001_mesh_vtx[] = {
{{{   162,      0,    -34}, 0, {  1462,    -80},  {0x83, 0x03, 0x18, 0xFF}}},
{{{   162,      0,     34}, 0, {   510,    -80},  {0x83, 0x03, 0xE8, 0xFF}}},
{{{   162,    -29,      0}, 0, {   986,    -34},  {0x8B, 0x32, 0x00, 0xFF}}},
{{{    98,    -23,    -73}, 0, {   988,    -60},  {0xF3, 0x2E, 0x76, 0xFF}}},
{{{   151,    -16,    -57}, 0, {   988,    -60},  {0xAB, 0x27, 0x56, 0xFF}}},
{{{   130,    -37,    -58}, 0, {   988,    -60},  {0xD9, 0x55, 0x57, 0xFF}}},
{{{    92,      2,    -75}, 0, {   988,    -60},  {0xF1, 0x00, 0x7E, 0xFF}}},
{{{   155,      2,    -57}, 0, {   988,    -60},  {0xA3, 0x02, 0x57, 0xFF}}},
{{{    -1,    -34,    -74}, 0, {  1688,   1944},  {0xEA, 0x49, 0x65, 0xFF}}},
{{{    -2,      2,    -85}, 0, {  2016,   1944},  {0xF7, 0x02, 0x7F, 0xFF}}},
{{{    30,      1,    -79}, 0, {  2016,   1518},  {0xEE, 0x0C, 0x7D, 0xFF}}},
{{{    27,    -23,    -71}, 0, {  1754,   1564},  {0xEB, 0x47, 0x67, 0xFF}}},
{{{    68,    -31,    -66}, 0, {  1684,   1040},  {0x07, 0x52, 0x60, 0xFF}}},
{{{    63,      1,    -75}, 0, {  2016,   1108},  {0xFA, 0x09, 0x7F, 0xFF}}},
{{{    98,    -23,    -73}, 0, {  1792,    678},  {0xF3, 0x2E, 0x76, 0xFF}}},
{{{    92,      2,    -75}, 0, {  2016,    762},  {0xF1, 0x00, 0x7E, 0xFF}}},
{{{   130,    -37,    -58}, 0, {  1598,    322},  {0xD9, 0x55, 0x57, 0xFF}}},
{{{    74,    -49,    -37}, 0, {  1340,    972},  {0x06, 0x78, 0x28, 0xFF}}},
{{{   141,    -50,    -27}, 0, {  1226,    218},  {0xC6, 0x6D, 0x1E, 0xFF}}},
{{{   151,    -16,    -57}, 0, {  1736,     58},  {0xAB, 0x27, 0x56, 0xFF}}},
{{{   162,    -29,      0}, 0, {   988,    -60},  {0x8B, 0x32, 0x00, 0xFF}}},
{{{   162,      0,    -34}, 0, {  1466,    -60},  {0x83, 0x03, 0x18, 0xFF}}},
{{{   155,      2,    -57}, 0, {  1760,    -60},  {0xA3, 0x02, 0x57, 0xFF}}},
{{{   141,    -50,     27}, 0, {   750,    218},  {0xC6, 0x6D, 0xE2, 0xFF}}},
{{{   151,    -16,     57}, 0, {   240,     58},  {0xAB, 0x27, 0xAA, 0xFF}}},
{{{   162,      0,     34}, 0, {   510,    -60},  {0x83, 0x03, 0xE8, 0xFF}}},
{{{   155,      2,     57}, 0, {   216,    -60},  {0xA3, 0x02, 0xA9, 0xFF}}},
{{{   130,    -37,     58}, 0, {   378,    322},  {0xD9, 0x55, 0xA9, 0xFF}}},
{{{    74,    -49,     37}, 0, {   636,    972},  {0x06, 0x78, 0xD8, 0xFF}}},
{{{    68,    -31,     66}, 0, {   290,   1040},  {0x07, 0x52, 0xA0, 0xFF}}},
{{{    98,    -23,     73}, 0, {   184,    678},  {0xF3, 0x2E, 0x8A, 0xFF}}},
{{{    63,      1,     75}, 0, {   -32,   1108},  {0xFA, 0x09, 0x81, 0xFF}}},
{{{    98,    -23,     73}, 0, {   184,    678},  {0xF3, 0x2E, 0x8A, 0xFF}}},
{{{    92,      2,     75}, 0, {   -32,    762},  {0xF1, 0x00, 0x82, 0xFF}}},
{{{    63,      1,     75}, 0, {   -32,   1108},  {0xFA, 0x09, 0x81, 0xFF}}},
{{{    30,      1,     79}, 0, {   -32,   1518},  {0xEE, 0x0C, 0x83, 0xFF}}},
{{{    68,    -31,     66}, 0, {   290,   1040},  {0x07, 0x52, 0xA0, 0xFF}}},
{{{    27,    -23,     71}, 0, {   222,   1564},  {0xEB, 0x47, 0x99, 0xFF}}},
{{{    -1,    -34,     74}, 0, {   286,   1944},  {0xEA, 0x49, 0x9B, 0xFF}}},
{{{    -2,      2,     85}, 0, {   -32,   1944},  {0xF7, 0x02, 0x81, 0xFF}}},
{{{    -2,    -58,     43}, 0, {   612,   1944},  {0xDB, 0x70, 0xD1, 0xFF}}},
{{{    26,    -42,     43}, 0, {   560,   1570},  {0xE6, 0x74, 0xD2, 0xFF}}},
{{{    24,    -47,      0}, 0, {   988,   1550},  {0xE2, 0x7B, 0x00, 0xFF}}},
{{{    -3,    -65,      0}, 0, {   988,   1944},  {0xCC, 0x74, 0x00, 0xFF}}},
{{{    -2,    -58,    -43}, 0, {  1364,   1944},  {0xDB, 0x70, 0x2F, 0xFF}}},
{{{    26,    -42,    -43}, 0, {  1416,   1570},  {0xE6, 0x74, 0x2E, 0xFF}}},
{{{    27,    -23,    -71}, 0, {  1754,   1564},  {0xEB, 0x47, 0x67, 0xFF}}},
{{{    -1,    -34,    -74}, 0, {  1688,   1944},  {0xEA, 0x49, 0x65, 0xFF}}},
{{{    74,    -49,    -37}, 0, {  1340,    972},  {0x06, 0x78, 0x28, 0xFF}}},
{{{    68,    -31,    -66}, 0, {  1684,   1040},  {0x07, 0x52, 0x60, 0xFF}}},
{{{    75,    -53,      0}, 0, {   988,    966},  {0x07, 0x7F, 0x00, 0xFF}}},
{{{   141,    -50,    -27}, 0, {  1226,    218},  {0xC6, 0x6D, 0x1E, 0xFF}}},
{{{   141,    -50,     27}, 0, {   750,    218},  {0xC6, 0x6D, 0xE2, 0xFF}}},
{{{    74,    -49,     37}, 0, {   636,    972},  {0x06, 0x78, 0xD8, 0xFF}}},
{{{   151,    -16,     57}, 0, {   988,    -60},  {0xAB, 0x27, 0xAA, 0xFF}}},
{{{    92,      2,     75}, 0, {   988,    -60},  {0xF1, 0x00, 0x82, 0xFF}}},
{{{    98,    -23,     73}, 0, {   988,    -60},  {0xF3, 0x2E, 0x8A, 0xFF}}},
{{{   130,    -37,     58}, 0, {   988,    -60},  {0xD9, 0x55, 0xA9, 0xFF}}},
{{{   155,      2,    -57}, 0, {   924,   -132},  {0xA3, 0x02, 0x57, 0xFF}}},
{{{    92,      2,    -75}, 0, {   924,   -132},  {0xF1, 0x00, 0x7E, 0xFF}}},
{{{    98,     25,    -73}, 0, {   924,   -132},  {0xEC, 0xE8, 0x7B, 0xFF}}},
{{{   151,     25,    -57}, 0, {   924,   -132},  {0xA9, 0xD5, 0x52, 0xFF}}},
{{{   129,     38,    -61}, 0, {   924,   -132},  {0xD4, 0xBD, 0x63, 0xFF}}},
{{{    92,      2,     75}, 0, {   924,   -132},  {0xF1, 0x00, 0x82, 0xFF}}},
{{{   151,    -16,     57}, 0, {   924,   -132},  {0xAB, 0x27, 0xAA, 0xFF}}},
{{{   155,      2,     57}, 0, {   924,   -132},  {0xA3, 0x02, 0xA9, 0xFF}}},
{{{    98,     25,     73}, 0, {   924,   -132},  {0xEC, 0xE8, 0x85, 0xFF}}},
{{{   151,     25,     57}, 0, {   924,   -132},  {0xA9, 0xD5, 0xAE, 0xFF}}},
{{{   129,     38,     61}, 0, {   924,   -132},  {0xD4, 0xBD, 0x9D, 0xFF}}},
{{{   162,      0,    -34}, 0, {   510,    -80},  {0x83, 0x03, 0x18, 0xFF}}},
{{{   155,      2,    -57}, 0, {   216,    -80},  {0xA3, 0x02, 0x57, 0xFF}}},
{{{   151,     25,    -57}, 0, {   300,     30},  {0xA9, 0xD5, 0x52, 0xFF}}},
{{{   161,     31,      0}, 0, {   986,    -80},  {0x8A, 0xD1, 0x00, 0xFF}}},
{{{   135,     62,    -24}, 0, {   764,    280},  {0xBD, 0x99, 0x1F, 0xFF}}},
{{{   129,     38,    -61}, 0, {   276,    322},  {0xD4, 0xBD, 0x63, 0xFF}}},
{{{    78,     71,    -43}, 0, {   578,    946},  {0xE8, 0x92, 0x3B, 0xFF}}},
{{{    68,     45,    -70}, 0, {   266,   1032},  {0xF1, 0xC8, 0x71, 0xFF}}},
{{{    98,     25,    -73}, 0, {   130,    686},  {0xEC, 0xE8, 0x7B, 0xFF}}},
{{{    63,      1,    -75}, 0, {   -32,   1090},  {0xFA, 0x09, 0x7F, 0xFF}}},
{{{    92,      2,    -75}, 0, {   -32,    742},  {0xF1, 0x00, 0x7E, 0xFF}}},
{{{    30,      1,    -79}, 0, {   -32,   1500},  {0xEE, 0x0C, 0x7D, 0xFF}}},
{{{    31,     44,    -73}, 0, {   260,   1526},  {0xFA, 0xD1, 0x76, 0xFF}}},
{{{    -2,      2,    -85}, 0, {   -32,   1924},  {0xF7, 0x02, 0x7F, 0xFF}}},
{{{    -5,     45,    -72}, 0, {   288,   1924},  {0x05, 0xC4, 0x70, 0xFF}}},
{{{    30,     69,    -56}, 0, {   486,   1530},  {0xFC, 0x9D, 0x4F, 0xFF}}},
{{{    -7,     72,    -49}, 0, {   578,   1924},  {0x10, 0x93, 0x3F, 0xFF}}},
{{{    28,     83,    -20}, 0, {   816,   1542},  {0xFE, 0x83, 0x16, 0xFF}}},
{{{    -8,     81,      0}, 0, {   986,   1924},  {0x13, 0x82, 0x00, 0xFF}}},
{{{    28,     83,     20}, 0, {  1156,   1542},  {0xFE, 0x83, 0xEA, 0xFF}}},
{{{    -7,     72,     49}, 0, {  1394,   1924},  {0x10, 0x93, 0xC1, 0xFF}}},
{{{    30,     69,     56}, 0, {  1486,   1530},  {0xFC, 0x9D, 0xB1, 0xFF}}},
{{{    -5,     45,     72}, 0, {  1684,   1924},  {0x05, 0xC4, 0x90, 0xFF}}},
{{{    31,     44,     73}, 0, {  1712,   1526},  {0xFA, 0xD1, 0x8A, 0xFF}}},
{{{    -2,      2,     85}, 0, {  2016,   1924},  {0xF7, 0x02, 0x81, 0xFF}}},
{{{    30,      1,     79}, 0, {  2016,   1500},  {0xEE, 0x0C, 0x83, 0xFF}}},
{{{    68,     45,     70}, 0, {  1706,   1032},  {0xF1, 0xC8, 0x8F, 0xFF}}},
{{{    63,      1,     75}, 0, {  2016,   1090},  {0xFA, 0x09, 0x81, 0xFF}}},
{{{    98,     25,     73}, 0, {  1840,    686},  {0xEC, 0xE8, 0x85, 0xFF}}},
{{{    92,      2,     75}, 0, {  2016,    742},  {0xF1, 0x00, 0x82, 0xFF}}},
{{{   129,     38,     61}, 0, {  1696,    322},  {0xD4, 0xBD, 0x9D, 0xFF}}},
{{{    78,     71,     43}, 0, {  1392,    946},  {0xE8, 0x92, 0xC5, 0xFF}}},
{{{    78,     71,     43}, 0, {  1392,    946},  {0xE8, 0x92, 0xC5, 0xFF}}},
{{{   129,     38,     61}, 0, {  1696,    322},  {0xD4, 0xBD, 0x9D, 0xFF}}},
{{{   135,     62,     24}, 0, {  1206,    280},  {0xBD, 0x99, 0xE1, 0xFF}}},
{{{   151,     25,     57}, 0, {  1672,     30},  {0xA9, 0xD5, 0xAE, 0xFF}}},
{{{   161,     31,      0}, 0, {   986,    -80},  {0x8A, 0xD1, 0x00, 0xFF}}},
{{{   162,      0,     34}, 0, {  1462,    -80},  {0x83, 0x03, 0xE8, 0xFF}}},
{{{   155,      2,     57}, 0, {  1760,    -80},  {0xA3, 0x02, 0xA9, 0xFF}}},
{{{   162,      0,    -34}, 0, {   510,    -80},  {0x83, 0x03, 0x18, 0xFF}}},
{{{    68,     45,     70}, 0, {  1706,   1032},  {0xF1, 0xC8, 0x8F, 0xFF}}},
{{{    30,     69,     56}, 0, {  1486,   1530},  {0xFC, 0x9D, 0xB1, 0xFF}}},
{{{    31,     44,     73}, 0, {  1712,   1526},  {0xFA, 0xD1, 0x8A, 0xFF}}},
{{{    28,     83,     20}, 0, {  1156,   1542},  {0xFE, 0x83, 0xEA, 0xFF}}},
{{{    85,     77,      0}, 0, {   986,    890},  {0xE7, 0x83, 0x00, 0xFF}}},
{{{   135,     62,    -24}, 0, {   764,    280},  {0xBD, 0x99, 0x1F, 0xFF}}},
{{{    78,     71,    -43}, 0, {   578,    946},  {0xE8, 0x92, 0x3B, 0xFF}}},
{{{    28,     83,    -20}, 0, {   816,   1542},  {0xFE, 0x83, 0x16, 0xFF}}},
{{{    30,     69,    -56}, 0, {   486,   1530},  {0xFC, 0x9D, 0x4F, 0xFF}}},
{{{    68,     45,    -70}, 0, {   266,   1032},  {0xF1, 0xC8, 0x71, 0xFF}}},
{{{    31,     44,    -73}, 0, {   260,   1526},  {0xFA, 0xD1, 0x76, 0xFF}}},
{{{   -74,      0,     85}, 0, {    54,     75},  {0x42, 0x01, 0x93, 0xFF}}},
{{{   -78,     38,     73}, 0, {    54,     75},  {0x51, 0xD2, 0xAA, 0xFF}}},
{{{   -77,    -25,     76}, 0, {    54,     75},  {0x52, 0x2E, 0xAB, 0xFF}}},
{{{   -52,    -62,     44}, 0, {    44,    108},  {0x10, 0x72, 0xCA, 0xFF}}},
{{{    -2,    -58,     43}, 0, {    44,    108},  {0xDB, 0x70, 0xD1, 0xFF}}},
{{{    -1,    -34,     74}, 0, {    44,    108},  {0xEA, 0x49, 0x9B, 0xFF}}},
{{{   -21,    -70,      0}, 0, {    44,    108},  {0xEE, 0x7E, 0x00, 0xFF}}},
{{{   -44,    -71,      0}, 0, {    44,    108},  {0x0E, 0x7E, 0x00, 0xFF}}},
{{{   -83,    -59,      0}, 0, {    44,    108},  {0x63, 0x4F, 0x00, 0xFF}}},
{{{   -82,    -50,     47}, 0, {    44,    108},  {0x60, 0x46, 0xD4, 0xFF}}},
{{{   -77,    -25,     76}, 0, {    44,    108},  {0x52, 0x2E, 0xAB, 0xFF}}},
{{{   -44,    -33,     76}, 0, {    44,    108},  {0x05, 0x44, 0x95, 0xFF}}},
{{{    -2,      2,     85}, 0, {    44,    108},  {0xF7, 0x02, 0x81, 0xFF}}},
{{{   -74,      0,     85}, 0, {    44,    108},  {0x42, 0x01, 0x93, 0xFF}}},
{{{   -35,     43,     72}, 0, {    44,    108},  {0x06, 0xBE, 0x93, 0xFF}}},
{{{    -5,     45,     72}, 0, {    44,    108},  {0x05, 0xC4, 0x90, 0xFF}}},
{{{    -7,     72,     49}, 0, {    44,    108},  {0x10, 0x93, 0xC1, 0xFF}}},
{{{   -38,     66,     47}, 0, {    44,    108},  {0x13, 0x90, 0xC7, 0xFF}}},
{{{    -8,     81,      0}, 0, {    44,    108},  {0x13, 0x82, 0x00, 0xFF}}},
{{{   -83,     69,      0}, 0, {    44,    108},  {0x5C, 0xA9, 0x00, 0xFF}}},
{{{   -38,     66,    -47}, 0, {    44,    108},  {0x13, 0x90, 0x39, 0xFF}}},
{{{    -7,     72,    -49}, 0, {    44,    108},  {0x10, 0x93, 0x3F, 0xFF}}},
{{{   -35,     43,    -72}, 0, {    44,    108},  {0x06, 0xBE, 0x6D, 0xFF}}},
{{{    -5,     45,    -72}, 0, {    44,    108},  {0x05, 0xC4, 0x70, 0xFF}}},
{{{    -2,      2,    -85}, 0, {    44,    108},  {0xF7, 0x02, 0x7F, 0xFF}}},
{{{   -74,      0,    -85}, 0, {    44,    108},  {0x42, 0x01, 0x6D, 0xFF}}},
{{{   -44,    -33,    -76}, 0, {    44,    108},  {0x05, 0x44, 0x6B, 0xFF}}},
{{{    -1,    -34,    -74}, 0, {    44,    108},  {0xEA, 0x49, 0x65, 0xFF}}},
{{{   -52,    -62,    -44}, 0, {    44,    108},  {0x10, 0x72, 0x36, 0xFF}}},
{{{    -2,    -58,    -43}, 0, {    44,    108},  {0xDB, 0x70, 0x2F, 0xFF}}},
{{{    -3,    -65,      0}, 0, {    44,    108},  {0xCC, 0x74, 0x00, 0xFF}}},
{{{   -82,    -50,    -47}, 0, {    44,    108},  {0x60, 0x46, 0x2C, 0xFF}}},
{{{   -82,    -50,    -47}, 0, {    44,    108},  {0x60, 0x46, 0x2C, 0xFF}}},
{{{   -83,    -59,      0}, 0, {    44,    108},  {0x63, 0x4F, 0x00, 0xFF}}},
{{{   -82,     60,    -46}, 0, {    44,    108},  {0x5E, 0xB6, 0x2A, 0xFF}}},
{{{   -83,     69,      0}, 0, {    44,    108},  {0x5C, 0xA9, 0x00, 0xFF}}},
{{{   -82,     60,     46}, 0, {    44,    108},  {0x5E, 0xB6, 0xD6, 0xFF}}},
{{{   -82,    -50,     47}, 0, {    44,    108},  {0x60, 0x46, 0xD4, 0xFF}}},
{{{   -78,     38,     73}, 0, {    54,     75},  {0x51, 0xD2, 0xAA, 0xFF}}},
{{{   -77,    -25,     76}, 0, {    44,    108},  {0x52, 0x2E, 0xAB, 0xFF}}},
{{{   -71,     63,     46}, 0, {    44,    108},  {0x14, 0x8E, 0xCB, 0xFF}}},
{{{   -78,     38,     73}, 0, {    44,    108},  {0x51, 0xD2, 0xAA, 0xFF}}},
{{{   -67,     40,     73}, 0, {    44,    108},  {0x08, 0xBB, 0x95, 0xFF}}},
{{{   -74,      0,     85}, 0, {    44,    108},  {0x42, 0x01, 0x93, 0xFF}}},
{{{   -35,     43,     72}, 0, {    44,    108},  {0x06, 0xBE, 0x93, 0xFF}}},
{{{   -38,     66,     47}, 0, {    44,    108},  {0x13, 0x90, 0xC7, 0xFF}}},
{{{   -44,    -33,     76}, 0, {    44,    108},  {0x05, 0x44, 0x95, 0xFF}}},
{{{   -77,    -25,    -76}, 0, {    44,    108},  {0x52, 0x2E, 0x55, 0xFF}}},
{{{   -74,      0,    -85}, 0, {    44,    108},  {0x42, 0x01, 0x6D, 0xFF}}},
{{{   -44,    -33,    -76}, 0, {    44,    108},  {0x05, 0x44, 0x6B, 0xFF}}},
{{{   -78,     38,    -73}, 0, {    44,    108},  {0x51, 0xD2, 0x56, 0xFF}}},
{{{   -52,    -62,    -44}, 0, {    44,    108},  {0x10, 0x72, 0x36, 0xFF}}},
{{{   -71,     63,    -46}, 0, {    44,    108},  {0x14, 0x8E, 0x35, 0xFF}}},
{{{   -38,     66,    -47}, 0, {    44,    108},  {0x13, 0x90, 0x39, 0xFF}}},
{{{   -67,     40,    -73}, 0, {    44,    108},  {0x08, 0xBB, 0x6B, 0xFF}}},
{{{   -35,     43,    -72}, 0, {    44,    108},  {0x06, 0xBE, 0x6D, 0xFF}}},
};

const Gfx isabelle_outfit_back_tris[] = {
	gsSPVertex(_000_offset_001_mesh_vtx + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 4, 3, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 10, 13, 12, 0),
	gsSP2Triangles(12, 13, 14, 0, 13, 15, 14, 0),
	gsSP2Triangles(16, 12, 14, 0, 17, 12, 16, 0),
	gsSP2Triangles(18, 17, 16, 0, 18, 16, 19, 0),
	gsSP2Triangles(18, 19, 20, 0, 19, 21, 20, 0),
	gsSP2Triangles(19, 22, 21, 0, 18, 20, 23, 0),
	gsSP2Triangles(23, 20, 24, 0, 24, 20, 25, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 23, 24, 0),
	gsSP2Triangles(28, 23, 27, 0, 28, 27, 29, 0),
	gsSP2Triangles(27, 30, 29, 0, 29, 30, 31, 0),
	gsSPVertex(_000_offset_001_mesh_vtx + 32, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
	gsSP2Triangles(5, 4, 3, 0, 6, 5, 3, 0),
	gsSP2Triangles(6, 3, 7, 0, 8, 5, 6, 0),
	gsSP2Triangles(9, 5, 8, 0, 10, 9, 8, 0),
	gsSP2Triangles(10, 8, 11, 0, 10, 11, 12, 0),
	gsSP2Triangles(10, 12, 13, 0, 12, 14, 13, 0),
	gsSP2Triangles(12, 15, 14, 0, 13, 14, 16, 0),
	gsSP2Triangles(16, 14, 17, 0, 10, 13, 16, 0),
	gsSP2Triangles(10, 16, 18, 0, 18, 16, 19, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(10, 18, 21, 0, 10, 21, 9, 0),
	gsSP2Triangles(9, 21, 5, 0, 21, 4, 5, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 28, 29, 26, 0),
	gsSP1Triangle(29, 28, 30, 0),
	gsSPVertex(_000_offset_001_mesh_vtx + 63, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_outfit_front_tris[] = {
	gsSPVertex(_000_offset_001_mesh_vtx + 69, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(7, 5, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(8, 10, 9, 0, 7, 9, 11, 0),
	gsSP2Triangles(7, 11, 12, 0, 11, 13, 12, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 12, 14, 0),
	gsSP2Triangles(16, 15, 14, 0, 17, 15, 16, 0),
	gsSP2Triangles(17, 16, 18, 0, 19, 17, 18, 0),
	gsSP2Triangles(19, 18, 20, 0, 19, 20, 21, 0),
	gsSP2Triangles(20, 22, 21, 0, 23, 21, 22, 0),
	gsSP2Triangles(23, 22, 24, 0, 23, 24, 25, 0),
	gsSP2Triangles(26, 23, 25, 0, 26, 25, 27, 0),
	gsSP2Triangles(26, 27, 28, 0, 28, 27, 29, 0),
	gsSP2Triangles(26, 28, 30, 0, 26, 30, 31, 0),
	gsSPVertex(_000_offset_001_mesh_vtx + 101, 19, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(3, 4, 2, 0, 3, 5, 4, 0),
	gsSP2Triangles(3, 6, 5, 0, 5, 7, 4, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 0, 9, 0),
	gsSP2Triangles(0, 11, 9, 0, 0, 12, 11, 0),
	gsSP2Triangles(0, 2, 12, 0, 12, 2, 13, 0),
	gsSP2Triangles(2, 4, 13, 0, 12, 13, 14, 0),
	gsSP2Triangles(12, 14, 15, 0, 15, 14, 16, 0),
	gsSP2Triangles(14, 17, 16, 0, 17, 18, 16, 0),
	gsSP1Triangle(11, 12, 15, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_shz_extra_colors_skirt_tris[] = {
	gsSPVertex(_000_offset_001_mesh_vtx + 120, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 6, 4, 0, 3, 7, 6, 0),
	gsSP2Triangles(3, 8, 7, 0, 3, 9, 8, 0),
	gsSP2Triangles(3, 10, 9, 0, 3, 11, 10, 0),
	gsSP2Triangles(3, 5, 11, 0, 5, 12, 11, 0),
	gsSP2Triangles(11, 12, 13, 0, 12, 14, 13, 0),
	gsSP2Triangles(12, 15, 14, 0, 15, 16, 14, 0),
	gsSP2Triangles(14, 16, 17, 0, 16, 18, 17, 0),
	gsSP2Triangles(19, 17, 18, 0, 19, 18, 20, 0),
	gsSP2Triangles(21, 20, 18, 0, 22, 20, 21, 0),
	gsSP2Triangles(22, 21, 23, 0, 22, 23, 24, 0),
	gsSP2Triangles(25, 22, 24, 0, 25, 24, 26, 0),
	gsSP2Triangles(26, 24, 27, 0, 28, 26, 27, 0),
	gsSP2Triangles(29, 28, 27, 0, 6, 28, 29, 0),
	gsSP2Triangles(30, 6, 29, 0, 6, 30, 4, 0),
	gsSP2Triangles(7, 28, 6, 0, 8, 28, 7, 0),
	gsSP1Triangle(8, 31, 28, 0),
	gsSPVertex(_000_offset_001_mesh_vtx + 152, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(3, 1, 4, 0, 1, 5, 4, 0),
	gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
	gsSP2Triangles(3, 4, 8, 0, 9, 8, 4, 0),
	gsSP2Triangles(10, 8, 9, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 12, 10, 0, 10, 12, 13, 0),
	gsSP2Triangles(10, 13, 8, 0, 3, 8, 13, 0),
	gsSP2Triangles(7, 14, 11, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 16, 15, 0, 0, 18, 15, 0),
	gsSP2Triangles(0, 15, 19, 0, 15, 17, 19, 0),
	gsSP2Triangles(2, 18, 0, 0, 18, 2, 20, 0),
	gsSP2Triangles(2, 3, 20, 0, 3, 21, 20, 0),
	gsSP2Triangles(22, 20, 21, 0, 23, 22, 21, 0),
	gsSP2Triangles(16, 22, 23, 0, 16, 18, 22, 0),
	gsSP1Triangle(18, 20, 22, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_body[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_outfit_back_tris),
	gsSPDisplayList(isabelle_outfit_front_tris),
	gsSPDisplayList(isabelle_shz_extra_colors_skirt_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_body[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_outfit_back),
	gsSPDisplayList(isabelle_outfit_back_tris),
	gsSPDisplayList(isabelle_tex_outfit_front),
	gsSPDisplayList(isabelle_outfit_front_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPDisplayList(isabelle_tex_extras),
	gsSPDisplayList(isabelle_shz_extra_colors_skirt_tris),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Vtx _000_displaylist_mesh_vtx[] = {
{{{   101,    146,     88}, 0, {  1648,    416},  {0xCD, 0xA3, 0xB9, 0xFF}}},
{{{   117,     91,    106}, 0, {  1136,    -32},  {0xC9, 0xB7, 0xA8, 0xFF}}},
{{{   126,    123,     62}, 0, {  1456,     32},  {0xB4, 0xAA, 0xCA, 0xFF}}},
{{{    79,     99,    138}, 0, {   880,    608},  {0xF0, 0xC8, 0x8F, 0xFF}}},
{{{   109,     59,    134}, 0, {   752,     32},  {0xD7, 0xDF, 0x8C, 0xFF}}},
{{{   101,    146,    -87}, 0, {  1648,    416},  {0xCD, 0xA3, 0x47, 0xFF}}},
{{{   126,    123,    -62}, 0, {  1456,     32},  {0xB4, 0xA9, 0x36, 0xFF}}},
{{{   117,     91,   -106}, 0, {  1136,    -32},  {0xC9, 0xB7, 0x58, 0xFF}}},
{{{    79,     99,   -138}, 0, {   880,    608},  {0xF1, 0xC8, 0x71, 0xFF}}},
{{{   109,     59,   -134}, 0, {   752,     32},  {0xD6, 0xE0, 0x74, 0xFF}}},
{{{    90,    171,      0}, 0, {     0,    656},  {0x0A, 0x81, 0x00, 0xFF}}},
{{{   119,    169,    -25}, 0, {   256,    272},  {0xB8, 0x9B, 0x19, 0xFF}}},
{{{    73,    161,    -53}, 0, {   512,    848},  {0x11, 0x88, 0x27, 0xFF}}},
{{{   119,    169,      0}, 0, {     0,    272},  {0xB5, 0x9A, 0x00, 0xFF}}},
{{{   119,    169,     25}, 0, {   256,    272},  {0xB8, 0x9B, 0xE7, 0xFF}}},
{{{    73,    161,     53}, 0, {   512,    848},  {0x11, 0x88, 0xD9, 0xFF}}},
{{{    20,     95,   -113}, 0, {  1584,    288},  {0x54, 0xCA, 0x4E, 0xFF}}},
{{{    60,     50,   -146}, 0, {  1520,    224},  {0x13, 0xEE, 0x7C, 0xFF}}},
{{{    12,     44,   -122}, 0, {  1520,    288},  {0x5C, 0xEE, 0x55, 0xFF}}},
{{{    79,     99,   -138}, 0, {  1520,    224},  {0xF1, 0xC8, 0x71, 0xFF}}},
{{{    58,    130,   -105}, 0, {  1584,    224},  {0x21, 0xA3, 0x50, 0xFF}}},
{{{   101,    146,    -87}, 0, {  1584,    224},  {0xCD, 0xA3, 0x47, 0xFF}}},
{{{   109,     59,   -134}, 0, {  1520,    160},  {0xD6, 0xE0, 0x74, 0xFF}}},
{{{    20,     95,   -113}, 0, {  1712,    352},  {0x54, 0xCA, 0x4E, 0xFF}}},
{{{    12,     44,   -122}, 0, {  1648,    352},  {0x5C, 0xEE, 0x55, 0xFF}}},
{{{     0,     84,    -73}, 0, {  1712,    416},  {0x76, 0xDB, 0x1C, 0xFF}}},
{{{    -7,     36,    -79}, 0, {  1648,    416},  {0x7B, 0xF3, 0x1E, 0xFF}}},
{{{   -13,     31,      0}, 0, {  1712,    544},  {0x7E, 0xF3, 0x00, 0xFF}}},
{{{    -2,     89,      0}, 0, {  1776,    480},  {0x7A, 0xDE, 0x00, 0xFF}}},
{{{   -13,     31,      0}, 0, {  1776,    544},  {0x7E, 0xF3, 0x00, 0xFF}}},
{{{     0,     84,     73}, 0, {  1776,    416},  {0x76, 0xDA, 0xE4, 0xFF}}},
{{{    -7,     36,     80}, 0, {  1840,    416},  {0x7B, 0xF3, 0xE2, 0xFF}}},
{{{     0,     84,     73}, 0, {  1776,    416},  {0x76, 0xDA, 0xE4, 0xFF}}},
{{{    -7,     36,     80}, 0, {  1840,    416},  {0x7B, 0xF3, 0xE2, 0xFF}}},
{{{    12,     44,    122}, 0, {  1840,    352},  {0x5C, 0xEE, 0xAB, 0xFF}}},
{{{    20,     95,    113}, 0, {  1776,    352},  {0x54, 0xCA, 0xB2, 0xFF}}},
{{{    60,     50,    146}, 0, {  1840,    288},  {0x13, 0xEE, 0x84, 0xFF}}},
{{{    79,     99,    138}, 0, {  1840,    288},  {0xF0, 0xC8, 0x8F, 0xFF}}},
{{{   109,     59,    134}, 0, {  1840,    224},  {0xD7, 0xDF, 0x8C, 0xFF}}},
{{{    58,    130,    106}, 0, {  1776,    288},  {0x21, 0xA3, 0xB0, 0xFF}}},
{{{   101,    146,     88}, 0, {  1776,    288},  {0xCD, 0xA3, 0xB9, 0xFF}}},
{{{    41,    148,     66}, 0, {   624,   1248},  {0x3D, 0x9A, 0xD3, 0xFF}}},
{{{    20,     95,    113}, 0, {  1072,   1568},  {0x54, 0xCA, 0xB2, 0xFF}}},
{{{    58,    130,    106}, 0, {  1008,   1056},  {0x21, 0xA3, 0xB0, 0xFF}}},
{{{    16,    135,     35}, 0, {   304,   1632},  {0x64, 0xB4, 0xF0, 0xFF}}},
{{{    53,    165,      0}, 0, {   -16,   1120},  {0x31, 0x8B, 0x00, 0xFF}}},
{{{    73,    161,     53}, 0, {   496,    864},  {0x11, 0x88, 0xD9, 0xFF}}},
{{{   101,    146,     88}, 0, {   816,    480},  {0xCD, 0xA3, 0xB9, 0xFF}}},
{{{   119,    169,     25}, 0, {   240,    288},  {0xB8, 0x9B, 0xE7, 0xFF}}},
{{{   126,    123,     62}, 0, {   560,    224},  {0xB4, 0xAA, 0xCA, 0xFF}}},
{{{   131,    137,      0}, 0, {   -16,    160},  {0xA3, 0xAA, 0x00, 0xFF}}},
{{{   119,    169,      0}, 0, {   -16,    288},  {0xB5, 0x9A, 0x00, 0xFF}}},
{{{   119,    169,    -25}, 0, {   240,    288},  {0xB8, 0x9B, 0x19, 0xFF}}},
{{{   126,    123,    -62}, 0, {   560,    224},  {0xB4, 0xA9, 0x36, 0xFF}}},
{{{   101,    146,    -87}, 0, {   816,    480},  {0xCD, 0xA3, 0x47, 0xFF}}},
{{{    73,    161,    -53}, 0, {   496,    864},  {0x11, 0x88, 0x27, 0xFF}}},
{{{    58,    130,   -105}, 0, {  1008,   1056},  {0x21, 0xA3, 0x50, 0xFF}}},
{{{    41,    148,    -66}, 0, {   624,   1248},  {0x3C, 0x99, 0x2D, 0xFF}}},
{{{    20,     95,   -113}, 0, {  1072,   1568},  {0x54, 0xCA, 0x4E, 0xFF}}},
{{{    16,    135,    -35}, 0, {   304,   1632},  {0x64, 0xB4, 0x10, 0xFF}}},
{{{     0,     84,    -73}, 0, {   688,   1824},  {0x76, 0xDB, 0x1C, 0xFF}}},
{{{    -2,     89,      0}, 0, {   -16,   1824},  {0x7A, 0xDE, 0x00, 0xFF}}},
{{{    16,    135,      0}, 0, {   -16,   1632},  {0x66, 0xB5, 0x00, 0xFF}}},
{{{     0,     84,     73}, 0, {   688,   1824},  {0x76, 0xDA, 0xE4, 0xFF}}},
{{{    53,    165,      0}, 0, {   -16,   1120},  {0x31, 0x8B, 0x00, 0xFF}}},
{{{    90,    171,      0}, 0, {   -16,    672},  {0x0A, 0x81, 0x00, 0xFF}}},
{{{    73,    161,    -53}, 0, {   496,    864},  {0x11, 0x88, 0x27, 0xFF}}},
{{{    73,    161,     53}, 0, {   496,    864},  {0x11, 0x88, 0xD9, 0xFF}}},
{{{   188,     -4,    120}, 0, {  2192,     10},  {0x62, 0x4F, 0xF0, 0xFF}}},
{{{   232,     -4,    106}, 0, {  2192,     10},  {0xA3, 0x06, 0xAA, 0xFF}}},
{{{   217,     45,    128}, 0, {  2192,     10},  {0xDE, 0xF6, 0x86, 0xFF}}},
{{{   232,     -4,   -106}, 0, {   276,    -84},  {0xA3, 0x05, 0x56, 0xFF}}},
{{{   188,     -4,   -120}, 0, {   276,    -84},  {0x69, 0x45, 0x12, 0xFF}}},
{{{   217,     45,   -127}, 0, {   276,    -84},  {0xDF, 0xF6, 0x7A, 0xFF}}},
{{{   268,     -4,    -74}, 0, {  2416,     86},  {0x90, 0x0F, 0x3A, 0xFF}}},
{{{   232,     -4,   -106}, 0, {  2456,    150},  {0xA3, 0x05, 0x56, 0xFF}}},
{{{   263,     42,    -89}, 0, {  2422,    136},  {0x96, 0xF7, 0x45, 0xFF}}},
{{{   275,     68,    -36}, 0, {  2392,    128},  {0x8A, 0xD3, 0x0C, 0xFF}}},
{{{   280,     -4,      0}, 0, {  2374,     56},  {0x85, 0xE2, 0x00, 0xFF}}},
{{{   275,     68,      0}, 0, {  2374,    128},  {0x90, 0xC3, 0x00, 0xFF}}},
{{{   275,     68,     36}, 0, {  2356,    128},  {0x8A, 0xD3, 0xF4, 0xFF}}},
{{{   268,     -4,     74}, 0, {  2332,     86},  {0x90, 0x0F, 0xC6, 0xFF}}},
{{{   263,     42,     89}, 0, {  2326,    136},  {0x96, 0xF7, 0xBB, 0xFF}}},
{{{   232,     -4,    106}, 0, {  2294,    150},  {0xA3, 0x06, 0xAA, 0xFF}}},
{{{   232,    -58,   -102}, 0, {  2430,    326},  {0x9B, 0x22, 0x45, 0xFF}}},
{{{   232,     -4,   -106}, 0, {  2448,    310},  {0xA3, 0x05, 0x56, 0xFF}}},
{{{   268,     -4,    -74}, 0, {  2408,    310},  {0x90, 0x0F, 0x3A, 0xFF}}},
{{{   264,    -84,    -37}, 0, {  2386,    318},  {0xB2, 0x48, 0x47, 0xFF}}},
{{{   280,     -4,      0}, 0, {  2374,    310},  {0x85, 0xE2, 0x00, 0xFF}}},
{{{   232,   -108,    -68}, 0, {  2408,    330},  {0xAB, 0x4D, 0x36, 0xFF}}},
{{{   263,     42,     89}, 0, {  1816,    -66},  {0x96, 0xF7, 0xBB, 0xFF}}},
{{{   217,     45,    128}, 0, {  1816,    -66},  {0xDE, 0xF6, 0x86, 0xFF}}},
{{{   232,     -4,    106}, 0, {  1816,    -66},  {0xA3, 0x06, 0xAA, 0xFF}}},
{{{   236,     92,    104}, 0, {  1816,    -66},  {0xCA, 0xB4, 0xAA, 0xFF}}},
{{{   275,     68,     36}, 0, {  1816,    -66},  {0x8A, 0xD3, 0xF4, 0xFF}}},
{{{   240,    123,     44}, 0, {  1816,    -66},  {0xCA, 0x8D, 0x01, 0xFF}}},
{{{   232,    100,      0}, 0, {  1816,    -66},  {0xC6, 0x8F, 0x00, 0xFF}}},
{{{   275,     68,      0}, 0, {  1816,    -66},  {0x90, 0xC3, 0x00, 0xFF}}},
{{{   275,     68,    -36}, 0, {  1816,    -66},  {0x8A, 0xD3, 0x0C, 0xFF}}},
{{{   240,    123,    -44}, 0, {  1816,    -66},  {0xCA, 0x8D, 0xFF, 0xFF}}},
{{{   240,    123,    -44}, 0, {  1816,    -66},  {0xCA, 0x8D, 0xFF, 0xFF}}},
{{{   275,     68,    -36}, 0, {  1816,    -66},  {0x8A, 0xD3, 0x0C, 0xFF}}},
{{{   236,     92,   -104}, 0, {  1816,    -66},  {0xCA, 0xB4, 0x56, 0xFF}}},
{{{   263,     42,    -89}, 0, {  1816,    -66},  {0x96, 0xF7, 0x45, 0xFF}}},
{{{   217,     45,   -127}, 0, {  1816,    -66},  {0xDF, 0xF6, 0x7A, 0xFF}}},
{{{   232,     -4,   -106}, 0, {  1816,    -66},  {0xA3, 0x05, 0x56, 0xFF}}},
{{{    60,     50,   -146}, 0, {   126,     90},  {0x13, 0xEE, 0x7C, 0xFF}}},
{{{   109,     59,   -134}, 0, {   132,     52},  {0xD6, 0xE0, 0x74, 0xFF}}},
{{{    98,     -4,   -144}, 0, {   106,     52},  {0xEA, 0xFF, 0x7D, 0xFF}}},
{{{    49,     -4,   -146}, 0, {   108,     92},  {0x22, 0x06, 0x7A, 0xFF}}},
{{{    12,     44,   -122}, 0, {   128,    142},  {0x5C, 0xEE, 0x55, 0xFF}}},
{{{     8,     -2,   -120}, 0, {   110,    130},  {0x62, 0x09, 0x50, 0xFF}}},
{{{    -7,     36,    -79}, 0, {   130,    178},  {0x7B, 0xF3, 0x1E, 0xFF}}},
{{{    -7,      0,    -83}, 0, {   110,    160},  {0x7A, 0x06, 0x22, 0xFF}}},
{{{   -13,      0,    -34}, 0, {   112,    188},  {0x7F, 0x01, 0x09, 0xFF}}},
{{{   -13,     31,      0}, 0, {   172,    218},  {0x7E, 0xF3, 0x00, 0xFF}}},
{{{   109,     59,   -134}, 0, {  1474,   2038},  {0xD6, 0xE0, 0x74, 0xFF}}},
{{{   140,     -4,   -131}, 0, {  1894,   1534},  {0xDE, 0xF9, 0x7A, 0xFF}}},
{{{    98,     -4,   -144}, 0, {  1904,   2030},  {0xEA, 0xFF, 0x7D, 0xFF}}},
{{{   156,     55,   -120}, 0, {  1438,   1470},  {0xEE, 0xD9, 0x78, 0xFF}}},
{{{   166,     94,    -94}, 0, {   942,   1400},  {0xF8, 0xA0, 0x52, 0xFF}}},
{{{   117,     91,   -106}, 0, {  1018,   2038},  {0xC9, 0xB7, 0x58, 0xFF}}},
{{{   126,    123,    -62}, 0, {   610,   2030},  {0xB4, 0xA9, 0x36, 0xFF}}},
{{{   176,    117,    -40}, 0, {   374,   1248},  {0xEC, 0x84, 0x15, 0xFF}}},
{{{   131,    137,      0}, 0, {   -16,   2030},  {0xA3, 0xAA, 0x00, 0xFF}}},
{{{   176,    117,      0}, 0, {   -16,   1248},  {0xD3, 0x89, 0x00, 0xFF}}},
{{{   176,    117,     40}, 0, {   374,   1248},  {0xEC, 0x84, 0xEB, 0xFF}}},
{{{   126,    123,     62}, 0, {   610,   2030},  {0xB4, 0xAA, 0xCA, 0xFF}}},
{{{   166,     94,     94}, 0, {   938,   1400},  {0xF9, 0x9F, 0xAF, 0xFF}}},
{{{   117,     91,    106}, 0, {  1016,   2038},  {0xC9, 0xB7, 0xA8, 0xFF}}},
{{{   109,     59,    134}, 0, {  1472,   2038},  {0xD7, 0xDF, 0x8C, 0xFF}}},
{{{   156,     55,    121}, 0, {  1438,   1470},  {0xEF, 0xD9, 0x88, 0xFF}}},
{{{   156,     55,    121}, 0, {  1438,   1470},  {0xEF, 0xD9, 0x88, 0xFF}}},
{{{   109,     59,    134}, 0, {  1472,   2038},  {0xD7, 0xDF, 0x8C, 0xFF}}},
{{{   140,     -4,    131}, 0, {  1894,   1534},  {0xDF, 0xFA, 0x85, 0xFF}}},
{{{    98,     -4,    144}, 0, {  1904,   2030},  {0xEA, 0xFF, 0x83, 0xFF}}},
{{{   188,     -4,    120}, 0, {  1874,    624},  {0x62, 0x4F, 0xF0, 0xFF}}},
{{{   217,     45,    128}, 0, {  1490,    462},  {0xDE, 0xF6, 0x86, 0xFF}}},
{{{   236,     92,    104}, 0, {  1050,    316},  {0xCA, 0xB4, 0xAA, 0xFF}}},
{{{   166,     94,     94}, 0, {   938,   1400},  {0xF9, 0x9F, 0xAF, 0xFF}}},
{{{   240,    123,     44}, 0, {   410,    250},  {0xCA, 0x8D, 0x01, 0xFF}}},
{{{   176,    117,     40}, 0, {   374,   1248},  {0xEC, 0x84, 0xEB, 0xFF}}},
{{{   232,    100,      0}, 0, {   -16,    532},  {0xC6, 0x8F, 0x00, 0xFF}}},
{{{   176,    117,      0}, 0, {   -16,   1248},  {0xD3, 0x89, 0x00, 0xFF}}},
{{{   176,    117,    -40}, 0, {   374,   1248},  {0xEC, 0x84, 0x15, 0xFF}}},
{{{   240,    123,    -44}, 0, {   410,    250},  {0xCA, 0x8D, 0xFF, 0xFF}}},
{{{   166,     94,    -94}, 0, {   942,   1400},  {0xF8, 0xA0, 0x52, 0xFF}}},
{{{   236,     92,   -104}, 0, {  1052,    316},  {0xCA, 0xB4, 0x56, 0xFF}}},
{{{   156,     55,   -120}, 0, {  1438,   1470},  {0xEE, 0xD9, 0x78, 0xFF}}},
{{{   217,     45,   -127}, 0, {  1492,    462},  {0xDF, 0xF6, 0x7A, 0xFF}}},
{{{   188,     -4,   -120}, 0, {  1874,    624},  {0x69, 0x45, 0x12, 0xFF}}},
{{{   140,     -4,   -131}, 0, {  1894,   1534},  {0xDE, 0xF9, 0x7A, 0xFF}}},
{{{   232,    -58,    102}, 0, {  2316,    326},  {0x9B, 0x22, 0xBB, 0xFF}}},
{{{   268,     -4,     74}, 0, {  2338,    310},  {0x90, 0x0F, 0xC6, 0xFF}}},
{{{   232,     -4,    106}, 0, {  2302,    310},  {0xA3, 0x06, 0xAA, 0xFF}}},
{{{   264,    -84,     37}, 0, {  2360,    318},  {0xA3, 0x42, 0xC9, 0xFF}}},
{{{   232,   -108,     68}, 0, {  2340,    330},  {0xAB, 0x4D, 0xCA, 0xFF}}},
{{{   280,     -4,      0}, 0, {  2374,    310},  {0x85, 0xE2, 0x00, 0xFF}}},
{{{    60,     50,    146}, 0, {   262,     90},  {0x13, 0xEE, 0x84, 0xFF}}},
{{{    98,     -4,    144}, 0, {   280,     52},  {0xEA, 0xFF, 0x83, 0xFF}}},
{{{   109,     59,    134}, 0, {   256,     52},  {0xD7, 0xDF, 0x8C, 0xFF}}},
{{{    49,     -4,    146}, 0, {   280,     92},  {0x22, 0x06, 0x86, 0xFF}}},
{{{    12,     44,    122}, 0, {   258,    142},  {0x5C, 0xEE, 0xAB, 0xFF}}},
{{{     8,     -2,    120}, 0, {   276,    130},  {0x62, 0x09, 0xB0, 0xFF}}},
{{{     8,     -2,    120}, 0, {   276,    130},  {0x62, 0x09, 0xB0, 0xFF}}},
{{{    12,     44,    122}, 0, {   258,    142},  {0x5C, 0xEE, 0xAB, 0xFF}}},
{{{    -7,     36,     80}, 0, {   256,    178},  {0x7B, 0xF3, 0xE2, 0xFF}}},
{{{    -7,      0,     83}, 0, {   276,    160},  {0x7A, 0x06, 0xDE, 0xFF}}},
{{{   -13,      0,     34}, 0, {   276,    188},  {0x7F, 0x01, 0xF7, 0xFF}}},
{{{   -13,     31,      0}, 0, {   214,    218},  {0x7E, 0xF3, 0x00, 0xFF}}},
{{{     8,     -2,    120}, 0, {   256,    182},  {0x62, 0x09, 0xB0, 0xFF}}},
{{{    -7,      0,     83}, 0, {   238,    188},  {0x7A, 0x06, 0xDE, 0xFF}}},
{{{     8,    -68,     93}, 0, {   230,    182},  {0x6B, 0x27, 0xC8, 0xFF}}},
{{{    -6,    -55,     57}, 0, {   214,    190},  {0x7A, 0x1A, 0xEA, 0xFF}}},
{{{   -13,      0,     34}, 0, {   222,    192},  {0x7F, 0x01, 0xF7, 0xFF}}},
{{{   -13,    -29,      0}, 0, {   194,    192},  {0x7E, 0x0D, 0x00, 0xFF}}},
{{{    -5,    -72,      0}, 0, {   194,    190},  {0x7A, 0x22, 0x00, 0xFF}}},
{{{    -6,    -55,    -57}, 0, {   172,    190},  {0x7A, 0x1A, 0x16, 0xFF}}},
{{{   -13,      0,    -34}, 0, {   166,    192},  {0x7F, 0x01, 0x09, 0xFF}}},
{{{   -13,      0,      0}, 0, {   220,    190},  {0x7F, 0x00, 0x00, 0xFF}}},
{{{   -13,     31,      0}, 0, {   172,    218},  {0x7E, 0xF3, 0x00, 0xFF}}},
{{{    -7,      0,    -83}, 0, {   148,    188},  {0x7A, 0x06, 0x22, 0xFF}}},
{{{     8,    -68,    -93}, 0, {   156,    182},  {0x6B, 0x27, 0x38, 0xFF}}},
{{{     8,     -2,   -120}, 0, {   130,    182},  {0x62, 0x09, 0x50, 0xFF}}},
{{{    46,    -72,   -135}, 0, {   146,    174},  {0x34, 0x28, 0x6D, 0xFF}}},
{{{    49,     -4,   -146}, 0, {   126,    174},  {0x22, 0x06, 0x7A, 0xFF}}},
{{{    94,    -76,   -138}, 0, {   144,    166},  {0xFA, 0x21, 0x7B, 0xFF}}},
{{{    98,     -4,   -144}, 0, {   122,    166},  {0xEA, 0xFF, 0x7D, 0xFF}}},
{{{   140,    -68,   -131}, 0, {   142,    160},  {0xE3, 0x14, 0x7A, 0xFF}}},
{{{   140,     -4,   -131}, 0, {   124,    160},  {0xDE, 0xF9, 0x7A, 0xFF}}},
{{{   188,     -4,   -120}, 0, {   126,    150},  {0x69, 0x45, 0x12, 0xFF}}},
{{{   188,    -51,   -117}, 0, {   140,    152},  {0x86, 0x0F, 0xE0, 0xFF}}},
{{{   188,   -113,   -109}, 0, {   162,    154},  {0xD0, 0x42, 0x61, 0xFF}}},
{{{   232,    -58,   -102}, 0, {   152,    144},  {0x9B, 0x22, 0x45, 0xFF}}},
{{{   232,   -108,    -68}, 0, {   168,    146},  {0xAB, 0x4D, 0x36, 0xFF}}},
{{{   188,   -148,    -46}, 0, {   182,    154},  {0xCA, 0x70, 0x1B, 0xFF}}},
{{{   232,   -124,      0}, 0, {   194,    146},  {0xAE, 0x61, 0x00, 0xFF}}},
{{{   188,   -148,    -46}, 0, {   182,    154},  {0xCA, 0x70, 0x1B, 0xFF}}},
{{{   232,   -108,    -68}, 0, {   168,    146},  {0xAB, 0x4D, 0x36, 0xFF}}},
{{{   264,    -84,    -37}, 0, {   184,    140},  {0xB2, 0x48, 0x47, 0xFF}}},
{{{   264,    -84,      0}, 0, {   194,    140},  {0xF1, 0x7E, 0x00, 0xFF}}},
{{{   264,    -84,     37}, 0, {   204,    140},  {0xA3, 0x42, 0xC9, 0xFF}}},
{{{   232,   -108,     68}, 0, {   218,    146},  {0xAB, 0x4D, 0xCA, 0xFF}}},
{{{   188,   -148,     46}, 0, {   206,    154},  {0xCA, 0x70, 0xE5, 0xFF}}},
{{{   188,   -113,    109}, 0, {   224,    154},  {0xD0, 0x42, 0x9F, 0xFF}}},
{{{   232,    -58,    102}, 0, {   236,    144},  {0x9B, 0x22, 0xBB, 0xFF}}},
{{{   188,    -51,    117}, 0, {   246,    152},  {0x86, 0x0F, 0x20, 0xFF}}},
{{{   140,    -68,    131}, 0, {   244,    160},  {0xE3, 0x14, 0x86, 0xFF}}},
{{{   188,     -4,    120}, 0, {   262,    150},  {0x62, 0x4F, 0xF0, 0xFF}}},
{{{   140,     -4,    131}, 0, {   264,    160},  {0xDF, 0xFA, 0x85, 0xFF}}},
{{{    98,     -4,    144}, 0, {   264,    166},  {0xEA, 0xFF, 0x83, 0xFF}}},
{{{    94,    -76,    138}, 0, {   244,    166},  {0xFA, 0x21, 0x85, 0xFF}}},
{{{    49,     -4,    146}, 0, {   262,    174},  {0x22, 0x06, 0x86, 0xFF}}},
{{{    46,    -72,    135}, 0, {   242,    174},  {0x34, 0x28, 0x93, 0xFF}}},
{{{     8,     -2,    120}, 0, {   256,    182},  {0x62, 0x09, 0xB0, 0xFF}}},
{{{     8,    -68,     93}, 0, {   230,    182},  {0x6B, 0x27, 0xC8, 0xFF}}},
{{{    45,   -129,     98}, 0, {   222,    174},  {0x41, 0x56, 0xBE, 0xFF}}},
{{{    10,   -111,     44}, 0, {   206,    182},  {0x6A, 0x43, 0xEC, 0xFF}}},
{{{    -6,    -55,     57}, 0, {   214,    190},  {0x7A, 0x1A, 0xEA, 0xFF}}},
{{{    -5,    -72,      0}, 0, {   194,    190},  {0x7A, 0x22, 0x00, 0xFF}}},
{{{    10,   -111,      0}, 0, {   194,    182},  {0x6D, 0x41, 0x00, 0xFF}}},
{{{    10,   -111,    -44}, 0, {   182,    182},  {0x6A, 0x43, 0x14, 0xFF}}},
{{{    -6,    -55,    -57}, 0, {   172,    190},  {0x7A, 0x1A, 0x16, 0xFF}}},
{{{     8,    -68,    -93}, 0, {   156,    182},  {0x6B, 0x27, 0x38, 0xFF}}},
{{{    45,   -129,    -98}, 0, {   164,    174},  {0x41, 0x56, 0x42, 0xFF}}},
{{{    46,    -72,   -135}, 0, {   146,    174},  {0x34, 0x28, 0x6D, 0xFF}}},
{{{    94,   -132,   -113}, 0, {   160,    166},  {0x07, 0x56, 0x5D, 0xFF}}},
{{{    94,    -76,   -138}, 0, {   144,    166},  {0xFA, 0x21, 0x7B, 0xFF}}},
{{{   140,   -114,   -116}, 0, {   162,    160},  {0xEC, 0x40, 0x6C, 0xFF}}},
{{{    94,   -132,   -113}, 0, {   160,    166},  {0x07, 0x56, 0x5D, 0xFF}}},
{{{    94,    -76,   -138}, 0, {   144,    166},  {0xFA, 0x21, 0x7B, 0xFF}}},
{{{   140,    -68,   -131}, 0, {   142,    160},  {0xE3, 0x14, 0x7A, 0xFF}}},
{{{   188,   -113,   -109}, 0, {   162,    154},  {0xD0, 0x42, 0x61, 0xFF}}},
{{{   140,   -155,    -77}, 0, {   174,    160},  {0xEA, 0x70, 0x37, 0xFF}}},
{{{   188,   -148,    -46}, 0, {   182,    154},  {0xCA, 0x70, 0x1B, 0xFF}}},
{{{   140,   -164,      0}, 0, {   194,    160},  {0xE6, 0x7C, 0x00, 0xFF}}},
{{{   188,   -148,      0}, 0, {   194,    154},  {0xCD, 0x74, 0x00, 0xFF}}},
{{{   232,   -124,      0}, 0, {   194,    146},  {0xAE, 0x61, 0x00, 0xFF}}},
{{{   188,   -148,     46}, 0, {   206,    154},  {0xCA, 0x70, 0xE5, 0xFF}}},
{{{   140,   -155,     77}, 0, {   212,    160},  {0xEA, 0x70, 0xC9, 0xFF}}},
{{{   188,   -113,    109}, 0, {   224,    154},  {0xD0, 0x42, 0x9F, 0xFF}}},
{{{   140,   -114,    116}, 0, {   224,    160},  {0xEC, 0x40, 0x94, 0xFF}}},
{{{   140,    -68,    131}, 0, {   244,    160},  {0xE3, 0x14, 0x86, 0xFF}}},
{{{    94,    -76,    138}, 0, {   244,    166},  {0xFA, 0x21, 0x85, 0xFF}}},
{{{    94,   -132,    113}, 0, {   226,    166},  {0x07, 0x56, 0xA3, 0xFF}}},
{{{    46,    -72,    135}, 0, {   242,    174},  {0x34, 0x28, 0x93, 0xFF}}},
{{{    45,   -129,     98}, 0, {   222,    174},  {0x41, 0x56, 0xBE, 0xFF}}},
{{{    92,   -168,     42}, 0, {   204,    166},  {0x12, 0x7B, 0xE6, 0xFF}}},
{{{    46,   -154,      0}, 0, {   194,    174},  {0x46, 0x6A, 0x00, 0xFF}}},
{{{    10,   -111,     44}, 0, {   206,    182},  {0x6A, 0x43, 0xEC, 0xFF}}},
{{{    10,   -111,      0}, 0, {   194,    182},  {0x6D, 0x41, 0x00, 0xFF}}},
{{{    10,   -111,    -44}, 0, {   182,    182},  {0x6A, 0x43, 0x14, 0xFF}}},
{{{    45,   -129,    -98}, 0, {   164,    174},  {0x41, 0x56, 0x42, 0xFF}}},
{{{    92,   -168,    -42}, 0, {   184,    166},  {0x12, 0x7B, 0x1A, 0xFF}}},
{{{    92,   -168,      0}, 0, {   194,    166},  {0x0E, 0x7E, 0x00, 0xFF}}},
{{{   128,     43,    137}, 0, {   288,    480},  {0xF7, 0xA8, 0x5B, 0xFF}}},
{{{   188,     -4,    120}, 0, {   480,    224},  {0x62, 0x4F, 0xF0, 0xFF}}},
{{{   188,    -51,    117}, 0, {   736,    224},  {0x86, 0x0F, 0x20, 0xFF}}},
{{{   232,     -4,    106}, 0, {   480,     32},  {0xA3, 0x06, 0xAA, 0xFF}}},
{{{   201,     29,    132}, 0, {   352,    160},  {0xB9, 0x97, 0x07, 0xFF}}},
{{{   138,     43,    159}, 0, {   288,    416},  {0xD2, 0x8C, 0xE7, 0xFF}}},
{{{    48,     82,    181}, 0, {   160,    928},  {0x0B, 0x82, 0xF0, 0xFF}}},
{{{    41,     49,    147}, 0, {   288,    928},  {0x2B, 0xCD, 0x6C, 0xFF}}},
{{{    33,    -21,    144}, 0, {   672,    928},  {0x59, 0xF1, 0x59, 0xFF}}},
{{{    49,   -112,    109}, 0, {  1056,    800},  {0x3F, 0xFE, 0x6E, 0xFF}}},
{{{   194,   -112,    110}, 0, {   928,    224},  {0xB9, 0x4F, 0x47, 0xFF}}},
{{{   232,    -58,    102}, 0, {   800,     32},  {0x9B, 0x22, 0xBB, 0xFF}}},
{{{   202,    -84,    142}, 0, {   864,    160},  {0xA7, 0x35, 0xB7, 0xFF}}},
{{{   202,    -12,    157}, 0, {   480,    160},  {0xA7, 0xF2, 0xA7, 0xFF}}},
{{{   141,     20,    196}, 0, {   416,    480},  {0xC8, 0xE1, 0x92, 0xFF}}},
{{{    40,     26,    222}, 0, {   352,    800},  {0x1C, 0xFA, 0x84, 0xFF}}},
{{{     9,     60,    180}, 0, {   288,    992},  {0x67, 0xB6, 0xFE, 0xFF}}},
{{{    -2,      8,    179}, 0, {   352,   1056},  {0x7B, 0x20, 0xFC, 0xFF}}},
{{{    45,    -21,    194}, 0, {   672,    800},  {0x37, 0x15, 0x8F, 0xFF}}},
{{{     9,    -61,    173}, 0, {   864,    992},  {0x7D, 0x0A, 0xEB, 0xFF}}},
{{{    49,   -103,    164}, 0, {   992,    736},  {0x46, 0x41, 0xAD, 0xFF}}},
{{{    26,   -138,    129}, 0, {  1184,    864},  {0x78, 0x23, 0x15, 0xFF}}},
{{{    63,   -160,    121}, 0, {  1184,    672},  {0x12, 0x73, 0x33, 0xFF}}},
{{{   133,   -143,    116}, 0, {  1056,    352},  {0xDF, 0x6A, 0x3E, 0xFF}}},
{{{   142,   -126,    159}, 0, {  1056,    352},  {0xD4, 0x48, 0xA1, 0xFF}}},
{{{   132,    -97,    162}, 0, {   928,    416},  {0xE6, 0x34, 0x8F, 0xFF}}},
{{{   140,    -61,    198}, 0, {   864,    416},  {0xD8, 0x18, 0x8A, 0xFF}}},
{{{   128,    -21,    183}, 0, {   672,    416},  {0xE2, 0xFE, 0x85, 0xFF}}},
{{{    48,    -67,    212}, 0, {   864,    800},  {0x23, 0x21, 0x8A, 0xFF}}},
{{{    58,   -142,    165}, 0, {  1120,    736},  {0x20, 0x46, 0x9B, 0xFF}}},
{{{   128,     43,   -137}, 0, {   288,    480},  {0xF7, 0xA8, 0xA5, 0xFF}}},
{{{   188,    -51,   -117}, 0, {   736,    224},  {0x86, 0x0F, 0xE0, 0xFF}}},
{{{   188,     -4,   -120}, 0, {   480,    224},  {0x69, 0x45, 0x12, 0xFF}}},
{{{   194,   -112,   -110}, 0, {   928,    224},  {0xB9, 0x4E, 0xBA, 0xFF}}},
{{{    49,   -112,   -109}, 0, {  1056,    800},  {0x3F, 0xFE, 0x92, 0xFF}}},
{{{    33,    -21,   -144}, 0, {   672,    928},  {0x59, 0xF0, 0xA7, 0xFF}}},
{{{    41,     49,   -147}, 0, {   288,    928},  {0x2B, 0xCD, 0x94, 0xFF}}},
{{{    48,     82,   -181}, 0, {   160,    928},  {0x0B, 0x82, 0x10, 0xFF}}},
{{{   138,     43,   -159}, 0, {   288,    416},  {0xD2, 0x8C, 0x19, 0xFF}}},
{{{   201,     29,   -132}, 0, {   352,    160},  {0xB9, 0x97, 0xF9, 0xFF}}},
{{{   232,     -4,   -106}, 0, {   480,     32},  {0xA3, 0x05, 0x56, 0xFF}}},
{{{   202,    -12,   -157}, 0, {   480,    160},  {0xA8, 0xF2, 0x5A, 0xFF}}},
{{{   232,    -58,   -102}, 0, {   800,     32},  {0x9B, 0x22, 0x45, 0xFF}}},
{{{   202,    -84,   -141}, 0, {   864,    160},  {0xA7, 0x35, 0x4A, 0xFF}}},
{{{   142,   -126,   -158}, 0, {  1056,    352},  {0xD4, 0x49, 0x5F, 0xFF}}},
{{{   132,    -97,   -162}, 0, {   928,    416},  {0xE5, 0x36, 0x70, 0xFF}}},
{{{    58,   -142,   -164}, 0, {  1120,    736},  {0x1F, 0x48, 0x64, 0xFF}}},
{{{    63,   -160,   -120}, 0, {  1184,    672},  {0x12, 0x73, 0xCD, 0xFF}}},
{{{   133,   -143,   -115}, 0, {  1056,    352},  {0xDF, 0x69, 0xC1, 0xFF}}},
{{{    26,   -138,   -129}, 0, {  1184,    864},  {0x79, 0x23, 0xED, 0xFF}}},
{{{    49,   -103,   -164}, 0, {   992,    736},  {0x47, 0x41, 0x54, 0xFF}}},
{{{     9,    -61,   -167}, 0, {   864,    992},  {0x7E, 0x09, 0x0C, 0xFF}}},
{{{    45,    -21,   -194}, 0, {   672,    800},  {0x37, 0x17, 0x70, 0xFF}}},
{{{    -2,      8,   -179}, 0, {   352,   1056},  {0x7B, 0x20, 0x04, 0xFF}}},
{{{     9,     60,   -180}, 0, {   288,    992},  {0x67, 0xB6, 0x02, 0xFF}}},
{{{    40,     26,   -222}, 0, {   352,    800},  {0x1C, 0xFA, 0x7C, 0xFF}}},
{{{   141,     20,   -196}, 0, {   416,    480},  {0xC9, 0xE2, 0x6F, 0xFF}}},
{{{   128,    -21,   -182}, 0, {   672,    416},  {0xE2, 0xFF, 0x7B, 0xFF}}},
{{{   140,    -61,   -197}, 0, {   864,    416},  {0xD8, 0x18, 0x76, 0xFF}}},
{{{    48,    -67,   -212}, 0, {   864,    800},  {0x25, 0x20, 0x75, 0xFF}}},
{{{   294,    -51,     31}, 0, {   219,    238},  {0x18, 0xDD, 0x88, 0xFF}}},
{{{   264,    -84,     37}, 0, {   219,    238},  {0xA3, 0x42, 0xC9, 0xFF}}},
{{{   278,    -95,     10}, 0, {   219,    238},  {0x6A, 0x29, 0xC7, 0xFF}}},
{{{   280,     -4,      0}, 0, {   219,    238},  {0x85, 0xE2, 0x00, 0xFF}}},
{{{   303,    -14,     -2}, 0, {   219,    238},  {0x0C, 0x82, 0xF3, 0xFF}}},
{{{   290,    -59,    -35}, 0, {   219,    238},  {0x4C, 0xCF, 0x59, 0xFF}}},
{{{   264,    -84,    -37}, 0, {   219,    238},  {0xB2, 0x48, 0x47, 0xFF}}},
{{{   281,    -95,    -28}, 0, {   219,    238},  {0x5A, 0x3D, 0x42, 0xFF}}},
{{{   264,    -84,      0}, 0, {   219,    238},  {0xF1, 0x7E, 0x00, 0xFF}}},
{{{   281,    -95,    -28}, 0, {   100,   1860},  {0x5A, 0x3D, 0x42, 0xFF}}},
{{{   265,   -153,     38}, 0, {   892,   1860},  {0x7B, 0x05, 0xE2, 0xFF}}},
{{{   278,    -95,     10}, 0, {   100,   1860},  {0x6A, 0x29, 0xC7, 0xFF}}},
{{{   319,    -95,     35}, 0, {  1184,   1632},  {0x17, 0xD7, 0x8A, 0xFF}}},
{{{   294,    -51,     31}, 0, {   800,   2016},  {0x18, 0xDD, 0x88, 0xFF}}},
{{{   278,    -95,     10}, 0, {  1184,   2016},  {0x6A, 0x29, 0xC7, 0xFF}}},
{{{   354,    -41,     40}, 0, {   608,   1120},  {0xE4, 0xCB, 0x90, 0xFF}}},
{{{   351,   -104,     32}, 0, {  1184,   1120},  {0xB7, 0x0C, 0x99, 0xFF}}},
{{{   419,    -87,      8}, 0, {  1184,    416},  {0x96, 0x0E, 0xBC, 0xFF}}},
{{{   378,   -150,    -24}, 0, {  2016,    928},  {0xDB, 0x75, 0xDE, 0xFF}}},
{{{   329,   -124,    -12}, 0, {  1312,   1504},  {0xF6, 0x76, 0x2E, 0xFF}}},
{{{   334,   -152,    -80}, 0, {  1632,   1632},  {0x22, 0x72, 0x2D, 0xFF}}},
{{{   281,    -95,    -28}, 0, {  1184,   2016},  {0x5A, 0x3D, 0x42, 0xFF}}},
{{{   326,   -101,   -124}, 0, {  1184,   1504},  {0x2A, 0x13, 0x76, 0xFF}}},
{{{   290,    -59,    -35}, 0, {   800,   2016},  {0x4C, 0xCF, 0x59, 0xFF}}},
{{{   344,    -31,   -101}, 0, {   608,   1312},  {0x10, 0xB0, 0x61, 0xFF}}},
{{{   303,    -14,     -2}, 0, {   224,   2016},  {0x0C, 0x82, 0xF3, 0xFF}}},
{{{   367,      2,    -22}, 0, {    96,    928},  {0xDE, 0x86, 0xF3, 0xFF}}},
{{{   420,    -44,    -57}, 0, {   928,    800},  {0x94, 0xC6, 0x23, 0xFF}}},
{{{   412,   -110,    -82}, 0, {  1312,    928},  {0x9F, 0x2D, 0x44, 0xFF}}},
{{{   351,   -104,     32}, 0, {   224,    416},  {0xB7, 0x0C, 0x99, 0xFF}}},
{{{   319,    -95,     35}, 0, {   480,   1120},  {0x17, 0xD7, 0x8A, 0xFF}}},
{{{   347,   -135,     68}, 0, {   800,    800},  {0xAA, 0xE5, 0xA7, 0xFF}}},
{{{   302,   -149,     81}, 0, {  1312,   1632},  {0x23, 0xF3, 0x87, 0xFF}}},
{{{   278,    -95,     10}, 0, {    96,   2016},  {0x6A, 0x29, 0xC7, 0xFF}}},
{{{   265,   -153,     38}, 0, {  1760,   2016},  {0x7B, 0x05, 0xE2, 0xFF}}},
{{{   283,   -190,     50}, 0, {  1760,   1632},  {0x48, 0x5B, 0xCD, 0xFF}}},
{{{   300,   -201,      2}, 0, {  2016,   1632},  {0x12, 0x70, 0x39, 0xFF}}},
{{{   283,   -160,    -22}, 0, {  1312,   1504},  {0x38, 0x2C, 0x69, 0xFF}}},
{{{   281,    -95,    -28}, 0, {    96,   2016},  {0x5A, 0x3D, 0x42, 0xFF}}},
{{{   329,   -124,    -12}, 0, {   800,   1312},  {0xF6, 0x76, 0x2E, 0xFF}}},
{{{   349,   -175,     11}, 0, {  1504,    416},  {0x9A, 0x3B, 0x2F, 0xFF}}},
{{{   349,   -175,     11}, 0, {  1504,    416},  {0x9A, 0x3B, 0x2F, 0xFF}}},
{{{   347,   -135,     68}, 0, {   800,    800},  {0xAA, 0xE5, 0xA7, 0xFF}}},
{{{   331,   -184,     63}, 0, {  1504,   1120},  {0xC7, 0x57, 0xB6, 0xFF}}},
{{{   302,   -149,     81}, 0, {  1312,   1632},  {0x23, 0xF3, 0x87, 0xFF}}},
{{{   283,   -190,     50}, 0, {  1760,   1632},  {0x48, 0x5B, 0xCD, 0xFF}}},
{{{   300,   -201,      2}, 0, {  2016,   1632},  {0x12, 0x70, 0x39, 0xFF}}},
{{{   283,   -160,    -22}, 0, {  1312,   1504},  {0x38, 0x2C, 0x69, 0xFF}}},
{{{   280,   -115,    -20}, 0, {   480,    992},  {0xD4, 0x6D, 0xD0, 0xFF}}},
{{{   289,   -103,    -16}, 0, {   608,    416},  {0xB4, 0x4E, 0xC0, 0xFF}}},
{{{   280,    -96,     -9}, 0, {  -352,    416},  {0xFB, 0x0E, 0x82, 0xFF}}},
{{{   286,   -109,    -38}, 0, {  1632,    992},  {0xAD, 0x44, 0x43, 0xFF}}},
{{{   272,   -113,    -41}, 0, {  1312,   1568},  {0xFF, 0x5D, 0x56, 0xFF}}},
{{{   268,   -117,    -28}, 0, {   608,   1568},  {0x1D, 0x7C, 0xFC, 0xFF}}},
{{{   268,   -104,     -9}, 0, {  -352,    992},  {0x25, 0x26, 0x8D, 0xFF}}},
{{{   261,    -87,    -17}, 0, {   480,    992},  {0x53, 0xBA, 0xBD, 0xFF}}},
{{{   275,    -83,    -14}, 0, {   608,    416},  {0x2A, 0xA9, 0xAD, 0xFF}}},
{{{   267,    -81,    -35}, 0, {  1632,    992},  {0x2B, 0x93, 0x31, 0xFF}}},
{{{   279,    -79,    -27}, 0, {  1312,    416},  {0x03, 0x84, 0x1A, 0xFF}}},
{{{   279,    -92,    -45}, 0, {  2336,    992},  {0xD9, 0xD8, 0x72, 0xFF}}},
{{{   288,    -87,    -34}, 0, {  2336,    416},  {0xB8, 0xC5, 0x56, 0xFF}}},
{{{   293,    -99,    -29}, 0, {  1312,    416},  {0x8F, 0x29, 0x2A, 0xFF}}},
{{{   267,   -100,    -46}, 0, {  1952,   1568},  {0x20, 0x07, 0x7B, 0xFF}}},
{{{   258,   -108,    -36}, 0, {   992,   2016},  {0x62, 0x3E, 0x33, 0xFF}}},
{{{   259,   -109,    -21}, 0, {    96,   1568},  {0x5C, 0x46, 0xCB, 0xFF}}},
{{{   254,    -97,    -26}, 0, {   608,   1568},  {0x7D, 0xF2, 0xEE, 0xFF}}},
{{{   258,    -93,    -39}, 0, {  1312,   1568},  {0x60, 0xD5, 0x47, 0xFF}}},
{{{   264,    -87,    -42}, 0, {  -352,    992},  {0x40, 0x64, 0xD3, 0xFF}}},
{{{   259,    -76,    -62}, 0, {   608,   1568},  {0x62, 0x18, 0x4D, 0xFF}}},
{{{   266,    -88,    -57}, 0, {    96,   1568},  {0x34, 0x6C, 0x2A, 0xFF}}},
{{{   254,    -71,    -49}, 0, {   480,    992},  {0x7F, 0xFF, 0xFF, 0xFF}}},
{{{   267,    -77,    -31}, 0, {  -352,    416},  {0x30, 0x2C, 0x93, 0xFF}}},
{{{   284,    -87,    -42}, 0, {   480,    992},  {0xC0, 0x65, 0xD5, 0xFF}}},
{{{   280,    -88,    -57}, 0, {   608,   1568},  {0xD5, 0x6F, 0x2C, 0xFF}}},
{{{   273,    -79,    -67}, 0, {   992,   2016},  {0x04, 0x32, 0x75, 0xFF}}},
{{{   267,    -65,    -66}, 0, {  1312,   1568},  {0x30, 0xCF, 0x6B, 0xFF}}},
{{{   264,    -55,    -55}, 0, {  1632,    992},  {0x40, 0x9B, 0x2B, 0xFF}}},
{{{   260,    -65,    -36}, 0, {   608,    416},  {0x5F, 0xDC, 0xB4, 0xFF}}},
{{{   274,    -63,    -31}, 0, {   992,    -32},  {0xFE, 0xCB, 0x8D, 0xFF}}},
{{{   281,    -77,    -31}, 0, {   608,    416},  {0xD0, 0x2B, 0x92, 0xFF}}},
{{{   284,    -87,    -42}, 0, {   480,    992},  {0xC0, 0x65, 0xD5, 0xFF}}},
{{{   294,    -72,    -49}, 0, {  1632,    992},  {0x81, 0x04, 0x00, 0xFF}}},
{{{   281,    -77,    -31}, 0, {   608,    416},  {0xD0, 0x2B, 0x92, 0xFF}}},
{{{   288,    -77,    -62}, 0, {  1312,   1568},  {0xA2, 0x24, 0x4D, 0xFF}}},
{{{   280,    -88,    -57}, 0, {   608,   1568},  {0xD5, 0x6F, 0x2C, 0xFF}}},
{{{   273,    -79,    -67}, 0, {   992,   2016},  {0x04, 0x32, 0x75, 0xFF}}},
{{{   281,    -66,    -67}, 0, {  1952,   1568},  {0xD1, 0xD7, 0x6F, 0xFF}}},
{{{   267,    -65,    -66}, 0, {  1312,   1568},  {0x30, 0xCF, 0x6B, 0xFF}}},
{{{   264,    -55,    -55}, 0, {  1632,    992},  {0x40, 0x9B, 0x2B, 0xFF}}},
{{{   284,    -55,    -56}, 0, {  2336,    992},  {0xC1, 0x9B, 0x2C, 0xFF}}},
{{{   267,    -54,    -41}, 0, {  1312,    416},  {0x2D, 0x92, 0xD4, 0xFF}}},
{{{   260,    -65,    -36}, 0, {   608,    416},  {0x5F, 0xDC, 0xB4, 0xFF}}},
{{{   274,    -63,    -31}, 0, {   992,    -32},  {0xFE, 0xCB, 0x8D, 0xFF}}},
{{{   281,    -55,    -41}, 0, {  2336,    416},  {0xCD, 0x95, 0xD2, 0xFF}}},
{{{   288,    -66,    -36}, 0, {  1312,    416},  {0xA0, 0xDE, 0xB4, 0xFF}}},
};

const Gfx isabelle_face_mouth_tris[] = {
	gsSPVertex(_000_displaylist_mesh_vtx + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(1, 3, 4, 0, 5, 6, 7, 0),
	gsSP2Triangles(5, 7, 8, 0, 9, 8, 7, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 13, 11, 0),
	gsSP2Triangles(13, 10, 14, 0, 15, 14, 10, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 19, 16, 0, 20, 21, 19, 0),
	gsSP2Triangles(17, 19, 22, 0, 23, 24, 25, 0),
	gsSP2Triangles(25, 24, 26, 0, 27, 25, 26, 0),
	gsSP2Triangles(28, 25, 27, 0, 28, 29, 30, 0),
	gsSP1Triangle(29, 31, 30, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 7, 3, 5, 0),
	gsSP2Triangles(8, 7, 5, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 10, 9, 0, 13, 12, 9, 0),
	gsSP2Triangles(13, 9, 14, 0, 14, 9, 11, 0),
	gsSP2Triangles(14, 11, 15, 0, 14, 15, 16, 0),
	gsSP2Triangles(15, 17, 16, 0, 16, 17, 18, 0),
	gsSP2Triangles(18, 19, 16, 0, 19, 18, 20, 0),
	gsSP2Triangles(21, 20, 18, 0, 22, 20, 21, 0),
	gsSP2Triangles(23, 20, 22, 0, 24, 23, 22, 0),
	gsSP2Triangles(25, 23, 24, 0, 25, 24, 26, 0),
	gsSP2Triangles(25, 26, 27, 0, 27, 26, 28, 0),
	gsSP2Triangles(29, 27, 28, 0, 29, 30, 27, 0),
	gsSP2Triangles(30, 29, 12, 0, 12, 29, 31, 0),
	gsSP2Triangles(12, 31, 10, 0, 13, 30, 12, 0),
	gsSP2Triangles(30, 13, 27, 0, 13, 25, 27, 0),
	gsSP1Triangle(13, 23, 25, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 64, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eye_tris[] = {
	gsSPVertex(_000_displaylist_mesh_vtx + 68, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 6, 9, 0, 11, 10, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
	gsSP2Triangles(12, 14, 13, 0, 13, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 19, 16, 18, 0),
	gsSP2Triangles(20, 19, 18, 0, 21, 16, 19, 0),
	gsSP2Triangles(22, 23, 24, 0, 25, 23, 22, 0),
	gsSP2Triangles(26, 25, 22, 0, 26, 27, 25, 0),
	gsSP2Triangles(26, 28, 27, 0, 29, 28, 26, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 100, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 2, 3, 0, 5, 4, 3, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(6, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(12, 10, 11, 0, 12, 11, 13, 0),
	gsSP2Triangles(14, 12, 13, 0, 15, 12, 14, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 19, 16, 0, 20, 16, 21, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(22, 24, 23, 0, 24, 25, 23, 0),
	gsSP2Triangles(25, 24, 26, 0, 26, 24, 27, 0),
	gsSP2Triangles(26, 27, 28, 0, 29, 28, 27, 0),
	gsSP2Triangles(30, 28, 29, 0, 31, 28, 30, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 132, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(0, 2, 4, 0, 0, 4, 5, 0),
	gsSP2Triangles(6, 0, 5, 0, 6, 7, 0, 0),
	gsSP2Triangles(6, 8, 7, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(11, 10, 12, 0, 10, 13, 12, 0),
	gsSP2Triangles(13, 14, 12, 0, 13, 15, 14, 0),
	gsSP2Triangles(14, 15, 16, 0, 17, 16, 15, 0),
	gsSP2Triangles(17, 18, 16, 0, 19, 16, 18, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(24, 23, 20, 0, 21, 23, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 29, 27, 0),
	gsSP2Triangles(26, 30, 29, 0, 31, 29, 30, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 164, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(4, 3, 2, 0, 5, 4, 2, 0),
	gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
	gsSP2Triangles(10, 9, 7, 0, 11, 9, 10, 0),
	gsSP2Triangles(12, 9, 11, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 11, 14, 0, 11, 15, 14, 0),
	gsSP2Triangles(15, 11, 4, 0, 16, 15, 4, 0),
	gsSP2Triangles(15, 16, 14, 0, 13, 14, 17, 0),
	gsSP2Triangles(13, 17, 18, 0, 19, 18, 17, 0),
	gsSP2Triangles(20, 18, 19, 0, 20, 19, 21, 0),
	gsSP2Triangles(20, 21, 22, 0, 21, 23, 22, 0),
	gsSP2Triangles(24, 22, 23, 0, 24, 23, 25, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 24, 27, 0, 29, 28, 27, 0),
	gsSP2Triangles(30, 28, 29, 0, 30, 31, 28, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 196, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 0, 4, 5, 0),
	gsSP2Triangles(6, 0, 5, 0, 6, 7, 0, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 6, 9, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(10, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(13, 14, 11, 0, 11, 14, 15, 0),
	gsSP2Triangles(14, 16, 15, 0, 15, 16, 17, 0),
	gsSP2Triangles(16, 18, 17, 0, 17, 18, 19, 0),
	gsSP2Triangles(20, 17, 19, 0, 20, 19, 21, 0),
	gsSP2Triangles(21, 19, 22, 0, 21, 22, 23, 0),
	gsSP2Triangles(23, 24, 21, 0, 24, 23, 25, 0),
	gsSP2Triangles(25, 23, 26, 0, 25, 26, 27, 0),
	gsSP2Triangles(25, 27, 28, 0, 28, 27, 29, 0),
	gsSP2Triangles(28, 29, 30, 0, 30, 29, 31, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 228, 27, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(0, 3, 4, 0, 5, 0, 4, 0),
	gsSP2Triangles(6, 5, 4, 0, 7, 5, 6, 0),
	gsSP2Triangles(8, 7, 6, 0, 9, 8, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 7, 8, 10, 0),
	gsSP2Triangles(11, 7, 10, 0, 12, 11, 10, 0),
	gsSP2Triangles(12, 13, 11, 0, 12, 14, 13, 0),
	gsSP2Triangles(13, 14, 15, 0, 13, 15, 16, 0),
	gsSP2Triangles(16, 15, 17, 0, 16, 17, 18, 0),
	gsSP2Triangles(19, 16, 18, 0, 19, 18, 20, 0),
	gsSP2Triangles(20, 18, 21, 0, 22, 20, 21, 0),
	gsSP2Triangles(20, 22, 23, 0, 20, 23, 24, 0),
	gsSP2Triangles(20, 24, 25, 0, 25, 24, 1, 0),
	gsSP2Triangles(5, 25, 1, 0, 5, 1, 0, 0),
	gsSP2Triangles(7, 25, 5, 0, 7, 26, 25, 0),
	gsSP2Triangles(26, 7, 19, 0, 11, 19, 7, 0),
	gsSP2Triangles(11, 16, 19, 0, 11, 13, 16, 0),
	gsSP2Triangles(20, 26, 19, 0, 26, 20, 25, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_ears_tris[] = {
	gsSPVertex(_000_displaylist_mesh_vtx + 255, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 10, 9, 0, 0, 2, 10, 0),
	gsSP2Triangles(10, 2, 11, 0, 10, 11, 12, 0),
	gsSP2Triangles(11, 13, 12, 0, 3, 13, 11, 0),
	gsSP2Triangles(3, 4, 13, 0, 4, 14, 13, 0),
	gsSP2Triangles(5, 14, 4, 0, 6, 14, 5, 0),
	gsSP2Triangles(6, 15, 14, 0, 6, 16, 15, 0),
	gsSP2Triangles(6, 7, 16, 0, 17, 16, 7, 0),
	gsSP2Triangles(8, 17, 7, 0, 8, 18, 17, 0),
	gsSP2Triangles(8, 19, 18, 0, 8, 9, 19, 0),
	gsSP2Triangles(19, 9, 20, 0, 21, 20, 9, 0),
	gsSP2Triangles(22, 21, 9, 0, 23, 22, 9, 0),
	gsSP2Triangles(10, 23, 9, 0, 10, 24, 23, 0),
	gsSP2Triangles(10, 12, 24, 0, 12, 25, 24, 0),
	gsSP2Triangles(12, 26, 25, 0, 12, 13, 26, 0),
	gsSP2Triangles(26, 13, 27, 0, 14, 27, 13, 0),
	gsSP2Triangles(15, 27, 14, 0, 15, 18, 27, 0),
	gsSP2Triangles(17, 18, 15, 0, 17, 15, 16, 0),
	gsSP2Triangles(18, 28, 27, 0, 19, 28, 18, 0),
	gsSP2Triangles(19, 20, 28, 0, 28, 20, 25, 0),
	gsSP2Triangles(29, 25, 20, 0, 29, 20, 21, 0),
	gsSP2Triangles(22, 29, 21, 0, 22, 24, 29, 0),
	gsSP2Triangles(23, 24, 22, 0, 29, 24, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 28, 25, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 285, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(0, 6, 5, 0, 0, 7, 6, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 10, 9, 0, 0, 2, 10, 0),
	gsSP2Triangles(10, 11, 9, 0, 10, 12, 11, 0),
	gsSP2Triangles(12, 13, 11, 0, 12, 3, 13, 0),
	gsSP2Triangles(1, 3, 12, 0, 14, 13, 3, 0),
	gsSP2Triangles(14, 15, 13, 0, 16, 15, 14, 0),
	gsSP2Triangles(16, 14, 17, 0, 18, 17, 14, 0),
	gsSP2Triangles(18, 14, 3, 0, 4, 18, 3, 0),
	gsSP2Triangles(4, 17, 18, 0, 4, 19, 17, 0),
	gsSP2Triangles(4, 20, 19, 0, 4, 21, 20, 0),
	gsSP2Triangles(4, 5, 21, 0, 5, 22, 21, 0),
	gsSP2Triangles(5, 23, 22, 0, 6, 23, 5, 0),
	gsSP2Triangles(6, 24, 23, 0, 6, 7, 24, 0),
	gsSP2Triangles(24, 7, 25, 0, 7, 26, 25, 0),
	gsSP2Triangles(8, 26, 7, 0, 8, 9, 26, 0),
	gsSP2Triangles(9, 11, 26, 0, 26, 11, 27, 0),
	gsSP2Triangles(28, 27, 11, 0, 28, 11, 13, 0),
	gsSP2Triangles(15, 28, 13, 0, 15, 29, 28, 0),
	gsSP2Triangles(20, 29, 15, 0, 20, 15, 16, 0),
	gsSP2Triangles(20, 16, 19, 0, 16, 17, 19, 0),
	gsSP2Triangles(20, 21, 29, 0, 21, 22, 29, 0),
	gsSP2Triangles(22, 27, 29, 0, 22, 25, 27, 0),
	gsSP2Triangles(23, 25, 22, 0, 24, 25, 23, 0),
	gsSP2Triangles(26, 27, 25, 0, 28, 29, 27, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_shz_extra_colors_hair_clip_tris[] = {
	gsSPVertex(_000_displaylist_mesh_vtx + 315, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 0, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 3, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(6, 7, 2, 0, 2, 8, 6, 0),
	gsSP1Triangle(8, 2, 1, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_hair_tail_tris[] = {
	gsSPVertex(_000_displaylist_mesh_vtx + 324, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 4, 3, 0, 6, 3, 7, 0),
	gsSP2Triangles(6, 7, 8, 0, 7, 9, 8, 0),
	gsSP2Triangles(7, 10, 9, 0, 10, 11, 9, 0),
	gsSP2Triangles(10, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 13, 14, 15, 0),
	gsSP2Triangles(16, 15, 14, 0, 17, 15, 16, 0),
	gsSP2Triangles(6, 17, 16, 0, 6, 16, 4, 0),
	gsSP2Triangles(6, 8, 17, 0, 17, 8, 18, 0),
	gsSP2Triangles(8, 19, 18, 0, 8, 9, 19, 0),
	gsSP2Triangles(9, 11, 19, 0, 13, 19, 11, 0),
	gsSP2Triangles(13, 15, 19, 0, 18, 19, 15, 0),
	gsSP2Triangles(17, 18, 15, 0, 20, 21, 22, 0),
	gsSP2Triangles(22, 21, 23, 0, 24, 23, 21, 0),
	gsSP2Triangles(24, 25, 23, 0, 26, 23, 25, 0),
	gsSP2Triangles(27, 26, 25, 0, 27, 25, 28, 0),
	gsSP2Triangles(28, 25, 29, 0, 30, 28, 29, 0),
	gsSP2Triangles(31, 28, 30, 0, 31, 30, 20, 0),
	gsSP1Triangle(31, 20, 22, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 356, 7, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 2, 4, 0),
	gsSP2Triangles(0, 2, 5, 0, 0, 5, 6, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_hair_clip_bells_tris[] = {
	gsSPVertex(_000_displaylist_mesh_vtx + 363, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
	gsSP2Triangles(6, 5, 0, 0, 6, 0, 2, 0),
	gsSP2Triangles(6, 2, 7, 0, 7, 2, 8, 0),
	gsSP2Triangles(7, 8, 9, 0, 8, 10, 9, 0),
	gsSP2Triangles(11, 9, 10, 0, 11, 10, 12, 0),
	gsSP2Triangles(13, 11, 12, 0, 13, 3, 11, 0),
	gsSP2Triangles(1, 3, 13, 0, 11, 3, 14, 0),
	gsSP2Triangles(4, 14, 3, 0, 4, 15, 14, 0),
	gsSP2Triangles(5, 15, 4, 0, 16, 15, 5, 0),
	gsSP2Triangles(6, 16, 5, 0, 6, 17, 16, 0),
	gsSP2Triangles(6, 7, 17, 0, 7, 18, 17, 0),
	gsSP2Triangles(7, 9, 18, 0, 18, 9, 14, 0),
	gsSP2Triangles(11, 14, 9, 0, 18, 14, 15, 0),
	gsSP2Triangles(17, 18, 15, 0, 16, 17, 15, 0),
	gsSP2Triangles(19, 20, 21, 0, 19, 22, 20, 0),
	gsSP2Triangles(19, 23, 22, 0, 19, 24, 23, 0),
	gsSP2Triangles(19, 25, 24, 0, 19, 21, 25, 0),
	gsSP2Triangles(21, 26, 25, 0, 21, 20, 26, 0),
	gsSP2Triangles(20, 27, 26, 0, 22, 27, 20, 0),
	gsSP2Triangles(22, 28, 27, 0, 22, 29, 28, 0),
	gsSP2Triangles(22, 23, 29, 0, 23, 30, 29, 0),
	gsSP2Triangles(31, 30, 23, 0, 24, 31, 23, 0),
	gsSPVertex(_000_displaylist_mesh_vtx + 395, 15, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(3, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 9, 8, 0, 11, 10, 8, 0),
	gsSP2Triangles(11, 12, 10, 0, 10, 12, 13, 0),
	gsSP2Triangles(14, 13, 12, 0, 2, 14, 12, 0),
	gsSP2Triangles(2, 1, 14, 0, 14, 1, 9, 0),
	gsSP2Triangles(6, 9, 1, 0, 3, 6, 1, 0),
	gsSP2Triangles(14, 9, 13, 0, 10, 13, 9, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_face_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_face_mouth_tris),
	gsSPDisplayList(isabelle_face_eye_tris),
	gsSPDisplayList(isabelle_face_ears_tris),
	gsSPDisplayList(isabelle_shz_extra_colors_hair_clip_tris),
	gsSPDisplayList(isabelle_hair_tail_tris),
	gsSPDisplayList(isabelle_hair_clip_bells_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_ears),
	gsSPDisplayList(isabelle_face_ears_tris),
	gsSPDisplayList(isabelle_tex_hair_tail),
	gsSPDisplayList(isabelle_hair_tail_tris),
	gsSPDisplayList(isabelle_tex_hair_tail_bells),
	gsSPDisplayList(isabelle_hair_clip_bells_tris),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPDisplayList(isabelle_tex_extras),
	gsSPDisplayList(isabelle_shz_extra_colors_hair_clip_tris),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_open_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_halfclosed_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_halfclosed),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_closed_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_closed),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_angry_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_angry),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_sad_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_sad),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_happy_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_happy),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_surprised_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_surprised),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_worried_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_worried),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_verysurprised_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_verysurprised),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_eyes_dizzy_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_dizzy),
	gsSPDisplayList(isabelle_face_eye_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_mouth_closed_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_mouth_closed),
	gsSPDisplayList(isabelle_face_mouth_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_mouth_smile_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_mouth_smile),
	gsSPDisplayList(isabelle_face_mouth_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_mouth_bigsmile_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_mouth_bigsmile),
	gsSPDisplayList(isabelle_face_mouth_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_mouth_sad_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_mouth_sad),
	gsSPDisplayList(isabelle_face_mouth_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_mouth_open_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_mouth_open),
	gsSPDisplayList(isabelle_face_mouth_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_face_mouth_veryopen_dl[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_mouth_veryopen),
	gsSPDisplayList(isabelle_face_mouth_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Vtx mario_wings_half_1_dl_vertex[] = {
    {{{  -105,    212,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -105,      0,      0}, 0, {     0,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{     0,      0,      0}, 0, {   990,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{     0,    212,      0}, 0, {   990,      0}, {0x00, 0x00, 0x7f, 0xff}}},
};

const Vtx mario_wings_half_2_dl_vertex[] = {
    {{{     0,      0,      0}, 0, {     0,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{   106,    212,      0}, 0, {   990,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{     0,    212,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{   106,      0,      0}, 0, {   990,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
};

const Gfx mario_wings_half_1_dl[] = {
    gsSPVertex(mario_wings_half_1_dl_vertex, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPEndDisplayList(),
};

const Gfx mario_wings_half_2_dl[] = {
    gsSPVertex(mario_wings_half_2_dl_vertex, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSPEndDisplayList(),
};

const Gfx isabelle_wings[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPSetLights1(isabelle_tex_wings_lights),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x7FF, 0x100),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x7FF, 0x100),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

const Gfx isabelle_wings_transparent[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALFADEA, G_CC_DECALFADEA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPSetLights1(isabelle_tex_wings_lights),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x7FF, 0x100),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 0x7FF, 0x100),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

const Gfx isabelle_metal_wings[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPSetLights1(isabelle_tex_wings_lights),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_metal_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_metal_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

const Gfx isabelle_metal_wings_transparent[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_DECALFADEA, G_CC_DECALFADEA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPSetLights1(isabelle_tex_wings_lights),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_metal_wings_half_1),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_1_dl),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, isabelle_texture_metal_wings_half_2),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(mario_wings_half_2_dl),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN | G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(isabelle_texture_metal, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x0F80, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

const Vtx _000_offset_003_mesh_vtx[] = {
{{{   -22,    -17,     18}, 0, {   868,    -36},  {0x70, 0x28, 0xD2, 0xFF}}},
{{{    -4,    -37,      3}, 0, {   868,    -36},  {0x16, 0x7D, 0xFC, 0xFF}}},
{{{    -8,    -23,     26}, 0, {   868,    -36},  {0x22, 0x49, 0x9E, 0xFF}}},
{{{   -19,    -27,      0}, 0, {   868,    -36},  {0x67, 0x47, 0x19, 0xFF}}},
{{{   -22,     -1,     21}, 0, {   868,    -36},  {0x6F, 0x00, 0xC2, 0xFF}}},
{{{    -8,     -1,     30}, 0, {   868,    -36},  {0x1C, 0xFC, 0x84, 0xFF}}},
{{{    12,    -19,     27}, 0, {   868,    -36},  {0xFA, 0x41, 0x93, 0xFF}}},
{{{    19,    -31,      2}, 0, {   868,    -36},  {0xEF, 0x7D, 0xF6, 0xFF}}},
{{{     6,    -24,    -27}, 0, {   868,    -36},  {0x19, 0x52, 0x5D, 0xFF}}},
{{{   -11,    -17,    -20}, 0, {   868,    -36},  {0x5B, 0x27, 0x4F, 0xFF}}},
{{{    -9,      0,    -23}, 0, {   868,    -36},  {0x5A, 0x00, 0x59, 0xFF}}},
{{{   -21,     27,      2}, 0, {   868,    -36},  {0x6B, 0xBD, 0x0D, 0xFF}}},
{{{   -22,     12,     18}, 0, {   868,    -36},  {0x6E, 0xDF, 0xCA, 0xFF}}},
{{{    -8,     17,     26}, 0, {   868,    -36},  {0x1E, 0xC3, 0x95, 0xFF}}},
{{{    12,     15,     25}, 0, {   868,    -36},  {0x00, 0xC8, 0x8E, 0xFF}}},
{{{    41,     14,     30}, 0, {   868,    -36},  {0xAE, 0xD8, 0xA7, 0xFF}}},
{{{    41,    -17,     31}, 0, {   868,    -36},  {0xB1, 0x30, 0xA9, 0xFF}}},
{{{    41,    -30,      3}, 0, {   868,    -36},  {0xA5, 0x58, 0xF8, 0xFF}}},
{{{    41,    -21,    -29}, 0, {   868,    -36},  {0xAB, 0x3B, 0x4A, 0xFF}}},
{{{     9,     -1,    -33}, 0, {   868,    -36},  {0x1B, 0x02, 0x7C, 0xFF}}},
{{{   -11,     16,    -20}, 0, {   868,    -36},  {0x59, 0xDB, 0x52, 0xFF}}},
{{{    -7,     38,      5}, 0, {   868,    -36},  {0x23, 0x87, 0xEE, 0xFF}}},
{{{    13,     36,      3}, 0, {   868,    -36},  {0xF8, 0x83, 0xEB, 0xFF}}},
{{{    41,     34,      3}, 0, {   868,    -36},  {0xA7, 0xA7, 0xF1, 0xFF}}},
{{{    34,      1,      0}, 0, {   868,    -36},  {0x81, 0x00, 0x00, 0xFF}}},
{{{    41,     23,    -30}, 0, {   868,    -36},  {0xAE, 0xC7, 0x4E, 0xFF}}},
{{{     7,     24,    -27}, 0, {   868,    -36},  {0x1E, 0xB2, 0x5F, 0xFF}}},
{{{    68,     21,    -24}, 0, {   178,   2106},  {0xFA, 0xBC, 0x6B, 0xFF}}},
{{{    31,     20,    -24}, 0, {   178,   2082},  {0x02, 0xBC, 0x6B, 0xFF}}},
{{{    31,     30,      2}, 0, {   210,   2082},  {0x08, 0x83, 0xED, 0xFF}}},
{{{    67,     33,      2}, 0, {   210,   2108},  {0xF7, 0x83, 0xEE, 0xFF}}},
{{{    31,     12,     24}, 0, {   240,   2082},  {0x03, 0xCA, 0x8D, 0xFF}}},
{{{    65,     13,     24}, 0, {   240,   2108},  {0xFC, 0xCA, 0x8D, 0xFF}}},
{{{    31,    -15,     25}, 0, {   272,   2082},  {0x01, 0x41, 0x93, 0xFF}}},
{{{    64,    -16,     24}, 0, {   272,   2110},  {0x06, 0x3F, 0x92, 0xFF}}},
{{{    64,    -27,      2}, 0, {   302,   2112},  {0x06, 0x7F, 0xFD, 0xFF}}},
{{{    31,    -26,      2}, 0, {   302,   2082},  {0x04, 0x7F, 0xF8, 0xFF}}},
{{{    31,    -18,    -22}, 0, {   332,   2082},  {0x00, 0x4C, 0x66, 0xFF}}},
{{{    65,    -18,    -21}, 0, {   334,   2112},  {0xFD, 0x4B, 0x67, 0xFF}}},
{{{    68,     21,    -24}, 0, {   368,   2106},  {0xFA, 0xBC, 0x6B, 0xFF}}},
{{{    31,     20,    -24}, 0, {   370,   2082},  {0x02, 0xBC, 0x6B, 0xFF}}},
{{{    88,     28,      2}, 0, {   210,   2114},  {0xF6, 0x83, 0xEA, 0xFF}}},
};

const Gfx isabelle_outfit_left_arm_tris[] = {
	gsSPVertex(_000_offset_003_mesh_vtx + 0, 27, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(4, 3, 0, 0, 0, 5, 4, 0),
	gsSP2Triangles(2, 5, 0, 0, 6, 5, 2, 0),
	gsSP2Triangles(6, 2, 1, 0, 6, 1, 7, 0),
	gsSP2Triangles(7, 1, 8, 0, 9, 8, 1, 0),
	gsSP2Triangles(3, 9, 1, 0, 3, 10, 9, 0),
	gsSP2Triangles(10, 3, 11, 0, 3, 4, 11, 0),
	gsSP2Triangles(4, 12, 11, 0, 4, 5, 12, 0),
	gsSP2Triangles(5, 13, 12, 0, 5, 14, 13, 0),
	gsSP2Triangles(6, 14, 5, 0, 6, 15, 14, 0),
	gsSP2Triangles(6, 16, 15, 0, 6, 7, 16, 0),
	gsSP2Triangles(7, 17, 16, 0, 18, 17, 7, 0),
	gsSP2Triangles(18, 7, 8, 0, 18, 8, 19, 0),
	gsSP2Triangles(9, 19, 8, 0, 19, 9, 10, 0),
	gsSP2Triangles(19, 10, 20, 0, 20, 10, 11, 0),
	gsSP2Triangles(21, 20, 11, 0, 12, 21, 11, 0),
	gsSP2Triangles(21, 12, 13, 0, 13, 14, 21, 0),
	gsSP2Triangles(21, 14, 22, 0, 15, 22, 14, 0),
	gsSP2Triangles(15, 23, 22, 0, 24, 23, 15, 0),
	gsSP2Triangles(24, 15, 16, 0, 24, 16, 17, 0),
	gsSP2Triangles(24, 17, 18, 0, 24, 18, 25, 0),
	gsSP2Triangles(18, 19, 25, 0, 19, 26, 25, 0),
	gsSP2Triangles(19, 20, 26, 0, 20, 21, 26, 0),
	gsSP2Triangles(26, 21, 22, 0, 26, 22, 25, 0),
	gsSP2Triangles(25, 22, 23, 0, 24, 25, 23, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_color_left_arm_tris[] = {
	gsSPVertex(_000_offset_003_mesh_vtx + 27, 15, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(7, 6, 8, 0, 6, 9, 8, 0),
	gsSP2Triangles(9, 10, 8, 0, 8, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 10, 13, 12, 0),
	gsSP2Triangles(5, 14, 3, 0, 14, 12, 3, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_left_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_outfit_left_arm_tris),
	gsSPDisplayList(isabelle_color_left_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_left_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_outfit_front),
	gsSPDisplayList(isabelle_outfit_left_arm_tris),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_left_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_004_mesh_vtx[] = {
{{{    25,     20,    -23}, 0, {   178,   2110},  {0xFA, 0xBB, 0x6A, 0xFF}}},
{{{    75,     29,      1}, 0, {   208,   2144},  {0xD7, 0x88, 0xF6, 0xFF}}},
{{{    22,     11,     24}, 0, {   240,   2112},  {0xFA, 0xCA, 0x8D, 0xFF}}},
{{{    21,    -21,     24}, 0, {   272,   2110},  {0xFC, 0x4C, 0x9A, 0xFF}}},
{{{    21,    -28,      3}, 0, {   302,   2112},  {0xFA, 0x7F, 0x01, 0xFF}}},
{{{    22,    -19,    -20}, 0, {   334,   2112},  {0xF9, 0x4F, 0x64, 0xFF}}},
{{{    25,     20,    -23}, 0, {   368,   2110},  {0xFA, 0xBB, 0x6A, 0xFF}}},
{{{    88,     18,      1}, 0, {   220,   2156},  {0x8F, 0xC6, 0xFB, 0xFF}}},
{{{    88,     -9,      1}, 0, {   260,   2152},  {0x8F, 0x3A, 0xFD, 0xFF}}},
{{{    83,      5,    -16}, 0, {   178,   2152},  {0x9D, 0x00, 0x4F, 0xFF}}},
{{{    75,     18,    -20}, 0, {   178,   2144},  {0xD1, 0xC2, 0x64, 0xFF}}},
{{{    75,     29,      1}, 0, {   208,   2144},  {0xD7, 0x88, 0xF6, 0xFF}}},
{{{    25,     20,    -23}, 0, {   178,   2110},  {0xFA, 0xBB, 0x6A, 0xFF}}},
{{{    75,     16,     19}, 0, {   236,   2144},  {0xD7, 0xC5, 0x97, 0xFF}}},
{{{    84,      5,     15}, 0, {   260,   2152},  {0xA0, 0xFE, 0xAD, 0xFF}}},
{{{    75,     -8,     19}, 0, {   268,   2144},  {0xCD, 0x36, 0x99, 0xFF}}},
{{{    22,     11,     24}, 0, {   240,   2112},  {0xFA, 0xCA, 0x8D, 0xFF}}},
{{{    21,    -21,     24}, 0, {   272,   2110},  {0xFC, 0x4C, 0x9A, 0xFF}}},
{{{    75,    -20,      1}, 0, {   304,   2144},  {0xCC, 0x74, 0xFE, 0xFF}}},
{{{    21,    -28,      3}, 0, {   302,   2112},  {0xFA, 0x7F, 0x01, 0xFF}}},
{{{    22,    -19,    -20}, 0, {   334,   2112},  {0xF9, 0x4F, 0x64, 0xFF}}},
{{{    75,     -8,    -20}, 0, {   340,   2144},  {0xCF, 0x39, 0x66, 0xFF}}},
{{{    25,     20,    -23}, 0, {   368,   2110},  {0xFA, 0xBB, 0x6A, 0xFF}}},
{{{    75,     18,    -20}, 0, {   368,   2144},  {0xD1, 0xC2, 0x64, 0xFF}}},
{{{    83,      5,    -16}, 0, {   368,   2152},  {0x9D, 0x00, 0x4F, 0xFF}}},
{{{    88,     -9,      1}, 0, {   316,   2156},  {0x8F, 0x3A, 0xFD, 0xFF}}},

};

const Gfx isabelle_color_left_forearm_tris1[] = {
	gsSPVertex(_000_offset_004_mesh_vtx + 0, 7, 6),
	gsSP2Triangles(2, 6, 3, 0, 2, 7, 6, 0),
	gsSP2Triangles(8, 7, 2, 0, 5, 8, 2, 0),
	gsSP2Triangles(1, 8, 5, 0, 1, 9, 8, 0),
	gsSP2Triangles(0, 9, 1, 0, 0, 10, 9, 0),
	gsSP2Triangles(11, 10, 0, 0, 11, 0, 4, 0),
	gsSP2Triangles(3, 11, 4, 0, 3, 12, 11, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_color_left_forearm_tris2[] = {
	gsSPVertex(_000_offset_004_mesh_vtx + 7, 19, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(6, 0, 4, 0, 6, 7, 0, 0),
	gsSP2Triangles(6, 8, 7, 0, 9, 8, 6, 0),
	gsSP2Triangles(9, 6, 4, 0, 9, 10, 8, 0),
	gsSP2Triangles(10, 11, 8, 0, 10, 12, 11, 0),
	gsSP2Triangles(11, 12, 13, 0, 11, 13, 14, 0),
	gsSP2Triangles(14, 13, 15, 0, 14, 15, 16, 0),
	gsSP2Triangles(14, 16, 17, 0, 14, 17, 18, 0),
	gsSP2Triangles(11, 14, 18, 0, 11, 18, 8, 0),
	gsSP2Triangles(7, 8, 18, 0, 7, 18, 0, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_left_forearm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_left_forearm_tris1),
	gsSPDisplayList(isabelle_color_left_forearm_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};


const Gfx isabelle_left_forearm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_left_forearm_tris1),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_left_forearm_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};


const Vtx _000_offset_004_skinned_vtx[] = {
{{{    64,    -27,      2}, 0, {   302,   2112},  {0x06, 0x7F, 0xFD, 0xFF}}},
{{{    64,    -16,     24}, 0, {   272,   2110},  {0x06, 0x3F, 0x92, 0xFF}}},
{{{    88,     28,      2}, 0, {   210,   2114},  {0xF6, 0x83, 0xEA, 0xFF}}},
{{{    68,     21,    -24}, 0, {   368,   2106},  {0xFA, 0xBC, 0x6B, 0xFF}}},
{{{    65,    -18,    -21}, 0, {   334,   2112},  {0xFD, 0x4B, 0x67, 0xFF}}},
{{{    65,     13,     24}, 0, {   240,   2108},  {0xFC, 0xCA, 0x8D, 0xFF}}},
};

const Gfx isabelle_color_skinned_left_arm_tris[] = {
	gsSPVertex(_000_offset_004_skinned_vtx + 0, 6, 0),
	gsSPEndDisplayList(),
};


const Gfx isabelle_metal_skinned_left_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_skinned_left_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

const Gfx isabelle_skinned_left_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_skinned_left_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_006_mesh_vtx[] = {
{{{   -12,    -17,     21}, 0, {   868,    -36},  {0x5C, 0x27, 0xB2, 0xFF}}},
{{{     5,    -24,     28}, 0, {   868,    -36},  {0x19, 0x52, 0xA3, 0xFF}}},
{{{     8,     -1,     34}, 0, {   868,    -36},  {0x1B, 0x02, 0x84, 0xFF}}},
{{{    -5,    -37,     -2}, 0, {   868,    -36},  {0x17, 0x7D, 0x04, 0xFF}}},
{{{   -20,    -27,      0}, 0, {   868,    -36},  {0x67, 0x47, 0xEB, 0xFF}}},
{{{   -10,      0,     24}, 0, {   868,    -36},  {0x5A, 0x00, 0xA7, 0xFF}}},
{{{   -12,     16,     21}, 0, {   868,    -36},  {0x59, 0xDB, 0xAE, 0xFF}}},
{{{     6,     24,     28}, 0, {   868,    -36},  {0x1E, 0xB2, 0xA1, 0xFF}}},
{{{    40,     23,     31}, 0, {   868,    -36},  {0xAE, 0xC7, 0xB2, 0xFF}}},
{{{    40,    -21,     30}, 0, {   868,    -36},  {0xAC, 0x3B, 0xB5, 0xFF}}},
{{{    19,    -31,     -1}, 0, {   868,    -36},  {0xF0, 0x7E, 0x0A, 0xFF}}},
{{{    11,    -19,    -26}, 0, {   868,    -36},  {0xFA, 0x41, 0x6D, 0xFF}}},
{{{    -9,    -23,    -25}, 0, {   868,    -36},  {0x22, 0x49, 0x62, 0xFF}}},
{{{   -23,    -17,    -17}, 0, {   868,    -36},  {0x70, 0x28, 0x2E, 0xFF}}},
{{{   -23,     -1,    -20}, 0, {   868,    -36},  {0x6F, 0x00, 0x3E, 0xFF}}},
{{{   -22,     27,     -1}, 0, {   868,    -36},  {0x6B, 0xBD, 0xF3, 0xFF}}},
{{{    -8,     38,     -4}, 0, {   868,    -36},  {0x23, 0x87, 0x12, 0xFF}}},
{{{    12,     36,     -2}, 0, {   868,    -36},  {0xF8, 0x83, 0x15, 0xFF}}},
{{{    40,     34,     -2}, 0, {   868,    -36},  {0xA7, 0xA7, 0x0F, 0xFF}}},
{{{    33,      1,      1}, 0, {   868,    -36},  {0x81, 0x00, 0x00, 0xFF}}},
{{{    40,    -30,     -2}, 0, {   868,    -36},  {0xA5, 0x58, 0x08, 0xFF}}},
{{{    40,    -17,    -30}, 0, {   868,    -36},  {0xB1, 0x30, 0x57, 0xFF}}},
{{{    40,     14,    -29}, 0, {   868,    -36},  {0xAE, 0xD8, 0x59, 0xFF}}},
{{{    11,     15,    -24}, 0, {   868,    -36},  {0x00, 0xC8, 0x72, 0xFF}}},
{{{    -9,     -1,    -29}, 0, {   868,    -36},  {0x1C, 0xFC, 0x7C, 0xFF}}},
{{{   -23,     12,    -17}, 0, {   868,    -36},  {0x6E, 0xDF, 0x36, 0xFF}}},
{{{    -9,     17,    -25}, 0, {   868,    -36},  {0x1E, 0xC3, 0x6B, 0xFF}}},
{{{    30,    -18,     23}, 0, {   332,   2082},  {0xFD, 0x4C, 0x9B, 0xFF}}},
{{{    64,     21,     25}, 0, {   368,   2106},  {0xFA, 0xBE, 0x94, 0xFF}}},
{{{    30,     20,     25}, 0, {   370,   2082},  {0x02, 0xBD, 0x94, 0xFF}}},
{{{    61,    -18,     22}, 0, {   334,   2112},  {0xFB, 0x4A, 0x99, 0xFF}}},
{{{    61,    -27,     -1}, 0, {   302,   2112},  {0x04, 0x7F, 0x05, 0xFF}}},
{{{    30,    -26,     -1}, 0, {   302,   2082},  {0x02, 0x7F, 0x08, 0xFF}}},
{{{    30,    -15,    -24}, 0, {   272,   2082},  {0x01, 0x41, 0x6D, 0xFF}}},
{{{    59,    -16,    -23}, 0, {   272,   2110},  {0x05, 0x43, 0x6C, 0xFF}}},
{{{    61,     13,    -23}, 0, {   240,   2108},  {0x03, 0xCA, 0x73, 0xFF}}},
{{{    30,     12,    -23}, 0, {   240,   2082},  {0x06, 0xCA, 0x73, 0xFF}}},
{{{    62,     34,     -1}, 0, {   210,   2108},  {0xFD, 0x82, 0x10, 0xFF}}},
{{{    30,     30,     -1}, 0, {   210,   2082},  {0x0D, 0x83, 0x12, 0xFF}}},
{{{    64,     21,     25}, 0, {   178,   2106},  {0xFA, 0xBE, 0x94, 0xFF}}},
{{{    30,     20,     25}, 0, {   178,   2082},  {0x02, 0xBD, 0x94, 0xFF}}},
{{{    83,     30,     -3}, 0, {   210,   2114},  {0xF7, 0x84, 0x18, 0xFF}}},
};

const Gfx isabelle_outfit_right_arm_tris[] = {
	gsSPVertex(_000_offset_006_mesh_vtx + 0, 27, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 0, 5, 0),
	gsSP2Triangles(2, 5, 0, 0, 2, 6, 5, 0),
	gsSP2Triangles(2, 7, 6, 0, 2, 8, 7, 0),
	gsSP2Triangles(9, 8, 2, 0, 9, 2, 1, 0),
	gsSP2Triangles(9, 1, 10, 0, 10, 1, 3, 0),
	gsSP2Triangles(11, 10, 3, 0, 11, 3, 12, 0),
	gsSP2Triangles(13, 12, 3, 0, 3, 4, 13, 0),
	gsSP2Triangles(14, 13, 4, 0, 4, 15, 14, 0),
	gsSP2Triangles(5, 15, 4, 0, 6, 15, 5, 0),
	gsSP2Triangles(16, 15, 6, 0, 6, 7, 16, 0),
	gsSP2Triangles(7, 17, 16, 0, 7, 8, 17, 0),
	gsSP2Triangles(8, 18, 17, 0, 19, 18, 8, 0),
	gsSP2Triangles(19, 8, 9, 0, 19, 9, 20, 0),
	gsSP2Triangles(9, 10, 20, 0, 10, 21, 20, 0),
	gsSP2Triangles(11, 21, 10, 0, 11, 22, 21, 0),
	gsSP2Triangles(11, 23, 22, 0, 11, 24, 23, 0),
	gsSP2Triangles(11, 12, 24, 0, 12, 13, 24, 0),
	gsSP2Triangles(13, 14, 24, 0, 14, 25, 24, 0),
	gsSP2Triangles(14, 15, 25, 0, 25, 15, 16, 0),
	gsSP2Triangles(16, 26, 25, 0, 26, 16, 23, 0),
	gsSP2Triangles(16, 17, 23, 0, 22, 23, 17, 0),
	gsSP2Triangles(22, 17, 18, 0, 19, 22, 18, 0),
	gsSP2Triangles(19, 21, 22, 0, 19, 20, 21, 0),
	gsSP2Triangles(24, 26, 23, 0, 24, 25, 26, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_color_right_arm_tris[] = {
	gsSPVertex(_000_offset_006_mesh_vtx + 27, 15, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
	gsSP2Triangles(6, 4, 5, 0, 7, 4, 6, 0),
	gsSP2Triangles(7, 6, 8, 0, 9, 8, 6, 0),
	gsSP2Triangles(10, 8, 9, 0, 10, 9, 11, 0),
	gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
	gsSP2Triangles(14, 8, 10, 0, 1, 14, 10, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_right_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_outfit_right_arm_tris),
	gsSPDisplayList(isabelle_color_right_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_right_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_outfit_front),
	gsSPDisplayList(isabelle_outfit_right_arm_tris),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_right_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_007_mesh_vtx[] = {
{{{    20,     20,     23}, 0, {   368,   2110},  {0xF9, 0xBC, 0x95, 0xFF}}},
{{{    17,    -19,     20}, 0, {   334,   2112},  {0xFA, 0x4F, 0x9C, 0xFF}}},
{{{    17,    -28,     -3}, 0, {   302,   2112},  {0xFB, 0x7F, 0x08, 0xFF}}},
{{{    15,    -17,    -25}, 0, {   272,   2110},  {0xFD, 0x43, 0x6C, 0xFF}}},
{{{    17,     12,    -25}, 0, {   240,   2112},  {0xFD, 0xCC, 0x74, 0xFF}}},
{{{    74,     29,      0}, 0, {   208,   2144},  {0xD6, 0x88, 0x09, 0xFF}}},
{{{    20,     20,     23}, 0, {   178,   2110},  {0xF9, 0xBC, 0x95, 0xFF}}},
{{{    87,     18,      0}, 0, {   220,   2156},  {0x90, 0xC5, 0x06, 0xFF}}},
{{{    83,      5,     17}, 0, {   178,   2152},  {0x9D, 0xFF, 0xB1, 0xFF}}},
{{{    87,     -9,      0}, 0, {   260,   2152},  {0x8F, 0x3A, 0x04, 0xFF}}},
{{{    74,     18,     21}, 0, {   178,   2144},  {0xD3, 0xC2, 0x9B, 0xFF}}},
{{{    74,     29,      0}, 0, {   208,   2144},  {0xD6, 0x88, 0x09, 0xFF}}},
{{{    74,     16,    -18}, 0, {   236,   2144},  {0xD4, 0xC6, 0x68, 0xFF}}},
{{{    83,      5,    -14}, 0, {   260,   2152},  {0xA0, 0xFE, 0x53, 0xFF}}},
{{{    87,     -9,      0}, 0, {   316,   2156},  {0x8F, 0x3A, 0x04, 0xFF}}},
{{{    74,     -8,    -18}, 0, {   268,   2144},  {0xCD, 0x38, 0x66, 0xFF}}},
{{{    74,    -20,      0}, 0, {   304,   2144},  {0xCD, 0x74, 0x03, 0xFF}}},
{{{    74,     -8,     21}, 0, {   340,   2144},  {0xD1, 0x3B, 0x9A, 0xFF}}},
{{{    83,      5,     17}, 0, {   368,   2152},  {0x9D, 0xFF, 0xB1, 0xFF}}},
{{{    74,     18,     21}, 0, {   368,   2144},  {0xD3, 0xC2, 0x9B, 0xFF}}},
{{{    20,     20,     23}, 0, {   368,   2110},  {0xF9, 0xBC, 0x95, 0xFF}}},
{{{    17,    -19,     20}, 0, {   334,   2112},  {0xFA, 0x4F, 0x9C, 0xFF}}},
{{{    17,    -28,     -3}, 0, {   302,   2112},  {0xFB, 0x7F, 0x08, 0xFF}}},
{{{    15,    -17,    -25}, 0, {   272,   2110},  {0xFD, 0x43, 0x6C, 0xFF}}},
{{{    17,     12,    -25}, 0, {   240,   2112},  {0xFD, 0xCC, 0x74, 0xFF}}},
{{{    20,     20,     23}, 0, {   178,   2110},  {0xF9, 0xBC, 0x95, 0xFF}}},

};

const Gfx isabelle_color_right_forearm_tris1[] = {
	gsSPVertex(_000_offset_007_mesh_vtx + 0, 7, 6),
	gsSP2Triangles(2, 6, 3, 0, 2, 7, 6, 0),
	gsSP2Triangles(2, 1, 7, 0, 0, 7, 1, 0),
	gsSP2Triangles(0, 8, 7, 0, 0, 9, 8, 0),
	gsSP2Triangles(0, 5, 9, 0, 4, 9, 5, 0),
	gsSP2Triangles(4, 10, 9, 0, 3, 10, 4, 0),
	gsSP2Triangles(10, 3, 11, 0, 3, 12, 11, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_color_right_forearm_tris2[] = {
	gsSPVertex(_000_offset_007_mesh_vtx + 7, 19, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
	gsSP2Triangles(5, 0, 6, 0, 6, 0, 7, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 7, 10, 0, 10, 7, 11, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
	gsSP2Triangles(10, 13, 14, 0, 9, 10, 14, 0),
	gsSP2Triangles(9, 14, 15, 0, 16, 9, 15, 0),
	gsSP2Triangles(16, 8, 9, 0, 17, 8, 16, 0),
	gsSP2Triangles(17, 5, 8, 0, 17, 4, 5, 0),
	gsSP2Triangles(5, 6, 8, 0, 4, 18, 3, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_right_forearm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_right_forearm_tris1),
	gsSPDisplayList(isabelle_color_right_forearm_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_right_forearm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_right_forearm_tris1),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_right_forearm_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};


const Vtx _000_offset_007_skinned_vtx[] = {
{{{    61,    -27,     -1}, 0, {   302,   2112},  {0x04, 0x7F, 0x05, 0xFF}}},
{{{    61,    -18,     22}, 0, {   334,   2112},  {0xFB, 0x4A, 0x99, 0xFF}}},
{{{    64,     21,     25}, 0, {   368,   2106},  {0xFA, 0xBE, 0x94, 0xFF}}},
{{{    83,     30,     -3}, 0, {   210,   2114},  {0xF7, 0x84, 0x18, 0xFF}}},
{{{    61,     13,    -23}, 0, {   240,   2108},  {0x03, 0xCA, 0x73, 0xFF}}},
{{{    59,    -16,    -23}, 0, {   272,   2110},  {0x05, 0x43, 0x6C, 0xFF}}},
};

const Gfx isabelle_color_skinned_right_arm_tris[] = {
	gsSPVertex(_000_offset_007_skinned_vtx + 0, 6, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_skinned_right_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_skinned_right_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

const Gfx isabelle_skinned_right_arm[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_skinned_right_arm_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_009_mesh_vtx[] = {
{{{    22,      1,    -26}, 0, {   174,   2228},  {0x1A, 0xFF, 0x7C, 0xFF}}},
{{{     9,     -1,    -19}, 0, {   174,   2228},  {0x66, 0x0A, 0x4B, 0xFF}}},
{{{     7,     19,    -12}, 0, {   200,   2228},  {0x6C, 0xCE, 0x2C, 0xFF}}},
{{{    19,     28,    -17}, 0, {   200,   2228},  {0x26, 0x9D, 0x46, 0xFF}}},
{{{    19,     26,     20}, 0, {   240,   2236},  {0x22, 0xA4, 0xB0, 0xFF}}},
{{{     7,     18,     15}, 0, {   240,   2236},  {0x6A, 0xD2, 0xCB, 0xFF}}},
{{{     9,      0,     19}, 0, {   264,   2236},  {0x6A, 0x01, 0xBA, 0xFF}}},
{{{     9,     -1,    -19}, 0, {   364,   2228},  {0x66, 0x0A, 0x4B, 0xFF}}},
{{{    11,    -31,    -10}, 0, {   328,   2232},  {0x62, 0x47, 0x26, 0xFF}}},
{{{    22,      1,    -26}, 0, {   364,   2228},  {0x1A, 0xFF, 0x7C, 0xFF}}},
{{{    25,    -39,    -14}, 0, {   328,   2232},  {0x16, 0x6E, 0x3B, 0xFF}}},
{{{    72,      1,    -23}, 0, {   364,   2194},  {0xF8, 0x01, 0x7F, 0xFF}}},
{{{    68,    -26,    -12}, 0, {   332,   2196},  {0xE2, 0x63, 0x49, 0xFF}}},
{{{    76,    -24,    -12}, 0, {   334,   2190},  {0xF2, 0x65, 0x4C, 0xFF}}},
{{{    68,    -28,     11}, 0, {   306,   2196},  {0xDE, 0x6A, 0xC3, 0xFF}}},
{{{    76,    -26,     11}, 0, {   306,   2190},  {0xF0, 0x69, 0xBB, 0xFF}}},
{{{    72,      1,     22}, 0, {   262,   2194},  {0xF1, 0xFA, 0x82, 0xFF}}},
{{{    25,    -27,     27}, 0, {   294,   2236},  {0x15, 0x4A, 0x9B, 0xFF}}},
{{{    22,      2,     25}, 0, {   264,   2236},  {0x18, 0xF1, 0x84, 0xFF}}},
{{{    63,     26,     12}, 0, {   234,   2198},  {0xEB, 0x98, 0xBB, 0xFF}}},
{{{    72,     24,     11}, 0, {   230,   2192},  {0xEA, 0x9A, 0xB8, 0xFF}}},
{{{    71,     27,    -13}, 0, {   202,   2194},  {0xE8, 0x96, 0x41, 0xFF}}},
{{{    61,     29,    -14}, 0, {   200,   2200},  {0xF1, 0x94, 0x41, 0xFF}}},
{{{    72,      1,    -23}, 0, {   174,   2194},  {0xF8, 0x01, 0x7F, 0xFF}}},
{{{    11,    -22,     21}, 0, {   294,   2236},  {0x61, 0x31, 0xBE, 0xFF}}},
};

const Gfx isabelle_color_left_thigh_tris[] = {
	gsSPVertex(_000_offset_009_mesh_vtx + 0, 25, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 3, 2, 0, 4, 2, 5, 0),
	gsSP2Triangles(6, 5, 2, 0, 2, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 10, 8, 0, 10, 9, 11, 0),
	gsSP2Triangles(12, 10, 11, 0, 13, 12, 11, 0),
	gsSP2Triangles(14, 12, 13, 0, 14, 13, 15, 0),
	gsSP2Triangles(16, 14, 15, 0, 16, 17, 14, 0),
	gsSP2Triangles(16, 18, 17, 0, 16, 4, 18, 0),
	gsSP2Triangles(16, 19, 4, 0, 16, 20, 19, 0),
	gsSP2Triangles(21, 19, 20, 0, 19, 21, 22, 0),
	gsSP2Triangles(21, 23, 22, 0, 3, 22, 23, 0),
	gsSP2Triangles(3, 23, 0, 0, 4, 22, 3, 0),
	gsSP2Triangles(19, 22, 4, 0, 18, 4, 5, 0),
	gsSP2Triangles(18, 5, 6, 0, 18, 6, 24, 0),
	gsSP2Triangles(8, 24, 6, 0, 17, 24, 8, 0),
	gsSP2Triangles(17, 8, 10, 0, 14, 17, 10, 0),
	gsSP2Triangles(14, 10, 12, 0, 18, 24, 17, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_left_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_left_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};


const Gfx isabelle_left_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_left_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_010_mesh_vtx[] = {
{{{    57,      2,    -23}, 0, {   366,   2162},  {0xC6, 0xFE, 0x71, 0xFF}}},
{{{    57,    -22,    -13}, 0, {   334,   2162},  {0xBC, 0x59, 0x3D, 0xFF}}},
{{{    57,    -23,     12}, 0, {   306,   2162},  {0xBD, 0x58, 0xC2, 0xFF}}},
{{{    57,      2,     20}, 0, {   256,   2162},  {0xC8, 0xFB, 0x8E, 0xFF}}},
{{{    10,     23,     11}, 0, {   226,   2188},  {0xF8, 0x9A, 0xB5, 0xFF}}},
{{{    10,     26,    -12}, 0, {   202,   2188},  {0xF6, 0x91, 0x3E, 0xFF}}},
{{{    57,      2,    -23}, 0, {   176,   2162},  {0xC6, 0xFE, 0x71, 0xFF}}},
{{{    57,      2,    -23}, 0, {   366,   2162},  {0xC6, 0xFE, 0x71, 0xFF}}},
{{{    63,      1,    -12}, 0, {   368,   2158},  {0x85, 0x01, 0x1E, 0xFF}}},
{{{    57,    -22,    -13}, 0, {   334,   2162},  {0xBC, 0x59, 0x3D, 0xFF}}},
{{{    63,      1,     11}, 0, {   246,   2158},  {0x86, 0xFF, 0xDD, 0xFF}}},
{{{    57,    -23,     12}, 0, {   306,   2162},  {0xBD, 0x58, 0xC2, 0xFF}}},
{{{    57,      2,     20}, 0, {   256,   2162},  {0xC8, 0xFB, 0x8E, 0xFF}}},
{{{    57,     22,     12}, 0, {   224,   2162},  {0xBE, 0xA9, 0xBF, 0xFF}}},
{{{    57,     25,    -13}, 0, {   202,   2162},  {0xBF, 0xA1, 0x35, 0xFF}}},
{{{    63,      1,    -12}, 0, {   178,   2158},  {0x85, 0x01, 0x1E, 0xFF}}},
{{{    57,      2,    -23}, 0, {   176,   2162},  {0xC6, 0xFE, 0x71, 0xFF}}},
{{{    10,     26,    -12}, 0, {   202,   2188},  {0xF6, 0x91, 0x3E, 0xFF}}},
{{{    10,     23,     11}, 0, {   226,   2188},  {0xF8, 0x9A, 0xB5, 0xFF}}},
};

const Gfx isabelle_color_left_leg_tris1[] = {
	gsSPVertex(_000_offset_010_mesh_vtx + 0, 7, 7),
	gsSP2Triangles(5, 6, 7, 0, 5, 7, 8, 0),
	gsSP2Triangles(5, 8, 4, 0, 9, 4, 8, 0),
	gsSP2Triangles(10, 4, 9, 0, 3, 4, 10, 0),
	gsSP2Triangles(3, 10, 11, 0, 2, 3, 11, 0),
	gsSP2Triangles(11, 12, 2, 0, 1, 2, 12, 0),
	gsSP2Triangles(0, 1, 12, 0, 12, 13, 0, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_color_left_leg_tris2[] = {
	gsSPVertex(_000_offset_010_mesh_vtx + 7, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(4, 2, 3, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 3, 6, 0, 6, 3, 7, 0),
	gsSP2Triangles(3, 8, 7, 0, 9, 7, 8, 0),
	gsSP2Triangles(10, 7, 9, 0, 11, 7, 10, 0),
	gsSP2Triangles(6, 7, 11, 0, 5, 6, 11, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_left_leg[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_left_leg_tris1),
	gsSPDisplayList(isabelle_color_left_leg_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_left_leg[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_left_leg_tris1),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_left_leg_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};


const Vtx _000_offset_010_skinned_vtx[] = {
{{{    72,      1,    -23}, 0, {   174,   2194},  {0xF8, 0x01, 0x7F, 0xFF}}},
{{{    71,     27,    -13}, 0, {   202,   2194},  {0xE8, 0x96, 0x41, 0xFF}}},
{{{    72,     24,     11}, 0, {   230,   2192},  {0xEA, 0x9A, 0xB8, 0xFF}}},
{{{    72,      1,     22}, 0, {   262,   2194},  {0xF1, 0xFA, 0x82, 0xFF}}},
{{{    76,    -26,     11}, 0, {   306,   2190},  {0xF0, 0x69, 0xBB, 0xFF}}},
{{{    76,    -24,    -12}, 0, {   334,   2190},  {0xF2, 0x65, 0x4C, 0xFF}}},
{{{    72,      1,    -23}, 0, {   364,   2194},  {0xF8, 0x01, 0x7F, 0xFF}}},

};

const Gfx isabelle_color_skinned_left_thigh_tris[] = {
	gsSPVertex(_000_offset_010_skinned_vtx + 0, 7, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_skinned_left_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_skinned_left_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

const Gfx isabelle_skinned_left_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_skinned_left_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_011_mesh_vtx[] = { // not uv duplicated
	{{{1, -2, 0},0, {0xFFF0, 0xFFD2},{0x8B, 0x10, 0xD2, 0xFF}}},
	{{{-3, 0, 0},0, {0xFFF0, 0xFFD2},{0x8B, 0xE, 0xD0, 0xFF}}},
	{{{-1, -1, 0},0, {0xFFF0, 0xFFD2},{0x0, 0xBF, 0x6D, 0xFF}}},
};

const Gfx isabelle_color_left_foot_tris[] = {
	gsSPVertex(_000_offset_011_mesh_vtx + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_left_foot[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_left_foot_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_left_foot[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_left_foot_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_012_mesh_vtx[] = {
{{{    21,      1,     26}, 0, {   364,   2228},  {0x1F, 0x05, 0x85, 0xFF}}},
{{{    10,      0,     18}, 0, {   364,   2228},  {0x6A, 0x0E, 0xBC, 0xFF}}},
{{{    11,    -24,     10}, 0, {   328,   2232},  {0x66, 0x41, 0xD9, 0xFF}}},
{{{    24,    -32,     14}, 0, {   328,   2232},  {0x1E, 0x69, 0xBF, 0xFF}}},
{{{    11,    -21,    -20}, 0, {   294,   2236},  {0x66, 0x33, 0x38, 0xFF}}},
{{{     9,      0,    -18}, 0, {   264,   2236},  {0x6E, 0x04, 0x3F, 0xFF}}},
{{{    10,      0,     18}, 0, {   174,   2228},  {0x6A, 0x0E, 0xBC, 0xFF}}},
{{{     7,     21,     12}, 0, {   200,   2228},  {0x71, 0xD7, 0xD6, 0xFF}}},
{{{    21,      1,     26}, 0, {   174,   2228},  {0x1F, 0x05, 0x85, 0xFF}}},
{{{    17,     31,     17}, 0, {   200,   2228},  {0x2B, 0x9F, 0xBA, 0xFF}}},
{{{    72,      1,     23}, 0, {   174,   2194},  {0xF9, 0x02, 0x81, 0xFF}}},
{{{    61,     29,     14}, 0, {   200,   2200},  {0xED, 0x95, 0xBF, 0xFF}}},
{{{    17,     29,    -20}, 0, {   240,   2236},  {0x28, 0xA5, 0x4F, 0xFF}}},
{{{    63,     26,    -12}, 0, {   234,   2198},  {0xE7, 0x99, 0x46, 0xFF}}},
{{{     7,     19,    -15}, 0, {   240,   2236},  {0x70, 0xDB, 0x30, 0xFF}}},
{{{    20,      2,    -25}, 0, {   264,   2236},  {0x1E, 0xF3, 0x7B, 0xFF}}},
{{{    23,    -28,    -27}, 0, {   294,   2236},  {0x1D, 0x4F, 0x5F, 0xFF}}},
{{{    68,    -28,    -11}, 0, {   306,   2196},  {0xE3, 0x6D, 0x3A, 0xFF}}},
{{{    68,    -26,     12}, 0, {   332,   2196},  {0xE8, 0x66, 0xB9, 0xFF}}},
{{{    72,      1,     23}, 0, {   364,   2194},  {0xF9, 0x02, 0x81, 0xFF}}},
};

const Gfx isabelle_color_right_thigh_tris[] = {
	gsSPVertex(_000_offset_012_mesh_vtx + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 5, 4, 2, 0),
	gsSP2Triangles(6, 5, 2, 0, 6, 7, 5, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(9, 8, 10, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 9, 11, 0, 13, 12, 11, 0),
	gsSP2Triangles(12, 7, 9, 0, 12, 14, 7, 0),
	gsSP2Triangles(15, 14, 12, 0, 15, 5, 14, 0),
	gsSP2Triangles(15, 4, 5, 0, 15, 16, 4, 0),
	gsSP2Triangles(3, 4, 16, 0, 17, 3, 16, 0),
	gsSP2Triangles(17, 18, 3, 0, 18, 19, 3, 0),
	gsSP2Triangles(3, 19, 0, 0, 14, 5, 7, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_right_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_right_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_right_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_right_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};



const Vtx _000_offset_013_mesh_vtx[] = {
{{{     0,     27,     13}, 0, {   202,   2194},  {0xE7, 0x96, 0xBF, 0xFF}}},
{{{     1,     24,    -11}, 0, {   230,   2192},  {0xE9, 0x9A, 0x48, 0xFF}}},
{{{     2,      1,    -22}, 0, {   262,   2194},  {0xF1, 0xFA, 0x7E, 0xFF}}},
{{{    57,      2,    -20}, 0, {   256,   2162},  {0xC8, 0xFB, 0x72, 0xFF}}},
{{{    57,    -23,    -12}, 0, {   306,   2162},  {0xBD, 0x58, 0x3E, 0xFF}}},
{{{    57,    -22,     13}, 0, {   334,   2162},  {0xBC, 0x59, 0xC3, 0xFF}}},
{{{     5,    -24,     12}, 0, {   334,   2190},  {0xF0, 0x64, 0xB4, 0xFF}}},
{{{    57,      2,     23}, 0, {   366,   2162},  {0xC6, 0xFE, 0x8F, 0xFF}}},
{{{    10,     26,     12}, 0, {   202,   2188},  {0xF7, 0x91, 0xC2, 0xFF}}},
{{{    57,      2,     23}, 0, {   176,   2162},  {0xC6, 0xFE, 0x8F, 0xFF}}},
{{{     0,     27,     13}, 0, {   202,   2194},  {0xE7, 0x96, 0xBF, 0xFF}}},
{{{    10,     26,     12}, 0, {   202,   2188},  {0xF7, 0x91, 0xC2, 0xFF}}},
{{{     1,     24,    -11}, 0, {   230,   2192},  {0xE9, 0x9A, 0x48, 0xFF}}},
{{{    10,     23,    -11}, 0, {   226,   2188},  {0xF9, 0x9A, 0x4B, 0xFF}}},
{{{    57,     25,     13}, 0, {   202,   2162},  {0xBF, 0xA1, 0xCB, 0xFF}}},
{{{    57,      2,     23}, 0, {   176,   2162},  {0xC6, 0xFE, 0x8F, 0xFF}}},
{{{    63,      1,     12}, 0, {   178,   2158},  {0x85, 0x01, 0xE2, 0xFF}}},
{{{    63,      1,    -11}, 0, {   246,   2158},  {0x86, 0xFF, 0x23, 0xFF}}},
{{{    57,     22,    -12}, 0, {   224,   2162},  {0xBE, 0xA9, 0x41, 0xFF}}},
{{{    57,      2,    -20}, 0, {   256,   2162},  {0xC8, 0xFB, 0x72, 0xFF}}},
{{{    57,    -23,    -12}, 0, {   306,   2162},  {0xBD, 0x58, 0x3E, 0xFF}}},
{{{    57,    -22,     13}, 0, {   334,   2162},  {0xBC, 0x59, 0xC3, 0xFF}}},
{{{    63,      1,     12}, 0, {   368,   2158},  {0x85, 0x01, 0xE2, 0xFF}}},
{{{    57,      2,     23}, 0, {   366,   2162},  {0xC6, 0xFE, 0x8F, 0xFF}}},
{{{     5,    -24,     12}, 0, {   334,   2190},  {0xF0, 0x64, 0xB4, 0xFF}}},
{{{     2,      1,    -22}, 0, {   262,   2194},  {0xF1, 0xFA, 0x7E, 0xFF}}},
};

const Gfx isabelle_color_right_leg_tris1[] = {
	gsSPVertex(_000_offset_013_mesh_vtx + 0, 10, 10),
	gsSP2Triangles(10, 1, 2, 0, 0, 1, 10, 0),
	gsSP2Triangles(10, 11, 0, 0, 12, 0, 11, 0),
	gsSP2Triangles(12, 9, 0, 0, 12, 8, 9, 0),
	gsSP2Triangles(12, 7, 8, 0, 12, 3, 7, 0),
	gsSP2Triangles(12, 4, 3, 0, 12, 13, 4, 0),
	gsSP2Triangles(13, 14, 4, 0, 14, 15, 4, 0),
	gsSP2Triangles(16, 4, 15, 0, 3, 4, 16, 0),
	gsSP2Triangles(3, 16, 5, 0, 16, 6, 5, 0),
	gsSP2Triangles(16, 17, 6, 0, 2, 18, 10, 0),
	gsSP1Triangle(18, 2, 19, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_color_right_leg_tris2[] = {
	gsSPVertex(_000_offset_013_mesh_vtx + 10, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(3, 1, 4, 0, 1, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 4, 6, 0),
	gsSP2Triangles(8, 4, 7, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 7, 10, 0, 10, 7, 11, 0),
	gsSP2Triangles(11, 7, 12, 0, 13, 11, 12, 0),
	gsSP2Triangles(14, 11, 13, 0, 9, 3, 8, 0),
	gsSP2Triangles(15, 3, 9, 0, 2, 3, 15, 0),
	gsSP1Triangle(8, 3, 4, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_right_leg[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_right_leg_tris1),
	gsSPDisplayList(isabelle_color_right_leg_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};

const Gfx isabelle_right_leg[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_right_leg_tris1),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_right_leg_tris2),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	gsSPEndDisplayList(),
};


const Vtx _000_offset_013_skinned_vtx[] = {
{{{    63,     26,    -12}, 0, {   234,   2198},  {0xE7, 0x99, 0x46, 0xFF}}},
{{{    61,     29,     14}, 0, {   200,   2200},  {0xED, 0x95, 0xBF, 0xFF}}},
{{{    72,      1,     23}, 0, {   174,   2194},  {0xF9, 0x02, 0x81, 0xFF}}},
{{{    68,    -28,    -11}, 0, {   306,   2196},  {0xE3, 0x6D, 0x3A, 0xFF}}},
{{{    76,    -26,    -11}, 0, {   306,   2190},  {0xF0, 0x6A, 0x45, 0xFF}}},
{{{    68,    -26,     12}, 0, {   332,   2196},  {0xE8, 0x66, 0xB9, 0xFF}}},
{{{    72,      1,     23}, 0, {   364,   2194},  {0xF9, 0x02, 0x81, 0xFF}}},
{{{    23,    -28,    -27}, 0, {   294,   2236},  {0x1D, 0x4F, 0x5F, 0xFF}}},
{{{    20,      2,    -25}, 0, {   264,   2236},  {0x1E, 0xF3, 0x7B, 0xFF}}},
{{{    17,     29,    -20}, 0, {   240,   2236},  {0x28, 0xA5, 0x4F, 0xFF}}},
};

const Gfx isabelle_color_skinned_right_thigh_tris[] = {
	gsSPVertex(_000_offset_013_skinned_vtx + 0, 10, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_skinned_right_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_skinned_right_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};


const Gfx isabelle_skinned_right_thigh[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_skinned_right_thigh_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};



const Vtx _000_displaylist_005_mesh_vtx[] = { // not uv duplicated
	{{{0, 0, 0},0, {0xFFF0, 0xFFD2},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-2, 0, 0},0, {0xFFF0, 0xFFD2},{0x0, 0x0, 0x81, 0xFF}}},
	{{{3, -1, 0},0, {0xFFF0, 0xFFD2},{0x0, 0x0, 0x81, 0xFF}}},
};

const Gfx isabelle_color_right_foot_tris[] = {
	gsSPVertex(_000_displaylist_005_mesh_vtx + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

const Gfx isabelle_metal_right_foot[] = {
	gsSPDisplayList(isabelle_metal_shared_dl),
	gsSPDisplayList(isabelle_color_right_foot_tris),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

const Gfx isabelle_right_foot[] = {
    gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPDisplayList(isabelle_tex_face_eye_open),
	gsSPDisplayList(isabelle_color_right_foot_tris),
    gsDPSetTextureLUT(G_TT_NONE),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
	gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
