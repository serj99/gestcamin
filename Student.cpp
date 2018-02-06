#include "Student.h"

Student::Student()
{
    nume=prenume=facultate=specializare=CNP="null";
    numarcamera=-1;
    plati.push_back("null");
}

void Student::SetValori(string n, string p, string f, string s, string cnp)
{
    nume=n;
    prenume=p;
    facultate=f;
    specializare=s;
    CNP=cnp;
}

void Student::Setnumarcamera(int nc)
{
    numarcamera=nc;
}

void Student::Setplati(string plata)
{
    plati.push_back(plata);
}

string Student::Getnume()
{
    return nume;
}

string Student::Getprenume()
{
    return prenume;
}

int Student::Getnumarcamera()
{
    return numarcamera;
}

string Student::Getplati()
{
    return plati.back();
}

