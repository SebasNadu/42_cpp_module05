/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:58:16 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 17:16:58 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

std::string const Intern::_forms[Intern::_nForms] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern(void) { std::cout << "Intern created." << std::endl; }

Intern::Intern(Intern const &src) { *this = src; }

Intern::~Intern(void) { std::cout << "Intern fired." << std::endl; }

Intern &Intern::operator=(Intern const &rhs) {
  if (this != &rhs)
    *this = rhs;
  return *this;
}

char const *Intern::FormNotFoundException::what() const throw() {
  return "Form not found.";
}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
  size_t i(0);

  while (i < this->_nForms && formName != this->_forms[i])
    i++;
  try {
    switch (i) {
    case 0:
      std::cout << GREEN << "Intern creates:" << RESET << std::endl;
      return (new ShrubberyCreationForm(target));
    case 1:
      std::cout << GREEN << "Intern creates:" << RESET << std::endl;
      return (new RobotomyRequestForm(target));
    case 2:
      std::cout << GREEN << "Intern creates:" << RESET << std::endl;
      return (new PresidentialPardonForm(target));
    case 3:
      throw FormNotFoundException();
    }
  } catch (std::exception &e) {
    std::cerr << RED << formName << ": " << e.what() << RESET << std::endl;
  }
  return (NULL);
}
