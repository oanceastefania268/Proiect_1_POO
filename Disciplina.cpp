#include<iostream>
#include<cstring>

#include "Disciplina.hpp"

void Disciplina::copiazaNume(const char *sursa) ///am creat o functie privata pentru a facilita copierea numelui in constructori
{
    if(sursa!=nullptr) ///am verificat ca sursa sa fie diferita de nullptr pentru a evita o eroare la strlen si strcpy
    {
        nume=new char[strlen(sursa)+1];
        strcpy(nume, sursa);
    }
    else
        nume=nullptr;
}

Disciplina::Disciplina() ///constructor implicit
{
    nume = nullptr;
    credite = 0;
}

Disciplina::Disciplina( const char *nume_, int credite_) ///constructor parametrizat unde am apelat si functia copiazaNume()
{
    copiazaNume(nume_);
    credite=credite_;
}

Disciplina::Disciplina( const Disciplina& other) ///constructor de copiere unde am apelat si functia copiazaNume()
{
    copiazaNume(other.nume);
    credite=other.credite;
}

Disciplina& Disciplina::operator=( const Disciplina& other) ///supraincarcarea operatorului de atribuire unde am apelat si functia copiazaNume()
{
    if(this!= &other)
    {
        delete[] nume;
        copiazaNume(other.nume);
        credite=other.credite;
    }
    return *this;
}

Disciplina::~Disciplina() ///destructor
{
    delete[] nume;
}

std::ostream& operator<<(std::ostream& os, const Disciplina& dis) ///supraincarcarea operatorului de afisare
{
    os<<"Nume disciplina: "<<dis.nume<<"\n"<<"Numar credite: "<<dis.credite<<"\n";
    return os;
}

const char *Disciplina::getNume() const { return nume;} ///getter pentru numele disciplinei
int Disciplina::getCredite() const{ return credite;} ///getter pentru numarul de credite
