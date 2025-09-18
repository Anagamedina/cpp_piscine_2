/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:03:08 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 11:13:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef  SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm { 
	private:
		std::string		_target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executor) const;
};

#endif
