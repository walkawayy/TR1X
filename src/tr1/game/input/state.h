#pragma once

#include <stdint.h>

typedef union INPUT_STATE {
    uint64_t any;
    struct {
        uint64_t forward : 1;
        uint64_t back : 1;
        uint64_t left : 1;
        uint64_t right : 1;
        uint64_t jump : 1;
        uint64_t draw : 1;
        uint64_t action : 1;
        uint64_t slow : 1;
        uint64_t option : 1;
        uint64_t look : 1;
        uint64_t step_left : 1;
        uint64_t step_right : 1;
        uint64_t roll : 1;
        uint64_t pause : 1;
        uint64_t save : 1;
        uint64_t load : 1;
        uint64_t fly_cheat : 1;
        uint64_t item_cheat : 1;
        uint64_t level_skip_cheat : 1;
        uint64_t turbo_cheat : 1;
        uint64_t camera_up : 1;
        uint64_t camera_down : 1;
        uint64_t camera_forward : 1;
        uint64_t camera_back : 1;
        uint64_t camera_left : 1;
        uint64_t camera_right : 1;
        uint64_t camera_reset : 1;
        uint64_t equip_pistols : 1;
        uint64_t equip_shotgun : 1;
        uint64_t equip_magnums : 1;
        uint64_t equip_uzis : 1;
        uint64_t use_small_medi : 1;
        uint64_t use_big_medi : 1;
        uint64_t toggle_bilinear_filter : 1;
        uint64_t toggle_perspective_filter : 1;
        uint64_t toggle_fps_counter : 1;
        uint64_t menu_up : 1;
        uint64_t menu_down : 1;
        uint64_t menu_left : 1;
        uint64_t menu_right : 1;
        uint64_t menu_confirm : 1;
        uint64_t menu_back : 1;
        uint64_t enter_console : 1;
        uint64_t change_target : 1;
        uint64_t toggle_ui : 1;
        uint64_t toggle_photo_mode : 1;
    };
} INPUT_STATE;
