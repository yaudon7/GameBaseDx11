#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/SphereCollider.h"
#include "Player.h"
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

	/*Transform PlayerToEnemy;
	PlayerToEnemy.position_ = { player->GetPosition().x - transform_.position_.x,
					            player->GetPosition().y - transform_.position_.y,
					            player->GetPosition().z - transform_.position_.z
	};
	float length = sqrt(PlayerToEnemy.position_.x * PlayerToEnemy.position_.x +
		PlayerToEnemy.position_.y * PlayerToEnemy.position_.y +
		PlayerToEnemy.position_.z * PlayerToEnemy.position_.z);

	PlayerToEnemy.position_ = { PlayerToEnemy.position_.x / length,
								PlayerToEnemy.position_.y / length,
								PlayerToEnemy.position_.z / length };*/

	//if (enemyShootCoolDown_ == 0.0f)
	//{
	//	Bullet* eBullet = Instantiate<Bullet>(this->GetParent());//this = Enemy
	//	eBullet->SetPosition(transform_.position_);	
	//	eBullet->SetVelocity(
	//		PlayerToEnemy.position_.x,
	//		PlayerToEnemy.position_.y,
	//		PlayerToEnemy.position_.z
	//	);
	//	enemyShootCoolDown_ = 3.0f;
	//}
	//enemyShootCoolDown_ -= 1.0f / 60.0f;
	//if (enemyShootCoolDown_ < 0.0f) enemyShootCoolDown_ = 0.0f;
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

