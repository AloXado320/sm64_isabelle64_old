#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"

#include "make_const_nonconst.h"

const Lights1 n64logo_blue_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

const Lights1 n64logo_red_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

const Lights1 n64logo_green_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

const Lights1 n64logo_yellow_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

const u8 n64logo_blue_rgba16[] = {
	#include "levels/intro/blue.rgba16.inc.c"
};
const u8 n64logo_red_rgba16[] = {
	#include "levels/intro/red.rgba16.inc.c"
};
const u8 n64logo_green_rgba16[] = {
	#include "levels/intro/green.rgba16.inc.c"
};
const u8 n64logo_yeller_rgba16[] = {
	#include "levels/intro/yeller.rgba16.inc.c"
};
const Vtx n64logo_Ultra64_mesh_vtx_0[54] = {
	{{{-8275, 8275, 8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, 8275, 3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, 0, 8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, 0, 3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, -8275, 8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, -8275, 3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, 8275, -3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, 0, -3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, 8275, -8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, 0, -8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, -8275, -3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-8275, -8275, -8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{8275, 0, 8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, -8275, 8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, -8275, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 0, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 0, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 8275, 8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 0, 8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 8275, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, -8275, -3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 0, -3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, -8275, -8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 0, -8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 8275, -3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{8275, 8275, -8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{3761, 8275, 8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, 0, 8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, 8275, 3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, -8275, -3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, -8275, -8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, -8275, -3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, 0, -8275},0, {0xFFF0, 0x3F0},{0x81, 0x0, 0x0, 0xFF}}},
	{{{3761, -8275, 8275},0, {0xFFF0, 0x3F0},{0xBC, 0x95, 0x0, 0xFF}}},
	{{{-3761, 0, 3761},0, {0xFFF0, 0x3F0},{0xA2, 0xAB, 0x0, 0xFF}}},
	{{{3761, -8275, 3761},0, {0xFFF0, 0x3F0},{0xDE, 0x86, 0x0, 0xFF}}},
	{{{-3761, 0, 8275},0, {0xFFF0, 0x3F0},{0xA2, 0xAB, 0x0, 0xFF}}},
	{{{-3761, -8275, -8275},0, {0xFFF0, 0x3F0},{0x44, 0x95, 0x0, 0xFF}}},
	{{{3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x5E, 0xAB, 0x0, 0xFF}}},
	{{{-3761, -8275, -3761},0, {0xFFF0, 0x3F0},{0x22, 0x86, 0x0, 0xFF}}},
	{{{3761, 0, -8275},0, {0xFFF0, 0x3F0},{0x5E, 0xAB, 0x0, 0xFF}}},
	{{{-3761, -8275, 8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, 0, 8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, -8275, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, 8275, -3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, -8275, 3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, 8275, -8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-3761, 0, -8275},0, {0xFFF0, 0x3F0},{0x7F, 0x0, 0x0, 0xFF}}},
};

const Gfx n64logo_Ultra64_mesh_tri_0[] = {
	gsSPVertex(n64logo_Ultra64_mesh_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(3, 4, 2, 0),
	gsSP1Triangle(3, 5, 4, 0),
	gsSP1Triangle(5, 3, 6, 0),
	gsSP1Triangle(6, 7, 5, 0),
	gsSP1Triangle(6, 8, 7, 0),
	gsSP1Triangle(8, 9, 7, 0),
	gsSP1Triangle(7, 9, 10, 0),
	gsSP1Triangle(9, 11, 10, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(n64logo_Ultra64_mesh_vtx_0 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(3, 0, 4, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(4, 6, 5, 0),
	gsSP1Triangle(6, 7, 5, 0),
	gsSP1Triangle(8, 5, 7, 0),
	gsSP1Triangle(9, 8, 7, 0),
	gsSP1Triangle(10, 11, 12, 0),
	gsSP1Triangle(10, 13, 11, 0),
	gsSP1Triangle(13, 14, 11, 0),
	gsSP1Triangle(13, 15, 14, 0),
	gsSPVertex(n64logo_Ultra64_mesh_vtx_0 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 11, 9, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPVertex(n64logo_Ultra64_mesh_vtx_0 + 48, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(0, 3, 4, 0),
	gsSP1Triangle(3, 5, 4, 0),
	gsSPEndDisplayList(),
};const Vtx n64logo_Ultra64_mesh_vtx_1[16] = {
	{{{-8275, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0xAB, 0xA2, 0xFF}}},
	{{{-3761, -8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x8C, 0xCC, 0xFF}}},
	{{{-8275, -8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x8C, 0xCC, 0xFF}}},
	{{{-3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0xAB, 0xA2, 0xFF}}},
	{{{8275, -8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x95, 0x44, 0xFF}}},
	{{{8275, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0xAB, 0x5E, 0xFF}}},
	{{{3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0xAB, 0x5E, 0xFF}}},
	{{{3761, -8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x86, 0x22, 0xFF}}},
	{{{-3761, 8275, 8275},0, {0xFFF0, 0x3F0},{0x44, 0x6B, 0x0, 0xFF}}},
	{{{3761, 0, 8275},0, {0xFFF0, 0x3F0},{0x5E, 0x55, 0x0, 0xFF}}},
	{{{3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x5E, 0x55, 0x0, 0xFF}}},
	{{{-3761, 8275, 3761},0, {0xFFF0, 0x3F0},{0x22, 0x7A, 0x0, 0xFF}}},
	{{{-3761, 0, -3761},0, {0xFFF0, 0x3F0},{0xA2, 0x55, 0x0, 0xFF}}},
	{{{3761, 8275, -8275},0, {0xFFF0, 0x3F0},{0xBC, 0x6B, 0x0, 0xFF}}},
	{{{-3761, 0, -8275},0, {0xFFF0, 0x3F0},{0xA2, 0x55, 0x0, 0xFF}}},
	{{{3761, 8275, -3761},0, {0xFFF0, 0x3F0},{0xDE, 0x7A, 0x0, 0xFF}}},
};

const Gfx n64logo_Ultra64_mesh_tri_1[] = {
	gsSPVertex(n64logo_Ultra64_mesh_vtx_1 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 1, 0, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPEndDisplayList(),
};const Vtx n64logo_Ultra64_mesh_vtx_2[52] = {
	{{{-3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8275, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8275, -8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-3761, -8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{3761, 8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8275, 8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8275, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8275, 8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8275, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-3761, 8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{3761, -8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8275, -8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8275, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-3761, 8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x74, 0x34, 0xFF}}},
	{{{-8275, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x55, 0x5E, 0xFF}}},
	{{{-3761, 0, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x55, 0x5E, 0xFF}}},
	{{{-8275, 8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x74, 0x34, 0xFF}}},
	{{{8275, 8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x6B, 0xBC, 0xFF}}},
	{{{3761, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x55, 0xA2, 0xFF}}},
	{{{3761, 8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x7A, 0xDE, 0xFF}}},
	{{{8275, 0, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x55, 0xA2, 0xFF}}},
	{{{8275, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{3761, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8275, 0, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{3761, 0, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8275, -8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{3761, -8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-3761, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-3761, 0, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-3761, 0, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-3761, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8275, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8275, 0, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-3761, -8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-8275, -8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{8275, -8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{3761, -8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8275, 0, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{3761, 0, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{8275, 8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{3761, 8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-3761, -8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-3761, 0, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8275, -8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8275, 0, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-3761, 0, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8275, 0, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-3761, 8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-8275, 8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x0, 0x81, 0xFF}}},
};

const Gfx n64logo_Ultra64_mesh_tri_2[] = {
	gsSPVertex(n64logo_Ultra64_mesh_vtx_2 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(4, 0, 3, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSP1Triangle(6, 4, 5, 0),
	gsSP1Triangle(6, 5, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 11, 9, 0),
	gsSP1Triangle(9, 11, 12, 0),
	gsSP1Triangle(11, 13, 12, 0),
	gsSP1Triangle(14, 12, 13, 0),
	gsSP1Triangle(14, 13, 15, 0),
	gsSPVertex(n64logo_Ultra64_mesh_vtx_2 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(9, 11, 10, 0),
	gsSP1Triangle(12, 10, 11, 0),
	gsSP1Triangle(13, 12, 11, 0),
	gsSP1Triangle(11, 14, 13, 0),
	gsSP1Triangle(14, 15, 13, 0),
	gsSPVertex(n64logo_Ultra64_mesh_vtx_2 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 0, 3, 0),
	gsSP1Triangle(5, 4, 3, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(7, 9, 8, 0),
	gsSP1Triangle(10, 8, 9, 0),
	gsSP1Triangle(11, 10, 9, 0),
	gsSP1Triangle(9, 12, 11, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(13, 12, 14, 0),
	gsSP1Triangle(13, 14, 15, 0),
	gsSPVertex(n64logo_Ultra64_mesh_vtx_2 + 48, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSPEndDisplayList(),
};const Vtx n64logo_Ultra64_mesh_vtx_3[32] = {
	{{{8275, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{3761, 8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x7A, 0xDE, 0xFF}}},
	{{{3761, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8275, 8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x6B, 0xBC, 0xFF}}},
	{{{-3761, 8275, 3761},0, {0xFFF0, 0x3F0},{0x22, 0x7A, 0x0, 0xFF}}},
	{{{-8275, 8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-3761, 8275, 8275},0, {0xFFF0, 0x3F0},{0x44, 0x6B, 0x0, 0xFF}}},
	{{{-8275, 8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{3761, -8275, 3761},0, {0xFFF0, 0x3F0},{0xDE, 0x86, 0x0, 0xFF}}},
	{{{8275, -8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{3761, -8275, 8275},0, {0xFFF0, 0x3F0},{0xBC, 0x95, 0x0, 0xFF}}},
	{{{8275, -8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-3761, -8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x8C, 0xCC, 0xFF}}},
	{{{-3761, -8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8275, -8275, 8275},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8275, -8275, 3761},0, {0xFFF0, 0x3F0},{0x0, 0x8C, 0xCC, 0xFF}}},
	{{{-3761, 8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x74, 0x34, 0xFF}}},
	{{{-8275, 8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8275, 8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x74, 0x34, 0xFF}}},
	{{{-3761, 8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8275, -8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-8275, -8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-3761, -8275, -3761},0, {0xFFF0, 0x3F0},{0x22, 0x86, 0x0, 0xFF}}},
	{{{-3761, -8275, -8275},0, {0xFFF0, 0x3F0},{0x44, 0x95, 0x0, 0xFF}}},
	{{{3761, 8275, -3761},0, {0xFFF0, 0x3F0},{0xDE, 0x7A, 0x0, 0xFF}}},
	{{{8275, 8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{3761, 8275, -8275},0, {0xFFF0, 0x3F0},{0xBC, 0x6B, 0x0, 0xFF}}},
	{{{8275, 8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{3761, -8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{8275, -8275, -8275},0, {0xFFF0, 0x3F0},{0x0, 0x81, 0x0, 0xFF}}},
	{{{3761, -8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x86, 0x22, 0xFF}}},
	{{{8275, -8275, -3761},0, {0xFFF0, 0x3F0},{0x0, 0x95, 0x44, 0xFF}}},
};

const Gfx n64logo_Ultra64_mesh_tri_3[] = {
	gsSPVertex(n64logo_Ultra64_mesh_vtx_3 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(7, 5, 4, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 9, 8, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(15, 12, 14, 0),
	gsSPVertex(n64logo_Ultra64_mesh_vtx_3 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(6, 5, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 9, 8, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(13, 15, 14, 0),
	gsSPEndDisplayList(),
};


const Gfx mat_n64logo_blue[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, n64logo_blue_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(n64logo_blue_lights),
	gsSPEndDisplayList(),
};


const Gfx mat_n64logo_red[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, n64logo_red_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(n64logo_red_lights),
	gsSPEndDisplayList(),
};


const Gfx mat_n64logo_green[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, n64logo_green_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(n64logo_green_lights),
	gsSPEndDisplayList(),
};


const Gfx mat_n64logo_yellow[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, n64logo_yeller_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(n64logo_yellow_lights),
	gsSPEndDisplayList(),
};


const Gfx n64logo_Ultra64_mesh[] = {
	gsSPDisplayList(mat_n64logo_blue),
	gsSPDisplayList(n64logo_Ultra64_mesh_tri_0),
	gsSPDisplayList(mat_n64logo_red),
	gsSPDisplayList(n64logo_Ultra64_mesh_tri_1),
	gsSPDisplayList(mat_n64logo_green),
	gsSPDisplayList(n64logo_Ultra64_mesh_tri_2),
	gsSPDisplayList(mat_n64logo_yellow),
	gsSPDisplayList(n64logo_Ultra64_mesh_tri_3),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



const Gfx n64logo_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


const Gfx dl_intro_n64_logo[] = {
    gsSPDisplayList(n64logo_Ultra64_mesh),
    gsSPDisplayList(n64logo_material_revert_render_settings),
    gsSPEndDisplayList(),
};

ALIGNED8 const u8 texture_nintendo_words_pallete[] = {
#include "levels/intro/nintendo_texture_ci4_pallete.ia16.inc.c"
};

ALIGNED8 const u8 texture_nintendo_words_ci4[] = {
#include "levels/intro/nintendo_texture_ci4.inc.c"
};

ALIGNED8 const u8 texture_64_words_pallete[] = {
#include "levels/intro/64_texture_ci4_pallete.ia16.inc.c"
};

ALIGNED8 const u8 texture_64_words_ci4[] = {
#include "levels/intro/64_texture_ci4.inc.c"
};


// 0x0700B4A0 - 0x0700B4A2
ALIGNED8 static const u8 alo_intro_icon_pallete[] = {
#include "levels/intro/aloxado_icon_pallete.rgba16.inc.c"
};

// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const u8 alo_intro_icon_tex_ci4[] = {
#include "levels/intro/aloxado_icon_ci4.inc.c"
};

#define ALO_ICON_INTRO_X 96
#define ALO_ICON_INTRO_Y 46
#define ALO_ICON_INTRO_SCALE 2

const Gfx dl_icon_aloxado_intro[] = {
   
    gsDPSetTextureLUT(G_TT_RGBA16), // enable CI
    
    gsDPLoadTLUT_pal16(0, alo_intro_icon_pallete),
    
    // 64x64 texture (CI4 64x64)
    gsDPLoadTextureBlock_4b(alo_intro_icon_tex_ci4, G_IM_FMT_CI, 64, 64, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTextureRectangle(
        ALO_ICON_INTRO_X << 2, ALO_ICON_INTRO_Y << 2, (ALO_ICON_INTRO_X + 64 * ALO_ICON_INTRO_SCALE) << 2, (ALO_ICON_INTRO_Y + 64 * ALO_ICON_INTRO_SCALE) << 2, 
        G_TX_RENDERTILE, 0, 0, (1 << 10) / ALO_ICON_INTRO_SCALE, (1 << 10) / ALO_ICON_INTRO_SCALE),
    
    gsDPSetTextureLUT(G_TT_NONE),
    
    gsSPEndDisplayList(),
    
};

ALIGNED8 static const u8 dl_yui_aloxado_logo_tex_rgba32[] = {
#include "levels/intro/yui.rgba32.inc.c"
};

#define ALO_YUI_INTRO_X 44
#define ALO_YUI_INTRO_Y 94
#define ALO_YUI_INTRO_SCALE 2

const Gfx dl_yui_aloxado_intro[] = {
  
    // 32x32 texture (RGBA32 32x32)
    gsDPLoadTextureBlock(dl_yui_aloxado_logo_tex_rgba32, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTextureRectangle(
        ALO_YUI_INTRO_X << 2, ALO_YUI_INTRO_Y << 2, (ALO_YUI_INTRO_X + 32 * ALO_YUI_INTRO_SCALE) << 2, (ALO_YUI_INTRO_Y + 32 * ALO_YUI_INTRO_SCALE) << 2, 
        G_TX_RENDERTILE, 0, 0, (1 << 10) / ALO_YUI_INTRO_SCALE, (1 << 10) / ALO_YUI_INTRO_SCALE),
       
    gsSPEndDisplayList(),
    
};

ALIGNED8 static const u8 dl_isabelle_aloxado_logo_tex_rgba32[] = {
#include "levels/intro/isabelle.rgba32.inc.c"
};

#define ALO_DOG_INTRO_X 210
#define ALO_DOG_INTRO_Y 94
#define ALO_DOG_INTRO_SCALE 2

const Gfx dl_isabelle_aloxado_intro[] = {

    gsDPLoadTextureBlock(dl_isabelle_aloxado_logo_tex_rgba32, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_WRAP | G_TX_MIRROR, G_TX_WRAP | G_TX_MIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTextureRectangle(
        ALO_DOG_INTRO_X << 2, ALO_DOG_INTRO_Y << 2, (ALO_DOG_INTRO_X + 32 * ALO_DOG_INTRO_SCALE) << 2, (ALO_DOG_INTRO_Y + 32 * ALO_DOG_INTRO_SCALE) << 2, 
        G_TX_RENDERTILE, 0, 0, (1 << 10) / ALO_DOG_INTRO_SCALE, (1 << 10) / ALO_DOG_INTRO_SCALE),
       
    gsSPEndDisplayList(),
    
};

ALIGNED8 static const u8 dl_alo_aloxado_logo_tex_ia8[] = {
#include "levels/intro/aloxado_logo.ia8.inc.c"
};


#define ALO_LOGO_INTRO_X 32
#define ALO_LOGO_INTRO_Y 140
#define ALO_LOGO_INTRO_SCALE 2

const Gfx dl_logo_aloxado_intro[] = {

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
