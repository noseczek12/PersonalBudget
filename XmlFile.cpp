#include "XmlFile.h"

string XmlFile::getFileName()
{
    return FILENAME;
}

/*bool XmlFile::isFileEmpty()
{
    bool emptyFile = true;
    fstream xmlFile;
    xmlFile.open(getFileName().c_str(), ios::app);

    if (xmlFile.good() == true) {
        xmlFile.seekg(0, ios::end);
        if (xmlFile.tellg() != 0)
            emptyFile = false;
    }

    xmlFile.close();
    return emptyFile;
}
*/
