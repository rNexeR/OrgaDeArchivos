#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //ofstream myfile ("example.txt",ios::app);
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
      myfile << "Juan";
      myfile.close();
    }
    else cout << "Unable to open file";


    string line;
    ifstream myfileread ("example.txt");
    if (myfileread.is_open())
    {
      while ( getline (myfileread,line) )
      {
        cout << line << '\n';
      }
      myfileread.close();
    }

    else cout << "Unable to open file";


    ///// SEEK
    ///
    streampos begin,end;
    ifstream myfile3 ("example.txt");
    begin = myfile3.tellg();
    myfile3.seekg (0, ios::end);
    end = myfile3.tellg();
    myfile3.close();
    cout << "end: " << (end) << ".\n";
    cout << "Begin: " << (begin) << ".\n";
    cout << "size is: " << (end-begin) << ".\n";

    char name[10];
     cout << "Size of NAME : " << sizeof(name) << endl;
    strcpy(name, "john");
    ofstream output_file("students.data", ios::binary);
    output_file.write(name, sizeof(name));
    output_file.close();
    cout << "Size of NAME : " << sizeof(name) << endl;
    ifstream myfile4 ("students.data", ios::binary);
    begin = myfile4.tellg();
    myfile4.seekg (0, ios::end);
    end = myfile4.tellg();
    myfile4.close();
    cout << "NAME size is: " << (end-begin) << ".\n";


    return a.exec();
}
