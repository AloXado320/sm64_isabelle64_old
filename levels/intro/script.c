#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/area.h"
#include "game/level_update.h"
#include "menu/level_select_menu.h"

#include "levels/scripts.h"
#include "levels/menu/header.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/intro/header.h"

// AloXado Logo
const LevelScript level_intro_entry_1_p3[] = {
    INIT_LEVEL(),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),
    CALL(/*arg*/ 2, /*func*/ lvl_intro_update),

    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_geo_aloxado_logo),
    END_AREA(),
    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 1),

    SLEEP(/*frames*/ 65),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 12, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 12),
    CMD2A(/*unk2*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 4),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_2),
};

// N64 Logo
const LevelScript level_intro_entry_1_p2[] = {
    INIT_LEVEL(),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),
    CALL(/*arg*/ 1, /*func*/ lvl_intro_update),

    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_geo_n64_logo),
    END_AREA(),
    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 1),

    SLEEP(/*frames*/ 105),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 12, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 12),
    CALL(/*arg*/ 3, /*func*/ lvl_intro_update),
    CMD2A(/*unk2*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 4),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_1_p3),
};

// Text Intro
const LevelScript level_intro_entry_1_p1[] = {
    INIT_LEVEL(),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),
    CALL(/*arg*/ 0, /*func*/ lvl_intro_update),

    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_geo_text_intro),
    END_AREA(),
    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 1),

    SLEEP(/*frames*/ 70),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 12, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 12),
    CALL(/*arg*/ 3, /*func*/ lvl_intro_update),
    CMD2A(/*unk2*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 4),

    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_1_p2),


};

const LevelScript level_intro_entry_1[] = {
    JUMP_LINK(level_intro_entry_1_p1),
};

const LevelScript level_intro_entry_2[] = {
    INIT_LEVEL(),
    BLACKOUT(/*active*/ TRUE),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd), // this needs to stay or else game crashes loading next demo
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    ALLOC_LEVEL_POOL(),

    FREE_LEVEL_POOL(),
    SLEEP(/*frames*/ 2),
    BLACKOUT(/*active*/ FALSE),

    CLEAR_DEMO_PTR(), // we need to do this or else file select will be tainted with inputs
    GET_OR_SET(/*op*/ OP_GET, /*var*/ 5),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ 1, script_intro_L1), // was start pressed when demo ended last time?

    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_STAR, /*time*/ 20, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 10),
    SET_MENU_MUSIC(/*seq*/ 0x0002),

    ADV_DEMO(), // # advance the demo ID manually with a new command which sets the level as script register
    JUMP(script_intro_L4), // go to ingame
};

const LevelScript level_intro_entry_3[] = {
    JUMP(level_intro_entry_2),
};

const LevelScript level_intro_entry_4[] = {
    INIT_LEVEL(),
    LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_MIO0_TEXTURE(/*seg*/ 0x0A, _title_screen_bg_mio0SegmentRomStart, _title_screen_bg_mio0SegmentRomEnd),
    LOAD_MIO0(/*seg*/ 0x07, _debug_level_select_mio0SegmentRomStart, _debug_level_select_mio0SegmentRomEnd),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    ALLOC_LEVEL_POOL(),

    AREA(/*index*/ 1, intro_geo_000414),
    END_AREA(),
    CLEAR_DEMO_PTR(),

    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 1),
    SET_MENU_MUSIC(/*seq*/ 0x0002),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CALL_LOOP(/*arg*/ 4, /*func*/ lvl_intro_update),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ -1, script_intro_L5),
    JUMP(script_intro_L3),
};

// These should be static, but C doesn't allow non-sized forward declarations of static arrays

const LevelScript script_intro_L1[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    SET_REG(/*value*/ 16),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _menuSegmentRomStart, _menuSegmentRomEnd, level_main_menu_entry_1),
};

const LevelScript script_intro_L2[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_4),
};

const LevelScript script_intro_L3[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x15, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript script_intro_L4[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x15, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript script_intro_L5[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ 0x14, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_1),
};
