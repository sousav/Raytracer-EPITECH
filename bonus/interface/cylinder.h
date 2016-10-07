#ifndef CYLINDER_H
#define CYLINDER_H

#include "vector3f.hpp"
#include "camera.h"

class Cylinder : public Object
{
    public:
        Cylinder();
        Cylinder(const Vector3f<float> center, const Vector3f<float> direction, const float radius, const float height, Material *mat, QString name);
        Vector3f<float> direction;
        float       radius;
        float       height;

        virtual bool            hit(const Camera ray, float &old_dist);
        virtual Vector3f<float> getNormale(const Camera ray, const Vector3f<float> hitPoint);
        virtual Vector3f<float> getObjectColor(const Vector3f<float> hitPoint);
        virtual QString         getObjectType();
};

#endif // CYLINDER_H
