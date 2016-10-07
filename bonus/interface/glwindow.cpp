#include "glwindow.h"

GlWindow::GlWindow(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    this->scene = NULL;
}

GlWindow::~GlWindow()
{

}

void GlWindow::initializeGL()
{
    glViewport(0, 0, this->size().width(), this->size().height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, this->size().width(), this->size().height(), 0.0, -1, 1);
    this->pixel = new Color[this->size().height() * this->size().width()];
    for (int i = 0; i < this->size().height() * this->size().width() - 10; i++)
    {
        this->pixel[i] = Color();
    }
    this->thread = new RaytraceThread(&this->mutex, this);
}

void GlWindow::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1, 1);
    this->pixel = new Color[height * width];
    for (int i = 0; i < height * width - 10; i++)
    {
        this->pixel[i] = Color();
    }
}

void GlWindow::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Vector2 pos;
    for (pos.y = 0; pos.y < this->size().height(); pos.y++)
    {
        for (pos.x = 0; pos.x < this->size().width(); pos.x++)
        {
            setPixelOnScreen(pos, this->pixel[pos.x + pos.y * this->size().width()]);
        }
    }
    glFlush();
}

void GlWindow::raytrace_button()
{
    this->resize(global_scene->camera->win_size.x, global_scene->camera->win_size.y);
    glViewport(0, 0, this->size().width(), this->size().height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, global_scene->camera->win_size.x, global_scene->camera->win_size.y, 0.0, -1, 1);
    this->thread->start();
}

void GlWindow::save_button()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "/path/to/file/*.png",
                                tr("Images *.png"));
    QPixmap *outPixmap = new QPixmap(global_scene->camera->win_size.x, global_scene->camera->win_size.y);
    QImage img = outPixmap->toImage();
    for(int i = 0; i < global_scene->camera->win_size.x; i++)
    {
        for(int j = 0; j < global_scene->camera->win_size.y; j++)
        {
            Color _color = this->pixel[i + j * this->size().width()].clamp_color();
            img.setPixel(i, j, QColor(_color.r * 255,
                                      _color.g * 255,
                                      _color.b * 255).rgba());
        }
    }

    outPixmap = new QPixmap;
    outPixmap->convertFromImage(img);
    outPixmap->save(fileName, "PNG");
}

void GlWindow::setPixel(const Vector2 pixel_pos, const Color color)
{
    this->pixel[pixel_pos.x + pixel_pos.y * this->size().width()].r = color.r;
    this->pixel[pixel_pos.x + pixel_pos.y * this->size().width()].g = color.g;
    this->pixel[pixel_pos.x + pixel_pos.y * this->size().width()].b = color.b;
}

void GlWindow::setPixelOnScreen(const Vector2 pixel_pos, Color color)
{
    // Draw a Red 1x1 Square
    float   ratio_x = (float)this->size().width()  / (global_scene == NULL ? (float)this->size().width()  : (float)global_scene->camera->win_size.x) + 0.35;
    float   ratio_y = (float)this->size().height() / (global_scene == NULL ? (float)this->size().height() : (float)global_scene->camera->win_size.y) + 0.35;
    float   size_x  = 0.5 * ratio_x;
    float   size_y  = 0.5 * ratio_y;
    Color   _color = color.clamp_color();
    glBegin(GL_QUADS);
        glColor3f(_color.r, _color.g, _color.b);
        glVertex2f(pixel_pos.x - size_x, pixel_pos.y - size_y);
        glVertex2f(pixel_pos.x - size_x, pixel_pos.y + size_y);
        glVertex2f(pixel_pos.x + size_x, pixel_pos.y - size_y);
        glVertex2f(pixel_pos.x + size_x, pixel_pos.y + size_y);
    glEnd();
}

