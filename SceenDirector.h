#pragma once
#ifndef _SCEEN_DIRECTOR_H_
#define _SCEEN_DIRECTOR_H_

#include "Sceen.h"

class SceenDirector {
public:
	SceenDirector() = default;
	SceenDirector(Sceen* product, SceenWorker* worker);
	SceenDirector(SceenWorker* worker);

	void SetWorker(SceenWorker* worker);
	void SetProduct(Sceen* product);

	void Produce() {
		worker->MakePlate(product);
		worker->MakeToys(product);
		worker->Checkout(product);
	}

	Sceen* GetProduct();
	Sceen* ReleaseProduct();
private:
	Sceen* product;
	//SceenWorker *worker;
};

#endif