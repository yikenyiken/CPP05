#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator = (const RobotomyRequestForm &rhs);
		void				executeAction() const;
};

#endif