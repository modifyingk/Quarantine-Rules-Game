#include "BreadFailScene.h"
#include "PlayScene.h"
#include "StageTwoScene.h"
#include "SimpleAudioEngine.h"  // ����� ȿ���� �ʿ��� �������
using namespace CocosDenshion;  // ����� ȿ���� �ʿ��� namespace

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

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();   // ������� �Ͻ�����
    SimpleAudioEngine::getInstance()->playEffect("Fail.wav"); // ���� ȿ����

    auto item1 = MenuItemFont::create("Menu", CC_CALLBACK_1(BreadFailScene::doClose, this));    // "Menu" ��ư ���� 
    item1->setColor(Color3B(255, 255, 255));
    auto pMenu = Menu::create(item1, NULL);
    pMenu->setPosition(Point(970, 30));
    this->addChild(pMenu, 3);

    auto item2 = MenuItemFont::create("Replay", CC_CALLBACK_1(BreadFailScene::doClose2, this)); // "Replay" ��ư ����
    item2->setColor(Color3B(255, 255, 255));
    auto pMenu2 = Menu::create(item2, NULL);
    pMenu2->setPosition(Point(870, 30));
    this->addChild(pMenu2, 3);


    return true;

}

void BreadFailScene::createBackgroundParallax() // �� ���
{
    auto backGround1 = CCSprite::create("room.jpg");
    backGround1->setAnchorPoint(Point(0, 0));

    auto voidNode = CCParallaxNode::create();

    voidNode->addChild(backGround1, 1, Point(1.0f, 0.0f), Point(0, 0));
    voidNode->setTag(1);
    this->addChild(voidNode, 1);

}
void BreadFailScene::createDoor()   // �� ����
{
    auto texture1 = Director::getInstance()->getTextureCache()->addImage("door.jpg");
    door = CCSprite::createWithTexture(texture1, Rect(0, 0, 193, 400));
    door->setPosition(Point(250, 430));
    this->addChild(door, 2);
}
void BreadFailScene::createTable()  // Ź�� ����
{
    auto texture2 = Director::getInstance()->getTextureCache()->addImage("table.png");
    table = CCSprite::createWithTexture(texture2, Rect(0, 0, 300, 253));
    table->setPosition(Point(590, 250));
    this->addChild(table, 2);
}
void BreadFailScene::createSanitizer()  // �� �ҵ��� ����
{
    auto texture3 = Director::getInstance()->getTextureCache()->addImage("sanitizer.png");
    sanitizer = CCSprite::createWithTexture(texture3, Rect(0, 0, 90, 180));
    sanitizer->setPosition(Point(590, 430));
    this->addChild(sanitizer, 2);
}

void BreadFailScene::createHand()   // �� ����
{
    auto texture4 = Director::getInstance()->getTextureCache()->addImage("hand.png");
    hand = CCSprite::createWithTexture(texture4, Rect(0, 0, 145, 200));
    hand->setPosition(Point(200, 200));
    hand->setAnchorPoint(Vec2(0.5, 0.5));
    hand->setTag(TAG_SPRITE_IMAGE);
    this->addChild(hand, 3);
    //doMove(hand);
}

void BreadFailScene::createPicture()    // ���� ��� ����
{
    auto texture5 = Director::getInstance()->getTextureCache()->addImage("picture.png");
    picture = CCSprite::createWithTexture(texture5, Rect(0, 0, 167, 180));
    picture->setPosition(Point(840, 560));
    this->addChild(picture, 2);
}
void BreadFailScene::createMask()   // ����ũ ����
{
    auto texture6 = Director::getInstance()->getTextureCache()->addImage("dirtymask.png");
    dirtymask = CCSprite::createWithTexture(texture6, Rect(0, 0, 200, 112));
    dirtymask->setPosition(Point(800, 120));
    this->addChild(dirtymask, 2);
}
void BreadFailScene::createVirusMass()  // ����ũ ���̷���
{
    auto texture7 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass = CCSprite::createWithTexture(texture7, Rect(0, 0, 100, 92));
    virusmass->setPosition(Point(800, 120));
    this->addChild(virusmass, 2);
}
void BreadFailScene::createVirusMass2()  // �� ���̷���
{
    auto texture8 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    virusmass2 = CCSprite::createWithTexture(texture8, Rect(0, 0, 100, 92));
    virusmass2->setPosition(Point(215, 430));
    this->addChild(virusmass2, 2);
}
void BreadFailScene::createBread()  // �� ����
{
    auto texture9 = Director::getInstance()->getTextureCache()->addImage("bread.png");
    bread = CCSprite::createWithTexture(texture9, Rect(0, 0, 200, 144));
    bread->setPosition(Point(215, 160));
    this->addChild(bread, 2);
}
void BreadFailScene::createVir()    // �տ� ���̷��� ����
{
    auto texture10 = Director::getInstance()->getTextureCache()->addImage("virusmass.png");
    Vir = CCSprite::createWithTexture(texture10, Rect(0, 0, 100, 92));
    Vir->setPosition(Point(200, 200));
    this->addChild(Vir, 3);
}
void BreadFailScene::createGame()   // "GAME" ���� �̹��� ����
{
    auto texture11 = Director::getInstance()->getTextureCache()->addImage("game.png");
    game = CCSprite::createWithTexture(texture11, Rect(0, 0, 512, 512));
    game->setPosition(Point(520, 600));
    this->addChild(game, 3);
    //doAction8(person);
}

void BreadFailScene::createOver()   // "OVER" ���� �̹��� ����
{
    auto texture12 = Director::getInstance()->getTextureCache()->addImage("over.png");
    over = CCSprite::createWithTexture(texture12, Rect(0, 0, 512, 512));
    over->setPosition(Point(600, 600));
    this->addChild(over, 3);
    //doAction8(person);
}

void BreadFailScene::doClose(Ref* pSender)  // �޴�ȭ������ ���ư���
{
    auto pScene = PlayScene::createScene();
    Director::getInstance()->replaceScene(pScene);
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();  // ������� �ٽý���
}
void BreadFailScene::doClose2(Ref* pSender)   // ���� �ٽ� ����
{
    auto pScene = StageTwoScene::createScene();
    Director::getInstance()->replaceScene(pScene);
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();  // ������� �ٽý���
}