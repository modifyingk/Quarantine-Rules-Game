#include "PlayScene.h"
#include "HelloWorldScene.h"

Scene* PlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = PlayScene::create();
	scene->addChild(layer);
	return scene;
}

bool PlayScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 0, 255)))
	{
		return false;
	}

	auto item1 = MenuItemFont::create("Close Scene 3", CC_CALLBACK_1(PlayScene::doClose, this));

	item1->setColor(Color3B(255, 255, 255));



	auto pMenu = Menu::create(item1, NULL);



	pMenu->setPosition(Point(240, 50));



	this->addChild(pMenu);



	return true;

}



void PlayScene::doClose(Ref* pSender)

{

	auto pScene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(pScene);

}