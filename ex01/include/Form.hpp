/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:01:38 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/26 13:13:22 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
  // Constructors
  Form(void);
  Form(Form const &src);
  Form(std::string const name);
  Form(int sign_grade, int exec_grade);
  Form(std::string const name, int sign_grade, int exec_grade);
  Form(std::string const name, bool is_signed, int sign_grade, int exec_grade);
  // Deconstructor
  ~Form(void);
  // Overload Operators
  Form &operator=(Form const &rhs);

  // Getters
  std::string const getName(void) const;
  bool getIsSigned(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;

  void beSigned(Bureaucrat *signer);

  class GradeTooLowException : public std::exception {
  public:
    virtual char const *what(void) const throw();
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual char const *what(void) const throw();
  };

private:
  std::string const _name;
  bool _is_signed;
  size_t const _sign_grade;
  size_t const _exec_grade;
};

std::ostream &operator<<(std::ostream &out, Form &form);
