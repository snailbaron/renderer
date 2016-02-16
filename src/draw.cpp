#include <SDL2/SDL.h>
#include "draw.hpp"
#include "errors.hpp"

static const float PI = (float)M_PI;

static const char WINDOW_TITLE[] = "Window Title";

static SDL_Window *g_window = nullptr;
static SDL_Renderer *g_renderer = nullptr;

static DrawColor g_clearColor(100, 100, 100);

void drawInit(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER)) {
        THROW(SdlException);
    }

    g_window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        0);
    if (!g_window) {
        THROW(SdlException);
    }

    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    if (!g_renderer) {
        THROW(SdlException);
    }
}

void drawFinish()
{
    SDL_Quit();
}

bool drawProcessEvents()
{
    bool wantQuit = false;
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
        switch (evt.type) {
            case SDL_QUIT:
                wantQuit = true;
                break;
        }        
    }
    return wantQuit;
}

void drawPixel(int x, int y, const DrawColor &color)
{
    SDL_SetRenderDrawColor(g_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(g_renderer, x, y);
}

void drawShow()
{
    SDL_RenderPresent(g_renderer);
}

void drawSetClearColor(const DrawColor &color)
{
    g_clearColor = color;
}

void drawClear()
{
    SDL_SetRenderDrawColor(g_renderer, g_clearColor.r, g_clearColor.g, g_clearColor.b, g_clearColor.a);
    SDL_RenderClear(g_renderer);
}

void drawCircle_Trigonometry(int x, int y, float r)
{
    //DrawColor color(255, 0, 255);

    //for (int deg = 1; deg <= 360; deg++) {
    //    float rad = deg * 2 * (float)M_PI / 360;
    //    float xx = cosf(rad);
    //    float yy = sinf(rad);
    //    drawPixel(x + xx * r, y + yy * r, color);
    //}
}

//float cosf_Polynom(float a)
//{
//    while (a > 2.0f * (float)M_PI) {
//        a -= 2.0f * (float)M_PI;
//    }
//    while (a < 0.0f) {
//        a += 2.0f * (float)M_PI;
//    }
//
//    if (a > M_PI) {
//        a = 2 * M_PI - a;
//    }
//
//    float c = 1.0f;
//    if (a > M_PI_2) {
//        c = -1.0f;
//        a = M_PI - a;
//    }
//
//    float res = 1.0 - 0.5f * a * a + 1.0f / 24.0f * a * a * a * a;
//    return res * c;
//}
//
//float sinf_Polynom(float a)
//{
//    return a - 1.0f/6.0f * a * a * a + 1.0f/120.0f * a * a * a * a * a;
//}

void drawCircle_Polynom(int x, int y, float r)
{
    //DrawColor color(255, 0, 255);

    //for (int deg = 1; deg <= 360; deg++) {
    //    float rad = deg * 2 * (float)M_PI / 360;

    //    float xx = cosf_Polynom(rad);
    //    float yy = sinf(rad);
    //    drawPixel(x + xx * r, y + yy * r, color);
    //}
}

void drawCircle_RotationMatrix(int x0, int y0, float r)
{
    //DrawColor color(255, 0, 255);

    //float delta = 2.0 * PI / 360.0;
    //float s = sinf(delta);
    //float c = cosf(delta);

    //float x = 1.0, y = 0.0;
    //for (int i = 0; i < 360; i++) {
    //    float xnew = c * x - s * y;
    //    y = s * x + c * y;
    //    x = xnew;

    //    drawPixel(x0 + x * r, y0 + y * r, color);
    //}
}

void drawCircle_Approx(int x0, int y0, float r)
{
    //DrawColor color(255, 0, 255);

    //float angle = 2 * PI / 360;
    //
    //float x = 1.0f, y = 0.0f;
    //for (int i = 0; i < 360; i++) {
    //    //float xnew = x - angle * y;
    //    //y = angle * x + y;
    //    //x = xnew;

    //    x = x - angle * y;
    //    y = angle * x + y;

    //    drawPixel(x0 + x * r, y0 + y * r, color);
    //}
}