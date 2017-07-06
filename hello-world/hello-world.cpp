// hello-world.cpp

// Includes
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>
#include <thread>
#include <mutex>


// Console output function template
template<class T>
void ConsoleOutput(const std::string& str, const std::vector<T>& myContainer)
{
	std::cout << str.c_str();
	for (const T& a : myContainer) {
		std::cout << a << " ";
	}
	std::cout << '\n';
	return;
}

void hello()
{
	static int i = 0;
	std::cout << "Hello from thread" << i++ << ": " << std::this_thread::get_id() << std::endl;
}


//#############################################################################
int main()
{
	//----------------------------------------------------------------------------
	// Hello World!
	std::cout << "Hello World!\n";

	// Construct a vector of length n.
	const int n_length = 25;
	std::vector<int> myVector;
	myVector.resize(n_length);

	// Initialize the vector
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);
	for (int i = 0; i < n_length; ++i)
	{
		int dice_throw = dis(gen) + dis(gen);
		myVector[i] = dice_throw;
	}
	ConsoleOutput("Pre-sort:\t", myVector);

	// Sort using the default < operator.
	std::sort(myVector.begin(), myVector.end());
	ConsoleOutput("Post-sort:\t", myVector);
	std::cout << '\n';

	// Create thread pool of n threads.
	const int n_threads = 10;
	std::vector<std::thread> myThreadPool;
	for (int i = 0; i < n_threads; ++i) {
		myThreadPool.push_back(std::thread(hello));
	}

	// Wait for threads to complete execution.
	for (auto& thread : myThreadPool) {
		thread.join();
	}


	// Exit
	std::cout << "\n\n";
	system("pause");
	return 0;
}