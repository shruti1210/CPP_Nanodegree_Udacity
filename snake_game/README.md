# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Additions
* The user can select a initial input speed for the snake.
* User can input it's name. 
* The game can store the user input data and score results over the games in "History.txt" file.
* Memory Management: SDL_WIindow and SDL_Renderer are stored as unique_ptr's inside Renderer
* Because of the use of unique pointer used, the destrutor is commented out. 


## Project Rubrics
* [x] README (All Rubric Points REQUIRED):
  * [x] A README with instructions is included with the project.
  * [x] The README indicates which project is chosen.
  * [x] The README includes information about each rubric point addressed.
* [x] Compiling and Testing (All Rubric Points REQUIRED)
* [x] The submission must compile and run.
* [x] Loops, Functions, I/O
  * [x] The project demonstrates an understanding of C++ functions and control structures.
  * [x] The project reads data from a file and process the data, or the program writes data to a file. Program reads the data about discrete speeds and the name of the user. This user-defined speed is used to define the speed of snake at which it approaches the food. And all these values, scores, and user name are stores in a file called "History.txt"
  * [x] The project accepts user input and processes the input. --> User can change the input speed: using 0 and 1. 
* [x] Object Oriented Programming
  * [x] The project uses Object Oriented Programming techniques. --> Controller class is located inside Game in order to hide it from main and abstract.
  * [x] Classes use appropriate access specifiers for class members. 
  * [x] Class constructors utilize member initialization lists.
  * [x] Classes abstract implementation details from their interfaces. --> Snake hides to controller its last moved direction.
  * [x] Classes encapsulate behavior. --> Controller only forwards the direction to move, then snake decides if it is allowed or not by checking last direction moved.
  * [ ] Classes follow an appropriate inheritance hierarchy.
  * [ ] Overloaded functions allow the same function to operate on different parameters.
  * [ ] Derived class functions override virtual base class functions.
  * [ ] Templates generalize functions in the project.
* [x] Memory Management
  * [x] The project makes use of references in function declarations.
  * [x] The project uses destructors appropriately. --> Have set the proper destructors for SDL_Window and SDL_Renderer unique_ptr's, so no memory leaks.
  * [x] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. --> Smart pointers are used instead of raw pointers, which ise the RAII principle, deallocating memory as soon as their owner class goes out of scope.
  * [ ] The project follows the Rule of 5. 
  * [ ] The project uses move semantics to move data, instead of copying it, where possible.
  * [x] The project uses smart pointers instead of raw pointers. -->  SDL_Window and SDL_Renderer inside Renderer, use smart pointers.
* [ ] Concurrency
  * [ ] The project uses multithreading.
  * [ ] A promise and future is used in the project.
  * [ ] A mutex or lock is used in the project.
  * [ ] A condition variable is used in the project.
