#pragma once

#ifndef _SCEEN_H_
#define _SCEEN_H_

#include "Frames.h"
#include "Toys.h"

//
class Player;
class Panel;

class Sceen {
public:
	struct Action {
		//
	};

	Sceen() = default;
	Sceen(...); //

	void Start();

	void GameCicle();

	Player& GetPlayer();
	Panel& GetPanel();

	//дальнейший перечень публичных и приватных методов должен исходить из правил игровой логики
private:
	Player player;
	Panel panel;
	//
};

#endif