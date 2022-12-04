#include "HumanB.hpp"
#include "HumanA.hpp"
int main()
{
    {
        //On change le type d'une arme initialisée dans le constructeur
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        //On change le type d'une arme initialisée plus tard
        //La valeur de weapon a besoin d'etre initialisé si
        //on choisi une ref
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}