#ifndef CCNode_h__
#define CCNode_h__

#include "base/CCRef.h"

NS_CC_BEGIN

class Node : public Ref
{
public:
	static const int INVALID_TAG = -1;

	static Node *create();

	virtual bool init();

};

NS_CC_END

#endif // CCNode_h__
