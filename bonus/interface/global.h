#ifndef GLOBAL_H
#define GLOBAL_H

#include "scene.h"

# define 		DTR(ang) 	((ang) / 180.0 * M_PI)
# define		RTD(rad) 	((rad) * (180.0 / M_PI))
# define        M_1_PI_2    ((float)M_1_PI * 0.5)
# define		invsqrtf(x)	(1.0f / sqrt(x))

extern Scene *global_scene;

double	fade(double t);
double	lerp(double t, double a, double b);
double	grad(int hash, double x, double y, double z);
double	noise(double x, double y, double z);
void    applyPerlin(const Vector3f<float> &_hitPoint, Vector3f<float> &normale, const float &bump);

#endif // GLOBAL_H
