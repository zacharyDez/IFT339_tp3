/*
 * VOTRE EN-TÊTE ICI!
 */


#ifndef TP3_CHAINETAB_H
#define TP3_CHAINETAB_H


#include <iostream>
using namespace std;

/**
 * Classe pour une structure de données de chaîne de tableau.
 */
template<typename TYPE>
class chainetab {
private:

    struct cellule {
        TYPE *tab;
        cellule *next;  //cellule suivante, nullptr si dernière cellule
        cellule *pred;  //cellule précédente, nullptr si première cellule
        cellule(TYPE *tab, cellule *pred, cellule *next);
    };

    cellule *pFirst;    //première cellule, ou nullptr si vide
    cellule *pLast;      //dernière cellule, ou nullptr si vide
    size_t tabsize;     //taille des tableaux pointés par vos cellules

    size_t pospremier;  //indice du premier élément dans le premier tableau
    size_t posdernier;  //indice du dernier élément dans le dernier tableau
    size_t dim;        //dimension, i.e. le nb d'éléments insérés

public:


    chainetab(size_t tabsize);

    ~chainetab();

    chainetab(const chainetab &source);

    chainetab &operator=(const chainetab &source);


    TYPE &operator[](size_t i);

    size_t size() const;

    void push_front(const TYPE &val);

    void push_back(const TYPE &val);

    void pop_front();

    void pop_back();

    //note: pour être une vraie liste, il faudrait implémenter l'insertion et la
    //suppression n'importe où.  Ce n'est pas demandé.


    void clear();


    void
    afficher_contenu();    //Affiche le contenu avec une ligne par sous-tableau.  Un X veut dire "case non-utilisée"

};





/*------------------------------------------------------------------------------
IMPLÉMENTATION
------------------------------------------------------------------------------*/



/**
 * Constructeur de cellule.
 */
template<typename TYPE>
chainetab<TYPE>::cellule::cellule(TYPE *tab, cellule *pred, cellule *next) {
    this->tab = tab;
    this->pred = pred;
    this->next = next;
}


/**
 * Constructeur qui initialise avec une liste vide.
 * tabsize est la taille des sous-tableaux
 */
template<typename TYPE>
chainetab<TYPE>::chainetab(size_t tabsize) {
    // initialiser param pour cellule
    TYPE *tab = new TYPE[tabsize];
    // initialiser premiere cellule
    cellule *cFirst = new cellule(tab, nullptr, nullptr);

    // ajuster param chaine tab
    // pFirst demeure sur nullptr tant que premier elt pas ajouter
    // afficher_contenu() regarde si pFirst = nullptr
    pFirst = nullptr;

    pLast = cFirst;
    this->tabsize = tabsize;
    dim = 0;
    pospremier = 0;
    posdernier = 0;

}


/**
 * Destructeur qui désalloue toute la mémoire et nettoie
 */
template<typename TYPE>
chainetab<TYPE>::~chainetab() {
    clear();
}


/**
 * Constructeur par copie: met la liste à vide et délègue tout à l'opérateur =
 */
template<typename TYPE>
chainetab<TYPE>::chainetab(const chainetab &source) {
    pFirst = nullptr;
    pLast = nullptr;
    (*this) = source;
}


/**
 * Opérateur =
 * Nettoie l'objet courant et copie tout de la source
 */
template<typename TYPE>
chainetab<TYPE> &chainetab<TYPE>::operator=(const chainetab &source) {
    //implémentez-moi
}


/**
 * Retourne le i-ème élément.
 */
template<typename TYPE>
TYPE &chainetab<TYPE>::operator[](size_t i) {
    int idxTab = i % tabsize;
    int noCell = (i-idxTab)/tabsize;

    cellule* ptr = pFirst;
    for(int i=0; i!=noCell;i++){
        ptr = ptr->next;
    }

    return ptr->tab[idxTab];

}


/**
 * Retourne le nombre d'éléments dans votre liste.
 */
template<typename TYPE>
size_t chainetab<TYPE>::size() const {
    //implémentez moi
}


/**
 * Ajouter en début de liste.  Insérer une nouvelle cellule au début si nécessaire.
 */
template<typename TYPE>
void chainetab<TYPE>::push_front(const TYPE &val) {

    //implémentez moi

}

/**
 * Ajouter en fin de liste.  Ajouter une nouvelle cellule à la fin si nécessaire.
 */
template<typename TYPE>
void chainetab<TYPE>::push_back(const TYPE &val) {
    // faire pointer pFirst sur pLast
    if (pFirst == nullptr) {
        pFirst = pLast;
    }

    // Si dimension tableau pas atteint ajouter au tableau ou dimension pas de zero
    // Sinon creer nouvelle cellule
    if (dim % tabsize > 0  || dim == 0) {
        pLast->tab[dim % tabsize] = val;
    } else {
        // creer nouvelle cellule
        // ajouter val
        TYPE* tab = new TYPE[tabsize];
        cellule* cNew = new cellule(tab, pLast, nullptr);
        cNew->tab[0]=val;

        // ajuster les pointeurs
        pLast->next = cNew;
        pLast = cNew;

        // ajuster les compteurs
        posdernier++;
    }

    dim++;

}


/**
 * Supprime tous les éléments et remet à l'état d'une liste vide.
 */
template<typename TYPE>
void chainetab<TYPE>::clear() {
    cellule *ptr = pFirst;
    while (ptr->next != nullptr) {
        delete[] ptr->tab;
        ptr = ptr->next;
    }

    delete pFirst;
    delete pLast;
}


/**
 * Enlève l'élément en tête de liste.  Ne vérifie rien.
 */
template<typename TYPE>
void chainetab<TYPE>::pop_front() {
    //implémentez-moi
}


/**
 * Enlève l'élément en fin de liste.  Ne vérifie rien.
 */
template<typename TYPE>
void chainetab<TYPE>::pop_back() {
    //implémentez-moi
}


/**
 * Affiche le contenu avec une ligne par sous-tableau.  Un X veut dire "case non-utilisée"
 */
template<typename TYPE>
void chainetab<TYPE>::afficher_contenu() {
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "dim=" << dim << " pospremier=" << pospremier << " posdernier=" << posdernier << std::endl;


    cellule *ptr = pFirst;
    while (ptr != nullptr) {
        std::cout << "[  ";
        /*
         * Ici, on itère sur le sous-tableau pointé par ptr.  On met un X aux position non-utilisées,
         * qui peuvent survenir dans le premier ou dernier sous-tableau.
         */
        size_t depart = 0;
        size_t fin = tabsize - 1;
        if (ptr->pred == nullptr)   //si on est sur la 1re cellule
            depart = pospremier;
        if (ptr->next == nullptr)
            fin = posdernier;       //si on est sur la dernière cellule

        for (size_t i = 0; i < tabsize; ++i) {
            if (i < depart || i > fin)
                std::cout << "X";
            else
                std::cout << ptr->tab[i];
            std::cout << "  ";
        }

        std::cout << "]";
        std::cout << std::endl;

        ptr = ptr->next;
    }

    std::cout << "Contenu avec []: ";
    for (size_t i = 0; i < dim; i++) {
        std::cout << (*this)[i] << "  ";
    }
    std::cout << std::endl;


}


#endif //TP3_CHAINETAB_H
