#include "InfoOneScene.h"
#include "InfoTwoScene.h"
#include "InfoThreeScene.h"
#include "InfoFourScene.h"
#include "PlayScene.h"

Scene* PlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(layer);
	return scene;
}

bool PlayScene::init()
{
	if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto item = Sprite::create("menu.png");		// Menu �̹��� ����
	item->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 1.2 + origin.y));
	this->addChild(item);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.3f);
	animation->addSpriteFrameWithFile("menu.png");	// Menu �����Ÿ���
	animation->addSpriteFrameWithFile("menu_01.png");
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	item->runAction(rep);  // �ִϸ��̼� ������ �ݺ�

	auto item1 = MenuItemFont::create("Home", CC_CALLBACK_1(PlayScene::doClose, this));		// "Home" ��ư ����
	item1->setColor(Color3B(255, 255, 255));
	auto pMenu = Menu::create(item1, NULL);
	pMenu->setPosition(Point(970, 30));
	this->addChild(pMenu);


	auto item_1 = MenuItemImage::create("stage1.png", "stage1_off.png", "stage1_off.png", CC_CALLBACK_1(PlayScene::doPushScene_1, this));	// Stage �̹��� ����
	auto item_2 = MenuItemImage::create("stage2.png", "stage2_off.png", "stage2_off.png", CC_CALLBACK_1(PlayScene::doPushScene_2, this));
	auto item_3 = MenuItemImage::create("stage3.png", "stage3_off.png", "stage3_off.png", CC_CALLBACK_1(PlayScene::doPushScene_3, this));
	auto item_4 = MenuItemImage::create("stage4.png", "stage4_off.png", "stage4_off.png", CC_CALLBACK_1(PlayScene::doPushScene_4, this));

	auto menu_1 = Menu::create(item_1, NULL);
	auto menu_2 = Menu::create(item_2, NULL);
	auto menu_3 = Menu::create(item_3, NULL);
	auto menu_4 = Menu::create(item_4, NULL);

	menu_1->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 2.0 + origin.y));  // menu�� �ؾ� ��ġ�� ��
	menu_2->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 3.5 + origin.y));  // �ʹ� ������ Ŭ�� ������ �̻���
	menu_3->setPosition(Vec2(visibleSize.width / 1.4 + origin.x, visibleSize.height / 2.0 + origin.y));
	menu_4->setPosition(Vec2(visibleSize.width / 1.4 + origin.x, visibleSize.height / 3.5 + origin.y));

	this->addChild(menu_1, 1);
	this->addChild(menu_2, 1);
	this->addChild(menu_3, 1);
	this->addChild(menu_4, 1);


	return true;

}

void PlayScene::menuCallback(cocos2d::Ref* sender)
{
	CCLOG("menuCallback");

}



void PlayScene::doClose(Ref* pSender)	// Home ȭ������ ���ư���
{
	auto pScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(pScene);
}

void PlayScene::doPushScene_1(Ref* pSender)		// Stage1 ���� ȭ��
{
	auto pScene = InfoOneScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void PlayScene::doPushScene_2(Ref* pSender)		// Stage2 ���� ȭ��
{
	auto pScene = InfoTwoScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void PlayScene::doPushScene_3(Ref* pSender)		// Stage3 ���� ȭ��
{
	auto pScene = InfoThreeScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void PlayScene::doPushScene_4(Ref* pSender)		// Stage4 ���� ȭ��
{
	auto pScene = InfoFourScene::createScene();
	Director::getInstance()->pushScene(pScene);
}
