#include<iostream>


#include "Examen.hpp"
#include "Disciplina.hpp"

void Examen::copiazaDisciplina(const Disciplina *sursa) ///am creat o functie privata pentru a facilita copierea disciplinei
{
    if(sursa!=nullptr)
        disciplina_examen=new Disciplina(*sursa);
    else
        disciplina_examen=nullptr;
}

Examen::Examen() ///constructor implicit
{
    disciplina_examen=nullptr;
    nota=0.0;
}

Examen::Examen( const Disciplina* disciplina_examen_, float nota_) ///constructor parametrizat unde am folosit functia copiazaDisciplina()
{
    copiazaDisciplina(disciplina_examen_);
    nota=nota_;
}

Examen::Examen(const Examen& other)///constructor de copiere unde am folosit functia copiazaDisciplina()
{
    copiazaDisciplina(other.disciplina_examen);
    nota=other.nota;

}

Examen& Examen::operator=( const Examen& other)///operator de atribuire unde am folosit functia copiazaDisciplina()
{
    if(this!=&other)
    {
        delete disciplina_examen;

        copiazaDisciplina(other.disciplina_examen);

        nota=other.nota;
    }


    return *this;
}

Examen::~Examen() ///destructor
{
    delete disciplina_examen;
}

std::ostream& operator<<(std::ostream& os, const Examen& exam) ///operator de afisare
{
    if(exam.disciplina_examen!=nullptr)
        os<<"Nota din examen la disciplina "<< exam.disciplina_examen->getNume()<<" este "<<exam.nota<<"\n";

    return os;
}

float Examen::getNota() const ///getter pentru nota examenului
{
    return nota;
}

Disciplina* Examen::getDisciplina() const { return disciplina_examen; }


/**
    Am implementat o functie de rotunjire a notei, folosita in functia mediei ponderate si in functia totalului de credite din clasa Student.
    Este folosita pentru a rotunji nota (8,5=9; 8,4=8), asigurand astfel corectitudinea calcului mediei ponderate.
**/
float Examen::rotunjire() const
{
    return (float)(int)(nota+0.5f);

}
