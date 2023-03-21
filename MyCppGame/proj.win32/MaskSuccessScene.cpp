#include "MaskSuccessScene.h"
#include "PlayScene.h"
#include "OneGuideScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace

Scene* MaskSuccessScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MaskSuccessScene::create();
    scene->addChild(layer);
    return scene;
}

bool MaskSuccessScene::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    SimpleAudioEngine::getInstance()->playEffect("Clear.wav"); // 성공 효과음
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
    this->createClear();

    return true;
}

void MaskSuccessScene::createBackgroundParallax()   // 배경
{
    auto backGround1 = CCSprite::create("personbackground.png");
    backGround1->setAnchorPoint(Point(0, 0));
    backGround1->setOpacity(100);

    auto voidNode = CCParallaxNode::create();

    voidNode->addChild(backGround1, 1, Point(1.0f, 0.0f), Point(0, 0));

    voidNode->setTag(1);
    this->addChild(voidNode, 0);

}

void MaskSuccessScene::createmask()   // 마스크 생성
{
    auto texture = Director::getInstance()->getTextureCache()->addImage("mask.png");
    mask = CCSprite::createWithTexture(texture, Rect(0, 0, 200, 200));
    mask->setPosition(Point(495, 240));
    this->addChild(mask, 2);
}
void MaskSuccessScene::createVirus1()   // 바이러스 생성
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("virus1.png");
    virus1 = CCSprite::createWithTexture(texture1, Rect(0, 0, 200, 200));
    virus1->setPosition(Point(200, 400));
    this->addChild(virus1);
    doAction1(virus1);
}
void MaskSuccessScene::createVirus2()
{
    auto texture2 = Director::getInstance()->getTextureCache()->addImage("virus2.png");
    virus2 = CCSprite::createWithTexture(texture2, Rect(0, 0, 200, 200));
    virus2->setPosition(Point(150, 200));
    this->addChild(virus2);
    doAction2(virus2);
}
void MaskSuccessScene::createVirus3()
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("virus3.png");
    virus3 = CCSprite::createWithTexture(texture3, Rect(0, 0, 200, 200));
    virus3->setPosition(Point(500, 620));
    this->addChild(virus3);
    doAction3(virus3);
}
void MaskSuccessScene::createVirus4()
{
    auto texture4 = Director::getInstance()->getTextureCache()->addImage("virus4.png");
    virus4 = CCSprite::createWithTexture(texture4, Rect(0, 0, 200, 200));
    virus4->setPosition(Point(820, 620));
    this->addChild(virus4);
    doAction4(virus4);
}
void MaskSuccessScene::createVirus5()
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("virus1.png");
    virus5 = CCSprite::createWithTexture(texture5, Rect(0, 0, 200, 200));
    virus5->setPosition(Point(850, 370));
    this->addChild(virus5);
    doAction5(virus5);
}
void MaskSuccessScene::createVirus6()
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("virus2.png");
    virus6 = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 200));
    virus6->setPosition(Point(800, 100));
    this->addChild(virus6);
    doAction6(virus6);
}
void MaskSuccessScene::createVirus7()
{
    auto texture7 = Director::getInstance()->getTextureCache()->addImage("virus4.png");
    virus7 = CCSprite::createWithTexture(texture7, Rect(0, 0, 200, 200));
    virus7->setPosition(Point(120, 600));
    this->addChild(virus7);
    doAction7(virus7);
}
void MaskSuccessScene::createVirus8()
{
    auto texture8 = Director::getInstance()->getTextureCache()->addImage("virus3.png");
    virus8 = CCSprite::createWithTexture(texture8, Rect(0, 0, 200, 200));
    virus8->setPosition(Point(400, 100));
    this->addChild(virus8);
    doAction8(virus8);
}
void MaskSuccessScene::createPerson()   // 사람 생성
{
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("success.png");
    person = CCSprite::createWithTexture(texture9, Rect(0, 0, 427, 500));
    person->setPosition(Point(500, 190));
    this->addChild(person, 1);
}
void MaskSuccessScene::createClear()   // "CLEAR" 글자 이미지 생성
{
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("clear.png");
    clear = CCSprite::createWithTexture(texture9, Rect(0, 0, 512, 512));
    clear->setPosition(Point(530, 500));
    this->addChild(clear, 2);
}
void MaskSuccessScene::createBack()      // "Next" 버튼 생성
{
    auto item1 = MenuItemFont::create("Next", CC_CALLBACK_1(MaskSuccessScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);
}

void MaskSuccessScene::doAction1(Ref* pSender) {   // 바이러스 회전 액션
    auto myAction = RotateBy::create(5.5, 180);
    virus1->runAction(myAction);
    auto rep = RepeatForever::create(myAction);    // 애니메이션 영원히 반복
    virus1->runAction(rep);
}
void MaskSuccessScene::doAction2(Ref* pSender) {
    auto myAction = RotateBy::create(1, 45);
    virus2->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus2->runAction(rep);
}
void MaskSuccessScene::doAction3(Ref* pSender) {
    auto myAction = RotateBy::create(2, 50);
    virus3->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus3->runAction(rep);
}
void MaskSuccessScene::doAction4(Ref* pSender) {
    auto myAction = RotateBy::create(2, 90);
    virus4->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus4->runAction(rep);
}
void MaskSuccessScene::doAction5(Ref* pSender) {
    auto myAction = RotateBy::create(3, 50);
    virus5->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus5->runAction(rep);
}
void MaskSuccessScene::doAction6(Ref* pSender) {
    auto myAction = RotateBy::create(2, 30);
    virus6->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus6->runAction(rep);
}
void MaskSuccessScene::doAction7(Ref* pSender) {
    auto myAction = RotateBy::create(2, 50);
    virus7->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus7->runAction(rep);
}
void MaskSuccessScene::doAction8(Ref* pSender) {
    auto myAction = RotateBy::create(2.5, 50);
    virus8->runAction(myAction);
    auto rep = RepeatForever::create(myAction);
    virus8->runAction(rep);
}

void MaskSuccessScene::onExit()
{
    _eventDispatcher->removeEventListenersForType(EventListener::Type::KEYBOARD);

    Layer::onExit();
}

void MaskSuccessScene::doClose(Ref* pSender)   // 다음화면으로
{
    auto pScene = OneGuideScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}

