#include "edirectory.h"

EDirectory::EDirectory(QString name) : ExplorerObject(name)
{
    fileList = new SerpentList<ExplorerObject*>();
}

bool EDirectory::isDirectory()
{
    return true;
}
