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

//constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery creation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj),  _target(obj._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	if (this != &obj){
		AForm::operator=(obj);
		_target = obj._target;
	}
	return *this;
}

//destructors

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getSigned())
		throw FormException();
	if (executor.getGrade() > getGradeToExecute())
		throw FormException();
		throw GradeTooLowException();
	//creamos en archivooo con ofstream class 
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
		std::cout << "The file" << _target << "_shubbery" << std::endl;
	}
	else{
		std::cerr << "Error: could not open file." << std::endl;
	}

}
