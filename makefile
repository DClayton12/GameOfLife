#target: dependencies
#	rule to build
#

gameoflife: gamelife.cpp gameinterface.h gameimplementation.cpp
	g++ -std=c++0x gamelife.cpp gameimplementation.cpp -o gameoflife