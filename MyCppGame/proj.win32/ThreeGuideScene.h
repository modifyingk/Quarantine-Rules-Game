#ifndef ThreeGuideScene_H
#define ThreeGuideScene_H

#include "cocos2d.h"
USING_NS_CC;

class ThreeGuideScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ThreeGuideScene);
	void createBack();
	void createBoard();
	void createPerson();
	void createNext();
	void doClose(Ref* pSender);
	void doClose2(Ref* pSender);
	cocos2d::CCSprite* board;
	cocos2d::CCSprite* person;
private:
	void type(float dt);
	Label* label;
	Label* label2;
	Label* label3;
	Label* label4;
	Label* label5;
	Label* label6;
	Label* label7;
	Label* label8;
	Sprite* letter;
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
};

#endif
