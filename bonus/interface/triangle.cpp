#include "triangle.h"

Triangle::Triangle()
{
    this->point[0].x = 0;
    this->point[0].y = 0;
    this->point[0].z = 0;

    this->point[1].x = 0;
    this->point[1].y = 0;
    this->point[1].z = 0;

    this->point[2].x = 0;
    this->point[2].y = 0;
    this->point[2].z = 0;

    this->material = new Material();
    this->name = QString("null");
}

Triangle::Triangle(const Vector3f<float> point1, const Vector3f<float> point2, const Vector3f<float> point3, Material *mat, QString name)
{
    this->point[0].x = point1.x;
    this->point[0].y = point1.y;
    this->point[0].z = point1.z;

    this->point[1].x = point2.x;
    this->point[1].y = point2.y;
    this->point[1].z = point2.z;

    this->point[2].x = point3.x;
    this->point[2].y = point3.y;
    this->point[2].z = point3.z;

    this->material = mat;
    this->name = name;
}

typedef struct		s_hit_triangle
{
  Vector3f<float>e1;
  Vector3f<float>e2;
  Vector3f<float>h;
  Vector3f<float>s;
  Vector3f<float>q;
  float 		a;
  float			f;
  float			u;
  float			v;
  float			t;
}			t_hit_triangle;
Vector3f<float>                 minus_vector(const Vector3f<float> v1, const Vector3f<float> v2)
{
  Vector3f<float>               out;

  out.x = v1.x - v2.x;
  out.y = v1.y - v2.y;
  out.z = v1.z - v2.z;
  return (out);
}
Vector3f<float>			crossProduct(Vector3f<float> c1, Vector3f<float> c2)
{
  Vector3f<float>		out;

  out.x = c1.y * c2.z - c2.y * c1.z;
  out.y = c1.z * c2.x - c2.z * c1.x;
  out.z = c1.x * c2.y - c2.x * c1.y;
  return (out);
}
float                   mult_vector(const Vector3f<float> v1, const Vector3f<float> v2)
{
  return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

bool Triangle::hit(const Camera ray, float &old_dist)
{
    t_hit_triangle	t_tri;

    t_tri.e1 = minus_vector(this->point[2], this->point[0]);
    t_tri.e2 = minus_vector(this->point[1], this->point[0]);
    t_tri.h = crossProduct(ray.direction, t_tri.e2);
    t_tri.a = mult_vector(t_tri.e1, t_tri.h);
    if (t_tri.a > -0.01 && t_tri.a < 0.01)
      return (0);
    t_tri.f = 1 / t_tri.a;
    t_tri.s = minus_vector(ray.start, this->point[0]);
    t_tri.u = t_tri.f * (mult_vector(t_tri.s, t_tri.h));
    if (t_tri.u < 0.0 || t_tri.u > 1.0)
      return (0);
    t_tri.q = crossProduct(t_tri.s, t_tri.e1);
    t_tri.v = t_tri.f * mult_vector(ray.direction, t_tri.q);
    if (t_tri.v < 0.0 || t_tri.u + t_tri.v > 1.0)
      return (0);
    t_tri.t = t_tri.f * mult_vector(t_tri.e2, t_tri.q);
    if (t_tri.t > 0.1 && old_dist > t_tri.t)
      {
        old_dist = t_tri.t;
        return (1);
      }
    return (0);
}

Vector3f<float> Triangle::getNormale(const Camera ray, const Vector3f<float> hitPoint)
{
    (void)hitPoint;
    Vector3f<float>e1 = this->point[1] - this->point[0];
    Vector3f<float>e2 = this->point[2] - this->point[0];
    Vector3f<float>h = Vector3f<float>::cross(e2, e1);
    if (ray.direction.dot(h) >= 0)
        h = Vector3f<float>::cross(e1, e2);
    return h.normalize();
}

Vector3f<float> Triangle::getObjectColor(const Vector3f<float> hitPoint)
{
    (void)hitPoint;
    return (Vector3f<float>(this->material->color->r, this->material->color->g, this->material->color->b) / 255.0);
}

QString Triangle::getObjectType()
{
    return (QString("Triangle"));
}
