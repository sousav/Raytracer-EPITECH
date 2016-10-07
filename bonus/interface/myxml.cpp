#include "myxml.h"

MyXML::MyXML(QStringList file)
{
    this->file = file;
}

QString MyXML::get_field(const char *_field)
{
    QString     field = QString::fromUtf8(_field);
    int         field_i = 0;
    QStringList parent = field.split(":");
    int         parent_i = 0;
    QString     out = NULL;
    QString     error_msg;

    while (field_i < this->file.length())
    {
        QRegularExpression      regexp("<" + parent.at(parent_i) + ">*");
        QRegularExpressionMatch match = regexp.match(this->file.at(field_i));
        if (match.hasMatch())
        {
            parent_i++;
            if (parent_i >= parent.length())
            {
                out = this->file.at(field_i);
                int beg = 0;
                while (out.at(beg++) != '>');
                int end = 0;
                while (out.at(beg + end++) != '<');
                out = out.mid(beg, --end);
                return (out);
            }
        }
        field_i++;
    }
    error_msg = "Could not find xml field :\n";
    parent_i = 0;
    while (parent_i < parent.length())
    {
        error_msg = error_msg + "<" + parent.at(parent_i++) + ">\n";
    }
    QMessageBox::information(0, "Field not found", error_msg);
    return (NULL);
}
