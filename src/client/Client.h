// Generated by dia2code
#ifndef CLIENT__CLIENT__H
#define CLIENT__CLIENT__H

#include <iostream>

namespace server {
  class Server;
  class Observable;
  class ServerObserver;
}

#include "server/Server.h"
#include "server/Observable.h"
#include "server/ServerObserver.h"

namespace client {

  /// class Client - 
  class Client : public server::Server, public server::Observable, public server::ServerObserver {
    // Attributes
  protected:
    server::Server* server;
    // Operations
  public:
    Client (server::Server* serv);
    ~Client ();
    virtual void run () = 0;
    void serverChanged (server::ServerEvent& sc);
  protected:
    virtual void init () = 0;
    virtual bool acquireControls ();
    virtual void stateChanged ();
  };

};

#endif