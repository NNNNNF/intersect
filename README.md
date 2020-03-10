## 个人项目作业

intersect.exe运行：

intersect.exe -i input.txt -o output.txt

| Q                                    | A                                                            |
| ------------------------------------ | ------------------------------------------------------------ |
| 这个作业属于哪个课程                 | [2020春季计算机学院软件工程(罗杰 任健)](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ) |
| 这个作业的要求在哪里                 | [个人项目作业](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ/homework/10429) |
| 我在这个课程的目标是                 | 系统地学习软件工程开发知识，掌握相关流程和技术，提升工程化开发的能力 |
| 这个作业在哪个具体方面帮助我实现目标 | 了解熟悉个人软件开发流程（PSP）                              |
| 教学班级                             | 005                                                          |
| 项目地址                             | https://github.com/NNNNNF/intersect.git                      |

#### PSP表格：

| PSP2.1                                  | Personal Software Process Stages        | 预估耗时（分钟） | 实际耗时（分钟） |
| --------------------------------------- | --------------------------------------- | ---------------- | ---------------- |
| Planning                                | 计划                                    |                  |                  |
| · Estimate                              | · 估计这个任务需要多少时间              | 10               | 10               |
| Development                             | 开发                                    |                  |                  |
| · Analysis                              | · 需求分析 (包括学习新技术)             | 60               | 120              |
| · Design Spec                           | · 生成设计文档                          | 20               | 30               |
| · Design Review                         | · 设计复审 (和同事审核设计文档)         | 0                |                  |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) | 20               | 20               |
| · Design                                | · 具体设计                              | 20               | 30               |
| · Coding                                | · 具体编码                              | 60               | 80               |
| · Code Review                           | · 代码复审                              | 20               | 30               |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  | 100              | 120              |
| Reporting                               | 报告                                    |                  |                  |
| · Test Report                           | · 测试报告                              | 60               | 60               |
| · Size Measurement                      | · 计算工作量                            | 30               | 30               |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          | 30               | 50               |
|                                         | 合计                                    | 430              | 580              |

#### 解题思路

- 对题目中的给出的条件$$(x_1,y_1)$$和$$(x_2,y_2)$$,首先想到的是求取直线表达式，我采取的表达方式是：

  $$l:ax+by+c=0$$,利用已知两个点的坐标可以比较容易的求出$$a,b,c$$的值：

  $$a=y_1-y_2$$，$$b=x_2-x_1$$，$$c=x_1y_2-x_2y_1$$，由于直线组中的每两条直线都需要求交点，所以选择记录$$a,b,c$$的值来存储直线。

- 然后是求交点。根据两条直线方程$$l_1:a_1x+b_1y+c_1=0$$和$$l_2:a_2x+b_2y+c_2=0$$可求得交点坐标为：

  $$x=\frac{c_2b_1-c_1b_2}{a_1b_2-a_2b_1},y=\frac{c_1a_2-c_2a_1}{a_1b_2-a_2b_1}$$，此时涉及到分母为0的情况，即两直线平行，交点个数为0；故在对任意两直线求交点前，先判断其是否平行，若不平行才进行求交点计算。

- 最后是关于直线和点选择什么样的容器存储的问题，考虑到点集会有重复，所以在vetor和set之间，选择了可以确保容器内有不重复元素的set（[参考资料](https://www.cnblogs.com/xkfz007/articles/2534249.html)），此时也涉及到了运算符重载的问题，以确保set容器中不存在重复点。

#### 设计实现

- 在实现过程中设计了两个类，一个是Point，一个是Line，因为Line的3个参数$$a,b,c$$是由两个点的坐标计算而来，故Line继承自Point。由于两个类涉及到的参数和计算都不算复杂，所以关于Point和Line的函数都放置在assis.h中。

- 需要实现的重要函数有以下：1.求直线参数；2.判断直线是否相交；3.求直线交点；4.set用于去重的运算符重载函数，所有的函数由main函数调用。

- 关于单元测试，我主要设计了对点和直线的构造函数、求直线表达式函数、判断直线是否相交函数的测试数据，对无重复交点的直线集合、有重复交点的直线集合，无交点直线集合，临界数据几种情况进行测试。

  

#### 程序性能

​	总共花费时间：40分钟

​	一开始想的是等所有直线输入完成再开始计算交点，其实可以一边输入一边对直线交点进行处理。即一开始直线容器$lines$为空，对输入的直线$l$，先与$lines$中所有直线求交点，若存在则insert到点集容器$points$中，然后将直线$$l$$存储到$$lines$$中，再接着输入，这样可以减小循环开销。

性能分析：

在数据量为1000时的性能分析：

![1583767894028](C:\Users\IDEA\AppData\Roaming\Typora\typora-user-images\1583767894028.png)

由下图可以看出程序中消耗最大的操作是set容器的insert操作：

![1583767988599](C:\Users\IDEA\AppData\Roaming\Typora\typora-user-images\1583767988599.png)

#### 代码说明

- Line类

```c++
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
```

- 求交点

```c++
inline Point Line::getintersection(Line l1, Line l2) {
	Point result;
	double mid = l1.a * l2.b - l2.a * l1.b;
	result.Xpoint = (l2.c * l1.b - l1.c * l2.b) / mid;
	result.Ypoint = (l1.c * l2.a - l2.c * l1.a) / mid;
	return result;
}
```

- 主函数

```c++
	for (i = 0; i < n; i++) {
		char L;
		int x1, y1, x2, y2;
		fin >> L >> x1 >> y1 >> x2 >> y2;
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
		lines.insert(l);//插入直线
	}
```

#### 单元测试和Code Quality Analysis

![1583768914337](C:\Users\IDEA\AppData\Roaming\Typora\typora-user-images\1583768914337.png)

![1583768934441](C:\Users\IDEA\AppData\Roaming\Typora\typora-user-images\1583768934441.png)