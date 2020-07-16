
#include <windows.h>
#include <qthread.h>

#include "UDPSocketProtocol.h"

QByteArray datagram;
bool IsImageTransferCompleted = FALSE;

bool UDPSocketProtocol::sendDatagram(const QByteArray& data, QHostAddress host,
		quint16 port, int compressionLevel) 
{
	QUdpSocket socket;
	socket.writeDatagram(datagram, host, port);
	
	return true;
}

bool UDPSocketProtocol::receiveDatagram(QUdpSocket* socket, QByteArray* data,
		QHostAddress *host, quint16 *port) 
{
	Sleep(1); //usleep(100);
	IsImageTransferCompleted = FALSE;

	if (socket->hasPendingDatagrams()) {
		datagram.resize(socket->pendingDatagramSize());
		int bytesread = socket->readDatagram(datagram.data(), datagram.size(),
				host, port);
		if (bytesread != datagram.size()) {
			qWarning("RECEIVE FAILED");
			return false;
		}
	}


	IsImageTransferCompleted = TRUE;

	return true;
}





