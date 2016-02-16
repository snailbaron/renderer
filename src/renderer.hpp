#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "geom.hpp"

void srSetViewport(int width, int height);

void srVertex(float x, float y, float z=0.0f, float w=1.0f);

void _drawLine(DepPixPoint p0, DepPixPoint p1);

void srDrawTriangles();

#endif
