#include "QuizTwoAnswerScene.h"
#include "QuizThreeScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "QuizTwoScene.h"
#define N 1000

Scene* QuizTwoAnswerScene::createScene()
{
	auto scene = Scene::create();
	auto layer = QuizTwoAnswerScene::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool QuizTwoAnswerScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}

	auto item1 = MenuItemFont::create("Next", CC_CALLBACK_1(QuizTwoAnswerScene::doPushQuiz_Answer, this));

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
	item_f->runAction(rep_f);  // �ִϸ��̼� ������ �ݺ�

	char MyString[N];
	char MyString_1[N];
	WideCharToMultiByte(CP_UTF8, 0, L"                       ��ȸ�� �Ÿ� �α� �ܰ�� \n   1�ܰ�, 2�ܰ�, 3�ܰ�, 4�ܰ�, 5�ܰ�� �� 5�ܰ谡 �ִ�.", -1, MyString, N, NULL, NULL);
	WideCharToMultiByte(CP_UTF8, 0, L"                       -> ��ȸ�� �Ÿ� �α� �ܰ�� \n   1�ܰ�, 1.5�ܰ�, 2�ܰ�, 2.5�ܰ�, 3�ܰ�� �� 5�ܰ谡 �ִ�.", -1, MyString_1, N, NULL, NULL);
	auto label = Label::createWithTTF(MyString, "fonts/Cafe24Oneprettynight.ttf", 40);   // Hello World ���
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
	item->runAction(rep);  //�ִϸ��̼� ������ �ݺ�



	return true;

}

void QuizTwoAnswerScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");

}

void QuizTwoAnswerScene::doPushQuiz_Answer(Ref* pSender)

{

	auto pScene = QuizThreeScene::createScene();

	Director::getInstance()->pushScene(pScene);

}


void QuizTwoAnswerScene::doClose(Ref* pSender)

{

	auto pScene = PlayScene::createScene();

	Director::getInstance()->replaceScene(pScene);

}
