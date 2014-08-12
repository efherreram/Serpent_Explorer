#include "efile.h"

EFile::EFile(QString name) : ExplorerObject(name)
{

}

bool EFile::isDirectory()
{
    return false;
}
