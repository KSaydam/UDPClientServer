#include "Client.h"
#include <QApplication>
#include <mainwindow.h>

using namespace std;

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	//Start main loop
	return a.exec();
}

/*Bu gorevde karsilastigim bir takim durumlardan bahsetmek istiyorum. UDP protokolunun POSIX API kullanilarak gelistirmesi ifadesi
  ve iki yazlimin da windows da calisacak olmasi biraz celisiyor gibi geldi. POSIX socket API, bildigim kadariyla linux icin gelisitrilmis 
  <sys/socket.h> arayuzunde bulunmaktadir. Dolayisiyla bu yazilimin cross platform olmasi gerektiginin dusundum, cmake ile derlenmesi de buna bir 
  neden sayilabilir. POSIX API kullanmak icin linux environmentini windows uzerinde emule edecegimi dusundum CyGwin kullanip yapmayi denedim. Ancak 
  MS visual studio ile CyGWin projesi olusturmak icin VM ya da embedded bir sistem ihtiyaci olacagindan bundan vazgectim. Windows uzerinde gelistirecegim icin 
  WinSock libini kullanmaya karar verdim. Kullanilan apilerin isimleri POSIX API' deki kullanilmasi gereken fonksiyonlarla aynidir, zaten Winsock, BSD
  tarafindan gelistirilis olan POSIX API baz alinarak yapilmistir. Qt nin kendi socket API' lerinin isimleri POSIX apidekilerden farkli oldugu icin
  baslangicta onlari kullanmaktan cekindim.Ancak projenin GUI elementleri ve programin bunlarla etkilesimi server tarafinda, client 
  tarafindan daha fazla oldugu icin, burada Qt nin socket apilerinin kullandim.
*/
