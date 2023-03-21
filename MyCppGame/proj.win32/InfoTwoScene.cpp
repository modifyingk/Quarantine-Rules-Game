#pragma execution_character_set("utf-8")
#include "InfoTwoScene.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "StageTwoScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace
#define N 1000
USING_NS_CC;

#define IMG_WIDTH 1024

Scene* InfoTwoScene::createScene()
{
    auto scene = Scene::create();
    auto layer = InfoTwoScene::create();
    scene->addChild(layer);
    return scene;
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool InfoTwoScene::init()
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

    label = Label::createWithTTF("밖에", "fonts/DOSSaemmul.ttf", 30);
    label2 = Label::createWithTTF("있는", "fonts/DOSSaemmul.ttf", 30);
    label3 = Label::createWithTTF("친구에게", "fonts/DOSSaemmul.ttf", 30);
    label4 = Label::createWithTTF("빵을", "fonts/DOSSaemmul.ttf", 30);
    label5 = Label::createWithTTF("주려고", "fonts/DOSSaemmul.ttf", 30);
    label6 = Label::createWithTTF("합니다", "fonts/DOSSaemmul.ttf", 30);

    label7 = Label::createWithTTF("방", "fonts/DOSSaemmul.ttf", 30);
    label8 = Label::createWithTTF("안에서", "fonts/DOSSaemmul.ttf", 30);
    label9 = Label::createWithTTF("친구에게", "fonts/DOSSaemmul.ttf", 30);
    label10 = Label::createWithTTF("빵을", "fonts/DOSSaemmul.ttf", 30);
    label11 = Label::createWithTTF("가져다", "fonts/DOSSaemmul.ttf", 30);
    label12 = Label::createWithTTF("줄", "fonts/DOSSaemmul.ttf", 30);
    label13 = Label::createWithTTF("준비를", "fonts/DOSSaemmul.ttf", 30);
    label14 = Label::createWithTTF("완료하세요", "fonts/DOSSaemmul.ttf", 30);

    label15 = Label::createWithTTF("P.S.", "fonts/DOSSaemmul.ttf", 30);
    label16 = Label::createWithTTF("문고리를", "fonts/DOSSaemmul.ttf", 30);
    label17 = Label::createWithTTF("클릭하면", "fonts/DOSSaemmul.ttf", 30);
    label18 = Label::createWithTTF("빵이", "fonts/DOSSaemmul.ttf", 30);
    label19 = Label::createWithTTF("나타납니다", "fonts/DOSSaemmul.ttf", 30);


    label->setPosition(Point(250, 245));
    label2->setPosition(Point(330, 245));
    label3->setPosition(Point(430, 245));
    label4->setPosition(Point(540, 245));
    label5->setPosition(Point(630, 245));
    label6->setPosition(Point(735, 245));

    label7->setPosition(Point(135, 175));  
    label8->setPosition(Point(210, 175)); 
    label9->setPosition(Point(330, 175));  
    label10->setPosition(Point(435, 175)); 
    label11->setPosition(Point(520, 175)); 
    label12->setPosition(Point(600, 175));
    label13->setPosition(Point(675, 175)); 
    label14->setPosition(Point(810, 175));

    label15->setPosition(Point(255, 105));
    label16->setPosition(Point(355, 105));
    label17->setPosition(Point(485, 105));
    label18->setPosition(Point(595, 105));
    label19->setPosition(Point(715, 105));

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

    this->addChild(label);
    this->addChild(label2);
    this->addChild(label3);
    this->addChild(label4);
    this->addChild(label5);
    this->addChild(label6);
    this->addChild(label7);
    this->addChild(label8);
    this->addChild(label9);
    this->addChild(label10);
    this->addChild(label11);
    this->addChild(label12);
    this->addChild(label13);
    this->addChild(label14);

    this->addChild(label15);
    this->addChild(label16);
    this->addChild(label17);
    this->addChild(label18);
    this->addChild(label19);

    this->schedule(schedule_selector(InfoTwoScene::type), 0.04f);

    return true;
}
void InfoTwoScene::type(float dt)
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
                if (b < label4->getStringLength())
                {
                    log("called");

                    letter = label4->getLetter(b);
                    letter->setColor(Color3B(0, 0, 0));
                    letter->setOpacity(255);
                    b++;
                }
                else {
                    if (c < label5->getStringLength())
                    {
                        log("called");

                        letter = label5->getLetter(c);
                        letter->setColor(Color3B(0, 0, 0));
                        letter->setOpacity(255);
                        c++;
                    }
                    else {
                        if (d < label6->getStringLength())
                        {
                            log("called");

                            letter = label6->getLetter(d);
                            letter->setColor(Color3B(0, 0, 0));
                            letter->setOpacity(255);
                            d++;
                        }
                        else {
                            if (e < label7->getStringLength())
                            {
                                log("called");

                                letter = label7->getLetter(e);
                                letter->setColor(Color3B(0, 0, 0));
                                letter->setOpacity(255);
                                e++;
                            }
                            else {
                                if (f < label8->getStringLength())
                                {
                                    log("called");

                                    letter = label8->getLetter(f);
                                    letter->setColor(Color3B(0, 0, 0));
                                    letter->setOpacity(255);
                                    f++;
                                }
                                else {
                                    if (g < label9->getStringLength())
                                    {
                                        log("called");

                                        letter = label9->getLetter(g);
                                        letter->setColor(Color3B(0, 0, 0));
                                        letter->setOpacity(255);
                                        g++;
                                    }
                                    else {
                                        if (h < label10->getStringLength())
                                        {
                                            log("called");

                                            letter = label10->getLetter(h);
                                            letter->setColor(Color3B(0, 0, 0));
                                            letter->setOpacity(255);
                                            h++;
                                        }
                                        else {
                                            if (k < label11->getStringLength())
                                            {
                                                log("called");

                                                letter = label11->getLetter(k);
                                                letter->setColor(Color3B(0, 0, 0));
                                                letter->setOpacity(255);
                                                k++;
                                            }
                                            else {
                                                if (l < label12->getStringLength())
                                                {
                                                    log("called");

                                                    letter = label12->getLetter(l);
                                                    letter->setColor(Color3B(0, 0, 0));
                                                    letter->setOpacity(255);
                                                    l++;
                                                }
                                                else {
                                                    if (m < label13->getStringLength())
                                                    {
                                                        log("called");

                                                        letter = label13->getLetter(m);
                                                        letter->setColor(Color3B(0, 0, 0));
                                                        letter->setOpacity(255);
                                                        m++;
                                                    }
                                                    else {
                                                        if (n < label14->getStringLength())
                                                        {
                                                            log("called");

                                                            letter = label14->getLetter(n);
                                                            letter->setColor(Color3B(0, 0, 0));
                                                            letter->setOpacity(255);
                                                            n++;
                                                        }
                                                        else {
                                                            if (o < label15->getStringLength())
                                                            {
                                                                log("called");

                                                                letter = label15->getLetter(o);
                                                                letter->setColor(Color3B(0, 0, 0));
                                                                letter->setOpacity(255);
                                                                o++;
                                                            }
                                                            else {
                                                                if (p < label16->getStringLength())
                                                                {
                                                                    log("called");

                                                                    letter = label16->getLetter(p);
                                                                    letter->setColor(Color3B(0, 0, 0));
                                                                    letter->setOpacity(255);
                                                                    p++;
                                                                }
                                                                else {
                                                                    if (q < label17->getStringLength())
                                                                    {
                                                                        log("called");

                                                                        letter = label17->getLetter(q);
                                                                        letter->setColor(Color3B(0, 0, 0));
                                                                        letter->setOpacity(255);
                                                                        q++;
                                                                    }
                                                                    else {
                                                                        if (r < label18->getStringLength())
                                                                        {
                                                                            log("called");

                                                                            letter = label18->getLetter(r);
                                                                            letter->setColor(Color3B(0, 0, 0));
                                                                            letter->setOpacity(255);
                                                                            r++;
                                                                        }
                                                                        else {
                                                                            if (s < label19->getStringLength())
                                                                            {
                                                                                log("called");

                                                                                letter = label19->getLetter(s);
                                                                                letter->setColor(Color3B(0, 0, 0));
                                                                                letter->setOpacity(255);
                                                                                s++;
                                                                            }
                                                                            else {
                                                                                s = 0;
                                                                                unschedule(schedule_selector(InfoTwoScene::type));
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

void InfoTwoScene::createBack()   // "Menu" 버튼 생성
{
    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(InfoTwoScene::doClose, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(870, 30));
    this->addChild(pMenu, 3);
}
void InfoTwoScene::createNext()   // "Start" 버튼 생성
{
    auto item1 = MenuItemFont::create("Start", CC_CALLBACK_1(InfoTwoScene::doClose2, this));
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);
}
void InfoTwoScene::createStage() {      // Stage2 이미지 삽입
    auto texture = Director::getInstance()->getTextureCache()->addImage("stage2_off.png");
    stage = CCSprite::createWithTexture(texture, Rect(0, 0, 256, 256));
    stage->setPosition(Point(500, 650));
    this->addChild(stage, 3);
}

void InfoTwoScene::createPerson() {     // 파란옷 사람 이미지 삽입
    auto texture = Director::getInstance()->getTextureCache()->addImage("blueperson1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.25f);

    animation->addSpriteFrameWithFile("blueperson1.png");
    animation->addSpriteFrameWithFile("blueperson2.png");
    animation->addSpriteFrameWithFile("blueperson3.png");

    person = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    person->setPosition(Point(200, 440));
    this->addChild(person);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);
    person->runAction(rep);
}
void InfoTwoScene::createPerson2() {     // 초록옷 사람 이미지 삽입
    auto texture = Director::getInstance()->getTextureCache()->addImage("greenperson1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.25f);

    animation->addSpriteFrameWithFile("greenperson1.png");
    animation->addSpriteFrameWithFile("greenperson2.png");
    animation->addSpriteFrameWithFile("greenperson3.png");

    person2 = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    person2->setPosition(Point(500, 440));
    this->addChild(person2);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);
    person2->runAction(rep);
}
void InfoTwoScene::createPerson3() {     // 핑크옷 사람 이미지 삽입
    auto texture = Director::getInstance()->getTextureCache()->addImage("pinkperson1.png");
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.25f);

    animation->addSpriteFrameWithFile("pinkperson1.png");
    animation->addSpriteFrameWithFile("pinkperson2.png");
    animation->addSpriteFrameWithFile("pinkperson3.png");

    person3 = Sprite::createWithTexture(texture, Rect(0, 0, 100, 300));
    person3->setPosition(Point(800, 440));
    this->addChild(person3);

    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);
    person3->runAction(rep);
}

void InfoTwoScene::doClose(Ref* pSender)   // 메뉴화면으로 돌아가기
{
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}
void InfoTwoScene::doClose2(Ref* pSender)   // 다음 화면으로
{
    auto pScene = StageTwoScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}