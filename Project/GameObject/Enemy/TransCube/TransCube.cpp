#include"TransCube.h"

TransCube::TransCube()
{
}

TransCube::~TransCube()
{
}

void TransCube::Initialize()
{
	model_ = std::make_unique<Model>();
	worldTransform.matWorld_ = MakeIdentity4x4();
	model_.get()->CreateFromOBJ("Project/Resources","TransCube.obj");
}

void TransCube::Update()
{

}

void TransCube::Draw(ViewProjection view)
{
	model_.get()->Draw(worldTransform, view);
}
