#pragma once

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
	bool operator<(const Point& a)const
	{
		if (Xpoint != a.Xpoint) {
			return Xpoint < a.Xpoint;
		}
		else {
			return Ypoint < a.Ypoint;
		}
	}
};

class Line :public Point {
public:
	double a = 0;
	double b = 0;
	double c = 0;
public:
	Line getLine(Point pt1, Point pt2);
	Point getintersection(Line l1, Line l2);
	bool ifinter(Line l1, Line l2);
	void showPoint(Point ptinter);

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

Line Line::getLine(Point pt1, Point pt2) {
	Line result;
	/*
	a = y1-y2
	b = x2-x1
	c = x1*y2-x2*y1
	y = ax+by+c=0
	*/
	result.a = pt1.Ypoint - pt2.Ypoint;
	result.b = pt2.Xpoint - pt1.Xpoint;
	result.c = pt1.Xpoint * pt2.Ypoint - pt2.Xpoint * pt1.Ypoint;
	return result;
}

Point Line::getintersection(Line l1, Line l2) {
	Point result;
	double mid = l1.a * l2.b - l2.a * l1.b;
	result.Xpoint = (l2.c * l1.b - l1.c * l2.b) / mid;
	result.Ypoint = (l1.c * l2.a - l2.c * l1.a) / mid;
	return result;
}

bool Line::ifinter(Line l1, Line l2) {
	double mid = l1.a * l2.b - l2.a * l1.b;
	if (mid == 0) {
		return false;
	}
	else {
		return true;
	}
}
