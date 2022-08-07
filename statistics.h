#pragma once
#include <vector>
#include <numeric>
#include <random>
#include <time.h>

namespace statistics
{
	/**
	 * Types of probability distributions
	 */
	enum distribution
	{
		NORMAL,
		UNIFORM,
		BINOMIAL,
		BERNOULLI,
		POISSON,
		EXPONENTIAL
	};

	template <typename T>
	bool isEven(T number)
	{
		return !(number % 2);
	}

	template <class T>
	float mean(std::vector<T> &data)
	{
		return std::accumulate(data.begin(), data.end(), 0) / (float)data.size();
	}

	template <class T>
	float mean(T &a, T &b)
	{
		return (float)(a + b) / 2;
	}

	template <class T>
	float median(std::vector<T> &data)
	{
		if (data.empty())
		{
			// TODO throw new Error("Cannot compute median of an empty dataset!");
			return 0;
		}
		if (isEven<unsigned int>(data.size()))
		{
			return mean<T>(data[data.size() / 2], data[data.size() / 2 - 1]);
		}
		else
		{
			return data[data.size() / 2];
		}
	}

	template <class T>
	float variance(std::vector<T> &data)
	{
		// TODO handle empty data
		float _v = 0;
		float _mean = mean(data);
		for (const T &datapoint : data)
		{
			_v += ((datapoint - _mean) * (datapoint - _mean));
		}
		return _v / data.size();
	}

	template <class T>
	float standard_deviation(std::vector<T> &data)
	{
		if (data.empty())
		{
			// TODO
			return 0;
		}
		return std::sqrtf(variance<T>(data));
	}

	class genRandomOptions
	{
	public:
		distribution dist;
		unsigned int size;
		float min_val;
		float max_val;
		float mean;
		float standard_deviation;
	};
	template <class T>
	std::vector<T> genRandom(genRandomOptions &opts)
	{
		std::vector<T> _v;
		if (opts.dist == NORMAL)
		{
			srand(time(NULL));
			std::default_random_engine generator;
			std::normal_distribution<T> normal_distribution(opts.mean, opts.standard_deviation);
			unsigned int count = 0;
			while (count < opts.size)
			{
				T generated = normal_distribution(generator);
				if (generated >= opts.min_val and generated <= opts.max_val)
				{
					_v.push_back(generated);
					count++;
				}
			}
		}
		return _v;
	};

	template <class T>
	std::vector<unsigned int> freq(std::vector<T> data, T start, T end, T size)
	{
		unsigned int bucketCount = (end - start + 1) / size;
		std::vector<unsigned int> _freq(bucketCount);
		for (const T &d : data)
		{
			++_freq[(int)((d - start) / size)];
		}
		return _freq;
	}
}