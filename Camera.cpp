#include "Camera.h"

Camera::Camera()
{
    tip="null";
    nume.push_back("null");
    etaj=-1;
}

void Camera::Settip(string t)
{
    tip=t;
}

void Camera::Adauganume(string n)
{
    nume.push_back(n);
}

void Camera::Setnume(vector<string> n)
{
    nume=n;
}

void Camera::Setetaj(int e)
{
    etaj=e;
}

string Camera::Gettip()
{
    return tip;
}

vector<string> Camera::Getnume()
{
    return nume;
}

int Camera::Getetaj()
{
    return etaj;
}


