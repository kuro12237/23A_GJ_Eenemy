#pragma once
#include"Model/Model.h"

class TransCube
{
public:
	TransCube();
	~TransCube();

	void Initialize();

	void Update();

	void Draw(ViewProjection view);



private:

	std::unique_ptr<Model> model_;
	WorldTransform worldTransform = {};
};

