/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:49:59 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/28 07:41:22 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", false, 25, 5, "default") {
  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
    : AForm("PresidentialPardonForm", false, 25, 5, target) {
  std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &src) {
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
  *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
  std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
  if (this != &rhs) {
    this->setTarget(rhs.getTarget());
  }
  return (*this);
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &form) {
  out << "Form " << form.getName() << " is ";
  if (form.getIsSigned())
    out << "signed";
  else
    out << "not signed";
  out << ". Sign grade: " << form.getSignGrade()
      << " Exec grade: " << form.getExecGrade() << std::endl;
  return (out);
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (AForm::execute(executor)) {
    this->_pardon();
    return (true);
  }
  return (false);
}

void PresidentialPardonForm::_pardon(void) const {
  std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox"
            << std::endl;
}
