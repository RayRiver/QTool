#ifndef CCAutoReleasePool_h__
#define CCAutoReleasePool_h__

#include <string>
#include <vector>
#include <deque>

#include "CCRef.h"

NS_CC_BEGIN

class AutoReleasePool
{
public:
	AutoReleasePool();
	AutoReleasePool(const std::string &name);
	~AutoReleasePool();

	void addObject(Ref *object);
	void clear();
	bool contains(Ref *object) const;

private:
	std::string m_name;
	std::vector<Ref *> m_objects;
};

class PoolManager
{
public:
	static PoolManager *getInstance();
	static void destroyInstance();

	AutoReleasePool *getCurrentPool() const;

	bool isObjectInPools(Ref *obj) const;

	friend class AutoReleasePool;

private:
	PoolManager();
	~PoolManager();

	void push(AutoReleasePool *pool);
	void pop();

	static PoolManager *s_instance;

	std::deque<AutoReleasePool *> m_releasePoolStack;
	AutoReleasePool *m_currentReleasePool;
};

NS_CC_END

#endif // CCAutoReleasePool_h__
