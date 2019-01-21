#include "Model.h"



Model::Model()
{
}


Model::~Model()
{
}

cocos2d::Sprite * Model::getSprite()
{
	return this->Sprite;
}

void Model::SetSprite(cocos2d::Sprite * sprite)
{
	this->Sprite = sprite;
}

void Model::SetAlive(bool alive)
{
	this->isAlive = alive;
	this->getSprite()->setVisible(isAlive);
}

bool Model::IsAlive()
{
	return this->isAlive;
}

cocos2d::Vec2 Model::getPosition()
{
	return this->getSprite()->getPosition();
}

void Model::SetPosition(cocos2d::Vec2 pos)
{
	this->getSprite()->setPosition(pos);
}


cocos2d::Vec2 Model::getLocation() {
	return Sprite->getPosition();
}

Rect Model::GetRect()
{
	return Sprite->getBoundingBox();
}
