#pragma once
#include <iostream>
#include "graph.hpp"
#include <climits>

namespace cs251 {

	

class color_walk {
	struct vertex
	{
		handle m_handle = -1;
		
		size_t m_value = 0;

		enum color col = NONE;



	};

	static void insert(handle handle, int value, std::vector<vertex>& heap, color col);
	static vertex getMin(std::vector<vertex>& heap);
	static int minChild(int i, std::vector<vertex>& heap);
	static int contains(handle handle, std::vector<vertex>& heap, color col);
	static void heapify(std::vector<vertex>& heap);
	static void siftdown(int n, int i, std::vector<vertex>& heap);

	static bool compare_edges(graph_edge edge1, graph_edge edge2);
	static bool validNextEdge(graph_edge edge1, std::vector<graph_edge> edge_list);
	
public:
	static std::vector<std::pair<char, int>> calculate(const graph& g, handle startHandle);
};

}
