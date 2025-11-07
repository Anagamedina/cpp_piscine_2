#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
/*
    typedef typename std::deque<T>::const_iterator const_iterator;
	typedef std::deque<T> tDeque;		//	 DEQUE
	typedef typename tDeque::iterator iterator;	
    
    */
template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef std::stack<T> Base;
    typedef typename Base::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

    //reverse iterator
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

    MutantStack() : Base() {}
    MutantStack(const MutantStack& other) : Base(other) {}
    ~MutantStack() {}

    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            Base::operator=(other);
        }
        return *this;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif // MUTANTSTACK_HPP
