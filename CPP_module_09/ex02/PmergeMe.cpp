#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	_vector = copy._vector;
	_vectorTime = copy._vectorTime;
	_deque = copy._deque;
	_dequeTime = copy._dequeTime;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	(void) assign;
	return *this;
}

/*===========================================================================*/
/*                           Important Constructor                           */
/*===========================================================================*/

static int	InputSize(char **input)
{
	int	size = 0;
	
	while (input[size])
		size++;
	return (size);
}

static	bool	isZero(char *s)
{
	int	i = -1;

	while (s[++i])
		if (s[i] != '0')
			return (false);
	return (true);
}

PmergeMe::PmergeMe(char **input)
{
	int	a;

	for (int i = 1; i < InputSize(input); i++)
	{
		a = atoi(input[i]);
		if (a == 0 && !isZero(input[i]))
			throw (std::exception());
		else if (a < 0)
			throw (std::exception());
		else
		{
			_deque.push_back(a);
			_vector.push_back(a);
		}			
	}
}

/*===========================================================================*/
/*                                  getters                                  */
/*===========================================================================*/

std::vector<int>	PmergeMe::getVector()	{
	return (_vector);
}

double	PmergeMe::getVectorTime()	{
	return (_vectorTime);
}

std::deque<int>	PmergeMe::getDeque()	{
	return (_deque);
}

double	PmergeMe::getDequeTime()	{
	return (_dequeTime);
}

/*===========================================================================*/
/*                             Common Functions                              */
/*===========================================================================*/

template <typename T>
static int	biggestIndex(T vectors, int left, int size)
{
	int	biggest	= vectors.a.at(left);
	int	bgIndex	= left;

	for (int i = left + 1; i < size; i++)
	{
		if (vectors.a.at(i) > biggest)
		{
			biggest	= vectors.a.at(i);
			bgIndex		= i;
		}
	}
	return (bgIndex);
}

template <typename T>
static void	SortArrays(T *vectors, int left, int size)
{
	int	biggest;
	int	sa;
	int	sb;

	if (left == size)
		return;
	biggest = biggestIndex(*vectors, left, size);

	sa = vectors->a.at(biggest);
	sb = vectors->b.at(biggest);
	vectors->a.at(biggest) = vectors->a.at(left);
	vectors->b.at(biggest) = vectors->b.at(left);
	vectors->a.at(left) = sa;
	vectors->b.at(left) = sb;

	SortArrays(vectors, left + 1 ,size);
}

template <typename T>
static int	specialSize(T v)
{
	int	counter = 0;

	for (int i = 0; i < (int)v.size(); i++)
	{
		if (v.at(i) != -1)
			counter++;
	}
	return (counter);
}

template <typename T>
static int	FindCost(T vectors, int numIndex)
{
	int		N;
	int		cost;
	bool	isPair = true;

	if ((vectors.a.size() + specialSize(vectors.b)) % 2)
		isPair = false;
	if (isPair)
		N = vectors.a.size() - vectors.b.size() + numIndex;
	else
		N = vectors.a.size() - (vectors.b.size() - 1) + numIndex;

	cost = floor(log2(N));
	return (cost);
}

template <typename T>
static int	FindBestMoveIndex(T vectors)
{
	int	smallestCost = 2147483647;
	int biggestTargetChainLenght = 0;

	for (int i = 0; i < (int)vectors.b.size(); i++)
	{
		if (vectors.b.at(i) != REMOVED)
		{
			if (FindCost(vectors, i) < smallestCost)
				smallestCost = FindCost(vectors, i);
			if (FindCost(vectors, i) == smallestCost)
				if (i > biggestTargetChainLenght)
					biggestTargetChainLenght = i;
		}
	}
	for (int i = 0; i < (int)vectors.b.size(); i++)
	{
		if (vectors.b.at(i) != REMOVED)
			if (FindCost(vectors, i) == smallestCost && i == biggestTargetChainLenght)
				return (i);
	}
	return (-1);
}

