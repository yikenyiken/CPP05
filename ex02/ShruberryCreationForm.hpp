#ifndef ShruberryCreationForm_HPP
# define ShruberryCreationForm_HPP
# include <string>
# include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShruberryCreationForm();
		ShruberryCreationForm(std::string target);
		ShruberryCreationForm(const ShruberryCreationForm &other);
		~ShruberryCreationForm();

		ShruberryCreationForm	&operator = (const ShruberryCreationForm &rhs);
		void					executeAction() const;
};

#endif