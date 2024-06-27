/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:11:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 13:12:59 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <unistd.h>

static void tic_tac(int usleep_time, int duration) {
  std::cout << std::unitbuf;
  for (int i = 0; i < duration; i++) {
    std::cout << ".";
    usleep(usleep_time);
  }
  std::cout << std::nounitbuf;
  std::cout << std::endl;
}

int main(void) {

  std::cout << YELLOW << "\nForm creation test\n" << RESET;
  tic_tac(100000, 5);
  PresidentialPardonForm form("Pardon_me");
  tic_tac(100000, 5);
  ShrubberyCreationForm form2("planting");
  tic_tac(100000, 5);
  RobotomyRequestForm form3("robotize_me");

  std::cout << YELLOW << "\nBureaucrat creation test\n" << RESET;
  tic_tac(100000, 5);
  Bureaucrat juan;
  tic_tac(100000, 5);
  Bureaucrat bob("bob", 1);

  std::cout << YELLOW << "\nUnsigned form execution test\n" << RESET;
  tic_tac(100000, 5);
  juan.executeForm(form);
  tic_tac(100000, 5);
  bob.executeForm(form);
  tic_tac(100000, 5);
  bob.executeForm(form2);
  tic_tac(100000, 5);
  bob.executeForm(form3);

  std::cout << YELLOW << "\nForm signing test\n" << RESET;
  tic_tac(100000, 5);
  juan.signForm(form);
  tic_tac(100000, 5);
  bob.signForm(form);
  tic_tac(100000, 5);
  bob.signForm(form3);
  tic_tac(100000, 5);
  bob.signForm(form2);

  std::cout << YELLOW << "\nSigned form execution test\n" << RESET;
  tic_tac(100000, 5);
  juan.executeForm(form);
  tic_tac(100000, 5);
  bob.executeForm(form);
  tic_tac(100000, 5);
  bob.executeForm(form3);
  tic_tac(100000, 5);
  bob.executeForm(form2);

  std::cout << YELLOW << "\nBureaucrat increment/decrement grade test\n"
            << RESET;
  tic_tac(100000, 5);
  std::cout << juan << std::endl;
  tic_tac(100000, 5);
  std::cout << bob << std::endl;
  tic_tac(100000, 5);
  bob.incrementGrade();
  bob.incrementGrade();
  bob.incrementGrade();
  juan.decrementGrade();
  juan.decrementGrade();
  juan.decrementGrade();
  tic_tac(100000, 5);
  std::cout << juan << std::endl;
  tic_tac(100000, 5);
  std::cout << bob << std::endl;

  std::cout << YELLOW << "\nTest Form exec limits\n" << RESET;
  tic_tac(100000, 5);
  juan.setGrade(20);
  std::cout << juan << std::endl;
  tic_tac(100000, 5);
  juan.executeForm(form);
  tic_tac(100000, 5);
  juan.executeForm(form2);
  tic_tac(100000, 5);
  juan.executeForm(form3);

  return (0);
}
