
all: mips_disasm

clean:
	rm -rf *.o mips_disasm

mips_disasm: main.o asm.o
	g++ main.o asm.o -o mips_disasm

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -o main.o

asm.o: asm.cpp
	g++ -c asm.cpp -std=c++11 -o asm.o

