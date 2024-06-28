/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:11:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/28 16:21:49 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

int main(void) {
  Bureaucrat *a;

  std::cout << GREEN << "\nBureaucrat test to fail: \n" << RESET;
  {
    a = NULL;
    try {
      a = new Bureaucrat(0);
    } catch (std::exception const &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat(151);
    } catch (std::exception const &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 50);
      a->setGrade(0);
    } catch (std::exception const &e) {
      std::cout << RED << "setGrade failed: " << e.what() << RESET << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 50);
      a->setGrade(151);
    } catch (std::exception const &e) {
      std::cout << RED << "setGrade failed: " << e.what() << RESET << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 1);
      std::cout << *a;
      a->incrementGrade();
    } catch (std::exception const &e) {
      std::cout << RED << "incrementGrade failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 150);
      std::cout << *a;
      a->decrementGrade();
    } catch (std::exception const &e) {
      std::cout << RED << "decrementGrade failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
  }
  std::cout << GREEN << "\nBureaucrat test to pass: \n" << RESET;
  {
    try {
      a = new Bureaucrat("BobTheGood", 50);
      std::cout << *a;
      a->incrementGrade();
      std::cout << *a;
      a->decrementGrade();
      std::cout << *a;
      Bureaucrat *b = new Bureaucrat(*a);
      std::cout << *b;
      b->setGrade(2);
      std::cout << *b;
      b->incrementGrade();
      std::cout << *b;
      Bureaucrat c;
      c = *b;
      std::cout << c;
      delete a;
      delete b;
    } catch (std::exception const &e) {
      std::cout << RED << "Bureaucrat test failed: " << e.what() << RESET
                << std::endl;
    }
  }
  return (0);
}
