#include <QLineEdit>
#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->is_scene_init = 0;
    ui->setupUi(this);
    ui->lineEdit_cpx->setReadOnly(true);
    ui->lineEdit_cpy->setReadOnly(true);
    ui->lineEdit_cpz->setReadOnly(true);
    ui->lineEdit_lax->setReadOnly(true);
    ui->lineEdit_lay->setReadOnly(true);
    ui->lineEdit_laz->setReadOnly(true);
    ui->comboBox_wx->setDisabled(true);
    ui->comboBox_wy->setDisabled(true);
    ui->horizontalSlider_aa->setDisabled(true);
    ui->horizontalSlider_fov->setDisabled(true);
    ui->listObject->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listObject->setColumnWidth(0, ui->listObject->size().width());
    ui->listObject->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listLight->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listLight->setColumnWidth(0, ui->listLight->size().width());
    ui->listLight->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listMat->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listMat->setColumnWidth(0, ui->listMat->size().width());
    ui->listMat->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->comboBox_ao->addItem("Enabled");
    ui->comboBox_ao->addItem("Disabled");
    ui->comboBox_ao->setCurrentIndex(0);
    QString tab_x[] = {"1152", "960", "768", "640", "576", "480", "384", "320"};
    QString tab_y[] = {"720", "600", "480", "400", "360", "300", "240", "300"};
    QString tab_f[] = {"Normal", "Reverse", "Grey", " Black and White", "Sepia"};
    for(int i = 0; i < 8; i++)
      ui->comboBox_wx->addItem(tab_x[i]);
    for(int i = 0; i < 8; i++)
      ui->comboBox_wy->addItem(tab_y[i]);
    for (int i = 0; i < 5; i++)
      ui->comboBox_filtre->addItem(tab_f[i]);
    ui->renderButton->setDisabled(true);
    ui->saveButton->setDisabled(true);
    ui->comboBox_ao->setDisabled(true);
    ui->comboBox_filtre->setDisabled(true);
    ui->lineEdit_ss->setDisabled(true);
    ui->listProMat->setDisabled(true);
    this->affProceduralMat();
}

void MainWindow::CloseWindow()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void MainWindow::on_loadButton_clicked()
{
    global_scene = new Scene(this, 0);
    ui->saveButton->setDisabled(false);
    ui->renderButton->setDisabled(false);
    ui->lineEdit_cpx->setReadOnly(false);
    ui->lineEdit_cpy->setReadOnly(false);
    ui->lineEdit_cpz->setReadOnly(false);
    ui->lineEdit_lax->setReadOnly(false);
    ui->lineEdit_lay->setReadOnly(false);
    ui->lineEdit_laz->setReadOnly(false);
    ui->comboBox_wx->setDisabled(false);
    ui->comboBox_wy->setDisabled(false);
    ui->editButtonObj->setEnabled(true);
    ui->editButtonObj_2->setEnabled(true);
    ui->editButtonObj_4->setEnabled(true);
    ui->editButtonObj_3->setEnabled(true);
    ui->editButtonObj_5->setEnabled(true);
    ui->editButtonObj_6->setEnabled(true);
    ui->horizontalSlider_aa->setDisabled(false);
    ui->horizontalSlider_fov->setDisabled(false);
    ui->comboBox_filtre->setDisabled(false);
    ui->lineEdit_cpx->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_cpy->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_cpz->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_lax->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_lay->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_cpx->setText(QString::number(global_scene->camera->start.x));
    ui->lineEdit_cpy->setText(QString::number(global_scene->camera->start.y));
    ui->lineEdit_cpz->setText(QString::number(global_scene->camera->start.z));
    ui->lineEdit_lax->setText(QString::number(global_scene->camera->look_at.x));
    ui->lineEdit_lay->setText(QString::number(global_scene->camera->look_at.y));
    ui->lineEdit_laz->setText(QString::number(global_scene->camera->look_at.z));
    ui->comboBox_ao->setDisabled(false);
    ui->lineEdit_ss->setDisabled(false);
    ui->lineEdit_ss->setText(QString::number(global_scene->shadowsampling));
    ui->listProMat->setDisabled(false);
    global_scene->mode = 1;
    connect(ui->comboBox_filtre, SIGNAL(currentIndexChanged(int)), this, SLOT(setFiltre(int)));
    this->affLightTab();
    this->affObjTab();
    this->affMatTab();
    this->is_scene_init = 1;
}

