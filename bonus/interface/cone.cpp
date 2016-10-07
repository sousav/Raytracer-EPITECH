#include "cone.h"

Cone::Cone()
{
    this->center = Vector3f<float>();
    this->center = Vector3f<float>(0, 1, 0);
    this->radius = 100;
    this->height = 150;
    this->material = new Material();
    this->name = QString("null");
}

Cone::Cone(const Vector3f<float> center, const Vector3f<float> direction, const float radius, const float height, Material *mat, QString name)
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

bool Cone::hit(const Camera ray, float &old_dist)
{
    double 		dist[2];
    double		fac;
    Vector3f<float>	x;
    Vector3f<float>	y;
    double		d;
    Vector3f<float>	temp;

    fac = (this->radius * this->radius) / (double) (this->height * this->height);
    y.x = (fac) * ray.direction.y * ray.direction.y;
    y.y = (2.0 * fac * ray.start.y * ray.direction.y) - (2.0 *
       (this->radius * this->radius) / this->height) * ray.direction.y;
    y.z = (fac * ray.start.y * ray.start.y) - ((2.0 * (this->radius * this->radius) /
                         this->height) * ray.start.y) +
    (this->radius * this->radius);
    x.x = (ray.direction.x * ray.direction.x) + (ray.direction.z * ray.direction.z) - y.x;
    x.y = (2.0 * ray.start.x * ray.direction.x) + (2.0 * ray.start.z * ray.direction.z) - y.y;
    x.z = (ray.start.x * ray.start.x) + (ray.start.z * ray.start.z) - y.z;
    d = (x.y * x.y) - (4.0 * x.x * x.z);
    if (d >= 0)
    {
        dist[0] = (-x.y - sqrt(d)) / (2.0 * x.x);
        dist[1] = (-x.y + sqrt(d)) / (2.0 * x.x);
        if (dist[1] < dist[0] && dist[1] > 0.1)
        {
            temp = ray.start + ray.direction * dist[1];
            if (temp.y <= this->height && temp.y >= 0.0 && dist[1] < old_dist)
            {
                old_dist = dist[1];
                return (1);
            }
        }
        else if (dist[1] > dist[0] && dist[0] > 0.1)
        {
            temp = ray.start + ray.direction * dist[0];
            if (temp.y <= this->height && temp.y >= 0.0 && dist[0] < old_dist)
            {
                old_dist = dist[0];
                return (1);
            }
        }
    }
    return(0);
}

Vector3f<float> Cone::getNormale(const Camera ray, const Vector3f<float> hitPoint)
{
    Vector3f<float>	top;
    Vector3f<float>	perp;

    (void)ray;
    top = this->center + this->direction * this->height;
    perp = Vector3f<float>::cross(this->direction, top - hitPoint);
    return (Vector3f<float>::cross(top - hitPoint, perp).normalize());
}

Vector3f<float> Cone::getObjectColor(const Vector3f<float> hitPoint)
{
    (void)hitPoint;
    return (Vector3f<float>(this->material->color->r, this->material->color->g, this->material->color->b) / 255.0);
}

QString Cone::getObjectType()
{
    return (QString("cone"));
}
