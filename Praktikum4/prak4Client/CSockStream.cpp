

#include "CSockStream.h"

CSockStream::CSockStream() : mSocket( 0 )
{
        signal( SIGPIPE, SIG_IGN );
}

CSockStream::~CSockStream() { }

int CSockStream::recv( void *buffer, Int32 size )
{
    int len=0;
    int x;
    do
    {
        x = read( mSocket, ((char *) buffer)+len, size-len );
    }
    while (x>0 && (len+=x)<size);
    
    return x;
}

int CSockStream::send( const void *buffer, Int32 size )
{
    return write( mSocket, buffer, size );
}
void CSockStream::close()
{
    ::close( mSocket );
    mSocket = 0;
}
