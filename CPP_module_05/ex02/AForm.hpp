#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		AForm(int grade_to_sign, int grade_to_execute);
		AForm( AForm const & src );
		~AForm();

		AForm &			operator=( AForm const & rhs );

		std::string		getName() const;
		bool			is_signed() const;
		int				getGrade_to_sign() const;
		int				getGrade_to_execute() const;

		void			beSigned(Bureaucrat a);
		virtual void	execute(Bureaucrat const & executor)const = 0;

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
		class NotSignedException: public std::exception
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

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */