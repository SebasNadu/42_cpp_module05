/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:55:51 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/28 09:24:38 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(std::string const target);
  RobotomyRequestForm(RobotomyRequestForm const &src);
  ~RobotomyRequestForm(void);

  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

  bool execute(Bureaucrat const &executor) const;

private:
  void _robotomize(void) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &form);
