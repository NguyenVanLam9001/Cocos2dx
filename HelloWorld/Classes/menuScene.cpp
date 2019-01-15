#include "LogoScene.h"
#include"HelloWorldScene.h"
#include"menuScene.h"
#include"Log1.h"

#include"ui\CocosGUI.h"
USING_NS_CC;
Scene* menuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = menuScene::create();
	scene->addChild(layer);
	return scene;
}
bool menuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	

	auto screenSize = Director::getInstance()->getVisibleSize();
	/*static auto logo = Sprite::create("mySprite.png");
	logo->setPosition(screenSize.width/2, screenSize.height/2);*/
	//auto impr = Sprite::create("image2.png");
	//impr->setScale(2);


	auto BACKGROUND = Sprite::create("mama.jpg");
	BACKGROUND->setScale(0.4);	
	//BACKGROUND->getContentSize();
	BACKGROUND->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(BACKGROUND, -2);
	auto bee = Sprite::create();
	bee->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(bee);

	//logo->setPosition(50,50);


	auto myLabel = Label::createWithTTF("Mario", "fonts/Marker Felt.ttf", 24);
	myLabel->setPosition(screenSize.width / 2, screenSize.height - 30);
	//addChild(logo);
	addChild(myLabel);
	myLabel->enableGlow(Color4B::RED);
	
	auto ratingButton = ui::Button::create("rating_normal.png",
		"rating_pressed.png");
	ratingButton->addClickEventListener([&](Ref* event) {
		log("Rating clicked");
	});

	ratingButton->setAnchorPoint(Vec2(1, 0));
	ratingButton->setPosition(Vec2(screenSize.width, 0));
	addChild(ratingButton);




	auto itemPlay = MenuItemFont::create("Play", CC_CALLBACK_1(menuScene::PlayGameClick,this));
	auto itemSetting = MenuItemFont::create("Setting", nullptr);
	auto itemMoreGame = MenuItemFont::create("More Game", nullptr);
	auto itemAbout = MenuItemFont::create("About", nullptr);
	itemPlay->setPosition(400, 300);
	itemSetting->setPosition(400, 250);
	itemMoreGame->setPosition(400, 200);
	itemAbout->setPosition(400, 150);

	itemPlay->setColor(Color3B::ORANGE);
	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoreGame,
		itemAbout, nullptr);
	menuLabel->setPosition(0, 0);
	addChild(menuLabel);



	static auto checkbox = ui::CheckBox::create("checkbox_normal.png",
		"checkbox_pressed.png", "checkbox_checked.png",
		"checkbox_normal_disable.png", "checkbox_checked_disable.png");
	checkbox->setSelected(true);
	checkbox->addClickEventListener([&](Ref* event) {
		log("CheckBox state: %d", checkbox->isSelected());
	});
	checkbox->setPosition(Vec2(50,50));
	checkbox->setEnabled(true);
	addChild(checkbox);




	auto loadingBarGB = Sprite::create("loadingbar_bg.png");
	loadingBarGB->setScale(0.3);
	loadingBarGB->setPosition(Vec2(screenSize.width/ 2, 20));
	addChild(loadingBarGB);
	static auto loadingbar = ui::LoadingBar::create("loadingbar.png");
	loadingbar->setScale(0.3);
	loadingbar->setPercent(0);
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingbar->setPosition(loadingBarGB->getPosition());
	addChild(loadingbar);
	//update Loading Bar
	auto updateLoadingBar = CallFunc::create([]() {
		if (loadingbar->getPercent() < 100)
		{
			loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
	});
	auto sequenceRunUpdateLoadingBar =
		Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sequenceRunUpdateLoadingBar, 100);
	loadingbar->runAction(repeat);


	//auto beeMC = Sprite::create();
	//beeMC->setPosition(screenSize / 2, 100);
	
	//addChild(beeMC);
	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(SpriteFrame::create("bee1.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee2.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee3.png", Rect(0, 0, 150, 150)));
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	bee->runAction(RepeatForever::create(animate));
	


	/*auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(Log1::createScene());
	});
	auto sequence = Sequence::create(DelayTime::create(3), gotoNext,
		nullptr);
	runAction(sequence);
*/
	return true;
}
void menuScene::PlayGameClick(cocos2d::Ref* pSender)
{
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(Log1::createScene());
	});
	auto sequence = Sequence::create(DelayTime::create(0.1), gotoNext,
		nullptr);
	runAction(sequence);
}
