#include "StageTwoScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "BreadSuccessScene.h"
#include "BreadFailScene.h"
#include "SimpleAudioEngine.h"  // ����� ȿ���� �ʿ��� �������
using namespace CocosDenshion;  // ����� ȿ���� �ʿ��� namespace
#define N 1000

Scene* StageTwoScene::createScene()
{
    auto scene = Scene::create();
    auto layer = StageTwoScene::create();
    scene->addChild(layer);
    return scene;
}

bool StageTwoScene::init()
{
    this->createBackgroundParallax();
    this->createDoor();
    this->createTable();
    this->createSanitizer();
    this->createHand();
    this->createVir();
    auto vir = (Sprite*)this->getChildByTag(TAG_SPRITE_IMAGE_1);
    auto mask = (Sprite*)this->getChildByTag(TAG_SPRITE_IMAGE_2);
    Hide* action = Hide::create();
    vir->runAction(action);
    this->createPicture();
    this->createMask();
    //this->createVirusMass();
    this->createVirusMass2();

    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(StageTwoScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);

    pMenu->setPosition(Point(970, 30));

    this->addChild(pMenu, 3);

    listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(StageTwoScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(StageTwoScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(StageTwoScene::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    listenerVir = EventListenerTouchOneByOne::create();
    listenerVir->onTouchBegan = CC_CALLBACK_2(StageTwoScene::onTouchBeganVir, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerVir, this);

    return true;

}

void StageTwoScene::createBackgroundParallax()  // �� ���
{
    auto backGround1 = CCSprite::create("room.jpg");
    backGround1->setAnchorPoint(Point(0, 0));

    auto voidNode = CCParallaxNode::create();

    voidNode->addChild(backGround1, 1, Point(1.0f, 0.0f), Point(0, 0));

    voidNode->setTag(1);
    this->addChild(voidNode, 1);

}

void StageTwoScene::createDoor()    // �� ����
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("door.jpg");
    door = CCSprite::createWithTexture(texture1, Rect(0, 0, 193, 400));
    door->setPosition(Point(250, 430));
    this->addChild(door, 2);
}
void StageTwoScene::createTable()   // Ź�� ����
{
    auto texture2 = Director::getInstance()->getTextureCache()->addImage("table.png");
    table = CCSprite::createWithTexture(texture2, Rect(0, 0, 300, 253));
    table->setPosition(Point(590, 250));
    this->addChild(table, 2);
}
void StageTwoScene::createSanitizer()   // �� �ҵ��� ����
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("sanitizer.png");
    sanitizer = CCSprite::createWithTexture(texture3, Rect(0, 0, 90, 180));
    sanitizer->setPosition(Point(590, 430));
    this->addChild(sanitizer, 2);
}
void StageTwoScene::createHand()    // �� ����
{
    auto texture4 = Director::getInstance()->getTextureCache()->addImage("hand.png");
    hand = CCSprite::createWithTexture(texture4, Rect(0, 0, 145, 200));
    hand->setPosition(Point(200, 200));
    hand->setAnchorPoint(Vec2(0.5, 0.5));
    hand->setTag(TAG_SPRITE_IMAGE);
    this->addChild(hand, 3);
}
void StageTwoScene::createVir()     // �� ���̷��� ����
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    Vir = CCSprite::createWithTexture(texture5, Rect(0, 0, 100, 92));
    Vir->setPosition(Point(200, 200));
    Vir->setAnchorPoint(Vec2(0.5, 0.5));
    Vir->setTag(TAG_SPRITE_IMAGE_1);
    this->addChild(Vir, 3);
}
void StageTwoScene::createPicture()  // ���� ��� ����
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("picture.png");
    picture = CCSprite::createWithTexture(texture5, Rect(0, 0, 167, 180));
    picture->setPosition(Point(840, 560));
    this->addChild(picture, 2);
}
void StageTwoScene::createMask()    // ����ũ ����
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("dirtymask.png");
    dirtymask = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 112));
    dirtymask->setPosition(Point(800, 120));
    dirtymask->setTag(TAG_SPRITE_IMAGE_2);
    this->addChild(dirtymask, 2);
}
void StageTwoScene::createVirusMass()  // ����ũ ���̷��� ����
{
    auto texture7 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass = CCSprite::createWithTexture(texture7, Rect(0, 0, 100, 92));
    virusmass->setPosition(Point(800, 120));
    this->addChild(virusmass, 2);
}
void StageTwoScene::createVirusMass2()  // �� ���̷��� ����
{
    auto texture8 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass2 = CCSprite::createWithTexture(texture8, Rect(0, 0, 100, 92));
    virusmass2->setPosition(Point(215, 430));
    this->addChild(virusmass2, 2);
}
void StageTwoScene::createBread()   // �� ����
{
    SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // �� Ŭ�� ȿ����
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("bread.png");
    bread = CCSprite::createWithTexture(texture9, Rect(0, 0, 200, 144));
    bread->setPosition(Point(215, 430));
    this->addChild(bread, 2);
    doAction(bread);

}
void StageTwoScene::doAction(Ref* pSender) {    // �� ������ �ִϸ��̼�
    auto moveBy = MoveBy::create(1.2, Vec2(0, -270));
    bread->runAction(moveBy);
}

