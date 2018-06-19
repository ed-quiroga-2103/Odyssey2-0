//
// Created by estebandcg1999 on 18/06/18.
//

#ifndef CLIONTEST_RAID5CONTROLLER_H
#define CLIONTEST_RAID5CONTROLLER_H

#include <iostream>
#include <QString>
#include <QDir>
#include <fstream>


class RAID5Controller {

public:
    std::string getOtherBlock(std::string parityBlock, std::string infoBlock);

    std::string GetBinaryStringFromHexString (std::string sHex);

    std::string GetHexStringFromBinaryString (std::string sBin);

    void createVirtualDisks ();

    QByteArray saveFile (std::string fileName);

    QString getInfoBinaray(QString hex);

    QString getInfoHex(QByteArray array);

    int getBlockLength(QString infoBinary);

    std::string getParityBlock(std::string firstBlock, std::string secondBlock, int blockLength);

    void writeFiles(std::string firstBlock,std::string name,int num);

    std::string getBlock(std::string fileName, int num);

    bool seek(std::string fileName);

    void read(std::string fileName);

    void write(std::string fileName);

};


#endif //CLIONTEST_RAID5CONTROLLER_H
