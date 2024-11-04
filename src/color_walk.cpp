#include "color_walk.hpp"

using namespace cs251;

static enum color next_color(color color) {
	if (color == RED) {
		return GREEN;
	} else if (color == GREEN) {
		return BLUE;
	} else if (color == BLUE) {
		return RED;
	} else {
		return NONE;
	}
}

std::vector<std::pair<char, int>> color_walk::calculate(const graph& g, const handle startHandle) {
	std::vector<vertex> heap;

	std::vector<std::vector<int>> dist;
	dist.resize(g.peek_vertices().size());

	std::vector<std::vector<graph_edge>> prev;
	prev.resize(g.peek_vertices().size());


	std::vector<std::vector<color>> starting_colors;
	starting_colors.resize(g.peek_vertices().size());
	for(int i = 0; i < starting_colors.size(); i++) {
		starting_colors[i].resize(3);
		starting_colors[i][0] = NONE;
		starting_colors[i][1] = NONE;
		starting_colors[i][2] = NONE;
	}


	for (int i = 0; i < dist.size(); i++) {
		dist[i].resize(3);
		if (i == startHandle) {
			dist[i][0] = 0;
			dist[i][1] = 0;
			dist[i][2] = 0;
		} else {
			dist[i][0] = INT_MAX;
			dist[i][1] = INT_MAX;
			dist[i][2] = INT_MAX;
		}

		prev[i].resize(3);
	}

	


	for (int i = 0; i < g.peek_vertices().size(); i++) {
		if (i != startHandle) {
			insert(i, INT_MAX, heap, RED);
			insert(i, INT_MAX, heap, BLUE);
			insert(i, INT_MAX, heap, GREEN);
		} else {
			insert(i, 0, heap, RED);
			insert(i, 0, heap, BLUE);
			insert(i, 0, heap, GREEN);
		}
	}

	while (heap.size() != 0) {
		vertex current = getMin(heap);

		int placement = int(current.col);

		
		if (dist[current.m_handle][placement] == INT_MAX) {
			continue;
		}

		for (graph_edge edge: g.peek_edges(current.m_handle)) {
			

			if (edge.col == current.col) {

				int destinationPlacement = int(next_color(edge.col));

				int destination = edge.m_destinationHandle;
				int d = dist[current.m_handle][placement] + edge.m_weight;

				if (d <= dist[destination][destinationPlacement]) {

					int k = dist[destination][destinationPlacement];
					dist[destination][destinationPlacement] = d;

					prev[destination][destinationPlacement] = edge;

					color colToPropogate;


					if (current.m_handle == startHandle) {
						colToPropogate = edge.col;
					} else {
						colToPropogate = starting_colors[current.m_handle][placement];
					}

					
					vertex a = {destination, d, next_color(edge.col)};


					if (d == k) {
						if (colToPropogate < starting_colors[destination][destinationPlacement]) {
							starting_colors[destination][destinationPlacement] = colToPropogate;
						}
					} else {
						starting_colors[destination][destinationPlacement] = colToPropogate;
					}


					int location = contains(destination, heap, next_color(edge.col));
					if (location != -1) {
						heap[location] = a;
						heapify(heap);
					} 
				}

			} 
		}
		
	}
	
	std::vector<std::pair<char, int>> final_distances;
	final_distances.resize(g.peek_vertices().size());

	std::pair<char, int> temp_pair = {'-', INT_MAX};

	for (int i = 0; i < final_distances.size(); i++) {
		final_distances[i] = temp_pair;
	}


	for (int i = 0; i < dist.size(); i++) {
		for (int k = 0; k < 3; k++) {
			if (starting_colors[i][k] == RED) {
				int a = dist[i][k];
				if (a != INT_MAX) {
					if (a < final_distances[i].second) {
						temp_pair = { 'R', a };
						final_distances[i] = temp_pair;
					}
				}
			} 
		}
	}

	for (int i = 0; i < dist.size(); i++) {
		for (int k = 0; k < 3; k++) {
			if (starting_colors[i][k] == GREEN) {
				int a = dist[i][k];
				if (a != INT_MAX) {
					if (a < final_distances[i].second) {
						temp_pair = { 'G', a };
						final_distances[i] = temp_pair;
					}
				}
			}
		}
	}

	for (int i = 0; i < dist.size(); i++) {
		for (int k = 0; k < 3; k++) {
			if (starting_colors[i][k] == BLUE) {
				int a = dist[i][k];
				if (a != INT_MAX) {
					if (a < final_distances[i].second) {
						temp_pair = { 'B', a };
						final_distances[i] = temp_pair;
					}
				}
			}
		}
	}


	for (int i = 0; i < final_distances.size(); i++) {
		if (final_distances[i].second == INT_MAX) {
			final_distances[i].second = -1;
		}
	}

	final_distances[startHandle].second = 0;

	return final_distances;

}






