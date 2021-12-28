#include <string>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

enum Color
{
  RED = 1,
  BLACK = 2
};

template <typename T>
struct Edge
{
  unsigned src;
  unsigned dst;
  T weight;
};

template <typename T>
class Graph
{
public:
  Graph(unsigned N) : V(N) {}

  auto vertices() const { return V; }

  auto &edges() const { return edge_list; }

  auto edges(unsigned v) const
  {
    vector<Edge<T>> edges_from_v;

    for (auto &e : edge_list)
    {
      if (e.src == v)
        edges_from_v.emplace_back(e);
    }

    return edges_from_v;
  }

  void add_edge(Edge<T> &&e)
  {
    if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
      edge_list.emplace_back(e);
    else
      cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
  }

  template <typename U>
  friend ostream &operator<<(ostream &os, const Graph<U> &G);

private:
  unsigned V;
  vector<Edge<T>> edge_list;
};

template <typename U>
ostream &operator<<(ostream &os, const Graph<U> &G)
{
  for (unsigned i = 1; i < G.vertices(); i++)
  {
    os << i << ":\t";

    auto edges = G.edges(i);

    for (auto &e : edges)
      os << "{" << e.dst << ":" << e.weight << "}, ";

    os << endl;
  }

  return os;
}

template <typename T>
auto create_reference_graph()
{
  Graph<T> G(9);

  map<unsigned, vector<pair<unsigned, T>>> edge_map;

  edge_map[1] = {{2, 0}};
  edge_map[2] = {{1, 0}, {3, 0}, {8, 0}};
  edge_map[3] = {{2, 0}, {4, 0}};
  edge_map[4] = {{3, 0}, {6, 0}};
  edge_map[5] = {{7, 0}, {9, 0}};
  edge_map[6] = {{4, 0}};
  edge_map[7] = {{5, 0}};
  edge_map[8] = {{2, 0}, {9, 0}};
  edge_map[9] = {{5, 0}, {8, 0}};

  for (auto &i : edge_map)
    for (auto &j : i.second)
      G.add_edge(Edge<T>{i.first, j.first, j.second});

  return G;
}

template <typename T>
auto bipartite_graph(const Graph<T> &G, unsigned start)
{
  stack<pair<unsigned, Color>> stack;
  set<unsigned> visited;
  vector<pair<unsigned, Color>> visit_order;

  stack.push(pair{start, Color::BLACK});

  while (!stack.empty())
  {
    auto current_vertex = stack.top();
    stack.pop();

    if (visited.find(current_vertex.first) == visited.end())
    {
      visited.insert(current_vertex.first);
      visit_order.push_back(current_vertex);

      for (auto &e : G.edges(current_vertex.first))
      {
        if (visited.find(e.dst) == visited.end())
        {
          stack.push({e.dst, current_vertex.second == Color::BLACK
                                 ? Color::RED
                                 : Color::BLACK});
        }
      }
    }
  }

  return visit_order;
}

bool is_bipartite_graph(vector<pair<unsigned, Color>> &v)
{
  Color prev_color = v.back().second;
  v.pop_back();

  while (!v.empty())
  {
    if (prev_color == v.back().second)
      return false;

    prev_color = v.back().second;
    v.pop_back();
  }

  return true;
}

int main()
{
  using T = unsigned;

  auto G = create_reference_graph<T>();
  cout << "[입력 그래프]" << endl;
  cout << G << endl;

  cout << "[DFS 방문 순서]" << endl;

  auto depth_visit_order = bipartite_graph(G, 1);

  for (auto v : depth_visit_order)
    cout << v.first << "번 정점: \t" << (v.second == Color::BLACK ? "검정색" : "빨간색") << endl;

  cout << "이분 그래프가 " << (is_bipartite_graph(depth_visit_order) ? "맞습니다." : "아닙니다.") << endl;
}