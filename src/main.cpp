#include "draw.hpp"
#include "renderer.hpp"
#include "affine.hpp"

int main(int argc, char *argv[])
{
    aff::Point<int, 2> ap0 = { 1, 2 }, ap1 = { 3, 4 };
    aff::Vector<int, 2> av = ap1 - ap0;



    drawInit(800, 600);

    srSetViewport(800, 600);

    DepPixPoint p0(100, 100), p1(300, 110);
    _drawLine(p0, p1);
    
    //srVertex(-0.5f, -0.5f, 0.0f);
    //srVertex(0.5f, -0.6f, 0.0f);
    //srVertex(0.0f, 0.5f, 0.0f);
    //srDrawTriangles();

    drawShow();


    bool done = false;
    while (!done) {
        done = drawProcessEvents();
    }

    drawFinish();

    return 0;
}