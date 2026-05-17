#include "Sceen.h"
#include <iostream>
#include <chrono>
#include <thread>

Screen::Screen(const GameLevel& level) : level(level) {
	remainingTime = level.timeSeconds;
}

void Screen::GenerateLevelContent() {
	// Фабричный метод для игрушек и рамок
	std::vector<Form::Shapes> allShapes = {
		Form::Shapes::circle,
		Form::Shapes::triangle,
		Form::Shapes::square,
		Form::Shapes::star
	};

	// Берём первые propertiesCount форм для уровня
	for (int i = 0; i < level.propertiesCount && i < allShapes.size(); ++i) {
		Form form(allShapes[i]);
		player.AddToy(Toys(form));
		panel.AddFrame(Frames(form));
	}
}

void Screen::Start() {
	GenerateLevelContent();
	isGameActive = true;
	score = 0;
	std::cout << "\n=== Игра началась! Уровень: " << level.name
	          << " | Время: " << remainingTime << " сек | Очков за форму: " << level.pointsPerSuccess << "\n\n";
}

Screen::ActionResult Screen::PerformAction(PlayerAction action, int frameIndex) {
	if (!isGameActive) return {false, 0, "Игра окончена"};

	switch (action) {
	case PlayerAction::InspectToy:
		if (player.HasToys()) {
			return {true, 0, "Игрушка формы: " + player.GetCurrentToy().GetForm().GetName()};
		}
		return {false, 0, "Нет игрушек"};

	case PlayerAction::InspectFrame:
		if (frameIndex >= 0 && frameIndex < panel.GetFramesCount()) {
			return {true, 0, "Отверстие формы: " + panel.GetFrame(frameIndex).GetForm().GetName()};
		}
		return {false, 0, "Неверный индекс отверстия"};

	case PlayerAction::PlaceToy:
		if (!player.HasToys()) return {false, 0, "Нет игрушек"};
		if (panel.TryPlaceToy(player.GetCurrentToy(), frameIndex)) {
			player.RemoveCurrentToy();
			int points = level.pointsPerSuccess;
			score += points;
			return {true, points, "Успех! +" + std::to_string(points) + " очков"};
		}
		return {false, 0, "Игрушка не подходит"};

	case PlayerAction::NextToy:
		player.SelectNextToy();
		return {true, 0, "Следующая игрушка"};

	case PlayerAction::PrevToy:
		player.SelectPreviousToy();
		return {true, 0, "Предыдущая игрушка"};

	case PlayerAction::Quit:
		isGameActive = false;
		return {true, 0, "Выход из игры"};
	}
	return {false, 0, "Неизвестное действие"};
}

void Screen::ShowState() const {
	std::cout << "Счёт: " << score << " | Игрушек: " << player.GetToysCount()
	          << " | Отверстий: " << panel.GetFramesCount() << "\n";
}

void Screen::GameCycle() {
	while (isGameActive && player.HasToys() && panel.GetFramesCount() > 0) {
		ShowState();
		std::cout << "\nДействия: [1]Осмотреть игрушку [2]Осмотреть отверстие [3]Поместить\n"
		          << "[4]След.игрушка [5]Пред.игрушка [6]Выйти\nВыбор: ";
		int choice;
		std::cin >> choice;
		if (choice == 6) {
			PerformAction(PlayerAction::Quit);
			break;
		}
		if (choice == 2 || choice == 3) {
			std::cout << "Введите индекс отверстия (0.." << panel.GetFramesCount() - 1 << "): ";
			int idx;
			std::cin >> idx;
			auto res = PerformAction(static_cast<PlayerAction>(choice - 1), idx);
			std::cout << res.message << "\n";
		} else {
			auto res = PerformAction(static_cast<PlayerAction>(choice - 1));
			std::cout << res.message << "\n";
		}
	}
	if (isGameActive) {
		std::cout << "\nИгра окончена! Финальный счёт: " << score << "\n";
	}
	isGameActive = false;
}