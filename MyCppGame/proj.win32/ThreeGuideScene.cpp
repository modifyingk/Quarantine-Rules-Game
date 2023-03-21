#pragma execution_character_set("utf-8")
#include "ThreeGuideScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "StageThreeScene.h"
#include "InfoFourScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace
#define N 1000
USING_NS_CC;

#define IMG_WIDTH 1024

Scene* ThreeGuideScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ThreeGuideScene::create();
    scene->addChild(layer);
    return scene;
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool ThreeGuideScene::init()
{
    if (!LayerColor::initWithColor(Color4B(249, 223, 132, 255)))
    {
        return false;
    }
    SimpleAudioEngine::getInstance()->playEffect("Typing.wav"); // 타이핑 소리 효과음

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->createBack();
    this->createBoard();
    this->createPerson();
    this->createNext();

    label = Label::createWithTTF("다른", "fonts/DOSSaemmul.ttf", 30);
    label2 = Label::createWithTTF("사람과의", "fonts/DOSSaemmul.ttf", 30);
    label3 = Label::createWithTTF("거리는", "fonts/DOSSaemmul.ttf", 30);
    label4 = Label::createWithTTF("1m", "fonts/DOSSaemmul.ttf", 30);
    label5 = Label::createWithTTF("이상", "fonts/DOSSaemmul.ttf", 30);
    label6 = Label::createWithTTF("떨어져", "fonts/DOSSaemmul.ttf", 30);
    label7 = Label::createWithTTF("있어야", "fonts/DOSSaemmul.ttf", 30);
    label8 = Label::createWithTTF("해요!", "fonts/DOSSaemmul.ttf", 30);

    label->setPosition(Point(290, 500));
    label2->setPosition(Point(380, 500));
    label3->setPosition(Point(510, 500));
    label4->setPosition(Point(590, 500));
    label5->setPosition(Point(660, 500));

    label6->setPosition(Point(360, 430));
    label7->setPosition(Point(470, 430));
    label8->setPosition(Point(570, 430));

    label->setOpacity(0);
    label2->setOpacity(0);
    label3->setOpacity(0);
    label4->setOpacity(0);
    label5->setOpacity(0);
    label6->setOpacity(0);
    label7->setOpacity(0);
    label8->setOpacity(0);

    this->addChild(label, 3);
    this->addChild(label2, 3);
    this->addChild(label3, 3);
    this->addChild(label4, 3);
    this->addChild(label5, 3);
    this->addChild(label6, 3);
    this->addChild(label7, 3);
    this->addChild(label8, 3);

    this->schedule(schedule_selector(ThreeGuideScene::type), 0.08f);

    return true;
}
void ThreeGuideScene::type(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (i < label->getStringLength())
    {
        log("called");

        letter = label->getLetter(i);
        letter->setColor(Color3B(255, 255, 255));
        letter->setOpacity(255);
        i++;
    }
    else {
        if (j < label2->getStringLength())
        {
            log("called");

            letter = label2->getLetter(j);
            letter->setColor(Color3B(255, 255, 255));
            letter->setOpacity(255);
            j++;
        }
        else {
            if (a < label3->getStringLength())
            {
                log("called");

                letter = label3->getLetter(a);
                letter->setColor(Color3B(255, 255, 255));
                letter->setOpacity(255);
                a++;
            }
            else {
                if (b < label4->getStringLength())
                {
                    log("called");

                    letter = label4->getLetter(b);
                    letter->setColor(Color3B(255, 255, 255));
                    letter->setOpacity(255);
                    b++;
                }
                else {
                    if (c < label5->getStringLength())
                    {
                        log("called");

                        letter = label5->getLetter(c);
                        letter->setColor(Color3B(255, 255, 255));
                        letter->setOpacity(255);
                        c++;
                    }
                    else {
                        if (d < label6->getStringLength())
                        {
                            log("called");

                            letter = label6->getLetter(d);
                            letter->setColor(Color3B(255, 255, 255));
                            letter->setOpacity(255);
                            d++;
                        }
                        else {
                            if (e < label7->getStringLength())
                            {
                                log("called");

                                letter = label7->getLetter(e);
                                letter->setColor(Color3B(255, 255, 255));
                                letter->setOpacity(255);
                                e++;
                            }
                            else {
                                if (f < label8->getStringLength())
                                {
                                    log("called");

                                    letter = label8->getLetter(f);
                                    letter->setColor(Color3B(255, 255, 255));
                                    letter->setOpacity(255);
                                    f++;
                                }
                                else {
                                    f = 0;
                                    unschedule(schedule_selector(ThreeGuideScene::type));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void ThreeGuideScene::createPerson() {
    auto texture = Director::getInstance()->getTextureCache()->addImage("teacher1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.25f);

    animation->addSpriteFrameWithFile("teacher1.png");
    animation->addSpriteFrameWithFile("teacher2.png");


    person = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    person->setPosition(Point(810, 230));
    this->addChild(person, 3);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);

    person->runAction(rep);
}

void ThreeGuideScene::createBack()   // "Menu" 버튼 생성
{
    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(ThreeGuideScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(840, 30));
    this->addChild(pMenu, 3);
}

void ThreeGuideScene::createNext()   // "Next Stage" 버튼 생성
{
    auto item1 = MenuItemFont::create("Stage4", CC_CALLBACK_1(ThreeGuideScene::doClose2, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(950, 30));
    this->addChild(pMenu, 3);
}

void ThreeGuideScene::createBoard()   // 칠판 생성
{
    auto texture = Director::getInstance()->getTextureCache()->addImage("Board.png");
    board = CCSprite::createWithTexture(texture, Rect(0, 0, 1280, 877));
    board->setPosition(Point(675, 250));
    this->addChild(board, 1);
}

void ThreeGuideScene::doClose(Ref* pSender)   // 메뉴화면으로 돌아가기
{
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}

void ThreeGuideScene::doClose2(Ref* pSender)   // 메뉴화면으로 돌아가기
{
    auto pScene = InfoFourScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}