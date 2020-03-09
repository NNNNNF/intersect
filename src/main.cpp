#include<iostream>
#include <vector>
#include <set>
#include "assist.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	set <Line> lines;
	set <Point> points;
	string inputFilename;
	string outputFilename;

	if (argv[1][0] == '-' && argv[1][1] == 'i' && argv[3][0] == '-' && argv[3][1] == 'o') {
		inputFilename = argv[2];
		outputFilename = argv[4];
	}else if (argv[1][0] == '-' && argv[1][1] == 'o' && argv[3][0] == '-' && argv[3][1] == 'i') {
		inputFilename = argv[4];
		outputFilename = argv[2];
	}
	ifstream fin(inputFilename);
	ofstream out(outputFilename);

	int i, n;
	fin >> n;
	for (i = 0; i < n; i++) {
		char L;
		//cin >> L;
		//cout << L << endl;
		int x1, y1, x2, y2;
		fin >> L >> x1 >> y1 >> x2 >> y2;
		Point pt1, pt2;
		pt1.Xpoint = x1;
		pt1.Ypoint = y1;
		pt2.Xpoint = x2;
		pt2.Ypoint = y2;
		Line l = l.getLine(pt1, pt2);
		for (Line lx : lines) {
			if (lx.ifinter(lx, l)) {
				Point px = lx.getintersection(lx, l);
				//cout << px.Xpoint << px.Ypoint << endl;
				points.insert(px);
				//cout << points.size() << endl;
			}
		}
		lines.insert(l);
	}
	cout << points.size() << endl;
	out << points.size() << endl;
	fin.close();
	out.close();
}

/*
	   char ** argv 表示main函数所在的程序在运行时输入的参数表，用,或者空格分隔：
	   第一个参数存在 argv[1]中 每个第二维数组单元存一位数，例如 biji 12546 
	   即argv[1][0] = 1, argv[1][2]=2, argv[1][3]=5, argv[1][4]=5, argv[1][6]=6, 而argv[1]=12546
*/