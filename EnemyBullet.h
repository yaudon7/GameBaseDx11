#pragma once
#include "Engine/GameObject.h"
class EnemyBullet :
    public GameObject
{
public:
	EnemyBullet(GameObject* parent);
	~EnemyBullet() {};
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void SetVelocity(float x, float y, float z) { velocity_ = { x,y,z }; }
private:
	float speed_;//弾の速さ
	int hModel_;//モデルのハンドル
	XMFLOAT3 velocity_;//弾の移動方向
};

