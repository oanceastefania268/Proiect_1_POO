#ifndef _DISCIPLINA_H
#define _DISCIPLINA_H

#include<iostream>

class Disciplina{

private:
    char *nume;
    int credite;

    void copiazaNume(const char *sursa);

public:
    Disciplina();
    Disciplina( const char *nume_, int credite_);
    Disciplina( const Disciplina& other);
    Disciplina& operator=( const Disciplina& other);
    ~Disciplina();
    friend std::ostream& operator<<(std::ostream& os, const Disciplina& dis);
    const char* getNume() const;
    int getCredite() const;

};

#endif
