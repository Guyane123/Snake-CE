#include <graphx.h>


class Pos 
{
public:

	Pos();
	Pos(int const x, int const y);

	void changePos(int const x, int const y);

private:
	int m_xpos;
	int m_ypos;


};


class Player
{
public:

	Player();
	void Move();
	void changePlayerSize(int const height, int const width);


private:

	Pos* m_pos;

	int m_height;
	int m_width;

	int m_speed;

	int m_backgroundColor;
};