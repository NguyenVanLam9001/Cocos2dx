#ifndef _LOG1_H_
#define _LOG1_H_
#include "cocos2d.h"
using namespace cocos2d;
class Log1 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	bool Log1::onTouchBegan(Touch* touch, Event *event);
	void Log1::onTouchMoved(Touch* touch, Event *event);
	void Log1::onTouchEnded(Touch* touch, Event *event);
	virtual bool init();
	CREATE_FUNC(Log1);
};
#endif

