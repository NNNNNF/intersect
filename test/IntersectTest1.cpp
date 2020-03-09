#include "pch.h"
#include "CppUnitTest.h"
#include "..\intersect\assist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest1
{
	TEST_CLASS(IntersectTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Point pt1(0, 1);
			Assert::AreEqual(pt1.showPoint(),(string)"(0,1)");
		}

		TEST_METHOD(TestMethod2)
		{
			Point pt2(-100000, 100000);
			Assert::AreEqual(pt2.showPoint(), (string)"(-100000,100000)");
		}

		TEST_METHOD(TestMethod3) {
			Point pt1(0, 1);
			Point pt2(1, 0);
			Line l1 = l1.getLine(pt1, pt2);
			Assert::AreEqual(l1.showLine(), (string)"l=1x+1y+-1=0");
		}

		TEST_METHOD(TestMethod4) {
			Point pt1(0, 1);
			Point pt2(1, 0);
			Point pt3(0, 0);
			Point pt4(1, 1);
			Line l1 = l1.getLine(pt1, pt2);
			Line l2 = l2.getLine(pt3, pt4);
			Point p(0.5, 0.5);
			Point px = getintersection(l1, l2);
			Assert::AreEqual((double)px.Xpoint, (double)0.5);
			Assert::AreEqual((double)px.Ypoint, (double)0.5);
		}

		TEST_METHOD(TestMethod5) {
			Point pt1(2, 1);
			Point pt2(1, 0);
			Point pt3(-5, -3);
			Point pt4(1, 1);
			Line l1 = l1.getLine(pt1, pt2);
			Line l2 = l2.getLine(pt3, pt4);
			Assert::AreEqual(l1.ifinter(l1, l2), true);
		}

		TEST_METHOD(TestMethod6) {
			Point pt1(-1, 6);
			Point pt2(1, 2);
			Point pt3(-3,2);
			Point pt4(2, -8);
			Line l1 = l1.getLine(pt1, pt2);
			Line l2 = l2.getLine(pt3, pt4);
			Assert::AreEqual(l1.ifinter(l1, l2), false);
		}

		TEST_METHOD(testMethod7) {
			Point pt1(2, 1);
			Point pt2(1, 0);
			Point pt3(-5, -3);
			Point pt4(1, 1);
			Line l1 = l1.getLine(pt1, pt2);
			Line l2 = l2.getLine(pt3, pt4);
			set <Point> points;
			Point px = l1.getintersection(l1, l2);
			points.insert(px);
			int num = points.size();
			Assert::AreEqual(num,1);
		}

		TEST_METHOD(testMethod8) {
			Point pt1(0, 0);
			Point pt2(1, 1);
			Point pt3(1, 0);
			Point pt4(0, 1);
			Point pt5(1, 2);
			Point pt6(2, 0);
			Line l1 = l1.getLine(pt1, pt2);
			Line l2 = l2.getLine(pt3, pt4);
			Line l3 = l3.getLine(pt5, pt6);
			Point p1 = l1.getintersection(l1, l2);
			Point p2 = l1.getintersection(l1, l3);
			Point p3 = l2.getintersection(l2, l3);
			set <Point> points;
			points.insert(p1);
			points.insert(p2);
			points.insert(p3);
			int num = points.size();
			Assert::AreEqual(num, 3);
		}

		TEST_METHOD(testMethod9) {
			Point pt1(0, 0);
			Point pt2(1, 1);
			Point pt3(0, 0);
			Point pt4(0, 1);
			Point pt5(0, 0);
			Point pt6(-1, 0);
			Line l1 = l1.getLine(pt1, pt2);
			Line l2 = l2.getLine(pt3, pt4);
			Line l3 = l3.getLine(pt5, pt6);
			Point p1 = l1.getintersection(l1, l2);
			Point p2 = l1.getintersection(l1, l3);
			Point p3 = l2.getintersection(l2, l3);
			set <Point> points;
			points.insert(p1);
			points.insert(p2);
			points.insert(p3);
			int num = points.size();
			Assert::AreEqual(num, 1);
		}

		TEST_METHOD(testMethod10) {
			Point pt1(100000, 100000);
			Point pt2(-3, 19999);
			Point pt3(99999, 10000);
			Point pt4(4, 8366);
			Point pt5(-6542, 768);
			Point pt6(9999, -4);
			Line l1 = l1.getLine(pt1, pt2);
			Line l2 = l2.getLine(pt3, pt4);
			Line l3 = l3.getLine(pt5, pt6);
			Point p1 = l1.getintersection(l1, l2);
			Point p2 = l1.getintersection(l1, l3);
			Point p3 = l2.getintersection(l2, l3);
			set <Point> points;
			points.insert(p1);
			points.insert(p2);
			points.insert(p3);
			int num = points.size();
			Assert::AreEqual(num, 3);
		}
	};
}
