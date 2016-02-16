#ifndef DRAW_HPP
#define DRAW_HPP

#include <cstdint>

struct DrawColor
{
    uint8_t r, g, b, a;
    DrawColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255) : r(red), g(green), b(blue), a(alpha) {}
};

const DrawColor DRAW_COLOR_RED = DrawColor(255, 0, 0);

void drawInit(int width, int height);
void drawFinish();

bool drawProcessEvents();
void drawShow();
void drawClear();

void drawPixel(int x, int y, const DrawColor &color);

void drawCircle_Trigonometry(int x, int y, float r);
void drawCircle_Polynom(int x, int y, float r);
void drawCircle_RotationMatrix(int x, int y, float r);
void drawCircle_Approx(int x0, int y0, float r);

#endif