#include "UDPListener.h"
#include "UDPSocketProtocol.h"


UDPListener::UDPListener(quint16 port, QObject *parent) :QThread(parent)
{
	_port = port;
}

void UDPListener::processPendingDatagrams()
{
	QByteArray data;
	QHostAddress host;
	quint16 port;
	if (UDPSocketProtocol::receiveDatagram(_socket, &data, &host, &port))
	{
		QMutexLocker locker(&_mutex);
	}
	else
	{
		qWarning("UDPListener::processPendingDatagrams(BAD UDP PACKET)");
	}
}

void UDPListener::stop()
{
	_running = false;
	wait();
}

//Listens the port continuously to receive message
void UDPListener::run()
{
	_running = true;
	_socket = new QUdpSocket();

	if (!_socket->bind(_port))
	{
		qWarning("(CAN'T BIND port %d)", _port);
		return;
	}

	while (_running)
	{
		//Check for incoming datagram
		if (_socket->hasPendingDatagrams())
		{
			processPendingDatagrams();
		}

		msleep(10);
	}

	_socket->close();
	delete _socket;
}

UDPListener::~UDPListener()
{

}
