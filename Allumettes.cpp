#include "Allumettes.h"

Allumettes::Allumettes(int nombreAllumettes, bool multijoueur)
 : m_multijoueur(multijoueur), m_dernierJoueur(2)
{
    if(nombreAllumettes < 10)
        nombreAllumettes = 10;
    m_nombreDepart = nombreAllumettes;
    m_nombreActuel = nombreAllumettes;
}

bool Allumettes::retirerAllumettes(int nombre)
{
    if(nombre > 3 || nombre < 0)
        return false;
    if(m_multijoueur && getJoueurActuel() == 2)
        return false;

    m_nombreActuel -= nombre;

    if(m_nombreActuel < 0)
        m_nombreActuel = 0;

    m_dernierJoueur = getJoueurActuel();
    return true;
}

int Allumettes::vainqueur() //0, 1 ou 2
{
    if(m_nombreActuel != 0) return 0;
    else return m_dernierJoueur;
}

void Allumettes::reinitialiser()
{
    m_nombreActuel = m_nombreDepart;
}

int Allumettes::getNombreActuel()
{
    return m_nombreActuel;
}

int Allumettes::getJoueurActuel()
{
    if(m_dernierJoueur == 1) return 2;
    else return 1;
}

bool Allumettes::getMulti()
{
    return m_multijoueur;
}

int Allumettes::ia()
{
    int choix(0);

    if(m_nombreActuel <= 3)
        choix = m_nombreActuel;
    else if(m_nombreActuel % 4 == 0)
        choix = 3;
    else
        choix = m_nombreActuel % 4;

    m_nombreActuel -= choix;
    m_dernierJoueur = getJoueurActuel();
    return choix;
}
