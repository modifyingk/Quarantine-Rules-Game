#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "QuizFinalScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace

Scene* QuizFinalScene::createScene()
{
	auto scene = Scene::create();
	auto layer = QuizFinalScene::create();
	scene->addChild(layer);
	return scene;
}

bool QuizFinalScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}
	SimpleAudioEngine::getInstance()->playEffect("Clear.wav"); // 성공 효과음
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto item = Sprite::create("goal.png");
	item->setPosition(Point(505, 550));
	this->addChild(item);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.3f);

	animation->addSpriteFrameWithFile("goal.png");
	animation->addSpriteFrameWithFile("goal_01.png");

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	item->runAction(rep);  // 애니메이션 영원히 반복

	auto item1 = MenuItemFont::create("Home", CC_CALLBACK_1(QuizFinalScene::doClose, this));	// "Home" 버튼 구현
	item1->setColor(Color3B(255, 255, 255));


	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Point(970, 30));
	this->addChild(pMenu);

	auto item_1 = Sprite::create("Fireworks.png");	// 폭죽 1
	item_1->setPosition(Point(155, 290));
	this->addChild(item_1);

	auto animation_1 = Animation::create();	// 폭죽 애니메이션 효과
	animation_1->setDelayPerUnit(0.12f);
	animation_1->addSpriteFrameWithFile("Fireworks.png");
	animation_1->addSpriteFrameWithFile("Fireworks_01.png");
	animation_1->addSpriteFrameWithFile("Fireworks_02.png");
	animation_1->addSpriteFrameWithFile("Fireworks_03.png");

	auto animate_1 = Animate::create(animation_1);
	auto rep_1 = RepeatForever::create(animate_1);
	item_1->runAction(rep_1);  // 애니메이션 영원히 반복

	auto item_2 = Sprite::create("Fireworks.png");	// 폭죽 2
	item_2->setPosition(Point(505, 290));
	this->addChild(item_2);

	auto animation_2 = Animation::create();
	animation_2->setDelayPerUnit(0.12f);
	animation_2->addSpriteFrameWithFile("Fireworks.png");
	animation_2->addSpriteFrameWithFile("Fireworks_01.png");
	animation_2->addSpriteFrameWithFile("Fireworks_02.png");
	animation_2->addSpriteFrameWithFile("Fireworks_03.png");

	auto animate_2 = Animate::create(animation_2);
	auto rep_2 = RepeatForever::create(animate_2);
	item_2->runAction(rep_2);

	auto item_3 = Sprite::create("Fireworks.png"); // 폭죽 3
	item_3->setPosition(Point(855, 290));
	this->addChild(item_3);

	auto animation_3 = Animation::create();
	animation_3->setDelayPerUnit(0.12f);
	animation_3->addSpriteFrameWithFile("Fireworks.png");
	animation_3->addSpriteFrameWithFile("Fireworks_01.png");
	animation_3->addSpriteFrameWithFile("Fireworks_02.png");
	animation_3->addSpriteFrameWithFile("Fireworks_03.png");

	auto animate_3 = Animate::create(animation_3);
	auto rep_3 = RepeatForever::create(animate_3);
	item_3->runAction(rep_3);  // 애니메이션 영원히 반복

	return true;

}

void QuizFinalScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");
}



void QuizFinalScene::doClose(Ref* pSender)	// Home 화면으로 돌아가기
{
	auto pScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(pScene);
}