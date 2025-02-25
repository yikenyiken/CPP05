#include "AForm.hpp"
#include <iostream>

AForm::AForm() : name("default"), signStatus(false), signGrade(LOWEST_GRADE)
	, executeGrade(LOWEST_GRADE)
{
	// std::cout << "AForm's Default Constructor called\n";
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name),
	signStatus(false), signGrade(signGrade), executeGrade(executeGrade)
{
	// std::cout << "AForm's Parametrized Constructor called\n";

	if (signGrade < HIGHEST_GRADE || executeGrade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();

	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name("default"), signStatus(false)
	, signGrade(LOWEST_GRADE), executeGrade(LOWEST_GRADE)
{
	// std::cout << "AForm's Copy Constructor called\n";

	*this = other;
}

AForm::~AForm() 
{
	// std::cout << "AForm's Destructor called\n";
}


AForm	&AForm::operator = (const AForm &rhs) 
{
	(void)rhs;

	return (*this);
}

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::getSignStatus() const
{
	return (signStatus);
}

int	AForm::getSignGrade() const
{
	return (signGrade);
}

int	AForm::GetExecuteGrade() const
{
	return (executeGrade);
}

void	AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() <= signGrade)
	{
		signStatus = true;
		return ;
	}

	throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!getSignStatus())
		throw AForm::UnsignedFormException();

	if (executor.getGrade() <= GetExecuteGrade())
	{
		executeAction();
		return ;
	}

	throw AForm::GradeTooLowException();
}


const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char	*AForm::UnsignedFormException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream	&operator << (std::ostream &os, AForm &form)
{
	std::string	signStatusString = form.getSignStatus() ? "signed" : "not signed";

	os << form.getName() << " Form with sign grade " << form.getSignGrade()
		<< " and execute grade " << form.GetExecuteGrade()
		<< " is " << signStatusString;

	return (os);
}