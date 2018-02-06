#include <string>
#include <vector>
using namespace std;

class Student
{
    string nume;
    string prenume;
    string facultate;
    string specializare;
    string CNP;

    //unde este cazat
    int numarcamera;

    /**
     * Fiecare element al vectorului este de forma "DD.MM.YY"
     * 07.11.2013 inseamna ca plata a fost achitata in ziua respectiva
     * Platile se achita intre 20 si 31 cu o luna inainte
     */
    vector<string> plati;

public:
    Student();
    void SetValori(string, string, string, string, string);
    void Setnumarcamera(int);
    void Setplati(string);
    string Getnume();
    string Getprenume();
    int Getnumarcamera();
    string Getplati();
};

