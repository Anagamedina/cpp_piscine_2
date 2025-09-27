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
    std::cout << BLUE << "=== FORM AND BUREAUCRAT DEMONSTRATION ===" << RESET << std::endl << std::endl;

    // Create bureaucrats once
    Bureaucrat highLevel(CYAN "High Manager" RESET, 3);
    Bureaucrat lowLevel(CYAN "Low Clerk" RESET, 140);

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();    

    // Create different forms
    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("target");
    PresidentialPardonForm pardon("criminal");

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Shrubbery Form - Individual try-catch
    std::cout << BLUE << "\n--- Testing Shrubbery Creation Form ---" << RESET << std::endl;
    try {
        highLevel.signForm(shrubbery);
        highLevel.executeForm(shrubbery);
        std::cout << GREEN << "Shrubbery Creation Form signed and executed successfully!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Shrubbery Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Robotomy Form - Individual try-catch
    std::cout << BLUE << "\n--- Testing Robotomy Request Form ---" << RESET << std::endl;
    try {
        highLevel.signForm(robotomy);
        highLevel.executeForm(robotomy);
        std::cout << GREEN << "Robotomy Request Form signed and executed successfully!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Robotomy Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Pardon Form - Individual try-catch
    std::cout << BLUE << "\n--- Testing Presidential Pardon Form ---" << RESET << std::endl;
    try {
        highLevel.signForm(pardon);
        highLevel.executeForm(pardon);
        std::cout << GREEN << "Presidential Pardon Form signed and executed successfully!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Pardon Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Low-level bureaucrat test - Individual try-catch
    std::cout << BLUE << "\n--- Testing with low-level bureaucrat ---" << RESET << std::endl;
    try {
        lowLevel.signForm(shrubbery);
        lowLevel.executeForm(shrubbery);
        std::cout << GREEN << "Low-level bureaucrat successfully signed and executed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Low-level bureaucrat Error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== END OF DEMONSTRATION ===" << RESET << std::endl;
    return 0;
}

