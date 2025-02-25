#include "Form.hpp"
#include <iostream>

Form::Form() : name("default"), signStatus(false), signGrade(LOWEST_GRADE)
	, executeGrade(LOWEST_GRADE)
{
	std::cout << "Form's Default Constructor called\n";
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name),
	signStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Form's Parametrized Constructor called\n";

	if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();

	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name("default"), signStatus(false)
	, signGrade(LOWEST_GRADE), executeGrade(LOWEST_GRADE)
{
	std::cout << "Form's Copy Constructor called\n";

	*this = other;
}

Form::~Form() 
{
	std::cout << "Form's Destructor called\n";
}


Form	&Form::operator = (const Form &rhs) 
{
	(void)rhs;

	return (*this);
}

std::string	Form::getName()
{
	return (name);
}

bool	Form::getSignStatus()
{
	return (signStatus);
}

int	Form::getSignGrade()
{
	return (signGrade);
}

int	Form::GetExecuteGrade()
{
	return (executeGrade);
}

void	Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() <= signGrade)
	{
		signStatus = true;
		return ;
	}

	throw Form::GradeTooLowException();
}


const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator << (std::ostream &os, Form &form)
{
	std::string	signStatusString = form.getSignStatus() ? "signed" : "not signed";

	os << form.getName() << " Form with sign grade " << form.getSignGrade()
		<< " and execute grade " << form.GetExecuteGrade()
		<< " is " << signStatusString;

	return (os);
}