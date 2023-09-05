#include "GameScene.h"
#include <cassert>

GameScene::GameScene() {};

GameScene::~GameScene() {};

void GameScene::Initialize(GameManager* gameManager) {
	//TextureManagerのインスタンスを取得
	textureManager_ = TextureManager::GetInstance();
	//Audioのインスタンスを取得
	audio_ = Audio::GetInstance();
	//Inputのインスタンスを取得
	input_ = Input::GetInstance();
	//PostProcessのインスタンスを取得
	postProcess_ = PostProcess::GetInstance();
	//衝突マネージャーの作成
	collisionManager_ = new CollisionManager();
	//デバッグカメラの生成
	debugCamera_ = new DebugCamera();

	transCube_ = std::make_unique<TransCube>();
	transCube_.get()->Initialize();


};

void GameScene::Update(GameManager* gameManager) {











	//デバッグカメラの更新
	debugCamera_->Update();
	//デバッグカメラの切り替え
	if (input_->IsPushKeyEnter(DIK_1)) {
		if (isDebugCameraActive_ == false) {
			isDebugCameraActive_ = true;
		}
		else {
			isDebugCameraActive_ = false;
		}
	}
	//ビュープロジェクションの更新
	if (isDebugCameraActive_ == true) {
		viewProjection_.matView_ = debugCamera_->GetViewProjection().matView_;
		viewProjection_.matProjection_ = debugCamera_->GetViewProjection().matProjection_;
	}
	else {
		viewProjection_.UpdateMatrix();
	}
};

void GameScene::Draw(GameManager* gameManager) {


#pragma region ポストプロセス
	//ポストプロセスの描画前処理
	postProcess_->PreDraw();
	transCube_.get()->Draw(viewProjection_);


	//ポストプロセスの描画後処理
	postProcess_->PostDraw();
#pragma endregion

};