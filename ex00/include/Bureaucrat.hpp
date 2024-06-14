#pragma once

#includ <string>

class Bureaucrat {
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat(std::string const name);
	~Bureaucrat(void);

private:
	std::string	name;
	unsigned int grade;
}
