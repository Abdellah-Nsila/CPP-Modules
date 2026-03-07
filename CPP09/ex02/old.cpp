



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
