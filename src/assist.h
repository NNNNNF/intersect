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
	Line getLine(Point pt1, Point pt2);
	Point getintersection(Line l1, Line l2);
	bool ifinter(Line l1, Line l2);

	//string showPoint(Point ptinter);
	string showLine();

	int getpoints(set<Line> lines);


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
//int Line::getpoints(set<Line> lines) {
//	for (Line lx : lines) {
//		if (lx.ifinter(lx, l)) {
//			Point px = lx.getintersection(lx, l);
//			//cout << px.Xpoint << px.Ypoint << endl;
//			points.insert(px);
//			//cout << points.size() << endl;
//		}
//	}
//}
inline Point getintersection(Line l1, Line l2) {
	Point result;
	double mid = l1.a * l2.b - l2.a * l1.b;
	result.Xpoint = (l2.c * l1.b - l1.c * l2.b) / mid;
	result.Ypoint = (l1.c * l2.a - l2.c * l1.a) / mid;
	return result;
}
