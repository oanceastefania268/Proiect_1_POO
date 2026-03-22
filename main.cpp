/**
Programul implementează un sistem de gestiune a situației școlare pentru studenți.

Clase:

    -DISCIPLINA: reține numele (*char) și numărul de credite (int);
    -EXAMEN: face legătura între o disciplină și nota obținută(float);
    -STUDENT: reține numele, un vector de examene și numărul examenelor.

Operații posibile:

    -Calculul punctelor credit obținute de student;
    -Calculul mediei ponderate a studentului;
    -Identificarea materiilor unde studentul are restanțe.

**/
#include <iostream>
#include "Disciplina.hpp"
#include "Examen.hpp"
#include "Student.hpp"

int main() {

    std::cout<<"TESTARE DISCIPLINA"<<"\n\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Constructor parametrizat: creare d1, d2, d3 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    Disciplina d1("Logica matematica si computationala", 4);
    Disciplina d2("Programare orientata pe obiecte", 6);
    Disciplina d3("Limbaje formale si automate", 5);

    std::cout <<d1<<d2<<d3;

    std::cout<<"\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Constructor de copiere: copiaza d1 in d4 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    Disciplina d4(d1);
    std::cout<<d4;

    std::cout<<"\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Operator de atribuire: d4=d2 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    d4=d2;
    std::cout<<d4;

    std::cout<<"\n";

    std::cout<<"TESTARE EXAMEN"<<"\n\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Constructor parametrizat: creare e1, e2, e3, e4, e5 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    Examen e1(&d1, 4.5);
    Examen e2(&d2, 4.0);
    Examen e3(&d3, 8.0);

    Examen e4(&d1, 9.0);
    Examen e5(&d2, 7.5);

    std::cout <<e1<<e2<<e3<<e4<<e5;

    std::cout<<"\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Constructor de copiere: copiaza e1 in e6 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    Examen e6(e1);
    std::cout<<e6;

    std::cout<<"\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Operator de atribuire: e6=e2 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    e6=e2;
    std::cout<<e6;

    std::cout<<"\n";


    std::cout<<"TESTARE STUDENT"<<"\n\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Constructor parametrizat: creare s1, s2 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    Examen lista1[]={e1,e2,e3};
    Examen lista2[]={e4,e5};

    Student s1("Popescu Ion", lista1, 3);
    Student s2("Moga Marius", lista2, 2);

    std::cout <<s1<<s2;


    std::cout<<" ~~~~~~~~~~~~~~~~~~ Constructor de copiere: copiaza s1 in s3 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    Student s3(s1);
    std::cout<<s3;

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Operator de atribuire: s3=s2 ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    s3=s2;
    std::cout<<s3;

    std::cout<<"TESTARE FUNCTII"<<"\n\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Puncte credit  ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    s1.total_puncte_credit();
    s2.total_puncte_credit();

    std::cout<<"\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Medie ponderata ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    s1.medie_ponderata();
    s2.medie_ponderata();

    std::cout<<"\n";

    std::cout<<" ~~~~~~~~~~~~~~~~~~ Restante ~~~~~~~~~~~~~~~~~~ "<<"\n\n";

    s1.restante();
    s2.restante();

    return 0;
}

