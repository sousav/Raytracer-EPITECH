#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector3f.hpp"
#include "object.h"
#include "camera.h"

class Triangle : public Object
{
    public:
        Triangle();
        Triangle(const Vector3f<float> point1, const Vector3f<float> point2, const Vector3f<float> point3, Material *mat, QString name);

        virtual bool            hit(const Camera ray, float &old_dist);
        virtual Vector3f<float> getNormale(const Camera ray, const Vector3f<float> hitPoint);
        virtual Vector3f<float> getObjectColor(const Vector3f<float> hitPoint);
        virtual QString         getObjectType();
        Vector3f<float>point[3];
};

#endif // TRIANGLE_H
