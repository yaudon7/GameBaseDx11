#include "ClearScene.h"
#include "Engine/Image.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hClearPic(-1)
{
}

void ClearScene::Initialize()
{
	hClearPic = Image::Load("Clear.png");
	assert(hClearPic >= 0);
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Image::SetTransform(hClearPic, transform_);
	Image::Draw(hClearPic);
}

void ClearScene::Release()
{
}
