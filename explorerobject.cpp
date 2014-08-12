#include "explorerobject.h"

ExplorerObject::ExplorerObject(QString name)
{
    this->name = name;
    this->createDate = QDate::currentDate();
    this->modifyDate = QDate::currentDate();
}
