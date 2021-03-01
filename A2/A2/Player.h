#pragma once
#include "Entity.h"
#include "../../Common/d3dUtil.h"
#include "../../Common/GameTimer.h"



class Player : public Entity
{
public:
    // Player(A1* gRef);
    Player();
    ~Player();

    void Init();
    void Update(const GameTimer& gt);
    void Draw();

private:
    void OnKeyboardInput(const GameTimer& gt);


};

