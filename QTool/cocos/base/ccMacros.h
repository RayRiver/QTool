#ifndef ccMacros_h__
#define ccMacros_h__

#include <stdio.h>
#include <assert.h>

inline void CCASSERT(bool cond, const char *msg = nullptr)
{
	if (!cond)
	{
		if (msg)
		{
			printf("Assert failed: %s\n", (msg)); 
		}
		assert(cond);
	}
}

#endif // ccMacros_h__
