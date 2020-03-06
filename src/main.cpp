#include<iostream>
#include <vector>
#include <set>
#include "assist.h"

int main(int argc, char** argv) {
	set <Line> lines;
	set <Point> points;
	int i, n;
	cin >> n;
	for (i = 0; i < n; i++) {
		char L;
		//cin >> L;
		//cout << L << endl;
		int x1, y1, x2, y2;
		cin >> L >> x1 >> y1 >> x2 >> y2;
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
}