#include <iostream>

#include "chainetab.h"





/**
 * Fait plusieurs pop successifs sur c.  Si isFront est true, fait des pop_front.  Sinon, des pop_back.
 */
void pop_many(chainetab<int> &c, size_t howMany, bool isFront)
{
    for (size_t i = 0; i < howMany; i++)
    {
        //pour infos sur la forme
        //(condition ? si-vrai : si-faux)
        //voir https://stackoverflow.com/questions/392932/how-do-i-use-the-conditional-operator
        (isFront ? c.pop_front() : c.pop_back());
    }
}




int main() {

    chainetab<int> a(10);

    a.push_front(-1);
    a.pop_back();
    a.afficher_contenu();

    a.push_front(-2);
    a.push_front(-3);
    a.pop_front();
    a.push_back(10);
    a.push_back(11);
    a.pop_back();
    a.afficher_contenu();

    //Ce code a généré la sortie attendue.
    chainetab<int> c(10);

    c.afficher_contenu();

    for (size_t i = 0; i < 25; i++)
    {
        c.push_back(i);
    }
    c.afficher_contenu();   //attendu: 25 éléments sur 3 cellules



    c.push_front(-1);
    c.afficher_contenu();   //attendu: 26 éléments sur 4 cellules (car nouvelle cellule insérée au début)

    c.pop_front();
    c.afficher_contenu();   //attendu: 25 éléments sur 3 cellules

//    cout<<"----------------------------------"<<endl;
//    cout<<"Test pop_back"<<endl;
//    cout<<"----------------------------------"<<endl;
//    c.pop_back();
//    c.pop_back();
//    c.pop_back();
//    c.pop_back();
//    c.pop_back();
//    c.pop_back();
//    c.afficher_contenu();

//
//
//
//
//
//    pop_many(c, 10, false); //popper 10 en fin
//    c.afficher_contenu();   //attendu: 15 éléments sur 2 cellules
//
//
//
//    for (size_t i = 0; i < 15; i++)
//    {
//        c.push_front(i);
//    }
//    c.afficher_contenu();   //attendu: 30 éléments sur 4 cellules (deux nouvelles insérées au début avec contenu non-initialisé)
//
//
//
//
//    pop_many(c, 10, true); //popper 10 en début
//    c.afficher_contenu();   //attendu: 20 éléments sur 3 cellules
//
//
//
//
//    for (size_t i = 0; i < 6; i++)
//    {
//        c.push_front(i);
//    }
//    c.afficher_contenu();   //attendu: 26 éléments sur 4 cellules (nouvelle insérée en fin)
//
//
//
//    pop_many(c, 20, false); //popper 20 en fin
//    c.afficher_contenu();   //attendu: 6 éléments sur 2 cellules
//
//    std::cout<<std::endl<<"***** Test de constructeur par copie et de l'affectation *****"<<std::endl;
//    chainetab<int> c2(100);
//    c2 = c;
//    c2.afficher_contenu();
//
//    chainetab<int> c3(c);
//    c3.afficher_contenu();


    return 0;
}










