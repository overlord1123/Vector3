
#ifndef _Vector3_h_
#define _Vector3_h_

#include <iostream>
#include <math.h>

class Vector3{
public:
	//constructors
	constexpr Vector3(float ix, float iy, float iz): x(ix), y(iy), z(iz){}
	constexpr Vector3(float ia): x(ia), y(ia), z(ia){}
	constexpr Vector3(): x(0), y(0), z(0){}

	//variables
	float x,y,z;

	//operators
	Vector3 operator+(const Vector3 &right) const;
	Vector3 operator-(const Vector3 &right) const;
	Vector3 operator-() const{return Vector3(-x, -y, -z);};
	Vector3 operator*(const Vector3 &right) const;
	Vector3 operator/(const Vector3 &right) const;
	Vector3& operator+=(const Vector3 &right);
	Vector3& operator-=(const Vector3 &right);
	Vector3& operator*=(const Vector3 &right);
	Vector3& operator/=(const Vector3 &right);

	//functions
	void normalize();
	Vector3 normalized() const;
	float absolute() const;
	float absolute2() const; // Squared variant
	bool isZero() const{return x == 0 && y == 0 && z == 0;}
	static float dotProduct(const Vector3 &left, const Vector3 &right);
	static Vector3 crossProduct(const Vector3 &left, const Vector3 &right);
	float angleBetweenVectors(const Vector3& otherVector) const;
	/**
	 * @brief      Rotate this vector using another vector as rotation axis.
	 *
	 * @param[in]  v         Vector used as rotations axis. Needs to be
	 *                       normalized
	 * @param[in]  rotation  The rotation angle in radians.
	 */
	void rotateArroundVector(const Vector3& v, float rotation);
};

std::ostream& operator<<(std::ostream& os, const Vector3& vector3);

#endif
