#include <vector>
#include <cassert>
#include <algorithm>
#include "draw.hpp"
#include "geom.hpp"
#include "affine.hpp"

static std::vector<GenVert> g_vertices;

// Clipping space to NDC transformation parameters
static float g_ndcWidth;
static float g_ndcHeight;
static float g_ndcSx = 1.0f;
static float g_ndcDx = 0.0f;
static float g_ndcSy = -1.0f;
static float g_ndcDy = 0.0f;

// Screen parameters
static int g_scrWidth;
static int g_scrHeight;

void srSetViewport(int width, int height)
{
    float W, H;
    if (width >= height) {
        H = 1.0f;
        W = (float)width / height;
    } else {
        W = 1.0f;
        H = (float)height / width;
    }

    g_ndcWidth = W;
    g_ndcHeight = H;
    g_ndcSx = W / 2.0f;
    g_ndcDx = W / 2.0f;
    g_ndcSy = -H / 2.0f;
    g_ndcDy = H / 2.0f;

    g_scrWidth = width;
    g_scrHeight = height;
}


Vert _vertexToNdc(const GenVert &gv)
{
    Vert n(gv);

    float ndcX = g_ndcSx * n.X() + g_ndcDx;
    float ndcY = g_ndcSy * n.Y() + g_ndcDy;

    return Vert(ndcX, ndcY, n.Z());
}


/*
  NDC to pixel coordinates transformation

  | 0 | 1 | 2 | ... | N-2 | N-1 |       <-- Pixel coordinates
  ^                             ^
  0                             W       <-- NDC

*/
DepPixPoint _ndcToPixel(const Vert &n)
{
    int px;
    if (n.X() == g_ndcWidth) {
        px = g_scrWidth - 1;
    } else {
        px = (int)(n.X() * g_scrWidth / g_ndcWidth);
    }

    int py;
    if (n.Y() == g_ndcHeight) {
        py = g_scrHeight;
    } else {
        py = (int)(n.Y() * g_scrHeight / g_ndcHeight);
    }

    return DepPixPoint(px, py, n.Z());
}

DepPixPoint _vertexToPixel(const GenVert &gv)
{
    return _ndcToPixel(_vertexToNdc(gv));
}


void srClear()
{
    g_vertices.clear();
}

void srVertex(float x, float y, float z=0.0f, float w=1.0f)
{
    g_vertices.push_back(GenVert(x, y, z, w));
}

void _drawLine(DepPixPoint p0, DepPixPoint p1)
{
    aff::Point<int, 2> v0 = { p0.X(), p0.Y() }, v1 = { p1.X(), p1.Y() };
    aff::Vector<int, 2> dv = v1 - v0;

    aff::Vector<int, 2> d1, d2;
    if (abs(dv[0]) >= abs(dv[1])) {
        d1 = dv.DirVec(0);
        d2 = dv.DirVec(1);
    } else {
        d1 = dv.DirVec(1);
        d2 = dv.DirVec(0);
    }
        
    




/*
    int dx = p1.X() - p0.X(), dy = p1.Y() - p0.Y();
    int adx = abs(dx), ady = abs(dy);

    int d1x = 0, d1y = 0, d2x = 0, d2y = 0;
    if (adx >= ady) {
        d1x = dx / adx;
        d2y = dy;
        if (ady > 0) {
            d2y /= ady;
        } else {
            d2y = 1;
        }
    } else {
        d1y = dy / ady;
        d2x = dx;
        if (adx > 0) {
            d2x /= adx;
        } else {
            d2x = 1;
        }
    }

    int dir = dx * d2y - dy * d2x;
    dir /= abs(dir);
    int nx = -dy * dir;
    int ny = dx * dir;

    int k = dx * d1x + dy * d1y;
    int x = p0.X(), y = p0.Y();
    int err = 0;
    for (int i = 0; i < k; i++) {
        x += d1x;
        y += d1y;

        if (err < 0) {
            x += d2x;
            y += d2y;
            err += nx * d2x + ny * d2y;
        }
        err += nx * d1x + ny * d1y;

        drawPixel(x, y, DRAW_COLOR_RED);
    }
*/
}

void srDrawTriangles()
{
    size_t n = g_vertices.size() / 3;
    for (size_t i = 0; i < n; i++) {
        GenVert vs[3] = { g_vertices[3*i], g_vertices[3*i+1], g_vertices[3*i+2] };

        //float minX = vs[0].x, maxX = vs[0].x, minY = vs[0].y, maxY = vs[0].y;
        //for (int i = 1; i < 3; i++) {
        //    if (vs[i].x < minX) minX = vs[i].x;
        //    if (vs[i].x > maxX) maxX = vs[i].x;
        //    if (vs[i].y < minY) minY = vs[i].y;
        //    if (vs[i].y > maxY) maxY = vs[i].y;
        //}

        DepPixPoint ps[3];
        for (int i = 0; i < 3; i++) {
            ps[i] = _vertexToPixel(vs[i]);
        }

        _drawLine(ps[0], ps[1]);
        _drawLine(ps[1], ps[2]);
        _drawLine(ps[2], ps[0]);    

    }
}