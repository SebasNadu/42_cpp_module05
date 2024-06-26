/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:27:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/26 15:13:06 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
    : _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150) {
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

Form::Form(Form const &src)
    : _name(src._name + "_copy"), _is_signed(src._is_signed),
      _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) {
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade;
  if (this->_is_signed)
    std::cout << ". Signed [x]." << std::endl;
  else
    std::cout << ". Signed [ ]." << std::endl;
}

Form::Form(std::string const name)
    : _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150) {
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

Form::Form(int sign_grade, int exec_grade)
    : _name("default"), _is_signed(false), _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (this->_sign_grade < 1 || this->_exec_grade < 1)
    throw Form::GradeTooHighException();
  if (this->_sign_grade > 150 || this->_exec_grade > 150)
    throw Form::GradeTooLowException();
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

Form::Form(std::string const name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (this->_sign_grade < 1 || this->_exec_grade < 1)
    throw Form::GradeTooHighException();
  if (this->_sign_grade > 150 || this->_exec_grade > 150)
    throw Form::GradeTooLowException();
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade << ". Signed [ ]."
            << std::endl;
}

Form::Form(std::string const name, bool is_signed, int sign_grade,
           int exec_grade)
    : _name(name), _is_signed(is_signed), _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (this->_sign_grade < 1 || this->_exec_grade < 1)
    throw Form::GradeTooHighException();
  if (this->_sign_grade > 150 || this->_exec_grade > 150)
    throw Form::GradeTooLowException();
  std::cout << "Form " << this->_name
            << " created. Sign grade: " << this->_sign_grade
            << " Exec grade: " << this->_exec_grade;
  if (this->_is_signed)
    std::cout << ". Signed [x]." << std::endl;
  else
    std::cout << ". Signed [ ]." << std::endl;
}

Form::~Form(void) {
  std::cout << "Deconstructor called for Form: " << this->_name << std::endl;
}

Form &Form::operator=(Form const &rhs) {
  std::cout << "Form assignment operator called" << std::endl;
  if (this != &rhs)
    *this = Form(rhs.getName() + "_copy", rhs.getIsSigned(), rhs.getSignGrade(),
                 rhs.getExecGrade());
  return (*this);
}

std::string const Form::getName(void) const { return (this->_name); }

bool Form::getIsSigned(void) const { return (this->_is_signed); }

int Form::getSignGrade(void) const { return (this->_sign_grade); }

int Form::getExecGrade(void) const { return (this->_exec_grade); }

char const *Form::GradeTooLowException::what(void) const throw() {
  return ("Grade is too low");
}

char const *Form::GradeTooHighException::what(void) const throw() {
  return ("Grade is too high");
}

void Form::beSigned(Bureaucrat *signer) {
  if (signer->getGrade() > this->_sign_grade)
    throw Form::GradeTooLowException();
  else if (this->_is_signed)
    std::cout << this->_name << " Form is already signed." << std::endl;
  else {
    this->_is_signed = true;
    std::cout << this->_name << " Form was signed by " << signer->getName()
              << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, Form &form) {
  out << "Form " << form.getName() << " Sign grade: " << form.getSignGrade()
      << " Exec grade: " << form.getExecGrade();
  if (form.getIsSigned())
    out << ". Signed [x]";
  else
    out << ". Signed [ ]";
  return (out);
}
