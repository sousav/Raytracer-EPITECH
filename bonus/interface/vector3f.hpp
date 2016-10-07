#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <QString>
#include <math.h>
#include "myxml.h"

template<typename T>
class Vector3f
{
    public:
        T x, y, z;

        Vector3f() : x(T(0)), y(T(0)), z(T(0)) {}
        Vector3f(T xx) : x(xx), y(xx), z(xx) {}
        Vector3f(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
        Vector3f(const QString beg_string, MyXML *file)
        {
            x = file->get_field(((QString(beg_string) + QString("x")).toLatin1().data())).toFloat();
            y = file->get_field(((QString(beg_string) + QString("y")).toLatin1().data())).toFloat();
            z = file->get_field(((QString(beg_string) + QString("z")).toLatin1().data())).toFloat();
        }
        Vector3f &normalize() {
            T nor2 = length2();
            if (nor2 > 0) {
                T invNor = 1 / sqrt(nor2);
                x *= invNor, y *= invNor, z *= invNor;
            }
            return *this;
        }
        static Vector3f<T> cross(const Vector3f<T> &u, const Vector3f<T> &v)
        {
            return Vector3f<T>(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
        }

        Vector3f<T> operator * (const T &f) const {
            return Vector3f<T>(x * f, y * f, z * f);
        }
        Vector3f<T> operator / (const T &f) const {
            return Vector3f<T>(x / f, y / f, z / f);
        }
        Vector3f<T> operator * (const Vector3f<T> &v) const {
            return Vector3f<T>(x * v.x, y * v.y, z * v.z);
        }
        T dot(const Vector3f<T> &v) const {
            return x * v.x + y * v.y + z * v.z;
        }
        Vector3f<T> operator - (const Vector3f<T> &v) const {
            return Vector3f<T>(x - v.x, y - v.y, z - v.z);
        }
        Vector3f<T> operator + (const Vector3f<T> &v) const {
            return Vector3f<T>(x + v.x, y + v.y, z + v.z);
        }
        Vector3f<T>& operator += (const Vector3f<T> &v) {
            x += v.x, y += v.y, z += v.z; return *this;
        }
        Vector3f<T>& operator *= (const Vector3f<T> &v) {
            x *= v.x, y *= v.y, z *= v.z; return *this;
        }
        Vector3f<T> operator - () const {
            return Vector3f<T>(-x, -y, -z);
        }
        T length2() const {
            return x * x + y * y + z * z;
        }
        T length() const {
            return sqrt(length2());
        }

};

#endif // VECTOR3F_H
