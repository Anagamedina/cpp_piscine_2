/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:00:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/09 19:00:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST DE SERIALIZACIÓN ===" << std::endl;
    std::cout << std::endl;
    
    // Crear un objeto Data con algunos valores
    Data original;
    original.numero = 42;
    original.letra = 'A';
    original.decimal = 3.14f;
    
    // Mostrar el objeto original
    std::cout << "📦 DATOS ORIGINALES:" << std::endl;
    std::cout << "   Dirección: " << &original << std::endl;
    std::cout << "   Número: " << original.numero << std::endl;
    std::cout << "   Letra: " << original.letra << std::endl;
    std::cout << "   Decimal: " << original.decimal << std::endl;
    std::cout << std::endl;
    
    // SERIALIZAR: Convertir el puntero a número
    unsigned long serializado = Serializer::serialize(&original);
    std::cout << "🔢 SERIALIZADO (puntero → número):" << std::endl;
    std::cout << "   Valor numérico: " << serializado << std::endl;
    std::cout << "   En hexadecimal: 0x" << std::hex << serializado << std::dec << std::endl;
    std::cout << std::endl;
    
    // DESERIALIZAR: Convertir el número de vuelta a puntero
    Data* restaurado = Serializer::deserialize(serializado);
    std::cout << "♻️  DESERIALIZADO (número → puntero):" << std::endl;
    std::cout << "   Dirección: " << restaurado << std::endl;
    std::cout << "   Número: " << restaurado->numero << std::endl;
    std::cout << "   Letra: " << restaurado->letra << std::endl;
    std::cout << "   Decimal: " << restaurado->decimal << std::endl;
    std::cout << std::endl;
    
    // Verificar que funcionó correctamente
    std::cout << "✅ VERIFICACIÓN:" << std::endl;
    if (restaurado == &original) {
        std::cout << "   ¡Las direcciones coinciden! ✓" << std::endl;
        std::cout << "   La serialización/deserialización funcionó correctamente" << std::endl;
    } else {
        std::cout << "   ❌ ERROR: Las direcciones no coinciden" << std::endl;
    }
    std::cout << std::endl;
    
    // Prueba adicional: modificar el objeto restaurado
    std::cout << "🔧 PRUEBA ADICIONAL:" << std::endl;
    std::cout << "   Modificando el objeto restaurado..." << std::endl;
    restaurado->numero = 100;
    restaurado->letra = 'Z';
    restaurado->decimal = 9.99f;
    
    std::cout << "   Valores del objeto original después de la modificación:" << std::endl;
    std::cout << "   Número: " << original.numero << std::endl;
    std::cout << "   Letra: " << original.letra << std::endl;
    std::cout << "   Decimal: " << original.decimal << std::endl;
    std::cout << "   (Los valores cambiaron porque apuntan al mismo objeto)" << std::endl;
    
    return 0;
}

