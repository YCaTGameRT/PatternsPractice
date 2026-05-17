#ifndef _FORM_H_
#define _FORM_H_

#include <string>

class Form {
public:
	enum class Shapes {
		circle,
		triangle,
		square,
		star
	};

	Form(Shapes shape) : shape(shape) {
		switch (shape) {
		case Shapes::circle:   name = "circle"; break;
		case Shapes::triangle: name = "triangle"; break;
		case Shapes::square:   name = "square"; break;
		case Shapes::star:     name = "star"; break;
		}
	}

	std::string GetName() const { return name; }
	Shapes GetShape() const { return shape; }

	bool operator==(const Form& other) const {
		return shape == other.shape;
	}
	bool IsEqual(const Form& other) const {
		return *this == other;
	}
private:
	Shapes shape;
	std::string name;
};

#endif