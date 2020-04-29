#include "ultra64.h"
#include "sm64.h"
#include "prevent_bss_reordering.h"
#include "types.h"
#include "game/memory.h"
#include "game/segment2.h"
#include "game/segment7.h"
#include "intro_geo.h"
#include "game/game_init.h"
#include "game/area.h"
#include "game/print.h"
#include "game/ingame_menu.h"

// background types
#define INTRO_BACKGROUND_SUPER_MARIO 0
#define INTRO_BACKGROUND_GAME_OVER 1

struct GraphNodeMore {
    /*0x00*/ struct GraphNode node;
    /*0x14*/ void *todo;
    /*0x18*/ u32 unk18;
};

// title screen segment A
extern Gfx title_screen_bg_dl_0A000118[];
extern Gfx title_screen_bg_dl_0A000100[];
extern Gfx title_screen_bg_dl_0A000130[];
extern Gfx title_screen_bg_dl_0A000148[];
extern Gfx title_screen_bg_dl_0A000160[];
extern Gfx title_screen_bg_dl_0A000178[];
extern Gfx title_screen_bg_dl_0A000190[];
extern const u8 *const mario_title_texture_table[];
extern const u8 *const game_over_texture_table[];

// intro geo bss
int gGameOverFrameCounter;
int gGameOverTableIndex;
s16 gTitleN64MainCounter;
s32 gTitleN64AlphaCounter;
s16 gTitleInitMessageCounter;

// intro screen background display lists for each of four 80x20 textures
Gfx *introBackgroundDlRows[] = { title_screen_bg_dl_0A000130, title_screen_bg_dl_0A000148,
                                 title_screen_bg_dl_0A000160, title_screen_bg_dl_0A000178 };

// intro screen background texture X offsets
float introBackgroundOffsetX[] = {
    0.0, 80.0, 160.0, 240.0, 0.0, 80.0, 160.0, 240.0, 0.0, 80.0, 160.0, 240.0,
};

// intro screen background texture Y offsets
float introBackgroundOffsetY[] = {
    160.0, 160.0, 160.0, 160.0, 80.0, 80.0, 80.0, 80.0, 0.0, 0.0, 0.0, 0.0,
};

// table that points to either the "Super Mario 64" or "Game Over" tables
const u8 *const *introBackgroundTextureType[] = { mario_title_texture_table, game_over_texture_table };

s8 introBackgroundIndexTable[] = {
    INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO,
    INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO,
    INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO,
    INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO, INTRO_BACKGROUND_SUPER_MARIO,
};

// only one table of indexes listed
s8 *introBackgroundTables[] = { introBackgroundIndexTable };

s8 gameOverBackgroundTable[] = {
    INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER,
    INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER,
    INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER,
    INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER, INTRO_BACKGROUND_GAME_OVER,
};

// order of tiles that are flipped from "Game Over" to "Super Mario 64"
s8 gameOverBackgroundFlipOrder[] = { 0x00, 0x01, 0x02, 0x03, 0x07, 0x0B,
                                     0x0a, 0x09, 0x08, 0x04, 0x05, 0x06 };

char *sShzIntroScreenText[] = {
    "Isabelle 64 version 1.3",
    "SM64 Character Mod by AloXado",
    "2018 - 2020 AloXado320",
    "",
    "Super Mario 64 - Animal Crossing",
    "and related characters made by",
    "Nintendo (EAD and EPD)",
    "All rights reserved",
    "",
    "This mod was made for entertainment",
    "purposes and as a Smash Tribute",
    "SM64 Decomp Project by Clever Folks",
    "Not Licensed by Nintendo (obviously)",
};

void render_initial_intro_message(void) {
    static float alpha = 0;
    s16 i;
    s16 y;
    s16 xPos;

    if (alpha < 250) {
        alpha += 15;
    } else {
        alpha = 255;
    }

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, alpha);
    for (i = 0, y = 208; i < 13; y -= 16, i++) {
        xPos = get_str_x_pos_from_center_custom(LUT_TYPE_ASCII, 160, NULL, sShzIntroScreenText[i], 2.0f);
        print_generic_str_ascii(xPos, y, sShzIntroScreenText[i]);
    }

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

