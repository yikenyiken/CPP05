#ifndef Form_HPP
# define Form_HPP
# include <string>
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				signStatus;
		const int			signGrade;
		const int			executeGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &other);
		~Form();

		Form		&operator = (const Form &rhs);
		std::string	getName();
		bool		getSignStatus();
		int			getSignGrade();
		int			GetExecuteGrade();
		void		beSigned(Bureaucrat &signer);

	private:
		class GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			// need make it [public] ?
			const char	*what() const throw();
		};
};

std::ostream	&operator << (std::ostream &os, Form &form);

#endif