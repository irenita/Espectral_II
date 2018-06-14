#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication3.h"

#include <QImage>
#include <QPixmap>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

class QtGuiApplication3 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication3(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication3Class ui;

public slots:
	void botonCargarImagen();
	void cambiarLabelTITA(int);
	void cambiarLabelPHI(int);
	void cambiarSliderTITA();
	void cambiarSliderPHI();
	void cambiarSliderLuminancia();
	void cambiarLabelLuminancia();
	void mensajeSalir();
	void botonGuardarImagen();
	void cvMat2QPixmap(Mat matrizImagen);	// int matFilas, int matColumnas
	void mostrarOriginal();
	void ocultarOriginal();
	void resizeImagen(int valor);			//Realiza el resize en función del porcentaje indicado como valor
	void cambiarLabelResolucion();			//Cambia la resolucion original de la imagen y lineEdit
	void cambiarSliderResolucion();			//Cambia la resolucion original de la imagen y Slider
	void direccionEntrada(QString);
	void selecValProm();
	void selecValInd();
	void reestValores();
	void algoritmoParteUno();
	void algoritmoParteDos();
};

// *************************************************************


static struct ImagenCargada {

	string nombreArchivo;			// String de fileName que es QString
	
	bool valPromTITA = false;
	bool valIndTITA = false;
	bool valPromPHI = false;
	bool valIndPHI = false;
	bool valManualTITA = false;
	bool valManualPHI = false;

	bool ejecutaAlgoritmo = false;	// Si queremos llamar a unas funciones sin ejecutar Algoritmo de decoloración
	bool cargandoImagen = false;	// Si es la primera vez que se carga la imagen y la queremos ver a color // Una variable que indica que si NO es una imagen recién cargada se pueden reestablecer valores que permiten ejecutar el algoritmo
	bool guardandoImagen = false;	// Si presionamos el botón de GUARDAR se quiere la imagen FULL SIZE, sin resize

	int altoOriginal;
	int anchoOriginal;

	QString fileName;
	Mat imagen;						//ImagenOriginal que se lee del archivo y se modifica con resize()
	Mat imagenResized;				//Imagen escalada (a color o decolorada)
	Mat magnitudBlue;
	Mat magnitudGreen;
	Mat magnitudRed;
	Mat magnitudL;
	Mat magnituda;
	Mat magnitudb;
	Mat complexLSplit[2];
	Mat complexaSplit[2];
	Mat complexbSplit[2];
	Mat IMAGENFINAL;					// Es la imagen FINAL del algoritmo, Full size (o no, si se selecciona la opción)
	Mat complexLmodSplit[2];			// Experimento: el canal L de CIELab de la imagen se suma o resta al resultado final
	QImage QImageImagenResized;			//Imagen original en resize pero en formato QImage

} imagenCargada;
