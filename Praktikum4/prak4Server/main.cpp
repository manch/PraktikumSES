
#include <cstdlib>
#include <iostream>

#include "CInetAddr.h"
#include "CSockAcceptor.h"
#include "CSockConnector.h"
#include "CSockStream.h"

using namespace std;
#define BUFFER_SIZE 32
/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Run Server" << endl;        

    CSockAcceptor* server = new CSockAcceptor();
    
    int port = 2000;
    CInetAddr addr;
    addr.set(port);    
    bool opened = server->open(addr);
    cout << "Server Socket" << (opened ? "" : "not ") << " openened on Port " << port << endl;

    void* buf[BUFFER_SIZE];
    CSockStream stream;

    
    bool accepted = server->accept(stream, 0);
    cout << "Server " << (accepted ? "" : "not ") << " Connection" << endl;
    
    if(accepted)
    {
        int num_received = 0;
        while((num_received = stream.recv(buf, BUFFER_SIZE)) > 0)
        {
            char* c = new char[num_received];
            memcpy(c, buf, num_received);
            cout << "server received(" << num_received << "):" << c << endl;   
            
            char* ack = "1";
            stream.send((void*)ack, 1);
        }  
    }
        
    cout << "Server Shutdown" << endl;    
    
    return 0;
}

