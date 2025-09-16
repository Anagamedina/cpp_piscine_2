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

//constructores 
Bureaucrat::Bureaucrat() : _name("Default"), _grade(42) {}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
	if (_grade < 1)
		throw GradeTooLowException();
	if (_grade > 150)
		throw GradeTooHighException();
}

//implementar cualquier intento de crear un Bureaucrat  con un grado invalido
//debe lanzar una excepcion 

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade){}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	if (this != &obj){
		_grade = obj._grade;
	}
	return (*this);
}
 
//destructor
Bureaucrat::~Bureaucrat(){}

//getter y setters
const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }




//creamos nuestras exepciones !!! TODO:
void Bureaucrat::incrementGrade(){
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade -= 1;
}



void Bureaucrat::decrementGrade(){
	if (_grade == 150)
		throw GradeTooLowException();
	else 
		_grade += 1;
}


//metodo what 

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

//sobrecarga del operator de insertion

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
	out<< obj.getName() << ", Bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return  out;
}
