/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:09:22 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 11:01:35 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string   _name;
		bool				_Signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		
		AForm();

	public:
		AForm(const std::string name, int gradetosign, int gradetoexecute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		// Destructor
		virtual ~AForm();

		// Getters
		const std::string& getName() const;
		bool getSigned() const;
		int	getGradeToSign() const;
		int getGradeToExecute() const;

		// Sign form if bureaucrat has sufficient grade 
		void beSigned(const Bureaucrat& b);

		//funcion pura funcion miembro
		//centralizado para evitar duplicacion
		//queda mas limpio y elegante , y las clases dependen de la logica
		//centralizada de la base 
		virtual void execute(const Bureaucrat& executor) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		
		//implentar una funcion para ejcutar la accion del formulario en las
		//clases concretas. el formulario debe estar firmado y el grado del
		//burocrata que intenta ejecutar el formulario sea suficiente si no ->
		//exceptions
		class FormException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);



