#include <string>
#include <iostream>

#include "Form.hpp"

class Intern
{
	private :
		std::string	_formRequest[3];
	public :
	Intern(void);
	Intern(Intern const & intern);
	virtual ~Intern();
	Intern &operator=(Intern const & Intern);
	Form*	makeForm(std::string const s1, std::string const s2);
	class NoFormFind : public std::exception
	{
		public :
			virtual const char *what() const throw() {return ("Did not find Form");}
	};
};