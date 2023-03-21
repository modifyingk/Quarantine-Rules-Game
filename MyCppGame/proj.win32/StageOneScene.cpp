#include "StageOneScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "MaskSuccessScene.h"
#include "InfoOneScene.h"

USING_NS_CC;

#define IMG_WIDTH 1024

Scene* StageOneScene::createScene()
{
    auto scene = Scene::create();
    auto layer = StageOneScene::create();
    scene->addChild(layer);
    return scene;
}

bool StageOneScene::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->createBackgroundParallax();
    this->createmask();
    this->createVirus1();
    this->createVirus2();
    this->createVirus3();
    this->createVirus4();
    this->createVirus5();
    this->createVirus6();
    this->createVirus7();
    this->createVirus8();
    this->createPerson();
    this->createBack();

    return true;
}

void StageOneScene::createBackgroundParallax()      // 배경
{
    auto backGround1 = CCSprite::create("personbackground.png");
    backGround1->setAnchorPoint(Point(0, 0));
    backGround1->setOpacity(100);   // 배경 투명도

    auto voidNode = CCParallaxNode::create();

    voidNode->addChild(backGround1, 1, Point(1.0f, 0.0f), Point(0, 0));

    voidNode->setTag(1);
    this->addChild(voidNode, 0);

}

void StageOneScene::createmask()   // 마스크 생성
{
    auto texture = Director::getInstance()->getTextureCache()->addImage("mask.png");
    mask = CCSprite::createWithTexture(texture, Rect(0, 0, 200, 200));
    mask->setPosition(Point(300, 100));
    this->addChild(mask, 2);
}

void StageOneScene::createVirus1()   // 바이러스 생성
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("virus1.png");
    virus1 = CCSprite::createWithTexture(texture1, Rect(0, 0, 200, 200));
    virus1->setPosition(Point(200, 400));
    this->addChild(virus1);
    doAction1(virus1);
}
void StageOneScene::createVirus2()
{
    auto texture2 = Director::getInstance()->getTextureCache()->addImage("virus2.png");
    virus2 = CCSprite::createWithTexture(texture2, Rect(0, 0, 200, 200));
    virus2->setPosition(Point(150, 200));
    this->addChild(virus2);
    doAction2(virus2);
}
void StageOneScene::createVirus3()
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("virus3.png");
    virus3 = CCSprite::createWithTexture(texture3, Rect(0, 0, 200, 200));
    virus3->setPosition(Point(500, 620));
    this->addChild(virus3);
    doAction3(virus3);
}
void StageOneScene::createVirus4()
{
    auto texture4 = Director::getInstance()->getTextureCache()->addImage("virus4.png");
    virus4 = CCSprite::createWithTexture(texture4, Rect(0, 0, 200, 200));
    virus4->setPosition(Point(820, 620));
    this->addChild(virus4);
    doAction4(virus4);
}
void StageOneScene::createVirus5()
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("virus1.png");
    virus5 = CCSprite::createWithTexture(texture5, Rect(0, 0, 200, 200));
    virus5->setPosition(Point(850, 370));
    this->addChild(virus5);
    doAction5(virus5);
}
void StageOneScene::createVirus6()
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("virus2.png");
    virus6 = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 200));
    virus6->setPosition(Point(800, 100));
    this->addChild(virus6);
    doAction6(virus6);
}
void StageOneScene::createVirus7()
{
    auto texture7 = Director::getInstance()->getTextureCache()->addImage("virus4.png");
    virus7 = CCSprite::createWithTexture(texture7, Rect(0, 0, 200, 200));
    virus7->setPosition(Point(120, 600));
    this->addChild(virus7);
    doAction7(virus7);
}
void StageOneScene::createVirus8()
{
    auto texture8 = Director::getInstance()->getTextureCache()->addImage("virus3.png");
    virus8 = CCSprite::createWithTexture(texture8, Rect(0, 0, 200, 200));
    virus8->setPosition(Point(400, 100));
    this->addChild(virus8);
    doAction8(virus8);
}

void StageOneScene::createPerson()   // 사람 생성
{
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("person.png");
    person = CCSprite::createWithTexture(texture9, Rect(0, 0, 300, 500));
    person->setPosition(Point(500, 200));
    this->addChild(person, 1);
    //doAction8(person);
}

void StageOneScene::createBack()   // "MENU" 버튼 생성
{
    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(StageOneScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);
}

void StageOneScene::doAction1(Ref* pSender) {   // 바이러스 회전 액션
    auto myAction = RotateBy::create(5.5, 180);
    virus1->runAction(myAction);
    auto rep = RepeatForever::create(myAction);  //애니메이션 영원히 반복
    virus1->runAction(rep);
}
void StageOneScene::doAction2(Ref* pSender) {
    auto myAction = RotateBy::create(1, 45);
    virus2->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus2->runAction(rep);
}
void StageOneScene::doAction3(Ref* pSender) {
    auto myAction = RotateBy::create(2, 50);
    virus3->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus3->runAction(rep);
}
void StageOneScene::doAction4(Ref* pSender) {
    auto myAction = RotateBy::create(2, 90);
    virus4->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus4->runAction(rep);
}
void StageOneScene::doAction5(Ref* pSender) {
    auto myAction = RotateBy::create(3, 50);
    virus5->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus5->runAction(rep);
}
void StageOneScene::doAction6(Ref* pSender) {
    auto myAction = RotateBy::create(2, 30);
    virus6->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus6->runAction(rep);
}
void StageOneScene::doAction7(Ref* pSender) {
    auto myAction = RotateBy::create(2, 50);
    virus7->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus7->runAction(rep);
}
void StageOneScene::doAction8(Ref* pSender) {
    auto myAction = RotateBy::create(2.5, 50);
    virus8->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus8->runAction(rep);
}

void StageOneScene::onEnter()
{
    Layer::onEnter();

    auto kListener = EventListenerKeyboard::create();
    kListener->onKeyPressed = CC_CALLBACK_2(StageOneScene::onKeyPressed, this);
    kListener->onKeyReleased = CC_CALLBACK_2(StageOneScene::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(kListener, this);

    isUpKeyArrow = false;
    isDownKeyArrow = false;
    isLeftKeyArrow = false;
    isRightKeyArrow = false;
}

void StageOneScene::onExit()
{
    _eventDispatcher->removeEventListenersForType(EventListener::Type::KEYBOARD);

    Layer::onExit();
}

void StageOneScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)   // 방향키 설정
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_UP_ARROW:
        isUpKeyArrow = true;
        this->startMovingBackground();
        break;
    case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        isDownKeyArrow = true;
        this->startMovingBackground();
        break;
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        isLeftKeyArrow = true;
        this->startMovingBackground();
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        isRightKeyArrow = true;
        this->startMovingBackground();
        break;
    }
    distancex = mask->getPosition().x;   // 마스크의 x좌표 위치 받기
    distancey = mask->getPosition().y;   // 마스크의 y좌표 위치 받기

    if (distancex >= 485 && distancex <= 535 && distancey >= 235 && distancey <= 260) {      // 마스크가 이 위치 범위일 때
        Director::getInstance()->replaceScene(MaskSuccessScene::createScene());      // MaskSuccessScene으로 전환 (CLEAR 화면 구현)
    }
}

void StageOneScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    isLeftKeyArrow = false;
    isRightKeyArrow = false;
    isUpKeyArrow = false;
    isDownKeyArrow = false;
    this->stopMovingBackground();
}

void StageOneScene::startMovingBackground()
{
    this->schedule(schedule_selector(StageOneScene::moveBackground));
}

void StageOneScene::stopMovingBackground()
{
    this->unschedule(schedule_selector(StageOneScene::moveBackground));
}

void StageOneScene::moveBackground(float t)
{
    auto moveStepX = 3;
    auto moveStepY = 2;

    if (isLeftKeyArrow) {
        moveStepX = -3;
        mask->setFlippedX(false);
        mask->setPosition(mask->getPosition().x + moveStepX, mask->getPosition().y);
    }
    else if (isRightKeyArrow) {
        moveStepX = 3;
        mask->setFlippedX(true);
        mask->setPosition(mask->getPosition().x + moveStepX, mask->getPosition().y);
    }
    else if (isUpKeyArrow) {
        moveStepY = 2;
        mask->setPosition(mask->getPosition().x, mask->getPosition().y + moveStepY);
    }
    else if (isDownKeyArrow) {
        moveStepY = -2;
        mask->setPosition(mask->getPosition().x, mask->getPosition().y + moveStepY);
    }

    if (mask->getPosition().x < 0)
        mask->setPosition(Point(0, mask->getPosition().y));
    else if (mask->getPosition().x > 512 * 2)
        mask->setPosition(Point(512 * 2, mask->getPosition().y));
    else if (mask->getPosition().y < 50)
        mask->setPosition(Point(mask->getPosition().x, 50));
    else if (mask->getPosition().y > 320)
        mask->setPosition(Point(mask->getPosition().x, 320));

    this->runAction(Follow::create(mask, Rect(0, 0, 512 * 2, 320)));
}

void StageOneScene::doClose(Ref* pSender)   // 메뉴화면으로 돌아가기
{
    auto pScene = InfoOneScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}