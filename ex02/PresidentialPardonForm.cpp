#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 72, 45), target("target")
{
	// std::cout << "PresidentialPardonForm's Default Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 72, 45), target(target)
{
	// std::cout << "PresidentialPardonForm's Paramterized Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
	: AForm("PresidentialPardonForm", 72, 45)
{
	// std::cout << "PresidentialPardonForm's Copy Constructor called\n";

	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	// std::cout << "PresidentialPardonForm's Destructor called\n";
}


PresidentialPardonForm	&PresidentialPardonForm::operator = (const PresidentialPardonForm &rhs) 
{
	target = rhs.target;

	return (*this);
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblbrox\n";
}