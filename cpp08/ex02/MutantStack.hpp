#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

        //Typedef pour que le main passe

        typedef typename std::stack<T>::container_type::iterator		iterator;
	    typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		
        //Forme canonique
        MutantStack<T>() {}; //Constructeur
		MutantStack<T>(MutantStack<T> const &copy): std::stack<T>(copy){}; //Constructeur par copie
        ~MutantStack<T>() {}; //Destructeur
		MutantStack<T>	&operator=(MutantStack<T> const &copy) //Operateur
		{
			std::stack<T>::operator=(copy);
			return *this; 
		}

        //Iterateurs

		iterator begin() { return std::stack<T>::c.begin(); };
		iterator end() { return std::stack<T>::c.end(); };
		
        const_iterator		begin() const { return std::stack<T>::c.begin(); };
		const_iterator		end() const { return std::stack<T>::c.end(); };
		
       /*typedef typename std::stack<T>::container_type::reverse_iterator		rbegin() { return std::stack<T>::c.rbegin(); };
		typedef typename std::stack<T>::container_type::reverse_iterator 		rend() { return std::stack<T>::c.rend(); };
		typedef typename std::stack<T>::container_type::const_reverse_iterator	rbegin() const { return std::stack<T>::c.rbegin(); };
		typedef typename std::stack<T>::container_type::const_reverse_iterator	rend() const { return std::stack<T>::c.rend(); };*/
};

#endif