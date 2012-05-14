

#ifndef CINETADDR_H
#define	CINETADDR_H

#include <netinet/in.h>
#include <arpa/inet.h>

#include <string.h>
#include "Global.h"

class CInetAddr {
friend class CSockConnector;
friend class CSockAcceptor;
public:
    CInetAddr();
    ~CInetAddr();
    bool set(UInt16 port, const char *address );
    bool set( UInt16 port );
    private:
        sockaddr_in mInetAddr;
};

#endif	/* CINETADDR_H */

