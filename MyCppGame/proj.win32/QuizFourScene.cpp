#include "QuizThreeScene.h"
#include "QuizFourScene.h"
#include "QuizFinalScene.h"
#include "QuizFourAnswerScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#define N 1000
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace

Scene* QuizFourScene::createScene()
{
	auto scene = Scene::create();
	auto layer = QuizFourScene::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool QuizFourScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}

	auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(QuizFourScene::doClose, this));

	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	//pMenu->setPosition(Point(240, 50));
	pMenu->setPosition(Point(970, 30));

	this->addChild(pMenu);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	char MyString[N];
	WideCharToMultiByte(CP_UTF8, 0, L"          손씻기는 30초 동안 유지하고  \n       기침은 옷소매에 하도록 해야 한다.", -1, MyString, N, NULL, NULL);
	auto label = Label::createWithTTF(MyString, "fonts/Cafe24Oneprettynight.ttf", 40);   // Hello World 출력
	label->setColor(Color3B::BLACK);  //글씨 색상바꾸기
	if (label == nullptr)
	{
		problemLoading("'fonts/Cafe24Oneprettynight.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height / 1.2 - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	auto item_1 = MenuItemImage::create("o.png", "o.png", "o.png", CC_CALLBACK_1(QuizFourScene::doPushQuiz_o, this));
	auto item_2 = MenuItemImage::create("x.png", "x.png", "x.png", CC_CALLBACK_1(QuizFourScene::doPushQuiz_x, this));

	auto menu_1 = Menu::create(item_1, NULL);
	auto menu_2 = Menu::create(item_2, NULL);

	menu_1->setPosition(Vec2(visibleSize.width / 3.0 + origin.x, visibleSize.height / 3.0 + origin.y));  //menu로 해야 위치가 들어감
	menu_2->setPosition(Vec2(visibleSize.width / 1.5 + origin.x, visibleSize.height / 3.0 + origin.y));  //너무 가까우면 클릭 지점이 이상함

	this->addChild(menu_1, 1);
	this->addChild(menu_2, 1);

	//슬라임 넣기
	auto item = Sprite::create("slime.png");
	item->setPosition(Vec2(visibleSize.width / 1.08 + origin.x, visibleSize.height / 6 + origin.y));
	this->addChild(item);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.08f);

	animation->addSpriteFrameWithFile("slime.png");
	animation->addSpriteFrameWithFile("slime_01.png");
	animation->addSpriteFrameWithFile("slime_02.png");
	animation->addSpriteFrameWithFile("slime_03.png");
	animation->addSpriteFrameWithFile("slime_04.png");
	animation->addSpriteFrameWithFile("slime_05.png");

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	item->runAction(rep);  //애니메이션 영원히 반복



	return true;

}

void QuizFourScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");

}

void QuizFourScene::doPushQuiz_o(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // 클릭 효과음
	auto pScene = QuizFinalScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void QuizFourScene::doPushQuiz_x(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // 클릭 효과음
	auto pScene = QuizFourAnswerScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void QuizFourScene::doClose(Ref* pSender)
{
	auto pScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}