#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"
#include "Player.h"
#include "EnemyBullet.h"
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
	enemyShootCoolDown_ = 0.0f;
}

void Enemy::Update()
{
	static float time = 0.0f;
	Player* player = (Player*)(this->GetParent());
	

	transform_.position_ = { 0.0f, -2.0f, 20.0f };
	transform_.scale_ = { 0.5f, 0.5f, 0.5f };
	//tr_.rotate_.y = time; //回転させる
	time += 0.025f;
	transform_.position_.x = 6.0f * sin(time);
	
	//プレイヤーの位置を取得して、敵からプレイヤーへのベクトルを求める
	Transform EnemyToPlayer;
	EnemyToPlayer.position_ = {
		transform_.position_.x - player->GetPosition().x,
		transform_.position_.y - player->GetPosition().y,
		transform_.position_.z - player->GetPosition().z
	};
	//ベクトルを正規化する
	float length = sqrt(EnemyToPlayer.position_.x * EnemyToPlayer.position_.x +
		                EnemyToPlayer.position_.y * EnemyToPlayer.position_.y +
		                EnemyToPlayer.position_.z * EnemyToPlayer.position_.z);
	//ベクトルの長さが0でない場合のみ正規化する
	EnemyToPlayer.position_ = { EnemyToPlayer.position_.x / length,
								EnemyToPlayer.position_.y / length,
								EnemyToPlayer.position_.z / length };
	//攻撃間隔が0になったら、プレイヤーの方向に弾を発射する
	if (enemyShootCoolDown_ == 0.0f)
	{
		EnemyBullet* eBullet = Instantiate<EnemyBullet>(this->GetParent());//this = Enemy
		eBullet->SetPosition(transform_.position_);	
		eBullet->SetVelocity(
			EnemyToPlayer.position_.x,
			EnemyToPlayer.position_.y,
			EnemyToPlayer.position_.z
		);
		enemyShootCoolDown_ = 3.0f;
	}
	enemyShootCoolDown_ -= 1.0f / 60.0f;
	if (enemyShootCoolDown_ < 0.0f) enemyShootCoolDown_ = 0.0f;
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

