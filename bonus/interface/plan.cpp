#include "plan.h"

Plan::Plan()
{
    this->center = Vector3f<float>();
    this->direction = Vector3f<float>(0.0, 1.0, 0.0);
    this->material = new Material();
    this->material2 = new Material();
    this->name = QString("null");
}

Plan::Plan(const Vector3f<float> center, const Vector3f<float> dir , Material *mat, Material *mat2, QString name)
{
    this->center.x = center.x;
    this->center.y = center.y;
    this->center.z = center.z;
    this->direction.x = dir.x;
    this->direction.y = dir.y;
    this->direction.z = dir.z;
    this->material = mat;
    this->material2 = mat2;
    this->name = name;
}

bool Plan::hit(const Camera ray, float &old_dist)
{
    float denom = this->direction.dot(ray.direction);
    if (denom > 0)
    {
        Vector3f<float> p0l0 = this->center - ray.start;
        float dist = (p0l0.dot(this->direction)) / denom;
        if (dist > 0.1 && old_dist > dist)
        {
            old_dist = dist;
            return (1);
        }
    }
    return (0);
}

Vector3f<float> Plan::getNormale(const Camera ray, const Vector3f<float> hitPoint)
{
    (void)ray;
    (void)hitPoint;
    return (-this->direction);
}


Vector3f<float> Plan::getObjectColor(const Vector3f<float> hitPoint)
{
    Vector3f<float>dist_to_center = hitPoint - this->center;
    if (damier(dist_to_center) == 0)
        return Vector3f<float>(this->material->color->r,  this->material->color->g,  this->material->color->b) / 255.0;
    else
        return Vector3f<float>(this->material2->color->r, this->material2->color->g, this->material2->color->b) / 255.0;
}

#define     SIZE_TILE   10
bool	Plan::damier(const Vector3f<float> &pos)
{
  Vector3f<int>tmp;

  tmp.x = (int)((pos.x + 13000) / SIZE_TILE);
  tmp.y = (int)(pos.y / SIZE_TILE);
  tmp.z = (int)((pos.z + 13000) / SIZE_TILE);
  if (tmp.x % 2 == 0)
    {
      if (((tmp.y % 2 == 0) && (tmp.z % 2 == 0)) ||
      (((tmp.y % 2 != 0) && (tmp.z % 2 != 0))))
    return (0);
      else
    return (1);
    }
  else
    {
      if ((((tmp.y % 2 == 0) && (tmp.z % 2 == 0))) ||
      (((tmp.y % 2 != 0) && (tmp.z % 2 != 0))))
    return (1);
      else
    return (0);
  }
}

QString Plan::getObjectType()
{
    return (QString("plan"));
}
