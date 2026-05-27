#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
	speed_ = 0.5f;
	velocity_ = { 0.0f,0.0f,0.0f };
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Bullet::Update()
{
	transform_.position_.z += 0.5f;
	transform_.rotate_.y = 180.0f;
	if (transform_.position_.z > 50.0f) {
		KillMe();//自分を削除する
	}


}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}

void Bullet::SetVelocity(float x, float y, float z)
{
	velocity_ = { x,y,z };
}
