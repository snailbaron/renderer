#include "geom.hpp"

PixPoint::PixPoint(int x, int y) :
    m_x(x), m_y(y) {}

PixPoint::PixPoint(const PixPoint &pp) :
    m_x(pp.m_x), m_y(pp.m_y) {}

PixPoint::PixPoint(const DepPixPoint &dpp) :
    m_x(dpp.X()), m_y(dpp.Y()) {}

PixPoint::~PixPoint() {}
