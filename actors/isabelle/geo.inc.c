#define LAYER_SHZ_SILLOUETE LAYER_8_CUSTOM

const GeoLayout geo_isabelle_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),

      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(), // geo_switch_mario_cap_on_off ENABLE
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_dl),
      GEO_CLOSE_NODE(), // geo_switch_mario_cap_on_off DISABLE

      GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
      GEO_OPEN_NODE(), // geo_switch_mario_eyes ENABLE
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_open_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_halfclosed_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_closed_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_angry_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_sad_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_happy_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_surprised_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_worried_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_verysurprised_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_eyes_dizzy_dl),
      GEO_CLOSE_NODE(), // geo_switch_mario_eyes DISABLE

      GEO_SWITCH_CASE(0, geo_switch_isabelle_mouth),
      GEO_OPEN_NODE(), // geo_switch_isabelle_mouth ENABLE
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_mouth_closed_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_mouth_smile_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_mouth_bigsmile_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_mouth_sad_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_mouth_open_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_face_mouth_veryopen_dl),
      GEO_CLOSE_NODE(), // geo_switch_isabelle_mouth DISABLE

      GEO_TRANSLATE_ROTATE(0, -93, -132, -118, 15, -33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, isabelle_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, -93, -132, 118, -15, 33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, isabelle_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const GeoLayout geo_isabelle_vanish_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),

      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(), // geo_switch_mario_cap_on_off ENABLE
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_dl),
      GEO_CLOSE_NODE(), // geo_switch_mario_cap_on_off DISABLE

      GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
      GEO_OPEN_NODE(), // geo_switch_mario_eyes ENABLE
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_open_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_halfclosed_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_closed_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_angry_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_sad_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_happy_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_surprised_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_worried_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_verysurprised_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_eyes_dizzy_dl),
      GEO_CLOSE_NODE(), // geo_switch_mario_eyes DISABLE

      GEO_SWITCH_CASE(0, geo_switch_isabelle_mouth),
      GEO_OPEN_NODE(), // geo_switch_isabelle_mouth ENABLE
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_mouth_closed_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_mouth_smile_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_mouth_bigsmile_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_mouth_sad_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_mouth_open_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_face_mouth_veryopen_dl),
      GEO_CLOSE_NODE(), // geo_switch_isabelle_mouth DISABLE

      GEO_TRANSLATE_ROTATE(0, -93, -132, -118, 15, -33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_wings_transparent), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, -93, -132, 118, -15, 33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_wings_transparent), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const uintptr_t geo_isabelle_metal_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_metal_face_dl),
         GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_metal_face_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, -93, -132, -118, 15, -33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, isabelle_metal_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, -93, -132, 118, -15, 33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, isabelle_metal_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

const uintptr_t geo_isabelle_metal_vanish_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_face_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_face_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, -93, -132, -118, 15, -33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_wings_transparent), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, -93, -132, 118, -15, 33, -133),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_wings_transparent), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};