void MainWindow::on_lineEdit_cpx_editingFinished()
{
    if (ui->lineEdit_cpx->text() != NULL)
    global_scene->camera->start.x = ui->lineEdit_cpx->text().toFloat();
}

void MainWindow::on_lineEdit_cpy_editingFinished()
{
    if (ui->lineEdit_cpy->text() != NULL)
    global_scene->camera->start.y = ui->lineEdit_cpy->text().toFloat();
}

void MainWindow::on_lineEdit_cpz_editingFinished()
{
    if (ui->lineEdit_cpz->text() != NULL)
    global_scene->camera->start.z = ui->lineEdit_cpz->text().toFloat();
}

void MainWindow::on_lineEdit_lax_editingFinished()
{
    if (ui->lineEdit_lax->text() != NULL)
    global_scene->camera->look_at.x = ui->lineEdit_lax->text().toFloat();
}

void MainWindow::on_lineEdit_lay_editingFinished()
{
    if (ui->lineEdit_lay->text() != NULL)
    global_scene->camera->look_at.y = ui->lineEdit_lay->text().toFloat();
}

void MainWindow::on_lineEdit_laz_editingFinished()
{
    if (ui->lineEdit_laz->text() != NULL)
    global_scene->camera->look_at.z = ui->lineEdit_laz->text().toFloat();
}

void MainWindow::on_comboBox_wx_currentIndexChanged(const QString &arg1)
{
    if (global_scene != NULL)
        global_scene->camera->win_size.x = arg1.toInt();
}

void MainWindow::on_comboBox_wy_currentIndexChanged(const QString &arg1)
{
    if (global_scene != NULL)
        global_scene->camera->win_size.y = arg1.toInt();
}


void MainWindow::on_horizontalSlider_aa_valueChanged(int value)
{
   ui->LabelAA->setText(QString::number(value).toLatin1().data());
   global_scene->camera->alliasing = value;
}

void MainWindow::on_horizontalSlider_fov_valueChanged(int value)
{
    ui->labelFOV->setText(QString::number(value));
    global_scene->camera->updateFov(float(value));
}

void MainWindow::on_listObject_itemClicked(QTableWidgetItem *item)
{
    this->objSelect = item->row();
}

void MainWindow::on_editButtonObj_clicked()
{
    if (this->objSelect != -1)
    {
        this->popup = new MyPopup(this);
        popup->set_ui_obj(global_scene->objectList.at(this->objSelect));
    }
}

void MainWindow::on_pushButton_3_pressed()
{
    global_scene = new Scene(this, 1);
    ui->saveButton->setDisabled(false);
    ui->renderButton->setDisabled(false);
    ui->lineEdit_cpx->setReadOnly(false);
    ui->lineEdit_cpy->setReadOnly(false);
    ui->lineEdit_cpz->setReadOnly(false);
    ui->lineEdit_lax->setReadOnly(false);
    ui->lineEdit_lay->setReadOnly(false);
    ui->lineEdit_laz->setReadOnly(false);
    ui->comboBox_wx->setDisabled(false);
    ui->comboBox_wy->setDisabled(false);
    ui->editButtonObj->setEnabled(true);
    ui->editButtonObj_2->setEnabled(true);
    ui->editButtonObj_4->setEnabled(true);
    ui->editButtonObj_3->setEnabled(true);
    ui->editButtonObj_5->setEnabled(true);
    ui->editButtonObj_6->setEnabled(true);
    ui->horizontalSlider_aa->setDisabled(false);
    ui->horizontalSlider_fov->setDisabled(false);
    ui->comboBox_filtre->setDisabled(false);
    ui->lineEdit_cpx->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_cpy->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_cpz->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_lax->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_lay->setValidator(new QIntValidator(-99999999, 99999999, this));
    ui->lineEdit_cpx->setText(QString::number(global_scene->camera->start.x));
    ui->lineEdit_cpy->setText(QString::number(global_scene->camera->start.y));
    ui->lineEdit_cpz->setText(QString::number(global_scene->camera->start.z));
    ui->lineEdit_lax->setText(QString::number(global_scene->camera->look_at.x));
    ui->lineEdit_lay->setText(QString::number(global_scene->camera->look_at.y));
    ui->lineEdit_laz->setText(QString::number(global_scene->camera->look_at.z));
    ui->comboBox_ao->setDisabled(false);
    ui->lineEdit_ss->setDisabled(false);
    ui->lineEdit_ss->setText(QString::number(global_scene->shadowsampling));
    ui->listProMat->setDisabled(false);
    global_scene->mode = 1;
    connect(ui->comboBox_filtre, SIGNAL(currentIndexChanged(int)), this, SLOT(setFiltre(int)));
    this->affLightTab();
    this->affObjTab();
    this->affMatTab();
}

