/*
 * CInetAddr.cpp
 *
 *  Created on: 01.05.2012
 *      Author: chris
 */

#include "CInetAddr.h"

CInetAddr::CInetAddr() {
	// TODO Auto-generated constructor stub

}

CInetAddr::~CInetAddr() {
	// TODO Auto-generated destructor stub
}

bool CInetAddr::set( int port, const char *address){
	memset( &mInetAddr, sizeof( mInetAddr), 0);
	mInetAddr.sin_family = AF_INET;
	mInetAddr.sin_port = htons(port);
	if (inet_aton(address, &mInetAddr.sin_addr) <= 0){
		return false;
	}
	return true;
}

bool CInetAddr::set(int port){
	memset(&mInetAddr, sizeof(mInetAddr),0);
	mInetAddr.sin_family = AF_INET;
	mInetAddr.sin_port = htons(port);
	mInetAddr.sin_addr-s_addr = htpnl(INADDR_ANY);
	return true;
}
