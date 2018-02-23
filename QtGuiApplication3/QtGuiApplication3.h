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
	//void cambiarSliderPHI_ValProm();
	void mensajeSalir();
	void botonGuardarImagen();
	void transformacionBGRtoQpixMap();	//QString
	void cvMat2QPixmap(Mat matrizImagen);	//, int matFilas, int matColumnas
	void mostrarOriginal();
	void ocultarOriginal();
	void resizeImagen();
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
	bool cargandoImagen = false;	// Si es la primera vez que se carga la imagen y la queremos ver a color
	bool guardandoImagen = false;	// Si presionamos el botón de GUARDAR se quiere la imagen FULL SIZE, sin resize

	QString fileName;
	Mat imagen; //ImagenOriginal que se lee del archivo
	Mat imagenResized;
	Mat magnitudBlue;
	Mat magnitudGreen;
	Mat magnitudRed;
	Mat magnitudL;
	Mat magnituda;
	Mat magnitudb;
	Mat complexLSplit[2];
	Mat complexaSplit[2];
	Mat complexbSplit[2];
	Mat IMAGENFINAL;

} imagenCargada;
