/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:00:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/14 12:00:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>  // Para size_t

template<typename T>
class Array {
private:
    T*      _elements;  // Pointer to dynamic array
    size_t  _size;      // Array size
    
public:
    // ==========================================
    // DEFAULT CONSTRUCTOR
    // Creates empty array (size 0)
    // ==========================================
    Array() : _elements(NULL), _size(0) {
    }
    
    // ==========================================
    // SIZE CONSTRUCTOR
    // Creates array of n initialized elements
    // ==========================================
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {
        // new T[n]() → initializes all elements to 0/empty
        // The () after [n] is crucial for initialization
    }
    
    // ==========================================
    // COPY CONSTRUCTOR
    // Creates deep copy of array
    // ==========================================
    Array(Array const & other) : _elements(NULL), _size(other._size) {
        // Does the work directly, without calling operator=
        if (_size > 0) {
            _elements = new T[_size];
            for (size_t i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
    }
    
    // ==========================================
    // ASSIGNMENT OPERATOR
    // Makes deep copy
    // ==========================================
    Array & operator=(Array const & other) {
        if (this != &other) {
            // 1. Free old memory
            delete[] _elements;
            
            // 2. Copy size
            _size = other._size;
            
            // 3. Allocate new memory and copy elements
            if (_size > 0) {
                _elements = new T[_size];
                for (size_t i = 0; i < _size; i++) {
                    _elements[i] = other._elements[i];
                }
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }
    
    // ==========================================
    // DESTRUCTOR
    // Frees array memory
    // ==========================================
    ~Array() {
        delete[] _elements;
    }
    
    // ==========================================
    // OPERATOR [] (non-const version)
    // Index access with bounds checking
    // ==========================================
    T & operator[](size_t index) {
        if (index >= _size) {
            throw std::exception();
        }
        return _elements[index];
    }
    
    // ==========================================
    // OPERATOR [] (const version)
    // Index access for const objects
    // ==========================================
    T const & operator[](size_t index) const {
        if (index >= _size) {
            throw std::exception();
        }
        return _elements[index];
    }
    
    // ==========================================
    // SIZE
    // Returns number of array elements
    // ==========================================
    size_t size() const {
        return _size;
    }
};

#endif // ARRAY_HPP

