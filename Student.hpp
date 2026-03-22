#ifndef _STUDENT_H
#define _STUDENT_H

#include<iostream>
#include<cstring>

#include "Examen.hpp"

class Student
{
private:
    char *nume;
    Examen *examene;
    int nr_examene;

    void copiazaNume(const char *sursa);
    void copiazaExamene(Examen *sursa, int nr_sursa);

public:

    Student();
    Student( const char *nume_, Examen *examene_, int nr_examene_);
    Student( const Student& other);
    Student &operator=(const Student& other);
    ~Student();
    friend std::ostream& operator<<(std::ostream& os, const Student& stud);

    void total_puncte_credit() const;
    char *getNume() const {return nume;};

    void medie_ponderata() const;

    void restante() const;



};
#endif // _STUDENT_H
