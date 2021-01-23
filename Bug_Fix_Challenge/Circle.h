/*
 * Circle.h
 *
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
class Circle {
public:
	Circle (double);
	virtual ~Circle();
	void setR(double);
	void setR(int);
	double getR() const;
	double calculateCircumference() const;
	double calculateArea();
	bool equals(Circle&);
private:
	double  r;
	double const PI = 3.14; 
};
#endif /* CIRCLE_H_ */
