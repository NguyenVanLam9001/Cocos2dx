#include "LogoScene.h"
#include"HelloWorldScene.h"
#include"menuScene.h"
USING_NS_CC;
Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}
bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	

	auto screenSize = Director::getInstance()->getVisibleSize();
	static auto logo = Sprite::create("mySprite.png");
	logo->setPosition(screenSize.width/2, screenSize.height/2);
	//auto impr = Sprite::create("image2.png");
	//impr->setScale(2);


	auto BACKGROUND = Sprite::create("splash_ground.png");
	BACKGROUND->setScale(0.6);	
	//BACKGROUND->getContentSize();
	BACKGROUND->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(BACKGROUND, -2);
	//logo->setRotation(45);
	//logo->setSkewY(10);
	//logo->setScale(10);
	//logo->setColor(Color3B(255, 0, 0));
	//logo->setOpacity(100);
	//logo->setAnchorPoint(Vec2(0, 0));

	//auto mySprite = Sprite::create("mysprite.png");
	// Rotates a Node to the specific angle over 2 seconds
	//auto rotateTo = RotateTo::create(2.0f, 40.0f);
	//logo->runAction(rotateTo);

	// Rotates a Node clockwise by 40 degree over 2 seconds
	//auto rotateBy = RotateBy::create(2.0f, 40.0f);
	//logo->runAction(rotateBy);


	// Scale to uniformly to 3x over 2 seconds
	/*auto scaleTo = ScaleTo::create(2.0f, 3.0f);
	logo->runAction(scaleTo);*/

	// Scale X to 5 and Y to 3x over 2 seconds
	//auto scaleTo = ScaleTo::create(2.0f, 3.0f, 3.0f);
	//logo->runAction(scaleTo);


	/*auto scaleBy = ScaleBy::create(2.0f, 0.5f);
	logo->runAction(scaleBy);
*/

// Move a sprite to a specific location over 2 seconds.
	//auto moveTo = MoveTo::create(2, Vec2(0, 0));
	//logo->runAction(moveTo);


	// fades in the sprite in 1 seconds
	//auto fadeIn = FadeIn::create(3.0f);
	//logo->runAction(fadeIn);

	logo->setPosition(50,50);

	addChild(logo);
	//addChild(impr);
	//auto moveTo = MoveTo::create(2, Vec2(400, 240));
	//auto callbackHide = CallFunc::create([]() {
	//	logo->setVisible(false);
	//});
	////logo->setPosition(200, 300);
	//
	//auto sequence = Sequence::create(moveTo, callbackHide, nullptr);
	//logo->runAction(sequence);


	/*auto moveBy = MoveBy::create(4, Vec2(400, 240));
	auto rotateBy = RotateBy::create(4, 360);
	auto spawn = Spawn::create(moveBy, rotateBy, nullptr);
	logo->runAction(spawn);*/


	

	//auto fadeOut = FadeOut::create(2);
	//auto fadeIn = FadeIn::create(2);
	//auto move = MoveBy::create(3, Vec2(400, 100));
	//auto rotate = RotateBy::create(3, 360);
	//auto spawn_move_rotate = Spawn::create(move, rotate, nullptr);
	//auto sequence_spawn = Sequence::create(spawn_move_rotate, fadeOut,
	//	fadeIn, nullptr);
	//logo->runAction(sequence_spawn);


	//auto moveBy = MoveBy::create(10, Vec2(400, 100));

	/*auto moveBy = MoveBy::create(4, Vec2(400, 240));
	auto rotateBy = RotateBy::create(4, 360);
	auto spawn = Spawn::create(moveBy, rotateBy, nullptr);
	logo->runAction(spawn);*/


	auto moveTo = MoveTo::create(2, Vec2(400, 240));

	/*auto callbackHide = CallFunc::create([]() {
		logo->setVisible(false);
	});*/
	auto sequence = Sequence::create(moveTo, nullptr);
	logo->runAction(sequence);

	//impr->runAction(spawn->clone());
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(menuScene::createScene());
	});
	auto sequence1 = Sequence::create(DelayTime::create(3), gotoNext,
		nullptr);
	runAction(sequence1);
	return true;
}