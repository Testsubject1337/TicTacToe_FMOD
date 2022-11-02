#pragma once

#include "Player.h"
#include "Field.h"
#include <random>
#include <time.h>

class AIPlayer : public Player 
{
public:
	AIPlayer();
	void doTurn(Field* field) override;
};