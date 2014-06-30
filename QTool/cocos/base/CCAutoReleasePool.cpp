#include "CCAutoReleasePool.h"

#include "base/ccMacros.h"

NS_CC_BEGIN

AutoReleasePool::AutoReleasePool()
	: m_name("")
{
	m_objects.reserve(150);
	PoolManager::getInstance()->push(this);
}

AutoReleasePool::AutoReleasePool( const std::string &name )
	: m_name(name)
{
	m_objects.reserve(150);
	PoolManager::getInstance()->push(this);
}

AutoReleasePool::~AutoReleasePool()
{
	clear();
	PoolManager::getInstance()->pop();
}

void AutoReleasePool::addObject( Ref *object )
{
	m_objects.push_back(object);
}

void AutoReleasePool::clear()
{
	for (const auto &obj : m_objects)
	{
		obj->release();
	}
	m_objects.clear();
}

bool AutoReleasePool::contains( Ref *object ) const
{
	for (const auto &obj : m_objects)
	{
		if (object == obj)
		{
			return true;
		}
	}
	return false;
}

PoolManager *PoolManager::s_instance = nullptr;
PoolManager * PoolManager::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new PoolManager();
		s_instance->m_currentReleasePool = new AutoReleasePool("cocos autorelease pool");
		s_instance->m_releasePoolStack.push_back(s_instance->m_currentReleasePool);
	}
	return s_instance;
}

void PoolManager::destroyInstance()
{
	delete s_instance;
	s_instance = nullptr;
}

PoolManager::PoolManager()
{

}

PoolManager::~PoolManager()
{
	while (!m_releasePoolStack.empty())
	{
		auto pool = m_releasePoolStack.back();
		m_releasePoolStack.pop_back();
		delete pool;
	}
}

AutoReleasePool * PoolManager::getCurrentPool() const
{
	return m_currentReleasePool;
}

bool PoolManager::isObjectInPools( Ref *obj ) const
{
	for (const auto &pool : m_releasePoolStack)
	{
		if (pool->contains(obj))
		{
			return true;
		}
	}
	return false;
}

void PoolManager::push( AutoReleasePool *pool )
{
	m_releasePoolStack.push_back(pool);
	m_currentReleasePool = pool;
}

void PoolManager::pop()
{
	CCASSERT(m_releasePoolStack.size() >= 1);

	m_releasePoolStack.pop_back();

	if (m_releasePoolStack.size() > 1)
	{
		m_currentReleasePool = m_releasePoolStack.back();
	}
}

NS_CC_END
