/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:24:48 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 16:44:15 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
public:
  Intern(void);
  Intern(Intern const &src);
  ~Intern(void);

  Intern &operator=(Intern const &rhs);

  AForm *makeForm(std::string const &formName, std::string const &target);

  class FormNotFoundException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

private:
  static size_t const _nForms = 3;
  static std::string const _forms[_nForms];
};
