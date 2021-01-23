/*
 * Square.cpp
 *
 */

#include "Square.h"

Square::Square(double a) {
	setA(a);
	setB(a);
}

Square::~Square() {
}

void Square::setA(double a){
	this->a = a; 
	this->b = a;
}

void Square::setB(double b){
	this->b = b;
	this->a = b;
}

double Square::calculateCircumference(){
	return (a + b) * 2;
}

double Square::calculateArea(){
	return a * b;
}
