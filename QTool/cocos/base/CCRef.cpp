#include "CCRef.h"

#include "base/ccMacros.h"
#include "base/CCAutoReleasePool.h"

NS_CC_BEGIN

Ref::Ref()
	: m_nReferenceCount(1)
{

}

Ref::~Ref()
{

}

void Ref::retain()
{
	CCASSERT(m_nReferenceCount > 0, "reference count should greater than 0");
	++m_nReferenceCount;
}

void Ref::release()
{
	CCASSERT(m_nReferenceCount > 0, "reference count should greater than 0");
	--m_nReferenceCount;

	if (m_nReferenceCount == 0)
	{
		delete this;
	}
}

Ref * Ref::autorelease()
{
	PoolManager::getInstance()->getCurrentPool()->addObject(this);
	return this;
}

unsigned int Ref::getReferenceCount() const
{
	return m_nReferenceCount;
}

NS_CC_END
