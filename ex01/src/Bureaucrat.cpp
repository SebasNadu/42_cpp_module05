/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:18:04 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/26 15:37:01 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Anonymous"), _grade(150) {
  std::cout << "Bureaucrat " << this->_name
            << " created. Grade: " << this->_grade << std::endl;
};

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
  std::cout << "Bureaucrat " << this->_name
            << " created. Grade: " << this->_grade << std::endl;
};

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150) {
  std::cout << "Bureaucrat " << this->_name
            << " created. Grade: " << this->_grade << std::endl;
};

Bureaucrat::Bureaucrat(int grade) : _name("Anonymous") {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
  std::cout << "Bureaucrat " << this->_name
            << " created. Grade: " << this->_grade << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src._name + "_copy"), _grade(src._grade) {
  std::cout << "Bureaucrat " << this->_name
            << " created. Grade: " << this->_grade << std::endl;
};

Bureaucrat::~Bureaucrat(void) {
  std::cout << "Deconstructor called for Bureaucrat: " << this->_name
            << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  std::cout << "Bureaucrat assignment operator called" << std::endl;
  if (this != &rhs)
    *this = Bureaucrat(rhs.getName() + "_copy", rhs.getGrade());
  return (*this);
}

std::string const Bureaucrat::getName(void) const { return (this->_name); }

size_t Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::setGrade(int grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
}

void Bureaucrat::incrementGrade(void) {
  if (this->_grade == 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade--;
  std::cout << "Bureaucrat " << this->_name << " grade incremented to "
            << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade(void) {
  if (this->_grade == 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade++;
  std::cout << "Bureaucrat " << this->_name << " grade decremented to "
            << this->_grade << std::endl;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(this);
  } catch (std::exception &e) {
    std::cout << RED << this->_name << " couldn't sign " << form.getName()
              << " because: " << e.what() << RESET << std::endl;
  }
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return ("Grade is too low");
}

// Overload operator<<
std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return (out);
}
