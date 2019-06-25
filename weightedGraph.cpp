#include <map>
#include <list>
#include<string>

namespace mine{

class weightedGraph{
  std::map<std::string, std::map<std::string, std::string> > vertices;
  
  public:
  int numberOfVerts();
  bool addVert(std::string newVert);
  bool addEdge(std::string startVert, std::string destVert,
                  std::string weight);
  bool contains(std::string targetVert);
  std::list<std::string> getRoots();
  std::list<std::string> getLeaves();
  std::list<std::string> getSelfies();
};

int weightedGraph::numberOfVerts(){
  return vertices.size();
}

bool weightedGraph::addVert(std::string newVert){
  vertices.emplace(newVert, std::map<std::string, std::string>());
  return contains(newVert);
}

bool weightedGraph::addEdge(std::string startVert, std::string destVert,
                  std::string weight){
  addVert(startVert);
  addVert(destVert);
  if(contains(startVert)){
    vertices[startVert].emplace(destVert, weight);
  }
  return true;
}

bool weightedGraph::contains(std::string targetVert){
  if(vertices.count(targetVert) == 1)
    return true;
  return false;
}

std::list<std::string> weightedGraph::getRoots(){
  std::list<std::string> rootVerts;
  std::list<std::string> notRoots;
  for(auto& vertice: vertices){
    rootVerts.push_back(vertice.first);
    for(auto& edgeDestination: vertice.second){
      notRoots.push_back(edgeDestination.first);
    }
  }
  notRoots.sort();
  notRoots.unique();
  for(auto notARoot: notRoots){
    rootVerts.remove(notARoot);
  }
  return rootVerts;
}

std::list<std::string> weightedGraph::getLeaves(){
  std::list<std::string> leafVerts;
  for(auto& vertice: vertices){
    if(vertice.second.empty())
      leafVerts.push_back(vertice.first);
  }
  return leafVerts;
}

std::list<std::string> weightedGraph::getSelfies(){
  std::list<std::string> selfVerts;
  for(auto& vertice: vertices){
    if(vertice.second.count(vertice.first))
      selfVerts.push_back(vertice.first);
  }
  return selfVerts;
}

}

