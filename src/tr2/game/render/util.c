#include "game/render/util.h"

RGBA_8888 Render_ARGB1555To8888(const uint16_t argb1555)
{
    // Extract 5-bit values for each ARGB component
    uint8_t a1 = (argb1555 >> 15) & 0x01;
    uint8_t r5 = (argb1555 >> 10) & 0x1F;
    uint8_t g5 = (argb1555 >> 5) & 0x1F;
    uint8_t b5 = argb1555 & 0x1F;

    // Expand 5-bit color components to 8-bit
    uint8_t a8 = a1 * 255; // 1-bit alpha (either 0 or 255)
    uint8_t r8 = (r5 << 3) | (r5 >> 2);
    uint8_t g8 = (g5 << 3) | (g5 >> 2);
    uint8_t b8 = (b5 << 3) | (b5 >> 2);

    return (RGBA_8888) {
        .r = r8,
        .g = g8,
        .b = b8,
        .a = a8,
    };
}
