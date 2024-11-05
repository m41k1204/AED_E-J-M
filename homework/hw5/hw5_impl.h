#ifndef HW5_IMPL_H
#define HW5_IMPL_H

#include <string>
#include <vector>

#include "hw5.h"

void add_edge(std::vector<std::vector<int>>& graph, int from, int to) {
  // COMPLETE AQUI
  if (from >= graph.size()) {
    graph.resize(from + 1);
  }
  graph[from].push_back(to);
}

int n_vertices(std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI

  return graph.size();
}

int n_edges(std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  int count = 0;
  for (const auto& adj_list : graph){
      count += adj_list.size();
  }
  return count;
}

std::vector<int> BFS(std::vector<std::vector<int>> const& graph, int from) {
  // COMPLETE AQUI
  std::vector<int> ret;
  std::vector<bool> visited(graph.size(), false);
  std::queue<int> q;

  visited[from] = true;
  q.push(from);

  while (!q.empty()){
      int current = q.front();
      q.pop();
      ret.push_back(current);

      for (int neighbor : graph[current]){
          if (!visited[neighbor]){
              visited[neighbor] = true;
              q.push(neighbor);
          }
      }
  }
  return ret;
}

std::vector<int> DFS(std::vector<std::vector<int>> const& graph, int from) {
  // COMPLETE AQUI
  std::vector<int> ret;
  std::vector<bool> visited(graph.size(), false);
  std::stack<int> s;

  s.push(from);

  while (!s.empty()){
      int current = s.top();
      s.pop();

        if (!visited[current]){
            visited[current] = true;
            ret.push_back(current);

            for (auto it = graph[current].rbegin(); it != graph[current].rend(); ++it){
                if (!visited[*it]){
                    s.push(*it);
                }
            }
        }
  }
  return ret;
}

std::vector<std::vector<int>> connected_components(
  std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI

  std::vector<std::vector<int>> components;
  std::vector<bool> visited(graph.size(), false);

  for (int i = 0; i < graph.size(); ++i){
      if (!visited[i]){
          std::vector<int> component;
          std::stack<int> s;
          s.push(i);

          while (!s.empty()){
              int current = s.top();
              s.pop();

              if (!visited[current]){
                  visited[current] = true;
                  component.push_back(current);

                  for (int neighbor : graph[current]){
                      if (!visited[neighbor]){
                          s.push(neighbor);
                      }
                  }
              }
          }
          components.push_back(component);
      }
  }
  return ret;
}

int n_connected_components(std::vector<std::vector<int>> const& graph) {
  // COMPLETE AQUI
  return connectec_components(graph).size();
}

#endif
