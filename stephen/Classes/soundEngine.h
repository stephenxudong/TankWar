#pragma once
#include "SimpleAudioEngine.h"
#include "gvarible.h"

#define STARTBGM "music/STARTBGM.mp3"
#define SELECTBGM "music/backMusic.mp3"
#define BATTELBGM "music/battlebgm1.mp3"
#define SETTINGBGM "music/STARTBGM.mp3"

#define E_Add_Life ""
#define E_Bullet ""
#define E_Enemy_Bomb ""
#define E_Hit_Obstacle ""
#define E_Metal ""
#define E_Obstacle_Bomb ""
#define E_Player_Bomb ""
#define E_Slip ""
#define E_ClickOn "music/E_Clickon.mp3"
#define E_MoveBack "music/E_MoveBack.mp3"
#define E_GG ""

using namespace CocosDenshion;

class soundEngine
{

public:

	static void PreLoadBGM(); //Ԥ���ر�������
	static void KindsOfBgm(char * pFilename, double percentage); //�������֣����ż�ȷ����������
	static void SetBGVolume(int percentage); //�������֣����ò�������
	static void PauseBGMusic(); //��ͣ��������
	static void ResumeBGMusic(); //�ָ���������
	static void StopBGMusic(char * pFilename);  //ֹͣ��������

	static void PreLoadSE(); //Ԥ������Ч
	static void KindsOfSE(char * pFilename, double percentage); //��Ч�����ż�ȷ����Ч����
	static void SetSEVolume(int percentage); //��Ч�����ò�������
	static void PauseSE(); //��ͣȫ����Ч
	static void ResumeSE(); //�ָ�ȫ����Ч
	static void StopSEMusic();  //ֹͣȫ����Ч

	friend class HelloWorld;
	friend class settingScene;
};
