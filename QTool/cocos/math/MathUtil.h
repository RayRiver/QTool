#ifndef MathUtil_h__
#define MathUtil_h__

#include "CCMathBase.h"

NS_CC_MATH_BEGIN

class MathUtil
{
	friend class Vec3;

private:
	inline static void crossVec3(const float *v1, const float *v2, float *dst);
};

NS_CC_MATH_END

#include "MathUtil.inl"

#endif // MathUtil_h__
