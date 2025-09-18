/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:37:27 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 16:52:49 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : Form("Default", 25, 5 ), _target("Default_target"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("Presidential Pardon", 25, 5 ), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form(obj), _target(obj._target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	if (this != &obj){
		Form::operator=(obj);
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
