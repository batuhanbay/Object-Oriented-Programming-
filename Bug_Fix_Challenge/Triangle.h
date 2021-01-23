/*
 * Triangle.h
 *
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle {
public:
	Triangle(double, double, double);
	virtual ~Triangle();
	void setA(double);
	void setB(double);
	void setC(double);
	double calculateCircumference();
private:
	double a;
	double b;
	double c;
};

#endif /* TRIANGLE_H_ */
