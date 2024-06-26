/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:11:23 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/26 16:37:10 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat *a;
  Form *f;

  std::cout << GREEN << "\nBureaucrat test to fail:\n" << RESET;
  {
    a = NULL;
    try {
      a = new Bureaucrat(0);
    } catch (std::exception &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat(151);
    } catch (std::exception &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 50);
      a->setGrade(0);
    } catch (std::exception &e) {
      std::cout << RED << "setGrade failed: " << e.what() << RESET << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 50);
      a->setGrade(151);
    } catch (std::exception &e) {
      std::cout << RED << "setGrade failed: " << e.what() << RESET << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 1);
      std::cout << *a << std::endl;
      a->incrementGrade();
    } catch (std::exception &e) {
      std::cout << RED << "incrementGrade failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
    a = NULL;
    try {
      a = new Bureaucrat("JuanTheBad", 150);
      std::cout << *a << std::endl;
      a->decrementGrade();
    } catch (std::exception &e) {
      std::cout << RED << "decrementGrade failed: " << e.what() << RESET
                << std::endl;
    }
    if (a)
      delete a;
  }
  std::cout << GREEN << "\nBureaucrat test to pass:\n" << RESET;
  {
    try {
      a = new Bureaucrat("BobTheGood", 50);
      std::cout << *a << std::endl;
      a->incrementGrade();
      std::cout << *a << std::endl;
      a->decrementGrade();
      std::cout << *a << std::endl;
      Bureaucrat *b = new Bureaucrat(*a);
      std::cout << *b << std::endl;
      b->setGrade(2);
      std::cout << *b << std::endl;
      b->incrementGrade();
      std::cout << *b << std::endl;
      Bureaucrat c = *b;
      delete a;
      delete b;
      std::cout << c << std::endl;
    } catch (std::exception &e) {
      std::cout << RED << "Bureaucrat test failed: " << e.what() << RESET
                << std::endl;
    }
  }
  std::cout << GREEN << "\nForm test to fail: \n";
  {
    f = NULL;
    try {
      f = new Form("A", 0, 50);
    } catch (std::exception &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (f)
      delete f;
    f = NULL;
    try {
      f = new Form("A", 151, 50);
    } catch (std::exception &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (f)
      delete f;
    f = NULL;
    try {
      f = new Form("A", 50, 0);
    } catch (std::exception &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (f)
      delete f;
    f = NULL;
    try {
      f = new Form("A", 50, 151);
    } catch (std::exception &e) {
      std::cout << RED << "Constructor default failed: " << e.what() << RESET
                << std::endl;
    }
    if (f)
      delete f;
    f = NULL;
    try {
      f = new Form("A", 50, 50);
      a = new Bureaucrat("Bob", 50);
      a->decrementGrade();
      f->beSigned(a);
    } catch (std::exception &e) {
      std::cout << RED << "beSigned failed: " << e.what() << RESET << std::endl;
    }
    if (f)
      delete f;
    if (a)
      delete a;
    f = NULL;
    a = NULL;
    try {
      f = new Form("A", 50, 50);
      a = new Bureaucrat("Bob", 50);
      a->signForm(*f);
      Bureaucrat b("Juan", 50);
      b.signForm(*f);
      b.decrementGrade();
      b.signForm(*f);
      f->beSigned(&b);
    } catch (std::exception &e) {
      std::cout << RED << "signForm failed: " << e.what() << RESET << std::endl;
    }
    if (f)
      delete f;
    if (a)
      delete a;
  }
  std::cout << GREEN << "\nForm test to pass:\n" << RESET;
  {
    try {
      f = NULL;
      f = new Form("A", 50, 50);
      Form f2(*f);
      a = new Bureaucrat("Juan", 50);
      a->signForm(*f);
      std::cout << *f << std::endl;
      std::cout << f2 << std::endl;
      f2.beSigned(a);
      std::cout << f2 << std::endl;
      delete f;
      delete a;
    } catch (std::exception &e) {
      std::cout << RED << "Form test failed: " << e.what() << RESET
                << std::endl;
    }
  }
  return (0);
}
