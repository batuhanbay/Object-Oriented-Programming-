/*
 * Square.h
 *
 */

#ifndef SQUARE_H_
#define SQUARE_H_

class Square {
public:
	Square(double);
	virtual ~Square();
	void setA(double);
	void setB(double);
	double calculateCircumference();
	double calculateArea();
private:
	double a;
	double b;
};

#endif /* SQUARE_H_ */
