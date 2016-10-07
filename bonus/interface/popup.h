#ifndef POPUP_H
#define POPUP_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtGui>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QLabel>
#include <QComboBox>
#include <object.h>
#include <QCheckBox>
#include <QSlider>
#include <qwidget.h>
#include <QFileDialog>
#include <QDoubleValidator>
#include <QTableWidget>
#include "sphere.h"
#include "mainwindow.h"
#include "vector2f.h"
#include "plan.h"
#include "cone.h"
#include "cylinder.h"
#include "raytracethread.h"

class MyPopup: public QWidget
{
    Q_OBJECT

public:
    MyPopup(MainWindow *mw);
    ~MyPopup();
    void show_it();
    void set_ui_obj(Object *object);
    void keyPressEvent(QKeyEvent *e);
    QWidget *parent;
    void set_ui_selectobj();
    void set_ui_addobj();
    void set_ui_addmat();
    void set_layout_sphere(QGridLayout *mainLayout);
    void set_layout_mat(QGridLayout *mainLayout);
    int typeSelected = 0;
    void set_ui_editmat(int id);
    void set_layout_editmat(QGridLayout *mainLayout, int id);
    void set_ui_promat(int id);
    void set_layout_promat(QGridLayout *mainLayoun, int id);
    bool isInGayPride(int nb);
    bool isInCircle(int nb);
    bool isInMarble(int nb);
    bool isInColorCircle(int nb);
    bool isInWood(int nb);
    bool isInTurbulence(int nb);
    /*
     * 0 : sphere
     */

private:
    QTableWidget *tabProMat;
    QPushButton *Apply;
    QLabel *CenterX;
    QLabel *CenterY;
    QLabel *CenterZ;
    QLabel *matLab;
    QLabel *radLab;
    QLabel *reflectSlider;
    QLabel *LabDir;
    QLabel *LabHeight;
    QLabel *transpaSlider;
    QLineEdit *EditRad;
    QLineEdit *EditX;
    QLineEdit *EditY;
    QLineEdit *EditZ;
    QLineEdit *EditName;
    QLineEdit *EditIor;
    QLineEdit *DirX;
    QLineEdit *DirY;
    QLineEdit *Height;
    QLineEdit *DirZ;
    QSlider *bumpstate;
    QLabel *LabelBump;
    QComboBox *matList;
    QComboBox *matList2;
    QSlider *transpa;
    QSlider *reflect;
    QCheckBox *sky;
    Object *object;
    MainWindow *mw;
    QComboBox *SelectMat;
    QPushButton *createSph;
    QPushButton *createMat;
    QPushButton *editMat;
    QPushButton *PrevColor;
    QPushButton *getPath;
    QLineEdit *curPath;
    QColorDialog *cp;
    QString path_file;
    Color ColorCur = Color();
    Color *editColorCur;
    int editId;
    int proId;

private slots:
     void setValueObj();
     void cancelButtonPressed();
     void createButtonPressed();
     void editTypeSelect(int nb);
     void createSphere();
     void createMaterial();
     void EditSliderReflect(int nb);
     void EditSliderTranspa(int nb);
     void EditSliderBump(int nb);
     void openColorPicker();
     void updatePrevButton(QColor color);
     void selectPathFile();
     void refMatListInObj(int nb);
     void editMaterial();
     void selectProMat(QTableWidgetItem *item);
};

#else
    class MyPopup;

#endif // POPUP_H
