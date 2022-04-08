CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o MonteCarlo.o

main: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS}

clean:
	rm -f ds*
	rm main
	rm ${OBJS} main MonteCarlo
	
