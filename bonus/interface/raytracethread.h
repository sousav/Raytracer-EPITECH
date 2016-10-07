#ifndef RAYTRACETHREAD_H
#define RAYTRACETHREAD_H

#include <QThread>
#include <QMutex>
#include "vector2.h"
#include "color.h"
#include "glwindow.h"
#include "scene.h"
#include "global.h"
#include "sphere.h"
#include "plan.h"


#define SoftShadows                             global_scene->booleansoftshadow
#define GISamples                               global_scene->shadowsampling

#define MAX_DEPTH                               10

#define AmbientOcclusion                        1
#define TDRM                                    (2.0 / (float)RAND_MAX)
#define ODGISamples                             (1.0f / (float)GISamples)
#define AmbientOcclusionIntensity               1
#define ODGISamplesMAmbientOcclusionIntensity   (ODGISamples * AmbientOcclusionIntensity)

#define MARBLE                                  1
#define CIRCLE                                  2
#define WOOD                                    3
#define GAYPRIDE                                4
#define TURBULENCE                              5
#define COLORCIRCLE                             6

class RaytraceThread : public QThread
{
    private:
        QMutex          *mutex;
        GlWindow        *glWin;
        Scene           *scene;
        Vector3f<float> raytrace(const Vector3f<float> &camStart, const Vector3f<float> &camDir, int depth, float coef);
        bool            Shadow(Vector3f<float> &Point, Vector3f<float> &LightDirection, float LightDistance);
        Vector3f<float> reflect(const Vector3f<float> &i, const Vector3f<float> &n);
        Vector3f<float> refract(const Vector3f<float> &i, const Vector3f<float> &n, float eta);
        Vector3f<float> mix(const Vector3f<float> &u, const Vector3f<float> &v, float a);
        float           clamp(const float &lo, const float &hi, const float &v);

        void IlluminatePoint(Vector3f<float> &Point, Vector3f<float> &Normal, Vector3f<float> &Color, Camera &camera);
        Vector3f<float> LightIntensity(Vector3f<float> &Point, Vector3f<float> &Normal, Vector3f<float> &LightPosition, float AO);
        void compute_photon(float &attenuation, const Vector3f<float> start, const Vector3f<float> lightDir, float LightDistance);
        float AmbientOcclusionFactor(Vector3f<float> &Point, Vector3f<float> &Normal);
        void applyProceduralTexture(Vector3f<float> &outColor, Vector3f<float> hitPoint, const int procedMat);

    public:
        RaytraceThread(QMutex* mu, GlWindow *glWin);

    protected:
        void run();

};

#else

class RaytraceThread;

#endif // RAYTRACETHREAD_H
