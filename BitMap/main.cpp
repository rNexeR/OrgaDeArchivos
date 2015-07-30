#include <QCoreApplication>
#include <fstream>
#include <iostream>
using namespace std;


int set_in_use(int in_use,int car_num)
{
    in_use= in_use | 1<<car_num;
    return in_use;
}

int is_in_use(int in_use,int car_num)
{
    return in_use & 1<<car_num;
}

int set_unused(int in_use,int car_num)
{
    in_use = in_use & ~(1<<car_num);
    return in_use;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int bitmap =1;
    cout <<bitmap;
    //bitmap = set_in_use(bitmap,0);
    //bitmap = set_in_use(bitmap,4);
    //bitmap = set_unused(bitmap,0);
     //bitmap = is_in_use(bitmap,0);
     cout << is_in_use(bitmap,3);

    ofstream output_file("bitmap.data", ios::binary);
    output_file.write((char*)&bitmap,sizeof(bitmap));
    output_file.close();

    return a.exec();
}
