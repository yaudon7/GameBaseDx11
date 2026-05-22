#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/SphereCollider.h"
Enemy::Enemy(GameObject* parent) :
	GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.rotate_ = { 0.0f,180.0f,0.0f };
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Enemy::Update()
{
	static float time = 0.0f;

	transform_.position_ = { 0.0f, -2.0f, 20.0f };
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	//tr_.rotate_.y = time; //回転させる
	time += 0.025f;
	transform_.position_.x = 6.0f * sin(time);
	//float posx = 6.0*sin(0.2f*time);
	//float posy = cos(3.0f * time);
	//tr_.position_.x = posx;
	//tr_.position_.y = posy;
}
void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		pTarget->KillMe();
		this->KillMe();
	}
}
