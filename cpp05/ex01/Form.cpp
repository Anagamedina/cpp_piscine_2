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
Form::Form() : _name("Default"), _Signed(false), _gradeToSign(42), _gradeToExecute(42){}

Form::Form(const std::string name, int gradetosign, int gradetoexecute) :  _name(name), _Signed(false), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute) { 
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();  // Grade 1 is highest
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();   // Grade 150 is lowest
}

Form::Form(const Form& obj): _name(obj._name), _Signed(obj._Signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute){
}

Form& Form::operator=(const Form& obj){
	if (this != &obj){
		_Signed = obj._Signed;
	}
	return *this;
}
// Destructor
Form::~Form(){}


// Getters
const std::string& Form::getName() const { 
	return _name;
}

bool Form::getSigned() const {
	return _Signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const { 
	return _gradeToExecute;
}


// Sign form if bureaucrat grade is sufficient
void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= _gradeToSign)
		_Signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too High";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too Low";
}

// Output operator

std::ostream& operator<<(std::ostream& out, const Form& obj) { 
	out << "Form: " << obj.getName()
		<< "\nSigned: " << (obj.getSigned() ? "Yes" : "No")
		<< "\nGrade to Sign: " << obj.getGradeToSign()
		<< "\nGrade to Execute: " << obj.getGradeToExecute() << std::endl;
	return out;
}
