/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/16 18:54:20 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main(){
	std::cout << "=== DEMOSTRACIÓN DEL BUREAUCRAT ===" << std::endl << std::endl;
	
	// Test 1: Create valid bureaucrat
	std::cout << "1. Creando un Bureaucrat válido:" << std::endl;
	try {
		Bureaucrat a("Juan", 42);
		std::cout << a;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	// Test 2: Increment grade (move up hierarchy)
	std::cout << "\n2. Incrementando grado (subiendo en jerarquía):" << std::endl;
	try {
		Bureaucrat b("María", 5);
		std::cout << "Antes: " << b.getName() << " tiene grado " << b.getGrade() << std::endl;
		b.incrementGrade(); // From 5 to 4
		std::cout << "Después: " << b.getName() << " tiene grado " << b.getGrade() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	// Test 3: Decrement grade (move down hierarchy)
	std::cout << "\n3. Decrementando grado (bajando en jerarquía):" << std::endl;
	try {
		Bureaucrat c("Pedro", 149);
		std::cout << "Antes: " << c.getName() << " tiene grado " << c.getGrade() << std::endl;
		c.decrementGrade(); // From 149 to 150
		std::cout << "Después: " << c.getName() << " tiene grado " << c.getGrade() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	// Test 4: Try to create bureaucrat with invalid grade (too high)
	std::cout << "\n4. Intentando crear Bureaucrat con grado muy alto (0):" << std::endl;
	try {
		Bureaucrat d("Ana", 0);
		std::cout << d;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 5: Try to create bureaucrat with invalid grade (too low)
	std::cout << "\n5. Intentando crear Bureaucrat con grado muy bajo (151):" << std::endl;
	try {
		Bureaucrat e("Luis", 151);
		std::cout << e;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 6: Try to increment when already at highest grade
	std::cout << "\n6. Intentando incrementar grado cuando ya está en el máximo (1):" << std::endl;
	try {
		Bureaucrat f("Jefe", 1);
		std::cout << "Antes: " << f;
		f.incrementGrade(); // This should throw exception
		std::cout << "Después: " << f;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 7: Try to decrement when already at lowest grade
	std::cout << "\n7. Intentando decrementar grado cuando ya está en el mínimo (150):" << std::endl;
	try {
		Bureaucrat g("Novato", 150);
		std::cout << "Antes: " << g;
		g.decrementGrade(); // This should throw exception
		std::cout << "Después: " << g;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 8: Copy bureaucrat
	std::cout << "\n8. Copiando un Bureaucrat:" << std::endl;
	try {
		Bureaucrat original("Original", 25);
		Bureaucrat copia(original);
		std::cout << "Original: " << original;
		std::cout << "Copia: " << copia;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== FIN DE LA DEMOSTRACIÓN ===" << std::endl;
	return 0;
}
