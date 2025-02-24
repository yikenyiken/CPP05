#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string		name;
		int						grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat	&operator = (const Bureaucrat &rhs);
		std::string	getName();
		int			getGrade();
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &form);

	private:
		class GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};
};

std::ostream	&operator << (std::ostream &os, Bureaucrat &employee);

#endif