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
		throw GradeTooHighException();  // Grado 1 es el más alto, <1 es demasiado alto
	if (_grade > 150)
		throw GradeTooLowException();   // Grado 150 es el más bajo, >150 es demasiado bajo
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
	if (_grade <= 1)
		throw GradeTooHighException();  // Si ya está en grado 1 (máximo), no puede subir más
	else
		_grade -= 1;  // Decrementar el número = subir de grado
}



void Bureaucrat::decrementGrade(){
	if (_grade >= 150)
		throw GradeTooLowException();   // Si ya está en grado 150 (mínimo), no puede bajar más
	else 
		_grade += 1;  // Incrementar el número = bajar de grado
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
