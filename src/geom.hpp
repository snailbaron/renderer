#ifndef GEOM_HPP
#define GEOM_HPP

class DepPixPoint;

class PixPoint
{
public:
    PixPoint(int x=0, int y=0);
    PixPoint(const PixPoint &pp);
    PixPoint(const DepPixPoint &dpp);
    ~PixPoint();

    

private:
    int m_x, m_y;
};


class DepPixPoint
{
public:
    DepPixPoint(int x=0, int y=0, float z=0.0f) : m_x(x), m_y(y), m_z(z) {}
    DepPixPoint(const DepPixPoint &dp) : m_x(dp.m_x), m_y(dp.m_y), m_z(dp.m_z) {}
    ~DepPixPoint() {}

    int X() const { return m_x; }
    int Y() const { return m_y; }
    float Z() const { return m_z; }

private:
    int m_x, m_y;
    float m_z;
};








class GenVert
{
public:
    GenVert(float x=0.0f, float y=0.0f, float z=0.0f, float w=1.0f) : m_els{x, y, z, w} {}
    GenVert(const GenVert &gv) : m_els{gv.m_els[0], gv.m_els[1], gv.m_els[2], gv.m_els[3]} {}
    ~GenVert() {}

    float X() const { return m_els[0]; }
    float Y() const { return m_els[1]; }
    float Z() const { return m_els[2]; }
    float W() const { return m_els[3]; }

private:
    float m_els[4];
};

class Vert
{
public:
    Vert(float x=0.0f, float y=0.0f, float z=0.0f) : m_els{x, y, z} {}
    Vert(const Vert &v) : m_els{v.m_els[0], v.m_els[1], v.m_els[2]} {}
    Vert(const GenVert &gv) : m_els{ gv.X() / gv.W(), gv.Y() / gv.W(), gv.Z() / gv.W() } {}
    ~Vert() {}

    float X() const { return m_els[0]; }
    float Y() const { return m_els[1]; }
    float Z() const { return m_els[2]; }

private:
    float m_els[3];
};


#endif
