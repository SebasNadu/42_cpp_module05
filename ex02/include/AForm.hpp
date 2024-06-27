/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:01:38 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 11:40:02 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
  // Constructors
  AForm(void);
  AForm(AForm const &src);
  AForm(std::string const name);
  AForm(int sign_grade, int exec_grade);
  AForm(std::string const name, int sign_grade, int exec_grade);
  AForm(std::string const name, bool is_signed, int sign_grade, int exec_grade);
  AForm(std::string const name, bool is_signed, int sign_grade, int exec_grade,
        std::string target);
  virtual ~AForm(void);
  // Overload Operators
  AForm &operator=(AForm const &rhs);

  // Getters
  std::string const getName(void) const;
  bool getIsSigned(void) const;
  size_t getSignGrade(void) const;
  size_t getExecGrade(void) const;
  std::string getTarget(void) const;
  void setTarget(std::string target);

  void beSigned(Bureaucrat *signer);
  virtual bool execute(Bureaucrat const &executor) const = 0;

  class GradeTooLowException : public std::exception {
  public:
    virtual char const *what(void) const throw();
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual char const *what(void) const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual char const *what(void) const throw();
  };

private:
  std::string const _name;
  bool _is_signed;
  size_t const _sign_grade;
  size_t const _exec_grade;
  std::string _target;
};

std::ostream &operator<<(std::ostream &out, AForm &form);
