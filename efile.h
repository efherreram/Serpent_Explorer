#ifndef EFILE_H
#define EFILE_H
#include "explorerobject.h"
class EFile  : public ExplorerObject
{
public:
    EFile(QString name);
    bool isDirectory();
};

#endif // EFILE_H
