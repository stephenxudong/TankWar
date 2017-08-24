#include "GameScene.h"
#include "TankController.h"
#include "TankCanon.h"
#include "MoveController.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Joystick.h"
GameScene::GameScene()
{
	m_nLevel = 1;
}


GameScene::~GameScene()
{
}

Scene * GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	loadConfig();
	loadController();

	return true;
}

void GameScene::loadConfig()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
		StringUtils::format("music/bgmusic_level%d", m_nLevel).c_str(), true);

	auto MapScene = TMXTiledMap::create(
		StringUtils::format("GameWar_Level%d.tmx", m_nLevel).c_str());

	addChild(MapScene,1);

	m_tankCtr = TankController::creatTankCtrWithLevel(m_nLevel, MapScene);

	addChild(m_tankCtr, 3);
}

void GameScene::loadController()
{
	m_moveCtr = MoveController::createWithTank(m_tankCtr->m_Tank);
	addChild(m_moveCtr);

	auto joystick1= Joystick::create();
	joystick1->bindMoveCtr(m_moveCtr);
	addChild(joystick1,10,999);
	
	auto _listener = EventListenerCustom::create(JoystickEvent::EVENT_JOYSTICK, [=](EventCustom* event) {
		JoystickEvent* jsevent = static_cast<JoystickEvent*>(event->getUserData());	
		double angle = jsevent->mAnagle;

		switch ((int)(angle/30))
		{
		case 0:
			m_moveCtr->setSpeedX(m_tankCtr->m_Tank->getnSpeed());
			m_moveCtr->setSpeedY(0);
			m_tankCtr->m_Tank->setRotation(90);
			break;

		case 1:
			m_moveCtr->setSpeedX(m_tankCtr->m_Tank->getnSpeed()/1.4);
			m_moveCtr->setSpeedY(m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_tankCtr->m_Tank->setRotation(45);
			break;
		case 2:
		case 3:
			m_moveCtr->setSpeedX(0);
			m_moveCtr->setSpeedY(m_tankCtr->m_Tank->getnSpeed());
			m_tankCtr->m_Tank->setRotation(0);
			break;
	
		case 4:
			m_moveCtr->setSpeedX(-m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_moveCtr->setSpeedY(m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_tankCtr->m_Tank->setRotation(-45);
			break;
		case -1:
			m_moveCtr->setSpeedX(m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_moveCtr->setSpeedY(-m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_tankCtr->m_Tank->setRotation(135);
			break;
		case-2:
		case-3:
			m_moveCtr->setSpeedX(0);
			m_moveCtr->setSpeedY(-m_tankCtr->m_Tank->getnSpeed());
			m_tankCtr->m_Tank->setRotation(180);
			break;
		case -4:
			m_moveCtr->setSpeedX(-m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_moveCtr->setSpeedY(-m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_tankCtr->m_Tank->setRotation(225);
			break;
		case 5:
		case -5:
			m_moveCtr->setSpeedX(-m_tankCtr->m_Tank->getnSpeed() / 1.4);
			m_moveCtr->setSpeedY(0);
			m_tankCtr->m_Tank->setRotation(270);
			break;
		}
	});
	_eventDispatcher->addEventListenerWithFixedPriority(_listener, 1);

	auto joystick2 = CanonJoystick::create();
	addChild(joystick2, 10, 999);
	auto _listener2 = EventListenerCustom::create(CanonjoystickEvent::EVENT_JOYSTICK, [=](EventCustom* event) {
		CanonjoystickEvent* jsevent = static_cast<CanonjoystickEvent*>(event->getUserData());
		double angle = jsevent->mAnagle;
		m_tankCtr->m_Tank->m_Tankcanon->setRotation(90 - angle);

	});
	_eventDispatcher->addEventListenerWithFixedPriority(_listener2, 1);

}