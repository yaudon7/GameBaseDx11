#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);//Playerのインスタンス
	Instantiate<Enemy>(this);//Enemyのインスタンス
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

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
