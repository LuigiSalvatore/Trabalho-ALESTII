EXERCICIO = app
CFLAGS = -c -std=c++11 #-DDEBUG
DASHOES = main.o funcs.o DLL.o #${DASHOES}

all:			${EXERCICIO}

${EXERCICIO}:	${DASHOES} 
	g++ -o ${EXERCICIO} ${DASHOES}
	
main.o:		main.cpp funcs.cpp funcs.hpp DLL.hpp DLL.cpp
	g++ ${CFLAGS} main.cpp

funcs.o:			funcs.cpp funcs.hpp	
	g++ ${CFLAGS} funcs.cpp

DLL.o:			DLL.cpp DLL.hpp
	g++ ${CFLAGS} DLL.cpp

run:			${EXERCICIO} 
	./${EXERCICIO}

clean: 			
	rm -f ${DASHOES} ${EXERCICIO}