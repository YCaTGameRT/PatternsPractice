#ifndef _SCEEN_H_
#define _SCEEN_H_

#include "Player.h"
#include "Panel.h"
#include "GameLevel.h"
#include <vector>
#include <string>

class Screen {
public:
	enum class PlayerAction {
		InspectToy,
		InspectFrame,
		PlaceToy,
		NextToy,
		PrevToy,
		Quit
	};

	struct ActionResult {
		bool success;
		int pointsEarned;
		std::string message;
	};

	Screen(const GameLevel& level);

	void Start();
	void GameCycle();

	Player& GetPlayer() { return player; }
	Panel& GetPanel() { return panel; }
	int GetScore() const { return score; }

	ActionResult PerformAction(PlayerAction action, int frameIndex = -1);

private:
	Player player;
	Panel panel;
	GameLevel level;
	int score = 0;
	int remainingTime;
	bool isGameActive = false;

	void GenerateLevelContent();
	void ShowState() const;
};

#endif