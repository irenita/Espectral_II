/********************************************************************************
** 31-01-2018
** Autor: Irena Cabanach Dresden
** Universidad Central de Venezuela
** TESIS: "Implementación y evaluación de resultados del algoritmo de Desaturación Espectral"
** Basado en el paper:
** Implementado con OpenCV 2.4.13.4 (compilación vc14)
** Versión Qt 5.10.0
** Visuaal Studio 2017
** 
********************************************************************************/

#include "QtGuiApplication3.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiApplication3 w;
	w.show();
	return a.exec();
}
