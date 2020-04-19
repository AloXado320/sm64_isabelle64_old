const GeoLayout yellow_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 85),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_ALPHA, sm64ds_yellow_coin_dl),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

const GeoLayout yellow_coin_no_shadow_geo[] = {
   GEO_BRANCH(1, yellow_coin_geo),
   GEO_END(),
};

const GeoLayout blue_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 85),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_ALPHA, sm64ds_blue_coin_dl),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

const GeoLayout blue_coin_no_shadow_geo[] = {
   GEO_BRANCH(1, blue_coin_geo),
   GEO_END(),
};

const GeoLayout red_coin_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 85),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_ALPHA, sm64ds_red_coin_dl),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

const GeoLayout red_coin_no_shadow_geo[] = {
   GEO_BRANCH(1, red_coin_geo),
   GEO_END(),
};
