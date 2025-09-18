/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:01:08 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/16 18:53:41 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors 
Bureaucrat::Bureaucrat() : _name("Default"), _grade(42) {}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
	if (_grade < 1)
		throw GradeTooHighException();  // Grade 1 is highest, <1 is too high
	if (_grade > 150)
		throw GradeTooLowException();   // Grade 150 is lowest, >150 is too low
}

// Invalid grade throws exception 

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade){}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	if (this != &obj){
		_grade = obj._grade;
	}
	return (*this);
}
 
// Destructor
Bureaucrat::~Bureaucrat(){}

// Getters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }




// Grade management methods
void Bureaucrat::incrementGrade(){
	if (_grade <= 1)
		throw GradeTooHighException();  // Already at highest grade (1)
	else
		_grade -= 1;  // Decrease number = increase grade level
}



void Bureaucrat::decrementGrade(){
	if (_grade >= 150)
		throw GradeTooLowException();   // Already at lowest grade (150)
	else 
		_grade += 1;  // Increase number = decrease grade level
}

// Form management methods
void Bureaucrat::signForm(Form& form){
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form){
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}


// Exception messages 

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

// Output operator

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
	out<< obj.getName() << ", Bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return  out;
}
