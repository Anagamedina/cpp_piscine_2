/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:24:57 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/17 12:48:12 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors 
Form::Form() : _name("Default"), _Signed(false), _gradeToSign(42), _gradeToExecute(42){}	// Default values

Form::Form(const std::string name, int gradetosign, int gradetoexecute) :  _name(name), _Signed(false), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute) { 
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();  // Grade 1 is highest
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();   // Grade 150 is lowest
}

Form::Form(const Form& obj): _name(obj._name), _Signed(obj._Signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute){}	// Copy constructor

Form& Form::operator=(const Form& obj){
	if (this != &obj){					// Self-assignment check
		_Signed = obj._Signed;			// Only copy sign status (others are const)
	}
	return *this;
}
// Destructor
Form::~Form(){}						// Default destructor

// Getters
const std::string& Form::getName() const { 
	return _name;					// Return form name
}

bool Form::getSigned() const {
	return _Signed;					// Return sign status
}

int Form::getGradeToSign() const {
	return _gradeToSign;			// Return required grade to sign
}

int Form::getGradeToExecute() const { 
	return _gradeToExecute;			// Return required grade to execute
}

// Sign form if bureaucrat grade is sufficient
void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= _gradeToSign)	// Check if bureaucrat has sufficient grade
		_Signed = true;					// Sign the form
	else
		throw GradeTooLowException();	// Throw exception if grade too low
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too High";		// Exception message
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too Low";		// Exception message
}

// Output operator
std::ostream& operator<<(std::ostream& out, const Form& obj) { 
	out << "Form: " << obj.getName()
		<< "\nSigned: " << (obj.getSigned() ? "Yes" : "No")
		<< "\nGrade to Sign: " << obj.getGradeToSign()
		<< "\nGrade to Execute: " << obj.getGradeToExecute() << std::endl;
	return out;
}
