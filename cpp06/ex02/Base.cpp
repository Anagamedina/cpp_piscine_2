/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+      */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2025/10/09 19:30:00 by anamedin          #+#    #+#              */
/*   Updated: 2025/10/09 19:30:00 by anamedin         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*
 * DESTRUCTOR VIRTUAL DE BASE
 * 
 * Es necesario implementar este destructor virtual porque:
 * 1. La clase Base tiene un destructor virtual declarado
 * 2. Las clases derivadas (A, B, C) lo heredan
 * 3. El compilador necesita la implementación para crear la vtable
 * 4. dynamic_cast requiere que la clase sea polimórfica (destructor virtual)
 * 
 * Este destructor está vacío porque Base no tiene miembros que liberar,
 * pero es necesario para el polimorfismo.
 */
Base::~Base() {
    // Destructor vacío pero necesario para el polimorfismo
}








