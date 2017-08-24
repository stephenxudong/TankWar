#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "TankControl.h"
#include "BulletControl.h"
static int  GAME_SCENE_HEIGHT = 50;
static int  GAME_SCENE_WIDTH = 40;

using namespace CocosDenshion;
USING_NS_CC;
class GameScene :
	public cocos2d::Layer
{
private:
	int _count; //֡��������
	int _screenHeight, _screenWidth; //��Ļ�ĸ߶ȺͿ��
	int _score; //�÷�
	static TankControl* _tankControler;
	static BulletControl* _bulletControler;
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	virtual void onEnter();
	void update();
	void updateScore(int delta);
	static TankControl* getTankControler() { return _tankControler; };
	static BulletControl* getBulletControler() { return _bulletControler; };
};

	
