#ifndef LIGHT_H
#define LIGHT_H

#include "vector3f.hpp"
#include "material.h"
#include "object.h"

class Light
{

public:
        Light(Vector3f<float> center, float inten);
        Light();

        Vector3f<float> center;
        float           intensity;
};

#else
    class Light;

#endif // LIGHT_H
