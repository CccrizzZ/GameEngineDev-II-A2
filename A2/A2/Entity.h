#pragma once
#include "SceneNode.h"



// 2D Entity
class Entity : public SceneNode
{
public:
	Entity();
	// Entity(A1* gRef);
	~Entity();



	XMFLOAT2 getVelocity();
	void setVelocity(float x, float y);
	void updateVelocity(const GameTimer& gt);

	// render item
	unique_ptr<RenderItem> EntityRenderItem;


	// entity velocity
	XMFLOAT2 Velocity;

};


