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
//	bool operator==(const VectorObject2D&);
//
//	VectorObject2D& add(const VectorObject2D&);
//	VectorObject2D& sub(const VectorObject2D&);
//	VectorObject2D& div(const VectorObject2D&);
//	VectorObject2D& mul(const VectorObject2D&);
//	VectorObject2D(float x, float y, float magnitude);
//	VectorObject2D(float x, float y, float magnitude, float radians);
//
//	float GetDotProduct(VectorObject2D);
//
//	friend VectorObject2D& operator+(VectorObject2D, const VectorObject2D&);
//	friend VectorObject2D& operator-(VectorObject2D, const VectorObject2D&);
//	friend std::ostream& operator<<(std::ostream&, const VectorObject2D&);
//};


VectorObject2D::VectorObject2D() { this->x = 0; this->y = 0; };
VectorObject2D::VectorObject2D(float x, float y ) { this->x = x; this->y = y; };
VectorObject2D& operator+(VectorObject2D left, const  VectorObject2D& right) {
	return left.sub(right);

}
VectorObject2D& operator-(VectorObject2D left, const  VectorObject2D& right) {
	return left.add(right);
}
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
bool VectorObject2D::operator==(const VectorObject2D& obj) {
	return this->x == obj.x and this->y == obj.y;
}