void MainWindow::refObjTab()
{
    while (ui->listObject->rowCount() > 0)
        ui->listObject->removeRow(0);
    this->affObjTab();
}

void MainWindow::refMatTab()
{
    while (ui->listMat->rowCount() > 0)
        ui->listMat->removeRow(0);
    this->affMatTab();
}

void MainWindow::refLightTab()
{
    while (ui->listLight->rowCount() > 0)
        ui->listLight->removeRow(0);
    this->affLightTab();
}

void MainWindow::affMatTab()
{
    int i = 0;
    while (i < int(global_scene->matList.size()))
    {
        ui->listMat->insertRow(i);
        ui->listMat->setItem(i, 0, new QTableWidgetItem(global_scene->matList[i]->name, 1));
        i++;
    }
}

void MainWindow::affObjTab()
{
   int i = 0;
   while (i < int(global_scene->objectList.size()))
    {
       ui->listObject->insertRow(i);
       ui->listObject->setItem(i, 0, new QTableWidgetItem(global_scene->objectList[i]->name, 1));
       i++;
   }
}

void MainWindow::affLightTab()
{
    int i = 0;

    while (i < int(global_scene->lightList.size()))
    {
        ui->listLight->insertRow(i);
        ui->listLight->setItem(i, 0, new QTableWidgetItem(QString::number(global_scene->lightList[i]->intensity), 1));
        i++;
    }
}

void MainWindow::on_editButtonObj_2_clicked()
{
    if (this->objSelect != -1)
    {
        global_scene->objectList.erase(global_scene->objectList.begin() + this->objSelect);
        global_scene->objectCount -= 1;
        this->refObjTab();
    }
}

void MainWindow::on_editButtonObj_4_clicked()
{
    this->popup = new MyPopup(this);
    popup->set_ui_selectobj();
    this->refObjTab();
}

void MainWindow::on_editButtonObj_5_clicked()
{
    this->popup = new MyPopup(this);
    popup->set_ui_addmat();
    this->refObjTab();
}

void MainWindow::on_editButtonObj_6_clicked()
{
    if (ui->listMat->currentRow() >= 0)
    {
        this->popup = new MyPopup(this);
        popup->set_ui_editmat(ui->listMat->currentRow());
        this->refObjTab();
    }
}

void MainWindow::on_saveButton_clicked()
{

}

void MainWindow::on_loadButton_2_clicked()
{
    if (this->is_scene_init == 1)
    {
        delete(global_scene);
        ui->renderButton->setDisabled(true);
        ui->saveButton->setDisabled(true);
    }
    this->is_scene_init = 0;
}

void MainWindow::on_comboBox_ao_activated(int index)
{
    if (index != 1)
    {
        ui->label_11->setDisabled(false);
        global_scene->booleansoftshadow = true;
        ui->lineEdit_ss->setDisabled(false);
    }
    else
    {
        ui->label_11->setDisabled(true);
        global_scene->booleansoftshadow = false;
        ui->lineEdit_ss->setDisabled(true);
    }
}

void MainWindow::on_lineEdit_ss_textChanged(const QString &arg1)
{
    global_scene->shadowsampling = arg1.toInt();
}

void MainWindow::affProceduralMat()
{
    ui->listProMat->insertRow(0);
    ui->listProMat->setItem(0, 0, new QTableWidgetItem("Marble", 1));
    ui->listProMat->insertRow(1);
    ui->listProMat->setItem(1, 0, new QTableWidgetItem("Circle", 1));
    ui->listProMat->insertRow(2);
    ui->listProMat->setItem(2, 0, new QTableWidgetItem("Wood", 1));
    ui->listProMat->insertRow(3);
    ui->listProMat->setItem(3, 0, new QTableWidgetItem("GayPride", 1));
    ui->listProMat->insertRow(4);
    ui->listProMat->setItem(4, 0, new QTableWidgetItem("Turbulence", 1));
    ui->listProMat->insertRow(5);
    ui->listProMat->setItem(5, 0, new QTableWidgetItem("Color Circle"));
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->listProMat->currentRow() >= 0)
    {
        this->popup = new MyPopup(this);
        popup->set_ui_promat(ui->listProMat->currentRow());
        this->refObjTab();
    }
}

void MainWindow::setFiltre(int index)
{
    global_scene->mode = index + 1;
}
