/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:08:22 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 08:53:02 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(std::string const target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  ~ShrubberyCreationForm(void);

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

  bool execute(Bureaucrat const &executor) const;

private:
  void _createTree(void) const;
  static std::string const _tree;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &form);
