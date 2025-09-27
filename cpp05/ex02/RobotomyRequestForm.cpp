/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:57:56 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/25 15:45:12 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Constructors
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

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const { 
	if (!getSigned())
		throw FormException();  // Form must be signed to execute
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();  // Bureaucrat grade too low to execute
	
	// 50% chance of success
	std::srand((unsigned int)(std::time(0)));  // Seed random number generator
	if (std::rand() % 2 == 0) {
		std::cout << "Drilling noises... *BZZZZZZZZ*" << std::endl;
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	}
	else {
		std::cout << "Robotomy failed for " << _target << std::endl;
	}
}


