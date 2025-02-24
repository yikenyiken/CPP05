#include "Bureaucrat.hpp"
#include <iostream>

void	fluctuatingCareer(std::string name, int grade, void (Bureaucrat::*gradeUpdate)())
{
	try
	{
		Bureaucrat	workaholic(name, grade);
	
		std::cout << workaholic;

		(workaholic.*gradeUpdate)();

		std::cout << workaholic;

		(workaholic.*gradeUpdate)();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	replaceEmployee()
{
	Bureaucrat	willy = Bureaucrat("will", 150);

	try
	{
		willy.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << willy << std::endl;

	try
	{
		Bureaucrat	billy = willy;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	billy("bill", 15);

		std::cout << billy << std::endl;
	
		billy = willy;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	fluctuatingCareer("workaholic", 0, &Bureaucrat::incrementGrade);

	fluctuatingCareer("workaholic", 155, &Bureaucrat::incrementGrade);

	fluctuatingCareer("workaholic", 2, &Bureaucrat::incrementGrade);

	fluctuatingCareer("lazyGaga", 149, &Bureaucrat::decrementGrade);

	replaceEmployee();
}