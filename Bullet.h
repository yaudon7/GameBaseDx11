#pragma once
#include "Engine/GameObject.h"
class Bullet :
    public GameObject
{
public:
	Bullet(GameObject* parent);
	~Bullet() {};
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	
	void SetVelocity(float x, float y, float z);
	XMFLOAT3 GetVelocity() const { return velocity_; }

private:
	int hModel_;//モデルのハンドル
	float speed_;//弾の速さ	
	XMFLOAT3 velocity_;
};

