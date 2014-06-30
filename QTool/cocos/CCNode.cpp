#include "CCNode.h"

NS_CC_BEGIN

Node * cocos2d::Node::create()
{
	Node * ret = new Node();
	if (ret && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		delete ret;	
		ret = nullptr;
	}
	return ret;
}

bool Node::init()
{
	return true;
}

NS_CC_END
	