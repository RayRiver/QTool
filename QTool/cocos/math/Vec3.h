#ifndef Vec3_h__
#define Vec3_h__

#include "CCMathBase.h"

NS_CC_MATH_BEGIN

class Vec3
{
public:
	float x, y, z;

	Vec3();
	Vec3(float xx, float yy, float zz);

	// direction from p1 to p2
	Vec3(const Vec3 &p1, const Vec3 &p2);
	Vec3(const Vec3 &copy);

	~Vec3();

	bool isZero() const;

	void add(const Vec3 &v);

	float dot(const Vec3 &v) const;
	void cross(const Vec3 &v);

	float distance(const Vec3 &v) const;
	float distance2(const Vec3 &v) const;

	void normalize();
	Vec3 getNormalized() const;

	inline const Vec3 operator+(const Vec3 &v) const;
	inline Vec3 &operator+=(const Vec3 &v);
	inline const Vec3 operator-(const Vec3 &v) const;
	inline Vec3 &operator-=(const Vec3 &v);

	inline const Vec3 operator-() const;

	inline const Vec3 operator*(float s) const;
	inline Vec3 &operator*=(float s);
	inline const Vec3 operator/(float s) const;

	inline bool operator<(const Vec3& v) const;
	inline bool operator==(const Vec3& v) const;
	inline bool operator!=(const Vec3& v) const;

	static const Vec3 ZERO;
};

NS_CC_MATH_END

#include "Vec3.inl"

#endif // Vec3_h__
