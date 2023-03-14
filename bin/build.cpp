#include <iostream>

int main()
{
	std::string type;

	std::cout << "Choose a type (Debug, Release, Dev): ";
	std::cin >> type;

	if (type == "Debug" || type == "debug" || type == "1")
		system("gcc -c src/*.cpp src/Math/*.cpp src/Core/*.cpp src/Graphic/*.cpp src/Graphic/OpenGL/*.cpp src/Events/*.cpp src/Audio/*.cpp src/Physics/*.cpp src/Network/*.cpp -Wall -g -std=c++17 -Isrc -Iexternal && g++ -o bin/Debug/NAQH *.o -Lexternal/SDL2 -Lexternal/glad -lmingw32 -lSDL2main -lSDL2 -lSDL2_net -lglad && start bin/Debug/NAQH");
	else if (type == "Release" || type == "release" || type == "2")
		system("gcc -c src/*.cpp src/Math/*.cpp src/Core/*.cpp src/Graphic/*.cpp src/Graphic/OpenGL/*.cpp src/Events/*.cpp src/Audio/*.cpp src/Physics/*.cpp src/Network/*.cpp -Wall -O3 -std=c++17 -Isrc -Iexternal && g++ -o bin/Release/NAQH *.o -mwindows -Lexternal/SDL2 -Lexternal/glad -lmingw32 -lSDL2main -lSDL2 -lSDL2_net -lglad -s && start bin/Release/NAQH");
	else if (type == "Dev" || type == "dev" || type == "3")
		system("gcc -c src/*.cpp src/Math/*.cpp src/Core/*.cpp src/Graphic/*.cpp src/Graphic/OpenGL/*.cpp src/Events/*.cpp src/Audio/*.cpp src/Physics/*.cpp src/Network/*.cpp -Wall -O3 -std=c++17 -Isrc -Iexternal && g++ -o bin/Dev/NAQH *.o -mwindows -Lexternal/SDL2 -Lexternal/glad -lmingw32 -lSDL2main -lSDL2 -lSDL2_net -lglad -s && start bin/Dev/NAQH");

	system("move *.o bin/obj");
	//system("pause");
}