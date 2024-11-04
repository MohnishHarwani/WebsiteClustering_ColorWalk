#pragma once
#include <iostream>
#include "graph.hpp"

namespace cs251 {

	struct vertex
	{
		handle m_handle = -1;
		
		size_t m_value = 0;
	};

class max_height {
	
	static void insert(handle handle, int value, std::vector<vertex>& heap);
	static int getMin(std::vector<vertex>& heap);
	static int minChild(int i, std::vector<vertex>& heap);
	static int contains(handle handle, std::vector<vertex>& heap);
	static void heapify(std::vector<vertex>& heap);
	static void siftdown(int n, int i, std::vector<vertex>& heap);
	
public:
	static int calculate(const graph& g);
	
	
};

}
