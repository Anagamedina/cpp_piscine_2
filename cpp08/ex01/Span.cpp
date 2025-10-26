#include "Span.hpp"

Span::Span(unsigned int capacity)
    : m_values(), m_capacity(capacity) {}

Span::~Span() {}

Span::Span(const Span& other)
    : m_values(other.m_values), m_capacity(other.m_capacity) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        m_values = other.m_values;
        m_capacity = other.m_capacity;
    }
    return *this;
}

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

int Span::shortestSpan() const {
    if (m_values.size() < 2) {
        throw std::runtime_error("Span: no hay suficientes elementos");
    }

    // Copia y ordena para comparar diferencias consecutivas
    std::vector<int> sorted = m_values;
    std::sort(sorted.begin(), sorted.end());

    long best = static_cast<long>(std::numeric_limits<int>::max());
    for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i) {
        long a = static_cast<long>(sorted[i]);
        long b = static_cast<long>(sorted[i - 1]);
        long diff = a - b; // no negativo por estar ordenado
        if (diff < best) {
            best = diff;
        }
    }
    return static_cast<int>(best);
}

int Span::longestSpan() const {
    if (m_values.size() < 2) {
        throw std::runtime_error("Span: no hay suficientes elementos");
    }

    std::vector<int> sorted = m_values;
    std::sort(sorted.begin(), sorted.end());

    long minVal = static_cast<long>(sorted.front());
    long maxVal = static_cast<long>(sorted.back());
    long diff = maxVal - minVal;
    return static_cast<int>(diff);
}








