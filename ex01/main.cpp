#include <iostream>
#include "Bureaucrat.hpp"

void	unsignableForm()
{
	std::cout << "#UNSIGNABLE FORM#\n";
	try
	{
		Form	contactForm("contactForm", -13, 3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	feedbackForm("feedbackForm", 9, 167);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	promotionGrandiose()
{
	std::cout << "#PROMOTION GRANDIOSE#\n";
	Bureaucrat	regularGuy("regularGuy", 77);
	Form		contactForm("contactForm", 76, 56);

	std::cout << regularGuy << std::endl;
	std::cout << contactForm << std::endl;

	regularGuy.signForm(contactForm);

	regularGuy.incrementGrade(); // got promoted

	std::cout << regularGuy << std::endl;

	regularGuy.signForm(contactForm);

	std::cout << contactForm << std::endl;

	regularGuy.signForm(contactForm);

}

void	incredibleWork() // maybe to get rid of
{
	std::cout << "#INCREDIBLE WORK#\n";

	Bureaucrat	workaholic("workaholic", 1);
	Form		feedbackForm("feedbackForm", 1, 1);

	try
	{
		workaholic.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << workaholic << std::endl;

	try
	{
		workaholic.signForm(feedbackForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	unsignableForm();

	std::cout << std::endl;

	promotionGrandiose();

	std::cout << std::endl;

	incredibleWork();
}