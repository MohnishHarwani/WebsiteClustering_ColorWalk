#include "max_height.hpp"
#include <climits>

using namespace cs251;

int max_height::calculate(const graph& g) {

	int v_count = g.peek_vertices().size();

	std::vector<vertex> heap;

	std::vector<int> distTo;
	distTo.resize(v_count);
	std::vector<bool> visited;
	visited.resize(v_count);
	std::vector<graph_edge> edgeTo;
	edgeTo.resize(v_count);

	for (int i = 0; i < v_count; i++) {
		visited[i] = false;
		distTo[i] = INT_MIN;
		edgeTo[i] = {};
	}

	distTo[0] = 0;
	vertex a = {0, 0};

	insert(0, 0, heap);
	

	while (heap.size() != 0) {


		int vertex = getMin(heap);
		visited[vertex] = true;
		
		for (graph_edge edge: g.peek_edges(vertex)) {
			
			if (visited[edge.m_destinationHandle]) {
				continue;
			}

			if (edge.m_weight > distTo[edge.m_destinationHandle]) {
				edgeTo[edge.m_destinationHandle] = edge;
				distTo[edge.m_destinationHandle] = edge.m_weight;

				int index = contains(edge.m_destinationHandle, heap);

				if (index != -1) {
					heap[index].m_value = edge.m_weight;
					heapify(heap);
				} else {
					insert(edge.m_destinationHandle, edge.m_weight, heap);
				}

			}



		}
	}
	int count = 0;
	int minEdge = INT_MAX;
	for (graph_edge edge: edgeTo) {
		if (count == 0) {
			count++;
			continue;
		}
		if (minEdge > edge.m_weight) {
			minEdge = edge.m_weight;
		}
	}

	return minEdge;
}




int max_height::contains(handle handle, std::vector<vertex>& heap) {
	int i = 0;
	for (vertex index: heap) {
		if (index.m_handle == handle) {
			return i;
		}
		i++;
	}

	return -1;
}

void max_height::insert(handle handle, int value, std::vector<vertex>& heap) {
	int i = heap.size();
	vertex a;
	a.m_handle = handle;
	a.m_value = value;
	heap.push_back(a);

	

	int parent = (i-1)/2;

	while ((i > 0 ) && (heap[i].m_value > heap[parent].m_value)) {
		vertex g = {heap[i].m_handle, heap[i].m_value};
		heap[i].m_handle = heap[parent].m_handle;
		heap[i].m_value = heap[parent].m_value;
		heap[parent] = g;


		i = parent;
		parent = (i-1)/2;
	}

}

int max_height::getMin(std::vector<vertex>& heap) {
	int handle = heap[0].m_handle;

	heap[0] = heap[heap.size() - 1];

	heap.pop_back();
	int i = 0;

	int min = minChild(i, heap);


	while ((min < heap.size()) && (heap[i].m_value < heap[min].m_value)) {
		vertex g = {heap[i].m_handle, heap[i].m_value};
		heap[i].m_handle = heap[min].m_handle;
		heap[i].m_value = heap[min].m_value;
		heap[min] = g;

		i = min;
		min = minChild(i, heap);
	}

	return handle;
}


int max_height::minChild(int i, std::vector<vertex>& heap) {
	int left_child = (2 * i) + 1;
	int right_child = (2 * i) + 2;
	if (right_child >= heap.size()) {
		return left_child;
	}
	if (heap[left_child].m_value > heap[right_child].m_value) {
		return left_child;
	} else {
		return right_child;
	}
}

void max_height::heapify(std::vector<vertex>& heap) {
	int n = heap.size();
	for (int i = (n/2) - 1; i >=0; i--) {
		siftdown(n, i, heap);
	}
}

void max_height::siftdown(int n, int i, std::vector<vertex>& heap) {
	int min = minChild(i, heap);

	while ((min < heap.size()) && (heap[i].m_value < heap[min].m_value)) {
		vertex g = {heap[i].m_handle, heap[i].m_value};
		heap[i].m_handle = heap[min].m_handle;
		heap[i].m_value = heap[min].m_value;
		heap[min] = g;

		i = min;
		min = minChild(i, heap);
	}
}























/*
void min_heap::push(int value, handle handle)
{
	vertex a{};
	a.m_handle = handle;
	a.m_value = value;

	int i = m_nodes.size();
	m_nodes.push_back(a);
	int p = (i - 1) / 2;

	while ((i > 0) && (m_nodes[i].m_value < m_nodes[p].m_value)) {
		a = m_nodes[i];
		m_nodes[i] = m_nodes[p];
		m_nodes[p] = a;
		i = p;
		p = (p - 1) / 2;
	}

	m_nodeSize++;
}


int min_heap::top() {
	vertex temp = m_nodes[0];
	remove();
	return temp.m_handle;
}




void min_heap::remove() {
	int slotToRemove = 0;

	vertex a = m_nodes[m_nodes.size() - 1];
	m_nodes[m_nodes.size() - 1] = m_nodes[slotToRemove];
	m_nodes[slotToRemove] = a;

	m_nodes.pop_back();

	siftdown(slotToRemove);

	m_nodeSize--;
}


void min_heap::siftdown(int i) {
	int m = minChild(i);
	vertex a{};
	while ((m < m_nodes.size()) && (m_nodes[i].m_value < m_nodes[m].m_value)) {
		a = m_nodes[i];
		m_nodes[i] = m_nodes[m];
		m_nodes[m] = a;
		i = m;
		m = minChild(i);
	}
}

int min_heap::minChild(int i) {
	int left_child = (2 * i) + 1;
	if (left_child >= m_nodes.size()) {
		return m_nodes.size();
	}
	int right_child = (2 * i) + 2;
	if (right_child >= m_nodes.size()) {
		return left_child;
	}
	if (m_nodes[left_child].m_value > m_nodes[right_child].m_value) {
		return left_child;
	} else {
		return right_child;
	}
}

int min_heap::size() {
	return m_nodes.size();
}
*/





