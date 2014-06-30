#ifndef CCDirector_h__
#define CCDirector_h__

#include "CCRef.h"

NS_CC_BEGIN

class Director : public Ref
{
public:
	static Director* getInstance();

	void mainLoop();
	void drawScene();
	void end();

protected:
	Director();

	void purgeDirector();

	static Director *s_instance;

private:
	bool m_purgeDirectorInNextLoop;
};

NS_CC_END

#endif // CCDirector_h__
