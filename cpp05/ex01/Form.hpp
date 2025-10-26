/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:09:22 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/25 15:28:40 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string   _name;			// Form name (immutable)
		bool				_Signed;		// Sign status
		const int			_gradeToSign;	// Required grade to sign (immutable)
		const int			_gradeToExecute; // Required grade to execute (immutable)

	public:
		Form();													// Default constructor
		Form(const std::string name, int gradetosign, int gradetoexecute); // Parameterized constructor
		Form(const Form& obj);									// Copy constructor
		Form& operator=(const Form& obj);						// Assignment operator
		// Destructor
		~Form();												// Destructor

		// Getters
		const 	std::string& getName() const;					// Get form name
		bool 	getSigned() const;								// Get sign status
		int		getGradeToSign() const;							// Get required grade to sign
		int 	getGradeToExecute() const;						// Get required grade to execute

		// Sign form if bureaucrat has sufficient grade 
		void beSigned(const Bureaucrat& b);					// Sign form by bureaucrat

		// Exceptions
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();		// Exception message
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();		// Exception message
		};

};

std::ostream& operator<<(std::ostream& out, const Form& obj);



