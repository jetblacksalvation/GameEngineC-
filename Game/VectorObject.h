#pragma once
#include <iostream>
class VectorObject2D
{


public:
	VectorObject2D();

	VectorObject2D(float x, float y);

	float x, y;

	VectorObject2D& add(const VectorObject2D&);
	VectorObject2D& sub(const VectorObject2D&);
	VectorObject2D& div(const VectorObject2D&);
	VectorObject2D& mul(const VectorObject2D&);


	float GetDotProduct(VectorObject2D);

	friend VectorObject2D& operator+(VectorObject2D, const VectorObject2D&);
	friend VectorObject2D& operator-(VectorObject2D, const VectorObject2D&);
	friend std::ostream& operator<<(std::ostream&, const VectorObject2D&);
};

