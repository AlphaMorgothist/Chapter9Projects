// Chapter9Exercisesv2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lobby.h"
void runGame();

int main()
{
	cout << "\nChapter 9 Exercises.\nBoth the overloaded operator and the tail have been added to this version." << endl;
	system("pause");
	system("CLS");
	runGame();
    return 0;
}

void runGame()
{
	Lobby lobby;
	int choice;
	do
	{
		cout << lobby;
		cout << "\nGAME LOBBY\n";
		cout << "\n0: Quit" << endl;
		cout << "1: Add a player to the lobby" << endl;
		cout << "2: Remove a player from the lobby" << endl;
		cout << "3: Clear the lobby" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		system("CLS");
		switch (choice)
		{
		default: cout << "That is not a valid choice" << endl;
		case 0: {cout << "\nGoodbye!"; }break;
		case 1: {lobby.AddPlayer(); }break;
		case 2: {lobby.RemovePlayer(); }break;
		case 3: {lobby.Clear(); }break;\

		}
	} while (choice != 0);
}
