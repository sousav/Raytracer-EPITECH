#ifndef SCENE_H
#define SCENE_H

#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <vector>

#include "object.h"
#include "camera.h"
#include "material.h"
#include "light.h"
#include "myxml.h"

class Scene
{
    public:
        std::vector<Object *> objectList;
        std::vector<Light  *> lightList;
        std::vector<Material  *> matList;
        int objectCount;
        int lightCount;
        int matCount;
        Scene(QWidget *parent, int i);
        QString path_file;
        QFile *file;
        QStringList stringlist;
        Camera *camera;
        MyXML *myxml;
        int shadowsampling;
        int booleansoftshadow;
        int mode;
        std::vector<int>objUsingMarble;
        std::vector<int>objUsingCircle;
        std::vector<int>objUsingWood;
        std::vector<int>objUsingGayPride;
        std::vector<int>objUsingColorCircle;
        std::vector<int>objUsingTurbulence;
};

#else
    class Scene;

#endif // SCENE_H
