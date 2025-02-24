#ifndef Form_HPP
# define Form_HPP
# include <string>
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				signStatus;
		const int			signGrade;
		const int			executeGrade;

	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		~AForm();

		AForm			&operator = (const AForm &rhs);
		std::string		getName();
		bool			getSignStatus();
		int				getSignGrade();
		int				GetExecuteGrade();
		void			beSigned(Bureaucrat &employee);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

std::ostream	&operator << (std::ostream &os, AForm &form);

#endif