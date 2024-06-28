/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:58:16 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/28 08:59:44 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) { std::cout << "Intern constructor called" << std::endl; }

Intern::Intern(Intern const &src) {
  std::cout << "Intern copy constructor called" << std::endl;
  *this = src;
}

Intern::~Intern(void) { std::cout << "Intern fired." << std::endl; }

Intern &Intern::operator=(Intern const &rhs) {
  std::cout << "Intern assignment operator called" << std::endl;
  (void)rhs;
  return (*this);
}

char const *Intern::FormNotFoundException::what() const throw() {
  return "Form not found.";
}

static AForm *newPresidentialForm(std::string const &target) {
  return (new PresidentialPardonForm(target));
}

static AForm *newRobotomyForm(std::string const &target) {
  return (new RobotomyRequestForm(target));
}

static AForm *newShrubberyForm(std::string const &target) {
  return (new ShrubberyCreationForm(target));
}

Intern::tForms const Intern::_forms[Intern::_nForms] = {
    {"shrubbery creation", newShrubberyForm},
    {"robotomy request", newRobotomyForm},
    {"presidential pardon", newPresidentialForm}};

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
  AForm *createdForm = NULL;

  try {
    for (int i = 0; i < this->_nForms; ++i) {
      if (this->_forms[i].formName == formName) {
        createdForm = this->_forms[i].new_fn(target);
        std::cout << GREEN << "Intern creates:" << RESET << std::endl;
        break;
      }
    }
    if (!createdForm)
      throw FormNotFoundException();
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << ": " << formName << RESET << std::endl;
  }
  return (createdForm);
}
