#include <sstream>

#include "tillen_math.h"

// =========== TillenArray2 beg ===========
TillenArray2::TillenArray2(double v0, double v1) : x(v0), y(v1) {};
TillenArray2::~TillenArray2() {}
std::string TillenArray2::to_str()const
{
	std::ostringstream oss;
	oss << "TillenArray2[" << std::hex << this << "]: " << std::dec << "(" << x << "," << y << ")";
	return oss.str();
}
std::ostream& operator<<(std::ostream& output, const TillenArray2& a)
{
	std::ostringstream oss;
	output << a.to_str();
	return output;
}


TillenArray2 TillenArray2::array_add(const TillenArray2& a) const
{
	return TillenArray2(this->x + a.x, this->y + a.y);
}
TillenArray2 TillenArray2::operator+(const TillenArray2& a) const
{
	return this->array_add(a);
}

TillenArray2 TillenArray2::array_sub(const TillenArray2& a) const
{
	return TillenArray2(this->x - a.x, this->y - a.y);
}
TillenArray2 TillenArray2::operator-(const TillenArray2& a) const
{
	return this->array_sub(a);
}

TillenArray2 TillenArray2::array_multi(double a) const
{
	return TillenArray2(this->x * a, this->y * a);
}
TillenArray2 TillenArray2::operator*(double a) const
{
	return this->array_multi(a);
}

double TillenArray2::array_dot(const TillenArray2& a) const
{
	return this->x * a.x + this->y * a.y;
}
double TillenArray2::operator*(const TillenArray2& a) const
{
	return this->array_dot(a);
}

double TillenArray2::array_cross(const TillenArray2& a) const
{
	return this->x * a.y - a.x * this->y;
}
// =========== TillenArray2 end ===========

// =========== TillenArray3 beg ===========
TillenArray3::TillenArray3(double v0, double v1, double v2) : x(v0), y(v1), z(v2) {};
TillenArray3::~TillenArray3() {}
std::string TillenArray3::to_str()const
{
	std::ostringstream oss;
	oss << "TillenArray3[" << std::hex << this << "]: " << std::dec << "(" << x << "," << y << "," << z << ")";
	return oss.str();
}
std::ostream& operator<<(std::ostream& output, const TillenArray3& a)
{
	std::ostringstream oss;
	output << a.to_str();
	return output;
}

TillenArray3 TillenArray3::array_add(const TillenArray3& a) const
{
	return TillenArray3(this->x + a.x, this->y + a.y, this->z + a.z);
}
TillenArray3 TillenArray3::operator+(const TillenArray3& a) const
{
	return this->array_add(a);
}

TillenArray3 TillenArray3::array_sub(const TillenArray3& a) const
{
	return TillenArray3(this->x - a.x, this->y - a.y, this->z - a.z);
}
TillenArray3 TillenArray3::operator-(const TillenArray3& a) const
{
	return this->array_sub(a);
}

TillenArray3 TillenArray3::array_multi(double a) const
{
	return TillenArray3(this->x * a, this->y * a, this->z * a);
}
TillenArray3 TillenArray3::operator*(double a) const
{
	return this->array_multi(a);
}

double TillenArray3::array_dot(const TillenArray3& a) const
{
	return this->x * a.x + this->y * a.y + this->z * a.z;
}
double TillenArray3::operator*(const TillenArray3& a) const
{
	return this->array_dot(a);
}

TillenArray3 TillenArray3::array_cross(const TillenArray3& a) const
{
	return TillenArray3(
		this->y * a.z - a.y * this->z,
		a.x * this->z - this->x * a.z,
		this->x * a.y - a.x * this->y
	);

}
// =========== TillenArray3 end ===========

// =========== TillenArray4 end ===========
TillenArray4::TillenArray4(double v0, double v1, double v2, double v3) : x(v0), y(v1), z(v2), w(v3) {};
TillenArray4::~TillenArray4() {};
std::string TillenArray4::to_str()const
{
	std::ostringstream oss;
	oss << "TillenArray4[" << std::hex << this << "]: " << std::dec << "(" << x << "," << y << "," << z << "," << w << ")";
	return oss.str();
}
std::ostream& operator<<(std::ostream& output, const TillenArray4& a)
{
	std::ostringstream oss;
	output << a.to_str();
	return output;
}

TillenArray4 TillenArray4::array_add(const TillenArray4& a) const
{
	return TillenArray4(this->x + a.x, this->y + a.y, this->z + a.z, this->w + a.w);
}
TillenArray4 TillenArray4::operator+(const TillenArray4& a) const
{
	return this->array_add(a);
}

TillenArray4 TillenArray4::array_sub(const TillenArray4& a) const
{
	return TillenArray4(this->x - a.x, this->y - a.y, this->z - a.z, this->w - a.w);
}
TillenArray4 TillenArray4::operator-(const TillenArray4& a) const
{
	return this->array_sub(a);
}

TillenArray4 TillenArray4::array_multi(double a) const
{
	return TillenArray4(this->x * a, this->y * a, this->z * a, this->w * a);
}
TillenArray4 TillenArray4::operator*(double a) const
{
	return this->array_multi(a);
}

double TillenArray4::array_dot(const TillenArray4& a) const
{
	return this->x * a.x + this->y * a.y + this->z * a.z + this->w * a.w;
}
double TillenArray4::operator*(const TillenArray4& a) const
{
	return this->array_dot(a);
}

// =========== TillenArray4 end ===========


int get_intersection_between_sphere_and_ray(TillenArray2& res, const TillenVec3& ray_start, const TillenVec3& ray_end, const TillenVec3& sphere_center, double sphere_radius)
{
	// o: ray_start
	// v: ray_end
	// c: sphere_center
	// r: radius

	int res_num = 0;

	TillenVec3 ov = ray_end - ray_start;
	TillenVec3 co = ray_start - sphere_center;

	double a = ov * ov;
	double b = co * ov * 2.0;
	double c = co * co - sphere_radius * sphere_radius;

	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return 0;
	
	res.val[0] = (-b + sqrt(discriminant)) / (2 * a);
	res.val[1] = (-b - sqrt(discriminant)) / (2 * a);

	if (discriminant == 0.0)
		return 1;

	return 2;
}


int test_tillen_math()
{
	TillenVec2 a2(10, 10), b2(9.5, 9.5);
	std::cout << "=========== TillenArray2 beg ===========" << std::endl;
	std::cout << a2 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << a2 + b2 << std::endl;
	std::cout << a2 - b2 << std::endl;
	std::cout << a2 * b2 << std::endl;
	std::cout << a2 * 3.0 << std::endl;
	std::cout << a2.array_cross(b2) << std::endl;

	std::cout << "=========== TillenArray3 beg ===========" << std::endl;
	TillenVec3 a3(10, 0, 0), b3(0, 10, 0);
	std::cout << a3 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << a3 + b3 << std::endl;
	std::cout << a3 - b3 << std::endl;
	std::cout << a3 * b3 << std::endl;
	std::cout << a3 * 3.0 << std::endl;
	std::cout << a3.array_cross(b3) << std::endl;

	std::cout << "=========== TillenArray4 beg ===========" << std::endl;
	TillenVec4 a4(10, 10, 10, 10), b4(9.5, 9.5, 9.5, 9.5);
	std::cout << a4 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << a4 + b4 << std::endl;
	std::cout << a4 - b4 << std::endl;
	std::cout << a4 * b4 << std::endl;
	std::cout << a4 * 3.0 << std::endl;
	return 0;
}
