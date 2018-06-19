//
// Created by estebandcg1999 on 18/06/18.
//

#include "RAID5Controller.h"

#include <iostream>
#include <QString>
#include <QDir>
#include <fstream>

std::string RAID5Controller::getOtherBlock(std::string parityBlock, std::string infoBlock){
    std::string newBlock = "";
    for (int i = 0; i < parityBlock.length(); i++) {
        if ((parityBlock[i] == '1') && (infoBlock[i] == '1'))
            newBlock.append("0");
        else if ((parityBlock[i] == '1') && (infoBlock[i] == '0'))
            newBlock.append("1");
        else if ((parityBlock[i] == '0') && (infoBlock[i] == '1'))
            newBlock.append("1");
        else if ((parityBlock[i] == '0') && (infoBlock[i] == '0'))
            newBlock.append("0");
    }
    return newBlock;
}

std::string RAID5Controller::GetBinaryStringFromHexString (std::string sHex)
{
    std::string sBin = "";
    for (int i = 0; i < sHex.length (); ++i)
    {
        switch (sHex [i])
        {
            case '0': sBin.append ("0000"); break;
            case '1': sBin.append ("0001"); break;
            case '2': sBin.append ("0010"); break;
            case '3': sBin.append ("0011"); break;
            case '4': sBin.append ("0100"); break;
            case '5': sBin.append ("0101"); break;
            case '6': sBin.append ("0110"); break;
            case '7': sBin.append ("0111"); break;
            case '8': sBin.append ("1000"); break;
            case '9': sBin.append ("1001"); break;
            case 'a': sBin.append ("1010"); break;
            case 'b': sBin.append ("1011"); break;
            case 'c': sBin.append ("1100"); break;
            case 'd': sBin.append ("1101"); break;
            case 'e': sBin.append ("1110"); break;
            case 'f': sBin.append ("1111"); break;
        }
    }
    return sBin;
}

std::string RAID5Controller::GetHexStringFromBinaryString (std::string sBin)
{
    std::string sHex = "";
    for (int i = 0; i < sBin.length(); i = i + 4)
    {
        if (sBin.substr(i,4) == "0000")
            sHex.append ("0");
        else if (sBin.substr(i,4) == "0001")
            sHex.append ("1");
        else if (sBin.substr(i,4) == "0010")
            sHex.append ("2");
        else if (sBin.substr(i,4) == "0011")
            sHex.append ("3");
        else if (sBin.substr(i,4) == "0100")
            sHex.append ("4");
        else if (sBin.substr(i,4) == "0101")
            sHex.append ("5");
        else if (sBin.substr(i,4) == "0110")
            sHex.append ("6");
        else if (sBin.substr(i,4) == "0111")
            sHex.append ("7");
        else if (sBin.substr(i,4) == "1000")
            sHex.append ("8");
        else if (sBin.substr(i,4) == "1001")
            sHex.append ("9");
        else if (sBin.substr(i,4) == "1010")
            sHex.append ("a");
        else if (sBin.substr(i,4) == "1011")
            sHex.append ("b");
        else if (sBin.substr(i,4) == "1100")
            sHex.append ("c");
        else if (sBin.substr(i,4) == "1101")
            sHex.append ("d");
        else if (sBin.substr(i,4) == "1110")
            sHex.append ("e");
        else if (sBin.substr(i,4) == "1111")
            sHex.append ("f");
    }
    return sHex;
}

void RAID5Controller::createVirtualDisks() {

    /**
     * Crea las carpetas que van a simular los discos del RAID5 en el sistema de archivos
     */

    QString path ="/home/estebandcg1999/Downloads/RAI5Simulation-master"; ///Hay que cambiarla
    QString discosvirtuales[] = {"DiscoVirtual1","DiscoVirtual2","DiscoVirtual3"};

    for(int i = 0; i<3 ;i++){
        QDir dir(path+"/"+discosvirtuales[i]);
        if (!dir.exists()) {
            dir.mkpath(".");
        }
    }

}

QByteArray RAID5Controller::saveFile (std::string fileName){

    std::string directory = "/home/estebandcg1999/Downloads/RAI5Simulation-master/"+fileName+".mp4";
    QFile file(directory.c_str());
    QByteArray array;
    file.open((QIODevice::ReadOnly));
    array = file.readAll();
    QString information = array.toBase64().constData();
    file.close();
    return array;

}

