/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:37:38 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/06/27 11:14:39 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137) {
  this->setTarget("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
    : AForm("ShrubberyCreationForm", false, 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) {
  *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
  std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
  if (this != &rhs)
    *this = ShrubberyCreationForm(rhs.getTarget());
  return (*this);
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &form) {
  out << "Form " << form.getName() << " is ";
  if (form.getIsSigned())
    out << "signed";
  else
    out << "not signed";
  out << ". Sign grade: " << form.getSignGrade()
      << " Exec grade: " << form.getExecGrade() << std::endl;
  return (out);
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (AForm::execute(executor)) {
    this->_createTree();
    return (true);
  }
  return (false);
}

void ShrubberyCreationForm::_createTree(void) const {
  std::ofstream ofs;

  try {
    ofs.open((this->getTarget() + "_shrubbery").c_str(),
             std::ofstream::out | std::ofstream::app);
    if (!ofs.is_open())
      throw std::ofstream::failure("Failed to open file" + this->getTarget() +
                                   "_shrubbery");
    ofs << ShrubberyCreationForm::_tree;
    std::cout << "A Shrubbery has been planted in " << this->getTarget()
              << "_shrubbery" << std::endl;
    ofs.close();
  } catch (std::ofstream::failure &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}

std::string const ShrubberyCreationForm::_tree =
    "\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣠⣀⣠⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡴⣶⣿⡿⠛⠛⠛⠻⠯⣿⠿⢿⣻⣶⣤⣤⣄⣀⣀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣟⣿⣯⡿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠉⠙⠿⠿⢿⡷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⡾⠿⠚⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⢿⣿⠳⡦⠐⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣰⣾⠟⠁⠀⠀⠀⠀⢀⣤⢶⡀⠀⠀⠀⠀⠀⣠⠶⢾⡏⠓⡆⠀⠀⠀⠀⠐⠚⠛⠻⣿⣿⠷⣿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣼⡗⡾⠋⠉⠛⠀⠀⠀⣀⣴⣾⡉⡄⠀⠀⠀⠀⠀⠐⠾⣧⠀⡿⠃⠀⠳⣄⡀⠀⠀⠀⠀⠀⠀⠘⠻⡻⣿⣿⣿⢿⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⠉⠉⠁⠀⠀⠀⠀⠀⣤⡴⣏⣀⠀⢹⣿⣦⡄⠀⠀⠀⠠⣄⣹⣧⡇⠀⠀⠀⠀⠹⣦⠀⠀⠀⠀⢠⣀⠀⡇⠹⣟⣧⣼⣤⣤⣄⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⢀⣿⠛⡤⠤⠤⣄⠀⠀⠦⠤⣿⡄⠀⠙⣷⡌⣿⡀⠀⠀⠀⣴⢤⠻⣿⣿⡇⠀⠀⠀⢠⣴⠆⠘⣶⠤⠀⠀⠈⠓⢸⡄⠀⢹⣧⣤⣿⡛⢛⣇⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⢀⡀⣠⣤⣴⢿⣿⠳⣤⣬⣿⡝⠣⠀⠀⠀⠙⠀⠀⡄⠭⡇⠀⡀⠀⠀⠀⠀⢠⣿⣖⠄⠀⣤⠞⢫⡀⠀⠀⠈⠃⢿⣿⡟⠁⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⣠⣴⣿⡅⢠⡤⣄⣰⠋⢿⣷⠖⠀⠀⠀⠀⠈⠛⣿⣧⣦⣼⣦⡤⣴⡚⣿⣷⣶⣶⣾⣏⠽⠇⠀⠀⢲⣿⣁⣀⡶⠋⠀⠀⠳⠀⠀⠄⠀⠘⠿⣧⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⣿⣟⣿⣷⡟⢠⣼⣽⡷⢦⡁⠀⠀⠀⢀⣦⣶⣤⣘⣻⡆⠉⣿⣿⣤⣿⣿⡛⠻⣿⡷⣾⣿⢳⡄⠀⠀⢨⠟⠋⠴⡿⠲⣤⣤⡀⠀⠀⠀⠀⣤⣽⡇⠀⠀⠀\n"
    "⠀⠀⠀⢀⣀⣿⣿⣿⡿⠛⠛⠛⠃⠀⠀⠀⠠⣼⣛⣿⣷⣿⣿⣿⣆⠙⣟⡁⣰⣌⡙⢷⠀⠀⠀⢶⣟⣻⡷⣤⢀⡔⢦⡀⠀⠀⠀⠀⠀⠀⢹⣤⣄⠀⢸⡟⠒⢻⣦⡀⠀\n"
    "⠀⠀⠀⣠⣙⣿⣿⣏⠀⠀⠀⠀⢀⠀⠀⠀⣼⣿⠛⠋⢛⣛⣨⣍⢹⣿⣿⡟⠛⢿⣌⣿⣦⣄⢀⣼⣿⣿⣿⣿⣿⣿⢿⣭⣧⣦⠀⠀⠀⠀⠀⠈⠻⠆⢠⣭⢛⡟⣿⣿⡀\n"
    "⠀⠰⢿⣿⣿⡿⣿⣿⣷⡶⣴⠟⠃⠀⣰⠲⢿⣿⣦⣨⣿⡥⠈⠉⢿⡻⠗⢻⡆⢀⠀⠙⠛⢿⣻⡇⠀⢸⡟⠉⠀⠙⠂⠀⠉⠡⣅⠀⣄⣤⡴⠀⠀⠀⠀⢻⣿⣷⣿⣿⠀\n"
    "⠀⠀⣤⣽⣿⣋⡿⠟⠛⠟⠿⠁⢠⡬⣧⣴⡶⢽⡏⠉⠉⢿⡍⠁⢀⠁⠀⠠⡟⢮⣧⣀⠀⠀⢏⡇⠀⢸⠇⠀⠀⠀⢰⠀⠀⠴⠈⠛⢁⣰⡇⠀⠀⠀⠀⠀⣼⣿⠉⠀⠀\n"
    "⠀⠸⢿⣿⣿⡻⢀⣀⠀⠀⠀⢀⡨⠶⠾⠋⠀⠀⠈⠉⠀⠞⣷⠀⢸⡄⠀⢠⣀⠀⣿⠘⡆⠀⣿⣇⣀⡼⢰⡄⠀⣴⠋⠀⠀⠀⠀⠂⠘⠿⣷⡇⠀⠀⢀⣶⣋⣿⠀⠀⠀\n"
    "⢠⣄⣼⣿⣿⣿⣿⣥⣤⡀⠘⠋⢀⡀⢀⣄⣀⣀⡰⠚⠂⣠⣿⠄⠈⢳⣦⣈⣿⣿⣿⡀⣿⠀⡟⠉⣿⡿⣿⣦⡾⣷⠉⠀⠀⣀⡴⠄⠀⠀⠚⢀⠀⠀⠠⣽⣿⠁⠀⠀⠀\n"
    "⠘⢿⣞⢿⣿⢿⡽⠿⣭⣍⣀⡀⠀⣁⣈⠛⠙⠻⣦⣀⣠⣾⡟⠑⢒⣺⣿⣛⠿⣿⣿⣭⣿⣦⣿⣾⣹⣧⣼⠏⢀⡞⠀⠀⣰⣿⠁⠀⠀⠀⡀⠈⢗⡶⢰⣿⡷⠋⠀⠀⠀\n"
    "⠀⠀⠙⢿⣿⣾⣷⣄⡉⠙⠉⠑⠂⣉⡋⢿⣷⣦⣶⣿⣿⣵⣿⢾⠋⠛⣿⣷⣾⣿⣬⣿⣿⣿⣿⢿⣿⣿⡏⠠⡼⠃⢀⣰⣿⠁⠀⠀⠀⣈⠿⢿⢟⣀⣈⣿⡶⠀⠀⠀⠀\n"
    "⠀⠀⠀⢺⣿⢿⠿⣿⠆⢐⢀⣠⡤⢾⣟⣻⣟⣿⡛⣿⣿⣿⣿⡶⣆⡙⠛⣿⣿⣿⣿⣛⢻⣿⣿⣿⣿⡿⢷⣶⣇⣠⣿⡿⠀⣰⣶⠶⡛⠁⠀⠰⣻⣿⣿⠏⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠉⠿⠿⠙⣦⣼⡿⢿⣿⣦⣸⣿⣿⣿⣿⣞⣿⣿⣿⣿⣉⢿⣿⣿⣿⣋⣯⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⡷⠞⠉⣰⡾⠉⢠⣄⣶⣿⡿⠁⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣏⣺⣿⣿⡟⠛⢿⣺⡿⣿⡽⣿⣿⣿⣿⣷⣿⣿⠻⢿⣿⣿⣿⡿⣿⡿⢱⣼⣿⣴⣽⣿⣿⣅⣴⣶⣠⣤⡶⣾⣿⣿⠃⠁⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⢿⣿⣴⡤⡿⣿⠿⢦⣽⣿⣿⣿⣙⣿⣿⠓⠚⣻⣿⣿⣿⣿⣿⣿⣿⡏⣿⠿⣯⣍⢻⣿⠉⣹⠥⢀⡸⠿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⠳⣿⡿⠶⠾⢉⡛⢻⣿⣯⣽⣿⣿⣷⣿⣿⢻⣿⣿⣿⣿⣿⡿⣇⣠⣿⣿⣟⣻⣿⣾⣶⢿⣿⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⠻⣦⣤⡘⠻⣿⣿⢻⣿⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣹⣿⣿⣿⠟⠓⠛⠛⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡈⢻⢿⣿⣿⣿⣿⣻⣿⣿⣿⣻⣿⣟⣿⣿⣿⣿⡿⠛⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠀⠈⣿⣿⣿⣿⣿⣿⣿⣾⣿⣥⡿⠟⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⡟⣻⣿⣿⣄⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣤⣤⣤⣴⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⠿⠶⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣏⣿⣿⣿⡷⣿⣷⣶⣤⢄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠿⠛⠛⠛⠻⠿⠿⠟⠋⣉⣉⣿⠿⠿⠟⠛⠻⠁⠈⢟⠻⡿⠛⣻⣯⡿⣻⣿⣿⣿⠷⠧⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⢀⣀⠀⠀⠉⠻⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠉⠁⠉⠉⠑⠚⠳⠬⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
