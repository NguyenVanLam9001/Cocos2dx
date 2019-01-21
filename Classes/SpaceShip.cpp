#include "Model.h"
#include "Rock.h"
#include"SpaceShip.h"
#include "Define.h"
#include "cocos2d.h"
#include"Bullet.h"
#include"ui\CocosGUI.h"
using namespace cocos2d;

SpaceShip::SpaceShip(cocos2d::Scene * scene) : Model()
{
	//auto spriteSpaceShip = cocos2d::Sprite::create(IMG_SPACESHIP);
	Sprite = cocos2d::Sprite::create(IMG_SPACESHIP);
	this->SetSprite(Sprite);
	scene->addChild(Sprite);
	IndexBullet = 0;
	for (int i = 0; i <= NUM_LIST_BULLET; i++)
	{
		auto b = new Bullet(scene);
		b->Init();
		listBullet.push_back(b);
	}
	
	
	
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::Init()
{
	this->getSprite()->setScale(0.4);
	SetPosition(cocos2d::Vec2(SCREEN_W / 2, 50));
}

void SpaceShip::Update()
{
	for (int i = 0; i < listBullet.size(); i++)
	{
		if (!listBullet.at(i)->IsAlive()) {
			listBullet.at(i)->UpdateLocation(getPosition());
		}
		listBullet.at(i)->Update();
	}

	FrameBullet++;
	if (FrameBullet % 4 == 0) {
		for (int i = 0; i < listBullet.size(); i++) {
			if (!listBullet.at(i)->IsAlive()) {
				listBullet.at(i)->Init();
				listBullet.at(i)->SetAlive(true);
				break;
			}
		}
	}
}

bool SpaceShip::CheckColisionBulletWithRock(Rock * rock)
{
	for (int i = 0; i < listBullet.size(); i++)
	{
		if (listBullet.at(i)->IsAlive())
		{
			auto rectRock = rock->GetRect();
			auto rectBull = listBullet.at(i)->GetRect();
			if (rectBull.intersectsRect(rectRock))
			{
				return true;
			}
		}
	}
	return false;
}
bool SpaceShip::CheckColisionWithRock(Rock* rock)
{
	auto rectRock = rock->GetRect();
	auto recSpace = GetRect();
	if (recSpace.intersectsRect(rectRock))
	{
		return true;
	}
	return false;
}