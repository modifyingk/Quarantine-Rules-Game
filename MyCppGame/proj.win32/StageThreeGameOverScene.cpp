#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "StageThreeGameOverScene.h"
#include "StageThreeScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace

Scene* StageThreeGameOverScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StageThreeGameOverScene::create();
	scene->addChild(layer);
	return scene;
}

bool StageThreeGameOverScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();   // 배경음악 일시정지
	SimpleAudioEngine::getInstance()->playEffect("Fail.wav"); // 실패 효과음
	auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(StageThreeGameOverScene::doClose, this));
	item1->setColor(Color3B(255, 255, 255));
	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Point(970, 30));
	this->addChild(pMenu);

	auto item2 = MenuItemFont::create("Replay", CC_CALLBACK_1(StageThreeGameOverScene::doClose2, this)); // "Replay" 버튼 구현
	item2->setColor(Color3B(255, 255, 255));
	auto pMenu2 = Menu::create(item2, NULL);
	pMenu2->setPosition(Point(870, 30));
	this->addChild(pMenu2, 3);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto item3 = Sprite::create("gameover.png");
	item3->setPosition(Point(260, 300));
	this->addChild(item3);

	auto item4 = Sprite::create("gameover_01.png");
	item4->setPosition(Point(730, 300));
	this->addChild(item4);

	auto item_3 = Sprite::create("game.png");
	item_3->setPosition(Point(550, 650));
	this->addChild(item_3);

	auto animation_3 = Animation::create();
	animation_3->setDelayPerUnit(0.8f);

	animation_3->addSpriteFrameWithFile("game.png");
	animation_3->addSpriteFrameWithFile("over.png");

	auto animate_3 = Animate::create(animation_3);
	auto rep_3 = RepeatForever::create(animate_3);
	item_3->runAction(rep_3);  // 애니메이션 영원히 반복

	return true;

}

void StageThreeGameOverScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");
}

void StageThreeGameOverScene::doClose(Ref* pSender)
{
	auto pScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(pScene);
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();  // 배경음악 다시시작
}

void StageThreeGameOverScene::doClose2(Ref* pSender)   // 게임 다시 시작
{
	auto pScene = StageThreeScene::createScene();
	Director::getInstance()->replaceScene(pScene);
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();  // 배경음악 다시시작
}