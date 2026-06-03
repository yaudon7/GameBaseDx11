#include "EnemyBullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
EnemyBullet::EnemyBullet(GameObject* parent)
	:GameObject(parent, "EnemyBullet")
{
	speed_ = 0.5f;
	velocity_ = { 0.0f,0.0f,0.0f};
}

void EnemyBullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void EnemyBullet::Update()
{
	transform_.position_.z -= velocity_.z * speed_;
	if (transform_.position_.z < -50.0f) {
		KillMe();//自分を削除する
	}
}

void EnemyBullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

void EnemyBullet::Release()
{
}
