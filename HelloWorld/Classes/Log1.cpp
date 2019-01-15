#include "LogoScene.h"
#include"HelloWorldScene.h"
#include"Log1.h"
#include"ui\CocosGUI.h"

using namespace std;
Sprite *icon;
USING_NS_CC;

Scene* Log1::createScene()
{
	auto scene = Scene::create();
	auto layer = Log1::create();
	scene->addChild(layer);
	return scene;
}
bool Log1::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	auto screenSize = Director::getInstance()->getVisibleSize();

	auto BACKGROUND = Sprite::create("mama.jpg");
	BACKGROUND->setScale(0.4);
	//BACKGROUND->getContentSize();
	BACKGROUND->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(BACKGROUND, -2);
	icon = Sprite::create("mario-pose2.png");
	icon->setPosition(Vec2(100,100));
	icon->setScale(0.2);
	addChild(icon);


	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Log1::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Log1::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Log1::onTouchEnded, this);
_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	
	return true;
}
bool Log1::onTouchBegan(Touch* touch, Event *event) {
	Vec2 touchLocation = touch->getLocation(); 
	auto moveTo = MoveTo::create(2, touchLocation);
	icon->runAction(moveTo);
	return true;
}
void Log1::onTouchMoved(Touch* touch, Event *event) {
	Vec2 touchLocation = touch->getLocation();
	icon->setPosition(touchLocation);
}
void Log1::onTouchEnded(Touch* touch, Event *event) {
	icon->setPosition(Vec2(0, 0));
}