#pragma once
#ifndef _FRAMES_H_
#define _FRAMES_H_

#include <string>
#include <iostream>
#include <memory>

#include "Form.h"
#include "Toys.h"

class Frames {
public:
	Frames(const Form& form) : form(std::make_unique<Form>(form)) {}

	bool IsSame(const Frames& other) {
		return this == &other;
	}
	const Form& GetForm() const {
		return *form;
	}
	bool IsPassable(const Toys& toy) const {
		return form->IsEqual(toy.GetForm());
	}
	//void Collect(const Toys& toy); уместен для объекта который сможет хранить в себе игрушки
private:
	std::unique_ptr<Form> form;
};

#endif //!_FRAMES_H_