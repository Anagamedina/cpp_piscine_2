/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:00:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/14 12:00:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>  // Para size_t

/*
 * ITER: Applies a function to each element of an array
 * 
 * Parameters:
 * • array: Array address (pointer)
 * • length: Array length
 * • function: Function to apply to each element
 * 
 * How it works?
 * • Iterates through array from index 0 to length-1
 * • Applies function to each element
 * • Function can modify or not the elements (depending on its signature)
 */
template<typename T, typename F>
void iter(T* array, size_t length, F function) {
    if (array == NULL || function == NULL)	// Null pointer checks
        return;
    
    for (size_t i = 0; i < length; i++) {	// Iterate through array
        function(array[i]);					// Apply function to each element
    }
}

// Overload for functions that take const reference
// This allows using iter with functions that don't modify elements
template<typename T>
void iter(T* array, size_t length, void (*function)(T const &)) {
    if (array == NULL || function == NULL)	// Null pointer checks
        return;
    
    for (size_t i = 0; i < length; i++) {	// Iterate through array
        function(array[i]);					// Apply function to each element
    }
}

// Overload for functions that take non-const reference
// This allows using iter with functions that DO modify elements
template<typename T>
void iter(T* array, size_t length, void (*function)(T&)) {
    if (array == NULL || function == NULL)	// Null pointer checks
        return;
    
    for (size_t i = 0; i < length; i++) {	// Iterate through array
        function(array[i]);					// Apply function to each element
    }
}

#endif // ITER_HPP

