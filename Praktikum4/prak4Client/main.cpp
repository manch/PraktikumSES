

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
    char* msg = "xAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAy";
    
    CInetAddr addr;
    addr.set(2000, "141.100.74.208");        
         
    CSockConnector* client = new CSockConnector();
    
    CSockStream stream; 
    bool connect = client->connect(stream, addr, 1);
    cout << "Client " << (connect ? "" : "not ") << "connect" << endl;

    
    for (int i = 0; i < 100; i++){
        int pos = 0;
        bool send = true;
        while(send)
        {
            int num_to_send = 0;
            if((pos + BUFFER_SIZE) > strlen(msg))
            {
                num_to_send = BUFFER_SIZE - ((pos + BUFFER_SIZE) - strlen(msg));
                send = false;
            }
            else
            {
                num_to_send = BUFFER_SIZE;
            }

            if(num_to_send)
            {
                char* buf = new char[BUFFER_SIZE];
                memcpy(buf, msg+pos, num_to_send);
                cout << "Send: " << buf << endl;
                stream.send((const void*)buf, BUFFER_SIZE);

                // Receive ACK
                void* buf_ack[1];
                stream.recv(buf_ack, 1);
                char* ack = new char[1];
                memcpy(ack, buf_ack, 1);            
                cout << "Received Ack:" << ack << endl;           

                // Check if the server has received the packet
                if('1' == ack[0])
                {
                    pos += num_to_send;
                }
            }
        }
    }
    
    stream.close();



    return 0;
}

