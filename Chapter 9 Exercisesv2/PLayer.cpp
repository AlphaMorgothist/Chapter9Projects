#include "stdafx.h"
#include "PLayer.h"

Player::Player(const string & name, int kd):
	m_Name(name), m_pNext(0), m_Kd(kd)
{

}

string Player::GetName() const
{
	return m_Name;
}

Player * Player::GetNext() const
{
	return m_pNext;
}

int Player::GetKd() const
{
	return m_Kd;
}

void Player::SetNext(Player * next)
{
	m_pNext = next;
}
