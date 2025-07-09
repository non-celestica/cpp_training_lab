#include "unit.h"
#include "fighter.h"
#include "knight.h"
#include <cstdio>
#include <vector>

void upDownCast()
{
    Knight k;
    k.setKnightStats("Sir Lancelot", 100, 50, 75);

    printf("Call from Knight object:\n");
    k.attack();

    printf("\nUpcast to Fighter*:\n");
    Fighter* fptr = &k;
    fptr->attack();  // Calls Fighter::attack()

    printf("\nUpcast to Unit*:\n");
    Unit* uptr = &k;
    uptr->attack();  // Calls Unit::attack()

    printf("\nDowncast to Knight*:\n");
    Knight* kptr = static_cast<Knight*>(uptr);
    kptr->attack();

    printf("\nSlicing example:\n");
    Fighter f2 = k;
    f2.attack();  // Knight part sliced
}

std::vector < Unit* > createSquad(int knightCnt, int fighterCnt)
{
    printf("Create squad with %d knights and %d fighters\n", knightCnt, fighterCnt);
    std::vector < Unit* > squad;
    for (int i=0; i<knightCnt; i++) {
        Knight *k = new Knight();
        std::string name = "Knight#"+std::to_string(i+1);
        k->setKnightStats(name, 100, 50, 75);
        squad.push_back(k);
    }

    for (int i=0; i<fighterCnt; i++) {
        Fighter *f = new Fighter();
        std::string name = "Fighter#"+std::to_string(i+1);
        f->setFighterStats(name, 50, 25);
        squad.push_back(f);
    }
    return squad;
}

void squadMember(std::vector < Unit* > &squad)
{
    /**
     * The squad is vector of Unit*, it calls Unit::showStatus()
     * TODO-5: Modify this logic to showStatus based on the entity we created
     * 
     * Example:
     * There are 5 squad members!
     * Knight: Knight#1, HP: 100 stamina: 50 armor: 75
     * ...
     * Fighter: Fighter#3, HP: 50 stamina: 25
     */
    printf("There are %d squad members!\n", squad.size());
    for (size_t i=0; i<squad.size(); i++) {
        squad[i]->showStatus();
    }
}

void disbandSquad(std::vector < Unit* > &squad)
{
    // Free squad members
    for (size_t i=0; i<squad.size(); i++) {
        delete squad[i];
    }
    squad.clear();
}

int main() 
{
    printf("UpDown cast\n");
    upDownCast();

    // We want to create squad mixed with knight and fighter, how to do it?
    printf("\n\n");
    std::vector < Unit* > squad = createSquad(2, 3);
    squadMember(squad);
    disbandSquad(squad);

    return 0;
}
