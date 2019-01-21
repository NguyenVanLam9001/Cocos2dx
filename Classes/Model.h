#ifndef _MODEL_H_
#define _MODEL_H_
#include "cocos2d.h"
using namespace cocos2d;
class Model
{
protected:
	cocos2d:: Sprite *Sprite;
	bool isAlive;
public:
	Model();
    ~ Model();
	//void setPos(float X, float Y);
	//Sprite* getSprite();
	////void update(float);
	//void setSprite(Sprite * sprite);
	//void setIsAlive(bool IsAlive);
	//bool getIsAlive();
	cocos2d::Vec2 getLocation();

	virtual	void Init() = 0;
	virtual	void Update() = 0;

	cocos2d::Sprite* getSprite();
	void SetSprite(cocos2d::Sprite* sprite);

	void SetAlive(bool alive);
	bool IsAlive();

	cocos2d::Vec2 getPosition();
	void SetPosition(cocos2d::Vec2 pos);
	Rect GetRect();
};
#endif