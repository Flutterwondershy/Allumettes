#ifndef ALLUMETTES_H_INCLUDED
#define ALLUMETTES_H_INCLUDED


class Allumettes
{
    public:
        Allumettes(int nombreAllumettes, bool multijoueur = false);

        bool retirerAllumettes(int nombre);
        int vainqueur(); //0, 1 ou 2
        void reinitialiser();
        int getNombreActuel();
        int getJoueurActuel();
        bool getMulti();
        int ia();
    private:
        bool m_multijoueur;
        int m_nombreDepart;
        int m_nombreActuel;
        int m_dernierJoueur; //1 ou 2
};

#endif // ALLUMETTES_H_INCLUDED
