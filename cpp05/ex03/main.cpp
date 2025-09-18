/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 17:04:04 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

int main(){
	std::cout << "=== DEMOSTRACIÓN DEL FORM Y BUREAUCRAT ===" << std::endl << std::endl;
	
	try {
		std::cout << "--- Test 1: Caso exitoso ---" << std::endl;
		Form contract("Contrato de Trabajo", 10, 5);
		Bureaucrat manager("Manager Bob", 8);


		ShrubberyCreationForm	form1("my_space");
		RobotomyRequestForm		form2("my_bath");
		PresidentialPardonForm  form3("my_tree");

		manager.signForm(form1);

		manager.executeForm(form1);
		std::cout << contract << std::endl;
		std::cout << manager << std::endl;
		
		contract.beSigned(manager);
		std::cout << "¡Formulario firmado exitosamente!" << std::endl;
		std::cout << contract << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	
	std::cout << "\n=== FIN DE LA DEMOSTRACIÓN ===" << std::endl;
	return 0;
}
