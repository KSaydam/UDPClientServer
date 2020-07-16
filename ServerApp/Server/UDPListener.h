
#ifndef UDPLISTENER_H_
#define UDPLISTENER_H_

#include <QtCore>
#include <QUdpSocket>

#include "UDPSocketProtocol.h"

class UDPListener: public QThread {
Q_OBJECT
public:
	UDPListener(quint16 port, 
			QObject *parent = 0);
	void run();
	void stop();
	virtual ~UDPListener();

	UDPSocketProtocol *m_pUdpsocketprotocol;
private:
	void processPendingDatagrams();
	QMutex _mutex;
	QUdpSocket* _socket;
	quint16 _port;
	bool _running;
};

#endif /* UDPLISTENER_H_ */
