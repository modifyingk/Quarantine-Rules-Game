#include "BreadFailScene.h"
#include "PlayScene.h"
#include "StageTwoScene.h"
#include "SimpleAudioEngine.h"  // 오디오 효과에 필요한 헤더파일
using namespace CocosDenshion;  // 오디오 효과에 필요한 namespace

Scene* BreadFailScene::createScene()
{
    auto scene = Scene::create();
    auto layer = BreadFailScene::create();
    scene->addChild(layer);
    return scene;
}

bool BreadFailScene::init()
{
    this->createBackgroundParallax();
    this->createDoor();
    this->createTable();
    this->createSanitizer();
    this->createHand();
    this->createPicture();
    this->createMask();
    this->createVirusMass2();
    this->createVir();
    this->createBread();
    this->createGame();
    this->createOver();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();   // 배경음악 일시정지
    SimpleAudioEngine::getInstance()->playEffect("Fail.wav"); // 실패 효과음

    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(BreadFailScene::doClose, this));    // "Menu" 버튼 구현 
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);

    auto item2 = MenuItemFont::create("Replay", CC_CALLBACK_1(BreadFailScene::doClose2, this)); // "Replay" 버튼 구현
    item2->setColor(Color3B(255, 255, 255));
    auto pMenu2 = Menu::create(item2, NULL);
    pMenu2->setPosition(Point(870, 30));
    this->addChild(pMenu2, 3);


    return true;

}

void BreadFailScene::createBackgroundParallax() // 방 배경
{
    auto backGround1 = CCSprite::create("room.jpg");
    backGround1->setAnchorPoint(Point(0, 0));

    auto voidNode = CCParallaxNode::create();

    voidNode->addChild(backGround1, 1, Point(1.0f, 0.0f), Point(0, 0));
    voidNode->setTag(1);
    this->addChild(voidNode, 1);

}
void BreadFailScene::createDoor()   // 문 생성
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("door.jpg");
    door = CCSprite::createWithTexture(texture1, Rect(0, 0, 193, 400));
    door->setPosition(Point(250, 430));
    this->addChild(door, 2);
}
void BreadFailScene::createTable()  // 탁자 생성
{
    auto texture2 = Director::getInstance()->getTextureCache()->addImage("table.png");
    table = CCSprite::createWithTexture(texture2, Rect(0, 0, 300, 253));
    table->setPosition(Point(590, 250));
    this->addChild(table, 2);
}
void BreadFailScene::createSanitizer()  // 손 소독제 생성
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("sanitizer.png");
    sanitizer = CCSprite::createWithTexture(texture3, Rect(0, 0, 90, 180));
    sanitizer->setPosition(Point(590, 430));
    this->addChild(sanitizer, 2);
}

void BreadFailScene::createHand()   // 손 생성
{
    auto texture4 = Director::getInstance()->getTextureCache()->addImage("hand.png");
    hand = CCSprite::createWithTexture(texture4, Rect(0, 0, 145, 200));
    hand->setPosition(Point(200, 200));
    hand->setAnchorPoint(Vec2(0.5, 0.5));
    hand->setTag(TAG_SPRITE_IMAGE);
    this->addChild(hand, 3);
    //doMove(hand);
}

void BreadFailScene::createPicture()    // 액자 장식 생성
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("picture.png");
    picture = CCSprite::createWithTexture(texture5, Rect(0, 0, 167, 180));
    picture->setPosition(Point(840, 560));
    this->addChild(picture, 2);
}
void BreadFailScene::createMask()   // 마스크 생성
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("dirtymask.png");
    dirtymask = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 112));
    dirtymask->setPosition(Point(800, 120));
    this->addChild(dirtymask, 2);
}
void BreadFailScene::createVirusMass()  // 마스크 바이러스
{
    auto texture7 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass = CCSprite::createWithTexture(texture7, Rect(0, 0, 100, 92));
    virusmass->setPosition(Point(800, 120));
    this->addChild(virusmass, 2);
}
void BreadFailScene::createVirusMass2()  // 문 바이러스
{
    auto texture8 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass2 = CCSprite::createWithTexture(texture8, Rect(0, 0, 100, 92));
    virusmass2->setPosition(Point(215, 430));
    this->addChild(virusmass2, 2);
}
void BreadFailScene::createBread()  // 빵 생성
{
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("bread.png");
    bread = CCSprite::createWithTexture(texture9, Rect(0, 0, 200, 144));
    bread->setPosition(Point(215, 160));
    this->addChild(bread, 2);
}
void BreadFailScene::createVir()    // 손에 바이러스 생성
{
    auto texture10 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    Vir = CCSprite::createWithTexture(texture10, Rect(0, 0, 100, 92));
    Vir->setPosition(Point(200, 200));
    this->addChild(Vir, 3);
}
void BreadFailScene::createGame()   // "GAME" 글자 이미지 생성
{
    auto texture11 = Director::getInstance()->getTextureCache()->addImage("game.png");
    game = CCSprite::createWithTexture(texture11, Rect(0, 0, 512, 512));
    game->setPosition(Point(520, 600));
    this->addChild(game, 3);
    //doAction8(person);
}

void BreadFailScene::createOver()   // "OVER" 글자 이미지 생성
{
    auto texture12 = Director::getInstance()->getTextureCache()->addImage("over.png");
    over = CCSprite::createWithTexture(texture12, Rect(0, 0, 512, 512));
    over->setPosition(Point(600, 600));
    this->addChild(over, 3);
    //doAction8(person);
}

void BreadFailScene::doClose(Ref* pSender)  // 메뉴화면으로 돌아가기
{
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();  // 배경음악 다시시작
}
void BreadFailScene::doClose2(Ref* pSender)   // 게임 다시 시작
{
    auto pScene = StageTwoScene::createScene();
    Director::getInstance()->replaceScene(pScene);
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();  // 배경음악 다시시작
}