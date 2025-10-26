/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:15:43 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/25 15:58:55 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern {
	public:
		// Constructors
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& obj);
		~Intern();

		// Form creation method
		AForm* makeForm(const std::string& formName, const std::string& target);

		// Exceptions
		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		// Static form creator functions
		static AForm* createShrubberyForm(const std::string& target);
		static AForm* createRobotomyForm(const std::string& target);
		static AForm* createPresidentialForm(const std::string& target);
};

#endif
