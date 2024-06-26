/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:27:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/26 20:32:16 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
    : _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150) {
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

AForm::AForm(AForm const &src)
    : _name(src.getName() + "_copy"), _is_signed(src.getIsSigned()),
      _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade()) {
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade;
  if (this->_is_signed)
    std::cout << ". Signed [x]." << std::endl;
  else
    std::cout << ". Signed [ ]." << std::endl;
}

AForm::AForm(std::string const name)
    : _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150) {
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

AForm::AForm(int sign_grade, int exec_grade)
    : _name("default"), _is_signed(false), _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (this->_sign_grade < 1 || this->_exec_grade < 1)
    throw AForm::GradeTooHighException();
  if (this->_sign_grade > 150 || this->_exec_grade > 150)
    throw AForm::GradeTooLowException();
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

AForm::AForm(std::string const name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (this->_sign_grade < 1 || this->_exec_grade < 1)
    throw AForm::GradeTooHighException();
  if (this->_sign_grade > 150 || this->_exec_grade > 150)
    throw AForm::GradeTooLowException();
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

AForm::AForm(std::string const name, bool is_signed, int sign_grade,
             int exec_grade)
    : _name(name), _is_signed(is_signed), _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (this->_sign_grade < 1 || this->_exec_grade < 1)
    throw AForm::GradeTooHighException();
  if (this->_sign_grade > 150 || this->_exec_grade > 150)
    throw AForm::GradeTooLowException();
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade;
  if (this->_is_signed)
    std::cout << ". Signed [x]." << std::endl;
  else
    std::cout << ". Signed [ ]." << std::endl;
}

AForm::~AForm(void) {
  std::cout << "Deconstructor called for Form: " << this->_name << std::endl;
}

// It's not possible to copy an abstract class object AForm.
AForm &AForm::operator=(AForm const &rhs) {
  std::cout << "Form assignment operator called" << std::endl;
  if (this != &rhs)
    this->_is_signed = rhs.getIsSigned();
  return (*this);
}

bool AForm::execute(Bureaucrat const &bureaucrat) const {
  if (!this->_is_signed) {
    throw AForm::FormNotSignedException();
    return (false);
  }
  if (bureaucrat.getGrade() > this->getExecGrade()) {
    throw AForm::GradeTooLowException();
    return (false);
  }
  return (true);
}

std::string const AForm::getName(void) const { return (this->_name); }

bool AForm::getIsSigned(void) const { return (this->_is_signed); }

size_t AForm::getSignGrade(void) const { return (this->_sign_grade); }

size_t AForm::getExecGrade(void) const { return (this->_exec_grade); }

std::string AForm::getTarget(void) const { return (this->_target); }

char const *AForm::GradeTooLowException::what(void) const throw() {
  return ("Grade is too low");
}

char const *AForm::GradeTooHighException::what(void) const throw() {
  return ("Grade is too high");
}

char const *AForm::FormNotSignedException::what(void) const throw() {
  return ("Form is not signed");
}

void AForm::beSigned(Bureaucrat *signer) {
  if (signer->getGrade() > this->_sign_grade)
    throw AForm::GradeTooLowException();
  else if (this->_is_signed)
    std::cout << this->_name << " Form is already signed." << std::endl;
  else {
    this->_is_signed = true;
    std::cout << this->_name << " Form was signed by " << signer->getName()
              << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, AForm &form) {
  out << "Form " << form.getName() << " Sign grade: " << form.getSignGrade()
      << " Exec grade: " << form.getExecGrade();
  if (form.getIsSigned())
    out << ". Signed [x]";
  else
    out << ". Signed [ ]";
  return (out);
}
