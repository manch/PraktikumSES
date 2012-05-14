

#ifndef CSOCKACCEPTOR_H
#define	CSOCKACCEPTOR_H

#include <netinet/in.h>
#include "CInetAddr.h"
#include "CSockStream.h"

class CSockAcceptor {
    public:
        CSockAcceptor();
        ~CSockAcceptor();
        bool open( CInetAddr& address ); // Initializes CInetAddr listen passively        
        bool accept( CSockStream& stream, UInt8 timeout = 0 ); // Initialize CSockStream with a new client connection
        
    private:
        int mListenfd;
};

#endif	/* CSOCKACCEPTOR_H */

