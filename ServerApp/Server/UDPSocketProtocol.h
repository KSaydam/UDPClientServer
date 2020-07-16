#ifndef UDPSOCKETPROTOCOL_H
#define UDPSOCKETPROTOCOL_H

#include <QtCore>

#include <QUdpSocket>

const unsigned ONE_WORD = 32;

class UDPSocketProtocol
{
public:
	static bool sendDatagram(const QByteArray& data, QHostAddress host, quint16 port, int compressionLevel = 0);
	static bool receiveDatagram(QUdpSocket *socket, QByteArray* data, QHostAddress *host = 0, quint16 *port = 0);


private:
};


#endif // UDPSOCKETPROTOCOL_H
