#pragma once
#include "PLayer.h"

class Lobby {
	friend ostream &operator <<(ostream &os, const Lobby &aLobby);
	friend ostream &operator <<(ostream &os, const Player *aPlayer);
public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();
private:
	Player *m_pHead;
	Player *m_pTail;
};