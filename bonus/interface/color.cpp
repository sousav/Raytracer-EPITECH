#include "color.h"

Color::Color()
{
    this->r = 0.0;
    this->g = 0.0;
    this->b = 0.0;
}


Color::Color(const float r, const float g, const float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Color Color::clamp_color()
{
    float   max = 1.0;

    if (this->r > max)
        max = this->r;
    if (this->g > max)
        max = this->g;
    if (this->b > max)
        max = this->b;
    Color out;
    out.r = this->r / max;
    out.g = this->g / max;
    out.b = this->b / max;
    return (out);
}
