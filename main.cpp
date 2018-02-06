#include <iostream>
#include <vector>
#include <string>
#include "Camera.h"
#include "Student.h"
#include "Functii.h"

int main()
{
    /**
     * Numerotarea camerelor incepe de la 1 si pana la 105
     * Declar 106 obiecte de tip Camera
     */
    Camera C[106];

    vector<Student> S;
    int n;

    SetareTipSiEtajCamere(C);
    while(1)
    {
        cout<<"Alege actiuni din meniul de mai jos!"<<endl;
        cout<<"1. Lista initiala, confirmarea locului si inchirierea camerei"<<endl;
        cout<<"2. Student nou pentru inchiriere dupa lista initiala"<<endl;
        cout<<"3. Efectuare plata student"<<endl;
        cout<<"4. Afisare lista cu studentii care inca n-au platit"<<endl;
        cout<<"5. Eliminare student din baza de date dupa renuntare sau neplata"<<endl;
        cout<<"6. Iesire"<<endl;
        cin>>n; 
        switch(n)
        {
            case 1:
                StergereEcran();
                AdaugareStudentInCamin(C, S, true); 
                break;
            case 2:
                StergereEcran();
                AdaugareStudentInCamin(C, S, false);
                break;
            case 3:
                StergereEcran();
                PlataStudent(S);
                break;
            case 4:
                StergereEcran();
                ListaNeplatitori(S);
                break;
            case 5:
                StergereEcran();
                StergereStudent(C, S);
                break;
            case 6:
                return 0;

        }
       RevenireMeniu();
       StergereEcran();
    }
}

