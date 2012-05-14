/*
 * CSockAcceptor.cpp
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#include "CSockAcceptor.h"

CSockAcceptor::CSockAcceptor() {
	// TODO Auto-generated constructor stub

}

CSockAcceptor::~CSockAcceptor() {
	// TODO Auto-generated destructor stub
}

bool CSockAcceptor::open(CInetAddr& adress){
	if((mListenfd = socket(AF_INET,SOCK_STREAM,0))<0){
		return false;
	}
	bind(mListenfd, (struct sockaddr*) &address.mInetAddr, sizeof(addrss.mInetAddr));
	listen(mListenfd, 5);
	return true;
}

bool CSockAcceptor::accept(CSockStream& stream, int timeout){
	if (timeout > 0){
		fd_set rfds;
		struct timeval tv;
		int retval;
		FD_ZERO( &rfds );
		FD_SET( (unsigned int)mListenfd, &rfds );
		tv.tv_sec = timeout;
		tv.tv_usec ) = 0;
		retval = select (mListefd +1, &rfds, NULL, NULL, &tv);
		if (!retval){
			return false
		}
		int connfd = ::accept(mListenfd, (sockaddr*) NULL,NULL);
		if (connfd == -1){
			return false;
		}
		stream.mSocket = connfd;
		return true;
	}
}
