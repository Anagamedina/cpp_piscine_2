/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:33:46 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/02 17:30:05 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
	private:
		ScalarConverter();									// Private default constructor
		ScalarConverter(const ScalarConverter& copy);		// Private copy constructor
        ScalarConverter& operator=(const ScalarConverter& obj);	// Private assignment operator
		~ScalarConverter();									// Private destructor

	public:
        static void convert(const std::string& literal);	// Static method to convert string to scalar types

};

#endif // SCALAR_CONVERTER_HPP
