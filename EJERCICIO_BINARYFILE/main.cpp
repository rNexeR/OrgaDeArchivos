#include <QCoreApplication>

#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
class student2{
    char age[10];
    int age2;
    char age1;
};

typedef struct student{
    char name[10];
    int age;


}student_t;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    student_t apprentice;
    student2 apprentice2;

        cout <<"Size of apprentice2 : "<< sizeof(apprentice2)<<endl;
        strcpy(apprentice.name, "          ");
        strcpy(apprentice.name, "john      ");
        apprentice.age = 21;
        string car = "camilo rivera pineda";
        vector<char> supo;
        supo.push_back('c');
        supo.push_back('a');
        vector<char> supa;
        supa.push_back('1');
        supa.push_back('2');
        supa.push_back('m3');
        supa.push_back('4');

        supo.push_back('m');
        supo.push_back('i');
        supo.push_back('l');
        supo.push_back('o');




        supa.push_back('5');
        supa.push_back('6');

        // Serializing struct to student.data
        ofstream output_file("students.data", ios::binary);
        output_file.write((char*)&supo[0],(sizeof(supo[0])*supo.size()));
        output_file.close();
        cout <<"Size of apprentice : "<< sizeof(car)<<endl;

        // Reading from it
        ifstream input_file("students.data", ios::binary);
        student_t master;
        input_file.read((char*)&master, sizeof(master));
            cout << "Name: " << master.name << endl;
            cout << "Age: " << master.age << endl;
            cout << endl << endl;




    return a.exec();
}
