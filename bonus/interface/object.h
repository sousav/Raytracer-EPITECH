#ifndef OBJECT_H
#define OBJECT_H

#include "vector3f.hpp"
#include "material.h"
#include "camera.h"

class Object
{
    public:
        Object();

        Vector3f<float> center;
        Material        *material;
        QString         name;

        virtual bool            hit(const Camera ray, float &old_dist) = 0;
        virtual Vector3f<float> getNormale(const Camera ray, const Vector3f<float> hitPoint) = 0;
        virtual Vector3f<float> getObjectColor(const Vector3f<float> hitPoint) = 0;
        virtual QString         getObjectType();

};

#else
    class Object;

#endif // OBJECT_H
