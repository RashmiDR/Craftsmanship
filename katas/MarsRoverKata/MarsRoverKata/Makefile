GXX=/usr/bin/g++
CPPFLAGS=-c -I/Users/RashmiDR/Craftsmanship/gtest-1.6.0/include

rover_test: rover.o main.o libgtest.a
	$(GXX) -o rover_test rover.o main.o libgtest.a

libgtest.a: getst-all.o
	 ar rc libgtest.a /Users/RashmiDR/Craftsmanship/gtest-1.6.0/src/gtest-all.o
	ranlib libgtest.a

getst-all.o: /Users/RashmiDR/Craftsmanship/gtest-1.6.0/src/gtest-all.cc
	$(GXX) $(CPPFLAGS) -I/Users/RashmiDR/Craftsmanship/gtest-1.6.0 -o /Users/RashmiDR/Craftsmanship/gtest-1.6.0/src/gtest-all.o /Users/RashmiDR/Craftsmanship/gtest-1.6.0/src/gtest-all.cc

rover.o: rover.cpp
	$(GXX) $(CPPFLAGS) -o rover.o rover.cpp

main.o: main.cpp
	$(GXX) $(CPPFLAGS) -o main.o main.cpp

