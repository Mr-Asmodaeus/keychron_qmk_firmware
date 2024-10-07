#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP_MINV
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_MINV
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_TYPING_HEATMAP_MINV
//#define RGB_MATRIX_BRIGHTNESS_TURN_OFF_VAL 4

#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 192
#define RGB_MATRIX_DEFAULT_VAL 64


#undef USE_CIE1931_CURVE
#define FORCE_NKRO

//#define DYNAMIC_KEYMAP_LAYER_COUNT 8
//#define DYNAMIC_KEYMAP_MACRO_COUNT 32

#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 200

