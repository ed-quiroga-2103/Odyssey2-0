//
// Created by eduardo on 05/06/18.
//

#ifndef XMLMANAGER_XMLMANAGER_H
#define XMLMANAGER_XMLMANAGER_H

#include "XMLParts.h"
#include "string"

class XMLManager {
public:
    //Creating documents
    XMLDoc* newXMLDoc(int opnum, string CDATA);
    void saveXML(XMLDoc doc, string name);

    //Parsing documents
    string getCDATA(string str);
    int getOpNum(string str);


};


#endif //XMLMANAGER_XMLMANAGER_H
