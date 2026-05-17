#ifndef _FRAMES_H_
#define _FRAMES_H_

#include <memory>
#include "Form.h"
#include "Toys.h"

class Frames {
public:
	Frames(const Form& form) : form(std::make_unique<Form>(form)) {}

	bool IsSame(const Frames& other) const { return this == &other; }
	const Form& GetForm() const { return *form; }
	bool IsPassable(const Toys& toy) const {
		return form->IsEqual(toy.GetForm());
	}
private:
	std::unique_ptr<Form> form;
};

#endif