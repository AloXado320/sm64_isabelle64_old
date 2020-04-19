// Transparent Star

// 0x0302C488
static const Lights1 transparent_star_seg3_lights_0302C488 = gdSPDefLights1(
    0x03, 0x05, 0x17,
    0x1e, 0x32, 0xe6, 0x28, 0x28, 0x28
);

// 0x0302C620 - 0x0302C658
const Gfx transparent_star_seg3_dl_0302C620[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsDPSetEnvColor(255, 255, 255, 120),
    gsSPLight(&transparent_star_seg3_lights_0302C488.l, 1),
    gsSPLight(&transparent_star_seg3_lights_0302C488.a, 2),
    gsSPDisplayList(gold_leaf_dl_tris),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};
