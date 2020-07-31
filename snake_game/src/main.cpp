#include <iostream>
#include <fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  	std::string str;

	std::cout<<"What is your name?"<<"\n"; 
	std::getline(std::cin, str);

  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  // add a function to update user defined speed
  game.ChangeSpeed();
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  
  std::ofstream myfile;
    myfile.open ("/home/workspace/CppND-Capstone-Snake-Game/src/history.txt", std::ios::app);
    if (myfile.is_open()){
    myfile  << "Name: " <<str << "   Score:     " << game.GetScore() << "   Size:      " << game.GetSize() <<std::endl;
    	}
     myfile.close();

  
  return 0;
}