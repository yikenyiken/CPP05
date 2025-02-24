#include "AForm.hpp"
#include <iostream>

AForm::AForm() : name("default"), signStatus(false), signGrade(LOWEST_GRADE)
	, executeGrade(LOWEST_GRADE)
{
	std::cout << "AForm's Default Constructor called\n";
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name),
	signStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "AForm's Parametrized Constructor called\n";

	if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();

	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name("default"), signStatus(false)
	, signGrade(LOWEST_GRADE), executeGrade(LOWEST_GRADE)
{
	std::cout << "AForm's Copy Constructor called\n";

	*this = other;
}

AForm::~AForm() 
{
	std::cout << "AForm's Destructor called\n";
}


AForm	&AForm::operator = (const AForm &rhs) 
{
	(void)rhs;

	return (*this);
}

std::string	AForm::getName()
{
	return (name);
}

bool	AForm::getSignStatus()
{
	return (signStatus);
}

int	AForm::getSignGrade()
{
	return (signGrade);
}

int	AForm::GetExecuteGrade()
{
	return (executeGrade);
}

void	AForm::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();

	if (employee.getGrade() > LOWEST_GRADE)
		throw AForm::GradeTooLowException();

	if (employee.getGrade() <= signGrade)
		signStatus = true;
}


const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLowException");
}

std::ostream	&operator << (std::ostream &os, AForm &form)
{
	std::string	signStatusString = form.getSignStatus() ? "signed" : "not Signed";

	os << form.getName() << " AForm with sign grade " << form.getSignGrade()
		<< " and execute grade " << form.GetExecuteGrade()
		<< " is " << signStatusString;

	return (os);
}