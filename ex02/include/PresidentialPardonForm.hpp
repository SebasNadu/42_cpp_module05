/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:48:17 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 09:53:35 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(void);
  PresidentialPardonForm(std::string const target);
  PresidentialPardonForm(PresidentialPardonForm const &src);
  ~PresidentialPardonForm(void);

  PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

  bool execute(Bureaucrat const &executor) const;

private:
  void _pardon(void) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &form);
