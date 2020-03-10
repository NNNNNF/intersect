#include<iostream>
#include <vector>
#include <set>
#include "assist.h"
#include <fstream>
#include <string>

using namespace std;

set <Point> points;

int main(int argc, char** argv) {

	set <Line> lines;
	set <Circle> circles;

	string inputFilename;
	string outputFilename;

	if (argv[1][0] == '-' && argv[1][1] == 'i' && argv[3][0] == '-' && argv[3][1] == 'o') {
		inputFilename = argv[2];
		outputFilename = argv[4];
	}
	else if (argv[1][0] == '-' && argv[1][1] == 'o' && argv[3][0] == '-' && argv[3][1] == 'i') {
		inputFilename = argv[4];
		outputFilename = argv[2];
	}
	ifstream fin(inputFilename);
	ofstream out(outputFilename);

	int i, n;
	fin >> n;
	for (i = 0; i < n; i++) {
		char L;
		int x1, y1, x2, y2;
		fin >> L ;
		if (L == 'L') {
			fin >> x1 >> y1 >> x2 >> y2;
			Point pt1, pt2;
			pt1.Xpoint = x1;
			pt1.Ypoint = y1;
			pt2.Xpoint = x2;
			pt2.Ypoint = y2;
			Line l = l.getLine(pt1, pt2);
			for (Line lx : lines) {
				if (lx.ifinter(lx, l)) {//判断是否平行
					Point px = lx.getintersection(lx, l);//求交点
					points.insert(px);//插入点集合
				}
			}
			for (Circle c : circles) {
				c.clifinter(c, l);
			}
			lines.insert(l);
		}
		if (L == 'C') {
			int cx, cy,cr;
			fin >> cx >> cy >> cr;
			Circle c;
			c.Xpoint = cx;
			c.Ypoint = cy;
			c.r = cr;
			for (Line lx : lines) {
				c.clifinter(c, lx);
			}
			for (Circle cc : circles) {
				if (c.ccifinter(c, cc)) {
					Line l = c.getCCline(c, cc); 
					c.clifinter(c, l);
				}
			}
			circles.insert(c);
		}
	}
	//cout << points.size() << endl;
	out << points.size() << endl;
	fin.close();
	out.close();
}

bool Circle::clifinter(Circle c, Line l) {
	double cx = c.Xpoint;
	double cy = c.Ypoint;
	double cr = c.r;
	double la = l.a;
	double lb = l.b;
	double lc = l.c;
	double d = fabs(la * cx + lb * cy + lc) / sqrt(la * la + lb * lb);
	if (d > c.r) {
		return false;
	}
	else if(lb==0){
		double parax = -1.0 * lc / la;
		double paray = cr * cr - cx * cx - (lc * lc + 2 * lc * la * cx) / (la * la);
		Point pt1;
		Point pt2;
		pt1.Xpoint = parax;
		pt1.Ypoint = cy + sqrt(paray);
		pt2.Xpoint = parax;
		pt2.Ypoint = cy - sqrt(paray);
		points.insert(pt1);
		points.insert(pt2);
		//cout << pt1.Xpoint << " " << pt1.Ypoint << endl;
		//cout << pt2.Xpoint << " " << pt2.Ypoint << endl;
	}
	else {
		double paraa = la * la + lb * lb;
		double parab = -2.0 * lb * lb * cx + 2 * la * lc + 2 * la * lb * cy;
		double parac = lb * lb * cx * cx + (lc + cy * lb) * (lc + cy * lb) - cr * cr * lb * lb;
		double deta = sqrt(parab * parab - 4 * paraa * parac);
		Point pt1;
		Point pt2;
		pt1.Xpoint = (-1.0 * parab + deta) /( 2 * paraa);
		pt1.Ypoint = (-1.0 * la * pt1.Xpoint - lc) / lb;
		pt2.Xpoint = (-1.0 * parab - deta) /( 2 * paraa);
		pt1.Ypoint = (-1.0 * la * pt2.Xpoint - lc) / lb;
		points.insert(pt1);
		points.insert(pt2);
		//cout << pt1.Xpoint << " " << pt1.Ypoint << endl;
		//cout << pt2.Xpoint << " " << pt2.Ypoint << endl;
	}
	return true;
}
/*
	   char ** argv 表示main函数所在的程序在运行时输入的参数表，用,或者空格分隔：
	   第一个参数存在 argv[1]中 每个第二维数组单元存一位数，例如 biji 12546
	   即argv[1][0] = 1, argv[1][2]=2, argv[1][3]=5, argv[1][4]=5, argv[1][6]=6, 而argv[1]=12546
*/