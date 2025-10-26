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
 * BASE CLASS
 * 
 * Polymorphic base class (has virtual destructor)
 * This is NECESSARY for dynamic_cast to work
 * 
 * Classes A, B and C will inherit from Base
 */
class Base {
    public:
        virtual ~Base();  // Virtual destructor (makes class polymorphic)
};

#endif // BASE_HPP





