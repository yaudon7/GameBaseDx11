#pragma once
#include "Engine/GameObject.h"
class GameOverScene :
    public GameObject
{
public:
	GameOverScene(GameObject* parent);
	~GameOverScene() {};
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
private:
	int hClearPic;

};

