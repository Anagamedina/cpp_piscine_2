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

Intern::Intern(){}

Intern::Intern(const Intern& copy){
	*this = copy;
}

Intern& Intern::operator=(const Intern& obj) { 
	
	(void)obj;
	return *this;
}

Intern::~Intern(){}

//funciones auxiliares

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
	std::string formNames[3] = { "RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};

	AForm* (*formCreators[3])(std::string) = {
		//funciones
	};

	for (int i; i < 3; i++){
		if (formName == formNames[i]){
			std::cout << "Intern creates" << formName << "form for" << target << std::endl;
			return //funcion auxiliar[i]
		} 
	}
}

//funcion especial makeform


