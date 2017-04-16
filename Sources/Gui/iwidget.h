#ifndef IWIDGET_H
#define IWIDGET_H

#include <QString>


class IWidget
{
public:
    virtual QString getFormatedString() = 0;
};

#endif // IWIDGET_H
