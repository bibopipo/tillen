#include "tillen_math.h"

// =========== TillenArray2 beg ===========
TillenArray2::TillenArray2(double v0, double v1) : x(v0), y(v1) {};
TillenArray2::~TillenArray2() {}

TillenArray2 TillenArray2::array_add(const TillenArray2& a)
{
	return TillenArray2(this->x + a.x, this->y + a.y);
}
TillenArray2 TillenArray2::operator+(const TillenArray2& a)
{
	return this->array_add(a);
}

TillenArray2 TillenArray2::array_sub(const TillenArray2& a)
{
	return TillenArray2(this->x - a.x, this->y - a.y);
}
TillenArray2 TillenArray2::operator-(const TillenArray2& a)
{
	return this->array_sub(a);
}

TillenArray2 TillenArray2::array_multi(double a)
{
	return TillenArray2(this->x * a, this->y * a);
}
TillenArray2 TillenArray2::operator*(double a)
{
	return this->array_multi(a);
}

double TillenArray2::array_dot(const TillenArray2& a)
{
	return this->x * a.x + this->y * a.y;
}
double TillenArray2::operator*(const TillenArray2& a)
{
	return this->array_dot(a);
}

double TillenArray2::array_cross(const TillenArray2& a)
{
	return this->x * a.y - a.x * this->y;
}
// =========== TillenArray2 end ===========

// =========== TillenArray3 beg ===========
TillenArray3::TillenArray3(double v0, double v1, double v2) : x(v0), y(v1), z(v2) {};
TillenArray3::~TillenArray3() {}
TillenArray3 TillenArray3::array_add(const TillenArray3& a)
{
	return TillenArray3(this->x + a.x, this->y + a.y, this->z + a.z);
}
TillenArray3 TillenArray3::operator+(const TillenArray3& a)
{
	return this->array_add(a);
}

TillenArray3 TillenArray3::array_sub(const TillenArray3& a)
{
	return TillenArray3(this->x - a.x, this->y - a.y, this->z - a.z);
}
TillenArray3 TillenArray3::operator-(const TillenArray3& a)
{
	return this->array_sub(a);
}

TillenArray3 TillenArray3::array_multi(double a)
{
	return TillenArray3(this->x * a, this->y * a, this->z * a);
}
TillenArray3 TillenArray3::operator*(double a)
{
	return this->array_multi(a);
}

double TillenArray3::array_dot(const TillenArray3& a)
{
	return this->x * a.x + this->y * a.y + this->z * a.z;
}
double TillenArray3::operator*(const TillenArray3& a)
{
	return this->array_dot(a);
}

TillenArray3 TillenArray3::array_cross(const TillenArray3& a)
{
	// TODO: 
	return TillenArray3();
}
// =========== TillenArray3 end ===========

// =========== TillenArray4 end ===========
TillenArray4::TillenArray4(double v0, double v1, double v2, double v3) : x(v0), y(v1), z(v2), w(v3) {};
TillenArray4::~TillenArray4() {};

TillenArray4 TillenArray4::array_add(const TillenArray4& a)
{
	return TillenArray4(this->x + a.x, this->y + a.y, this->z + a.z, this->w + a.w);
}
TillenArray4 TillenArray4::operator+(const TillenArray4& a)
{
	return this->array_add(a);
}

TillenArray4 TillenArray4::array_sub(const TillenArray4& a)
{
	return TillenArray4(this->x - a.x, this->y - a.y, this->z - a.z, this->w - a.w);
}
TillenArray4 TillenArray4::operator-(const TillenArray4& a)
{
	return this->array_sub(a);
}

TillenArray4 TillenArray4::array_multi(double a)
{
	return TillenArray4(this->x * a, this->y * a, this->z * a, this->w * a);
}
TillenArray4 TillenArray4::operator*(double a)
{
	return this->array_multi(a);
}

double TillenArray4::array_dot(const TillenArray4& a)
{
	return this->x * a.x + this->y * a.y + this->z * a.z + this->w * a.w;
}
double TillenArray4::operator*(const TillenArray4& a)
{
	return this->array_dot(a);
}

// =========== TillenArray4 end ===========
