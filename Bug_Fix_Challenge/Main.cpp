#include "Triangle.h"
#include "Square.h"
#include "Circle.h"

#include <iostream>
using namespace std;
void test();
/*
 * Fix the code and compile it */
int main() {
	/****************************************************/
	/*DO NOT CHANGE any line of code in this function */
	Triangle triangle(3, 5, 6);
	triangle.setA(7);
	triangle.setB(8);
	triangle.setC(9);
	double triAngleCircumference = triangle.calculateCircumference();

	Circle circle(3);
	double circleCircumference1 = circle.calculateCircumference();
	circle.setR(5);
	double circleCircumference2 = circle.calculateCircumference();
	double circleArea = circle.calculateArea();

	Square square(3);
	double squareCircumference1 = square.calculateCircumference();
	square.setA(4);
	square.setB(5);
	double squareCircumference2 = square.calculateCircumference();
	double squareArea = square.calculateArea();
	/****************************************************/
	test();
	return 0;
}

void test() {
	Circle const circle1(30);
	/* Block the changing r of above object not other objects only above object.*/
	//circle1.setR(20); //This line must show compile error.
	double  circumference = circle1.calculateCircumference();
	circle1.getR();

	/*DO NOT REMOVE below code block*/
	{
		Circle circle2(30);
		circle2.setR(20);
		double circumference2 = circle2.calculateCircumference();
		circle2.getR();
	}
	/*End of code block*/

	Circle circle4(5);
	circle4.setR(10);
	Circle circle5(10);
	/*  In Circle class, create an equals function which returns boolean to compare circle4 and circle5 objects
	 * and print if they are equal or not. */
	circle4.equals(circle5) == true ? printf("They are equal!") : printf("They are not equal!");
	/*  Review the PI variable and make it unchangeable from anywhere of that program.
	 * You know PI is always 22/7 */
	//It is done! 
	/*Overload the setR method of Circle class to take integer values */
	//It is done!
}

/*
 *  Review the code and fix the bugs
 */

