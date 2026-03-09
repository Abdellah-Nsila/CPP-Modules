

#include <cstdlib> // Required for srand() and rand()
#include <ctime>   // Required for time()
#include <algorithm> // Required for std::generate

std::srand(static_cast<unsigned int>(std::time(NULL)));

int getRandomNumber(int min, int max)
{
    // Formula: rand() % (max - min + 1) + min
    return (rand() % (max - min + 1)) + min;
}

std::vector<int>	generateRandomVectorNumbers()
{
    const int VECTOR_SIZE = getRandomNumber(1, 50);
    const int MIN_VAL = 1;
    const int MAX_VAL = 100;

    std::vector<int> random_vector(VECTOR_SIZE);

    for (size_t i = 0; i < random_vector.size(); ++i) {
        random_vector[i] = getRandomNumber(MIN_VAL, MAX_VAL);
    }
	return (random_vector);
}

bool	isVectorSorted(const std::vector<int>& vec)
{
    if (vec.size() <= 1) {
        return true;
    }
    for (unsigned int i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i+1]) {
            return false; // Found an unsorted pair
        }
    }
    return true; // All pairs were in non-descending order
}

void	binaryInsert(std::vector<int>& numbers, int value, size_t right)
{
	size_t	left = 0;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		// Value is smaller, search the left half
		if (value < numbers[mid])
			right = mid;
		// Value is larger or equal, search the right half
		else
			left = mid + 1;
	}
	numbers.insert(numbers.begin() + left, value);
}


template <typename T>
void	displayContainer(T container, int blockSize, std::string name)
{
	int	gs = 1;

	std::cout << "=========================" << name << "=========================" << std::endl;
	for (size_t i = 0; i < container.size(); i++)
	{
		if (gs == 1)
		{
			std::cout << "[" << container[i] << ", ";
			gs++;
		}
		else if (gs != blockSize)
		{
			std::cout << container[i] << ", ";
			gs++;
		}
		else if (gs == blockSize)
		{
			std::cout << container[i] << "] ";
			gs = 1;
		}
	}
	std::cout << std::endl;
	std::cout << "============================================================" << std::endl;
}


	// for (size_t i = 0; i < 10; i++)
	// {
	// 	std::vector<int>	v = generateRandomVectorNumbers();
	// 	displayContainer(v, 1, "original numbers before");
	// 	pmergeMe(v);
	// 	displayContainer(v, 1, "original numbers after");
	// 	if (isVectorSorted(v))
	// 		std::cout << "Sorted\n" << std::endl;
	// 	else
	// 		std::cout << "Not Sorted\n" << std::endl;
	// }

