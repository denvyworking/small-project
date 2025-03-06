#include <iostream>
#include <unordered_map>
#include <queue>
#include <limits.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii; // (расстояние, вершина)

void dijkstra(unordered_map<int, unordered_map<int, int>> &graph, int start){
    unordered_map<int, int> distance; // создаем словарь для хранения веса конкретной вершины 
    for(const auto& count : graph){
        distance[count.first] = INT_MAX; // каждой вершине присваиваем максимальный вес
    }
    distance[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> priority_queue;
    priority_queue.push(pair(0, start));

    while(!priority_queue.empty()){
        // достал первый элемент пары из приоритетной очереди(расстояние)
        int current_distance = priority_queue.top().first;
        // достал второй элемент пары из приоритетной очереди(вершину)
        int current_vertex = priority_queue.top().second;
        // удалил первый элемент из очереди
        priority_queue.pop();

        if(current_distance > distance[current_vertex]) continue;
        for(const auto& neighbor : graph.at(current_vertex)){
            int neighbor_vertex = neighbor.first;
            int neighbor_weight = neighbor.second;
            int maybe_distance = neighbor_weight + current_distance;
            if(maybe_distance < distance[neighbor_vertex]){
                distance[neighbor_vertex] = maybe_distance;
                priority_queue.push(pair(distance[neighbor_vertex], neighbor_vertex));
            }
        }
        
    }

    for (const auto& dist : distance) {
        cout << "Vertex " << dist.first << " has distance " << dist.second << endl;
    }

}

int main(){
    unordered_map<int, unordered_map<int, int>> graph = {
        {0, {{1, 4}, {2, 1}}},
        {1, {{3, 1}}},
        {2, {{1, 2}, {3, 5}}},
        {3, {}}
    };

    dijkstra(graph, 0);

    return 0;
}