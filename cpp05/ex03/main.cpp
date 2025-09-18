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
#include "Intern.hpp"
#include "Form.hpp"

int main(){
	std::cout << "=== INTERN AND FORM DEMONSTRATION ===" << std::endl << std::endl;
	
	try {
		// Create bureaucrats and intern
		Bureaucrat highLevel("High Manager", 3);
		Bureaucrat lowLevel("Low Clerk", 140);
		Intern intern;
		
		std::cout << "--- Test 1: Successful form creation and execution ---" << std::endl;
		
		// Create forms using Intern
		Form* shrubbery = intern.makeForm("shrubbery creation", "garden");
		Form* robotomy = intern.makeForm("robotomy request", "target");
		Form* pardon = intern.makeForm("presidential pardon", "criminal");
		
		if (shrubbery) {
			highLevel.signForm(*shrubbery);
			highLevel.executeForm(*shrubbery);
			delete shrubbery;
		}
		
		if (robotomy) {
			highLevel.signForm(*robotomy);
			highLevel.executeForm(*robotomy);
			delete robotomy;
		}
		
		if (pardon) {
			highLevel.signForm(*pardon);
			highLevel.executeForm(*pardon);
			delete pardon;
		}
		
		std::cout << "\n--- Test 2: Unknown form type ---" << std::endl;
		Form* unknown = intern.makeForm("unknown form", "target");
		if (unknown) {
			delete unknown;
		}
		
		std::cout << "\n--- Test 3: Low-level bureaucrat ---" << std::endl;
		Form* lowForm = intern.makeForm("shrubbery creation", "test");
		if (lowForm) {
			lowLevel.signForm(*lowForm);
			lowLevel.executeForm(*lowForm);
			delete lowForm;
		}
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== END OF DEMONSTRATION ===" << std::endl;
	return 0;
}