void render_nintendo_64_textures(void) {
    s16 i;
    s16 x, y;

    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_start);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_IA16);

    gDPSetEnvColor(gDisplayListHead++, 56, 56, 127, gTitleN64AlphaCounter);
    gDPLoadTLUT_pal16(gDisplayListHead++, 0, texture_nintendo_words_pallete);
    y = 32;

    for (i = 0, x = 16; i < 8; x += 32, i++) {
        gDPLoadTextureBlock_4b(gDisplayListHead++, &texture_nintendo_words_ci4[CI4_TEXTURE_SIZE(32, 32) * i], G_IM_FMT_CI,
            32, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 32) << 2, (y + 32) << 2,
            G_TX_RENDERTILE, 0, 0, (1 << 10), (1 << 10));
    }

    gDPSetEnvColor(gDisplayListHead++, 196, 0, 38, gTitleN64AlphaCounter);
    gDPLoadTLUT_pal16(gDisplayListHead++, 0, texture_64_words_pallete);
    gDPLoadTextureBlock_4b(gDisplayListHead++, texture_64_words_ci4, G_IM_FMT_CI,
        64, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPScisTextureRectangle(gDisplayListHead++, (32 * 8) << 2, (y - 8) << 2, ((32 * 8) + 64) << 2, ((y - 8) + 32) << 2,
        G_TX_RENDERTILE, 0, 0, (1 << 10), (1 << 10));

    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gSPDisplayList(gDisplayListHead++, dl_alo_texrect_block_end);
}

