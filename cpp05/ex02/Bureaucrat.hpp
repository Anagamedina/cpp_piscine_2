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

class Form;

class Bureaucrat{

  private:
	const std::string	_name;
	int					_grade; // Grade 1-150 (1=highest, 150=lowest)

  public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat& obj);
	// Destructor 
	virtual	~Bureaucrat();
	
	// Getters
	const std::string& getName() const;
	int getGrade() const;

	// Grade management (1=highest, 150=lowest)
	void incrementGrade();
	void decrementGrade();

	// Form management
	void signForm(Form& form);
	void executeForm(const Form& form);

	// Exceptions
	class GradeTooHighException : public std::exception{
	  public:
		virtual const char* what() const throw();
	};

	class  GradeTooLowException : public std::exception { 
	  public: 
		virtual const char* what() const throw();
	};

};

// Output operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
