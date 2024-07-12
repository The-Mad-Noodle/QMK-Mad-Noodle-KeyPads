// Copyright 2023 The Mad Noodle(@the_mad_noodle)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL + 5

// I2C Settings For OLED
#define I2C1_SCL_PIN GP5
#define I2C1_SDA_PIN GP4
#define I2C_DRIVER I2CD0

// OLED Timeout
#define OLED_TIMEOUT 1800000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 8