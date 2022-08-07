# statistics - a C++ library

**statistics** is a header only cplusplus library which you can use to make statistical computations easily.

## How to use this library
Just `#include` the `statistics.h` file in your C++ programs and you're good to go.


## Documentation
### `template <typename T> bool isEven(T number)`
#### Description
- Checks if a given number is even or not
#### Template parameters
1. **T:** Type of the number. Accepted values: int, float, double
#### Parameters
1. **number:** The number to be checked if its even or not.
#### Returns
- true if the given number is even, false otherwise.
#### Example Usage:
```cpp
bool isEvenNumber = statistics::isEven<int>(3);
bool isEvenFloat = statistics::isEven<float>(4.0);
```


### `template <class T> float mean(std::vector<T> &data)`
#### Description
- Calculates the mean of the elements in `data`.
#### Template parameters
1. **T:** Type of the elements
#### Parameters
1. **data:** The vector containing the elements whose mean is to be calculated 
#### Returns
- the mean of the given elements in the array as a `float`
#### Example Usage:
```cpp
std::vector<float> myNumbers{3.4, 8.9, 6. -4.5, 0.8};
std::cout << "Mean of my numbers is " << statistics::mean<float>(myNumbers);
```

### `template <class T> float mean(std::vector<T> &data)`
#### Description
- Calculates the median of the elements in `data`.
#### Template parameters
1. **T:** Type of the elements
#### Parameters
1. **data:** The vector containing the elements whose median is to be calculated 
#### Returns
- the mean of the given elements in the array as a `float`
#### Example Usage:
```cpp
std::vector<float> myNumbers{3.4, 8.9, 6. -4.5, 0.8};
std::cout << "Median of my numbers is " << statistics::median<float>(myNumbers);
```


### `template <class T> float variance(std::vector<T> &data)`
#### Description
- Calculates the variance of the elements in `data`.
#### Template parameters
1. **T:** Type of the elements
#### Parameters
1. **data:** The vector containing the elements whose variance is to be calculated 
#### Returns
- the variance of the given elements in the array as a `float`
#### Example Usage:
```cpp
std::vector<float> myNumbers{3.4, 8.9, 6. -4.5, 0.8};
std::cout << "Variance of my numbers is " << statistics::variance<float>(myNumbers);
```

### `template <class T> float standard_deviation(std::vector<T> &data)`
#### Description
- Calculates the standard deviation of the elements in `data`.
#### Template parameters
1. **T:** Type of the elements
#### Parameters
1. **data:** The vector containing the elements whose standard deviation is to be calculated 
#### Returns
- the standard deviation of the given elements in the array as a `float`
#### Example Usage:
```cpp
std::vector<float> myNumbers{3.4, 8.9, 6. -4.5, 0.8};
std::cout << "sigma of my numbers is " << statistics::standard_deviation<float>(myNumbers);
```

### `template <class T> std::vector<T> genRandom(genRandomOptions &opts)`
#### Description
- Generates a vector of random numbers of given type `T` with the given options.
#### Template parameters
1. **T:** Type of the random numbers to be generated.
#### Parameters
1. **opts:** An instance of class `genRandomOpts` with set values of parameters required to generate the random numbers.
    1. **opts.min_val**: Lowest boundary for the random numbers
    2. **opts.max_val**: Maximum boundary for the random numbers
    3. **opts.mean**:    Mean of the random numbers
    4. **opts.dist**: Type of probability distribution of the numbers. Accepted values:
        1. statistics::NORMAL,
      	1. statistics::UNIFORM,
		1. statistics::BINOMIAL,
		2. statistics::BERNOULLI,
		3. statistics::POISSON,
		4. statistics::EXPONENTIAL
    5. **opts.standard_deviation**: Std Deviation of the random numbers.
#### Returns
- An array of random numbers with the given type.
#### Example Usage:
```cpp
statistics::genRandomOptions opts{};
opts.dist = statistics::NORMAL;
opts.size = 10000;
opts.min_val = 1;
opts.max_val = 1000;
opts.mean = 500;
opts.standard_deviation = 200;
std::vector<float> randomFloats = statistics::genRandom<float>(opts);
```

## Contribute
Feel free to raise a pull with description and I'll take a look at it.
