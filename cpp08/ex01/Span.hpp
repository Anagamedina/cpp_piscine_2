#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {
public:
    explicit Span(unsigned int capacity);
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int value);

    template <typename InputIt>
    void addRange(InputIt first, InputIt last) {
        for (InputIt it = first; it != last; ++it) {
            addNumber(*it);
        }
    }

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int size() const;
    unsigned int capacity() const;

private:
    std::vector<int> m_values;
    unsigned int m_capacity;
};

#endif // SPAN_HPP
