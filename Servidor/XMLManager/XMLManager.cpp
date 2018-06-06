//
// Created by eduardo on 05/06/18.
//

#include "XMLManager.h"

using Node = pugi::xml_node;

XMLDoc* XMLManager::newXMLDoc(int opnum, string CDATA) {
    XMLDoc* doc = new XMLDoc(0);
    //doc->newChild(opnum, CDATA);
    return doc;
}

void XMLManager::saveXML(XMLDoc doc, string name) {
    doc.saveXML(name);
    return;
}

string XMLManager::getCDATA(string str) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(str.c_str());
    return doc.child("oddata").child("data").child("CData").text().get();
}

int XMLManager::getOpNum(string str) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_string(str.c_str());

    return std::stoi(doc.child("oddata").child("data").child("opnum").text().get());
}

XMLDoc *XMLManager::logInResponse(bool confirm, string username) {
    XMLDoc *doc = new XMLDoc("root");

    if(confirm) {

        doc->newChild("op", 0);
        doc->newChild("confirmation", std::to_string(confirm).c_str());
        Node user = doc->newChild("user");
        user.append_child("name").append_child(pugi::node_pcdata).set_value("REALNAME");
        user.append_child("username").append_child(pugi::node_pcdata).set_value(username.c_str());
        user.append_child("age").append_child(pugi::node_pcdata).set_value("19");
        user.append_child("email").append_child(pugi::node_pcdata).set_value("EMAIL");
        Node nots = doc->newChild("notifications");
        nots.append_child("notification").append_child("message").append_child(pugi::node_pcdata).set_value(
                "THIS IS A MESSAGE");
    }
    else{

        doc->newChild("confirmation", std::to_string(confirm).c_str());

    }
    return doc;

}
