/* ************************************************************************** */
/*                                                                            */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:14:38 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/25 23:18:32 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

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

  std::string const getName(void) const;
  size_t getGrade(void) const;
  void setGrade(int grade);

  void incrementGrade(void);
  void decrementGrade(void);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  std::string const _name;
  size_t _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);
