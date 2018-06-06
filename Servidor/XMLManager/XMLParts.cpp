//
// Created by eduardo on 05/06/18.
//

#include "XMLParts.h"

#include <iostream>
#include <sstream>
#include "XMLParts.h"
#include "pugixml.hpp"
#include "string"

XMLDoc::XMLDoc(string rootStr){

    pugi::xml_node root = this->append_child(rootStr.c_str());
    rootNode = rootStr;
}

//Metodo root

void XMLDoc::newChild(string dataName, string data) {

    pugi::xml_node parent = this->child(rootNode.c_str());
    pugi::xml_node child = parent.append_child(dataName.c_str());
    child.append_child(pugi::node_pcdata).set_value(data.c_str());


}

void XMLDoc::saveXML(string name) {

    this->save_file(name.c_str());

}

string XMLDoc::toString() {

    this->print(writer);

    return writer.print();

}

string XMLDoc::remove_extra_whitespaces(string a)
{
    string tab = "\t";
    string line = "\n";

    std::stringstream output;

    for(int i = 0; i < a.length(); i++){


        string comp;
        comp.push_back(a[i]);

        if(comp != tab && comp != line){

            output << a[i];

        }

    }

    return output.str();

}

