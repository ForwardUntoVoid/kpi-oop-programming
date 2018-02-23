#include "stdafx.h"
#include <string>
#include <conio.h>
#include <iostream>
#include <iomanip>

unsigned int maxSits = 150;

using namespace std;

class Plane
{
private:
	unsigned int m_sits;
	float m_vel;
	string m_destPoint;
public:
	void seating();
	void setParam(unsigned int sits, float vel, string destPoint);
	void showDest();
	void flyTime();
};

void Plane::setParam(unsigned int sits, float vel, string destPoint)
{
	m_sits = sits;
	m_vel = vel;
	m_destPoint = destPoint;
}

void Plane::flyTime()
{
	float destDist;
	cout << "Enter distance to target (km): ";
	cin >> destDist;
	cout << "Fly Time: " << fixed << setprecision(3) << (destDist / m_vel) << " hours" << endl;
}

void Plane::showDest()
{
	cout << m_destPoint;
}

void Plane::seating()
{
	unsigned int people;
	cout << " > Enter number of passangers: ";
	cin >> people;
	if (people <= maxSits)
	{
		cout << "   All passangers have seats !";
	}
	else
	{
		cout << "   Not enought seats for " << (people - maxSits) << " passangers !!!";
	}
}

int main()
{
	string Places[5] = { "Kiev", "Moskau", "Brestlau", "Berlin", "London" };
	Plane AN25;
	Plane * ptr_Hangar = new Plane[5];
	for (int i = 0; i < 5; ++i)
	{
		ptr_Hangar[i].setParam(120, 600, Places[i]);
	}
	//AN25.setParam(120,520.5,"Fastiv");
	//AN25.showDest();
	//AN25.flyTime();
	//AN25.seating();
	for (int i = 0; i < 5; ++i)
	{
		cout << " Plane Number " << i + 1 << " fly to ";
		ptr_Hangar[i].showDest();
		cout << endl;
	}
	getch();
	return 0;
}