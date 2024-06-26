/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:06:31 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/26 16:06:33 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

class Form;

class Bureaucrat {
public:
  // Constructors
  Bureaucrat(void);
  Bureaucrat(std::string const name, int grade);
  Bureaucrat(std::string const name);
  Bureaucrat(int grade);
  Bureaucrat(Bureaucrat const &src);
  // Destructor
  ~Bureaucrat(void);
  // Overload operator=
  Bureaucrat &operator=(Bureaucrat const &rhs);

  // Getters
  std::string const getName(void) const;
  size_t getGrade(void) const;
  // Setters
  void setGrade(int grade);

  // Methods
  void incrementGrade(void);
  void decrementGrade(void);
  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

private:
  std::string const _name;
  size_t _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);
