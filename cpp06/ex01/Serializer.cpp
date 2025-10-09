/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:00:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/09 19:00:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ============================================================================
// CONSTRUCTORES Y DESTRUCTOR (privados - no se pueden usar)
// ============================================================================

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) { (void)other; }

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

// ============================================================================
// FUNCIONES PÚBLICAS ESTÁTICAS
// ============================================================================

/*
 * SERIALIZE: Convierte un puntero a número
 * 
 * ¿Por qué?
 * A veces necesitamos guardar o transmitir punteros como números
 * (por ejemplo, para guardarlos en un archivo o enviarlos por red)
 * 
 * ¿Cómo funciona?
 * reinterpret_cast<unsigned long>(ptr) toma la dirección de memoria
 * y la convierte en un número entero sin signo
 * 
 * Nota: Usamos unsigned long porque es compatible con C++98
 */
unsigned long Serializer::serialize(Data* ptr) {
    return reinterpret_cast<unsigned long>(ptr);
}

/*
 * DESERIALIZE: Convierte un número de vuelta a puntero
 * 
 * ¿Por qué?
 * Para recuperar el puntero original que habíamos serializado
 * 
 * ¿Cómo funciona?
 * reinterpret_cast<Data*>(raw) toma el número y lo convierte
 * de vuelta en un puntero Data*
 * 
 * ⚠️ IMPORTANTE:
 * Solo funciona si el número viene de serialize() y el objeto
 * original todavía existe en memoria
 */
Data* Serializer::deserialize(unsigned long raw) {
    return reinterpret_cast<Data*>(raw);
}

