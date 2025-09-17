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
	
	// Test 1: Crear un Bureaucrat válido
	std::cout << "1. Creando un Bureaucrat válido:" << std::endl;
	try {
		Bureaucrat a("Juan", 42);
		std::cout << a;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	// Test 2: Incrementar grado (subir en la jerarquía)
	std::cout << "\n2. Incrementando grado (subiendo en jerarquía):" << std::endl;
	try {
		Bureaucrat b("María", 5);
		std::cout << "Antes: " << b.getName() << " tiene grado " << b.getGrade() << std::endl;
		b.incrementGrade(); // De 5 a 4
		std::cout << "Después: " << b.getName() << " tiene grado " << b.getGrade() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	// Test 3: Decrementar grado (bajar en la jerarquía)
	std::cout << "\n3. Decrementando grado (bajando en jerarquía):" << std::endl;
	try {
		Bureaucrat c("Pedro", 149);
		std::cout << "Antes: " << c.getName() << " tiene grado " << c.getGrade() << std::endl;
		c.decrementGrade(); // De 149 a 150
		std::cout << "Después: " << c.getName() << " tiene grado " << c.getGrade() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	// Test 4: Intentar crear un Bureaucrat con grado inválido (muy alto)
	std::cout << "\n4. Intentando crear Bureaucrat con grado muy alto (0):" << std::endl;
	try {
		Bureaucrat d("Ana", 0);
		std::cout << d;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 5: Intentar crear un Bureaucrat con grado inválido (muy bajo)
	std::cout << "\n5. Intentando crear Bureaucrat con grado muy bajo (151):" << std::endl;
	try {
		Bureaucrat e("Luis", 151);
		std::cout << e;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 6: Intentar incrementar cuando ya está en el grado más alto
	std::cout << "\n6. Intentando incrementar grado cuando ya está en el máximo (1):" << std::endl;
	try {
		Bureaucrat f("Jefe", 1);
		std::cout << "Antes: " << f;
		f.incrementGrade(); // Esto debería lanzar excepción
		std::cout << "Después: " << f;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 7: Intentar decrementar cuando ya está en el grado más bajo
	std::cout << "\n7. Intentando decrementar grado cuando ya está en el mínimo (150):" << std::endl;
	try {
		Bureaucrat g("Novato", 150);
		std::cout << "Antes: " << g;
		g.decrementGrade(); // Esto debería lanzar excepción
		std::cout << "Después: " << g;
	} catch (const std::exception& e) {
		std::cout << "Error capturado: " << e.what() << std::endl;
	}
	
	// Test 8: Copia de Bureaucrat
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
