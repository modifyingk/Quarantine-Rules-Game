#include "QuizThreeAnswerScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "QuizThreeScene.h"
#include "QuizFourScene.h"
#define N 1000

Scene* QuizThreeAnswerScene::createScene()
{
	auto scene = Scene::create();
	auto layer = QuizThreeAnswerScene::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool QuizThreeAnswerScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}

	auto item1 = MenuItemFont::create("Next", CC_CALLBACK_1(QuizThreeAnswerScene::doPushQuiz_Answer, this));

	item1->setColor(Color3B(255, 255, 255));

	auto pMenu = Menu::create(item1, NULL);

	//pMenu->setPosition(Point(240, 50));
	pMenu->setPosition(Point(970, 30));

	this->addChild(pMenu);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto item_f = Sprite::create("fail.png");
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
	WideCharToMultiByte(CP_UTF8, 0, L"            거리두기만 하면 \n   마스크는 착용하지 않아도 된다.", -1, MyString, N, NULL, NULL);
	WideCharToMultiByte(CP_UTF8, 0, L"         -> 집을 제외한 외부에서는 대부분 마스크를 착용해야 한다. \n          실외에선 집회나 공연, 행사 등 사람들이 모이는 곳은 \n          사회적 거리두기 단계와 관계없이 마스크를 착용해야 한다.", -1, MyString_1, N, NULL, NULL);
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
		label->setPosition(Point(480, 420));
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

	auto item = Sprite::create("slime.png");
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
	item->runAction(rep);  //애니메이션 영원히 반복



	return true;

}

void QuizThreeAnswerScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");

}

void QuizThreeAnswerScene::doPushQuiz_Answer(Ref* pSender)

{

	auto pScene = QuizFourScene::createScene();

	Director::getInstance()->pushScene(pScene);

}


void QuizThreeAnswerScene::doClose(Ref* pSender)

{

	auto pScene = PlayScene::createScene();

	Director::getInstance()->replaceScene(pScene);

}
