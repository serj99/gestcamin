void StergereEcran();
void RevenireMeniu();
void SetareTipSiEtajCamere(Camera []);
string CalculeazaTipCamera(int);
void AdaugareStudentInCamin(Camera [], vector<Student> &, bool);
void VerificareCamereLibere(Camera []);
void PreiaInfo(string &, string &, string &, string &, string &,
                    int &, string &);
void PlataStudent(vector<Student> &);
void ListaNeplatitori(vector<Student>);
void StergereStudent(Camera [], vector<Student> &);

void StergereEcran()
{
    cout << "\033[2J\033[1;1H";
}

void RevenireMeniu()
{
    string str;
    cout<<endl<<"Apasa oricare tasta pentru a reveni la meniul anterior!"<<endl;
    cin>>str;
}

void PreiaInfo(string &n, string &p, string &fac, string &spec,
                    string &cnp, int &nrcam, string &dataplata)
{
    cout<<"Care sunt datele studentului?"<<endl;
    cout<<"Nume: "; cin>>n;
    cout<<"Prenume: "; cin>>p;
    cout<<"Cod numeric personal: "; cin>>cnp;
    cout<<"Facultate: "; cin>>fac;
    cout<<"Specializare: "; cin>>spec;
    cout<<"Numarul camerei: "; cin>>nrcam;
    cout<<"Data platii: "; cin>>dataplata;
}

/**
 * Pentru lista initiala
 * Administratorul primeste lista cu studenti admisi in camin.
 * Verifica informatiile din lista cu cele oferite de student
 * ca mai apoi sa introduca valorile.
 * Fiecare student trebuie sa isi confirme locul si sa achite
 * plata pentru octombrie.
 */
void AdaugareStudentInCamin(Camera C[], vector<Student> &S, bool listainitiala)
{
    Student stud;
    string n, p, fac, spec, cnp;
    int nrcam;
    string dataplata;

    /**
     * Daca nu este vorba de lista initiala ci dupa lista initiala
     * pentru anul universitar in derulare i se ofera posibilitatea
     * studentului de a alege dintre camerele libere
     */
    if(listainitiala==false)
        VerificareCamereLibere(C);

    PreiaInfo(n, p, fac, spec, cnp, nrcam, dataplata);
    stud.SetValori(n, p, fac, spec, cnp);
    stud.Setnumarcamera(nrcam);
    stud.Setplati(dataplata);

    cout<<"Studentul "<<n<<" "<<p<<" a fost cazat"
         " cu succes in camera "<<nrcam<<"!"<<endl;

    //adaugare student in camera
    C[nrcam].Adauganume(n);

    //adaugare obiect de tip Student la vectorul de obiecte Student
    S.push_back(stud);

}

