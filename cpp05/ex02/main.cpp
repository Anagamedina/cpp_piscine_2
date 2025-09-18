/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 17:04:04 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

int main(){
	std::cout << "=== FORM AND BUREAUCRAT DEMONSTRATION ===" << std::endl << std::endl;
	
	try {
		std::cout << "--- Test 1: Successful case ---" << std::endl;
		Bureaucrat highLevel("High Manager", 3);
		Bureaucrat lowLevel("Low Clerk", 140);
		
		// Create different forms
		ShrubberyCreationForm shrubbery("garden");
		RobotomyRequestForm robotomy("target");
		PresidentialPardonForm pardon("criminal");
		
		std::cout << "\n--- Testing Shrubbery Creation Form ---" << std::endl;
		highLevel.signForm(shrubbery);
		highLevel.executeForm(shrubbery);
		
		std::cout << "\n--- Testing Robotomy Request Form ---" << std::endl;
		highLevel.signForm(robotomy);
		highLevel.executeForm(robotomy);
		
		std::cout << "\n--- Testing Presidential Pardon Form ---" << std::endl;
		highLevel.signForm(pardon);
		highLevel.executeForm(pardon);
		
		std::cout << "\n--- Testing with low-level bureaucrat ---" << std::endl;
		lowLevel.signForm(shrubbery);
		lowLevel.executeForm(shrubbery);
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== END OF DEMONSTRATION ===" << std::endl;
	return 0;
}
