CC      = g++
CFLAG   = -std=c++11
OUT_DIR = ./bin
SRC_DIR = ./src
INCLUDE = 
LIBS	= -lm

all: build-all
	${CC} ${CFLAG} -o ${OUT_DIR}/exec ${OUT_DIR}/main.o ${OUT_DIR}/event.o ${OUT_DIR}/eventLoop.o ${OUT_DIR}/tcpConnection.o  ${OUT_DIR}/tcpListener.o 	${OUT_DIR}/httpHandle.o  ${OUT_DIR}/httpRequest.o ${OUT_DIR}/httpResponse.o

.PHONY: tcp build-all clean
build-all: event main eventLoop tcpConnection tcpListener httpHandle httpRequest httpResponse

event: 
	${CC} ${CFLAG} -o ${OUT_DIR}/event.o -c ${SRC_DIR}/event.cpp

eventLoop: 
	${CC} ${CFLAG} -o ${OUT_DIR}/eventLoop.o -c ${SRC_DIR}/eventLoop.cpp

tcpConnection: 
	${CC} ${CFLAG} -o ${OUT_DIR}/tcpConnection.o -c ${SRC_DIR}/tcpConnection.cpp

tcpListener: 
	${CC} ${CFLAG} -o ${OUT_DIR}/tcpListener.o -c ${SRC_DIR}/tcpListener.cpp

main: 
	${CC} ${CFLAG} -o ${OUT_DIR}/main.o -c ./main.cpp

httpHandle: 
	${CC} ${CFLAG} -o ${OUT_DIR}/httpHandle.o -c ${SRC_DIR}/httpHandle.cpp

httpRequest: 
	${CC} ${CFLAG} -o ${OUT_DIR}/httpRequest.o -c ${SRC_DIR}/httpRequest.cpp

httpResponse: 
	${CC} ${CFLAG} -o ${OUT_DIR}/httpResponse.o -c ${SRC_DIR}/httpResponse.cpp


clean:
	rm -f ${OUT_DIR}/*