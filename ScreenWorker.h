#ifndef _SCREENWORKER_H_
#define _SCREENWORKER_H_

#include "Sceen.h"

class ScreenWorker {
public:
	virtual void MakePlate(Screen* product) = 0;
	virtual void MakeToys(Screen* product) = 0;
	virtual void Checkout(Screen* product) = 0;
	virtual ~ScreenWorker() = default;
};

#endif