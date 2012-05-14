

#ifndef CSOCKSTREAM_H
#define	CSOCKSTREAM_H

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "Global.h"

class CSockStream {
    friend class CSockConnector;
    friend class CSockAcceptor;
    
    public:
    CSockStream();
    ~CSockStream();
    // Default constructor
    // Destructor
    int recv( void *buffer, Int32 size );
    // read size bytes from stream into buffer
    // return number of bytes actually read.
    int send( const void *buffer, Int32 size ); // send size bytes from the buffer into stream.
    // return number of bytes actually send.
    void close();
    // Close this stream for reading and writing
    private:
        int mSocket;
};

#endif	/* CSOCKSTREAM_H */

