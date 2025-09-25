/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:24:57 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/25 15:33:35 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors 
AForm::AForm() : _name("Default"), _Signed(false), _gradeToSign(42), _gradeToExecute(42){}

AForm::AForm(const std::string name, int gradetosign, int gradetoexecute) :  _name(name), _Signed(false), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute) { 
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();  // Grade 1 is highest
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();   // Grade 150 is lowest
}

AForm::AForm(const AForm& obj): _name(obj._name), _Signed(obj._Signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute){
}

AForm& AForm::operator=(const AForm& obj){
	if (this != &obj){
		_Signed = obj._Signed;
	}
	return *this;
}

// Destructor
AForm::~AForm(){}

// Getters
const std::string& AForm::getName() const { 
	return _name;
}

bool AForm::getSigned() const {
	return _Signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const { 
	return _gradeToExecute;
}

// Sign form if bureaucrat grade is sufficient
void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= _gradeToSign)
		_Signed = true;
	else
		throw GradeTooLowException();
}

// Exception messages
const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too High";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too Low";
}

const char* AForm::FormException::what() const throw(){
	return "Form not signed or grade too low";
}

// Output operator
std::ostream& operator<<(std::ostream& out, const AForm& obj) { 
	out << "Form: " << obj.getName()
		<< "\nSigned: " << (obj.getSigned() ? "Yes" : "No")
		<< "\nGrade to Sign: " << obj.getGradeToSign()
		<< "\nGrade to Execute: " << obj.getGradeToExecute() << std::endl;
	return out;
}
