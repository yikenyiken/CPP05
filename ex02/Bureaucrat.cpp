#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat's Default Constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat's String/Uint Constructor called\n";

	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();

	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name("default")
{
	std::cout << "Bureaucrat's Copy Constructor called\n";

	*this = other;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat's Destructor called\n";
}


Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &rhs) 
{
	if (rhs.grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();

	if (rhs.grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();

	grade = rhs.grade;

	return (*this);
}

std::string	Bureaucrat::getName()
{
	return (name);
}

int	Bureaucrat::getGrade()
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	if (--grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	if (++grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form)
{
	bool	prevSignStatus = form.getSignStatus();

	if (prevSignStatus)
	{
		std::cout << getName() << " couldn't sign "
			<< form.getName() << ", already signed\n";
		return ;
	}

	form.beSigned(*this);

	if (form.getSignStatus())
		std::cout << getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << getName() << " couldn't sign "
			<< form.getName() << ", low grade\n";
}


const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

std::ostream	&operator << (std::ostream &os, Bureaucrat &employee)
{
	os << employee.getName() << ", bureaucrat grade "
		<< employee.getGrade();

	return (os);
}