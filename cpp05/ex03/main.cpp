/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/25 16:10:57 by anamedin         ###   ########.fr       */
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

int main(){
    // ============================================================================
    // 1. INTRODUCCIÓN INTERACTIVA - Entrada del nombre del usuario
    // ============================================================================
    std::string user;
    std::cout << BLUE << "Somewhere in the headoffices of Vogsphere, the President of the Galaxy, Zaphood Beeblebrox is welcoming the new head of the intergalactical Construction department." << std::endl << RESET << "Zaphood Beeblebrox: " << GREEN << "My apologies, but, what was your name again? " << std::endl << RESET; 
    
    if (!std::getline(std::cin, user)) {
        std::cout << std::endl << "Zaphood Beeblebrox: " << RED << "Don't screw with me...! You want the job or not?" << std::endl;
        return 0;
    }
    
    // ============================================================================
    // 2. CREACIÓN DE OBJETOS - Bureaucrat dinámico e Intern
    // ============================================================================
    Bureaucrat *headBureaucrat = new Bureaucrat(user, 1);
    std::cout << "The Bureaucrat " << user << " has been employed with level: 1!" << std::endl;
    
    sleep(1);
    std::srand(std::time(0)); 
    Intern intern;
    std::cout << "A new intern has been employed." << std::endl;
    
    int missionType = std::rand() % 2;
    std::cout << RED_BACKGROUND << "The fate of Earth is in the hands of " << headBureaucrat->getName() << " and some random intern..." << RESET << std::endl << std::endl;
    sleep(2);
    
    // ============================================================================
    // 3. FACTORY METHOD EN ACCIÓN - Creación de formularios con Intern
    // ============================================================================
    std::cout << YELLOW << "But before anything,.. office routine requires the creation of some forms to start off the day .." << RESET << std::endl;
    sleep(2);
    
    AForm* forms[4];
    forms[0] = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
    sleep(2);
    forms[1] = intern.makeForm("robotomy request", "Marvin the Paranoid Android");
    sleep(2);
    forms[2] = intern.makeForm("shrubbery creation", "VogonPoetryDepartment");
    sleep(2);

    try {
        forms[3] = intern.makeForm("impossible form", "Uncharted Territory");
    } catch (const std::exception& e) {
        std::cerr << "Intern error: " << e.what() << std::endl;
        forms[3] = NULL;
    }

    // ============================================================================
    // 4. NARRATIVA INTERACTIVA - Finales alternativos según missionType
    // ============================================================================
    try {
        if (missionType == 0) {
            std::cout << headBureaucrat->getName() << ": " << RED_BACKGROUND << "What is this,.. in this pile of Paperwork I just found a relocation requirement for Earth! .. quick, intern, make the relocation request ASAP!" << RESET << std::endl;
            sleep(2);
            AForm* relocationForm = intern.makeForm("relocation request", "Earth");

            if (relocationForm) {
                std::cout << "Relocation form created. Submitting to " << headBureaucrat->getName() << " for final signature..." << std::endl;
                sleep(1);
                headBureaucrat->signForm(*relocationForm);
                sleep(1);
                headBureaucrat->executeForm(*relocationForm);
                delete relocationForm;
            }
        } else {
            std::cout << RED_BACKGROUND << "Since the Earth relocation Form got lost in the pile of paperwork, Earth's doom is set; destruction is imminent, and our Bureaucrats are continuing utterly ignorant of the importance of the lost document..." << RESET << std::endl << std::endl;
        }

        // ============================================================================
        // 5. POLIMORFISMO Y ASOCIACIÓN - Procesamiento de formularios
        // ============================================================================
        std::cout << std::endl << YELLOW << "The usual forms processing continues..." << RESET << std::endl;
        for (int i = 0; i < 3; ++i) {
            if (forms[i]) {
                try {
                    std::cout << std::endl << "Processing " << forms[i]->getName() << " form:" << std::endl;
                    sleep(2);
                    headBureaucrat->signForm(*forms[i]);
                    sleep(2);
                    headBureaucrat->executeForm(*forms[i]);
                } catch (const std::exception& e) {
                    std::cout << "Form handling error: " << e.what() << std::endl;
                }
                delete forms[i];
            }
        }
        if (forms[3]) delete forms[3]; 
    } catch (const std::exception& e) {
        std::cerr << "Mission error: " << e.what() << std::endl;
    }

    // ============================================================================
    // 6. FINALIZACIÓN - Finales alternativos y limpieza de memoria
    // ============================================================================
    if (missionType == 0) {
        std::cout << std::endl << "The intern reflects, wondering if future assignments might be less... apocalyptic." << std::endl;
    } else {
        std::cout << headBureaucrat->getName() << ": " << YELLOW << " Well done everybody..., it is already 15:30, time to pack up and leave before some other form comes in.. " << RESET << std::endl; 
    }

    delete headBureaucrat;
    return 0;
}

