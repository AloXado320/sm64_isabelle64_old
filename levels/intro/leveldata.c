#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"

#include "make_const_nonconst.h"

// 0x0700B4A0 - 0x0700B4A2
ALIGNED8 static const u8 dl_alo_intro_icon_pallete[] = {
#include "levels/intro/aloxado_icon_pallete.rgba16.inc.c"
};

// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const u8 dl_alo_intro_icon_tex_ci4[] = {
#include "levels/intro/aloxado_icon_ci4.bin.inc.c"
};

#define ALO_ICON_INTRO_X 96
#define ALO_ICON_INTRO_Y 46
#define ALO_ICON_INTRO_SCALE 2

// 0x0700C6A0 - 0x0700C790
const Gfx dl_icon_aloxado_intro[] = {
   
    gsDPSetTextureLUT(G_TT_RGBA16), // enable CI
    
    gsDPLoadTLUT_pal16(0, dl_alo_intro_icon_pallete),
    
    // 64x64 texture (CI4 64x64)
    gsDPLoadTextureBlock_4b(dl_alo_intro_icon_tex_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTextureRectangle(
        ALO_ICON_INTRO_X << 2, ALO_ICON_INTRO_Y << 2, (ALO_ICON_INTRO_X + 64 * ALO_ICON_INTRO_SCALE) << 2, (ALO_ICON_INTRO_Y + 64 * ALO_ICON_INTRO_SCALE) << 2, 
        G_TX_RENDERTILE, 0, 0, (1 << 10) / ALO_ICON_INTRO_SCALE, (1 << 10) / ALO_ICON_INTRO_SCALE),
    
    gsDPSetTextureLUT(G_TT_NONE),
    
    gsSPEndDisplayList(),
    
};

// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const u8 dl_yui_aloxado_logo_tex_rgba32[] = {
#include "levels/intro/yui.rgba32.inc.c"
};

#define ALO_YUI_INTRO_X 44
#define ALO_YUI_INTRO_Y 94
#define ALO_YUI_INTRO_SCALE 2

// 0x0700C6A0 - 0x0700C790
const Gfx dl_yui_aloxado_intro[] = {
  
    // 32x32 texture (RGBA32 32x32)
    gsDPLoadTextureBlock(dl_yui_aloxado_logo_tex_rgba32, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTextureRectangle(
        ALO_YUI_INTRO_X << 2, ALO_YUI_INTRO_Y << 2, (ALO_YUI_INTRO_X + 32 * ALO_YUI_INTRO_SCALE) << 2, (ALO_YUI_INTRO_Y + 32 * ALO_YUI_INTRO_SCALE) << 2, 
        G_TX_RENDERTILE, 0, 0, (1 << 10) / ALO_YUI_INTRO_SCALE, (1 << 10) / ALO_YUI_INTRO_SCALE),
       
    gsSPEndDisplayList(),
    
};

// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const u8 dl_isabelle_aloxado_logo_tex_rgba32[] = {
#include "levels/intro/isabelle.rgba32.inc.c"
};

#define ALO_DOG_INTRO_X 210
#define ALO_DOG_INTRO_Y 94
#define ALO_DOG_INTRO_SCALE 2

// 0x0700C6A0 - 0x0700C790
const Gfx dl_isabelle_aloxado_intro[] = {
  
    // 32x32 texture (RGBA32 32x32)
    gsDPLoadTextureBlock(dl_isabelle_aloxado_logo_tex_rgba32, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTextureRectangle(
        ALO_DOG_INTRO_X << 2, ALO_DOG_INTRO_Y << 2, (ALO_DOG_INTRO_X + 32 * ALO_DOG_INTRO_SCALE) << 2, (ALO_DOG_INTRO_Y + 32 * ALO_DOG_INTRO_SCALE) << 2, 
        G_TX_RENDERTILE, 0, 0, (1 << 10) / ALO_DOG_INTRO_SCALE, (1 << 10) / ALO_DOG_INTRO_SCALE),
       
    gsSPEndDisplayList(),
    
};

// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const u8 dl_alo_aloxado_logo_tex_ia8[] = {
#include "levels/intro/aloxado_logo.ia8.inc.c"
};


#define ALO_LOGO_INTRO_X 32
#define ALO_LOGO_INTRO_Y 140
#define ALO_LOGO_INTRO_SCALE 2

// 0x0700C6A0 - 0x0700C790
const Gfx dl_logo_aloxado_intro[] = {
  
    // 128x32 texture (IA8 128x32)
    gsDPLoadTextureBlock(dl_alo_aloxado_logo_tex_ia8, G_IM_FMT_IA, G_IM_SIZ_8b, 128, 32, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 7, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTextureRectangle(
        ALO_LOGO_INTRO_X << 2, ALO_LOGO_INTRO_Y << 2, (ALO_LOGO_INTRO_X + 128 * ALO_LOGO_INTRO_SCALE) << 2, (ALO_LOGO_INTRO_Y + 32 * ALO_LOGO_INTRO_SCALE) << 2, 
        G_TX_RENDERTILE, 0, 0, (1 << 10) / ALO_LOGO_INTRO_SCALE, (1 << 10) / ALO_LOGO_INTRO_SCALE),
       
    gsSPEndDisplayList(),
    
};

const Gfx dl_main_aloxado_intro[] = {
    gsSPDisplayList(dl_icon_aloxado_intro),
    gsSPDisplayList(dl_yui_aloxado_intro),
    gsSPDisplayList(dl_isabelle_aloxado_intro),
    gsSPDisplayList(dl_logo_aloxado_intro),
    gsSPEndDisplayList(),
};  