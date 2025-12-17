#include "Array.tpp"

int	main()
{
	Array<int>	arr1;
	Array<int>	arr2(5);

	std::cout << arr1.size() << std::endl;
	std::cout << arr2.size() << std::endl;

	try
	{
		std::cout << arr1[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << arr2[0] << std::endl;
}
