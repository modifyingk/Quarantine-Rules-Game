#include "BreadSuccessScene.h"
#include "PlayScene.h"
#include "TwoGuideScene.h"
#include "SimpleAudioEngine.h"  // ����� ȿ���� �ʿ��� �������
using namespace CocosDenshion;  // ����� ȿ���� �ʿ��� namespace

Scene* BreadSuccessScene::createScene()
{
    auto scene = Scene::create();
    auto layer = BreadSuccessScene::create();
    scene->addChild(layer);
    return scene;
}

bool BreadSuccessScene::init()
{
    SimpleAudioEngine::getInstance()->playEffect("Clear.wav"); // ���� ȿ����
    this->createBackgroundParallax();
    this->createDoor();
    this->createTable();
    this->createSanitizer();
    this->createHand();
    this->createPicture();
    this->createVirusMass2();
    this->createBread();
    this->createClear();

    auto item1 = MenuItemFont::create("Next", CC_CALLBACK_1(BreadSuccessScene::doClose, this)); // "Next" ��ư ����
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);



    return true;

}

void BreadSuccessScene::createBackgroundParallax()  // �� ���
{
    auto backGround1 = CCSprite::create("room.jpg");
    backGround1->setAnchorPoint(Point(0, 0));

    auto voidNode = CCParallaxNode::create();

    voidNode->addChild(backGround1, 1, Point(1.0f, 0.0f), Point(0, 0));

    voidNode->setTag(1);
    this->addChild(voidNode, 1);

}
void BreadSuccessScene::createDoor()    // �� ����
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("door.jpg");
    door = CCSprite::createWithTexture(texture1, Rect(0, 0, 193, 400));
    door->setPosition(Point(250, 430));
    this->addChild(door, 2);
}
void BreadSuccessScene::createTable()   // Ź�� ����
{
    auto texture2 = Director::getInstance()->getTextureCache()->addImage("table.png");
    table = CCSprite::createWithTexture(texture2, Rect(0, 0, 300, 253));
    table->setPosition(Point(590, 250));
    this->addChild(table, 2);
}
void BreadSuccessScene::createSanitizer()   // �� �ҵ��� ����
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("sanitizer.png");
    sanitizer = CCSprite::createWithTexture(texture3, Rect(0, 0, 90, 180));
    sanitizer->setPosition(Point(590, 430));
    this->addChild(sanitizer, 2);
}
void BreadSuccessScene::createHand()    // �� ����
{
    auto texture4 = Director::getInstance()->getTextureCache()->addImage("hand.png");
    hand = CCSprite::createWithTexture(texture4, Rect(0, 0, 145, 200));
    hand->setPosition(Point(200, 200));
    hand->setAnchorPoint(Vec2(0.5, 0.5));
    hand->setTag(TAG_SPRITE_IMAGE);
    this->addChild(hand, 3);
}
void BreadSuccessScene::createPicture() // ���� ��� ����
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("picture.png");
    picture = CCSprite::createWithTexture(texture5, Rect(0, 0, 167, 180));
    picture->setPosition(Point(840, 560));
    this->addChild(picture, 2);
}
void BreadSuccessScene::createMask()    // ����ũ ����
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("dirtymask.png");
    dirtymask = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 112));
    dirtymask->setPosition(Point(800, 120));
    this->addChild(dirtymask, 2);
}
void BreadSuccessScene::createVirusMass()  // ����ũ ���̷��� ����
{
    auto texture7 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass = CCSprite::createWithTexture(texture7, Rect(0, 0, 100, 92));
    virusmass->setPosition(Point(800, 120));
    this->addChild(virusmass, 2);
}
void BreadSuccessScene::createVirusMass2()  // �� ���̷��� ����
{
    auto texture8 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass2 = CCSprite::createWithTexture(texture8, Rect(0, 0, 100, 92));
    virusmass2->setPosition(Point(215, 430));
    this->addChild(virusmass2, 2);
}
void BreadSuccessScene::createBread()   // �� ����
{
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("bread.png");
    bread = CCSprite::createWithTexture(texture9, Rect(0, 0, 200, 144));
    bread->setPosition(Point(215, 160));
    this->addChild(bread, 2);
}
void BreadSuccessScene::createClear()   // "CLEAR" ���� �̹��� ����
{
    auto texture10 = Director::getInstance()->getTextureCache()->addImage("clear.png");
    success = CCSprite::createWithTexture(texture10, Rect(0, 0, 512, 512));
    success->setPosition(Point(530, 500));
    this->addChild(success, 3);
}

void BreadSuccessScene::doClose(Ref* pSender)   // �޴�ȭ������ ���ư���

{
    auto pScene = TwoGuideScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}