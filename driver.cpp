#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "weightedGraph.cpp"

int main(){
  std::string filepath;
  std::cout << "What's the file path?" << std::endl;
  std::cin >> filepath;
  std::ifstream file(filepath);

  mine::weightedGraph graphy;



// start graph
  std::string singleVert;
  std::string startVert;
  std::string destVert;
  std::string edgeWeight;
  for(std::string line; getline(file, line);){
    if(line.find(',') == std::string::npos){
      singleVert = line;
      graphy.addVert(singleVert);
    }
    else{
      startVert = line.substr(0, line.find(','));
      line = line.substr(line.find(',') + 1);
      if(line.find(',') == std::string::npos){
        continue;
      }
      destVert = line.substr(0, line.find(','));
      line = line.substr(line.find(',') + 1);
      if(line.find(',') == std::string::npos)
        edgeWeight = line;
      else{
        continue;
      }
      graphy.addEdge(startVert, destVert, edgeWeight);
    }
  }
  












  int numOfVerts;
  numOfVerts = graphy.numberOfVerts();
  std::cout << "Number of vertices: " << numOfVerts << std::endl;








  std::cout << "Vertices with no inbound edges:" << std::endl;
  std::list<std::string> roots;
  roots = graphy.getRoots();
  for(std::string s : roots){
    std::cout << s << std::endl;
  }
  std::cout << std::endl;









  std::cout << "Vertices with self edges:" << std::endl;
  std::list<std::string> selfies;
  selfies = graphy.getSelfies();
  for(std::string s : selfies){
    std::cout << s << " ";
  }
  std::cout << std::endl;








  std::cout << "Vertices with no outbound edges:" << std::endl;
  std::list<std::string> leaves;
  leaves = graphy.getLeaves();
  for(std::string s : leaves){
    std::cout << s << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
