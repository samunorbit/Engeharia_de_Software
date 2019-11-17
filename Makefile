OBJS = main.cpp entidades.cpp interface.cpp

OBJ_NAME = sistema

CC = g++

INCLUDE_PATHS =

LIBRARY_PATHS =

FLAGS = -std=c++11

all : $(OBJS)
	g++ $(OBJS)  $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(FLAGS) -o $(OBJ_NAME)
