/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:30:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/09 19:30:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

/*
 * GENERATE: Genera aleatoriamente un objeto de tipo A, B o C
 * 
 * ¿Cómo funciona?
 * 1. Genera un número aleatorio (0, 1 o 2)
 * 2. Según el número, crea un nuevo objeto A, B o C
 * 3. Retorna un puntero a Base (polimorfismo)
 */
Base* generate(void) {
    int random = rand() % 3;  // Número aleatorio entre 0 y 2
    
    switch (random) {
        case 0:
            std::cout << "   [Generado: A]" << std::endl;
            return new A();
        case 1:
            std::cout << "   [Generado: B]" << std::endl;
            return new B();
        case 2:
            std::cout << "   [Generado: C]" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

/*
 * IDENTIFY (con punteros): Identifica el tipo real del objeto
 * 
 * ¿Cómo funciona?
 * Usa dynamic_cast para intentar convertir el puntero Base*
 * a cada uno de los tipos A*, B*, C*
 * 
 * Si dynamic_cast tiene éxito, retorna un puntero válido
 * Si falla, retorna NULL
 */
void identify(Base* p) {
    // Intentar convertir a A*
    if (dynamic_cast<A*>(p)) {
        std::cout << "   Tipo identificado: A" << std::endl;
    }
    // Intentar convertir a B*
    else if (dynamic_cast<B*>(p)) {
        std::cout << "   Tipo identificado: B" << std::endl;
    }
    // Intentar convertir a C*
    else if (dynamic_cast<C*>(p)) {
        std::cout << "   Tipo identificado: C" << std::endl;
    }
    else {
        std::cout << "   Tipo desconocido" << std::endl;
    }
}

/*
 * IDENTIFY (con referencias): Identifica el tipo real del objeto
 * 
 * ¿Cómo funciona?
 * Similar a la versión con punteros, pero usa referencias
 * 
 * IMPORTANTE: Con referencias, dynamic_cast lanza una excepción
 * std::bad_cast si la conversión falla (en lugar de retornar NULL)
 * 
 * Por eso usamos try-catch para cada tipo
 */
void identify(Base& p) {
    // Intentar convertir a A&
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "   Tipo identificado: A" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // No es tipo A, continuamos
    }
    
    // Intentar convertir a B&
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "   Tipo identificado: B" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // No es tipo B, continuamos
    }
    
    // Intentar convertir a C&
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "   Tipo identificado: C" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // No es tipo C
    }
    
    std::cout << "   Tipo desconocido" << std::endl;
}

int main() {
    // Inicializar el generador de números aleatorios
    srand(time(NULL));
    
    std::cout << "=== TEST DE IDENTIFICACIÓN DE TIPOS ===" << std::endl;
    std::cout << std::endl;
    
    // Generar y probar varios objetos aleatorios
    for (int i = 1; i <= 6; i++) {
        std::cout << "🎲 Test " << i << ":" << std::endl;
        
        // Generar un objeto aleatorio
        Base* obj = generate();
        
        // Identificar usando punteros
        std::cout << "   Identificar con puntero: ";
        identify(obj);
        
        // Identificar usando referencias
        std::cout << "   Identificar con referencia: ";
        identify(*obj);
        
        // Liberar memoria
        delete obj;
        std::cout << std::endl;
    }
    
    std::cout << "=== TEST ADICIONAL: Objetos conocidos ===" << std::endl;
    std::cout << std::endl;
    
    // Crear objetos específicos para verificar
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    
    std::cout << "📋 Objeto A:" << std::endl;
    std::cout << "   Identificar con puntero: ";
    identify(a);
    std::cout << "   Identificar con referencia: ";
    identify(*a);
    std::cout << std::endl;
    
    std::cout << "📋 Objeto B:" << std::endl;
    std::cout << "   Identificar con puntero: ";
    identify(b);
    std::cout << "   Identificar con referencia: ";
    identify(*b);
    std::cout << std::endl;
    
    std::cout << "📋 Objeto C:" << std::endl;
    std::cout << "   Identificar con puntero: ";
    identify(c);
    std::cout << "   Identificar con referencia: ";
    identify(*c);
    
    // Liberar memoria
    delete a;
    delete b;
    delete c;
    
    return 0;
}

