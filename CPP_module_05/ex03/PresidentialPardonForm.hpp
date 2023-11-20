#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(std::string target, std::string name);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm();

		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

		void	execute(Bureaucrat const & executor)const;

		std::string	getTarget()const;

	private:

		std::string	target;

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */