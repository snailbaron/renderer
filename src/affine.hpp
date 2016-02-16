#ifndef AFFINE_HPP
#define AFFINE_HPP

#include <initializer_list>

namespace aff {

template <class T, unsigned D> class Vector;


template <class T, unsigned D> class Point
{
public:
    Point() : m_els{0} {}

    Point(std::initializer_list<T> l)
    {
        unsigned i = 0;
        const T *els = l.begin();
        for ( ; i < D && i < l.size(); i++) {
            m_els[i] = els[i];
        }
        for ( ; i < D; i++) {
            m_els[i] = 0;
        }
    }

    Point(const Point &p)
    {
        for (unsigned i = 0; i < D; i++) {
            m_els[i] = p.m_els[i];
        }
    }

    ~Point() {}

    T & operator[](unsigned idx) { return m_els[idx]; }

    Point & operator=(const Point &p)
    {
        if (&p != this) {
            for (unsigned i = 0; i < D; i++) {
                m_els[i] = p.m_els[i];
            }
        }
        return *this;
    }

    Vector<T, D> operator-(const Point<T, D> &p)
    {
        Vector<T, D> v;
        for (unsigned i = 0; i < D; i++) {
            v[i] = m_els[i] - p.m_els[i];
        }
        return v;
    }


private:
    T m_els[D];
};

template <class T, unsigned D> class Vector
{
public:
    Vector() : m_els{0} {}
    ~Vector() {}

    T & operator[](unsigned idx) { return m_els[idx]; }

    T Sqr() const
    {
        T res = 0;
        for (unsigned i = 0; i < D; i++) {
            res += m_els[i] * m_els[i];
        }
        return res;
    }

    Vector<T, D> DirVec(unsigned idx)
    {
        Vector<T, D> dirVec;
        if (m_els[idx] < 0) {
            dirVec[idx] = -1;
        } else {
            dirVec[idx] = 1;
        }
        return dirVec;
    }

    Vector operator*(const Vector &v)
    {
        Vector<T, D> res;
        for (unsigned i = 0; i < D; i++) {
            res[i] = m_els[i] * v.m_els[i];
        }
        return res;
    }
    
private:
    T m_els[D];
};



} // namespace aff

#endif
