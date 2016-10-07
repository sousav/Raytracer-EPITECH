#ifndef MYXML_H
#define MYXML_H

#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class MyXML
{
    public:
        MyXML(QStringList file);
        QString get_field(const char *field);

        QStringList file;
};

#else
    class MyXML;

#endif // MYXML_H
