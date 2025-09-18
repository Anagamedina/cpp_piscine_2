/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:57:56 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 12:46:40 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), _target("Default_target") { }

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) { 
	if (this != &obj) { 
		AForm::operator=(obj);
		_target = obj._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const { 
	if (!getSigned())
		throw FormNotSignedExeption();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	//funcion especial
	if (std::rand() % 2 == 0) {
		std::cout << "noiiiiseeeee..." << std::endl;
		std::cout << "\"" << _target << "\" RObotomyyyy failed! \n" << std::endl;
	}
	else
		std::cout << "\"" << _target << "\" robotomyyyy failed!\n" << std::endl;
}


