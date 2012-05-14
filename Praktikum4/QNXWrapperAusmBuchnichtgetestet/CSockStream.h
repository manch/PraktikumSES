/*
 * CSockStream.h
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#ifndef CSOCKSTREAM_H_
#define CSOCKSTREAM_H_
#include "CSockConnector.h"
#include "CSockAcceptor.h"

class CSockStream {
friend class CSockConnector;
friend class CSockAcceptor;
public:
	CSockStream();
	virtual ~CSockStream();
	int recv(void *buffer, int size);
	int send(const void *buffer, int size);
	void close();
private:
	mSocket;
};

#endif /* CSOCKSTREAM_H_ */
