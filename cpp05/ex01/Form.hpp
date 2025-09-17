/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:09:22 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/17 10:25:34 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string   _name;
		bool				_Signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const std::string name, int gradetosign, int gradetoexecute);
		Form(const& obj);
		Form& operator=(const Form& obj);
		//destructor
		virtual ~Form();

		//gettter setter
		const std::string& getName() const;
		bool getSigned() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;

		//cambiara el estado del formulario a firmado si la nota del burocrata
		//es lo suficiente alta es decir menor o igual que la requerida. 
		void besigned(const Bureaucrat& b);

		//clases de excepciones
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const Form& obj);



