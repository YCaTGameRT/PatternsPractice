#ifndef _GAMELEVEL_H_
#define _GAMELEVEL_H_

#include <string>

struct GameLevel {
	std::string name;
	int propertiesCount;
	int timeSeconds;
	int pointsPerSuccess;

	GameLevel(std::string n, int props, int time, int points)
		: name(n), propertiesCount(props), timeSeconds(time), pointsPerSuccess(points) {}
};

#endif