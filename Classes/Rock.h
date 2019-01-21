#pragma once
#include "cocos2d.h"
#include "Model.h"
class Rock : public Model
{
public:
	Rock(cocos2d::Scene *scene);
	~Rock();

	virtual	void Init();
	virtual	void Update();

	void SetStep(int step);
	int GetStep();

private:
	int Step;
};