// Client.cpp : Defines the entry point for the application.
//

#include "Client.h"

using namespace std;

Client::Client()
{
	WORD version = MAKEWORD(2, 2);
	int result = WSAStartup(version, &data); //Init Winsock
	if (result != 0)
	{
		cout << "Error during start up " << WSAGetLastError() << endl;
		exit(0);
	}
}


void Client::start()
{
    client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Create a socket for client
	if (client == INVALID_SOCKET)
	{
		cout << "Socket Error " << WSAGetLastError() << endl;
		exit(0);
	}
}

void Client::setReceiver(short port, char* serverIP)
{
	serverAddress.sin_family = AF_INET; //Set for IP4 adress family
	serverAddress.sin_port = htons(port); //Set port number as big endian
	inet_pton(AF_INET, serverIP, &serverAddress.sin_addr);//Convert network address to binary form from text represantation
}


int  Client::sendData(char* message, int length)
{
	//Send the message
	int sentBytes = sendto(client, message, length, 0, (sockaddr*)&serverAddress, sizeof(serverAddress));
	if (sentBytes == SOCKET_ERROR)
	{
		cout << "Error during sending " << WSAGetLastError() << endl;
	}

	return sentBytes;
}

void Client::end()
{
	if (client != INVALID_SOCKET)
	{
		closesocket(client);
	}

	WSACleanup();
}

