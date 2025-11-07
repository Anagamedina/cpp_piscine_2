#include "Span.hpp"
//CONSTRUCTORS
Span::Span(unsigned int capacity)
    : m_values(), m_capacity(capacity) {}



Span::Span(const Span& other)
    : m_values(other.m_values), m_capacity(other.m_capacity) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        m_values = other.m_values;
        m_capacity = other.m_capacity;
    }
    return *this;
}
//DESTRUCTOR
Span::~Span() {}


//METODOS
void Span::addNumber(int value) {
    if (m_values.size() >= m_capacity) {
        throw std::runtime_error("Span: capacidad excedida");
    }
    m_values.push_back(value);
}

unsigned int Span::size() const {
    return static_cast<unsigned int>(m_values.size());
}

unsigned int Span::capacity() const {
    return m_capacity;
}

unsigned int Span::shortestSpan() const
{
	if (numbers_.size() <= 1)
		throw std::length_error("not enough numbers.");

	// O(N log N) - Esto es necesario para el shortest span
	std::vector<int> sorted = numbers_;
	std::sort(sorted.begin(), sorted.end());

    // Inicializamos el span con el primer par, usando 'long' para el cálculo
	long minSpan = static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]);

	// Recorremos el resto del vector
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
        // Calculamos la diferencia del par adyacente, usando 'long'
		long currentDiff = static_cast<long>(sorted[i + 1]) - static_cast<long>(sorted[i]);
        
        // Usamos std::min para actualizar el valor
		minSpan = std::min(minSpan, currentDiff);
	}
    
    // Retornamos el valor, haciendo el cast al tipo de retorno
	return static_cast<unsigned int>(minSpan);
}

int Span::longestSpan() const {
    if (m_values.size() < 2) {
        throw std::runtime_error("Span: no hay suficientes elementos");
    }

    std::vector<int> sorted = m_values;
    /*std::sort(sorted.begin(), sorted.end());
    //SE PUEDE USAR BEGIN Y END PARA USAR ITEERADORES 
    long minVal = static_cast<long>(sorted.front());
    long maxVal = static_cast<long>(sorted.back());
    long diff = maxVal - minVal;
    return static_cast<int>(diff);*/
    
   // Usar 'long' para el cálculo de la diferencia para evitar overflow, 
    std::vector<int>::const_iterator maxIt = std::max_element(sorted.begin(), sorted.end());
    std::vector<int>::const_iterator minIt = std::min_element(sorted.begin(), sorted.end());
    long diff = static_cast<long>(*maxIt) - static_cast<long>(*minIt);
    return static_cast<int>(diff);
}








