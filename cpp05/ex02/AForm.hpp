/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:09:22 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/25 15:43:01 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

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
		const 	std::string& getName() const;
		bool 	getSigned() const;
		int		getGradeToSign() const;
		int 	getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);
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
		
		//exceptions
		class FormException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
