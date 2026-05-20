#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
Player::Player(GameObject* parent):
	GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = {0.0f, - 3.0f, 0.0f };
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A)) {
		tr_.position_.x += -1.0f;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D)) {
		tr_.position_.x += 1.0f;
	}
	
	if (Input::IsKey(DIK_SPACE)) {
		Instantiate<Bullet>(this);
	}
}


void Player::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
