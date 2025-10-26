/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hybrid.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/XX XX:XX:XX by anamedin         #+#    #+#             */
/*   Updated: 2025/01/XX XX:XX:XX by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

// Colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RED_BACKGROUND "\033[41m"

int main() {
    // 1️⃣ INTRO - User name
    std::string user;
    std::cout << BLUE << "Welcome to Vogon Headquarters!" << std::endl
              << RESET << "Zaphod Beeblebrox: " << GREEN
              << "Ah, what was your name again, bureaucrat? " << RESET;
    if (!std::getline(std::cin, user)) {
        std::cout << std::endl << RED << "Zaphod: Don't mess with me! Either work or leave." << RESET << std::endl;
        return 0;
    }

    // 2️⃣ CREATE OBJECTS
    Bureaucrat* jefe = new Bureaucrat(user, 1);
    Intern becario;
    
    std::cout << "The bureaucrat " << user << " has been employed with level 1." << std::endl;
    std::cout << CYAN << "\"A bureaucrat is someone who makes things work without anyone knowing how.\"" << RESET << std::endl;
    sleep(1);
    
    std::cout << "A new intern (Ford Prefect) has joined the department." << std::endl;
    std::cout << CYAN << "\"Don't Panic.\" - Ford Prefect" << RESET << std::endl;
    sleep(1);

    // 3️⃣ CREATE FORMS (Factory Pattern)
    std::cout << YELLOW << "\n--- CREATING FORMS ---" << RESET << std::endl;
    std::cout << CYAN << "\"Bureaucracy is the art of making the impossible, possible.\"" << RESET << std::endl;
    sleep(1);
    
    AForm* formularios[4];
    
    // Valid forms
    formularios[0] = becario.makeForm("presidential pardon", "Zaphod Beeblebrox");
    std::cout << CYAN << "\"A bureaucrat without forms is like a fish without water.\"" << RESET << std::endl;
    sleep(1);
    
    formularios[1] = becario.makeForm("robotomy request", "Marvin the Paranoid Android");
    std::cout << CYAN << "\"In space no one can hear you scream... especially if you're a bureaucrat.\"" << RESET << std::endl;
    sleep(1);
    
    formularios[2] = becario.makeForm("shrubbery creation", "Slartibartfast's Fjords");
    std::cout << CYAN << "\"Space is big. Really big.\"" << RESET << std::endl;
    sleep(1);
    
    // Invalid form (demonstrate exception)
    try {
        formularios[3] = becario.makeForm("impossible form", "Uncharted Territory");
    } catch (const std::exception& e) {
        std::cerr << "Intern error: " << e.what() << std::endl;
        std::cout << CYAN << "\"Bureaucracy: where dreams go to die... slowly.\"" << RESET << std::endl;
        formularios[3] = NULL;
    }

    // 4️⃣ PROCESS FORMS (Polymorphism)
    std::cout << YELLOW << "\n--- PROCESSING FORMS ---" << RESET << std::endl;
    std::cout << CYAN << "\"The answer to life, the universe and everything is 42.\"" << RESET << std::endl;
    sleep(1);
    
    for (int i = 0; i < 3; ++i) {
        if (formularios[i]) {
            try {
                std::cout << "\nProcessing: " << formularios[i]->getName() << std::endl;
                jefe->signForm(*formularios[i]);
                std::cout << CYAN << "\"The meaning of life is 42.\"" << RESET << std::endl;
                sleep(1);
                jefe->executeForm(*formularios[i]);
                std::cout << CYAN << "\"Earth is mostly harmless.\"" << RESET << std::endl;
                sleep(1);
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
                std::cout << CYAN << "\"Don't Panic.\"" << RESET << std::endl;
            }
        }
    }

    // 5️⃣ FUNNY ENDING
    std::cout << YELLOW << "\n--- FINAL ---" << RESET << std::endl;
    std::cout << jefe->getName() << ": " << YELLOW 
              << "Well done, everyone… it's already 15:30, time to leave before another form arrives." 
              << RESET << std::endl;
    std::cout << "The intern Ford Prefect wonders if future assignments might be less… apocalyptic." << std::endl;
    std::cout << CYAN << "\"Thanks for using the Hitchhiker's Guide to the Galaxy!\"" << RESET << std::endl;

    // 6️⃣ CLEANUP MEMORY
    std::cout << "\n--- CLEANUP ---" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (formularios[i]) {
            delete formularios[i];
        }
    }
    delete jefe;
    
    std::cout << "Program completed." << std::endl;
    return 0;
}
