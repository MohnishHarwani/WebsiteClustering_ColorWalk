#include <iostream>
#include "graph.hpp"
#include <sstream>
#include <string>

using namespace cs251;


enum color getColor(std::string a) {
	if (a.compare("R") == 0) {
		return RED;
	} else if (a.compare("G") == 0) {
		return GREEN;
	} else if (a.compare("B") == 0) {
		return BLUE;
	} else {
		return NONE;
	}
}

std::vector<std::string> splitString(std::string str) {
	char delimiter = ' ';
    std::vector<std::string> list;
    std::istringstream stream(str);
    std::string token;
    while (std::getline(stream, token, delimiter)) {
        list.push_back(token);
    }
    return list;
}

void graph::read_edge_weights(const std::string& filePath) {
	graph g{};

	std::ifstream file(filePath);

	std::string line;
	std::getline(file, line);

	int first_space = line.find_first_of(" ");
	
	std::string number = line.substr(0, line.find_first_of(" "));
	int vertex_count = std::stoi(number);
	number = line.substr(line.find_first_of(" "));
	int edge_count = std::stoi(line);

	m_vertices.resize(vertex_count);

	std::getline(file, line);

	std::vector<std::string> list = splitString(line);

	bool weights = (list.size() == 3);

	if (weights) {
		int vertex1 = std::stoi(list[0]);
		int vertex2 = std::stoi(list[1]);
		int weight = std::stoi(list[2]);

		graph_edge edge = {weight, vertex2, NONE};

		m_vertices[vertex1].m_edges.push_back(edge);

		while (std::getline(file, line)) {
			std::vector<std::string> list = splitString(line);
			vertex1 = std::stoi(list[0]);
			vertex2 = std::stoi(list[1]);
			weight = std::stoi(list[2]);

			//std::cout << vertex1 << '\n';
			//std::cout << vertex2 << '\n';
			//std::cout << weight << '\n';

			edge = {weight, vertex2, NONE};

			m_vertices[vertex1].m_edges.push_back(edge);
		}
	} else {
		// No weights - part 3

		//std::cout << "NO WEIGHTS" << std::endl;
		
		int vertex1 = std::stoi(list[0]);
		int vertex2 = std::stoi(list[1]);

		//std::cout << vertex1 << '\n';
		//std::cout << vertex2 << '\n';

		graph_edge edge = {};
		edge.m_destinationHandle = vertex2;

		m_vertices[vertex1].m_edges.push_back(edge);

		while (std::getline(file, line)) {
			std::vector<std::string> list = splitString(line);
			vertex1 = std::stoi(list[0]);
			vertex2 = std::stoi(list[1]);

			//std::cout << vertex1 << '\n';
			//std::cout << vertex2 << '\n';

			edge = {};
			edge.m_destinationHandle = vertex2;

			m_vertices[vertex1].m_edges.push_back(edge);
		}
	}
}

void graph::read_edge_colors(const std::string& filePath) {
	graph g{};

	std::ifstream file(filePath);

	std::string line;
	std::getline(file, line);

	int first_space = line.find_first_of(" ");
	
	std::string number = line.substr(0, line.find_first_of(" "));
	int vertex_count = std::stoi(number);
	number = line.substr(line.find_first_of(" "));
	int edge_count = std::stoi(line);

	m_vertices.resize(vertex_count);

	
	while (std::getline(file, line)) {
		std::vector<std::string> list = splitString(line);
		int vertex1 = std::stoi(list[0]);
		int vertex2 = std::stoi(list[1]);
		int weight = std::stoi(list[2]);
		enum color color = getColor(list[3]);

		std::cout << vertex1 << std::endl;
		std::cout << vertex2 << std::endl;
		std::cout << weight << std::endl;
		std::cout<< list[3] << std::endl;

		graph_edge edge = {weight, vertex2, color};

		m_vertices[vertex1].m_edges.push_back(edge);
	}
	
}
std::vector<graph_vertex> graph::peek_vertices() const {
	return m_vertices;
}

std::vector<graph_edge> graph::peek_edges(int index) const {
	return m_vertices[index].m_edges;
}


























/*
	int vertexCount;
	file >> vertexCount;
	int edgeNumber;
	file >> edgeNumber;

	g.m_vertices.resize(vertexCount);

	for (int i = 0; i < vertexCount; i++) {
		g.m_vertices[i].m_handle == i;
	}


	while (!file.eof()) {
		int initialVertexHandle;
		file >> initialVertexHandle;

		int destinationVertex;
		file >> destinationVertex;

		int edgeWeight;
		file >> edgeWeight;

		graph_edge a;
		a.m_destinationHandle = destinationVertex;
		a.m_weight = edgeWeight;
		a.col = NONE;

		graph_edge b;
		b.m_destinationHandle = initialVertexHandle;
		b.m_weight = edgeWeight;
		b.col = NONE;

		g.m_vertices[initialVertexHandle].m_edges.push_back(a);
		g.m_vertices[destinationVertex].m_edges.push_back(b);
	}
*/
