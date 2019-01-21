#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Rock.h"
#include"SpaceShip.h"
#include"Bullet.h"
#include<vector>
#include"Define.h"
#include <iostream>
using namespace std;
using namespace cocos2d;
Vec2 mLocation;
SpaceShip *space;
Bullet *bullet;
vector<Rock*> listrock;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}


bool HelloWorld::init()
{

	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create(IMG_BACKGROUND);
	background->setPosition(SCREEN_W / 2, SCREEN_H / 2);
	background->setScale(1.5);
	addChild(background);


	space = new SpaceShip(this);
	space->Init();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, space->getSprite());
	

	for (int i = 0; i < 10; i++)
	{
		Rock *rock = new Rock(this);
		rock->Init();
		listrock.push_back(rock);

	}
	scheduleUpdate();
	return true;
}

void HelloWorld::update(float delta)
{
	space->Update();
	for (int i = 0; i < listrock.size(); i++)
	{
		listrock.at(i)->Update();
	}

	FrameCount++;
	if (FrameCount % 4 == 0) {
		for (int i = 0; i < listrock.size(); i++) {
			if (!listrock.at(i)->IsAlive()) {
				listrock.at(i)->Init();
				listrock.at(i)->SetAlive(true);

			}
		}
	}
	for (int i = 0; i < listrock.size(); i++)
	{
		if (listrock.at(i)->IsAlive())
		{
			if (space->CheckColisionBulletWithRock(listrock.at(i)))
			{
				listrock.at(i)->SetAlive(false);
			}

			if (space->CheckColisionWithRock(listrock.at(i)))
			{
				listrock.at(i)->SetAlive(false);

				CCLOG("Die");

			}
		}
	}
}
bool HelloWorld::onTouchBegan(Touch* touch, Event *event) {
	mLocation = touch->getLocation();
	return true;
}
void HelloWorld::onTouchMoved(Touch* touch, Event *event) {
	auto SpaceLocation = space->getSprite()->getPosition();
	auto newTouch = touch->getLocation();
	space->getSprite()->setPosition(Vec2(SpaceLocation.x - (mLocation.x - newTouch.x),
		SpaceLocation.y - (mLocation.y - newTouch.y)));
	mLocation = newTouch;
}
void HelloWorld::onTouchEnded(Touch* touch, Event *event) {

}