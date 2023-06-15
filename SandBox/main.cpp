#include <vector>
#include <iostream>

// Implementing a custom vector class
class CustomVector
{
	size_t size;
	double* arr_;

public:
	// Copy constructor
	CustomVector(const CustomVector& rhs)
	{
		std::cout << "Copy constructor\n";
		this->size = rhs.size;
		this->arr_ = new double[this->size]{};
		for (size_t i = 0; i < this->size; ++i)
		{
			this->arr_[i] = rhs.arr_[i];
		}
	}

	// Move constructor
	CustomVector(CustomVector&& rhs)
	{
		std::cout << "Move constructor\n";
		this->size = rhs.size;
		this->arr_ = rhs.arr_;
		// Resetting rvalue 
		rhs.size = 0;
		rhs.arr_ = nullptr;
	}

	// Custom constructor with size
	CustomVector(size_t size)
	{
		std::cout << "Specialized constructor\n";
		this->size = size;
		this->arr_ = new double[this->size]{};
		for (size_t i = 0; i < this->size; ++i)
		{
			this->arr_[i] = i;
		}
	}

	// Destructor
	~CustomVector()
	{
		delete this->arr_;
	}

	// Print the contents of the CustomVector
	void Print()
	{
		for (size_t i = 0; i < this->size; ++i)
		{
			std::cout << this->arr_[i] << '\n';
		}
	}
};

// Function to create a CustomVector
CustomVector CreateVector(size_t size)
{
	return CustomVector(size); // Return Value Optimization (RVO)
}

// Function accepting a CustomVector
void foo(CustomVector vect)
{
	std::cout << "Inside foo function\n";
}

// Template function demonstrating perfect forwarding
template <typename T>
void Relay(T&& arg)
{
	// Perfect forwarding of the argument to the foo function
	foo(std::forward<T>(arg));
}

int main()
{
	// The CustomVector is constructed directly in the memory that will be used for customVector.
	// Hence, no copy or move operations are necessary, and no "Copy constructor" or "Move constructor" messages are printed.
	CustomVector reusable = CreateVector(6);

	Relay(reusable); // Here, reusable is an L-value

	Relay(CustomVector(5)); // Here, CustomVector(5) is an R-value
}
