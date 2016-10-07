#include "scene.h"
#include "sphere.h"
#include "cone.h"
#include "cylinder.h"
#include "triangle.h"
#include "plan.h"
#include <fstream>
#include <qdebug.h>

Scene::Scene(QWidget *parent, int y)
{
    if (y == 0)
        this->path_file = QFileDialog::getOpenFileName(parent, QObject::tr("Open File"),"/path/to/file/", QObject::tr(".xml file (*.xml);;.obj file (*.obj)"));
    else
        this->path_file = "/Users/ethankerdelhue/Documents/Shared/Raytracer/scene/slide_cpp/waater.xml";

    if (this->path_file == "")
        return;

    if (this->path_file[this->path_file.size() - 1] == 'l' &&
        this->path_file[this->path_file.size() - 2] == 'm' &&
        this->path_file[this->path_file.size() - 3] == 'x' &&
        this->path_file[this->path_file.size() - 4] == '.')
    {
        qDebug("Loading xml file...");
        this->file = new QFile(this->path_file);

        QStringList myStringList;
        if (!this->file->open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0, "Error opening file", this->file->errorString());
            return;
        }
        else
        {
            while(!this->file->atEnd())
                 myStringList.append(this->file->readLine());
            this->file->close();
        }
        this->stringlist = myStringList;
        this->myxml = new MyXML(this->stringlist);
        Vector3f<float> cam_pos = Vector3f<float>(this->myxml->get_field("scene:view:cam_pos:x").toFloat(),
                                            this->myxml->get_field("scene:view:cam_pos:y").toFloat(),
                                            this->myxml->get_field("scene:view:cam_pos:z").toFloat());
        Vector3f<float> look_at = Vector3f<float>(this->myxml->get_field("scene:view:look_at:x").toFloat(),
                                            this->myxml->get_field("scene:view:look_at:y").toFloat(),
                                            this->myxml->get_field("scene:view:look_at:z").toFloat());
        Vector2 size = Vector2(this->myxml->get_field("scene:view:x_size").toInt(), this->myxml->get_field("scene:view:y_size").toInt());
        this->camera = new Camera(size, cam_pos, look_at, this->myxml->get_field("scene:view:fov").toFloat(), this->myxml->get_field("scene:view:alias").toFloat());
        int i = 1;
        this->matCount = this->myxml->get_field("scene:material_list:count").toInt();
        while (i <= this->matCount)
        {
            this->matList.push_back(new Material(this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":name")).toLatin1().data()), i,
                                           Color(this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":red")).toLatin1().data()).toFloat() / 255.0,
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":green")).toLatin1().data()).toFloat() / 255.0,
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":blue")).toLatin1().data()).toFloat() / 255.0),
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":reflect")).toLatin1().data()).toFloat(),
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":transparency")).toLatin1().data()).toFloat(),
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":ior")).toLatin1().data()).toFloat(),
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":bump")).toLatin1().data()).toFloat(),
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":sky")).toLatin1().data()).toInt(),
                                                 this->myxml->get_field((QString("scene:material_list:mat") + QString::number(i) + QString(":texture")).toLatin1().data())));
            i++;
        }
        qDebug() << "materiaux loaded\n";

        this->objectCount = this->myxml->get_field("scene:object_list:count").toInt();
        i = 1;
        while (i <= this->objectCount)
        {
            if (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":type")).toLatin1().data()) == QString("sphere"))
            {
                Vector3f<float> sphere_center = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":center:"), this->myxml);
                float           sphere_radius = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":radius")).toLatin1().data()).toFloat();
                int             sphere_mat_id = (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":material_id")).toLatin1().data())).toInt() - 1;
                QString         sphere_name   = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":name")).toLatin1().data());
                Sphere *sphere_tmp = new Sphere(sphere_center, sphere_radius, this->matList[sphere_mat_id], sphere_name);
                this->objectList.push_back(sphere_tmp);
            }

            if (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":type")).toLatin1().data()) == QString("plan"))
            {
                Vector3f<float> plan_center  = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":center:"), this->myxml);
                Vector3f<float> plan_dir     = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":dir:"), this->myxml);
                int             plan_mat_id  = (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":material_id1")).toLatin1().data())).toInt() - 1;
                int             plan_mat_id2 = (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":material_id2")).toLatin1().data())).toInt() - 1;
                QString         Plan_name   = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":name")).toLatin1().data());
                Plan *plan_tmp = new Plan(plan_center, plan_dir, this->matList[plan_mat_id], this->matList[plan_mat_id2], Plan_name);
                this->objectList.push_back(plan_tmp);
            }

            if (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":type")).toLatin1().data()) == QString("cone"))
            {
                Vector3f<float> cone_center  = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":center:"), this->myxml);
                Vector3f<float> cone_dir     = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":dir:"), this->myxml);
                float           cone_radius = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":radius")).toLatin1().data()).toFloat();
                float           cone_height = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":height")).toLatin1().data()).toFloat();
                int             cone_mat_id  = (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":material_id")).toLatin1().data())).toInt() - 1;
                QString         cone_name   = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":name")).toLatin1().data());
                Cone *cone_tmp = new Cone(cone_center, cone_dir, cone_radius, cone_height, this->matList[cone_mat_id], cone_name);
                this->objectList.push_back(cone_tmp);
            }

            if (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":type")).toLatin1().data()) == QString("cylinder"))
            {
                Vector3f<float> cyl_center  = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":center:"), this->myxml);
                Vector3f<float> cyl_dir     = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":dir:"), this->myxml);
                float           cyl_radius = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":radius")).toLatin1().data()).toFloat();
                float           cyl_height = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":height")).toLatin1().data()).toFloat();
                int             cyl_mat_id  = (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":material_id")).toLatin1().data())).toInt() - 1;
                QString         cyl_name   = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":name")).toLatin1().data());
                Cylinder *cyl_tmp = new Cylinder(cyl_center, cyl_dir, cyl_radius, cyl_height, this->matList[cyl_mat_id], cyl_name);
                this->objectList.push_back(cyl_tmp);
            }


            if (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":type")).toLatin1().data()) == QString("triangle"))
            {
                Vector3f<float> point1  = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":point1:"), this->myxml);
                Vector3f<float> point2 = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":point2:"), this->myxml);
                Vector3f<float> point3  = Vector3f<float>(QString("scene:object_list:obj") + QString::number(i) + QString(":point3:"), this->myxml);
                int             tri_mat_id  = (this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":material_id")).toLatin1().data())).toInt() - 1;
                QString         tri_name   = this->myxml->get_field((QString("scene:object_list:obj") + QString::number(i) + QString(":name")).toLatin1().data());
                Triangle *tri_tmp = new Triangle(point1, point2, point3, this->matList[tri_mat_id], tri_name);
                this->objectList.push_back(tri_tmp);
            }
            i++;
        }

        qDebug() << "object loaded\n";

        i = 1;
        this->lightCount = this->myxml->get_field("scene:light_list:count").toInt();
        while (i <= this->lightCount)
        {
            this->lightList.push_back(new Light(Vector3f<float>(QString("scene:light_list:light") + QString::number(i) + QString(":center:"), this->myxml),
                                                this->myxml->get_field((QString("scene:light_list:light") + QString::number(i) + ":intensity").toLatin1().data()).toFloat()));
            i++;
        }
    }

    if (this->path_file[this->path_file.size() - 1] == 'j' &&
        this->path_file[this->path_file.size() - 2] == 'b' &&
        this->path_file[this->path_file.size() - 3] == 'o' &&
        this->path_file[this->path_file.size() - 4] == '.')
    {
        qDebug("Loading obj file...");
        Vector3f<float> cam_pos = Vector3f<float>(0.0, 25.0, -50.0);
        Vector3f<float> look_at = Vector3f<float>(0.0, 5.0, 0.0);
        Vector2 size = Vector2(1080, 720);
        this->camera = new Camera(size, cam_pos, look_at, 90.0, 1.0);
        //this->lightList.push_back(new Light(Vector3f<float>(30.0, 40.0, 30.0), 110.0));

        std::vector<std::string*> coord;
        std::vector<Vector3f<float>> vertex;
        std::ifstream file(this->path_file.toStdString().c_str(), std::ifstream::in);
        if(!file.is_open())
            return;
        char buf[256];

        while(!file.eof())
        {
            file.getline(buf, 256);
            coord.push_back(new std::string(buf));
        }

        int mat = -1;
        int flag = 0;
        for(unsigned int i = 0;i < coord.size(); i++)
        {
            if(coord[i]->c_str()[0] == '#')
                continue;

            if(coord[i]->c_str()[0 ]== 'v' && coord[i]->c_str()[1] == ' ')
            {
                float tmpx,tmpy,tmpz;
                sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);
                vertex.push_back(Vector3f<float>(tmpx,tmpy,tmpz));
            }

            if(coord[i]->c_str()[0] == 'g' && coord[i]->c_str()[1] == ' ')
            {
                mat++;
                this->matList.push_back(new Material(QString("material " + QString::number(mat)), mat,
                                                     Color((float)(std::rand() % 255) / 255.0,
                                                           (float)(std::rand() % 255) / 255.0,
                                                           (float)(std::rand() % 255) / 255.0),
                                                     10.0, 0.0, 0.0, 0.0, 0, "NULL"));
            }

            if(coord[i]->c_str()[0] == 'f' && coord[i]->c_str()[1] == ' ')
            {
                int a,b,c,x,y,z;
                if(count(coord[i]->begin(),coord[i]->end(),' ') == 5)
                {
                    flag = 1;
                    continue;
                }
                if(count(coord[i]->begin(),coord[i]->end(),' ') == 4)
                {
                    sscanf(coord[i]->c_str(),"f %d/%d %d/%d %d/%d",&a,&x, &b,&y, &c,&z);
                    Triangle *tri_tmp = new Triangle(vertex.at(a - 1), vertex.at(b - 1), vertex.at(c - 1), this->matList[mat], QString("obj_face") + QString::number(i));
                    this->objectList.push_back(tri_tmp);
                }
            }
        }
        if (flag)
            QMessageBox::information(0, "Wrong Obj format", "found some 4vertex face\nWe can't compute that");
    }
    this->booleansoftshadow = 1;
    this->shadowsampling = 4;
}
