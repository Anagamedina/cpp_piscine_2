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
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();

	public:
        static void convert(const std::string& literal);


};

#endif // SCALAR_CONVERTER_HPP
