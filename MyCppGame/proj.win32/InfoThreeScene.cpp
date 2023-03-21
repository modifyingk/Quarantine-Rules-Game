#pragma execution_character_set("utf-8")
#include "InfoThreeScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "StageThreeScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace
#define N 1000
USING_NS_CC;

#define IMG_WIDTH 1024

Scene* InfoThreeScene::createScene()
{
    auto scene = Scene::create();
    auto layer = InfoThreeScene::create();
    scene->addChild(layer);
    return scene;
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool InfoThreeScene::init()
{
    if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
    {
        return false;
    }
    SimpleAudioEngine::getInstance()->playEffect("Typing.wav"); // 타이핑 소리 효과음
    this->createStage();
    this->createPerson();
    this->createPerson2();
    this->createPerson3();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->createBack();
    this->createNext();

    label = Label::createWithTTF("일정거리를", "fonts/DOSSaemmul.ttf", 30);
    label2 = Label::createWithTTF("4초동안", "fonts/DOSSaemmul.ttf", 30);
    label3 = Label::createWithTTF("유지하세요", "fonts/DOSSaemmul.ttf", 30);

    label->setPosition(Point(342, 180));
    label2->setPosition(Point(502, 180));
    label3->setPosition(Point(662, 180));

    label->setOpacity(0);
    label2->setOpacity(0);
    label3->setOpacity(0);

    this->addChild(label);
    this->addChild(label2);
    this->addChild(label3);

    this->schedule(schedule_selector(InfoThreeScene::type), 0.14f);

    return true;
}
void InfoThreeScene::type(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (i < label->getStringLength())
    {
        log("called");

        letter = label->getLetter(i);
        letter->setColor(Color3B(0, 0, 0));
        letter->setOpacity(255);
        i++;
    }
    else {
        if (j < label2->getStringLength())
        {
            log("called");

            letter = label2->getLetter(j);
            letter->setColor(Color3B(0, 0, 0));
            letter->setOpacity(255);
            j++;
        }
        else {
            if (a < label3->getStringLength())
            {
                log("called");

                letter = label3->getLetter(a);
                letter->setColor(Color3B(0, 0, 0));
                letter->setOpacity(255);
                a++;
            }
            else {
                a = 0;
                unschedule(schedule_selector(InfoThreeScene::type));
            }
        }
    }
}

void InfoThreeScene::createBack()   // "Menu" 버튼 생성
{
    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(InfoThreeScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(870, 30));
    this->addChild(pMenu, 3);
}
void InfoThreeScene::createNext()   // "Start" 버튼 생성
{
    auto item1 = MenuItemFont::create("Start", CC_CALLBACK_1(InfoThreeScene::doClose2, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);
}
void InfoThreeScene::createStage() {
    auto texture = Director::getInstance()->getTextureCache()->addImage("stage3_off.png");  // Stage3 이미지 삽입
    stage = CCSprite::createWithTexture(texture, Rect(0, 0, 256, 256));
    stage->setPosition(Point(500, 630));
    this->addChild(stage, 3);
}
void InfoThreeScene::createPerson() {
    auto texture = Director::getInstance()->getTextureCache()->addImage("blueperson1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.25f);

    animation->addSpriteFrameWithFile("blueperson1.png");
    animation->addSpriteFrameWithFile("blueperson2.png");
    animation->addSpriteFrameWithFile("blueperson3.png");


    person = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    person->setPosition(Point(200, 400));
    this->addChild(person);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);

    person->runAction(rep);
}
void InfoThreeScene::createPerson2() {
    auto texture = Director::getInstance()->getTextureCache()->addImage("greenperson1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.25f);

    animation->addSpriteFrameWithFile("greenperson1.png");
    animation->addSpriteFrameWithFile("greenperson2.png");
    animation->addSpriteFrameWithFile("greenperson3.png");


    person2 = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    person2->setPosition(Point(500, 400));
    this->addChild(person2);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);

    person2->runAction(rep);
}
void InfoThreeScene::createPerson3() {
    auto texture = Director::getInstance()->getTextureCache()->addImage("pinkperson1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.25f);

    animation->addSpriteFrameWithFile("pinkperson1.png");
    animation->addSpriteFrameWithFile("pinkperson2.png");
    animation->addSpriteFrameWithFile("pinkperson3.png");


    person3 = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    person3->setPosition(Point(800, 400));
    this->addChild(person3);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);

    person3->runAction(rep);
}
void InfoThreeScene::doClose(Ref* pSender)   // 메뉴화면으로 돌아가기
{
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}
void InfoThreeScene::doClose2(Ref* pSender)   // 다음 화면으로
{
    auto pScene = StageThreeScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}