#include "light.h"

Light::Light()
{
    this->center.x = 0;
    this->center.y = 0;
    this->center.z = 0;
    this->intensity = 0.0;
}

Light::Light(const Vector3f<float> center, const float inten)
{
    this->center.x = center.x;
    this->center.y = center.y;
    this->center.z = center.z;
    this->intensity = inten;
}
