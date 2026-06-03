#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
Player::Player(GameObject* parent):
	GameObject(parent,"Player"),hModel_(-1)
{
	coolDown_ = 0.0f;
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = {0.0f, -2.0f, 0.0f };
	transform_.rotate_ = { 0.0f,180.0f,0.0f };
	speed_ = 1.0f;
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);

}

void Player::Update()
{
	float dt = 1.0f / 60.0f;//デルタタイム（1フレームの時間）

	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A)) {
		transform_.position_.x -= speed_ * dt;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D)) {
		transform_.position_.x += speed_ * dt;
	}
	
	if (Input::IsKeyDown(DIK_SPACE) && coolDown_ == 0.0f) {
		Bullet* pBullet = Instantiate<Bullet>(this->GetParent());//this = Player
		pBullet ->SetPosition(transform_.position_);
		coolDown_ = 0.5f;
	}
	coolDown_ -= dt;
	if (coolDown_ < 0.0f) coolDown_ = 0.0f;
	
}


void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "EnemyBullet") {
		pTarget->KillMe();
		this->KillMe();
	}
}
