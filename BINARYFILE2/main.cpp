#include <QCoreApplication>

#include <fstream>
#include <iostream>

using namespace std;

typedef struct reg{
    char name[256];
}reg_t;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int block[128];
    ofstream output_file("file.data", ios::binary);
    for(int i=0;i<5;i++){
    output_file.write((char*)block,sizeof(block));
    }
    output_file.close();
    reg_t registro1;
    reg_t registro2;
    reg_t registro3;
    memset (registro1.name,'a',256);
    memset (registro2.name,'b',256);
    memset (registro3.name,'c',256);
    output_file.open("file.data", ios::in | ios::out | ios::binary);
    output_file.write((char*)&registro1,sizeof(registro1));
    output_file.write((char*)&registro2,sizeof(registro1));
    output_file.write((char*)&registro3,sizeof(registro1));
    output_file.close();

    reg_t registro4;
    char buffer[512];
    ifstream input_file("file.data", ios::binary);
    input_file.read((char*)&buffer, sizeof(block));
    memcpy ( &registro4, buffer, sizeof(registro4) );
    ofstream output_reg("reg.data", ios::binary);
    output_reg.write((char*)&registro4,sizeof(registro4));
    output_reg.close();





    return a.exec();
}
