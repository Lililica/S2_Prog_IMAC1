#include <iostream>
#include "Graph.hpp"

void display_list_graph(std::unordered_map<int, std::vector<Graph::WeightedGraphEdge>> adjacency_list){
    std::cout << "{";
    for(int i{0}; i < adjacency_list.size(); i++){
        std::cout << i << ", {";
        for(Graph::WeightedGraphEdge edge : adjacency_list[i]){
            std::cout << "{" << edge.to << ", " << edge.weight << "},";
        }
        std::cout << "}," << std::endl;
    }
    std::cout << "}" << std::endl;
}

void display_vec_int(std::vector<int> v){
    std::cout << "[";
    for(int i{0}; i < v.size(); i++){
        std::cout << v[i];
        if(i != v.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main(){
    std::cout << "Exercice 1 - Td7" << std::endl;
    std::cout << std::endl;

    // Premier graphe

    std::vector<std::vector<float>> matrix_adjency {
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0}
    };

    std::cout << "La liste d'adjacence du premier graphe : " << std::endl;
    Graph::WeightedGraph firstGraph = Graph::build_from_adjacency_matrix(matrix_adjency);
    display_list_graph(firstGraph.adjacency_list);
    std::cout << std::endl;

    // Second graphe

    Graph::WeightedGraph secondGraph {};
    secondGraph.add_directed_edge(0, 1, 1);
    secondGraph.add_directed_edge(0, 4, 2);
    secondGraph.add_directed_edge(1, 2, 2);
    secondGraph.add_directed_edge(1, 3, 4);
    secondGraph.add_directed_edge(2, 3, 1);
    secondGraph.add_directed_edge(3, 4, 6);

    std::cout << "La liste d'adjacence du premier graphe : " << std::endl;
    display_list_graph(secondGraph.adjacency_list);
    std::cout << std::endl;

    std::cout << "Impression par DFS : " << std::endl;
    secondGraph.print_DFS(0);

    std::cout << "Impression par BFS : " << std::endl;
    secondGraph.print_BFS(0);

    std::cout << "Impression par Dijkstra : " << std::endl;
    display_vec_int(dijkstra_search(secondGraph));
}