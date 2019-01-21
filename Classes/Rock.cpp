#include "Model.h"
#include "Rock.h"
#include "Define.h"
#include "cocos2d.h"

Rock::Rock(cocos2d::Scene * scene) : Model()
{
	Sprite = cocos2d::Sprite::create(IMG_ROCK);
	this->SetSprite(Sprite);
	this->SetAlive(false);
	scene->addChild(Sprite);
	auto step = cocos2d::random(ROCK_MIN_STEP, ROCK_MAX_STEP);
	this->SetStep(step);
}

Rock::~Rock()
{
}

void Rock::Init()
{
	auto posX = cocos2d::random(this->getSprite()->getContentSize().width / 2, SCREEN_W - this->getSprite()->getContentSize().width / 2);
	auto posY = SCREEN_H + this->getSprite()->getContentSize().height / 2;

	this->SetPosition(cocos2d::Vec2(posX, posY));
}

void Rock::Update()
{
	if (this->IsAlive())
	{
		Sprite->setPosition(this->getPosition() - cocos2d::Vec2(0, this->GetStep()));
		if (getPosition().y <= -Sprite->getContentSize().height / 2)
		{
			SetAlive(false);
		}
	}
}

void Rock::SetStep(int step)
{
	this->Step = step;
}

int Rock::GetStep()
{
	return this->Step;
}
