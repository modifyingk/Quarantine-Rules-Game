#include "QuizFourAnswerScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "QuizFinalScene.h"
#include "QuizFourScene.h"
#define N 1000

Scene* QuizFourAnswerScene::createScene()
{
	auto scene = Scene::create();
	auto layer = QuizFourAnswerScene::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool QuizFourAnswerScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}

	auto item1 = MenuItemFont::create("Next", CC_CALLBACK_1(QuizFourAnswerScene::doPushQuiz_Answer, this));
	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Point(970, 30));
	this->addChild(pMenu);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto item_f = Sprite::create("fail.png");	// "Fail" 이미지 삽입
	item_f->setPosition(Point(500, 590));
	this->addChild(item_f);

	auto animation_f = Animation::create();
	animation_f->setDelayPerUnit(0.3f);

	animation_f->addSpriteFrameWithFile("fail.png");
	animation_f->addSpriteFrameWithFile("fail_off.png");

	auto animate_f = Animate::create(animation_f);
	auto rep_f = RepeatForever::create(animate_f);
	item_f->runAction(rep_f);  // 애니메이션 영원히 반복

	char MyString[N];
	char MyString_1[N];
	WideCharToMultiByte(CP_UTF8, 0, L"          손씻기는 30초 동안 유지하고  \n       기침은 옷소매에 하도록 해야 한다.", -1, MyString, N, NULL, NULL);
	WideCharToMultiByte(CP_UTF8, 0, L"       -> 손씻기는 30초 동안 유지하고  \n      기침은 옷소매에 하도록 해야 한다.", -1, MyString_1, N, NULL, NULL);
	auto label = Label::createWithTTF(MyString, "fonts/Cafe24Oneprettynight.ttf", 40);  
	auto label_1 = Label::createWithTTF(MyString_1, "fonts/Cafe24Oneprettynight.ttf", 40);
	label->setColor(Color3B::BLACK);
	label_1->setColor(Color3B::RED);

	if (label == nullptr) 
	{
		problemLoading("'fonts/Cafe24Oneprettynight.ttf'");
	}
	else
	{
		label->setPosition(Point(480, 400));
		this->addChild(label, 1);
	}

	if (label_1 == nullptr)
	{
		problemLoading("'fonts/Cafe24Oneprettynight.ttf'");
	}
	else
	{
		label_1->setPosition(Point(480, 260));
		this->addChild(label_1, 1);
	}

	auto item = Sprite::create("slime.png");	// 슬라임 이미지 삽입
	item->setPosition(Point(930, 120));
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
	item->runAction(rep);  // 애니메이션 영원히 반복

	return true;

}

void QuizFourAnswerScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");
}

void QuizFourAnswerScene::doPushQuiz_Answer(Ref* pSender)	// 마지막 화면으로
{
	auto pScene = QuizFinalScene::createScene();
	Director::getInstance()->pushScene(pScene);
}


void QuizFourAnswerScene::doClose(Ref* pSender)		// Menu 화면으로 돌아가기
{
	auto pScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
