
#ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
bool g_rgb_matrix_mode_uses_typing_heatmap = false;
#endif // ENABLE_RGB_MATRIX_TYPING_HEATMAP


void process_rgb_matrix_typing_heatmap (uint8_t row, uint8_t col, bool pressed) {
#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
#    if defined(RGB_MATRIX_KEYRELEASES)
    if (!pressed)
#    else
    if (pressed)
#    endif // defined(RGB_MATRIX_KEYRELEASES)
    {
        if (g_rgb_matrix_mode_uses_typing_heatmap || rgb_matrix_config.mode == RGB_MATRIX_TYPING_HEATMAP) {
            process_rgb_matrix_typing_heatmap(row, col);
        }
    }
#endif // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
}
