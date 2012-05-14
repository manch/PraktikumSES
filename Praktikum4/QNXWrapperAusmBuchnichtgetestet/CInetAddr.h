/*
 * CInetAddr.h
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#ifndef CINETADDR_H_
#define CINETADDR_H_
#include "CSockConnector.h"
#include "CSockAcceptor.h"

class CInetAddr {
	friend class CSockConnector;
	friend class CSockAcceptor;
public:
	CInetAddr();
	virtual ~CInetAddr();
	bool set( int port, const char *address);
	bool set( int port);
private:
	sockaddr_in mInetAddr;
};

#endif /* CINETADDR_H_ */
