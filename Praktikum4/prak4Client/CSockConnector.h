

#ifndef CSOCKCONNECTOR_H
#define	CSOCKCONNECTOR_H

#include <netinet/in.h>
#include "CSockStream.h"
#include "CInetAddr.h"

class CSockConnector {
    public:
        CSockConnector();
        ~CSockConnector();
        // constructor - create a CSockConnector
        // Destructor
        // Connect Params: stream: the stream data sent or received
        // address: of the server to connect to
        // block: whether the call should block
        bool connect( CSockStream& stream, CInetAddr& address, bool block = true );
};

#endif	/* CSOCKCONNECTOR_H */

