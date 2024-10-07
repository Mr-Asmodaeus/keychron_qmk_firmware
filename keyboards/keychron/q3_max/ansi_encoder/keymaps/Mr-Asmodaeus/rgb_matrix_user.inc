// !!! DO NOT ADD #pragma once !!! //


#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#   ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#       ifndef TYPING_HEATMAP_MODE_FLAG
#           define TYPING_HEATMAP_MODE_FLAG
bool g_rgb_matrix_mode_uses_typing_heatmap = false;
#       endif // TYPING_HEATMAP_MODE_FLAG
#   endif // ENABLE_RGB_MATRIX_TYPING_HEATMAP




void process_rgb_matrix_typing_heatmap_user (uint8_t row, uint8_t col, bool pressed) {
#   if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
#       if defined(RGB_MATRIX_KEYRELEASES)
    if (!pressed)
#       else
    if (pressed)
#       endif // defined(RGB_MATRIX_KEYRELEASES)
    {
        if (g_rgb_matrix_mode_uses_typing_heatmap ) {
            process_rgb_matrix_typing_heatmap(row, col);
        }
    }
#   endif // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
}
#endif //RGB_MATRIX_CUSTOM_EFFECT_IMPLS




#define RGB_MATRIX_TYPING_HEATMAP_SLIM
#define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 64
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50

#include "typing_heatmap_minv.h"

#include "solid_reactive_simple_anim_minv.h"



