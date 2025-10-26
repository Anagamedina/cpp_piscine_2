/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:28 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/16 18:55:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat{

  private:
	const std::string	_name;		// Bureaucrat's name (immutable)
	int					_grade;		// Grade 1-150 (1=highest, 150=lowest)

  public:
	// Constructors
	Bureaucrat();									// Default constructor
	Bureaucrat(const std::string name, int grade);	// Parameterized constructor
	Bureaucrat(const Bureaucrat& obj);				// Copy constructor
	Bureaucrat& operator=(const Bureaucrat& obj);	// Assignment operator
	// Destructor 
	virtual	~Bureaucrat();							// Virtual destructor
	
	// Getters
	const std::string& getName() const;			// Get bureaucrat's name
	int getGrade() const;							// Get bureaucrat's grade

	// Grade management (1=highest, 150=lowest)
	void incrementGrade();							// Increase grade (better position)
	void decrementGrade();							// Decrease grade (worse position)

	// Exceptions
	class GradeTooHighException : public std::exception{
	  public:
		virtual const char* what() const throw();	// Exception message
	};

	class  GradeTooLowException : public std::exception { 
	  public: 
		virtual const char* what() const throw();	// Exception message
	};

};

// Output operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
