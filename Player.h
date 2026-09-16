#pragma once
#include "Engine/GameObject.h"

class Player :
    public GameObject
{
public:
	Player(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
    void OnCollision(GameObject* pTarget) override;
private:
	int hModel_;//モデルのハンドル
	float coolDown_;//弾を発射するインターバル
	float speed_;//プレイヤーの移動速度
};