QString RAID5Controller::getInfoBinaray(QString hex){

    QString infobinary = QString::fromStdString(GetBinaryStringFromHexString(hex.toStdString()));
    return infobinary;

}
QString RAID5Controller::getInfoHex(QByteArray array){

    QString infohexadecimal = QString(array.toHex());
    return infohexadecimal;

}

int RAID5Controller::getBlockLength(QString infoBinary){

    int blockLength = infoBinary.toStdString().length()/2;
    return blockLength;

}

std::string RAID5Controller::getParityBlock(std::string firstBlock, std::string secondBlock, int blockLength) {

    std::string thirdBlock; ///Bloque de Paridad
    for (int i = 0; i < blockLength; i++) {
        if ((firstBlock[i] == '1') && (secondBlock[i] == '1'))
            thirdBlock.append("0");
        else if ((firstBlock[i] == '1') && (secondBlock[i] == '0'))
            thirdBlock.append("1");
        else if ((firstBlock[i] == '0') && (secondBlock[i] == '1'))
            thirdBlock.append("1");
        else if ((firstBlock[i] == '0') && (secondBlock[i] == '0'))
            thirdBlock.append("0");
    }
    return thirdBlock;
}

void RAID5Controller::writeFiles(std::string firstBlock,std::string name,int num){

    std::string fileName = "/home/estebandcg1999/Downloads/RAI5Simulation-master/DiscoVirtual"+std::to_string(num)+"/"+name+std::to_string(num)+".txt";

    QFile ArchivoDV1(fileName.c_str());
    ArchivoDV1.open(QIODevice::WriteOnly | QIODevice::ReadOnly);
    ArchivoDV1.write(QByteArray::fromStdString(firstBlock));
    ArchivoDV1.close();

}

std::string RAID5Controller::getBlock(std::string fileName, int num) {

    std::string FileName =
            "/home/estebandcg1999/Downloads/RAI5Simulation-master/DiscoVirtual" + std::to_string(num) + "/" + fileName + std::to_string(num) + ".txt";

    std::string bloque;
    std::ifstream myfile(FileName);
    if (myfile.is_open()) {
        while (myfile.good()) {
            getline(myfile, bloque);
            //std::cout << line << std::endl;
        }
        myfile.close();
    }

    return bloque;

}

void RAID5Controller::write(std::string fileName){

    QByteArray array = saveFile(fileName);

    /**
     * Conversor a binario
     */

    QByteArray transformation = array;
    QString infohexadecimal = getInfoHex(transformation);
    QString infobinary = getInfoBinaray(infohexadecimal);

    /**
     * Tenemos tres discos virtuales, por lo que cada archivo tendra dos archivos de información y uno de paridad
     */

    int blocklenght = getBlockLength(infobinary);
    std::string firstBlock = infobinary.toStdString().substr(0,blocklenght);
    std::string secondBlock = infobinary.toStdString().substr(blocklenght,blocklenght);
    std::string thirdBlock = getParityBlock(firstBlock,secondBlock,blocklenght);

    writeFiles(firstBlock,fileName,1);
    writeFiles(secondBlock,fileName,2);
    writeFiles(thirdBlock,fileName,3);

}

bool RAID5Controller::seek(std::string fileName){

    std::string block1 = getBlock(fileName,1);
    std::string block2 = getBlock(fileName,2);
    std::string block3 = getBlock(fileName,3);
    int dataLost = 0;
    if (block1 == "")
        dataLost++;
    if (block2 == "")
        dataLost++;
    if (block3 == "")
        dataLost++;
    if (dataLost < 2)
        return false;
    std::cout << "Se han perdido dos bloques de informacion";
    return true;

}

void RAID5Controller::read(std::string fileName) {

    std::string block1 = getBlock(fileName,1);
    std::string block2 = getBlock(fileName,2);
    std::string block3 = getBlock(fileName,3);

    std::string originalInfoBin;

    if (block1 == "")
        originalInfoBin = getOtherBlock(block3, block2).append(block2);
    else if (block2 == "")
        originalInfoBin = block1.append(getOtherBlock(block3, block1));
    else
        originalInfoBin = block1.append(block2);

    std::string originalInfoHex = GetHexStringFromBinaryString(originalInfoBin);

    QByteArray originalInfoArray;
    originalInfoArray = QByteArray::fromHex(originalInfoHex.c_str());
    QString arrayInfo = originalInfoArray.toBase64().constData();

}