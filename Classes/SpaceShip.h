#pragma once
#include "cocos2d.h"
#include "SpaceShip.h"
#include "Model.h"
#include <vector>
#include<Rock.h>
#include<Bullet.h>
using namespace cocos2d;
using namespace std;
class SpaceShip : public Model
{

private:
	vector<Bullet*> listBullet;
	int IndexBullet;
	int FrameBullet;
public:
	SpaceShip(cocos2d::Scene *scene);
	~SpaceShip();

	virtual	void Init();
	virtual	void Update();
	bool CheckColisionWithRock(Rock *rock);
	bool CheckColisionBulletWithRock(Rock *rock);	
};

