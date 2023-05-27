#include "VectorObject.h"
//class VectorObject2D
//{
//
//
//public:
//	VectorObject2D();
//
//	VectorObject2D(float x, float y);
//
//	float x, y;
//
//	VectorObject2D add(const VectorObject2D&);
//	VectorObject2D sub(const VectorObject2D&);
//	VectorObject2D div(const VectorObject2D&);
//	VectorObject2D mul(const VectorObject2D&);
//
//
//	float GetDotProduct(VectorObject2D);
//
//	float operator*(VectorObject2D);
//	VectorObject2D operator+(VectorObject2D);
//	VectorObject2D operator-(VectorObject2D);
// 	friend std::ostream& operator<<(std::ostream&, const VectorObject2D&);
//
//};

VectorObject2D::VectorObject2D() { this->x = 0; this->y = 0; };
VectorObject2D::VectorObject2D(float x, float y ) { this->x = x; this->y = y; };
VectorObject2D& VectorObject2D::add(const VectorObject2D& obj) {
	this->x += obj.x;
	this->y += obj.x;
	return *this;
}
VectorObject2D& VectorObject2D::sub(const VectorObject2D& obj) {
	this->x -= obj.x;
	this->y -= obj.x;
	return *this;
}
VectorObject2D& VectorObject2D::div(const VectorObject2D& obj) {
	this->x /= obj.x;
	this->y /= obj.x;
	return *this;
}
VectorObject2D& VectorObject2D::mul(const VectorObject2D& obj) {
	this->x *= obj.x;
	this->y *= obj.x;
	return *this;
}
std::ostream& operator<<(std::ostream& stream, const VectorObject2D& vec2) {
	stream << '(' << vec2.x << ',' << vec2.y << ')';
	return stream;
}