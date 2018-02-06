#include <string>
#include <vector>
using namespace std;

class Camera
{

    /**
     * Poate fi de tipul
     * "dubla cu baie proprie" sau
     * "tripla cu baie proprie" sau
     * "tripla cu baie proprie, fara frigider, fara TV"
     */
    string tip;

    /**
     * Cei care inchiriaza camera
     * maximum 3 persoane
     */
    vector<string> nume;

    //de la 0 - parterul pana la 4
    int etaj;

    public:
        Camera();
        void Settip(string);
        void Adauganume(string);
        void Setnume(vector<string>);
        void Setetaj(int);
        string Gettip();
        vector<string> Getnume();
        int Getetaj();
};

