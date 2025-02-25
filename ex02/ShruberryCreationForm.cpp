#include "ShruberryCreationForm.hpp"
#include <iostream>
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm()
	: AForm("ShruberryCreationForm", 145, 137), target("default")
{
	// std::cout << "ShruberryCreationForm's Default Constructor called\n";
}

ShruberryCreationForm::ShruberryCreationForm(std::string target)
	: AForm("ShruberryCreationForm", 145, 137), target(target)
{
	// std::cout << "ShruberryCreationForm's Parametrized constructor called\n";
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &other)
	: AForm("ShruberryCreationForm", 145, 137)
{
	// std::cout << "ShruberryCreationForm's Copy Constructor called\n";

	*this = other;
}

ShruberryCreationForm::~ShruberryCreationForm() 
{
	// std::cout << "ShruberryCreationForm's Destructor called\n";
}


ShruberryCreationForm	&ShruberryCreationForm::operator = (const ShruberryCreationForm &rhs) 
{
	target = rhs.target;

	return (*this);
}

void	ShruberryCreationForm::executeAction() const
{

	std::string	filename = target + "_shruberry";

	std::ofstream	outfile(filename);
	
	if (!outfile.is_open())
		throw std::runtime_error("failed to open " + filename);

	outfile << "      *\\      \n";
	outfile << "     ***\\     \n";
	outfile << "    *****\\    \n";
	outfile << "   *******\\   \n";
	outfile << "  *********\\  \n";
	outfile << " ***********\\ \n";
	outfile << "     |||     \n";
}