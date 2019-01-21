#pragma once
#include "cocos2d.h"
#include "Bullet.h"
#include"Model.h"
class Bullet : public Model
{
public:
	Bullet(cocos2d::Scene *scene);
	~Bullet();

	virtual	void Init();
	virtual	void Update();
	void UpdateLocation(cocos2d::Vec2);
	void SetStep(int step);
	int GetStep();

private:
	int mStep;
};

