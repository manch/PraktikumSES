

#include "CSockAcceptor.h"

CSockAcceptor::CSockAcceptor() {}
CSockAcceptor::~CSockAcceptor() { }

bool CSockAcceptor::open( CInetAddr& address )
{
    if ( ( mListenfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) // create    
    { 
        return false; 
    }
    
    bind( mListenfd, (struct sockaddr *) &address.mInetAddr, sizeof( address.mInetAddr ) );
    listen( mListenfd, 5 );
    
    return true;
}

// Stream to read & write, 0=blocking, other=wait in secs
bool CSockAcceptor::accept(CSockStream& stream, UInt8 timeout )
{
    if ( timeout > 0 )
    {
        fd_set rfds;
        struct timeval tv;
        int retval;
        FD_ZERO( &rfds );
        FD_SET( (unsigned int)mListenfd, &rfds );
        tv.tv_sec = timeout;
        tv.tv_usec = 0;
        retval = select( mListenfd + 1, &rfds, NULL, NULL, &tv );        
        if ( !retval )
        {
                return false; // Timeout with no connection request.    
        }
    }
    // here either we have no timeout (blocking mode) or we have pending connection request
    // so we accept the new connection.
    int connfd = ::accept( mListenfd, (sockaddr*) NULL, NULL );
    if ( connfd == -1 )
    {
        return false;
    }
    
    stream.mSocket = connfd;
    return true;    
}