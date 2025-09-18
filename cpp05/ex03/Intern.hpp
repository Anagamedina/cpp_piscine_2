/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:15:43 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 17:46:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

class Form;

class Intern {
	public:
		// Constructors
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& obj);
		~Intern();

		// Form creation method
		Form* makeForm(const std::string& formName, const std::string& target);

	private:
		// Static form creator functions
		static Form* createShrubberyForm(const std::string& target);
		static Form* createRobotomyForm(const std::string& target);
		static Form* createPresidentialForm(const std::string& target);
};

#endif
