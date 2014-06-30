#include "Vec3.h"

#include <math.h>
#include "math/MathUtil.h"

NS_CC_MATH_BEGIN

const Vec3 Vec3::ZERO = Vec3();

Vec3::Vec3()
	: x(0.0f), y(0.0f), z(0.0f)
{

}

Vec3::Vec3( float xx, float yy, float zz )
	: x(xx), y(yy), z(zz)
{

}

Vec3::Vec3( const Vec3 &p1, const Vec3 &p2 )
{
	x = p1.x - p2.x;
	y = p1.y - p2.y;
	z = p1.z - p2.z;
}

Vec3::Vec3( const Vec3 &copy )
{
	x = copy.x;
	y = copy.y;
	z = copy.z;
}

Vec3::~Vec3()
{

}

bool Vec3::isZero() const
{
	return x==0.0f && y==0.0f && z==0.0f;
}

void Vec3::add( const Vec3 &v )
{
	x += v.x;
	y += v.y;
	z += v.z;
}

float Vec3::dot( const Vec3 &v ) const
{
	return (x*v.x + y*v.y + z*v.z);
}

void Vec3::cross( const Vec3 &v )
{
	const Vec3 &v1 = *this;
	const Vec3 &v2 = v;
	Vec3 *dst = this;
	MathUtil::crossVec3(&v1.x, &v2.x, &dst->x);
}

float Vec3::distance( const Vec3 &v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	float dz = v.z - z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

float Vec3::distance2( const Vec3 &v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	float dz = v.z - z;
	return (dx*dx + dy*dy + dz*dz);
}

void Vec3::normalize()
{
	float n = x*x + y*y + z*z;

	// already normalized
	if (n == 1.0f)
	{
		return;
	}

	n = sqrt(n);

	// too close to zero
	if (n < MATH_TOLERANCE)
	{
		return;
	}

	n = 1.0 / n;
	x *= n;
	y *= n;
	z *= n;
}

cocos2d::Vec3 Vec3::getNormalized() const
{
	Vec3 v(*this);
	v.normalize();
	return v;
}


NS_CC_MATH_END
