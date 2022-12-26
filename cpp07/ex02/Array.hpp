#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
#include <climits>

template<typename T>
class Array
{
    private:
		int	_size;
		T	*_tab;
	public:
		class IndexOutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Index out of bound.";
				}
		};

        /* Constructeurs */

		Array<T>()
        {
            std::cout << "Default constructor called." << std::endl;
            _size = 0;
            _tab = new T[0]();
        };

		Array<T>(const unsigned int n){
            this->_size = n;
			this->_tab = new T[this->_size];
		};

        /* Destructeur */

        ~Array() {
            std::cout << "Destructor called." << std::endl;
			delete [] this->_tab;
        }

		Array<T>(Array<T> const &array) {
			this->_size = array._size;
			this->_tab = new T[this>_size];
			for (int i = 0; i < this->_size; i++)
				this->_tab[i] = array._tab[i];
		};
		
        Array<T>	&operator=(Array<T> const &array) {
		 	//if (this->_tab)
			delete [] this->_tab;
			this->_size = array._size;
			this->_tab = new T[this->_size];
			for (int i = 0; i < this->_size; i++)
				this->_tab[i] = array._tab[i];
			return *this;
		};

		T	&operator[](const int i) const {
			if (i >= this->_size || i < 0)
            {
                throw IndexOutOfBoundException();
            }
			return this->_tab[i];
		}

		unsigned int	size() const { return this->_size; };		
};

#endif