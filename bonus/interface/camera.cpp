#include "camera.h"

Camera::Camera()
{
    this->win_size.x = 0;
    this->win_size.y = 0;

    this->start.x = 0;
    this->start.y = 0;
    this->start.z = 0;

    this->look_at.x = 0;
    this->look_at.y = 0;
    this->look_at.z = 0;

    this->fov.x = 0;
    this->fov.y = 0;

    this->direction = Vector3f<float>();

    this->cam_rot.x = 0;
    this->cam_rot.y = 0;

    this->alliasing = 0;
}

Camera::Camera(const Vector2 size, const Vector3f<float> start, const Vector3f<float> look_at, const float fov, const int alliasing)
{
    this->win_size.x = size.x;
    this->win_size.y = size.y;

    this->start.x = start.x;
    this->start.y = start.y;
    this->start.z = start.z;

    this->look_at.x = look_at.x;
    this->look_at.y = look_at.y;
    this->look_at.z = look_at.z;

    this->fov.x = fov;
    this->fov.y = this->fov.x * ((this->win_size.x / this->win_size.y) / 1.5);

    this->direction = (this->look_at - this->start).normalize();

    this->cam_rot.x = RTD(acos(-(this->direction.z / sqrt(pow(this->direction.x, 2) + pow(this->direction.z, 2))))) - 90;
    this->cam_rot.y = RTD((M_PI / 2 - acos(this->direction.y)));

    this->alliasing = alliasing;
}

void Camera::processDir(Vector2 pos)
{
    Vector3f<float> point;
    Vector2f        ang;

    ang.x = this->cam_rot.x - (this->fov.x / this->win_size.x) * (pos.x - this->win_size.x / 2.0);
    ang.y = this->cam_rot.y - (this->fov.y / this->win_size.y) * (pos.y - this->win_size.y / 2.0);
    point.x = this->start.x + cos(DTR(ang.x));
    point.y = this->start.y + sin(DTR(ang.y));
    point.z = this->start.z + sin(DTR(ang.x));
    this->direction = (point - this->start).normalize();
}

void Camera::updateFov(float fov)
{
    this->fov.x = fov;
    this->fov.y = this->fov.x * ((this->win_size.x / this->win_size.y) / 1.5);
}
