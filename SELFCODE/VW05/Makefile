# Makefile - Build và chạy stress test
# Usage:
#   make          → build tất cả
#   make stress   → chạy 100 test
#   make stress N=200           → chạy 200 test
#   make stress N=50 STOP=--stop-on-fail
#   make clean

CXX     = g++
CXXFLAGS = -O2 -std=c++17

.PHONY: all stress clean

all: gen solution
	@echo "✓ Build xong. Chạy: make stress"

gen: gen.cpp
	$(CXX) $(CXXFLAGS) -o gen gen.cpp
	@echo "✓ Compiled gen"

solution: solution.cpp
	$(CXX) $(CXXFLAGS) -o solution solution.cpp
	@echo "✓ Compiled solution"

code.class: code.java
	javac code.java
	@echo "✓ Compiled code.java"

stress: gen solution code.class
	python3 stress.py $(N) $(STOP)

clean:
	rm -f gen solution code.class *.o
	rm -rf failed_tests __pycache__
	@echo "✓ Cleaned"
