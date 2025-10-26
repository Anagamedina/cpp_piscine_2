/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:00:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/14 12:00:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*
 * SWAP: Intercambia los valores de dos parámetros
 * 
 * ¿Cómo funciona?
 * • Toma dos referencias (pueden modificarse)
 * • Crea una variable temporal del tipo T
 * • Intercambia los valores
 * • No retorna nada (void)
 */
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

/*
 * MIN: Devuelve el menor de dos valores
 * 
 * ¿Cómo funciona?
 * • Compara a y b usando el operador <
 * • Si a < b, retorna a
 * • Si son iguales o b es menor, retorna b
 * 
 * IMPORTANTE: Si son iguales, retorna el SEGUNDO (b)
 */
template<typename T>
T const & min(T const & a, T const & b) {
    return (a < b) ? a : b;
}

/*
 * MAX: Devuelve el mayor de dos valores
 * 
 * ¿Cómo funciona?
 * • Compara a y b usando el operador >
 * • Si a > b, retorna a
 * • Si son iguales o b es mayor, retorna b
 * 
 * IMPORTANTE: Si son iguales, retorna el SEGUNDO (b)
 */
template<typename T>
T const & max(T const & a, T const & b) {
    return (a > b) ? a : b;
}

#endif // WHATEVER_HPP

