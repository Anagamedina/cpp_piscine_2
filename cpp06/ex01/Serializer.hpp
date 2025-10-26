/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:00:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/09 19:00:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

// Data structure to test serialization
struct Data {
    int numero;		// Integer field
    char letra;		// Character field
    float decimal;	// Float field
};

class Serializer {
    private:
        // Private constructors to prevent instantiation
        Serializer();									// Private default constructor
        Serializer(const Serializer& other);			// Private copy constructor
        Serializer& operator=(const Serializer& other);	// Private assignment operator
        ~Serializer();									// Private destructor

    public:
        // Convert Data* pointer to unsigned long (serialize)
        // Using unsigned long which is available in C++98
        static unsigned long serialize(Data* ptr);
        
        // Convert unsigned long back to Data* pointer (deserialize)
        static Data* deserialize(unsigned long raw);
};

#endif // SERIALIZER_HPP

