#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include "Control.h"
using namespace std;

//Save the name and score of the player in the file
void Save_points(string name , long int score)
{
    ofstream points_file;
    points_file.open("Points.txt" , ios::app);
    points_file << name << ":\t" << score << endl;
    points_file.close();

}
//Finding the most points from the games played in the file
int show_maxscore()
{
    ifstream points_file;
    points_file.open("Points.txt");
    long int maxscore=0;
    long int score;
    string name;
    while(points_file >> name)
    {
        points_file >> score;
        if(score > maxscore)
        {
            maxscore = score;
        }

    }
    points_file.close();
    return maxscore;
}
int score;
int main()
{
    player p;   //Build a player
    vector <snake *> sn;   //making snakes
    sn.push_back(new snake(5,5));  //Snake 1
    sn.push_back(new snake(16,23));   //Snake 2
    sn.push_back(new snake(30,9));   //Snake 3
    Control c(sn, p);
    cout << " .... ESCAPE FROM SNAKES .... " << endl;
    string name;
    cout << endl << " Please Enter your name => " ;
    cin >> name;
    system("cls");
    cout << "\n Instruction: " << "\n You have to escape from the snakes."
         << "\n Use A, W, D, S keys to move.\n" << "\n Enter 1 to start the game: " ;
    int n;
    cin >> n;
    Sleep(200);
    char k;  //Show the board
    clock_t startTime = clock();

    while(c.finished() == false)
    {
        Sleep(400);
        system("cls");
        cout << c.getboard();   //Show the board
        //Calculation of elapsed seconds of the game
        score = int(clock() - startTime) / (int) CLOCKS_PER_SEC ;
        cout << " SCORE : " << score;

        if(_kbhit())  //Getting input
        {
            k = _getch();
            c.updatekay(k);  //Update the location of the player
            system("cls");
            cout << c.getboard();  //Show the board
            score = int(clock() - startTime) / (int) CLOCKS_PER_SEC ;
            cout << " SCORE : " << score;
        }
            c.updatekay(k);  //Update the location of the player
            c.updetesnake();  //Move the snakes to the player

    }
    system("cls");
    Save_points(name , score);   //Save player name and score
    cout << ".... GAME OVER ...." << "\n Your Score : " << score << endl;
    //Show the most points from the games played
    cout << " Max Score : " << show_maxscore() << endl;
    cin.get();
    cin.get();
    for(size_t i=0 ; i <sn.size() ; i++)  //Remove built snakes
    {
        delete sn[i];
    }

    return 0;
}
