

#include "CSockConnector.h"

CSockConnector::CSockConnector() {}
CSockConnector::~CSockConnector() { }

bool CSockConnector::connect(CSockStream& stream, CInetAddr& address, bool block )
{
    int sockfd;
    if ( ( sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) //create socket
    { 
        return false; 
    }
    
    if ( ::connect( sockfd, (sockaddr*) &address.mInetAddr, sizeof( address.mInetAddr ) ) < 0 )
    { 
        return false; 
    }
    stream.mSocket = sockfd;
    
    return true;
}
