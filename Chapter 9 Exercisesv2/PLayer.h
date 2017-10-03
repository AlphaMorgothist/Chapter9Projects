#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player {
public:
	friend ostream & operator<<(ostream & os, const Player* aPlayer);
	Player(const string &name = " ", int kd = 0);
	string GetName() const;
	Player* GetNext() const;
	int GetKd() const;
	void SetNext(Player* next);
private:
	float m_Kd;
	string m_Name;
	Player* m_pNext;
};