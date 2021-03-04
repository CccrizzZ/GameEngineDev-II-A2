#pragma once
#include "Entity.hpp"

class SpriteNode :
    public Entity
{
public:
	SpriteNode(Game* game);
	void Update(const GameTimer gt);

private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();
};
