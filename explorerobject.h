#ifndef EXPLOREROBJECT_H
#define EXPLOREROBJECT_H
#include <QString>
#include <QDate>
class ExplorerObject
{
public:
    ExplorerObject(QString name);
    QString name;
    QDate createDate, modifyDate;
    virtual bool isDirectory() = 0;
};

#endif // EXPLOREROBJECT_H
