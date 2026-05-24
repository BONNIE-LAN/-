#include <iostream>
#include "menu.h"
#include"game.h"
using namespace std;
void showMenu()
{
	cout << "This is a game help you practice the four operation!" << endl;
	cout << "1.normal mode" << endl;
	cout << "2.game mode" << endl;
	cout << "Please press the number to choose the mode" << endl;
}
void getUserNumber(int n)
{
	if (n == 1)
	{
		generateFourOperation_N();
	}
	if (n == 2)
	{
		generateFourOperation_G();
	}
}
void explainRule(int n)
{
	if (n == 1)
	{
		cout << "You will get 10 four operation" << endl;
		cout << "After answering,you will return to the menu" << endl;
	}
	if (n == 2)
	{
		cout << "If your answer is correct,you will get one point" << endl;
		cout << "Once you get 5 points,you can get into the next diffculty level" << endl;
		cout << "There are totally 3 levels" << endl;
		cout << "After answering,you will return to the menu" << endl;
	}
}
int main()
{
    while(true)
	{
	   showMenu();
	   int n;
	   cin >> n;
	   system("cls");
	   explainRule(n);
	   system("pause");
	   system("cls");
	   getUserNumber(n);
	   system("cls");
	   system("pause");
	}
}