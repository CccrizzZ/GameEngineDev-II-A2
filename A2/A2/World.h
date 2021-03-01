#pragma once
#include "SceneNode.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include <map>

enum class RenderLayer : int
{
	Opaque = 0,
	Transparent,
	AlphaTested,
	Count
};

// class Player;

class World
{
public:
    // explicit World(A1* gRef);
    World();
    ~World();


    void Init();
    void Update(const GameTimer& gt);
    void Draw();


	std::vector<std::unique_ptr<RenderItem>> AllRenderItems;
	map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;
	map<std::string, std::unique_ptr<Material>> mMaterials;

	vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

    // scene objects
    Player* player1 = new Player();
    Enemy* enemy;
    Background* bg1 = new Background();



};

