/*
 * Circle.cpp
 *
 */

#include "Circle.h";


Circle::Circle(double  r) {
	setR(r);
}

Circle::~Circle() {
}

void  Circle::setR(double r) {
	this->r = r; 
}
void Circle::setR(int r) {
	this->r = r;
}

double Circle::getR() const {
	return r;
}

double  Circle::calculateCircumference() const {
	return 2 * PI * r ;
}

double Circle::calculateArea(){
	return PI * r * r;
}
bool Circle::equals(Circle& Circle5) {
	return 	this->r == Circle5.r ? true : false;
}
