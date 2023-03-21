#ifndef StageFourScene_H
#define StageFourScene_H

#include "cocos2d.h"
USING_NS_CC;

class StageFourScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StageFourScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doPushQuiz_o(Ref* pSender);
	void doPushQuiz_x(Ref* pSender);
};

#endif
