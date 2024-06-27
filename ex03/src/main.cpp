/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:11:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 17:24:54 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
  std::cout << GREEN << "\nWelcome to Bureaucracy Simulator 2024\n" << RESET;
  tic_tac(100000, 5);
  Intern intern;
  tic_tac(100000, 5);
  AForm *formPresidential = intern.makeForm("presidential pardon", "myself");
  tic_tac(100000, 5);
  AForm *formShrubbery = intern.makeForm("shrubbery creation", "planting");
  tic_tac(100000, 5);
  AForm *formRobotomy = intern.makeForm("robotomy request", "robotize_me");
  tic_tac(100000, 5);
  AForm *inexitentForm = intern.makeForm("Destroy bureaucrats", "Andy");
  tic_tac(100000, 5);
  Bureaucrat bureaucrat("Andy", 1);
  tic_tac(100000, 5);
  bureaucrat.executeForm(*formPresidential);
  tic_tac(100000, 5);
  bureaucrat.signForm(*formPresidential);
  tic_tac(100000, 5);
  bureaucrat.executeForm(*formPresidential);
  tic_tac(100000, 5);
  bureaucrat.executeForm(*formShrubbery);
  tic_tac(100000, 5);
  bureaucrat.signForm(*formShrubbery);
  tic_tac(100000, 5);
  bureaucrat.executeForm(*formShrubbery);
  tic_tac(100000, 5);
  bureaucrat.executeForm(*formRobotomy);
  tic_tac(100000, 5);
  bureaucrat.signForm(*formRobotomy);
  tic_tac(100000, 5);
  bureaucrat.executeForm(*formRobotomy);
  std::cout << "----------------------------------------" << std::endl;
  delete formPresidential;
  delete formRobotomy;
  delete formShrubbery;
  delete inexitentForm;
  return (0);
}
