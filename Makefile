
all: 
	Prj_stage_1
	
Prj_stage_1: 
	main.o ShuntYard.o Str2Vector.o
	g++ -o ShuntYard main.o ShuntYard.o Str2Vector.o
	
main.o: 
	main.cpp count.H
	g++ -c main.cpp
	
ShuntYard.o: 
	ShuntYard.cpp ShuntYard.h
	g++ -c ShuntYard.cpp
	
Str2Vector.o:
	Str2Vector.cpp Str2Vector.h
	g++ -c Str2Vector.cpp

clean:
	rm -rf *.o
	rm -rf count