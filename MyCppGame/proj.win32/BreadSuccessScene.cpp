#include "BreadSuccessScene.h"
#include "PlayScene.h"
#include "TwoGuideScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace

Scene* BreadSuccessScene::createScene()
{
    auto scene = Scene::create();
    auto layer = BreadSuccessScene::create();
    scene->addChild(layer);
    return scene;
}

bool BreadSuccessScene::init()
{
    SimpleAudioEngine::getInstance()->playEffect("Clear.wav"); // 성공 효과음
    this->createBackgroundParallax();
    this->createDoor();
    this->createTable();
    this->createSanitizer();
    this->createHand();
    this->createPicture();
    this->createVirusMass2();
    this->createBread();
    this->createClear();

    auto item1 = MenuItemFont::create("Next", CC_CALLBACK_1(BreadSuccessScene::doClose, this)); // "Next" 버튼 구현
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);



    return true;

}

void BreadSuccessScene::createBackgroundParallax()  // 방 배경
{
    auto backGround1 = CCSprite::create("room.jpg");
    backGround1->setAnchorPoint(Point(0, 0));

    auto voidNode = CCParallaxNode::create();

    voidNode->addChild(backGround1, 1, Point(1.0f, 0.0f), Point(0, 0));

    voidNode->setTag(1);
    this->addChild(voidNode, 1);

}
void BreadSuccessScene::createDoor()    // 문 생성
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("door.jpg");
    door = CCSprite::createWithTexture(texture1, Rect(0, 0, 193, 400));
    door->setPosition(Point(250, 430));
    this->addChild(door, 2);
}
void BreadSuccessScene::createTable()   // 탁자 생성
{
    auto texture2 = Director::getInstance()->getTextureCache()->addImage("table.png");
    table = CCSprite::createWithTexture(texture2, Rect(0, 0, 300, 253));
    table->setPosition(Point(590, 250));
    this->addChild(table, 2);
}
void BreadSuccessScene::createSanitizer()   // 손 소독제 생성
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("sanitizer.png");
    sanitizer = CCSprite::createWithTexture(texture3, Rect(0, 0, 90, 180));
    sanitizer->setPosition(Point(590, 430));
    this->addChild(sanitizer, 2);
}
void BreadSuccessScene::createHand()    // 손 생성
{
    auto texture4 = Director::getInstance()->getTextureCache()->addImage("hand.png");
    hand = CCSprite::createWithTexture(texture4, Rect(0, 0, 145, 200));
    hand->setPosition(Point(200, 200));
    hand->setAnchorPoint(Vec2(0.5, 0.5));
    hand->setTag(TAG_SPRITE_IMAGE);
    this->addChild(hand, 3);
}
void BreadSuccessScene::createPicture() // 액자 장식 생성
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("picture.png");
    picture = CCSprite::createWithTexture(texture5, Rect(0, 0, 167, 180));
    picture->setPosition(Point(840, 560));
    this->addChild(picture, 2);
}
void BreadSuccessScene::createMask()    // 마스크 생성
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("dirtymask.png");
    dirtymask = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 112));
    dirtymask->setPosition(Point(800, 120));
    this->addChild(dirtymask, 2);
}
void BreadSuccessScene::createVirusMass()  // 마스크 바이러스 생성
{
    auto texture7 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass = CCSprite::createWithTexture(texture7, Rect(0, 0, 100, 92));
    virusmass->setPosition(Point(800, 120));
    this->addChild(virusmass, 2);
}
void BreadSuccessScene::createVirusMass2()  // 문 바이러스 생성
{
    auto texture8 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass2 = CCSprite::createWithTexture(texture8, Rect(0, 0, 100, 92));
    virusmass2->setPosition(Point(215, 430));
    this->addChild(virusmass2, 2);
}
void BreadSuccessScene::createBread()   // 빵 생성
{
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("bread.png");
    bread = CCSprite::createWithTexture(texture9, Rect(0, 0, 200, 144));
    bread->setPosition(Point(215, 160));
    this->addChild(bread, 2);
}
void BreadSuccessScene::createClear()   // "CLEAR" 글자 이미지 생성
{
    auto texture10 = Director::getInstance()->getTextureCache()->addImage("clear.png");
    success = CCSprite::createWithTexture(texture10, Rect(0, 0, 512, 512));
    success->setPosition(Point(530, 500));
    this->addChild(success, 3);
}

void BreadSuccessScene::doClose(Ref* pSender)   // 메뉴화면으로 돌아가기

{
    auto pScene = TwoGuideScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}