#include "stdafx.h"
#include "Lobby.h"
#include <ctime>
#include <random>
#include <Windows.h>
double randomnumgen(double low, double high)
{
	srand(time(NULL));
	double range = (high - low);
	double num = fmod(rand(), range) + low;
	return(num);
}

Lobby::Lobby():
	m_pHead(0)
{
}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()
{
	cin.ignore();
	cout << "Please enter a player name: ";
	string name;
	getline(cin, name);
	
	double rando = randomnumgen(0.1, 10.5);
	
	
	if (m_pHead != NULL)
	{
		Player* pNewPlayer = new Player(name, rando);
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		m_pTail = pNewPlayer;
		pIter->SetNext(pNewPlayer);
		cout << *(&m_pHead);
	}
	else if (m_pHead == NULL) {
		Player* pNewPlayer = new Player(name, rando);
		m_pHead = pNewPlayer;
		cout << *(&m_pHead);
	}
	
}

void Lobby::RemovePlayer()
{
	cin.ignore();
	if (m_pHead == 0)
	{
		cout << "The game lobby is empty! No one to ban" << endl;
	}
	else {
		cout << "\nBan player: " << m_pHead->GetName() << endl;
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear()
{
	while (m_pHead != 0)
	{
		RemovePlayer();
	}
}

ostream &operator<<(ostream & os, const Player* aPlayer)
{
	Player *pIter = aPlayer->GetNext();
	os << "\nPlayers' K/D Ratio: \n";
	if ( aPlayer->GetName() == " " &&  aPlayer->GetNext() == 0)
	{
		os << "<empty>" << endl;
	}
	else
	{
		os << aPlayer->GetName() << ": " << aPlayer->GetKd() << endl;
		while ( pIter != NULL)
		{
			os << pIter->m_Name << ": " << pIter->m_Kd << endl;
			pIter = pIter->m_pNext;
		}
	}
	return os;

}

ostream &operator<<(ostream & os, const Lobby & aLobby)
{
	Player* Piter = aLobby.m_pHead;
	os << "\nPlayers in the Lobby: \n";
	if (Piter == 0)
	{
		os << "<empty>" << endl;
	}
	else
	{
		while (Piter != 0)
		{
			os << Piter->GetName() << endl;
			Piter = Piter->GetNext();
		}
	}
	return os;
}