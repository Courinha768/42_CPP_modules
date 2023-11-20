#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(int grade_to_sign, int grade_to_execute);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string	getName() const;
		bool		is_signed() const;
		int			getGrade_to_sign() const;
		int			getGrade_to_execute() const;

		void		beSigned(Bureaucrat a);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	name;
		const int			grade_to_sign;
		const int			grade_to_execute;
		bool				signature;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */