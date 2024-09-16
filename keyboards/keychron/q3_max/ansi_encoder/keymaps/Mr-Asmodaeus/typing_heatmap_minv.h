#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP_MINV)
RGB_MATRIX_EFFECT(TYPING_HEATMAP_MINV)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// A timer to track the last time we decremented all heatmap values.
static uint16_t heatmap_decrease_timer;
// Whether we should decrement the heatmap values during the next update.
static bool decrease_heatmap_values;

bool TYPING_HEATMAP_MINV(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb_min = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);

    if (params->init) {
        g_rgb_matrix_mode_uses_typing_heatmap = true;
        rgb_matrix_set_color_all(rgb_min.r, rgb_min.g, rgb_min.b);
        memset(g_rgb_frame_buffer, 0, sizeof g_rgb_frame_buffer);
    }

    // The heatmap animation might run in several iterations depending on
    // `RGB_MATRIX_LED_PROCESS_LIMIT`, therefore we only want to update the
    // timer when the animation starts.
    if (params->iter == 0) {
        decrease_heatmap_values = timer_elapsed(heatmap_decrease_timer) >= RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS;

        // Restart the timer if we are going to decrease the heatmap this frame.
        if (decrease_heatmap_values) {
            heatmap_decrease_timer = timer_read();
        }
    }

    // Render heatmap & decrease
    uint8_t count = 0;
    for (uint8_t row = 0; row < MATRIX_ROWS && count < RGB_MATRIX_LED_PROCESS_LIMIT; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS && RGB_MATRIX_LED_PROCESS_LIMIT; col++) {
            if (g_led_config.matrix_co[row][col] >= led_min && g_led_config.matrix_co[row][col] < led_max) {
                count++;
                uint8_t val = g_rgb_frame_buffer[row][col];
                if (!HAS_ANY_FLAGS(g_led_config.flags[g_led_config.matrix_co[row][col]], params->flags)) continue;

                HSV hsv = {170 - qsub8(val, 85), (val < RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP)? 0 : rgb_matrix_config.hsv.s, max((qadd8(170, val) - 170) * 3, rgb_matrix_config.hsv.v)};
                RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
                rgb_matrix_set_color(g_led_config.matrix_co[row][col], rgb.r, rgb.g, rgb.b);

                if (decrease_heatmap_values) {
                    g_rgb_frame_buffer[row][col] = qsub8(val, 1);
                }
            }
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
