#pragma execution_character_set("utf-8")
#include "TwoGuideScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "StageTwoScene.h"
#include "InfoThreeScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace
#define N 1000
USING_NS_CC;

#define IMG_WIDTH 1024

Scene* TwoGuideScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TwoGuideScene::create();
    scene->addChild(layer);
    return scene;
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool TwoGuideScene::init()
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

    label = Label::createWithTTF("사람을", "fonts/DOSSaemmul.ttf", 30);
    label2 = Label::createWithTTF("만나러", "fonts/DOSSaemmul.ttf", 30);
    label3 = Label::createWithTTF("갈", "fonts/DOSSaemmul.ttf", 30);
    label4 = Label::createWithTTF("때는", "fonts/DOSSaemmul.ttf", 30);
    label5 = Label::createWithTTF("친한", "fonts/DOSSaemmul.ttf", 30);
    label6 = Label::createWithTTF("친구여도", "fonts/DOSSaemmul.ttf", 30);

    label7 = Label::createWithTTF("마스크를", "fonts/DOSSaemmul.ttf", 30);
    label8 = Label::createWithTTF("꼭", "fonts/DOSSaemmul.ttf", 30);
    label9 = Label::createWithTTF("써야해요!", "fonts/DOSSaemmul.ttf", 30);

    label10 = Label::createWithTTF("또,", "fonts/DOSSaemmul.ttf", 30);
    label11 = Label::createWithTTF("마스크를", "fonts/DOSSaemmul.ttf", 30);
    label12 = Label::createWithTTF("쓸", "fonts/DOSSaemmul.ttf", 30);
    label13 = Label::createWithTTF("때나", "fonts/DOSSaemmul.ttf", 30);
    label14 = Label::createWithTTF("음식을", "fonts/DOSSaemmul.ttf", 30);
    label15 = Label::createWithTTF("만질", "fonts/DOSSaemmul.ttf", 30);
    label16 = Label::createWithTTF("때는", "fonts/DOSSaemmul.ttf", 30);
    label17 = Label::createWithTTF("꼭", "fonts/DOSSaemmul.ttf", 30);
    label18 = Label::createWithTTF("손을", "fonts/DOSSaemmul.ttf", 30);
    label19 = Label::createWithTTF("씻어야해요!", "fonts/DOSSaemmul.ttf", 30);


    label->setPosition(Point(200, 520));
    label2->setPosition(Point(300, 520));
    label3->setPosition(Point(380, 520));
    label4->setPosition(Point(440, 520));
    label5->setPosition(Point(520, 520));
    label6->setPosition(Point(630, 520));

    label7->setPosition(Point(330, 450));
    label8->setPosition(Point(420, 450));
    label9->setPosition(Point(520, 450));

    label10->setPosition(Point(170, 340));
    label11->setPosition(Point(260, 340));
    label12->setPosition(Point(350, 340));
    label13->setPosition(Point(400, 340));
    label14->setPosition(Point(500, 340));
    label15->setPosition(Point(600, 340));
    label16->setPosition(Point(660, 340));

    label17->setPosition(Point(290,270));
    label18->setPosition(Point(350, 270));
    label19->setPosition(Point(470, 270));

    label->setOpacity(0);
    label2->setOpacity(0);
    label3->setOpacity(0);
    label4->setOpacity(0);
    label5->setOpacity(0);
    label6->setOpacity(0);
    label7->setOpacity(0);
    label8->setOpacity(0);
    label9->setOpacity(0);
    label10->setOpacity(0);
    label11->setOpacity(0);
    label12->setOpacity(0);
    label13->setOpacity(0);
    label14->setOpacity(0);

    label15->setOpacity(0);
    label16->setOpacity(0);
    label17->setOpacity(0);
    label18->setOpacity(0);
    label19->setOpacity(0);

    this->addChild(label,3);
    this->addChild(label2,3);
    this->addChild(label3,3);
    this->addChild(label4,3);
    this->addChild(label5,3);
    this->addChild(label6,3);
    this->addChild(label7,3);
    this->addChild(label8,3);
    this->addChild(label9,3);
    this->addChild(label10,3);
    this->addChild(label11,3);
    this->addChild(label12,3);
    this->addChild(label13,3);
    this->addChild(label14,3);

    this->addChild(label15,3);
    this->addChild(label16,3);
    this->addChild(label17,3);
    this->addChild(label18,3);
    this->addChild(label19,3);

    this->schedule(schedule_selector(TwoGuideScene::type), 0.04f);

    return true;
}
void TwoGuideScene::type(float dt)
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
                                    if (g < label9->getStringLength())
                                    {
                                        log("called");

                                        letter = label9->getLetter(g);
                                        letter->setColor(Color3B(255, 255, 255));
                                        letter->setOpacity(255);
                                        g++;
                                    }
                                    else {
                                        if (h < label10->getStringLength())
                                        {
                                            log("called");

                                            letter = label10->getLetter(h);
                                            letter->setColor(Color3B(255, 255, 255));
                                            letter->setOpacity(255);
                                            h++;
                                        }
                                        else {
                                            if (k < label11->getStringLength())
                                            {
                                                log("called");

                                                letter = label11->getLetter(k);
                                                letter->setColor(Color3B(255, 255, 255));
                                                letter->setOpacity(255);
                                                k++;
                                            }
                                            else {
                                                if (l < label12->getStringLength())
                                                {
                                                    log("called");

                                                    letter = label12->getLetter(l);
                                                    letter->setColor(Color3B(255, 255, 255));
                                                    letter->setOpacity(255);
                                                    l++;
                                                }
                                                else {
                                                    if (m < label13->getStringLength())
                                                    {
                                                        log("called");

                                                        letter = label13->getLetter(m);
                                                        letter->setColor(Color3B(255, 255, 255));
                                                        letter->setOpacity(255);
                                                        m++;
                                                    }
                                                    else {
                                                        if (n < label14->getStringLength())
                                                        {
                                                            log("called");

                                                            letter = label14->getLetter(n);
                                                            letter->setColor(Color3B(255, 255, 255));
                                                            letter->setOpacity(255);
                                                            n++;
                                                        }
                                                        else {
                                                            if (o < label15->getStringLength())
                                                            {
                                                                log("called");

                                                                letter = label15->getLetter(o);
                                                                letter->setColor(Color3B(255, 255, 255));
                                                                letter->setOpacity(255);
                                                                o++;
                                                            }
                                                            else {
                                                                if (p < label16->getStringLength())
                                                                {
                                                                    log("called");

                                                                    letter = label16->getLetter(p);
                                                                    letter->setColor(Color3B(255, 255, 255));
                                                                    letter->setOpacity(255);
                                                                    p++;
                                                                }
                                                                else {
                                                                    if (q < label17->getStringLength())
                                                                    {
                                                                        log("called");

                                                                        letter = label17->getLetter(q);
                                                                        letter->setColor(Color3B(255, 255, 255));
                                                                        letter->setOpacity(255);
                                                                        q++;
                                                                    }
                                                                    else {
                                                                        if (r < label18->getStringLength())
                                                                        {
                                                                            log("called");

                                                                            letter = label18->getLetter(r);
                                                                            letter->setColor(Color3B(255, 255, 255));
                                                                            letter->setOpacity(255);
                                                                            r++;
                                                                        }
                                                                        else {
                                                                            if (s < label19->getStringLength())
                                                                            {
                                                                                log("called");

                                                                                letter = label19->getLetter(s);
                                                                                letter->setColor(Color3B(255, 255, 255));
                                                                                letter->setOpacity(255);
                                                                                s++;
                                                                            }
                                                                            else {
                                                                                s = 0;
                                                                                unschedule(schedule_selector(TwoGuideScene::type));
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void TwoGuideScene::createPerson() {
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

void TwoGuideScene::createBack()   // "Menu" 버튼 생성
{
    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(TwoGuideScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(840, 30));
    this->addChild(pMenu, 3);
}

void TwoGuideScene::createNext()   // "Next Stage" 버튼 생성
{
    auto item1 = MenuItemFont::create("Stage3", CC_CALLBACK_1(TwoGuideScene::doClose2, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(950, 30));
    this->addChild(pMenu, 3);
}

void TwoGuideScene::createBoard()   // 칠판 생성
{
    auto texture = Director::getInstance()->getTextureCache()->addImage("Board.png");
    board = CCSprite::createWithTexture(texture, Rect(0, 0, 1280, 877));
    board->setPosition(Point(675, 250));
    this->addChild(board, 1);
}

void TwoGuideScene::doClose(Ref* pSender)   // 메뉴화면으로 돌아가기
{
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}

void TwoGuideScene::doClose2(Ref* pSender)   // 메뉴화면으로 돌아가기
{
    auto pScene = InfoThreeScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}