bool color_walk::validNextEdge(graph_edge edge1, std::vector<graph_edge> edge_list) {
	for (int i = 0; i < edge_list.size(); i++) {
		if (edge1.col == next_color(edge_list[i].col)){
			return true;
		}
	}

	return false;
}



bool color_walk::compare_edges(graph_edge edge1, graph_edge edge2) {
	if ((edge1.col == edge2.col) && (edge1.m_destinationHandle == edge2.m_destinationHandle) && (edge1.m_weight == edge2.m_weight)) {
		return true;
	}
	return false;
}


int color_walk::contains(handle handle, std::vector<vertex>& heap, color col) {
	int i = 0;
	for (vertex index: heap) {
		if ((index.m_handle == handle) && (index.col == col)) {
			return i;
		}
		i++;
	}

	return -1;
}

void color_walk::insert(handle handle, int value, std::vector<vertex>& heap, color col) {
	int i = heap.size();
	vertex a;
	a.m_handle = handle;
	a.m_value = value;
	a.col = col;
	heap.push_back(a);

	

	int parent = (i-1)/2;

	while ((i > 0 ) && (heap[i].m_value < heap[parent].m_value)) {
		vertex g = {heap[i].m_handle, heap[i].m_value, heap[i].col};
		heap[i].m_handle = heap[parent].m_handle;
		heap[i].m_value = heap[parent].m_value;
		heap[i].col = heap[parent].col;

		heap[parent] = g;


		i = parent;
		parent = (i-1)/2;
	}

}

color_walk::vertex color_walk::getMin(std::vector<vertex>& heap) {
	vertex toReturn = heap[0];

	heap[0] = heap[heap.size() - 1];

	heap.pop_back();
	int i = 0;

	int min = minChild(i, heap);


	while ((min < heap.size()) && (heap[i].m_value > heap[min].m_value)) {
		vertex g = {heap[i].m_handle, heap[i].m_value, heap[i].col};
		heap[i].m_handle = heap[min].m_handle;
		heap[i].m_value = heap[min].m_value;
		heap[i].col = heap[min].col;
		heap[min] = g;

		i = min;
		min = minChild(i, heap);
	}

	return toReturn;
}


int color_walk::minChild(int i, std::vector<vertex>& heap) {
	int left_child = (2 * i) + 1;
	int right_child = (2 * i) + 2;
	if (right_child >= heap.size()) {
		return left_child;
	}
	if (heap[left_child].m_value < heap[right_child].m_value) {
		return left_child;
	} else {
		return right_child;
	}
}

void color_walk::heapify(std::vector<vertex>& heap) {
	int n = heap.size();
	for (int i = (n/2) - 1; i >=0; i--) {
		siftdown(n, i, heap);
	}
}

void color_walk::siftdown(int n, int i, std::vector<vertex>& heap) {
	int min = minChild(i, heap);

	while ((min < heap.size()) && (heap[i].m_value > heap[min].m_value)) {
		vertex g = heap[i];
		heap[i] = heap[min];
		heap[min] = g;

		i = min;
		min = minChild(i, heap);
	}
}