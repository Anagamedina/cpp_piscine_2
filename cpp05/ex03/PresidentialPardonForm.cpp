/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:37:27 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/25 16:08:33 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5 ), _target("Default_target"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", 25, 5 ), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), _target(obj._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	if (this != &obj){
		AForm::operator=(obj);
		_target = obj._target;
	}
	return *this;
}



// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const { 
	if (!getSigned())
		throw FormException();  // Form must be signed to execute
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();  // Bureaucrat grade too low to execute
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
