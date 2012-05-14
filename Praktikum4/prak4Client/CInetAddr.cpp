

#include "CInetAddr.h"

CInetAddr::CInetAddr() { }
CInetAddr::~CInetAddr() { }

bool CInetAddr::set( UInt16 port, const char *address )
{
    memset( &mInetAddr, sizeof( mInetAddr ), 0 );
    mInetAddr.sin_family = AF_INET;
    mInetAddr.sin_port = htons( port );
    if ( inet_aton( address, &mInetAddr.sin_addr ) <= 0 )
    {
        return false; 
    }
    
    return true;
}

    // set struct
bool CInetAddr::set( UInt16 port )
{
    memset( &mInetAddr, sizeof( mInetAddr ), 0 );
    mInetAddr.sin_family = AF_INET;
    mInetAddr.sin_port = htons( port );
    mInetAddr.sin_addr.s_addr = htonl( INADDR_ANY );
    
    return true;
}
