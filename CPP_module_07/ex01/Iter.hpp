#ifndef ITER_HPP
# define ITER_HPP


template <typename T, typename F>
void	iter(T* array, int array_length, F f)	{
	for (int i = 0; i < array_length; i++)
		f(array[i]);	
}


#endif