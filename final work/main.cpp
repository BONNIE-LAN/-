#include <iostream>
#include"menu.h"
using namespace std;
int main()
{
    int choice;
    while(true)
    {
        showMenu();
        choice=getUserChoice();
    }
    switch(choice)
    {
        case 1:startGame();
        break;
        case 2:
        cout<<"The rule:Based on the difficulty level,the computer will generate a number of digits,you should guess this number and every time you guess you can get a cule"<<endl;
        break;
        case 3:
        cout<<"set the difficulty of the game to two digit number"<<endl;
        break;
        case 4:
        cout<<"exit,thank for you attend!"<<endl;
        break;
        default:
        cout<<"invalid choice,please enter again"<<endl;
    }
    return 0;
}