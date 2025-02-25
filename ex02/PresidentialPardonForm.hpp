#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP
# include <string>
# include  "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator = (const PresidentialPardonForm &rhs);
		void					executeAction() const;
};

#endif