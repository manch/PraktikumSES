/*
 * CSockStream.cpp
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#include "CSockStream.h"

CSockStream::CSockStream() {
	// TODO Auto-generated constructor stub
	mSocket = 0;
	signal (SIGPIPE, SIG_IGN);

}

CSockStream::~CSockStream() {
	// TODO Auto-generated destructor stub
}

int CSockStream::recv(void *buffer, int size){
	return read(mSocket, buffer, size);
}

int CSockStream::send(const void *buffer, int size){
	return write(mSocket, buffer, size);
}

void CSockStream::close(){
	::close(mSocket);
	mSocket=0;
}
