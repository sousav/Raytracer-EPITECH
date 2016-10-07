#ifndef CAMERA_H
#define CAMERA_H

#include <math.h>
#include "global.h"
#include "vector2.h"
#include "vector2f.h"
#include "vector3f.hpp"

class Camera
{   
    public:
        Camera();
        Camera(const Vector2 size, const Vector3f<float>start, const Vector3f<float>look_at, const float fov, const int alliasing);
        void updateFov(float fov);

        Vector2         win_size;
        Vector3f<float> start;
        Vector3f<float> look_at;
        Vector3f<float> direction;
        Vector2f        cam_rot;
        Vector2f        fov;
        int             alliasing;

        void processDir(Vector2 pos);
};

#else
    class Camera;

#endif // CAMERA_H
