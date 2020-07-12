######################################################################
### @file makefile
### @author Tristan Fountain
### @brief Makefile for Game Engine
######################################################################

.PHONY: all clean

CXX = /usr/bin/g++
CXXFLAGS = -g -Wall -W -pedantic-errors -std=c++17

SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
HEADERS = $(wildcard *.h) $(wildcard */*.h)

OBJECTS = $(SOURCES:%.cpp=%.o)
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

default: driver

%.o: %.cpp
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

driver: $(OBJECTS)
	@echo "Building $@..."
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SFMLFLAGS)
	@echo "Success!"
	@echo ""

clean:
	-@rm -f core
	-@rm -f driver
	-@rm -f depend
	-@rm -f $(OBJECTS)

# Automatically generate dependencies and include them in makefile
depend: $(SOURCES) $(HEADERS)
	@echo "Generating dependencies"
	@$(CXX) -MM *.cpp > $@


-include depend
