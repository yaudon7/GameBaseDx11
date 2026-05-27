#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);//Playerのインスタンス
	Instantiate<Enemy>(this);//Enemyのインスタンス

	Camera::SetPosition(XMFLOAT3(0.0f, 2.0f, -10.0f));
	Camera::SetTarget(XMFLOAT3(0.0f, 1.0f, 10.0f));

}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		//見つからない場合はnullptrを返すので、nullptrでないことを確認してから使う
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}

	if (FindObject("Player") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_OVER);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
