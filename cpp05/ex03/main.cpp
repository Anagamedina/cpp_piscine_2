/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/30 13:59:32 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/*#include <iostream>
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
    // 1️⃣ INTRO - Get user name
    std::string user;
    std::cout << BLUE << "Welcome to the Vogon Headquarters!" << std::endl
              << RESET << "Zaphod Beeblebrox: " << GREEN 
              << "Ah, right… what's your name again, bureaucrat? " << RESET;
    if (!std::getline(std::cin, user)) {
        std::cout << std::endl << RED << "Zaphod: Don't mess with me! Either work or leave." << RESET << std::endl;
        return 0;
    }

    // 2️⃣ CREATE BUREAUCRAT & INTERN
    Bureaucrat* headBureaucrat = new Bureaucrat(user, 1);
    std::cout << "The Bureaucrat " << user << " has been employed with level 1!" << std::endl;
    sleep(1);

    Intern intern;
    std::cout << "A new intern (Ford Prefect) has joined the department." << std::endl;
    sleep(1);

    int missionType = std::rand() % 2;
    std::cout << RED_BACKGROUND << "The fate of Earth lies in the hands of " 
              << headBureaucrat->getName() << " and a confused intern..." << RESET << std::endl << std::endl;
    sleep(2);

    // 3️⃣ CREATE FORMS
    AForm* forms[4];
    forms[0] = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
    sleep(1);
    forms[1] = intern.makeForm("robotomy request", "Marvin the Paranoid Android");
    sleep(1);
    forms[2] = intern.makeForm("shrubbery creation", "Slartibartfast's Fjords");
    sleep(1);
    try {
        forms[3] = intern.makeForm("impossible form", "Uncharted Territory");
    } catch (const std::exception& e) {
        std::cerr << "Intern error: " << e.what() << std::endl;
        forms[3] = NULL;
    }

    // 4️⃣ MISSION: Planetary Relocation
    try {
        if (missionType == 0) {
            std::cout << headBureaucrat->getName() << ": " << RED_BACKGROUND
                      << "Wait… a Planetary Relocation Request for Earth?! Intern, make it fast!" 
                      << RESET << std::endl;
            sleep(2);
            AForm* relocationForm = intern.makeForm("relocation request", "Earth");
            if (relocationForm) {
                headBureaucrat->signForm(*relocationForm);
                sleep(1);
                headBureaucrat->executeForm(*relocationForm);
                delete relocationForm;
            }
        } else {
            std::cout << RED_BACKGROUND 
                      << "Oops… the relocation form got lost! Earth's doom is imminent. The Bureaucrats remain blissfully unaware." 
                      << RESET << std::endl << std::endl;
        }

        // 5️⃣ PROCESS OTHER FORMS
        std::cout << YELLOW << "Processing regular forms..." << RESET << std::endl;
        for (int i = 0; i < 3; ++i) {
            if (forms[i]) {
                try {
                    std::cout << std::endl << "Handling form: " << forms[i]->getName() << std::endl;
                    sleep(1);
                    headBureaucrat->signForm(*forms[i]);
                    sleep(1);
                    headBureaucrat->executeForm(*forms[i]);
                } catch (const std::exception& e) {
                    std::cout << "Form error: " << e.what() << std::endl;
                }
                delete forms[i];
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Mission error: " << e.what() << std::endl;
    }

    // 6️⃣ ENDING
    if (missionType == 0) {
        std::cout << std::endl << "Intern Ford Prefect wonders if future assignments might be less… apocalyptic." << std::endl;
    } else {
        std::cout << headBureaucrat->getName() << ": " << YELLOW 
                  << "Well done, everyone… it's already 15:30, let's leave before another form arrives!" 
                  << RESET << std::endl;
    }

    delete headBureaucrat;
    return 0;
}
*/


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_es.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:10:00 by anamedin         #+#    #+#             */
/*   Updated: 2025/09/30 18:10:00 by anamedin         ###   ########.fr       */
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
    // 1️⃣ INTRO - Nombre del usuario
    std::string user;
    std::cout << BLUE << "¡Bienvenido a la sede Vogon!" << std::endl
              << RESET << "Zaphod Beeblebrox: " << GREEN
              << "Ah, ¿cómo te llamabas, burócrata? " << RESET;
    if (!std::getline(std::cin, user)) {
        std::cout << std::endl << RED << "Zaphod: ¡No me hagas perder el tiempo! Trabaja o vete." << RESET << std::endl;
        return 0;
    }

    // 2️⃣ CREAR BUREAUCRAT & INTERN
    Bureaucrat* jefe = new Bureaucrat(user, 1);
    std::cout << "El burócrata " << user << " ha sido contratado con nivel 1." << std::endl;
    sleep(1);

    Intern becario;
    std::cout << "Un nuevo becario (Ford Prefect) se ha unido al departamento." << std::endl;
    sleep(1);

    int tipoMision = std::rand() % 2;
    std::cout << RED_BACKGROUND << "El destino de la Tierra depende de "
              << jefe->getName() << " y un becario confuso..." << RESET << std::endl << std::endl;
    sleep(2);

    // 3️⃣ CREAR FORMULARIOS
    AForm* formularios[4];
    formularios[0] = becario.makeForm("presidential pardon", "Zaphod Beeblebrox");
    sleep(1);
    formularios[1] = becario.makeForm("robotomy request", "Marvin el Androide Paranoico");
    sleep(1);
    formularios[2] = becario.makeForm("shrubbery creation", "Fiordos de Slartibartfast");
    sleep(1);
    try {
        formularios[3] = becario.makeForm("formulario imposible", "Territorio Desconocido");
    } catch (const std::exception& e) {
        std::cerr << "Error del becario: " << e.what() << std::endl;
        formularios[3] = NULL;
    }

    // 4️⃣ MISION: Reubicación Planetaria
    try {
        if (tipoMision == 0) {
            std::cout << jefe->getName() << ": " << RED_BACKGROUND
                      << "¡Un formulario de reubicación de la Tierra! Becario, ¡rápido!"
                      << RESET << std::endl;
            sleep(2);
            AForm* formReubicacion = becario.makeForm("relocation request", "Tierra");
            if (formReubicacion) {
                jefe->signForm(*formReubicacion);
                sleep(1);
                jefe->executeForm(*formReubicacion);
                delete formReubicacion;
            }
        } else {
            std::cout << RED_BACKGROUND
                      << "Ups… el formulario se perdió entre el papeleo. La Tierra está condenada. Los burócratas siguen ignorando su importancia."
                      << RESET << std::endl << std::endl;
        }

        // 5️⃣ PROCESAR OTROS FORMULARIOS
        std::cout << YELLOW << "Procesando formularios habituales..." << RESET << std::endl;
        for (int i = 0; i < 3; ++i) {
            if (formularios[i]) {
                try {
                    std::cout << std::endl << "Procesando formulario: " << formularios[i]->getName() << std::endl;
                    sleep(1);
                    jefe->signForm(*formularios[i]);
                    sleep(1);
                    jefe->executeForm(*formularios[i]);
                } catch (const std::exception& e) {
                    std::cout << "Error en el formulario: " << e.what() << std::endl;
                }
                delete formularios[i];
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error en la misión: " << e.what() << std::endl;
    }

    // 6️⃣ FINAL
    if (tipoMision == 0) {
        std::cout << std::endl << "El becario Ford Prefect se pregunta si las futuras asignaciones serán menos… apocalípticas." << std::endl;
    } else {
        std::cout << jefe->getName() << ": " << YELLOW
                  << "Bien hecho, todos… son las 15:30, es hora de irse antes de que llegue otro formulario."
                  << RESET << std::endl;
    }

    delete jefe;
    return 0;
}



/*#include <iostream>
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
*/
