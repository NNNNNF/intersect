#pragma once
#include <string>
#include <set>
using namespace std;

class Point {
public:
	double Xpoint = 0;
	double Ypoint = 0;

public:
	Point() {}
	Point(double x, double y) {
		Xpoint = x;
		Ypoint = y;
	}
	string showPoint();
	bool operator<(const Point& a)const
	{
		if (Xpoint != a.Xpoint) {
			return Xpoint < a.Xpoint;
		}
		else {
			return Ypoint < a.Ypoint;
		}
	}

	bool operator == (const Point& p) const
	{
		if (Xpoint != p.Xpoint) {
			return false;
		}
		else {
			return Ypoint == p.Ypoint;
		}
	}
};

class Line :public Point {
public:
	double a = 0;
	double b = 0;
	double c = 0;
public:
	//计算a,b,c
	Line getLine(Point pt1, Point pt2);
	//获得交点
	Point getintersection(Line l1, Line l2);
	//是否相交
	bool ifinter(Line l1, Line l2);
	//单元测试
	string showLine();
	//重载操作符
	bool operator < (const Line& lx) const
	{
		if (a != lx.a) {
			return a < lx.a;
		}
		else if (b != lx.b) {
			return b < lx.b;
		}
		else {
			return c < lx.c;
		}
	}

};

inline Line Line::getLine(Point pt1, Point pt2) {
	Line result;
	/*
	a = y1-y2
	b = x2-x1
	c = x1*y2-x2*y1
	l = ax+by+c=0
	*/
	result.a = pt1.Ypoint - pt2.Ypoint;
	result.b = pt2.Xpoint - pt1.Xpoint;
	result.c = pt1.Xpoint * pt2.Ypoint - pt2.Xpoint * pt1.Ypoint;
	return result;
}

inline Point Line::getintersection(Line l1, Line l2) {
	Point result;
	double mid = l1.a * l2.b - l2.a * l1.b;
	result.Xpoint = (l2.c * l1.b - l1.c * l2.b) / mid;
	result.Ypoint = (l1.c * l2.a - l2.c * l1.a) / mid;
	return result;
}

inline bool Line::ifinter(Line l1, Line l2) {
	double mid = l1.a * l2.b - l2.a * l1.b;
	if (mid == 0) {
		return false;
	}
	else {
		return true;
	}
}

inline string Line::showLine() {
	string s = "l=" + to_string((int)a) + "x+" + to_string((int)b) + "y+" + to_string((int)c) + "=0";
	return s;
	//return to_string(a) + "x+" + to_string(b) + "y+" + to_string(c) + "=0";
}

inline string Point::showPoint() {
	string s = "(" + to_string((int)Xpoint) + "," + to_string((int)Ypoint) + ")";
	return s;
}


inline Point getintersection(Line l1, Line l2) {
	Point result;
	double mid = l1.a * l2.b - l2.a * l1.b;
	result.Xpoint = (l2.c * l1.b - l1.c * l2.b) / mid;
	result.Ypoint = (l1.c * l2.a - l2.c * l1.a) / mid;
	return result;
}

class Circle {
public:
	double Xpoint = 0;
	double Ypoint = 0;
	double r = 0;

public:
	Circle() {}
	Circle(double x, double y,double r) {
		Xpoint = x;
		Ypoint = y;
		r = r;
	}
	bool operator<(const Circle& a)const
	{
		if (Xpoint != a.Xpoint) {
			return Xpoint < a.Xpoint;
		}
		else if (Ypoint != a.Ypoint) {
			return Ypoint < a.Ypoint;
		}
		else {
			return r<a.r;
		}
	}

	bool operator == (const Circle& p) const
	{
		if (Xpoint != p.Xpoint) {
			return false;
		}
		else if (Ypoint != p.Ypoint) {
			return false;
		}
		else {
			return r == p.r;
		}
	}

	bool ccifinter(Circle c1, Circle c2);
	bool clifinter(Circle c, Line l);
	Line getCCline(Circle c1, Circle c2);
	int getCLintersect(Circle c, Line l);
	
};

bool Circle::ccifinter(Circle c1, Circle c2) {
	double length = sqrt((c2.Ypoint - c1.Ypoint) * (c2.Ypoint - c1.Ypoint) + (c2.Xpoint - c1.Xpoint) * (c2.Xpoint- c1.Xpoint));
	if (length > c1.r + c2.r || length < fabs(c1.r - c2.r))
	{
		return false;
	}
	else {
		return true;
	}
}

Line Circle::getCCline(Circle c1, Circle c2) {
	double a = 2 * (c2.Xpoint - c1.Xpoint);
	double b = 2 * (c2.Ypoint - c1.Ypoint);
	double c = -1.0*(c1.r * c1.r - c2.r * c2.r + c2.Xpoint * c2.Xpoint - c1.Xpoint * c1.Xpoint +
		c2.Ypoint * c2.Ypoint - c1.Ypoint * c1.Ypoint);
	Line l;
	l.a = a;
	l.b = b;
	l.c = c;
	return l;
}
