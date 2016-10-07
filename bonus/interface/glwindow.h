#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QObject>
#include <QGLWidget>
#include <QtOpenGL>
#ifndef __APPLE__
    #include <GL/glut.h>
#elif defined _WIN32 || defined _WIN64
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_MAC
        #include <GLUT/glut.h>
        #include <OpenGL/OpenGL.h>
    #endif
#endif

#include "color.h"
#include "vector2.h"
#include "vector3.h"
#include "raytracethread.h"
#include "scene.h"

class GlWindow : public QGLWidget
{
    Q_OBJECT

    public:
        explicit GlWindow(QWidget *parent = 0);
       ~GlWindow();
        void setPixel(const Vector2 pixel_pos, const Color color);
        Color *pixel;

    protected:
        void initializeGL();
        void paintGL();
        void resizeGL(int width, int height);

    public slots:
        void raytrace_button();
        void save_button();

    private:
        Scene *scene;
        QMutex mutex;
        RaytraceThread *thread;
        void setPixelOnScreen(const Vector2 pixel_pos, const Color color);
};

#else
class GlWindow;

#endif // GLWINDOW_H
