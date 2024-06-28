/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:18:04 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 19:39:29 by sebasnadu        ###   ########.fr       */
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
    this->_grade = rhs.getGrade();
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
  try {
    if (this->_grade == 1)
      throw Bureaucrat::GradeTooHighException();
    this->_grade--;
    std::cout << GREEN << "Bureaucrat " << this->_name
              << " grade incremented to " << this->_grade << RESET << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << "Bureaucrat " << this->_name
              << " couldn't increment grade because: " << e.what() << RESET
              << std::endl;
  }
}

void Bureaucrat::decrementGrade(void) {
  try {
    if (this->_grade == 150)
      throw Bureaucrat::GradeTooLowException();
    this->_grade++;
    std::cout << GREEN << "Bureaucrat " << this->_name
              << " grade decremented to " << this->_grade << RESET << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << "Bureaucrat " << this->_name
              << " couldn't decrement grade because: " << e.what() << RESET
              << std::endl;
  }
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(this);
  } catch (std::exception &e) {
    std::cout << RED << this->_name << " couldn't sign " << form.getName()
              << " because: " << e.what() << RESET << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << GREEN << this->_name << " executed " << form.getName() << RESET
              << std::endl;
  } catch (std::exception &e) {
    std::cout << RED << this->_name << " couldn't execute " << form.getName()
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
