#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "StageThreeClearScene.h"
#include "ThreeGuideScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace

Scene* StageThreeClearScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StageThreeClearScene::create();
	scene->addChild(layer);
	return scene;
}

bool StageThreeClearScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}
	SimpleAudioEngine::getInstance()->playEffect("Clear.wav"); // 성공 효과음

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto item = Sprite::create("clear_01.png");
	item->setPosition(Point(260, 330));
	this->addChild(item);

	auto item2 = Sprite::create("clear_02.png");
	item2->setPosition(Point(720, 330));
	this->addChild(item2);

	auto item_3 = Sprite::create("clear.png");
	item_3->setPosition(Point(530, 520));
	this->addChild(item_3);

	auto item1 = MenuItemFont::create("Next", CC_CALLBACK_1(StageThreeClearScene::doClose, this));
	item1->setColor(Color3B(255, 255, 255));


	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Point(970, 30));
	this->addChild(pMenu);


	return true;

}

void StageThreeClearScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");

}



void StageThreeClearScene::doClose(Ref* pSender)

{

	auto pScene = ThreeGuideScene::createScene();

	Director::getInstance()->replaceScene(pScene);

}