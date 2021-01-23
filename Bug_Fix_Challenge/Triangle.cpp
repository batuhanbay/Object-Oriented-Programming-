/*
 * Triangle.cpp
 *
 */

#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) {
	setA(a);
	setB(b);
	setC(c);
}

Triangle::~Triangle() {

}

void Triangle::setA(double a){
	this->a = a;
}

void Triangle::setB(double b){
	this->b = b;
}

void Triangle::setC(double c){
	this->c = c;
}

double Triangle::calculateCircumference(){
	return a + b + c; 
}

