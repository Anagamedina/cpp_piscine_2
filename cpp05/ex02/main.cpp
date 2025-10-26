/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/23 18:51:59 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




/*
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(){
	std::cout << "=== FORM AND BUREAUCRAT DEMONSTRATION ===" << std::endl << std::endl;
	
	try {
		std::cout << "--- Test 1: Successful case ---" << std::endl;
		Bureaucrat highLevel("High Manager", 3);
		Bureaucrat lowLevel("Low Clerk", 140);

		std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    	std::cin.get();	
		// Create different forms
		ShrubberyCreationForm shrubbery("garden");
		RobotomyRequestForm robotomy("target");
		PresidentialPardonForm pardon("criminal");

		 std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    	std::cin.get();
		
		std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
		highLevel.signForm(shrubbery);
		highLevel.executeForm(shrubbery);

		 std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    	std::cin.get();
		
		std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
		highLevel.signForm(robotomy);
		highLevel.executeForm(robotomy);

		 std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    	std::cin.get();
		
		std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
		highLevel.signForm(pardon);
		highLevel.executeForm(pardon);

		std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    	std::cin.get();
		
		std::cout << "\n--- Testing with low-level bureaucrat ---" << std::endl;
		lowLevel.signForm(shrubbery);
		lowLevel.executeForm(shrubbery);
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== END OF DEMONSTRATION ===" << std::endl;
	return 0;
}*/


#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

// Colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

int main(){
    std::cout << BLUE << "=== FORM AND BUREAUCRAT DEMONSTRATION ===" << RESET << std::endl;

    // Create bureaucrats
    Bureaucrat highLevel("High Manager", 3);
    Bureaucrat lowLevel("Low Clerk", 140);
    
    std::cout << CYAN << "Created bureaucrats:" << RESET << std::endl;
    std::cout << highLevel << lowLevel << std::endl;

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Create different forms
    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("target");
    PresidentialPardonForm pardon("criminal");
    
    std::cout << CYAN << "Created forms:" << RESET << std::endl;
    std::cout << shrubbery << robotomy << pardon << std::endl;
    
    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 1: Shrubbery Form with high-level bureaucrat
    std::cout << BLUE << "\n--- Test 1: Shrubbery Creation Form ---" << RESET << std::endl;
    try {
        highLevel.signForm(shrubbery);
        std::cout << CYAN << "🌳 EXECUTING SHRUBBERY FORM:" << RESET << std::endl;
        highLevel.executeForm(shrubbery);
        std::cout << GREEN << "✅ Shrubbery Creation Form signed and executed successfully!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "❌ Shrubbery Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 2: Robotomy Form with high-level bureaucrat
    std::cout << BLUE << "\n--- Test 2: Robotomy Request Form ---" << RESET << std::endl;
    try {
        highLevel.signForm(robotomy);
        std::cout << YELLOW << "🤖 EXECUTING ROBOTOMY FORM:" << RESET << std::endl;
        highLevel.executeForm(robotomy);
        std::cout << GREEN << "✅ Robotomy Request Form signed and executed successfully!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "❌ Robotomy Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 3: Presidential Pardon Form with high-level bureaucrat
    std::cout << BLUE << "\n--- Test 3: Presidential Pardon Form ---" << RESET << std::endl;
    try {
        highLevel.signForm(pardon);
        std::cout << GREEN << "🏛️ EXECUTING PRESIDENTIAL PARDON FORM:" << RESET << std::endl;
        highLevel.executeForm(pardon);
        std::cout << GREEN << "✅ Presidential Pardon Form signed and executed successfully!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "❌ Pardon Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 4: Low-level bureaucrat (should fail)
    std::cout << BLUE << "\n--- Test 4: Low-level bureaucrat (should fail) ---" << RESET << std::endl;
    try {
        lowLevel.signForm(shrubbery);
        std::cout << CYAN << "🌳 EXECUTING SHRUBBERY FORM (Low-level bureaucrat):" << RESET << std::endl;
        lowLevel.executeForm(shrubbery);
        std::cout << GREEN << "✅ Low-level bureaucrat successfully signed and executed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "❌ Low-level bureaucrat Error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== END OF DEMONSTRATION ===" << RESET << std::endl;
    return 0;
}

