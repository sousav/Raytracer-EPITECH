#include "cylinder.h"


Cylinder::Cylinder()
{
    this->center = Vector3f<float>();
    this->center = Vector3f<float>(0, 1, 0);
    this->radius = 100;
    this->height = 150;
    this->material = new Material();
    this->name = QString("null");
}

Cylinder::Cylinder(const Vector3f<float> center, const Vector3f<float> direction, const float radius, const float height, Material *mat, QString name)
{
    this->center.x = center.x;
    this->center.y = center.y;
    this->center.z = center.z;
    this->direction.x = direction.x;
    this->direction.y = direction.y;
    this->direction.z = direction.z;
    this->radius = radius;
    this->height = height;
    this->material = mat;
    this->name = name;
}

bool Cylinder::hit(const Camera ray, float &old_dist)
{
    Vector3f<float> alpha = this->direction * ray.direction.dot(this->direction);
    Vector3f<float> deltaP = ray.start - this->center;
    Vector3f<float> beta = this->direction * deltaP.dot(this->direction);
    Vector3f<float> center2 = this->center + this->direction * this->height;
    double a = (ray.direction - alpha).dot(ray.direction - alpha);
    double b = 2 * (ray.direction - alpha).dot(deltaP - beta);
    double c = (deltaP - beta).dot(deltaP - beta) - this->radius * this->radius;
    double discriminant = b * b - 4 * a * c;
    double t1, t2;
    if (discriminant < 0)
        return (0);
    else
    {
        discriminant = sqrt(discriminant);
        t1 = ((-1 * b) + discriminant) / (2 * a);
        t2 = ((-1 * b) - discriminant) / (2 * a);
        if (t1 < t2 && t1 >= 0.1)
        {
            if (this->direction.dot((ray.start - this->center) + ray.direction * t1) > 0 &&
                this->direction.dot((ray.start - center2) + ray.direction * t1) < 0)
            {
                if (t1 < old_dist)
                {
                    old_dist = t1;
                    return (1);
                }
            }
        }
        else if (t2 >= 0.1)
        {
            if (this->direction.dot((ray.start - this->center) + ray.direction * t2) > 0 &&
                this->direction.dot((ray.start - center2) + ray.direction * t2) < 0)
            {
                if (t2 < old_dist)
                {
                    old_dist = t2;
                    return (1);
                }
            }
        }
    }
    return (0);
}

Vector3f<float> Cylinder::getNormale(const Camera ray, const Vector3f<float> hitPoint)
{
    Vector3f<float>	co;

    (void)ray;
    co = this->center - hitPoint;
    return ((this->direction * (co.dot(this->direction) / this->direction.length2())) - co);
}

Vector3f<float> Cylinder::getObjectColor(const Vector3f<float> hitPoint)
{
    (void)hitPoint;
    return (Vector3f<float>(this->material->color->r, this->material->color->g, this->material->color->b) / 255.0);
}

QString Cylinder::getObjectType()
{
    return (QString("Cylinder"));
}