template <typename T>
void	print(T v)
{
	for (int i = 0; i < (int)v.size(); i++)
	{
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;
}

template <typename T>
static int	BinaryTreeInsertFindIndex
	(T a, int num, int numIndex, int originalSize)
{
	int	RelevantChainSize = a.size() - originalSize + numIndex;
	int	InsertIndex = RelevantChainSize / 2;
	int	Size = InsertIndex / 2;

	if (num <= a.at(RelevantChainSize - 1))
		return (RelevantChainSize);
	if (num >= a.at(0))
		return (0);
	while (true)
	{	
		// std::cout << "a : ";
		// print(a);
		// std::cout << std::endl;
		// std::cout << "InserInde\t: " << InsertIndex << std::endl;
		// std::cout << "a at II\t\t: " << a.at(InsertIndex) << std::endl;
		// std::cout << "Size\t\t: " << Size << std::endl;
		// std::cout << "num\t\t: " << num << std::endl << std::endl;
		if (num <= a.at(InsertIndex) && num > a.at(InsertIndex + 1))
			return (InsertIndex + 1);
		if (num > a.at(InsertIndex))
			InsertIndex -= Size;
		if (num < a.at(InsertIndex + 1))
			InsertIndex += Size;
		Size /= 2;
		if (!Size)
			Size = 1;
	}
}

/*===========================================================================*/
/*                                  vectors                                  */
/*===========================================================================*/

vectors_t	PmergeMe::CreateVectors()
{
	vectors_t	vectors;

	for (int i = 0; i < (int)_vector.size(); i += 2)
	{
		if (!(i + 1 == (int)_vector.size()))
		{
			if (_vector.at(i) < _vector.at(i + 1))
			{
				vectors.a.push_back(_vector.at(i));
				vectors.b.push_back(_vector.at(i + 1));
			}
			else
			{
				vectors.a.push_back(_vector.at(i + 1));
				vectors.b.push_back(_vector.at(i));
			}
		}
		else
			vectors.b.push_back(_vector.at(i));
	}
	return (vectors);
}

void	PmergeMe::SortVector()
{
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);

	vectors_t	vectors = CreateVectors();
	int			BestMoveIndex;
	int			vectorOriginalSize = vectors.a.size();

	SortArrays(&vectors, 0, vectors.a.size());
	vectors.a.insert(vectors.a.begin(), vectors.b.at(0));
	vectors.b.at(0) = REMOVED;

	for (int i = 1; i < (int)vectors.b.size(); i++)
	{
		BestMoveIndex = FindBestMoveIndex(vectors);
		if (BestMoveIndex == -1)
			throw (std::exception());
		vectors.a.insert(vectors.a.begin() +
				BinaryTreeInsertFindIndex(vectors.a, vectors.b.at(BestMoveIndex),
				BestMoveIndex, vectorOriginalSize), vectors.b.at(BestMoveIndex));
		// std::cerr << "v: " << vectors.b.at(BestMoveIndex) << std::endl;
		vectors.b.at(BestMoveIndex) = REMOVED;
	}
	_vector = vectors.a;
	std::reverse(_vector.begin(), _vector.end());
	gettimeofday(&end, NULL);

	struct timeval time;
	time.tv_sec = end.tv_sec - start.tv_sec;
	time.tv_usec = end.tv_usec - start.tv_usec;
	_vectorTime = (double)time.tv_sec + (double)time.tv_usec / 100000;
}

/*===========================================================================*/
/*                                  deques                                   */
/*===========================================================================*/

deques_t	PmergeMe::CreateDeques()
{
	deques_t	deques;

	for (int i = 0; i < (int)_deque.size(); i += 2)
	{
		if (!(i + 1 == (int)_deque.size()))
		{
			if (_deque.at(i) < _deque.at(i + 1))
			{
				deques.a.push_back(_deque.at(i));
				deques.b.push_back(_deque.at(i + 1));
			}
			else
			{
				deques.a.push_back(_deque.at(i + 1));
				deques.b.push_back(_deque.at(i));
			}
		}
		else
			deques.b.push_back(_deque.at(i));
	}
	return (deques);
}

void	PmergeMe::SortDeque()
{
	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);

	deques_t	deques = CreateDeques();
	int			BestMoveIndex;
	int			dequeOriginalSize = deques.a.size();

	SortArrays(&deques, 0, deques.a.size());
	deques.a.push_front(deques.b.at(0));
	deques.b.at(0) = REMOVED;

	for (int i = 1; i < (int)deques.b.size(); i++)
	{
		BestMoveIndex = FindBestMoveIndex(deques);
		if (BestMoveIndex == -1)
			throw (std::exception());
		deques.a.insert(deques.a.begin() +
				BinaryTreeInsertFindIndex(deques.a, deques.b.at(BestMoveIndex),
				BestMoveIndex, dequeOriginalSize), deques.b.at(BestMoveIndex));
		// std::cerr << "d: " << deques.b.at(BestMoveIndex) << std::endl;
		deques.b.at(BestMoveIndex) = REMOVED;
	}
	std::reverse(deques.a.begin(), deques.a.end());
	_deque = deques.a;
	gettimeofday(&end, NULL);

	struct timeval time;
	time.tv_sec = end.tv_sec - start.tv_sec;
	time.tv_usec = end.tv_usec - start.tv_usec;
	_dequeTime = (double)time.tv_sec + (double)time.tv_usec / 100000;
}
