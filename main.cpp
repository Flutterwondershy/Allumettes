#include <iostream>
#include "Allumettes.h"
#include <string>
using namespace std;

int main()
{
    int choix(0);
    string rejouer;
    string multi;
    bool boolMulti;
    int nombreDepart;

    cout << "Jeu des Allumettes, choix des conditions de jeu: " << endl;
    cout << "Nombre d'allumettes de départ (suppérieur à 10) : ";
    cin >> nombreDepart;
    cout << "Jeu multijoueur ? (Oui/Non) : ";
    do cin >> multi; while(multi != "Oui" && multi != "Non");
    cout << endl;

    if(multi == "Oui") boolMulti = true; else boolMulti = false;
    Allumettes jeu(nombreDepart, boolMulti);

    do
    {
        while(!jeu.vainqueur())
        {

                cout << "Joueur" << jeu.getJoueurActuel() << endl;
                cout << " - Il y a actuellement " << jeu.getNombreActuel() << " Allumettes en jeu. Combien en retirez-vous ?";

                if(!jeu.getMulti() && jeu.getJoueurActuel() == 2)
                    cout << jeu.ia() << endl;
                else
                    do
                    {
                        cin >> choix;
                    } while(!jeu.retirerAllumettes(choix));
        }
        cout << "Joueur " << jeu.vainqueur() << " est le gagnant ! Félicitations !" << endl;

        jeu.reinitialiser();
        cout << "Voulez-vous rejouer ? (Oui/Non) : ";
        do{
            cin >> rejouer;
        } while(rejouer != "Oui" && rejouer != "Non");
    } while(rejouer == "Oui");
    return 0;
}
