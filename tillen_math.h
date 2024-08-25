#pragma once

#include <iostream>
#include <string>

class TillenArray2
{
public:
	union
	{
		struct { double x, y; };
		double val[2];
	};

	TillenArray2(double v0 = 0, double v1 = 0);
	~TillenArray2();

	TillenArray2 operator+ (const TillenArray2& a);
	TillenArray2 operator- (const TillenArray2& a);
	TillenArray2 operator* (double factor);
	double operator* (const TillenArray2& factor);
	friend std::ostream& operator<<(std::ostream& output, const TillenArray2& a);

	TillenArray2 array_add(const TillenArray2& a);
	TillenArray2 array_sub(const TillenArray2& a);
	TillenArray2 array_multi(double factor);
	double array_dot(const TillenArray2& a);
	double array_cross(const TillenArray2& a);

	std::string to_str() const;
};

class TillenArray3
{
public:
	union
	{
		struct { double x, y, z; };
		struct { double r, g, b; };
		double val[3];
	};

	TillenArray3(double v0 = 0, double v1 = 0, double v2 = 0);
	~TillenArray3();

	TillenArray3 operator+ (const TillenArray3& a);
	TillenArray3 operator- (const TillenArray3& a);
	TillenArray3 operator* (double factor);
	double operator* (const TillenArray3& factor);
	friend std::ostream& operator<<(std::ostream& output, const TillenArray3& a);

	TillenArray3 array_add(const TillenArray3& a);
	TillenArray3 array_sub(const TillenArray3& a);
	TillenArray3 array_multi(double factor);
	double array_dot(const TillenArray3& a);
	TillenArray3 array_cross(const TillenArray3& a);

	std::string to_str() const;
};

class TillenArray4
{
public:
	union
	{
		struct { double x, y, z, w; };
		struct { double r, g, b, a; };
		double val[4];
	};

	TillenArray4(double v0 = 0, double v1 = 0, double v2 = 0, double v3 = 0);
	~TillenArray4();

	TillenArray4 operator+ (const TillenArray4& a);
	TillenArray4 operator- (const TillenArray4& a);
	TillenArray4 operator* (double factor);
	double operator* (const TillenArray4& factor);
	friend std::ostream& operator<<(std::ostream& output, const TillenArray4& a);

	TillenArray4 array_add(const TillenArray4& a);
	TillenArray4 array_sub(const TillenArray4& a);
	TillenArray4 array_multi(double factor);
	double array_dot(const TillenArray4& a);

	std::string to_str() const;
};

typedef TillenArray2 TillenVec2;
typedef TillenArray3 TillenVec3;
typedef TillenArray4 TillenVec4;

typedef TillenArray3 TillenColorRGB;
typedef TillenArray4 TillenColorRGBA;


int test_tillen_math();

