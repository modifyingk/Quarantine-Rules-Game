#include "InfoThreeScene.h"
#include "StageThreeScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "StageThreeClearScene.h"
#include "StageThreeGameOverScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* StageThreeScene::createScene()
{
    auto scene = Scene::create();
    auto layer = StageThreeScene::create();
    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool StageThreeScene::init()
{
    if (!LayerColor::initWithColor(Color4B(300, 300, 255, 255)))
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->createBackgroundParallax();
    this->createPeople();
    this->createPeople2();
    this->createBack();


    setTimer();

    return true;

}

void StageThreeScene::createBackgroundParallax()
{
    // CCParallaxNode 생성
    CCParallaxNode* voidNode = CCParallaxNode::create();

    //배경 sprite 생성
    CCSprite* backGround1 = CCSprite::create("landscape.png");
    backGround1->setAnchorPoint(Point(0, 0));

    voidNode->addChild(backGround1, 1, Point(0.8f, 0.0f), Point(0, 0));


    voidNode->setTag(1);
    auto go1 = Place::create(Point(-768, 0));
    auto go = MoveTo::create(4, Point(0, 0));  //앞의 숫자는 딜레이 시간인듯

    auto goBack = Place::create(Point(-768, 0));

    auto seq = Sequence::create(go, goBack, NULL);

    auto act = RepeatForever::create(seq);


    voidNode->runAction(go1);
    voidNode->runAction(act);


    this->addChild(voidNode, 0);

}

void StageThreeScene::createPeople()
{
    auto texture = Director::getInstance()->getTextureCache()->addImage("people1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.8f);

    animation->addSpriteFrameWithFile("people1.png");
    animation->addSpriteFrameWithFile("people1_01.png");


    people = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    people->setPosition(Point(600, 150));
    this->addChild(people);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);

    people->runAction(rep);
}

void StageThreeScene::createPeople2()
{
    // CCParallaxNode 생성
    CCParallaxNode* voidNode1 = CCParallaxNode::create();

    //배경 sprite 생성
    CCSprite* people2 = CCSprite::create("people2.png");
    people2->setAnchorPoint(Point(0, 0));

    auto texture2 = Director::getInstance()->getTextureCache()->addImage("people2.png");
    voidNode1->addChild(people2, 1, Point(0.8f, 0.0f), Point(0, 80));  //point로 그림 위치 설정, y좌표 80
    people2 = Sprite::createWithTexture(texture2, Rect(0, 0, 100, 300));



    voidNode1->setTag(2);
    auto go1 = Place::create(Point(0, 0));  //앞의 숫자는 딜레이 시간인듯
    auto go = MoveTo::create(4, Point(500, 0));  //앞의 숫자는 딜레이 시간인듯
    auto goBack = Place::create(Point(0, 0));
    auto seq = Sequence::create(go, goBack, NULL);



    auto act1 = RepeatForever::create(seq);

    voidNode1->runAction(go1);

    voidNode1->runAction(act1);
    this->addChild(voidNode1, 160);

}
void StageThreeScene::createBack()   // "MENU" 버튼 생성
{
    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(StageThreeScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);
}
void StageThreeScene::onEnter()
{
    Layer::onEnter();

    auto kListener = EventListenerKeyboard::create();
    kListener->onKeyPressed = CC_CALLBACK_2(StageThreeScene::onKeyPressed, this);
    kListener->onKeyReleased = CC_CALLBACK_2(StageThreeScene::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(kListener, this);

    isUpKeyArrow = false;
    isDownKeyArrow = false;
    isLeftKeyArrow = false;
    isRightKeyArrow = false;
}

void StageThreeScene::onExit()
{
    _eventDispatcher->removeEventListenersForType(EventListener::Type::KEYBOARD);

    Layer::onExit();
}

void StageThreeScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        isLeftKeyArrow = true;
        this->startMovingBackground();
        break;
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        isRightKeyArrow = true;
        this->startMovingBackground();
        break;
    }


}

void StageThreeScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    isLeftKeyArrow = false;
    isRightKeyArrow = false;
    isUpKeyArrow = false;
    isDownKeyArrow = false;
    this->stopMovingBackground();
}

void StageThreeScene::startMovingBackground()
{
    this->schedule(schedule_selector(StageThreeScene::moveBackground));
}

void StageThreeScene::stopMovingBackground()
{
    this->unschedule(schedule_selector(StageThreeScene::moveBackground));
}

void StageThreeScene::moveBackground(float t)
{
    auto moveStepX = 3;
    auto moveStepY = 2;

    if (isLeftKeyArrow) {
        moveStepX = -3;
        people->setFlippedX(false);
        people->setPosition(people->getPosition().x + moveStepX, people->getPosition().y);
    }
    else if (isRightKeyArrow) {
        moveStepX = 3;
        people->setFlippedX(true);
        people->setPosition(people->getPosition().x + moveStepX, people->getPosition().y);
    }
    else if (isUpKeyArrow) {
        moveStepY = 2;
        people->setPosition(people->getPosition().x, people->getPosition().y + moveStepY);
    }
    else if (isDownKeyArrow) {
        moveStepY = -2;
        people->setPosition(people->getPosition().x, people->getPosition().y + moveStepY);
    }
    distance = people->getPosition().x;

    if (people->getPosition().x < 0)
        people->setPosition(Point(0, people->getPosition().y));
    else if (people->getPosition().x > 512 * 2)
        people->setPosition(Point(512 * 2, people->getPosition().y));
    else if (people->getPosition().y < 50)
        people->setPosition(Point(people->getPosition().x, 50));
    else if (people->getPosition().y > 320)
        people->setPosition(Point(people->getPosition().x, 320));

    this->runAction(Follow::create(people, Rect(0, 0, 512 * 2, 320)));

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    if (distance < 400) {
        Director::getInstance()->replaceScene(StageThreeGameOverScene::createScene());
    }
}

void StageThreeScene::setTimer() {
    _countDownTimer = 4.0f;
    schedule(schedule_selector(StageThreeScene::updateTimer));
}

void StageThreeScene::updateTimer(float time) {

    auto visibleSize = Director::getInstance()->getVisibleSize();

    auto pLabel1 = LabelAtlas::create("1234", "fps_images.png", 12, 32, '.');
    pLabel1->setString(std::to_string(ceilf((int)_countDownTimer)));
    pLabel1->setPosition(Point(450, 700));
    this->addChild(pLabel1);

    _countDownTimer -= time;

    if (_countDownTimer < 0) {

        _countDownTimer = 0;

        unschedule(schedule_selector(StageThreeScene::updateTimer));
        Director::getInstance()->replaceScene(StageThreeClearScene::createScene());

    }
}


void StageThreeScene::doClose(Ref* pSender)

{

    auto pScene = InfoThreeScene::createScene();

    Director::getInstance()->replaceScene(pScene);

}