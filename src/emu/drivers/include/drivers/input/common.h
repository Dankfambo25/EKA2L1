/*
 * Copyright (c) 2019 EKA2L1 Team.
 * 
 * This file is part of EKA2L1 project.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <common/vecx.h>

namespace eka2l1::drivers {
    enum class input_event_type {
        none,
        key,
        touch,
        button
    };

    enum class key_state {
        pressed,
        released,
        repeat
    };

    enum class button_state {
        pressed,
        released
    };

    enum class mouse_button {
        left,
        middle,
        right
    };

    enum class mouse_action {
        press,
        repeat,
        release
    };

    /**
     * Event for key press/key release.
     */
    struct key_event {
        int code_;
        key_state state_;
    };

    /**
     * Event for controller button press/release.
     */
    struct button_event {
        int controller_;
        int button_;
        button_state state_;
    };

    /**
     * Event for mouse 0/1/2 button press/move/release.
     */
    struct mouse_event {
        int pos_x_, pos_y_;
        mouse_button button_;
        mouse_action action_;
    };

    struct input_event {
        input_event_type type_;
        std::uint64_t time_;

        union {
            key_event key_;
            mouse_event mouse_;
            button_event button_;
        };
    };
}