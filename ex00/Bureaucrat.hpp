#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
# include <string>

class Bureaucrat
{
	private:
		const std::string		name;
		int						grade;

		class GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};

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
};

std::ostream	&operator << (std::ostream &os, Bureaucrat &employee);

#endif