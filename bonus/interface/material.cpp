#include "material.h"

#include <QDebug>

Material::Material()
{
    this->name = QString("empty");
    this->id = -1;
    this->color = new Color();
    this->reflect = 0.0;
    this->transparency = 0.5;
    this->bump = 0.0;
    this->texture_path = "";
    this->texture = new QImage();
    this->texture->fill(QColor(0, 0, 0));
}

Material::Material(QString name, const int id, const Color color, const float reflect, const float transparency, const float ior, const float bump, const int sky, QString path)
{
    this->name = name;
    this->id = id;
    this->color = new Color(color.r, color.g, color.b);
    this->reflect = reflect / 100.0;

    this->transparency = transparency / 100.0;
    this->ior = ior;
    this->eior = 1.0 / this->ior;

    this->bump = bump;

    this->sky = sky;
    this->texture_path = path;
    this->texture = new QImage();
    this->texture->load(path);
}

void Material::updateIor(const float newIior)
{
    this->ior = newIior;
    this->eior = 1.0 / this->ior;
}

void Material::updateImage(const QString new_path)
{
    this->texture = new QImage();
    this->texture->load(new_path);
}
