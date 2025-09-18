/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:13:51 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 11:46:01 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default", 145, 137), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("Shrubbery creation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(obj),  _target(obj._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	if (this != &obj){
		Form::operator=(obj);
		_target = obj._target;
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw FormException();  // Form must be signed to execute
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();  // Bureaucrat grade too low to execute
	
	// Create file with ASCII tree art
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open()) { 
		file << "       &&& &&  & &&\n";
		file << "   && &\\/&\\|& ()|/ @, &&\n";
		file << "   &\\/(/&/&||/& /_/)_&/_&\n";
		file << " &() &\\/&|()|/&\\/ '%\" & ()\n";
		file << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
		file << "&&   && & &| &| /& & % ()& /&&\n";
		file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
		file << "     &&     \\|||\n";
		file << "             |||\n";
		file << "             |||\n";
		file << "             |||\n";
		file << "       , -=-~  .-^- _\n";
		file.close();	
		std::cout << "Shrubbery has been planted in " << _target << "_shrubbery" << std::endl;
	}
	else{
		std::cerr << "Error: could not create shrubbery file." << std::endl;
	}
}
