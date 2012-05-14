/*
 * CSockAcceptor.h
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#ifndef CSOCKACCEPTOR_H_
#define CSOCKACCEPTOR_H_


#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class CSockAcceptor {
public:
	CSockAcceptor();
	virtual ~CSockAcceptor();
	bool open( CInetAddr& address);
	bool accept(CSockStream& stream, int timeout = 0);
private:
	int mListenfd;
};

#endif /* CSOCKACCEPTOR_H_ */
