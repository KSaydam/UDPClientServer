// Client.h : Include file for standard system include files,
// or project specific include files.
#ifndef CLIENT_H_
#define CLIENT_H_

#pragma once

#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <Ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")
class Client
{
private:
	WSADATA data;
	SOCKET client;
	sockaddr_in serverAddress;

public:
	Client();
	void start();
	void setReceiver(short port, char* serverIP);
	int sendData(char* message, int length);
	void end();
};
#endif


