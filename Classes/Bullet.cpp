#include "Model.h"
#include "Bullet.h"
#include "Define.h"

#include "cocos2d.h"

Bullet::Bullet(cocos2d::Scene * scene) : Model()
{
	/*auto spriteBullet = cocos2d::Sprite::create(IMG_BULLET);
	this->SetSprite(spriteBullet);

	scene->addChild(spriteBullet);
	auto step = cocos2d::random(ROCK_MIN_STEP, ROCK_MAX_STEP);
	this->SetStep(step);*/
	Sprite = cocos2d::Sprite::create(IMG_BULLET);
	this->SetSprite(Sprite);
	scene->addChild(Sprite);

}

Bullet::~Bullet()
{
}

void Bullet::Init()
{

	//this->SetPosition(cocos2d::Vec2(200, 50));
	SetAlive(false);
}

void Bullet::Update()
{


	//this->SetPosition(this->GetPosition() + cocos2d::Vec2(0, this->GetStep()));
	if (IsAlive()) {
		Sprite->setPosition(cocos2d::Vec2(getLocation().x, getLocation().y + 10));
		if (getLocation().y >= SCREEN_H + Sprite->getContentSize().height / 2) {
			SetAlive(false);
		}
	}


}
void Bullet::UpdateLocation(cocos2d::Vec2 location)
{
	Sprite->setPosition(location);
}

void Bullet::SetStep(int step)
{
	this->mStep = step;
}

int Bullet::GetStep()
{
	return this->mStep;
}
