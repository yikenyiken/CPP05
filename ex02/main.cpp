#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#define FORMS_N 3

void	executionRequirements()
{
	std::cout << "# EXECUTION REQUIREMENTS #\n";

	Bureaucrat				employee("employee", 138);
	ShruberryCreationForm	shrub("Park");
	RobotomyRequestForm		robotomy("Doctor octopus");
	PresidentialPardonForm	pardon("sisyphus");

	std::cout << ">> " << employee << std::endl;
	std::cout << std::endl;

	try
	{
		pardon.execute(employee); // sign it first
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	employee.executeForm(shrub);
	employee.signForm(shrub);
	employee.executeForm(shrub); // grade issue

	employee.incrementGrade(); // promoted

	std::cout << ">> " << employee << std::endl;
	std::cout << std::endl;

	employee.executeForm(shrub);
}

void	FormsOhMy()
{
	std::cout << "# FORMS OH MY #\n";

	Bureaucrat	workaholic("workaholic", 1);
	ShruberryCreationForm	shrub("Park");
	RobotomyRequestForm		robotomy("Doctor octopus");
	PresidentialPardonForm	pardon("Sisyphus");
	
	std::cout << ">> " << workaholic << std::endl;
	std::cout << std::endl;

	workaholic.signForm(shrub);
	workaholic.signForm(robotomy);
	workaholic.signForm(pardon);

	shrub.execute(workaholic);
	std::cout << std::endl;

	robotomy.execute(workaholic);
	std::cout << std::endl;

	pardon.execute(workaholic);
}

int main()
{
	executionRequirements();

	std::cout << std::endl;

	FormsOhMy();
}