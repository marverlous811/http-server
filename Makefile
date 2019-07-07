CC      = g++
CFLAG   = -std=c++11
OUT_DIR = ./bin
SRC_DIR = ./src
INCLUDE = 
LIBS	= -lm

all: build-all
	${CC} ${CFLAG} -o ${OUT_DIR}/exec ${OUT_DIR}/main.o ${OUT_DIR}/event.o ${OUT_DIR}/eventLoop.o ${OUT_DIR}/tcpConnection.o  ${OUT_DIR}/tcpListener.o 	${OUT_DIR}/util.o  ${OUT_DIR}/httpRequest.o ${OUT_DIR}/httpResponse.o ${OUT_DIR}/pooling.o ${OUT_DIR}/client.o

.PHONY: tcp build-all clean
build-all: event main eventLoop tcpConnection tcpListener util httpRequest httpResponse client pooling

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

util: 
	${CC} ${CFLAG} -o ${OUT_DIR}/util.o -c ${SRC_DIR}/util.cpp

httpRequest: 
	${CC} ${CFLAG} -o ${OUT_DIR}/httpRequest.o -c ${SRC_DIR}/Request.cpp

httpResponse: 
	${CC} ${CFLAG} -o ${OUT_DIR}/httpResponse.o -c ${SRC_DIR}/Response.cpp

client: 
	${CC} ${CFLAG} -o ${OUT_DIR}/client.o -c ${SRC_DIR}/Client.cpp

pooling: 
	${CC} ${CFLAG} -o ${OUT_DIR}/pooling.o -c ${SRC_DIR}/ObjectPooling.cpp

clean:
	rm -f ${OUT_DIR}/*