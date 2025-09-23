/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/23 18:26:31 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// Colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(){
    std::cout << BLUE << "=== DEMOSTRACIÓN DEL FORM Y BUREAUCRAT ===" << RESET << std::endl << std::endl;

    // Test 1: Valid form and bureaucrat - should work
    try {
        std::cout << BLUE << "--- Test 1: Caso exitoso ---" << RESET << std::endl;
        Form contract("Contrato de Trabajo", 10, 5);
        Bureaucrat manager("Manager Bob", 8);

        std::cout << contract << std::endl;
        std::cout << manager << std::endl;

        // Bob (grade 8) can sign (requires grade 10)
        contract.beSigned(manager);
        std::cout << GREEN << "¡Formulario firmado exitosamente!" << RESET << std::endl;
        std::cout << contract << std::endl;

    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 2: Grado insuficiente
    try {
        std::cout << BLUE << "\n--- Test 2: Grado insuficiente ---" << RESET << std::endl;
        Form important("Documento Importante", 5, 3);
        Bureaucrat intern("Intern Jane", 15);

        std::cout << important << std::endl;
        std::cout << intern << std::endl;

        important.beSigned(intern);
        std::cout << GREEN << "¡Formulario firmado!" << RESET << std::endl;

    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 3: Formulario con grados inválidos
    try {
        std::cout << BLUE << "\n--- Test 3: Formulario con grados inválidos ---" << RESET << std::endl;
        Form invalid("Invalid Form", 0, 200);
        std::cout << GREEN << "Formulario creado: " << invalid << RESET << std::endl;

    } catch (const std::exception& e) {
        std::cout << RED << "Error al crear formulario: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 4: Burócrata con grado inválido
    try {
        std::cout << BLUE << "\n--- Test 4: Burócrata con grado inválido ---" << RESET << std::endl;
        Bureaucrat invalid("Invalid Bureaucrat", 200);
        std::cout << GREEN << "Burócrata creado: " << invalid << RESET << std::endl;

    } catch (const std::exception& e) {
        std::cout << RED << "Error al crear burócrata: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    std::cout << BLUE << "\n=== FIN DE LA DEMOSTRACIÓN ===" << RESET << std::endl;
    return 0;
}




/*#include <iostream>
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

	std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();
		
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
	
	std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();
	
	std::cout << "\n--- Test 3: Formulario con grados inválidos ---" << std::endl;
	try {
		Form invalid("Invalid Form", 0, 200); // Grades out of range
		std::cout << "Formulario creado: " << invalid << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error al crear formulario: " << e.what() << std::endl;
	}
	

	std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();
	
	
	std::cout << "\n--- Test 4: Burócrata con grado inválido ---" << std::endl;
	try {
		Bureaucrat invalid("Invalid Bureaucrat", 200); // Grade out of range
		std::cout << "Burócrata creado: " << invalid << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error al crear burócrata: " << e.what() << std::endl;
	}
	

	std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

	
	std::cout << "\n=== FIN DE LA DEMOSTRACIÓN ===" << std::endl;
	return 0;
}
*/