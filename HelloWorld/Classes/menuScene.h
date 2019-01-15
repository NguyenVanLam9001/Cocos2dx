#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_
#include "cocos2d.h"
class menuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	void PlayGameClick(cocos2d::Ref* pSender);
	virtual bool init();	
	CREATE_FUNC(menuScene);
};
#endif

