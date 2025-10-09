/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:30:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/09 19:30:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

/*
 * CLASE BASE
 * 
 * Es una clase base polimórfica (tiene destructor virtual)
 * Esto es NECESARIO para que dynamic_cast funcione
 * 
 * Las clases A, B y C heredarán de Base
 */
class Base {
    public:
        virtual ~Base();  // Destructor virtual (hace la clase polimórfica)
};

#endif // BASE_HPP

