/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/23 19:24:24 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

// Colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

int main(){
    std::cout << BLUE << "=== INTERN AND FORM DEMONSTRATION ===" << RESET << std::endl << std::endl;

    try {
        // Create bureaucrats and intern
        Bureaucrat highLevel(CYAN "High Manager" RESET, 3);
        Bureaucrat lowLevel(CYAN "Low Clerk" RESET, 140);
        Intern intern;

        std::cout << BLUE << "--- Test 1: Successful form creation and execution ---" << RESET << std::endl;

        // Create forms using Intern
        Form* shrubbery = intern.makeForm("shrubbery creation", "garden");
        Form* robotomy = intern.makeForm("robotomy request", "target");
        Form* pardon = intern.makeForm("presidential pardon", "criminal");

        if (shrubbery) {
            highLevel.signForm(*shrubbery);
            highLevel.executeForm(*shrubbery);
            std::cout << GREEN << "Shrubbery form successfully signed and executed!" << RESET << std::endl;
            delete shrubbery;
        }

        if (robotomy) {
            highLevel.signForm(*robotomy);
            highLevel.executeForm(*robotomy);
            std::cout << GREEN << "Robotomy form successfully signed and executed!" << RESET << std::endl;
            delete robotomy;
        }

        if (pardon) {
            highLevel.signForm(*pardon);
            highLevel.executeForm(*pardon);
            std::cout << GREEN << "Presidential pardon form successfully signed and executed!" << RESET << std::endl;
            delete pardon;
        }

        std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
        std::cin.get();

        std::cout << BLUE << "\n--- Test 2: Unknown form type ---" << RESET << std::endl;
        Form* unknown = intern.makeForm("unknown form", "target");
        if (!unknown) {
            std::cout << RED << "Intern couldn't create unknown form!" << RESET << std::endl;
        } else {
            delete unknown;
        }

        std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
        std::cin.get();

        std::cout << BLUE << "\n--- Test 3: Low-level bureaucrat ---" << RESET << std::endl;
        Form* lowForm = intern.makeForm("shrubbery creation", "test");
        if (lowForm) {
            lowLevel.signForm(*lowForm);
            lowLevel.executeForm(*lowForm);
            std::cout << RED << "Low-level bureaucrat could not execute the form if grade too low!" << RESET << std::endl;
            delete lowForm;
        }

    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== END OF DEMONSTRATION ===" << RESET << std::endl;
    return 0;
}
