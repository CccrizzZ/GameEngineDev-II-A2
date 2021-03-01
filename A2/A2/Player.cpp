#include "Player.h"
// #include "Game.h"


// Player::Player(A1* gRef) : Entity(gRef)
// {
// }


Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{

}

// player update
void Player::Update(const GameTimer& gt)
{
    OnKeyboardInput(gt);
}


void Player::Draw()
{
	// EntityRenderItem->World = getTransform();
	// EntityRenderItem->NumFramesDirty++;
}



// player input
void Player::OnKeyboardInput(const GameTimer& gt)
{
	if (GetAsyncKeyState('D') & 0x8000)
	{
		Position.x += 0.01f;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		Position.z -= 0.01f;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		Position.x -= 0.01f;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		Position.z += 0.01f;	
	}
}