#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include <string>
#include "snake.h"
#include "Dir.h"
#include "player.h"
class Control
{
    public:
        Control(std::vector <snake *> , player);  //Determine the player and the number of snakes
        void updatekay(char);  //Update the location of the player according to the input key
        void updetesnake();    //Move the snakes to the player's new location
        bool finished();       //Check the completion of the game
        std::string getboard();    //Return the board

    private:
        std::vector <snake *> s;
        player p;

};

#endif
