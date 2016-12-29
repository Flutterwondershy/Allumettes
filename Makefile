CXX = g++
EXEC = bin/Sortie
DEBUG = yes

ifeq ($(DEBUG),yes)
	CXXFLAGS = -g -W -Wall
else
	CXXFLAGS =
endif

all : $(EXEC)

$(EXEC) : obj/main.o obj/Allumettes.o
	$(CXX) $^ -o $(EXEC)

obj/%.o : %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clear:
	rm obj/* -f
	rm bin/* -f

