#include "scc.hpp"
#include "climits"

using namespace cs251;

int scc::search(const graph& g) {

	int index = 0;
  std::vector<int> stack;
  std::vector<std::vector<int>> SCC;
  std::vector<int> indexMap;
  std::vector<int> lowLinkMap;
  std::vector<bool> onStack;
  

  int vertexCount = g.peek_vertices().size();
  indexMap.resize(vertexCount, -1);
  lowLinkMap.resize(vertexCount);
  onStack.resize(vertexCount, false);


  for (int v = 0; v < g.peek_vertices().size(); v++) {
    if (indexMap[v] == -1) {
      strongConnect(v, index, stack, SCC, indexMap, lowLinkMap, onStack, g);
    }
  }

  return SCC.size();
}

void scc::strongConnect(int v, int& index, std::vector<int>& stack, std::vector<std::vector<int>>& SCC, std::vector<int>& indexMap, std::vector<int>& lowLinkMap, std::vector<bool>& onStack, const graph& g) {
  indexMap[v] = index;
  lowLinkMap[v] = index;
  index++;
  

  stack.push_back(v);
  onStack[v] = true;

  for (graph_edge edge: g.peek_edges(v)) {
    if (indexMap[edge.m_destinationHandle] == -1) {

      strongConnect(edge.m_destinationHandle, index, stack, SCC, indexMap, lowLinkMap, onStack, g);
      lowLinkMap[v] = min(lowLinkMap[v], lowLinkMap[edge.m_destinationHandle]);

    } else if (onStack[edge.m_destinationHandle]) {
      

      lowLinkMap[v] = min(lowLinkMap[v], indexMap[edge.m_destinationHandle]);
    }
  }

  if (lowLinkMap[v] == indexMap[v]) {
    std::vector<int> newSCC;
    int w = -1;
    while ((w != v) && (!stack.empty())) {
      w = stack[stack.size() - 1];
      stack.pop_back();
      onStack[w] = false;
      newSCC.push_back(w);
    }

    


    if (newSCC.size() != 0) {
      SCC.push_back(newSCC);
    }
  }

}

bool scc::indexMapContains(int v, std::vector<int> indexMap) {
  if (indexMap[v] == -1) {
    return false;
  }
  return true;

}

int scc::min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

