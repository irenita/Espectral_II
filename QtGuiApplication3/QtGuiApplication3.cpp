#include "QtGuiApplication3.h"
#include <Qpixmap>

QtGuiApplication3::QtGuiApplication3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	// yo
	ui.cargarImagenEnLabel(this);

}


