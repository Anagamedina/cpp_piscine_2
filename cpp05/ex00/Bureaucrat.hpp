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

#include <iostream>
#include <exception>

class Bureaucrat{

  private:
	const std::string	_name;
	int					_grade; //del 1 al 150

  public:
	//constructores
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat& obj);
	//destructores 
	virtual	~Bureaucrat();
	
	//setter y getters
	const std::string& getName() const;
	int getGrade() const;

	//funciones miembro para incrementar o decrementar el grado del burocrata
	void incrementGrade();
	void decrementGrade();

	//clases de excepciones
	//TODO: 
	//constructor que toma un mensaje y lo almacena 
	//explicit MiExepcion(const std::string& msg) : mensaje(mg){}
	//virtual const char* what() const noexcept override{return mensaje.c_str();}
	class GradeTooHighException : public std::exception{
	  public:
		virtual const char* what() const throw();
	};

	class  GradeTooLowException : public std::exception { 
	  public: 
		virtual const char* what() const throw();
	};

};

//sobrecarga del operador de insersion (<<)
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
