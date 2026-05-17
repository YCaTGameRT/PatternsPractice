#ifndef _SCEENDIRECTOR_H_
#define _SCEENDIRECTOR_H_

#include "Sceen.h"
#include "ScreenWorker.h"

class ScreenDirector {
public:
	ScreenDirector() : product(nullptr), worker(nullptr) {}
	ScreenDirector(Screen* product, ScreenWorker* worker) : product(product), worker(worker) {}
	ScreenDirector(ScreenWorker* worker) : product(nullptr), worker(worker) {}

	void SetWorker(ScreenWorker* worker) { this->worker = worker; }
	void SetProduct(Screen* product) { this->product = product; }

	void Produce() {
		if (worker && product) {
			worker->MakePlate(product);
			worker->MakeToys(product);
			worker->Checkout(product);
		}
	}

	Screen* GetProduct() { return product; }
	Screen* ReleaseProduct() {
		Screen* p = product;
		product = nullptr;
		return p;
	}
private:
	Screen* product;
	ScreenWorker* worker;
};

#endif