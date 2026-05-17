#include "Sceen.h"
#include "GameLevel.h"
#include <iostream>
#include <vector>

int main() {
	std::vector<GameLevel> levels = {
		{"Лёгкий", 2, 60, 10},
		{"Средний", 3, 45, 20},
		{"Сложный", 4, 30, 30}
	};

	std::cout << "Выберите уровень сложности:\n";
	for (size_t i = 0; i < levels.size(); ++i) {
		std::cout << i + 1 << ". " << levels[i].name
		          << " (форм: " << levels[i].propertiesCount
		          << ", время: " << levels[i].timeSeconds << "с, очков: " << levels[i].pointsPerSuccess << ")\n";
	}
	int choice;
	std::cin >> choice;

	if (choice < 1 || choice > levels.size()) {
		std::cout << "Неверный выбор\n";
		return 1;
	}

	GameLevel selected = levels[choice - 1];
	Screen game(selected);
	game.Start();
	game.GameCycle();

	return 0;
}