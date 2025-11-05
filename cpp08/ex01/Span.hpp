#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {

    private:
    std::vector<int> m_values;
    unsigned int m_capacity;

    public:
    
        //COSNTRUCTORS & DESTRUCTORS
        Span(unsigned int capacity);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);

       
        //TEMPLATE
        template <typename InputIt>
        void addRange(InputIt first, InputIt last) {
            for (InputIt it = first; it != last; ++it) {
                addNumber(*it);
            }
        }

        //METODOS
        void addNumber(int value);
        int shortestSpan() const;
        int longestSpan() const;
        unsigned int size() const;
        unsigned int capacity() const;


};

#endif // SPAN_HPP
