#pragma once
#include "cocos2d.h"
#include "Tank.h"
USING_NS_CC;
enum BulletType
{
	 SIMPLE, //һ���ӵ�
	 STRENGTHENED, //��ǿ�ӵ�
};
class Bullet :
	public cocos2d::Sprite
{
public:
	CC_SYNTHESIZE(int, _distance, distance); 
	CC_SYNTHESIZE(float, _attackValue, attackValue);
	static Bullet* create(Tank* owner, float distance, int attackValue,Vec2 pos, BulletType bulletType); //�����ӵ�ָ�룬ȷ���������ߣ��������룬�˺�ֵ���ӵ�����
	void move(Point destPos); //�ӵ��ƶ��Ķ���
	Vec2 setDirection(Point curPos);  //�ӵ��ƶ��ķ���  ���һ����
	bool Bullet::init(Tank* owner, float distance, int attackValue,Vec2 pos, BulletType bulletType ); //��ʼ���ӵ�
	
private:
	
	Tank* _owner;//�ӵ�������̹������
	Vec2 _pos;
	bool _isReachBorder; //�ӵ��Ƿ񵽴�߽�
	bool _isReachObstacle; //�ӵ��Ƿ������ϰ���
	bool _isCollideTank; //�ӵ��Ƿ�����̹��
	bool _isBomb; //�Ƿ�ը
	Vec2 _nextPos;//��һ֡��λ��
	Vec2 _bombPos;//�ӵ���ըλ��

private:
	void collideTank();//�ж��ӵ��Ƿ��̹������ײ
	void reachBorder();//�ж��ӵ��Ƿ񵽴�߽�
	void reachObstacle();//�ж��ӵ��Ƿ�ͽ���������
	void valid(); //�ж��ӵ��Ƿ���Ч
	
};

