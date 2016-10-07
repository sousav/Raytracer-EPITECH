#ifndef PLAN_H
#define PLAN_H

#include "object.h"
#include "vector3f.hpp"
#include "camera.h"

class Plan : public Object
{
    public:
        Plan();
        Plan(const Vector3f<float> center, const Vector3f<float> dir , Material *mat, Material *mat2, QString name);
        Vector3f<float> direction;
        Material        *material2;

        virtual bool            hit(const Camera ray, float &old_dist);
        virtual Vector3f<float> getNormale(const Camera ray, const Vector3f<float> hitPoint);
        virtual Vector3f<float> getObjectColor(const Vector3f<float> hitPoint);
        virtual QString         getObjectType();

    private:
        bool	damier(const Vector3f<float> &pos);
};

#endif // PLAN_H
