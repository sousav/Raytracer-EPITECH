#ifndef SPHERE_H
#define SPHERE_H

#include "vector3f.hpp"
#include "material.h"
#include "camera.h"

class Sphere : public Object
{
    public:
        Sphere();
        Sphere(const Vector3f<float> center, const float radius, Material *mat, QString name);
        float       radius;

        virtual bool            hit(const Camera ray, float &old_dist);
        virtual Vector3f<float> getNormale(const Camera ray, const Vector3f<float> hitPoint);
        virtual Vector3f<float> getObjectColor(const Vector3f<float> hitPoint);
        virtual QString         getObjectType();
};

#endif // SPHERE_H
