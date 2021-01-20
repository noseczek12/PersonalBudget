#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XmlFile {
    const string FILENAME;
public:
    XmlFile(string fileName) : FILENAME(fileName) {};
    string getFileName();
    //bool isFileEmpty();
};

#endif
