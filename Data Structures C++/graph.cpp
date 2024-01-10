#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
  private:
    unordered_map< string, unordered_set<string> > adjList;

  public:
    void Print() {
      for( auto const& [ key, vertices ] : adjList ) {
          cout << key;
          cout << " : [";
          for( auto const& vertex : vertices ) {
            cout << vertex << ", "; 
          }
          cout << "]" << endl;
      }
    }
    
    void AddVertex( string vertex );
    void AddEdge( string vertex1, string vertex2 );
    void RemoveVertex( string vertex );
    void RemoveEdge( string vertex1, string vertex2 );
};

void Graph::AddVertex( string vertex ) {
  if( adjList.count( vertex ) == 0 )
    adjList[ vertex ];
}

void Graph::AddEdge( string vertex1, string vertex2 ) {
  if( adjList.count( vertex1 ) != 0 && adjList.count( vertex2 ) != 0 ) {
    adjList.at( vertex1 ).insert( vertex2 );
    adjList.at( vertex2 ).insert( vertex1 );
  }
}

void Graph::RemoveEdge( string vertex1, string vertex2 ) {
  if( adjList.count( vertex1 ) != 0 && adjList.count( vertex2 ) != 0 ) {
    adjList.at( vertex1 ).erase( vertex2 );
    adjList.at( vertex2 ).erase( vertex1 );
  }
}

void Graph::RemoveVertex( string vertex ) {
  if( adjList.count( vertex ) == 0 ) return;
  for( auto const& v : adjList.at( vertex ) ) {
    adjList.at( v ).erase( vertex );
  }

  adjList.erase( vertex );
}

int main() {
    Graph* graph = new Graph();
    graph->AddVertex( "A" );
    graph->AddVertex( "B" );
    graph->AddVertex( "C" );
    graph->AddEdge( "A", "B" );
    graph->AddEdge( "B", "C" );
    graph->AddEdge( "A", "C" );
    graph->Print();
    graph->RemoveEdge("A", "B");
    graph->Print();
    graph->RemoveEdge("A", "C");
    graph->Print();
    graph->RemoveVertex("C");
    graph->Print();
    
  return 0;
}
