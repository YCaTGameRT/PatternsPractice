#pragma once
#ifndef _TOYS_H_
#define _TOYS_H_

#include <string>
#include <iostream>
#include <memory>

#include "Form.h"

class Toys {
public:
	Toys(const Form& form) : form(std::make_unique<Form>(form)) {}
	
	const Form& GetForm() const {
		return *form;
	}
	bool IsSame(const Toys& other) const {
		return this == &other;
	}
private:
	std::string name;
	std::unique_ptr<Form> form;
};

#endif //!_TOYS_H_