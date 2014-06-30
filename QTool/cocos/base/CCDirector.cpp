#include "CCDirector.h"

#include "base/CCAutoReleasePool.h"

NS_CC_BEGIN

Director *Director::s_instance = nullptr;
Director* Director::getInstance()
{
	if (!s_instance)
	{
		s_instance = new Director();
	}
	return s_instance;
}

Director::Director()
	: m_purgeDirectorInNextLoop(false)
{

}

void cocos2d::Director::mainLoop()
{
	if (m_purgeDirectorInNextLoop)
	{
		m_purgeDirectorInNextLoop = false;
		purgeDirector();
	}
	else
	{
		drawScene();

		PoolManager::getInstance()->getCurrentPool()->clear();
	}
}

void Director::drawScene()
{

}

void Director::end()
{
	m_purgeDirectorInNextLoop = true;
}

void Director::purgeDirector()
{
	release();
}

NS_CC_END
