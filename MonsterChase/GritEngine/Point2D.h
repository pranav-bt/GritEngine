#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//This class handles all the math for the positio., velocity, force, etc. 
namespace GritEngine {
	class Point2D
	{
	public:
		Point2D(float x, float y) : xpri(x), ypri(y){}
		Point2D() : xpri(0), ypri(0){}

		//getters
		float x() const { return xpri; }
		float y() const { return ypri; }


		//setters
		void setx(float x) { xpri = x; }
		void sety(float y) { ypri = y; }
		void set(float x, float y) { xpri = x, ypri = y; }

		int generatex();
		int generatey();
		bool operator==(Point2D rhs);
		bool operator!=(Point2D rhs);
		Point2D operator+(Point2D addvector);
		Point2D operator-(Point2D& subvector);
		Point2D operator*(int rhs);
		Point2D operator*(float rhs);
		Point2D operator+(float rhs);
		Point2D operator/(int rhs);
		Point2D operator-();
		Point2D operator+=(Point2D rhs);
		Point2D operator-=(Point2D rhs);
		Point2D operator*=(int rhs);
		Point2D operator/=(int rhs);
		float mag();
		static Point2D moveup(Point2D playerpos);
		static Point2D moveleft(Point2D playerpos);
		static Point2D moveright(Point2D playerpos);
		static Point2D movedown(Point2D playerpos);
	private:
		float xpri; float ypri;
	};

	Point2D operator*(int lhs, Point2D& rhs);
}

