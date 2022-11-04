#pragma once
#include "Player.h"


class LocalPlayer : public Player
{
public:
	void doTurn(Field* field) override;
	void onWin() override;
	void onLose() override;
	void onTie() override;
	bool isSingleplayer = true;
	int playerNr = 1;

	LocalPlayer(bool isSingleplayer, int playerNr) : isSingleplayer(isSingleplayer), playerNr(playerNr) {};
	LocalPlayer() {};
};


