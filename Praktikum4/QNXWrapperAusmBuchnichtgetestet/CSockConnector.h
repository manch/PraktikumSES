/*
 * CSockConnector.h
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#ifndef CSOCKCONNECTOR_H_
#define CSOCKCONNECTOR_H_

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class CSockConnector {
public:
	CSockConnector();
	virtual ~CSockConnector();
	bool connect( CSockStream& stream, CInetAddr& address, bool block = true);
};

#endif /* CSOCKCONNECTOR_H_ */
