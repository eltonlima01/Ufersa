#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        uint8_t r, g, b, a;
    } rgba;
    uint32_t value;
} Color;

void readColorRGBA(Color *color) {
    printf("Digite uma cor no formato RGBA: ");
    scanf("%hhu %hhu %hhu %hhu", &color->rgba.r, &color->rgba.g, &color->rgba.b, &color->rgba.a);
}

void readColorInt32(Color *color) {
    printf("Digite uma cor no formato Int32: ");
    scanf("%u", &color->value);
}

void printColor(const Color *color) {
    printf("RGBA: %u %u %u %u\n", color->rgba.r, color->rgba.g, color->rgba.b, color->rgba.a);
    printf("Int32: %u\n", color->value);
}

int main() {
    Color color;
    
    readColorRGBA(&color);
    printColor(&color);
    
    readColorInt32(&color);
    printColor(&color);
    
    return 0;
}
