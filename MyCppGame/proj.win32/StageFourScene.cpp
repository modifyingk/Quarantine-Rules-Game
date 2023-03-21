#include "StageFourScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "QuizOneScene.h"
#include "QuizTwoScene.h"
#include  "StageFourAnswerScene.h"
#include "InfoFourScene.h"
#define N 1000
#include "SimpleAudioEngine.h"  // ����� ȿ���� �ʿ��� �������
using namespace CocosDenshion;  // ����� ȿ���� �ʿ��� namespace

Scene* StageFourScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StageFourScene::create();
	scene->addChild(layer);
	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool StageFourScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}

	auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(StageFourScene::doClose, this));

	item1->setColor(Color3B(255, 255, 255));

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	char MyString[N];
	WideCharToMultiByte(CP_UTF8, 0, L"5������� �������� �������� ��âȸ, ��ȣȸ, ����ȸ�� \n             �Ұ��������� ����ȸ���� �����ϴ�.", -1, MyString, N, NULL, NULL);
	auto label = Label::createWithTTF(MyString, "fonts/Cafe24Oneprettynight.ttf", 40);
	label->setColor(Color3B::BLACK);  // �۾� ����ٲٱ�
	if (label == nullptr)
	{
		problemLoading("'fonts/Cafe24Oneprettynight.ttf'");
	}
	else
	{
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height / 1.2 - label->getContentSize().height));
		this->addChild(label, 1);
	}

	auto item_1 = MenuItemImage::create("o.png", "o.png", "o.png", CC_CALLBACK_1(StageFourScene::doPushQuiz_o, this));
	auto item_2 = MenuItemImage::create("x.png", "x.png", "x.png", CC_CALLBACK_1(StageFourScene::doPushQuiz_x, this));

	auto menu_1 = Menu::create(item_1, NULL);
	auto menu_2 = Menu::create(item_2, NULL);

	menu_1->setPosition(Vec2(visibleSize.width / 3.0 + origin.x, visibleSize.height / 3.0 + origin.y));  // menu�� �ؾ� ��ġ�� ��
	menu_2->setPosition(Vec2(visibleSize.width / 1.5 + origin.x, visibleSize.height / 3.0 + origin.y));  // �ʹ� ������ Ŭ�� ������ �̻���

	this->addChild(menu_1, 1);
	this->addChild(menu_2, 1);

	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Point(970, 30));
	this->addChild(pMenu);

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
	item->runAction(rep);  // �ִϸ��̼� ������ �ݺ�



	return true;

}

void StageFourScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");
}

void StageFourScene::doPushQuiz_o(Ref* pSender)		// O �������� ��
{
	SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // Ŭ�� ȿ����
	auto pScene = StageFourAnswerScene::createScene();	// Ʋ�� -> �ùٸ� ���� �˷��ִ� ȭ������
	Director::getInstance()->pushScene(pScene);
}

void StageFourScene::doPushQuiz_x(Ref* pSender)		// X �������� ��
{
	SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // Ŭ�� ȿ����
	auto pScene = QuizOneScene::createScene();	// �ι�° ������
	Director::getInstance()->pushScene(pScene);
}

void StageFourScene::doClose(Ref* pSender)	// ���� ȭ������(Stage 4 ���� ȭ��)
{
	auto pScene = InfoFourScene::createScene();
	Director::getInstance()->replaceScene(pScene);
}
