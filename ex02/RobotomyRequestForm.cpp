#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default")
{
	// std::cout << "RobotomyRequestForm's Default Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	// std::cout << "RobotomyRequestForm's Parametrized Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm("RobotomyRequestForm", 72, 45)
{
	// std::cout << "RobotomyRequestForm's Copy Constructor called\n";

	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	// std::cout << "RobotomyRequestForm's Destructor called\n";
}


RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm &rhs) 
{
	target = rhs.target;

	return (*this);
}

void	RobotomyRequestForm::executeAction() const
{
	std::srand(std::time(0));
	int	random = std::rand();

	std::cout << "* DRILLING NOISES *\n";

	if (random % 2)
	{
		std::cout << target << " has been robotomized successfully\n";
		return ;
	}

	std::cout << "robotomy failed\n";
}