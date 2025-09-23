/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/23 18:19:38 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

// Colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(){
    std::cout << BLUE << "=== DEMOSTRACIÓN DEL BUREAUCRAT ===" << RESET << std::endl << std::endl;

    // Test 1: Create valid bureaucrat
    std::cout << BLUE << "1. Creando un Bureaucrat válido:" << RESET << std::endl;
    try {
        Bureaucrat a("Juan", 42);
        std::cout << GREEN << a << RESET;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 2: Increment grade
    std::cout << BLUE << "\n2. Incrementando grado (subiendo en jerarquía):" << RESET << std::endl;
    try {
        Bureaucrat b("María", 5);
        std::cout << "Antes: " << b.getName() << " tiene grado " << b.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << GREEN << "Después: " << b.getName() << " tiene grado " << b.getGrade() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 3: Decrement grade
    std::cout << BLUE << "\n3. Decrementando grado (bajando en jerarquía):" << RESET << std::endl;
    try {
        Bureaucrat c("Pedro", 149);
        std::cout << "Antes: " << c.getName() << " tiene grado " << c.getGrade() << std::endl;
        c.decrementGrade();
        std::cout << GREEN << "Después: " << c.getName() << " tiene grado " << c.getGrade() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 4: Invalid grade too high
    std::cout << BLUE << "\n4. Intentando crear Bureaucrat con grado muy alto (0):" << RESET << std::endl;
    try {
        Bureaucrat d("Ana", 0);
        std::cout << d;
    } catch (const std::exception& e) {
        std::cout << RED << "Error capturado: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 5: Invalid grade too low
    std::cout << BLUE << "\n5. Intentando crear Bureaucrat con grado muy bajo (151):" << RESET << std::endl;
    try {
        Bureaucrat e("Luis", 151);
        std::cout << e;
    } catch (const std::exception& e) {
        std::cout << RED << "Error capturado: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 6: Increment at max grade
    std::cout << BLUE << "\n6. Intentando incrementar grado cuando ya está en el máximo (1):" << RESET << std::endl;
    try {
        Bureaucrat f("Jefe", 1);
        std::cout << "Antes: " << f;
        f.incrementGrade();
        std::cout << "Después: " << f;
    } catch (const std::exception& e) {
        std::cout << RED << "Error capturado: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 7: Decrement at min grade
    std::cout << BLUE << "\n7. Intentando decrementar grado cuando ya está en el mínimo (150):" << RESET << std::endl;
    try {
        Bureaucrat g("Novato", 150);
        std::cout << "Antes: " << g;
        g.decrementGrade();
        std::cout << "Después: " << g;
    } catch (const std::exception& e) {
        std::cout << RED << "Error capturado: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n--- Press ENTER to continue ---" << RESET;
    std::cin.get();

    // Test 8: Copy bureaucrat
    std::cout << BLUE << "\n8. Copiando un Bureaucrat:" << RESET << std::endl;
    try {
        Bureaucrat original("Original", 25);
        Bureaucrat copia(original);
        std::cout << GREEN << "Original: " << original << RESET;
        std::cout << GREEN << "Copia: " << copia << RESET;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== FIN DE LA DEMOSTRACIÓN ===" << RESET << std::endl;
    return 0;
}