void StageTwoScene::setMove(Vec2 location) {  // �� �����̱�
    auto spr = (Sprite*)this->getChildByTag(TAG_SPRITE_IMAGE);
    spr->setPosition(location);
}

void StageTwoScene::setMoveVir(Vec2 location) {  // ���̷��� ��Ÿ����, �����
    auto vir = (Sprite*)this->getChildByTag(TAG_SPRITE_IMAGE_1);
    auto mask = (Sprite*)this->getChildByTag(TAG_SPRITE_IMAGE_2);
    if (location.x >= 570 && location.x <= 610 && location.y >= 410 && location.y <= 450) {     // �� �ҵ��� ������ ���̷��� �����
        SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // �ռҵ��� Ŭ�� ȿ����
        Hide* action = Hide::create();
        vir->runAction(action);

    }
    else if (location.x >= 195 && location.x <= 235 && location.y >= 410 && location.y <= 450) {    // ���� ������ ���̷��� ����
        SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // ���� Ŭ�� ȿ����
        Show* action = Show::create();
        vir->runAction(action);
        createBread();
    }
    vir->setPosition(location);

    if (vir->isVisible() == false) {
        if (location.x >= 200 && location.x <= 300 && location.y >= 100 && location.y <= 200) { // �ռҵ��� �ٸ��� �� ������ ��
            SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // �� Ŭ�� ȿ����
            Director::getInstance()->replaceScene(BreadSuccessScene::createScene());
        }
        else if (location.x >= 730 && location.x <= 800 && location.y >= 100 && location.y <= 200) { // ���̷��� ���� ����ũ ������ ��
            SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // ����ũ Ŭ�� ȿ����
            Hide* action = Hide::create();
            mask->runAction(action);
        }
    }
    else if ((vir->isVisible() == true)) {
        if (location.x >= 730 && location.x <= 800 && location.y >= 100 && location.y <= 200) { // ���̷����� ����ũ ������ ��
            SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // ����ũ Ŭ�� ȿ����
            Director::getInstance()->replaceScene(BreadFailScene::createScene());
            //Director::getInstance()->end();
        }
        else if (location.x >= 200 && location.x <= 300 && location.y >= 100 && location.y <= 200) { // ���̷����� �� ������ ��
            SimpleAudioEngine::getInstance()->playEffect("DropBread.wav"); // �� Ŭ�� ȿ����
            Director::getInstance()->replaceScene(BreadFailScene::createScene());
            //Director::getInstance()->end();
        }
    }
}

bool StageTwoScene::onTouchBegan(Touch* touch, Event* unused_event) {
    Vec2 location = touch->getLocation();
    setMove(location);
    return true;
}

bool StageTwoScene::onTouchBeganVir(Touch* touch, Event* unused_event) {
    Vec2 location = touch->getLocation();
    setMoveVir(location);
    return true;
}

void StageTwoScene::onTouchEnded(Touch* touch, Event* unused_event) {

}

void StageTwoScene::onTouchMoved(Touch* touch, Event* unused_event) {

}

void StageTwoScene::doClose(Ref* pSender)   // �޴�ȭ������ ���ư���
{
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}