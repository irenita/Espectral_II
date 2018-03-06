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

public slots:   //private
	void botonCargarImagen();
	void cambiarLabelTITA(int);
	void cambiarLabelPHI(int);
	void cambiarSliderTITA();
	//void cambiarSliderTITA_ValProm();
	void cambiarSliderPHI();
	void cambiarSliderLuminancia();
	void cambiarLabelLuminancia();
	//void cambiarSliderPHI_ValProm();
	void mensajeSalir();
	void botonGuardarImagen();
	//void transformacionBGRtoQpixMap();	//QString
	void cvMat2QPixmap(Mat matrizImagen);	//, int matFilas, int matColumnas
	void mostrarOriginal();
	void ocultarOriginal();
	void resizeImagen(int valor);		//realiza el resize en función del porcentaje indicado como valor
	void cambiarLabelResolucion();			//Cambia la resolucion original de la imagen y lineEdit
	void cambiarSliderResolucion();			//Cambia la resolucion original de la imagen y Slider
	void direccionEntrada(QString);
	void selecValProm();
	void selecValInd();
	void reestValores();
	//void selecTITAprom();
	//void selecPHIprom();
	void algoritmoParteUno();
	void algoritmoParteDos();
	//void direccionEntrada(QString);
};

// *************************************************************


//QPixmap mat_to_qimage_cpy(Mat, enum QImage::Format);  //  const //QImage::Format

//void ImagenCargada::setDireccionEntrada(QString direccion)   //char* direccion

static struct ImagenCargada {

	string nombreArchivo;
	
	bool valPromTITA = false;	//true
	bool valIndTITA = false;
	bool valPromPHI = false;		//true
	bool valIndPHI = false;
	bool valManualTITA = false;
	bool valManualPHI = false;

	bool ejecutaAlgoritmo = false; // Si queremos llamar a unas funciones sin ejecutar Algoritmo de decoloración
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
	Mat complexLmodSplit[2];
	QImage QImageImagenResized;			//Imagen original en resize pero en formato QImage

} imagenCargada;
