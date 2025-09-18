/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:47:14 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 18:32:01 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern(){}

Intern::Intern(const Intern& copy){
	*this = copy;
}

Intern& Intern::operator=(const Intern& obj) { 
	(void)obj;
	return *this;
}

Intern::~Intern(){}

// Form creation method
Form* Intern::makeForm(const std::string& formName, const std::string& target){
	// Array of form names
	std::string formNames[3] = { 
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"
	};

	// Array of form creator function pointers
	Form* (*formCreators[3])(const std::string&) = {
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm
	};

	// Search for matching form name
	for (int i = 0; i < 3; i++){
		if (formName == formNames[i]){
			std::cout << "Intern creates " << formName << " form for " << target << std::endl;
			return formCreators[i](target);
		} 
	}
	
	// Form name not found
	std::cout << "Intern couldn't create form: " << formName << " (unknown form type)" << std::endl;
	return NULL;
}

// Static form creator functions
Form* Intern::createShrubberyForm(const std::string& target){
	return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomyForm(const std::string& target){
	return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialForm(const std::string& target){
	return new PresidentialPardonForm(target);
}



