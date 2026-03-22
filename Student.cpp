#include<iostream>
#include<cstring>

#include "Student.hpp"
#include "Examen.hpp"


void Student::copiazaNume(const char *sursa) ///am creat o functie privata pentru a facilita copierea numelui
{
    if(sursa!=nullptr)
    {
        nume=new char[strlen(sursa)+1];
        strcpy(nume, sursa);
    }
    else
        nume=nullptr;
}

void Student::copiazaExamene(Examen *sursa, int nr_sursa) ///am creat o functie privata pentru a facilita copierea examenelor
{
    if(sursa!=nullptr)
    {
        examene=new Examen[nr_sursa];

        for(int i=0;i<nr_sursa;i++)
            examene[i]=sursa[i];
    }
    else
        examene=nullptr;
}

Student::Student() ///constructor implicit
{
    nume=nullptr;
    examene=nullptr;
    nr_examene=0;
}

Student::Student(const char *nume_, Examen *examene_, int nr_examene_) ///constructor parametrizat unde am folosit functiile copiazaNume() si copiazaExamene()
{
    copiazaNume(nume_);

    copiazaExamene(examene_,nr_examene_);

    nr_examene=nr_examene_;

}

Student::Student(const Student& other) ///constructor de copiere unde am folosit functiile copiazaNume() si copiazaExamene()
{
    copiazaNume(other.nume);

    copiazaExamene(other.examene,other.nr_examene);

    nr_examene=other.nr_examene;

}

Student& Student::operator=(const Student& other) ///operator de atribuire unde am folosit functiile copiazaNume() si copiazaExamene()
{
    if(this!=&other)
    {
        delete[] nume;
        delete[] examene;

        copiazaNume(other.nume);

        copiazaExamene(other.examene, other.nr_examene);

        nr_examene=other.nr_examene;
    }

    return *this;
}

Student::~Student() ///destructor
{
    delete[] nume;
    delete[] examene;
}

std::ostream& operator<<(std::ostream& os, const Student& stud) ///operator de afisare
{
    os<<"Student: "<<stud.nume<<"\n";
    os<<"Nr examene: "<<stud.nr_examene<<"\n";
    os<<"Situatie: "<<"\n";
    for(int i=0;i<stud.nr_examene;i++)
        os<<stud.examene[i]<<"\n";

    return os;
}

/// Am implementat o functie ce calculeaza si afiseaza numarul total de credite al unui student

void Student::total_puncte_credit() const
{

    float total=0.0;
    for (int i=0;i<nr_examene;i++) ///bucla pentru a parcurge fiecare examen
    {
        if(examene[i].getDisciplina()!=nullptr)///daca disciplina examenului este valida
        {
            if(examene[i].getNota()>=5.00) ///daca nota in examen este mai mare sau egala cu 5
                total+=examene[i].getDisciplina()->getCredite()*examene[i].rotunjire(); ///la total de adauga produsul dintre numarul de credite al disciplinei si nota din examen rotunjita
        }
    }
    std::cout<<"Studentul "<<nume<<" a acumulat "<<total<<" puncte credit"<<"\n"; ///Se afiseaza pe ecran un mesaj corespunzator
}


///Am implementat o functie ce calculeaza si afiseaza media ponderata unui student

void Student::medie_ponderata() const
{
    int credite=0;
    float total=0.0;
    float media=0.0;
    for (int i=0;i<nr_examene;i++)///bucla pentru a parcurge fiecare examen
    {
        if(examene[i].getDisciplina()!=nullptr)///daca disciplina examenului este valida
        {
            credite+=examene[i].getDisciplina()->getCredite();///la credite se adauga numarul de credite al disciplinei

            if(examene[i].getNota()>=5.00)///daca nota din examen este mai mare sau egala cu 5
                total+=examene[i].getDisciplina()->getCredite()*examene[i].rotunjire();///la total de adauga produsul dintre numarul de credite al disciplinei si nota din examen rotunjita
        }
    }
    if(credite!=0)///daca creditele disciplinelor nu sunt nule (verificam pentru a evita impartirea la 0)
    {
        media=total/credite;///media ponderata este raportul dintre totalul de credite al studentului si totalul de credite al disciplinelor
        std::cout<<"Studentul "<<nume<<" are media ponderata "<<(float)(int)(media * 100 + 0.5)/100.0<<"\n"; /// afisam un mesaj corespunzator cu media rotunjita la doua zecimale
    }


}

///Am implementat o functie pentru a afisa la ce discipline are un student restante

void Student::restante() const
{
    bool da=false;///bool pentru a verifica daca are restante
    bool unu=false;///bool pentru a verifica daca restanta gasita este prima din lista

    if(examene!=nullptr && nr_examene!=0)
    {
        for (int i=0;i<nr_examene;i++)///bucla pentru a parcurge toate examenele
        {   if(examene[i].getDisciplina()!=nullptr)///daca disciplina examenului este valida
            {
                if(examene[i].getNota()<5.00)///daca nota este mai mica decat 5
                {
                    if(!unu)///daca e prima restanta din lista
                    {
                        std::cout<<"Studentul "<<nume<<" are restanta la: "<<examene[i].getDisciplina()->getNume();///afisam un mesaj initial, apoi disciplina
                        da=true;///am gasit o restanta
                        unu=true;///am gasit prima restanta
                    }
                    else///daca nu este prima restanta
                    {
                        da=true;///am gasit o restanta
                        std::cout<<", "<<examene[i].getDisciplina()->getNume();///afisam in continuare disciplina, fara mesajul initial
                    }
                }
            }
        }
    }

    if(!da)///daca nu am gasit nici macar o restanta
        std::cout<<"Studentul "<<nume<<" nu are restante.";///afisam un mesaj corespunzator

    std::cout<<"\n";
}