/*
// ============================================================================
// MAIN ANTERIOR - VERSIÓN ORIGINAL (COMENTADO)
// ============================================================================

int main_original(){
    std::cout << BLUE << "=== INTERN AND FORM DEMONSTRATION ===" << RESET << std::endl << std::endl;

    // Create bureaucrats and intern
    Bureaucrat      highLevel(CYAN "High Manager" RESET, 3);
    Bureaucrat      lowLevel(CYAN "Low Clerk" RESET, 140);
    Intern          intern;

    std::cout << BLUE << "--- Test 1: Successful form creation and execution ---" << RESET << std::endl;

    // Create forms using Intern
    AForm* shrubbery = intern.makeForm("shrubbery creation", "garden");
    AForm* robotomy = intern.makeForm("robotomy request", "target");
    AForm* pardon = intern.makeForm("presidential pardon", "criminal");

    // Shrubbery Form - Individual try-catch
    if (shrubbery) {
        try {
            highLevel.signForm(*shrubbery);
            highLevel.executeForm(*shrubbery);
            std::cout << GREEN << "Shrubbery form successfully signed and executed!" << RESET << std::endl;
        } catch (const std::exception& e) {
            std::cout << RED << "Shrubbery Error: " << e.what() << RESET << std::endl;
        }
        delete shrubbery;
    }

    // Robotomy Form - Individual try-catch
    if (robotomy) {
        try {
            highLevel.signForm(*robotomy);
            highLevel.executeForm(*robotomy);
            std::cout << GREEN << "Robotomy form successfully signed and executed!" << RESET << std::endl;
        } catch (const std::exception& e) {
            std::cout << RED << "Robotomy Error: " << e.what() << RESET << std::endl;
        }
        delete robotomy;
    }

    // Pardon Form - Individual try-catch
    if (pardon) {
        try {
            highLevel.signForm(*pardon);
            highLevel.executeForm(*pardon);
            std::cout << GREEN << "Presidential pardon form successfully signed and executed!" << RESET << std::endl;
        } catch (const std::exception& e) {
            std::cout << RED << "Pardon Error: " << e.what() << RESET << std::endl;
        }
        delete pardon;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    std::cout << BLUE << "\n--- Test 2: Unknown form type ---" << RESET << std::endl;
    AForm* unknown = intern.makeForm("unknown form", "target");
    if (!unknown) {
        std::cout << RED << "Intern couldn't create unknown form!" << RESET << std::endl;
    } else {
        delete unknown;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    std::cout << BLUE << "\n--- Test 3: Low-level bureaucrat ---" << RESET << std::endl;
    AForm* lowForm = intern.makeForm("shrubbery creation", "test");
    if (lowForm) {
        try {
            lowLevel.signForm(*lowForm);
            lowLevel.executeForm(*lowForm);
            std::cout << GREEN << "Low-level bureaucrat successfully signed and executed!" << RESET << std::endl;
        } catch (const std::exception& e) {
            std::cout << RED << "Low-level bureaucrat Error: " << e.what() << RESET << std::endl;
        }
        delete lowForm;
    }

    std::cout << BLUE << "\n=== END OF DEMONSTRATION ===" << RESET << std::endl;
    return 0;
}

// ============================================================================
// DIFERENCIAS PRINCIPALES:
// ============================================================================
// 
// VERSIÓN NUEVA (ACTUAL):
// - Entrada interactiva del nombre del usuario
// - Narrativa con colores y pausas dramáticas
// - Creación dinámica del Bureaucrat con el nombre del usuario
// - Flujo de historia con finales alternativos
// - Manejo de errores más robusto
// - Experiencia de usuario más inmersiva
//
// VERSIÓN ANTERIOR (COMENTADA):
// - Bureaucrats estáticos predefinidos
// - Tests estructurados y secuenciales
// - Pausas manuales (ENTER para continuar)
// - Enfoque más técnico y educativo
// - Demostración clara de funcionalidades
//
// ============================================================================
*/
