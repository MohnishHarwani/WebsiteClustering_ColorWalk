#pragma once
#include "graph.hpp"

namespace cs251 {

class scc {
	static void strongConnect(int v, int& index, std::vector<int>& stack, std::vector<std::vector<int>>& SCC,
  			std::vector<int>& indexMap, std::vector<int>& lowLinkMap, std::vector<bool>& onStack, const graph& g);

	static bool indexMapContains(int v, std::vector<int> indexMap);
	static int min(int a, int b);
public:
	static int search(const graph& g);
};

}
