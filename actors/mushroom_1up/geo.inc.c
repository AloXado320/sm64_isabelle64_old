// 0x16000E84
const GeoLayout mushroom_1up_geo[] = {
      GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 80),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, mushroom_1up_main_dl),
            GEO_DISPLAY_LIST(LAYER_ALPHA, mushroom_1up_chocolate_dl),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_END(),
};