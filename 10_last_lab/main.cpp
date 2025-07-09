#include "unit.h"
#include "fighter.h"
#include "knight.h"
#include <cstdio>
#include <vector>
#include <map>

/**
 * TODO-2: Modify createSquad function to accept mageCnt and wizzardCnt
 * then add them to squad vector (naming should be "Mage#1", "Mage#2", ... | "Wizzard#1", "Wizzard#2", ...)
 * You can set stat whatever you want
 */
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

/**
 * TODO-1: We have Fighter and Knight unit, why don't we have Mage and Wizzard?
 * 1) Please create 2 new classes
 *     1.1) Class Mage derived from Unit (Mage.h, Mage.cpp)
 *          1.1.1) Mage will have 'hp' and 'mana'
 *          1.1.2) Add function setMageStats(name, hp, mana)
 *          1.1.3) Mage will attack with 'mana'
 *          1.1.4) Status should show 'mana'
 *     1.2) Class Wizzard derived from Mage (Wizzard.h, Wizzard.cpp)
 *          1.2.1) Wizzard will have 'hp', 'mana' and 'spirit'
 *          1.2.2) Add function setWizzardStats(name, hp, mana, spirit)
 *          1.2.3) Wizzard will attack with both 'mana' and 'spirit'
 *          1.2.4) Status should show 'mana' and 'spirit'
 */

int main() 
{
    std::vector < Unit* > squad = createSquad(2, 3);
    squadMember(squad);
    disbandSquad(squad);

    // TODO-3: Create new squad consist of 3 knights, 5 fighters, 1 wizzard and 2 mages

    /**
     * TODO-4: Create function to count each class in squad, output should look like:
     * Squad with 5 members consist of 2 knight(s), 1 fighter(s), 0 wizzard(s) and 2 mage(s)
     */
    // squadInfo(squad);

    return 0;
}
