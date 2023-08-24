#include <stdlib.h>;
#include <tice.h>;
#include "player.hpp";

#define XOFFSET 160
#define YOFFSET 120




Pos::Pos() : m_xpos(0), m_ypos(0) {};
Pos::Pos(int const x, int const y) : m_xpos(x), m_ypos(y) {};

void Pos::changePos(int const x, int const y)
{
	m_xpos = x + XOFFSET;
	m_xpos = y + YOFFSET;
}

Player::Player() : m_speed(5), m_width(10), m_height(10), m_pos(nullptr), m_backgroundColor(16)
{
	m_pos = new Pos(XOFFSET, YOFFSET);
}

void Player::Move()
{
	gfx_SetColor(m_backgroundColor);
	gfx_Rectangle(x + XOFFSET, y + YOFFSET, m_width, m_height);
}

void Player::changePlayerSize(int const width, int const height)
{
	m_width = width;
	m_height = height;
}

Player::~Player()
{
	delete m_pos;
}