Gfx *geo_intro_n64_logo(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]) {
    struct GraphNode *graphNode;
    Gfx *displayList;
    Gfx *displayListIter;
    Mtx *scaleMat;
    Mtx *transMat;
    Mtx *rotMatX;
    Mtx *rotMatSpin;
    static float scale = 0.001f;
    static float spinLogo = 0.0f;
    graphNode = node;
    displayList = NULL;
    displayListIter = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        graphNode->flags = (graphNode->flags & 0xFF) | (LAYER_OPAQUE << 8);
        scaleMat = alloc_display_list(sizeof(*scaleMat));
        transMat = alloc_display_list(sizeof(*transMat));
        rotMatX = alloc_display_list(sizeof(*rotMatX));
        rotMatSpin = alloc_display_list(sizeof(*rotMatSpin));
        displayList = alloc_display_list(7 * sizeof(*displayList));
        displayListIter = displayList;

        spinLogo += 5.0f;

        if (scale < 0.05f) {
            scale += 0.002;
        } else {
            scale = 0.05f;
        }

        if (gTitleN64MainCounter >= 10) {
            gTitleN64AlphaCounter += 20;
            if (gTitleN64AlphaCounter >= 256) {
                gTitleN64AlphaCounter = 255;
            }
        }

        guScale(scaleMat, scale, scale, scale);
        guTranslate(transMat, 1.0f, -5000.0f, 1.0f);
        guRotate(rotMatX, 20.0f, 1.0f, 0.0f, 0.0f);
        guRotate(rotMatSpin, spinLogo, 0.0f, 1.0f, 0.0f);

        gSPMatrix(displayListIter++, scaleMat, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
        gSPMatrix(displayListIter++, transMat, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
        gSPMatrix(displayListIter++, rotMatX, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        gSPMatrix(displayListIter++, rotMatSpin, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);

        gSPDisplayList(displayListIter++, &dl_intro_n64_logo);
        gSPPopMatrix(displayListIter++, G_MTX_MODELVIEW);

        gSPEndDisplayList(displayListIter);

        gTitleN64MainCounter++;
    }
    return displayList;
}


Gfx *geo_aloxado_logo_screen(s32 callContext, struct GraphNode *node, UNUSED f32 mtx[4][4]) {
    struct GraphNode *graphNode = node;
    static float alpha = 0;
    Gfx *displayList = NULL;
    Gfx *displayListIter = NULL;
    if (callContext == GEO_CONTEXT_RENDER) {
        graphNode->flags = (graphNode->flags & 0xFF) | (LAYER_TRANSPARENT << 8);
        displayList = alloc_display_list(5 * sizeof(*displayList));
        displayListIter = displayList;

        if (alpha < 250) {
            alpha += 15;
        } else {
            alpha = 255;
        }

        gSPDisplayList(displayListIter++, &dl_alo_texrect_block_start);

        gDPSetEnvColor(displayListIter++, 255, 255, 255, alpha);
        gSPDisplayList(displayListIter++, &dl_main_aloxado_intro);

        gSPDisplayList(displayListIter++, &dl_alo_texrect_block_end);
        gSPEndDisplayList(displayListIter);
    }
    return displayList;
}


Gfx *intro_backdrop_one_image(s32 index, s8 *backgroundTable) {
    Mtx *mtx;                         // sp5c
    Gfx *displayList;                 // sp58
    Gfx *displayListIter;             // sp54
    const u8 *const *vIntroBgTable;   // sp50
    s32 i;                            // sp4c
    mtx = alloc_display_list(sizeof(*mtx));
    displayList = alloc_display_list(36 * sizeof(*displayList));
    displayListIter = displayList;
    vIntroBgTable = segmented_to_virtual(introBackgroundTextureType[backgroundTable[index]]);
    guTranslate(mtx, introBackgroundOffsetX[index], introBackgroundOffsetY[index], 0.0f);
    gSPMatrix(displayListIter++, mtx, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPDisplayList(displayListIter++, &title_screen_bg_dl_0A000118);
    for (i = 0; i < 4; ++i) {
        gDPLoadTextureBlock(displayListIter++, vIntroBgTable[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 20, 0,
                            G_TX_CLAMP, G_TX_CLAMP, 7, 6, G_TX_NOLOD, G_TX_NOLOD)
        gSPDisplayList(displayListIter++, introBackgroundDlRows[i]);
    }
    gSPPopMatrix(displayListIter++, G_MTX_MODELVIEW);
    gSPEndDisplayList(displayListIter);
    return displayList;
}

Gfx *geo_intro_backdrop(s32 sp48, struct GraphNode *sp4c, UNUSED void *context) {
    struct GraphNodeMore *graphNode; // sp44
    s32 index;                       // sp40
    s8 *backgroundTable;             // sp3c
    Gfx *displayList;                // sp38
    Gfx *displayListIter;            // sp34
    s32 i;                           // sp30
    graphNode = (struct GraphNodeMore *) sp4c;
    index = graphNode->unk18 & 0xff; // TODO: word at offset 0x18 of struct GraphNode
    backgroundTable = introBackgroundTables[index];
    displayList = NULL;
    displayListIter = NULL;
    if (sp48 == 1) {
        displayList = alloc_display_list(16 * sizeof(*displayList));
        displayListIter = displayList;
        graphNode->node.flags = (graphNode->node.flags & 0xFF) | 0x100;
        gSPDisplayList(displayListIter++, &dl_proj_mtx_fullscreen);
        gSPDisplayList(displayListIter++, &title_screen_bg_dl_0A000100);
        for (i = 0; i < 12; ++i) {
            gSPDisplayList(displayListIter++, intro_backdrop_one_image(i, backgroundTable));
        }
        gSPDisplayList(displayListIter++, &title_screen_bg_dl_0A000190);
        gSPEndDisplayList(displayListIter);
    }
    return displayList;
}

Gfx *geo_game_over_tile(s32 sp40, struct GraphNode *sp44, UNUSED void *context) {
    struct GraphNode *graphNode; // sp3c
    Gfx *displayList;            // sp38
    Gfx *displayListIter;        // sp34
    s32 j;                       // sp30
    s32 i;                       // sp2c
    graphNode = sp44;
    displayList = NULL;
    displayListIter = NULL;
    if (sp40 != 1) {
        gGameOverFrameCounter = 0;
        gGameOverTableIndex = -2;
        for (i = 0; i < (s32) sizeof(gameOverBackgroundTable); ++i) {
            gameOverBackgroundTable[i] = INTRO_BACKGROUND_GAME_OVER;
        }
    } else {
        displayList = alloc_display_list(16 * sizeof(*displayList));
        displayListIter = displayList;
        if (gGameOverTableIndex == -2) {
            if (gGameOverFrameCounter == 180) {
                gGameOverTableIndex++;
                gGameOverFrameCounter = 0;
            }
        } else {
            // transition tile from "Game Over" to "Super Mario 64"
            if (gGameOverTableIndex != 11 && !(gGameOverFrameCounter & 0x1)) {
                gGameOverTableIndex++;
                gameOverBackgroundTable[gameOverBackgroundFlipOrder[gGameOverTableIndex]] =
                    INTRO_BACKGROUND_SUPER_MARIO;
            }
        }
        if (gGameOverTableIndex != 11) {
            gGameOverFrameCounter++;
        }
        graphNode->flags = (graphNode->flags & 0xFF) | 0x100;
        gSPDisplayList(displayListIter++, &dl_proj_mtx_fullscreen);
        gSPDisplayList(displayListIter++, &title_screen_bg_dl_0A000100);
        for (j = 0; j < (s32) sizeof(gameOverBackgroundTable); ++j) {
            gSPDisplayList(displayListIter++, intro_backdrop_one_image(j, gameOverBackgroundTable));
        }
        gSPDisplayList(displayListIter++, &title_screen_bg_dl_0A000190);
        gSPEndDisplayList(displayListIter);
    }
    return displayList;
}
