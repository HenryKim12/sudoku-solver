CXX := g++
CXXFLAGS := -c
RM := -del

solve: main.o solver.o
	$(CXX) main.o solver.o -o solve

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

solver.o: solver.cpp solver.hpp
	$(CXX) $(CXXFLAGS) solver.cpp

clean: 
	$(RM) *.o solve