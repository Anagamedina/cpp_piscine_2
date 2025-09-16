/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:56:37 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/16 18:54:20 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat a;
		std::cout << a << std::endl;

		Bureaucrat b("Ann", 33);
		
		b.decrementGrade();
		std::cout << b << std::endl;

		Bureaucrat copy(b);
		std::cout << "Copied Bureaucrat: " << copy << std::endl;

		copy.decrementGrade();

	}
	catch (std::exception& excep){
	}
	return (0);
}
