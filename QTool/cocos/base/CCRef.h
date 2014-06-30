#ifndef CCRef_h__
#define CCRef_h__

#include "base/CCPlatformMacros.h"

NS_CC_BEGIN

class Ref
{
public:
	void retain();
	void release();
	Ref *autorelease();
	unsigned int getReferenceCount() const;

protected:
	Ref();
public:
	virtual ~Ref();

protected:
	unsigned int m_nReferenceCount;

	friend class AutoReleasePool;
};

NS_CC_END

#endif // CCRef_h__