void VerificareCamereLibere(Camera C[])
{
    //fiecare vector va contine camerele disponibile
    vector<int> camdubla, camtripla, camtripla_fara;
    vector<int> ::iterator it;

    for(int i=1; i<=105; i++)
        if(C[i].Getnume().size()<4)
        {
            if(C[i].Getetaj()==0 || C[i].Getetaj()==1)
                camdubla.push_back(i);
            else
                if(C[i].Getetaj()==2 || C[i].Getetaj()==3)
                    camtripla.push_back(i);
                else
                    if(C[i].Getetaj()==4)
                        camtripla_fara.push_back(i);
        }

    cout<<"Camere duble cu baie proprie disponibile:"<<endl;
    for(it=camdubla.begin(); it!=camdubla.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"Camere triple cu baie proprie disponibile:"<<endl;
    for(it=camtripla.begin(); it!=camtripla.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"Camere triple cu baie proprie (fara tv, fara frigider) disponibile:"<<endl;
    for(it=camtripla_fara.begin(); it!=camtripla_fara.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}

/**
 * Caminul dispune de parter + 4 etaje, fiecare etaj cu 21 de camere.
 * Parter(etajul 0) si etajul 1 - camere duble cu baie proprie
 * Etajul 2 si 3 - camere triple cu baie proprie,
 * Etajul 4 - camere triple cu baie proprie, fara tv, fara frigider
 */
void SetareTipSiEtajCamere(Camera C[])
{
    int i, j, prima_cam=1, ultima_cam=21;
    for(i=0; i<=4; i++)
    {
        for(j=prima_cam; j<=ultima_cam; j++)
        {
            //setare etaj
            C[j].Setetaj(i);

            //setare tipul camerei in functie de etaj
            C[j].Settip(CalculeazaTipCamera(i));
        }
        prima_cam=ultima_cam+1;
        ultima_cam=prima_cam+20;
    }
}

string CalculeazaTipCamera(int etaj)
{
    if(etaj==0 || etaj==1)
        return "camera dubla cu baie proprie";
    else
        if(etaj==2 || etaj==3)
            return "camera tripla cu baie proprie";
        else
            return "camera tripla cu baie proprie, fara tv, fara frigider";
}

void ListaNeplatitori(vector<Student> S)
{
    vector<Student>::iterator it;
    int lunaverificare;
    string str;
    bool toti_au_platit=true;

    /*
    Plata se poate verifica pentru luna curenta.
    Automat un student este evacuat din camera daca nu plateste pana pe 1
    a lunii urmatoare.
    */
    cout<<"Pentru ce luna vrei sa verifici plata? "; cin>>lunaverificare;

    for(it=S.begin(); it!=S.end(); ++it)
    {
        str=(*it).Getplati();
        if((str.at(3)-'0')*10+(str.at(4)-'0')!=lunaverificare-1)
        {
            cout<<"Studentul "<<(*it).Getnume()<<" "
                   "din camera "<<(*it).Getnumarcamera()<<" nu a "
                   " platit pentru luna "<<lunaverificare<<"!"<<endl;
            toti_au_platit=false;
        }
    }
    if(toti_au_platit)
      cout<<"Nu exista student care sa aiba restanta la plata caminului!"<<endl;

}

void StergereStudent(Camera C[], vector<Student> &S)
{
    string nume;
    vector<Student>::iterator it;
    int i, nr=0;
    bool valid=false;
    vector<string> n;
    vector<string>::iterator itr;

    cout<<"Numele studentului pe care doresti sa il elimini din baza de date: ";
    cin>>nume;
    for(it=S.begin(); it!=S.end(); ++it)
    {
        nr++;
        if((*it).Getnume()==nume)
        {
            valid=true;
            S.erase(S.begin()+nr);
            cout<<"Studentul "<<nume<<" a fost eliminat "
                  "cu succes din baza de date a studentilor!"<<endl;
            break;
        }
    }
    if(!valid)
        cout<<"Studentul "<<nume<<" nu exista in baza de date!"<<endl;
    else

        //studentul trebuie eliminat si din registrul camerei

        //parcurgem toate camerele
        for(i=1; i<=105; i++)
        {
            n=C[i].Getnume();
            nr=0;

            //parcurgem numele studentilor cazati in camera respectiva
            for(itr=n.begin(); itr!=n.end(); ++itr)
            {
                nr++;
                if(*itr==nume)
                {
                    //stergem studentul din camera
                    n.erase(n.begin()+nr);
                    C[i].Setnume(n);
                    cout<<"Studentul "<<nume<<" a fost eliminat "
                          "cu succes din registrul camerelor!"<<endl;
                    break;
                }
            }
        }
}

void PlataStudent(vector<Student> &S)
{
    vector<Student>::iterator it;
    string nume, dataplata;
    bool valid=false;
    cout<<"Numele studentului: "; cin>>nume; 

    //parcurgerea tuturor obiectelor de tip Student
    for(it=S.begin(); it!=S.end(); ++it)
        if((*it).Getnume()==nume)
        {
            valid=true;
            cout<<"Data in care s-a facut plata: "; cin>>dataplata; 
            (*it).Setplati(dataplata);
            cout<<"Studentul "<<nume<<" a efectuat cu succes plata in data de "<<dataplata<<" !"<<endl;
        }
    if(!valid)
        cout<<"Studentul "<<nume<<" nu exista in baza de date!"<<endl;
}



