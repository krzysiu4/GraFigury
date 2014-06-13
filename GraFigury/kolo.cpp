#include "kolo.h"
#include <cmath>
#include <QTextStream>

using namespace std;

Kolo::Kolo()
{
    r = 0;
}


Kolo::Kolo(float x_, float y_, float r_) : Figura(x_,y_)
{
    r = r_;
    ustawOmega(0);
    typ = KOLO;
}

Kolo::~Kolo()
{
}

void Kolo::rysuj()
{
    glLoadIdentity();
    glTranslatef(x,y,0);
    glColor4fv(kolor);
    int num_segments = r*20;                                                    // smuklosc okręgu
    float theta = 2 * 3.1415926 / float(num_segments);
    float tangetial_factor = tan(theta);//calculate the tangential factor
    float radial_factor = cos(theta);//calculate the radial factor
    float x2 = r;//we start at angle = 0
    float y2 = 0;

    glBegin(GL_POLYGON);
    for(int i = 0; i < num_segments; i++)
    {
        glVertex2f(x2, y2);//output vertex
        float tx = -y2;
        float ty = x2;
        //add the tangential vector
        x2 += tx * tangetial_factor;
        y2 += ty * tangetial_factor;
        //correct using the radial factor
        x2 *= radial_factor;
        y2 *= radial_factor;
    }
    glEnd();
}

float Kolo::zwrocRozmiar()
{
    return 2*r;
}

bool Kolo::czyNalezydoFigury(float x_, float y_)
{
    float dx = (x_-x)*(x_-x);
    float dy = (y_-y)*(y_-y);
    return (sqrt(dx+dy) < r);
}

bool Kolo::czyKolizja(Figura *druga)
{
    if(druga->zwrocTyp() == KOLO)
    {
    return (odleglosc(druga) < r + druga->zwrocodlegloscDoKolizji()); // r+r
    }
    return false;
}

void Kolo::zmienRozmiar(float dr)
{
    r += dr;
}

float Kolo::zwrocPole()
{
    return 3.14*r*r;
}

void Kolo::zmienPole(float dp)
{
    float pole = zwrocPole() + dp;

    zmienRozmiar(sqrt(pole/3.14)-r);
}

int Kolo::zwrocTyp()
{
    return KOLO;
}

double Kolo::zwrocodlegloscDoKolizji()
{
    return r;
}

QDataStream & operator <<(QDataStream &stream, Kolo *kolo)
{

    stream << kolo->x;
    stream << kolo->y;
    stream << kolo->r;
    stream << kolo->kolor[0];
    stream << kolo->kolor[1];
    stream << kolo->kolor[2];
    stream << kolo->kolor[3];
    stream << kolo->predkosc[0];
    stream << kolo->predkosc[1];
    stream << kolo->typ;
    return stream;
}

QDataStream & operator >>(QDataStream &stream, Kolo *kolo)
{

    stream >> kolo->x;
    stream >> kolo->y;
    stream >> kolo->r;
    stream >> kolo->kolor[0];
    stream >> kolo->kolor[1];
    stream >> kolo->kolor[2];
    stream >> kolo->kolor[3];
    stream >> kolo->predkosc[0];
    stream >> kolo->predkosc[1];
    stream >> kolo->typ;
    return stream;
}

QDataStream & operator <<(QDataStream &stream, QList <Kolo*> &listaKol)
{

    stream << listaKol.size(); // Pierwszy element to dlugosc listy

    for(int i=0; i<listaKol.size();i++)
    {
        Kolo *kolo = listaKol.at(i);
        stream << kolo->x;
        stream << kolo->y;
        stream << kolo->r;
        stream << kolo->kolor[0];
        stream << kolo->kolor[1];
        stream << kolo->kolor[2];
        stream << kolo->kolor[3];
        stream << kolo->predkosc[0];
        stream << kolo->predkosc[1];
        stream << kolo->typ;
    }
    return stream;
}

QDataStream & operator >>(QDataStream &stream, QList <Kolo*> &listaKol)
{

    int rozmiarListy;
    stream >> rozmiarListy;
    QTextStream out (stdout);
    out << rozmiarListy;

    for(int i=0; i<rozmiarListy;i++)
    {
        Kolo *kolo = new Kolo();

        stream >> kolo->x;
        stream >> kolo->y;
        stream >> kolo->r;
        stream >> kolo->kolor[0];
        stream >> kolo->kolor[1];
        stream >> kolo->kolor[2];
        stream >> kolo->kolor[3];
        stream >> kolo->predkosc[0];
        stream >> kolo->predkosc[1];
        stream >> kolo->typ;
        listaKol.append(kolo);
    }
    return stream;

}
