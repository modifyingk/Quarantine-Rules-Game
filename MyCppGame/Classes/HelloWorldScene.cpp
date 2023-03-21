#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"  // ����� ȿ���� �ʿ��� �������
using namespace CocosDenshion;  // ����� ȿ���� �ʿ��� namespace
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
    {
        return false;
    }
    SimpleAudioEngine::getInstance()->playBackgroundMusic("PlangBGM.mp3", true);    // �����

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //this->createSanitizer();
    //this->createMask();
    //this->createVirus1();
    //this->createVirus2();

    auto item1 = MenuItemFont::create("PLAY", CC_CALLBACK_1(HelloWorld::doReplaceScene, this));  // Play ��ư ����
    item1->setPosition(Point(500, 260));   // Play ��ư ��ġ
    item1->setColor(Color3B(70, 120, 40));  // Play ��ư ��

    auto menu = Menu::create(item1, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this)); // ���� ��ư

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    auto label = Label::createWithTTF("https://pixabay.com/ko/", "fonts/arial.ttf", 20);    // ����(�Ȼ纣��) ��ó
    label->setColor(Color3B::BLACK);  // �۾� ����ٲٱ�
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        label->setPosition(Point(200, 100));
        this->addChild(label, 1);
    }

    auto menu1 = Menu::create(closeItem, NULL);
    menu1->setPosition(Vec2::ZERO);
    this->addChild(menu1, 1);

    auto sprite = Sprite::create("plang.png");  // Plang �̹��� ����
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.3f);
    animation->addSpriteFrameWithFile("plang.png");	// Plang �����Ÿ���
    animation->addSpriteFrameWithFile("plang_off.png");
    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);
    sprite->runAction(rep);  // �ִϸ��̼� ������ �ݺ�

    if (sprite == nullptr)
    {
        problemLoading("'plang.png'");
    }
    else
    {
        sprite->setPosition(Point(515, 600));
        this->addChild(sprite, 1);
    }

    auto sprite1 = Sprite::create("Start.png");
    if (sprite1 == nullptr)
    {
        problemLoading("'Start.png'");
    }
    else
    {
        sprite1->setPosition(Point(500,310));
        this->addChild(sprite1, 0);
    }

    return true;
}

void HelloWorld::createSanitizer()   // �� �ҵ��� ����
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("sanitizer.png");
    sanitizer = CCSprite::createWithTexture(texture3, Rect(0, 0, 90, 180));
    sanitizer->setPosition(Point(150, 480));
    this->addChild(sanitizer, 2);
}
void HelloWorld::createMask()    // ����ũ ����
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("mask.png");
    dirtymask = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 150));
    dirtymask->setPosition(Point(870, 160));
    this->addChild(dirtymask, 2);
}
void HelloWorld::createVirus1()   // ���̷��� ����
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("virus1.png");
    virus1 = CCSprite::createWithTexture(texture1, Rect(0, 0, 200, 200));
    virus1->setPosition(Point(870, 200));
    this->addChild(virus1, 2);
   // doAction1(virus1);
}
void HelloWorld::createVirus2()   // ���̷��� ����
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("virus1.png");
    virus2 = CCSprite::createWithTexture(texture1, Rect(0, 0, 200, 200));
    virus2->setPosition(Point(180, 200));
    this->addChild(virus2, 2);
    // doAction1(virus1);
}

void HelloWorld::menuCallback(cocos2d::Ref* sender)
{
    CCLOG("menuCallback");
}

void HelloWorld::doReplaceScene(cocos2d::Ref* pSender) {    // �޴�ȭ������ ��ȯ
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}

void HelloWorld::menuCloseCallback(cocos2d::Ref* pSender)   // ����
{
    Director::getInstance()->end();
}