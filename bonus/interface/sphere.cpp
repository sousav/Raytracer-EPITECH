#include "sphere.h"

Sphere::Sphere()
{
    this->center = Vector3f<float>();
    this->radius = 100;
    this->material = new Material();
    this->name = QString("null");
}

Sphere::Sphere(const Vector3f<float> center, const float radius, Material *mat, QString name)
{
    this->center.x = center.x;
    this->center.y = center.y;
    this->center.z = center.z;
    this->radius = radius;
    this->material = mat;
    this->name = name;
}

bool Sphere::hit(const Camera ray, float &old_dist)
{
    Vector3f<float> dist;
    float           B;
    float           delta;
    float           t0;
    float           t1;

    dist = this->center - ray.start;
    B = ray.direction.dot(dist);
    delta = B * B - dist.dot(dist) + this->radius * this->radius;
    if (delta < 0)
        return (0);
    t0 = B - sqrt(delta);
    t1 = B + sqrt(delta);
    if (t0 < t1 && (t0 > 0.01) && (t0 < old_dist))
    {
        old_dist = t0;
        return (1);
    }
    else if ((t1 > 0.01) && (t1 < old_dist))
    {
        old_dist = t1;
        return (1);
    }
    return (0);
}

Vector3f<float> Sphere::getNormale(const Camera ray, const Vector3f<float> hitPoint)
{
    (void)ray;
    return (hitPoint - this->center) / this->radius;
}

Vector3f<float> Sphere::getObjectColor(const Vector3f<float> hitPoint)
{
    if(this->material->texture->width() > 0)
    {
        Vector3f<float> vn = Vector3f<float>(0, -1, 0);
        vn = vn.normalize();

        Vector3f<float> ve = Vector3f<float>(-1, 0, 0);
        ve = ve.normalize();

        Vector3f<float>vp = hitPoint - this->center;
        vp = vp.normalize();
        float phi = acos(-vn.dot(vp));
        float v = phi / M_PI;
        float u;
        float theta = (acos(vp.dot(ve) / sin(phi))) / (2.0 * M_PI);
        if (vp.z < 0.001 && vp.z > -0.001)
            theta = 0;
        if (vp.cross(vn, ve).dot(vp) > 0)
            u = theta;
        else
            u = 1 - theta;
        v = v * (float)this->material->texture->height();
        u = u * (float)this->material->texture->width();
        if (v >= this->material->texture->height())
            v = 1;
        if (u >= this->material->texture->width())
            u = 1;
        QColor clrCurrent(this->material->texture->pixel(u, v));
        Vector3f<float> outColor;
        outColor.x = (float)clrCurrent.red();
        outColor.y = (float)clrCurrent.green();
        outColor.z = (float)clrCurrent.blue();

        outColor = outColor / 255.0 * 0.015;
        return (outColor);
    }
    else
        return (Vector3f<float>(this->material->color->r, this->material->color->g, this->material->color->b) / 255.0);
}

QString Sphere::getObjectType()
{
    return (QString("sphere"));
}
