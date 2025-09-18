/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:15:43 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/18 17:46:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class Intern {
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& obj);
		~Intern();

		//dvuelve un puntero a un objeto AForm
		AForm* makeForm(const std::string& formName, const std::string& target);
}
