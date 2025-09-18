/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/17 12:47:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	std::cout << "=== DEMOSTRACIÓN DEL FORM Y BUREAUCRAT ===" << std::endl << std::endl;
	
	// Test 1: Valid form and bureaucrat - should work
	try {
		std::cout << "--- Test 1: Caso exitoso ---" << std::endl;
		Form contract("Contrato de Trabajo", 10, 5);
		Bureaucrat manager("Manager Bob", 8);
		
		std::cout << contract << std::endl;
		std::cout << manager << std::endl;
		
		// Bob (grade 8) can sign (requires grade 10)
		contract.beSigned(manager);
		std::cout << "¡Formulario firmado exitosamente!" << std::endl;
		std::cout << contract << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- Test 2: Grado insuficiente ---" << std::endl;
	try {
		Form important("Documento Importante", 5, 3);
		Bureaucrat intern("Intern Jane", 15);
		
		std::cout << important << std::endl;
		std::cout << intern << std::endl;
		
		// Jane (grade 15) cannot sign (requires grade 5)
		important.beSigned(intern);
		std::cout << "¡Formulario firmado!" << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- Test 3: Formulario con grados inválidos ---" << std::endl;
	try {
		Form invalid("Invalid Form", 0, 200); // Grades out of range
		std::cout << "Formulario creado: " << invalid << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error al crear formulario: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- Test 4: Burócrata con grado inválido ---" << std::endl;
	try {
		Bureaucrat invalid("Invalid Bureaucrat", 200); // Grade out of range
		std::cout << "Burócrata creado: " << invalid << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error al crear burócrata: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== FIN DE LA DEMOSTRACIÓN ===" << std::endl;
	return 0;
}
