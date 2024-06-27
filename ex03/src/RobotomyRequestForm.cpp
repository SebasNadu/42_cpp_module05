/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:59:06 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 11:28:06 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

size_t RobotomyRequestForm::_count = 0;

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", false, 72, 45, "default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    : AForm("RobotomyRequestForm", false, 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {
  *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
  std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
  if (this != &rhs) {
    *this = RobotomyRequestForm(rhs.getTarget());
    this->_count = rhs.getCount();
  }
  return (*this);
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &form) {
  out << "Form " << form.getName() << " is ";
  if (form.getIsSigned())
    out << "signed";
  else
    out << "not signed";
  out << ". Sign grade: " << form.getSignGrade()
      << " Exec grade: " << form.getExecGrade() << std::endl;
  return (out);
}

size_t RobotomyRequestForm::getCount(void) const { return (this->_count); }

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (AForm::execute(executor)) {
    this->_robotomize();
    return (true);
  }
  return (false);
}

void RobotomyRequestForm::_robotomize(void) const {
  std::cout << "Drilling noises... Drrrrrrrrr...Drrrrrrrr....Drrrrrrrr....\n";
  if ((RobotomyRequestForm::_count++ & 1) == 0)
    std::cout << GREEN << this->getTarget()
              << " has been robotomized successfully" << RESET << std::endl;
  else
    std::cout << RED << "Robotomization of " << this->getTarget()
              << " has failed" << RESET << std::endl;
}
