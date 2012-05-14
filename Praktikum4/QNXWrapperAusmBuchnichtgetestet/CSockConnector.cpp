/*
 * CSockConnector.cpp
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#include "CSockConnector.h"

CSockConnector::CSockConnector() {
	// TODO Auto-generated constructor stub

}

CSockConnector::~CSockConnector() {
	// TODO Auto-generated destructor stub
}

bool CSockConnector::connect(CSockStream& stream, CInetAddr& address, bool block){
	int sockfd;
	if ((sockfd = socket (AF_INET,SOCK_STREAM,0))<0){
		return false;
	}
	if(::connect(sockfd,(sockaddr*) &address.mInetAddr,sizeof(address.mInetAddr))<0){
		return false;
	}
	stream.mSocket = sockfd;
	return true;
}
