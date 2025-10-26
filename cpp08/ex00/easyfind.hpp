#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

// Busca un valor int dentro de un contenedor y devuelve su iterador.
// Lanza std::runtime_error si no se encuentra.
// Compatible con C++98.

template <typename Container>
typename Container::iterator easyfind(Container& container, int value) {
    typename Container::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("easyfind: valor no encontrado");
    }
    return it;
}

template <typename Container>
typename Container::const_iterator easyfind(const Container& container, int value) {
    typename Container::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("easyfind: valor no encontrado");
    }
    return it;
}

#endif // EASYFIND_HPP
