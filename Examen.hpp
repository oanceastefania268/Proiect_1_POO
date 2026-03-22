#ifndef _EXAMEN_H
#define _EXAMEN_H

#include<iostream>
#include "Disciplina.hpp"

class Examen{

private:

    Disciplina *disciplina_examen;
    float nota;

    void copiazaDisciplina(const Disciplina *sursa);

public:
    Examen();
    Examen(const Disciplina* disciplina_examen_, float nota_);
    Examen(const Examen& other);
    Examen& operator=(const Examen& other);
    ~Examen();
    friend std::ostream& operator<<(std::ostream& os, const Examen& exam);
    float getNota() const;
    Disciplina* getDisciplina() const;
    float rotunjire() const;


};


#endif

