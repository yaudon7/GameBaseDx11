#pragma once
#include "Engine/GameObject.h"

class Enemy :
    public GameObject
{
public:
	Enemy(GameObject* parent);
	Enemy() {};
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
private:
	int hModel_;//モデルのハンドル
	float enemyShootCoolDown_;//敵の攻撃間隔
};

