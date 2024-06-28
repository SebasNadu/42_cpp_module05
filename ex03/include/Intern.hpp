/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:24:48 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/28 08:54:45 by sebasnadu        ###   ########.fr       */
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
  typedef struct sForms {
    std::string const &formName;
    AForm *(*new_fn)(std::string const &);
  } tForms;
  static int const _nForms = 3;
  static tForms const _forms[_nForms];
};
