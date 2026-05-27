#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"), hClearPic(-1)
{
}

void GameOverScene::Initialize()
{
	hClearPic = Image::Load("Over.png");
	assert(hClearPic >= 0);
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* OverSceneManager = (SceneManager*)(this->GetParent());
		OverSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(hClearPic, transform_);
	Image::Draw(hClearPic);
}

void GameOverScene::Release()
{
}
