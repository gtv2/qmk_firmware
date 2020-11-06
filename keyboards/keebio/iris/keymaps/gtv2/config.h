/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C

#define EE_HANDS
// #define MASTER_LEFT
// #define MASTER_RIGHT

#define GRAVE_ESC_ALT_OVERRIDE   //Always send Escape if Alt is pressed
#define GRAVE_ESC_CTRL_OVERRIDE  //Always send Escape if Control is pressed
#define GRAVE_ESC_GUI_OVERRIDE   //Always send Escape if GUI is pressed
// #define GRAVE_ESC_SHIFT_OVERRIDE //Always send Escape if Shift is pressed

#define TAPPING_TERM 200

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 4
//#define BACKLIGHT_BREATHING 

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLED_NUM 12  // Number of LEDs
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT { 6, 6 }
#    define RGB_DI_PIN D6

#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 32
#    define RGBLIGHT_VAL_STEP 32
#    define RGBLIGHT_LIMIT_VAL 128

#    undef RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_EFFECT_SNAKE 
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_ALTERNATING //?
//#    define RGBLIGHT_EFFECT_CHRISTMAS //no
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD //maybe
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL //no
//#    define RGBLIGHT_EFFECT_RGB_TEST //yes
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT //no
//#    define RGBLIGHT_EFFECT_TWINKLE //?

//#    define RGBLIGHT_EFFECT_BREATHE_CENTER      //If defined, used to calculate the curve for the breathing animation. Valid values are 1.0 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX 224       //The maximum brightness for the breathing mode. Valid values are 1 to 255
//#    define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL  //How long (in milliseconds) to wait between animation steps for the “Christmas” animation
//#    define RGBLIGHT_EFFECT_CHRISTMAS_STEP      //The number of LEDs to group the red/green colors by for the “Christmas” animation
//#    define RGBLIGHT_EFFECT_KNIGHT_LED_NUM      //The number of LEDs to have the “Knight” animation travel
//#    define RGBLIGHT_EFFECT_KNIGHT_LENGTH       //The number of LEDs to light up for the “Knight” animation
//#    define RGBLIGHT_EFFECT_KNIGHT_OFFSET       //The number of LEDs to start the “Knight” animation from the start of the strip by
//#    define RGBLIGHT_RAINBOW_SWIRL_RANGE        //Range adjustment for the rainbow swirl effect to get different swirls
//#    define RGBLIGHT_EFFECT_SNAKE_LENGTH 12       //The number of LEDs to light up for the “Snake” animation
//#    define RGBLIGHT_EFFECT_TWINKLE_LIFE        //Adjusts how quickly each LED brightens and dims when twinkling (in animation steps)
//#    define RGBLIGHT_EFFECT_TWINKLE_PROBABILITY //Adjusts how likely each LED is to twinkle (on each animation step)

#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_MAX_LAYERS 6
#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#endif  // RGBLIGHT_ENABLE

//#define SWAP_SCLN
//#define TAPPING_TERM 300
//#define IGNORE_MOD_TAP_INTERRUPT