const GeoLayout geo_isabelle_left_hand[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 59, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_mario_hand_foot_scaler),
			GEO_SCALE(0, 65536),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout geo_isabelle_right_hand[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(1, 59, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_mario_hand_foot_scaler),
			GEO_SCALE(0, 65536),
			GEO_HELD_OBJECT(0, 0, 0, 0, geo_switch_mario_hand_grab_pos),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout geo_isabelle_body[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, -21, 0, 0, isabelle_tail), // butt (Isabelle: Tail)
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_move_mario_part_from_parent),
				GEO_ASM(0, geo_mario_tilt_torso),
				GEO_ROTATION_NODE(0, 0, 0, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 21, 0, 0, isabelle_body), // torso (Isabelle: Body)
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 175, 0, 0, NULL),
						GEO_OPEN_NODE(),
                            GEO_BRANCH(1, geo_isabelle_face_and_wings), // head
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 125, 1, 66, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_left_arm), // left arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_skinned_left_arm), // skinned left arm with left forearm
								GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 64, 0, 0, isabelle_left_forearm), // left forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(1, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_left_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 126, 1, -67, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_right_arm), // right arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_skinned_right_arm), // skinned right arm with right forearm
								GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 65, 0, 0, isabelle_right_forearm), // right forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(0, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_right_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, -34, -9, 31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_left_thigh), // left thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_skinned_left_thigh), // skinned left thigh with left leg
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 70, 0, 0, isabelle_left_leg), // left leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 63, 0, 0, isabelle_left_foot), // Isabelle doesn't have foot so it's a stub dl
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, -34, 1, -31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_right_thigh), // right thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_skinned_right_thigh), // skinned right thigh with right leg
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 70, 0, 0, isabelle_right_leg), // right leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 63, 0, 0, NULL),
							GEO_OPEN_NODE(),
								GEO_ASM(2, geo_mario_hand_foot_scaler),
								GEO_SCALE(0, 65536),
								GEO_OPEN_NODE(),
									GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_right_foot), // Isabelle doesn't have foot so it's a stub dl
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout geo_isabelle_vanish_body[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT, -21, 0, 0, isabelle_tail), // butt (Isabelle: Tail)
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_move_mario_part_from_parent),
				GEO_ASM(0, geo_mario_tilt_torso),
				GEO_ROTATION_NODE(0, 0, 0, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 21, 0, 0, isabelle_body), // torso (Isabelle: Body)
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, NULL),
						GEO_OPEN_NODE(),
                            GEO_BRANCH(1, geo_isabelle_vanish_face_and_wings), // head
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 125, 1, 66, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_left_arm), // left arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_skinned_left_arm), // skinned left arm with left forearm
								GEO_ANIMATED_PART(LAYER_TRANSPARENT, 64, 0, 0, isabelle_left_forearm), // left forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(1, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_left_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 126, 1, -67, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_right_arm), // right arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_skinned_right_arm), // skinned right arm with right forearm
								GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, isabelle_right_forearm), // right forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(0, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_right_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, -34, -9, 31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_left_thigh), // left thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_skinned_left_thigh), // skinned left thigh with left leg
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 70, 0, 0, isabelle_left_leg), // left leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 63, 0, 0, isabelle_left_foot), // Isabelle doesn't have foot so it's a stub dl
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, -34, 1, -31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_right_thigh), // right thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_skinned_right_thigh), // skinned right thigh with right leg
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 70, 0, 0, isabelle_right_leg), // right leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 63, 0, 0, NULL),
							GEO_OPEN_NODE(),
								GEO_ASM(2, geo_mario_hand_foot_scaler),
								GEO_SCALE(0, 65536),
								GEO_OPEN_NODE(),
									GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_right_foot), // Isabelle doesn't have foot so it's a stub dl
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout geo_isabelle_metal_body[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, -21, 0, 0, isabelle_metal_tail), // butt (Isabelle: Tail)
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_move_mario_part_from_parent),
				GEO_ASM(0, geo_mario_tilt_torso),
				GEO_ROTATION_NODE(0, 0, 0, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 21, 0, 0, isabelle_metal_body), // torso (Isabelle: Body)
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 175, 0, 0, NULL),
						GEO_OPEN_NODE(),
                            GEO_BRANCH(1, geo_isabelle_metal_face_and_wings), // head
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 125, 1, 66, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_metal_left_arm), // left arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_metal_skinned_left_arm), // skinned left arm with left forearm
								GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 64, 0, 0, isabelle_metal_left_forearm), // left forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(1, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_left_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 126, 1, -67, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_metal_right_arm), // right arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_metal_skinned_right_arm), // skinned right arm with right forearm
								GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 65, 0, 0, isabelle_metal_right_forearm), // right forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(0, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_right_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, -34, -9, 31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_metal_left_thigh), // left thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_metal_skinned_left_thigh), // skinned left thigh with left leg
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 70, 0, 0, isabelle_metal_left_leg), // left leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 63, 0, 0, isabelle_metal_left_foot), // Isabelle doesn't have foot so it's a stub dl
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, -34, 1, -31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 0, 0, 0, isabelle_metal_right_thigh), // right thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_metal_skinned_right_thigh), // skinned right thigh with right leg
						GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 70, 0, 0, isabelle_metal_right_leg), // right leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_SHZ_SILLOUETE, 63, 0, 0, NULL),
							GEO_OPEN_NODE(),
								GEO_ASM(2, geo_mario_hand_foot_scaler),
								GEO_SCALE(0, 65536),
								GEO_OPEN_NODE(),
									GEO_DISPLAY_LIST(LAYER_SHZ_SILLOUETE, isabelle_metal_right_foot), // Isabelle doesn't have foot so it's a stub dl
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout geo_isabelle_metal_vanish_body[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT, -21, 0, 0, isabelle_metal_tail), // butt (Isabelle: Tail)
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_move_mario_part_from_parent),
				GEO_ASM(0, geo_mario_tilt_torso),
				GEO_ROTATION_NODE(0, 0, 0, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 21, 0, 0, isabelle_metal_body), // torso (Isabelle: Body)
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 175, 0, 0, NULL),
						GEO_OPEN_NODE(),
                            GEO_BRANCH(1, geo_isabelle_metal_vanish_face_and_wings), // head
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 125, 1, 66, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_metal_left_arm), // left arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_skinned_left_arm), // skinned left arm with left forearm
								GEO_ANIMATED_PART(LAYER_TRANSPARENT, 64, 0, 0, isabelle_metal_left_forearm), // left forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(1, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_left_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 126, 1, -67, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_metal_right_arm), // right arm
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_skinned_right_arm), // skinned right arm with right forearm
								GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, isabelle_metal_right_forearm), // right forearm
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(0, geo_switch_mario_hand),
									GEO_OPEN_NODE(),
										GEO_BRANCH(1, geo_isabelle_right_hand), // Isabelle doesn't have hands so it's a stub geo
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, -34, -9, 31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_metal_left_thigh), // left thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_skinned_left_thigh), // skinned left thigh with left leg
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 70, 0, 0, isabelle_metal_left_leg), // left leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 63, 0, 0, isabelle_metal_left_foot), // Isabelle doesn't have foot so it's a stub dl
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, -34, 1, -31, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, isabelle_metal_right_thigh), // right thigh
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_skinned_right_thigh), // skinned right thigh with right leg
						GEO_ANIMATED_PART(LAYER_TRANSPARENT, 70, 0, 0, isabelle_metal_right_leg), // right leg
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_TRANSPARENT, 63, 0, 0, NULL),
							GEO_OPEN_NODE(),
								GEO_ASM(2, geo_mario_hand_foot_scaler),
								GEO_SCALE(0, 65536),
								GEO_OPEN_NODE(),
									GEO_DISPLAY_LIST(LAYER_TRANSPARENT, isabelle_metal_right_foot), // Isabelle doesn't have foot so it's a stub dl
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

const GeoLayout geo_isabelle_load[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, geo_isabelle_body),
            GEO_BRANCH(1, geo_isabelle_vanish_body), // vanish
            GEO_BRANCH(1, geo_isabelle_metal_body), // metal
            GEO_BRANCH(1, geo_isabelle_metal_vanish_body), // metal vanish
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};

// geo_isabelle
const GeoLayout mario_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(SHADOW_CIRCLE_PLAYER, 0x96, 80),
		GEO_OPEN_NODE(),
			GEO_SCALE(0x00, 16000),
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_mirror_mario_backface_culling),
				GEO_ASM(0, geo_mirror_mario_set_alpha),
				GEO_SWITCH_CASE(0, geo_switch_mario_stand_run),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, geo_isabelle_load),
				GEO_CLOSE_NODE(),
				GEO_ASM(1, geo_mirror_mario_backface_culling),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#undef LAYER_SHZ_SILLOUETE
