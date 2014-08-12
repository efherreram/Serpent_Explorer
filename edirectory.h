#ifndef EDIRECTORY_H
#define EDIRECTORY_H
#include "explorerobject.h"
#include "serpentlist.h"

class EDirectory : public ExplorerObject
{
public:
    EDirectory(QString name);
    SerpentList<ExplorerObject*>* fileList;
    bool isDirectory();
};

#endif // EDIRECTORY_H
