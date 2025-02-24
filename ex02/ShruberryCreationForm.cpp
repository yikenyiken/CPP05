#include "ShruberryCreationForm.hpp"
#include <iostream>
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm()
	: AForm("ShruberryCreationFrom", 145, 137), target(target)
{
	std::cout << "ShruberryCreationForm's Default Constructor called\n";
}

ShruberryCreationForm::ShruberryCreationForm(std::string target)
	: AForm("ShruberryCreationFrom", 145, 137), target(target)
{
	std::cout << "ShruberryCreationForm's Parametrized Constructor called\n";
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &other)
	: AForm("ShruberryCreationFrom", 145, 137), target(target)
{
	std::cout << "ShruberryCreationForm's Copy Constructor called\n";

	*this = other;
}

ShruberryCreationForm::~ShruberryCreationForm() 
{
	std::cout << "ShruberryCreationForm's Destructor called\n";
}


ShruberryCreationForm	&ShruberryCreationForm::operator = (const ShruberryCreationForm &rhs) 
{
	target = rhs.target;

	return (*this);
}

void	ShruberryCreationForm::execute(const Bureaucrat &executor) const
{
	// throw exception if executor grade out of grade range
	// check if executor has enough grade

	std::ofstream	outfile(target + "_shruberry");

	

}