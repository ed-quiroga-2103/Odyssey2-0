//
// Created by eduardo on 05/06/18.
//

#ifndef XMLMANAGER_XMLPARTS_H
#define XMLMANAGER_XMLPARTS_H

#include "pugixml.hpp"
#include "string"
using string = std::string;

class XMLWriter: public pugi::xml_writer{

public:
    std::string result;

    virtual void write(const void* data, size_t size)
    {
        result.append(static_cast<const char*>(data), size);
    }

    string print(){ return result; }

};

class XMLDoc: public pugi::xml_document {
private:
    XMLWriter writer;
    string rootNode;

public:
    XMLDoc(string root);
    void newChild(string dataName,string data);
    void saveXML(string name);
    string toString();
    string remove_extra_whitespaces(string a);

};

#endif //XMLMANAGER_XMLPARTS_H
