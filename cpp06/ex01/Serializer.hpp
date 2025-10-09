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

// Estructura de datos para probar la serialización
struct Data {
    int numero;
    char letra;
    float decimal;
};

class Serializer {
    private:
        // Constructores privados para que no se puedan crear instancias
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();

    public:
        // Convierte un puntero Data* a un número entero (serializar)
        // Usamos unsigned long que está disponible en C++98
        static unsigned long serialize(Data* ptr);
        
        // Convierte un número entero de vuelta a puntero Data* (deserializar)
        static Data* deserialize(unsigned long raw);
};

#endif // SERIALIZER_HPP

