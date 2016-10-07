#ifndef COLOR_H
#define COLOR_H


class Color
{
    public:
        Color();
        Color(const float r, const float g, const float b);

        float r;
        float g;
        float b;

        Color clamp_color();

    private:

};

#endif // COLOR_H
