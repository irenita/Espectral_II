#include "QtGuiApplication3.h"
#include <Qpixmap>
#include <QFileDialog>
#include <qmessagebox.h>
#include <qstringbuilder.h>
#include <QString>
#include <math.h>
#include <QDebug>
// OPENCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/types_c.h"

using namespace std;
using namespace cv;

//static char dirEntrada[150];
//static string dirEntrada;

QtGuiApplication3::QtGuiApplication3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Connect button signal to appropriate slot - Conecta la señal del boton al slot apropiado
	connect(ui.pushButtonAbrir, SIGNAL(released()), this, SLOT(botonCargarImagen()));
	// Si lo colocamos en ui_QtGuiApplication3.h
	//QObject::connect(pushButtonAbrir, SIGNAL(released()), QtGuiApplication3Class, SLOT(botonCargarImagen()));
	connect(ui.pushButtonGuardar, SIGNAL(released()), this, SLOT(botonGuardarImagen()));
	connect(ui.horizontalSliderTITA, SIGNAL(valueChanged(int)), this, SLOT(cambiarLabelTITA(int)));
	//connect(ui.horizontalSliderTITA, SIGNAL(sliderMoved(int)), this, SLOT(cambiarLabelTITA(int)));
	connect(ui.horizontalSliderPHI, SIGNAL(valueChanged(int)), this, SLOT(cambiarLabelPHI(int)));
	//connect(ui.horizontalSliderPHI, SIGNAL(sliderMoved(int)), this, SLOT(cambiarLabelPHI(int)));
	connect(ui.lineEditTITA, SIGNAL(editingFinished()), this, SLOT(cambiarSliderTITA()));
	connect(ui.lineEditPHI, SIGNAL(editingFinished()), this, SLOT(cambiarSliderPHI()));
	connect(ui.pushButtonValProm, SIGNAL(released()), this, SLOT(selecValProm()));
	connect(ui.pushButtonValInd, SIGNAL(released()), this, SLOT(selecValInd()));
	connect(ui.pushButtonSalir, SIGNAL(released()), this, SLOT(mensajeSalir()));
	connect(ui.pushButtonReestVal, SIGNAL(released()), this, SLOT(reestValores()));

	//connect(ui.pushButtonImagenOriginal, SIGNAL(pressed()), this, SLOT(mostrarOriginal(true)));
	connect(ui.pushButtonImagenOriginal, SIGNAL(pressed()), this, SLOT(mostrarOriginal()));
	connect(ui.pushButtonImagenOriginal, SIGNAL(released()), this, SLOT(ocultarOriginal()));
}


//*********************************************************
//** IMPLEMENTACIÓN DE FUNCIONES
//*********************************************************

	void QtGuiApplication3::botonCargarImagen()
{
	
//		QPixmap pix("C:/Users/Irena/Downloads/Ire_SQ_glitch.jpg");
		int al = ui.label_pic->width();
		int an = ui.label_pic->height();

		QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir imagen..."),
							"/home", tr("Im\303\241genes (*.png *.bmp *.jpg)"));
		
		if (fileName.isEmpty()) {

			QMessageBox msgBox;
			msgBox.setWindowTitle("ERROR");
			msgBox.setText("No se seleccion\303\263 un archivo");
			QAbstractButton *botonAceptar = msgBox.addButton("Aceptar", QMessageBox::AcceptRole);
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.exec();
			msgBox.setEscapeButton(botonAceptar);

			if (msgBox.clickedButton() == botonAceptar)
				msgBox.close();

			return;
		}  // fin de fileName.isEmpty
			
		else {

			// Una variable que indica que no se debe de ejecutar el algoritmo
			imagenCargada.ejecutaAlgoritmo = false;
			// Una variable que indica que ya es una imagen recién cargada
			imagenCargada.cargandoImagen = true;
			// Y reestablecemos los varores
			reestValores();

			// Guardamos la direecion en formato QString static para posterior uso
			imagenCargada.fileName = fileName;
			// Si hay archivo válido, se carga en el QPixmap y...
			QPixmap pix(fileName);
			ui.label_pic->setPixmap(pix.scaled(al, an, Qt::KeepAspectRatio)); // KeepAspectRatio KeepAspectRatioByExpanding
			ui.label_pic->repaint();

			direccionEntrada(fileName);	// la dirección de entrada se guarda en la variable static dirEntrada

			// Se inician o reinician las variables que determinan si los
			// cálculos de valores de TITA y PHI son individuales o promedio
			//imagenCargada.valPromTITA = true;
			//imagenCargada.valIndTITA = false;
			//imagenCargada.valPromPHI = true;
			//imagenCargada.valIndPHI = false;

			// ... se llama al proceso que trabajará el algoritmo de transformación
	//***//		transformacionBGRtoQpixMap();	//transformacionBGRtoQpixMap(fileName);

			// Como puede que se carguen nuevas imágenes sin cerrar el programa
			// se reinician las variables pertinentes
			//reestValores();	//no sirve bien

			// Apenas se selecciona una imagen nueva se ejecuta una primera parte del algoritmo
			// Algoritmo que establece las variables que no cambian una vez cargada la imagen
			//algoritmoParteUno();
			// La primera vez que se carga la imagen tenemos su referencia de QPixmap
			//cvMat2QPixmap(imagenCargada.imagen);
		}

}

	// TITA reacciona sobre la Luminosidad y sobre ambos tonos
	void QtGuiApplication3::cambiarLabelTITA(int valor) {
		
		float valueTITA = ((float)valor / (float) ui.horizontalSliderTITA->maximum());
		int enteroTITA = (int)(valueTITA * 10000.0);
		double flotanteTITA = (double)(0.0);
		flotanteTITA = enteroTITA / 10000.0;
		ui.lineEditTITA->setText(QVariant(flotanteTITA).toString());
		
		// *** Si se cambia el label se coloca TITA como valor individual
		imagenCargada.valPromTITA = false;
		imagenCargada.valIndTITA = false;	//true
		imagenCargada.valManualTITA = true;

		// *** Al arrancar por primera vez el programa, todos los valores están FALSOS
		// *** por lo que vamos a indicar que si TODOS son falsos colocamos PHI manual como TRUE
		if (false == imagenCargada.valPromPHI == imagenCargada.valIndPHI == imagenCargada.valManualPHI)
			imagenCargada.valManualPHI = true;
		
		// Llamamos a la función que activa las opciones de TITA individual
		ui.pushButtonValInd->setEnabled(true);
		ui.pushButtonValProm->setEnabled(true);

		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		// SI LA VARIABLE EJECUTARALGORITMO LO INDICA
		// sino estamos en la primera carga de una imagen, que queremos a color
		if(imagenCargada.ejecutaAlgoritmo == true){
		algoritmoParteUno();
		algoritmoParteDos();
		}
	}

	// PHI reacciona sobre los tonos a y b
	void QtGuiApplication3::cambiarLabelPHI(int valor) {

		float valuePHI = ((float)valor / (float)ui.horizontalSliderPHI->maximum());
		int enteroPHI = (int)(valuePHI * 10000.0);
		double flotantePHI = (double)(0.0);
		flotantePHI = enteroPHI / 10000.0;
		ui.lineEditPHI->setText(QVariant(flotantePHI).toString());

		// *** Si se cambia el label se coloca PHI como valor individual
		imagenCargada.valPromPHI = false;
		imagenCargada.valIndPHI = false;	//false
		imagenCargada.valManualPHI = true;

		// *** Al arrancar por primera vez el programa, todos los valores están FALSOS
		// *** por lo que vamos a indicar que si TODOS son falsos colocamos TITA manual como TRUE
		if (false == imagenCargada.valPromTITA == imagenCargada.valIndTITA == imagenCargada.valManualTITA)
			imagenCargada.valManualTITA = true;

		// Llamamos a la función que activa las opciones de PHI individual
		ui.pushButtonValInd->setEnabled(true);
		ui.pushButtonValProm->setEnabled(true);


		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		// SI LA VARIABLE EJECUTARALGORITMO LO INDICA
		// sino estamos en la primera carga de una imagen, que queremos a color
		if (imagenCargada.ejecutaAlgoritmo == true) {
			algoritmoParteUno();
			algoritmoParteDos();
		}
	}

	// Cuando se presione ENTER en la casilla del numero TITA se desplaza el SliderTITA
	void QtGuiApplication3::cambiarSliderTITA() {
	
		QString valueTITA2 = ui.lineEditTITA->text();
		double valorTITAint = valueTITA2.toDouble();
		valorTITAint = valorTITAint * 10000;				//Slider va de 0 a 9999 // para tener 4 decimales
		ui.horizontalSliderTITA->setValue(valorTITAint);
		
		// *** Si se cambia el slider se coloca TITA como valor manual
		imagenCargada.valPromTITA = false;
		imagenCargada.valIndTITA = false;
		imagenCargada.valManualTITA = true;

		// Llamamos a la función que activa las opciones de TITA manual
		ui.pushButtonValInd->setEnabled(true);
		ui.pushButtonValProm->setEnabled(true);

		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		// SI LA VARIABLE EJECUTARALGORITMO LO INDICA
		// sino estamos en la primera carga de una imagen, que queremos a color
		if (imagenCargada.ejecutaAlgoritmo == true) {
			algoritmoParteUno();
			algoritmoParteDos();
		}
	}

	// Cuando se presione BOTON valPromTITA, TITA se desplaza el SliderTITA
/*	void QtGuiApplication3::cambiarSliderTITA_ValProm() {

		QString valueTITA2 = ui.lineEditTITA->text();
		double valorTITAint = valueTITA2.toDouble();
		valorTITAint = valorTITAint * 10000;				//Slider va de 0 a 9999 // para tener 4 decimales
		ui.horizontalSliderTITA->setValue(valorTITAint);

		// El algoritmo se llama desde el pushButton Valores Promedio

	}
	*/

	// Cuando se presione ENTER en la casilla del numero PHI se desplaza el SliderPHI
	void QtGuiApplication3::cambiarSliderPHI() {

		QString valuePHI2 = ui.lineEditPHI->text();
		double valorPHIint = valuePHI2.toDouble();
		valorPHIint = valorPHIint * 10000;				//Slider va de 0 a 9999
		ui.horizontalSliderPHI->setValue(valorPHIint);

		// *** Si se cambia el slider se coloca PHI como valor individual
		imagenCargada.valPromPHI = false;
		imagenCargada.valIndPHI = false;	//true
		imagenCargada.valManualPHI = true;
		
		// Llamamos a la función que activa las opciones de PHI individual
		ui.pushButtonValInd->setEnabled(true);
		ui.pushButtonValProm->setEnabled(true);


		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		// SI LA VARIABLE EJECUTARALGORITMO LO INDICA
		// sino estamos en la primera carga de una imagen, que queremos a color
		if (imagenCargada.ejecutaAlgoritmo == true) {
			algoritmoParteUno();
			algoritmoParteDos();
		}
	}

	// Cuando se presione BOTON valPromPHI, PHI se desplaza el SliderPHI
/*	void QtGuiApplication3::cambiarSliderPHI_ValProm() {

		QString valuePHI2 = ui.lineEditPHI->text();
		double valorPHIint = valuePHI2.toDouble();
		valorPHIint = valorPHIint * 10000;				//Slider va de 0 a 9999
		ui.horizontalSliderPHI->setValue(valorPHIint);

	}
*/

	// Mensaje que se arroha si se desea salir de la aplicación
	void QtGuiApplication3::mensajeSalir() {

		QMessageBox msgBox;
		msgBox.setWindowTitle("ATENCI\303\223N");
		msgBox.setText("\302\277Est\303\241 seguro que desea salir?");
		msgBox.setInformativeText("No se guardar\303\241n los cambios realizados");
		QAbstractButton *botonSalir = msgBox.addButton("Salir", QMessageBox::AcceptRole);
		QAbstractButton *botonCancelar = msgBox.addButton("Cancelar", QMessageBox::NoRole);
		msgBox.setIcon(QMessageBox::Question);
		msgBox.exec();
		msgBox.setEscapeButton(botonCancelar);

		if (msgBox.clickedButton() == botonSalir) {
			this->close();
		}
		else if (msgBox.clickedButton() == botonCancelar) {
			msgBox.close();
		}

	}

	void QtGuiApplication3::botonGuardarImagen()
	{

		//QFileDialog dialogoGuardar;
		//dialogoGuardar.setLabelText(dialogoGuardar.Accept, "whatever");
		//OpenFile.setLabelText(QFileDialog::Accept, tr("test"));
		//OpenFile.setLabelText(QFileDialog::Reject, tr("Cancell change"));
		//dialogoGuardar.exec();

		QString selectedFilter;
		QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar archivo"),
			"imagen",
			"*.png;;*.bmp;;*.jpg", &selectedFilter);

		if (fileName.isEmpty())
			return;
		else {
			//ui.label_pic->setText(fileName);
			//Tomar la direccion y nombre de fileName y guardar la imagen con OpenCV
			

		}
	}

	// Cuando se presiona el boton de Valores Promedio
	void QtGuiApplication3::selecValProm() {

		// Una variable que indica que sí se debe de ejecutar el algoritmo
		imagenCargada.ejecutaAlgoritmo = true;
		// Una variable que indica que ya no es una imagen recién cargada
		imagenCargada.cargandoImagen = false;

		imagenCargada.valPromTITA = true;
		imagenCargada.valIndTITA = false;
		imagenCargada.valPromPHI = true;
		imagenCargada.valIndPHI = false;
		imagenCargada.valManualTITA = false;
		imagenCargada.valManualPHI = false;
		//ui.pushButtonValProm->setStyleSheet(QStringLiteral("background-color: rgb(151, 151, 151);"));
		ui.pushButtonValProm->setDisabled(true);
		ui.pushButtonValInd->setEnabled(true);

		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		algoritmoParteUno();
		algoritmoParteDos();

	}

	// Cuando se presiona el boton de Valores Individuales
	void QtGuiApplication3::selecValInd() {

		// Una variable que indica que sí se debe de ejecutar el algoritmo
		imagenCargada.ejecutaAlgoritmo = true;
		// Una variable que indica que ya no es una imagen recién cargada
		imagenCargada.cargandoImagen = false;

		imagenCargada.valPromTITA = false;
		imagenCargada.valIndTITA = true;
		imagenCargada.valPromPHI = false;
		imagenCargada.valIndPHI = true;
		imagenCargada.valManualTITA = false;
		imagenCargada.valManualPHI = false;
		//ui.pushButtonValInd->setStyleSheet(QStringLiteral("background-color: rgb(151, 151, 151);"));
		ui.pushButtonValInd->setDisabled(true);
		ui.pushButtonValProm->setEnabled(true);
		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		algoritmoParteUno();
		algoritmoParteDos();

	}

	// Cuando se presiona el botón de Reestablecer Valores
	void QtGuiApplication3::reestValores() {
		
		// Una variable que indica que no se debe de ejecutar el algoritmo
		// que queremos que los valores se reinicien
		// se ejecuta el algoritmo al final
		imagenCargada.ejecutaAlgoritmo = false;

		cambiarLabelTITA(0);
		cambiarLabelPHI(0);

		bool valPromTITA = false;
		bool valIndTITA = false;
		bool valPromPHI = false;
		bool valIndPHI = false;
		bool valManualTITA = false;
		bool valManualPHI = false;

		ui.pushButtonValProm->setEnabled(true);
		cambiarSliderTITA();
		ui.pushButtonValInd->setEnabled(true);
		cambiarSliderPHI();
		ui.labelTITA->hide();
		ui.labelPHI->hide();

		// Si esta función es llamada cuando se carga la imagen
		// y la queremos ver a color, sin ejecutar la decoloración
		// no permitimos que se ejecuten los algoritmos de decoloración
		if (imagenCargada.cargandoImagen == false){
			algoritmoParteUno();
			algoritmoParteDos();
		}
	///cvMat2QPixmap(imagenCargada.imagen);

	}

	// Cuando se desliza el slider de TITA o se cambia el box de TITA
	// TITA se vuelve promedio pero PHI se queda en su estado
/*	void QtGuiApplication3::selecTITAprom() {
		imagenCargada.valPromTITA = true;
		imagenCargada.valIndTITA = false;
		ui.pushButtonValProm->setDisabled(true);
		ui.pushButtonValInd->setEnabled(true);
		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		algoritmoParteUno();
		algoritmoParteDos();

	}
*/
	// Cuando se desliza el slider de PHI o se cambia el box de PHI
	// PHI se vuelve promedio pero TITA se queda en su estado
/*	void QtGuiApplication3::selecPHIprom() {
		imagenCargada.valPromPHI = true;
		imagenCargada.valIndPHI = false;
		ui.pushButtonValProm->setDisabled(true);
		ui.pushButtonValInd->setEnabled(true);
		// EJECUTAMOS LA SEGUNDA PARTE DEL ALGORITMO
		// EN DONDE SE CAMBIAN LAS MATRICES
		algoritmoParteUno();
		algoritmoParteDos();

	}
*/

	// Se pasa un bool como parámetro que indica si la matriz que se va a cargar es la
	// gran matriz de la imagen original o sino es la imagenResized
	void QtGuiApplication3::algoritmoParteUno()
	{
		//*********************************************************************//
		//**** ESTA PARTE SE MANEJA CON ImagenCargada::setDireccionEntrada ****//
		// char entrada[100] = "Flor.jpg";
		/*		char entrada[100] = "";
		string stringDireccion = direccion.toUtf8();
		// int n = stringDireccion.length();
		strcpy(entrada, stringDireccion.c_str());		// copying the contents of the string to char array
		*/
		//*********************************************************************//
		//*********************************************************************//

		//	char entrada[100] = "";
		//	direccionEntrada(direccion);	
		// la dirección de entrada se guarda en la variable static dirEntrada

		//Mat imagen;										// new image - nueva imagen
		///imagen = imread(entrada, IMREAD_COLOR);			// read the file - leer el archivo
		//		imagen = imread(ImagenCargada::dirEntrada, IMREAD_COLOR);			// read the file - leer el archivo
		imagenCargada.imagen = imread(imagenCargada.nombreArchivo, IMREAD_COLOR);
		//	imagen = imread(dirEntrada, IMREAD_COLOR);

/*		if (!imagenCargada.imagen.data)								// Check for invalid input - chequea entrada invalida
		{
			cout << "No se pudo abrir o encontrar la imagen";
			//CargarimagenBGR();
			cin.get();
			return;
		}
*/
		//**********************************************************************************//
		// ************************************** BGR ************************************* //
		// **** SE ALMACENA CADA CANAL EN imagenBGR[]

		Mat imagenBGR[3];						//	Matriz de 3 canales
		imagenCargada.imagen.convertTo(imagenCargada.imagen, CV_8U);		//	8U es de 0 a 255
		split(imagenCargada.imagen, imagenBGR);				//	Separa la imagen original en 3 canales BGR (BlueGreenRed)
															//cout << imagenBGR[0];

															//  ****************************** BGR to CIELab ********************************** //
															//  **** SE ALMACENA CADA CANAL EN imagenLab[]

		Mat imagenLab_temp;
		//imagen.convertTo(imagenLab_temp, CV_32F);
		cvtColor(imagenCargada.imagen, imagenLab_temp, CV_BGR2Lab);	// Conversion de BGR 0 255 a CIELab	0 255
		Mat imagenLab[3];
		split(imagenLab_temp, imagenLab);				// Separa la imagen CIELab en 3 canales L a b
														//cout << imagenLab[1]; // imagenLab todos sus canales son de 0 a 255

														//Mat imagenLab_NEW(imagen.rows, imagen.cols, CV_8UC3); //CV_8UC3   // U porque va de 0 a 255
														//merge(imagenLab,3,imagenLab_NEW);
														//	cvtColor(imagenLab_NEW, imagenLab_temp, CV_Lab2BGR);
														//	split(imagenLab_temp, imagenLab);
														//namedWindow("L_merge", CV_WINDOW_NORMAL);
														//imshow("L_merge", imagenLab_NEW);

														//namedWindow("L", CV_WINDOW_NORMAL);
														//		namedWindow("L", CV_WINDOW_NORMAL);
														//		namedWindow("a", CV_WINDOW_NORMAL);
														//		namedWindow("b", CV_WINDOW_NORMAL);
														//		imshow("L", imagenLab[0]);
														//		imshow("a", imagenLab[1]);
														//		imshow("b", imagenLab[2]);


	// ****************************************************************************************//
	// ****************************  FFT  en  BGR y en CLIEAB  ********************************//

	// ****************************   BGR   ********************************//

		Mat tempBlue, tempGreen, tempRed;
		tempBlue = imagenBGR[0];
		tempGreen = imagenBGR[1];
		tempRed = imagenBGR[2];
		tempBlue.convertTo(tempBlue, CV_32F);
		tempGreen.convertTo(tempGreen, CV_32F);
		tempRed.convertTo(tempRed, CV_32F);

		Mat complexBlue, complexGreen, complexRed;    //Complex plane to contain the DFT coefficients {[0]-Real,[1]-Img}
													  //	merge(planes, 2, complexI);
		dft(tempBlue, complexBlue, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempGreen, complexGreen, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempRed, complexRed, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 


	// ****************************   CIELAB   ********************************//

		Mat tempL, tempa, tempb;
		tempL = imagenLab[0];
		tempa = imagenLab[1];
		tempb = imagenLab[2];
		tempL.convertTo(tempL, CV_32F);
		tempa.convertTo(tempa, CV_32F);
		tempb.convertTo(tempb, CV_32F);

		Mat complexL, complexa, complexb;			//Complex plane to contain the DFT coefficients {[0]-Real,[1]-Img}

		dft(tempL, complexL, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempa, complexa, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempb, complexb, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 


												   // Reconstructing original image from the DFT coefficients
		Mat invDFTL, invDFTcvtL, invDFTa, invDFTcvta, invDFTb, invDFTcvtb;

		idft(complexL, invDFTL, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
		idft(complexa, invDFTa, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
		idft(complexb, invDFTb, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT


	// ****************************  FIN   FFT  en  BGR y en CLIEAB  ********************************//
	// **********************************************************************************************//

	// **********************************************************************************************//
	// ************************  CALCULO DE MAGNITUDES EN FFT DE RGB Y CIELAB  **********************//

	// complexBlue, complexGreen, complexRed, complexL, complexa, complexb

		//Mat magnitudBlue;     // magnitudBlue3
		Mat complexBlueSplit[2];
		split(complexBlue, complexBlueSplit);
		magnitude(complexBlueSplit[0], complexBlueSplit[1], imagenCargada.magnitudBlue); //magnitudBlue |B^| es sqrt(R^2 +I^2)
																		   //magnitudBlue = abs(complexBlue); //valor absoluto

		//Mat magnitudGreen;
		Mat complexGreenSplit[2];
		split(complexGreen, complexGreenSplit);
		magnitude(complexGreenSplit[0], complexGreenSplit[1], imagenCargada.magnitudGreen); //magnitudGreen |G^| es sqrt(R^2 +I^2)

		//Mat magnitudRed;
		Mat complexRedSplit[2];
		split(complexRed, complexRedSplit);
		magnitude(complexRedSplit[0], complexRedSplit[1], imagenCargada.magnitudRed); //magnitudRed |R^| es sqrt(R^2 +I^2)

		//Mat magnitudL;
		//Mat complexLSplit[2];
		split(complexL, imagenCargada.complexLSplit);
		magnitude(imagenCargada.complexLSplit[0], imagenCargada.complexLSplit[1], imagenCargada.magnitudL); //magnitudL |L^| es sqrt(R^2 +I^2)

		//Mat magnituda;
		//Mat complexaSplit[2];
		split(complexa, imagenCargada.complexaSplit);
		magnitude(imagenCargada.complexaSplit[0], imagenCargada.complexaSplit[1], imagenCargada.magnituda); //magnituda |a^| es sqrt(R^2 +I^2)

		//Mat magnitudb;
		//Mat complexbSplit[2];
		split(complexb, imagenCargada.complexbSplit);
		magnitude(imagenCargada.complexbSplit[0], imagenCargada.complexbSplit[1], imagenCargada.magnitudb); //magnitudb |b^| es sqrt(R^2 +I^2)

																											// ***************** NOTA:
		//					LAS MAGNITUDES ESTAN ALMACENADAS EN LAS VARIABLES
		//					magnitudBlue, magnitudGreen, magnitudRed, magnitudL, magnituda, magnitudb

		// ********************  FIN DE CALCULO DE MAGNITUDES EN FFT DE RGB Y CIELAB  *******************//
		// **********************************************************************************************//
	}

	void QtGuiApplication3::algoritmoParteDos() {
 

		// **********************************************************************************************//
		// ***********************************  CALCULO DE TITA Y PHI  **********************************//

		Mat TITA;

		if (imagenCargada.valPromTITA == true) {		//si el valor promerio de TITA está activo = true

			// Para TITA promedio:
			//if (sum(imagenCargada.magnitudBlue + imagenCargada.magnitudGreen + imagenCargada.magnitudRed).val[0] > 0)
				TITA = (imagenCargada.magnitudBlue + imagenCargada.magnitudGreen +
					imagenCargada.magnitudRed - imagenCargada.magnitudL) /
					(imagenCargada.magnitudBlue + imagenCargada.magnitudGreen + imagenCargada.magnitudRed);
			//else
			//	TITA = 1.0;

			int m, n;
			m = imagenCargada.imagen.rows;		// Filas = alto
			n = imagenCargada.imagen.cols;		// Columnas = ancho
			double TITA2 = sum(TITA).val[0] / (m*n);		//val[0] es el primer canal que retorna sum()
															//	double TITA3 = sum(TITA).val[0];
			TITA = TITA2;

			// Mostrtamos el valor promedio de TITA arrojado por la fórmula
			ui.labelTITA->setText(QString::number(TITA2));
			ui.labelTITA->show();
			//ui.lineEditTITA->setText(QString::number(TITA2));
			//cambiarSliderTITA_ValProm();
			//cout << "\nTITA:" << TITA;

		}
		if (imagenCargada.valIndTITA == true) {		//si el valor individual de TITA está activado = true = valores individuales

			// Para TITAs individuales:
			TITA = (imagenCargada.magnitudBlue + imagenCargada.magnitudGreen +
				imagenCargada.magnitudRed - imagenCargada.magnitudL) /
				(imagenCargada.magnitudBlue + imagenCargada.magnitudGreen + imagenCargada.magnitudRed);

			// Se desactiva el label que muestra TITA promedio
			ui.labelTITA->hide();
		}
		if (imagenCargada.valManualTITA == true) {		//Si el valor de TITA es manual
			// Para TITA fijo, sin promedio:
			TITA = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32F);
			//		TITA = 1.0;
			QString textoTITA = ui.lineEditTITA->text();
			TITA = textoTITA.toFloat();
			// Se desactiva el label que muestra TITA promedio
			ui.labelTITA->hide();
			//cout << "\nMAGNITUD TITA:" << TITA; //sum(magnitudb).val[0];
			//cout << "\Valores de Lab:" << imagenLab[0];
			//cout << "\nAlto:" << m << "\nAncho: " << n;
		
		}

		
		Mat PHI;

		if (imagenCargada.valPromPHI == true) {		//si el valor promedio de PHI está activo = true

			PHI = imagenCargada.magnituda / (imagenCargada.magnituda + imagenCargada.magnitudb);
			//	cout << "\nMAGNITUD PHI:" << PHI; //sum(magnitudb).val[0];
			// Para PHI promedio>:
			int mm, nn;
			mm = imagenCargada.imagen.rows;		// Filas = alto
			nn = imagenCargada.imagen.cols;		// Columnas = ancho
			double PHI2 = sum(PHI).val[0] / (mm*nn);
			PHI = PHI2;

			// Mostrtamos el valor promedio de PHI arrojado por la fórmula
			ui.labelPHI->setText(QString::number(PHI2));
			ui.labelPHI->show();

			//ui.lineEditPHI->setText(QVariant(PHI).toString());
			//cout << "\nPHI:" << PHI2;
			//ui.lineEditPHI->setText(QString::number(PHI2));
			//cambiarSliderPHI_ValProm();

		}
		if (imagenCargada.valIndPHI == true) {		//si el valor individual de PHI está activado = true
			// Para PHI sin promedio:
			PHI = imagenCargada.magnituda / (imagenCargada.magnituda + imagenCargada.magnitudb);
			// Se desactiva el label que muestra PHI promedio
			ui.labelPHI->hide();
		}
		if (imagenCargada.valManualPHI == true) {	//Si el valor de PHI es manual
			// Para PHI fijo, sin promedio:
			PHI = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32F);
			//		PHI = 0.0;
			QString textoPHI = ui.lineEditPHI->text();
			PHI = textoPHI.toFloat();
			// Se desactiva el label que muestra PHI promedio
			ui.labelPHI->hide();
		}
		
		// *********************************** FIN CALCULO DE TITA Y PHI  *******************************//
		// **********************************************************************************************//

		// **********************************************************************************************//
		// *********************************  APLICACION DE LOS VALORES  ********************************//

		//IMAGEN_MODIFICADA = ((1 - TITA).*FFT_L_Shift) + (TITA).*(PHI.* (FFT_a_Shift)+((1 - PHI).*FFT_b_Shift));

		// *** SE DIVIDEN LAS OPERACIONES PARA TRABAJAR CON LA PARTE REAL Y LA IMAGINARIA DE LOS NUMEROS COMPLEJOS
		// *** ((1 - TITA).*FFT_L_Shift) ---------------------------------------- A
		Mat complexLSplit_temp[2];
		complexLSplit_temp[0] = imagenCargada.complexLSplit[0];
		complexLSplit_temp[1] = imagenCargada.complexLSplit[1];
		Mat unoMenosTita = 1 - TITA;
		multiply(imagenCargada.complexLSplit[0], unoMenosTita, complexLSplit_temp[0], 1.0);   // probar quitando el 1.0
		multiply(imagenCargada.complexLSplit[1], unoMenosTita, complexLSplit_temp[1], 1.0);

		// *** PHI.* (FFT_a_Shift)	--------------------------------------------- B
		Mat complexaSplit_temp[2];
		complexaSplit_temp[0] = imagenCargada.complexaSplit[0];
		complexaSplit_temp[1] = imagenCargada.complexaSplit[1];
		multiply(imagenCargada.complexaSplit[0], PHI, complexaSplit_temp[0], 1.0);
		multiply(imagenCargada.complexaSplit[1], PHI, complexaSplit_temp[1], 1.0);

		// *** ((1 - PHI).*FFT_b_Shift)	----------------------------------------- C
		Mat complexbSplit_temp[2];
		complexbSplit_temp[0] = imagenCargada.complexbSplit[0];
		complexbSplit_temp[1] = imagenCargada.complexbSplit[1];
		Mat unoMenosPhi = 1 - PHI;
		multiply(imagenCargada.complexbSplit[0], unoMenosPhi, complexbSplit_temp[0], 1.0);
		multiply(imagenCargada.complexbSplit[1], unoMenosPhi, complexbSplit_temp[1], 1.0);

		// *** B + C = D	----------------------------------------------------- D
		Mat sumaAmasB[2];
		add(complexaSplit_temp[0], complexbSplit_temp[0], sumaAmasB[0]);
		add(complexaSplit_temp[1], complexbSplit_temp[1], sumaAmasB[1]);

		// *** (TITA)*D = E	----------------------------------------------------- E
		Mat titaPorD[2];
		multiply(sumaAmasB[0], TITA, titaPorD[0], 1.0);
		multiply(sumaAmasB[1], TITA, titaPorD[1], 1.0);

		// *** A + E
		Mat sumaAmasE[2];
		add(titaPorD[0], complexLSplit_temp[0], sumaAmasE[0]);
		add(titaPorD[1], complexLSplit_temp[1], sumaAmasE[1]);

		// ****************************** FIN  APLICACION DE LOS VALORES   ******************************//
		// **********************************************************************************************//

		// **********************************************************************************************//
		// ******************************  IFFT DE LA IMAGEN MODIFICADA  ********************************//
		// **************** LA INVERSA DE LA DFT SE ALMACENA EN LA VARIABLE invDFTFinal *****************//

		Mat invDFTFinal, imagenFinal;
		Mat mergeAE; // (imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC2);
		merge(sumaAmasE, 2, mergeAE);
		idft(mergeAE, invDFTFinal, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT

	// **********************************************************************************************//
	// *****************************  FIN IFFT DE LA IMAGEN MODIFICADA  *****************************//


	// ***************************************** CIELAB2BGR *****************************************//
	// * EL RESULTADO DE LA CONVERSION DE CIELAB2BGR SE ALMACENA EN LA VARIABLE: imagenLabBGR_final *//

	// imagenFinal es de un canal, representado en el espacio Lab
	// ahora, ese canal, lo vamos a llevar al especio BGR
	// el canal L sera el indicado en imagenFinal, el canal a y b seran ceros

	// ********** LA SIGUIENTE TRANSFORMACION SE LLEVA EN EL RANGO DE 0 A 255 PARA L a b ********** //

																 /*
																 invDFTFinal.convertTo(imagenFinal, CV_8UC1);
																 Mat matrizLCerosCeros[3], imagenLabBGR_final;
																 matrizLCerosCeros[0] = imagenFinal;
																 matrizLCerosCeros[1] = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC1)*128;	// 128 es blanco para el rango de 0 a 255
																 matrizLCerosCeros[2] = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC1)*128;
																 Mat imagenLabBGR(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC3);						// U porque va de 0 a 255
																 merge(matrizLCerosCeros, 3, imagenLabBGR);
																 cvtColor(imagenLabBGR, imagenLabBGR_final, CV_Lab2BGR);						// Conversion de CIELab a BGR 0 255
																 */

	// ********** LA SIGUIENTE TRANSFORMACION SE LLEVA EN EL RANGO DE: L 0 a 100 y a, b de -127 a 127) ********** // 

		invDFTFinal.convertTo(imagenFinal, CV_32FC1);	//32FC1 para los rangos 0 100 y -127 127
		Mat matrizLCerosCeros[3], imagenLabBGR_final;
		imagenFinal = imagenFinal * 100 / 255;			// lo llevamos a un rango de 0 a 100
		matrizLCerosCeros[0] = imagenFinal;
		matrizLCerosCeros[1] = Mat::zeros(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32FC1);	// -127 0 127
		matrizLCerosCeros[2] = Mat::zeros(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32FC1);	// -127 0 127
		Mat imagenLabBGR(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32FC3);
		merge(matrizLCerosCeros, 3, imagenLabBGR);
		cvtColor(imagenLabBGR, imagenLabBGR_final, CV_Lab2BGR);					// Conversion de CIELab a BGR
		imagenLabBGR_final.convertTo(imagenLabBGR_final, CV_8U, 255.0);			//imagenLabBGR_final = imagenLabBGR_final * 255;

	// ***************************************** FIN CIELAB2BGR *****************************************//

//		namedWindow("L FINAL PROCESO", CV_WINDOW_AUTOSIZE);
//		imshow("L FINAL PROCESO", imagenLabBGR_final);

		// Se transforma la Mat de BGR a RGB, se convierte a Qpixmap y se carga en el label:
		cvMat2QPixmap(imagenLabBGR_final);

		// GUARDAMOS EL RESULTADO Y LO MOSTRAMOS
		/* imwrite("C:/Users/Irena/Pictures/Gray_Image2.jpg", imagenLabBGRtoRGB, vector<int>({ CV_IMWRITE_JPEG_QUALITY, 100 }));
		QPixmap pix("C:/Users/Irena/Pictures/Gray_Image.jpg");
		ui.label_pic->setPixmap(pix.scaled(al, an, Qt::KeepAspectRatio)); // KeepAspectRatio KeepAspectRatioByExpanding
		ui.label_pic->repaint();
		*/

	}

	// Probando la transformación de RGB a BGR y a QpixMap
	void QtGuiApplication3::transformacionBGRtoQpixMap() {
	
		//*********************************************************************//
		//**** ESTA PARTE SE MANEJA CON ImagenCargada::setDireccionEntrada ****//
														// char entrada[100] = "Flor.jpg";
/*		char entrada[100] = "";
		string stringDireccion = direccion.toUtf8();
														// int n = stringDireccion.length();
		strcpy(entrada, stringDireccion.c_str());		// copying the contents of the string to char array
*/
		//*********************************************************************//
		//*********************************************************************//

	//	char entrada[100] = "";
	//	direccionEntrada(direccion);	
	// la dirección de entrada se guarda en la variable static dirEntrada

		//Mat imagen;										// new image - nueva imagen
		///imagen = imread(entrada, IMREAD_COLOR);			// read the file - leer el archivo
//		imagen = imread(ImagenCargada::dirEntrada, IMREAD_COLOR);			// read the file - leer el archivo
		imagenCargada.imagen = imread(imagenCargada.nombreArchivo, IMREAD_COLOR);
	//	imagen = imread(dirEntrada, IMREAD_COLOR);

		if (!imagenCargada.imagen.data)								// Check for invalid input - chequea entrada invalida
		{
			cout << "No se pudo abrir o encontrar la imagen";
			//CargarimagenBGR();
			cin.get();
			return;
		}

		//**********************************************************************************//
		// ************************************** BGR ************************************* //
		// **** SE ALMACENA CADA CANAL EN imagenBGR[]

		Mat imagenBGR[3];						//	Matriz de 3 canales
		imagenCargada.imagen.convertTo(imagenCargada.imagen, CV_8U);		//	8U es de 0 a 255
		split(imagenCargada.imagen, imagenBGR);				//	Separa la imagen original en 3 canales BGR (BlueGreenRed)
												//cout << imagenBGR[0];

		//  ****************************** BGR to CIELab ********************************** //
		//  **** SE ALMACENA CADA CANAL EN imagenLab[]

		Mat imagenLab_temp;
		//imagen.convertTo(imagenLab_temp, CV_32F);
		cvtColor(imagenCargada.imagen, imagenLab_temp, CV_BGR2Lab);	// Conversion de BGR 0 255 a CIELab	0 255
		Mat imagenLab[3];
		split(imagenLab_temp, imagenLab);				// Separa la imagen CIELab en 3 canales L a b
														//cout << imagenLab[1]; // imagenLab todos sus canales son de 0 a 255

														//Mat imagenLab_NEW(imagen.rows, imagen.cols, CV_8UC3); //CV_8UC3   // U porque va de 0 a 255
														//merge(imagenLab,3,imagenLab_NEW);
														//	cvtColor(imagenLab_NEW, imagenLab_temp, CV_Lab2BGR);
														//	split(imagenLab_temp, imagenLab);
														//namedWindow("L_merge", CV_WINDOW_NORMAL);
														//imshow("L_merge", imagenLab_NEW);

														//namedWindow("L", CV_WINDOW_NORMAL);
//		namedWindow("L", CV_WINDOW_NORMAL);
//		namedWindow("a", CV_WINDOW_NORMAL);
//		namedWindow("b", CV_WINDOW_NORMAL);
//		imshow("L", imagenLab[0]);
//		imshow("a", imagenLab[1]);
//		imshow("b", imagenLab[2]);


		// ****************************************************************************************//
		// ****************************  FFT  en  BGR y en CLIEAB  ********************************//

		// ****************************   BGR   ********************************//

		Mat tempBlue, tempGreen, tempRed;
		tempBlue = imagenBGR[0];
		tempGreen = imagenBGR[1];
		tempRed = imagenBGR[2];
		tempBlue.convertTo(tempBlue, CV_32F);
		tempGreen.convertTo(tempGreen, CV_32F);
		tempRed.convertTo(tempRed, CV_32F);

		Mat complexBlue, complexGreen, complexRed;    //Complex plane to contain the DFT coefficients {[0]-Real,[1]-Img}
													  //	merge(planes, 2, complexI);
		dft(tempBlue, complexBlue, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempGreen, complexGreen, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempRed, complexRed, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 


		// ****************************   CIELAB   ********************************//
				
		Mat tempL, tempa, tempb;
		tempL = imagenLab[0];
		tempa = imagenLab[1];
		tempb = imagenLab[2];
		tempL.convertTo(tempL, CV_32F);
		tempa.convertTo(tempa, CV_32F);
		tempb.convertTo(tempb, CV_32F);

		Mat complexL, complexa, complexb;			//Complex plane to contain the DFT coefficients {[0]-Real,[1]-Img}

		dft(tempL, complexL, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempa, complexa, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 
		dft(tempb, complexb, DFT_COMPLEX_OUTPUT);  // Applying DFT dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT); 


	    // Reconstructing original image from the DFT coefficients
		Mat invDFTL, invDFTcvtL, invDFTa, invDFTcvta, invDFTb, invDFTcvtb;

		idft(complexL, invDFTL, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
		idft(complexa, invDFTa, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
		idft(complexb, invDFTb, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT

	
		// ****************************  FIN   FFT  en  BGR y en CLIEAB  ********************************//
		// **********************************************************************************************//

		// **********************************************************************************************//
		// ************************  CALCULO DE MAGNITUDES EN FFT DE RGB Y CIELAB  **********************//

		// complexBlue, complexGreen, complexRed, complexL, complexa, complexb

		Mat magnitudBlue;     // magnitudBlue3
		Mat complexBlueSplit[2];
		split(complexBlue, complexBlueSplit);
		magnitude(complexBlueSplit[0], complexBlueSplit[1], magnitudBlue); //magnitudBlue |B^| es sqrt(R^2 +I^2)
																		   //magnitudBlue = abs(complexBlue); //valor absoluto

		Mat magnitudGreen;
		Mat complexGreenSplit[2];
		split(complexGreen, complexGreenSplit);
		magnitude(complexGreenSplit[0], complexGreenSplit[1], magnitudGreen); //magnitudGreen |G^| es sqrt(R^2 +I^2)

		Mat magnitudRed;
		Mat complexRedSplit[2];
		split(complexRed, complexRedSplit);
		magnitude(complexRedSplit[0], complexRedSplit[1], magnitudRed); //magnitudRed |R^| es sqrt(R^2 +I^2)

		Mat magnitudL;
		Mat complexLSplit[2];
		split(complexL, complexLSplit);
		magnitude(complexLSplit[0], complexLSplit[1], magnitudL); //magnitudL |L^| es sqrt(R^2 +I^2)

		Mat magnituda;
		Mat complexaSplit[2];
		split(complexa, complexaSplit);
		magnitude(complexaSplit[0], complexaSplit[1], magnituda); //magnituda |a^| es sqrt(R^2 +I^2)

		Mat magnitudb;
		Mat complexbSplit[2];
		split(complexb, complexbSplit);
		magnitude(complexbSplit[0], complexbSplit[1], magnitudb); //magnitudb |b^| es sqrt(R^2 +I^2)

	
		// ***************** NOTA:
		//					LAS MAGNITUDES ESTAN ALMACENADAS EN LAS VARIABLES
		//					magnitudBlue, magnitudGreen, magnitudRed, magnitudL, magnituda, magnitudb

		// ********************  FIN DE CALCULO DE MAGNITUDES EN FFT DE RGB Y CIELAB  *******************//
		// **********************************************************************************************//

		// **********************************************************************************************//
		// ***********************************  CALCULO DE TITA Y PHI  **********************************//

		Mat TITA;
		
		if (imagenCargada.valPromTITA){		//si el valor promerio de TITA está activo = true
			
			// Para TITA promedio:
			
			TITA = (magnitudBlue + magnitudGreen + magnitudRed - magnitudL) / (magnitudBlue + magnitudGreen + magnitudRed);

			int m, n;
			m = imagenCargada.imagen.rows;		// Filas = alto
			n = imagenCargada.imagen.cols;		// Columnas = ancho
			double TITA2 = sum(TITA).val[0] / (m*n);		//val[0] es el primer canal que retorna sum()
			//	double TITA3 = sum(TITA).val[0];
			TITA = TITA2;
			//cout << "\nTITA:" << TITA;
		
		}
		if(imagenCargada.valIndTITA) {		//si el valor promerio de TITA está desactivado = false = valores individuales
			// Para TITA fijo, sin promedio:
			TITA = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32F);
	//		TITA = 1.0;
			QString textoTITA = ui.lineEditTITA->text();
			TITA = textoTITA.toFloat();
			//cout << "\nMAGNITUD TITA:" << TITA; //sum(magnitudb).val[0];
			//cout << "\Valores de Lab:" << imagenLab[0];
			//cout << "\nAlto:" << m << "\nAncho: " << n;

		}
		
		

		Mat PHI;

		if (imagenCargada.valPromPHI) {		//si el valor promerio de PHI está activo = true
			PHI = magnituda / (magnituda + magnitudb);
			//	cout << "\nMAGNITUD PHI:" << PHI; //sum(magnitudb).val[0];
			// Para PHI promedio>:
			int mm, nn;
			mm = imagenCargada.imagen.rows;		// Filas = alto
			nn = imagenCargada.imagen.cols;		// Columnas = ancho
			double PHI2 = sum(PHI).val[0] / (mm*nn);
			PHI = PHI2;
			//cout << "\nPHI:" << PHI2;
			
		}
		if (imagenCargada.valIndPHI) {		//si el valor promerio de PHI está desactivado = false = valores individuales
			// Para PHI fijo, sin promedio:
			PHI = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32F);
	//		PHI = 0.0;
			QString textoPHI = ui.lineEditPHI->text();
			PHI = textoPHI.toFloat();				
		}


		// *********************************** FIN CALCULO DE TITA Y PHI  *******************************//
		// **********************************************************************************************//

		// **********************************************************************************************//
		// *********************************  APLICACION DE LOS VALORES  ********************************//

		//IMAGEN_MODIFICADA = ((1 - TITA).*FFT_L_Shift) + (TITA).*(PHI.* (FFT_a_Shift)+((1 - PHI).*FFT_b_Shift));

		// *** SE DIVIDEN LAS OPERACIONES PARA TRABAJAR CON LA PARTE REAL Y LA IMAGINARIA DE LOS NUMEROS COMPLEJOS
		// *** ((1 - TITA).*FFT_L_Shift) ---------------------------------------- A
		Mat complexLSplit_temp[2];
		complexLSplit_temp[0] = complexLSplit[0];
		complexLSplit_temp[1] = complexLSplit[1];
		Mat unoMenosTita = 1 - TITA;
		multiply(complexLSplit[0], unoMenosTita, complexLSplit_temp[0], 1.0);   // probar quitando el 1.0
		multiply(complexLSplit[1], unoMenosTita, complexLSplit_temp[1], 1.0);

		// *** PHI.* (FFT_a_Shift)	--------------------------------------------- B
		Mat complexaSplit_temp[2];
		complexaSplit_temp[0] = complexaSplit[0];
		complexaSplit_temp[1] = complexaSplit[1];
		multiply(complexaSplit[0], PHI, complexaSplit_temp[0], 1.0);
		multiply(complexaSplit[1], PHI, complexaSplit_temp[1], 1.0);

		// *** ((1 - PHI).*FFT_b_Shift)	----------------------------------------- C
		Mat complexbSplit_temp[2];
		complexbSplit_temp[0] = complexbSplit[0];
		complexbSplit_temp[1] = complexbSplit[1];
		Mat unoMenosPhi = 1 - PHI;
		multiply(complexbSplit[0], unoMenosPhi, complexbSplit_temp[0], 1.0);
		multiply(complexbSplit[1], unoMenosPhi, complexbSplit_temp[1], 1.0);

		// *** B + C = D	----------------------------------------------------- D
		Mat sumaAmasB[2];
		add(complexaSplit_temp[0], complexbSplit_temp[0], sumaAmasB[0]);
		add(complexaSplit_temp[1], complexbSplit_temp[1], sumaAmasB[1]);

		// *** (TITA)*D = E	----------------------------------------------------- E
		Mat titaPorD[2];
		multiply(sumaAmasB[0], TITA, titaPorD[0], 1.0);
		multiply(sumaAmasB[1], TITA, titaPorD[1], 1.0);

		// *** A + E
		Mat sumaAmasE[2];
		add(titaPorD[0], complexLSplit_temp[0], sumaAmasE[0]);
		add(titaPorD[1], complexLSplit_temp[1], sumaAmasE[1]);

		// ****************************** FIN  APLICACION DE LOS VALORES   ******************************//
		// **********************************************************************************************//

		// **********************************************************************************************//
		// ******************************  IFFT DE LA IMAGEN MODIFICADA  ********************************//
		// **************** LA INVERSA DE LA DFT SE ALMACENA EN LA VARIABLE invDFTFinal *****************//

		Mat invDFTFinal, imagenFinal;
		Mat mergeAE; // (imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC2);
		merge(sumaAmasE, 2, mergeAE);
		idft(mergeAE, invDFTFinal, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT

		// **********************************************************************************************//
		// *****************************  FIN IFFT DE LA IMAGEN MODIFICADA  *****************************//


		// ***************************************** CIELAB2BGR *****************************************//
		// * EL RESULTADO DE LA CONVERSION DE CIELAB2BGR SE ALMACENA EN LA VARIABLE: imagenLabBGR_final *//

		// imagenFinal es de un canal, representado en el espacio Lab
		// ahora, ese canal, lo vamos a llevar al especio BGR
		// el canal L sera el indicado en imagenFinal, el canal a y b seran ceros

		// ********** LA SIGUIENTE TRANSFORMACION SE LLEVA EN EL RANGO DE 0 A 255 PARA L a b ********** //

		/*
		invDFTFinal.convertTo(imagenFinal, CV_8UC1);
		Mat matrizLCerosCeros[3], imagenLabBGR_final;
		matrizLCerosCeros[0] = imagenFinal;
		matrizLCerosCeros[1] = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC1)*128;	// 128 es blanco para el rango de 0 a 255
		matrizLCerosCeros[2] = Mat::ones(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC1)*128;
		Mat imagenLabBGR(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_8UC3);						// U porque va de 0 a 255
		merge(matrizLCerosCeros, 3, imagenLabBGR);
		cvtColor(imagenLabBGR, imagenLabBGR_final, CV_Lab2BGR);						// Conversion de CIELab a BGR 0 255
		*/

		// ********** LA SIGUIENTE TRANSFORMACION SE LLEVA EN EL RANGO DE: L 0 a 100 y a, b de -127 a 127) ********** // 

		invDFTFinal.convertTo(imagenFinal, CV_32FC1);	//32FC1 para los rangos 0 100 y -127 127
		Mat matrizLCerosCeros[3], imagenLabBGR_final;
		imagenFinal = imagenFinal * 100 / 255;			// lo llevamos a un rango de 0 a 100
		matrizLCerosCeros[0] = imagenFinal;
		matrizLCerosCeros[1] = Mat::zeros(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32FC1);	// -127 0 127
		matrizLCerosCeros[2] = Mat::zeros(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32FC1);	// -127 0 127
		Mat imagenLabBGR(imagenCargada.imagen.rows, imagenCargada.imagen.cols, CV_32FC3);
		merge(matrizLCerosCeros, 3, imagenLabBGR);
		cvtColor(imagenLabBGR, imagenLabBGR_final, CV_Lab2BGR);					// Conversion de CIELab a BGR
		imagenLabBGR_final.convertTo(imagenLabBGR_final, CV_8U, 255.0);			//imagenLabBGR_final = imagenLabBGR_final * 255;

		// ***************************************** FIN CIELAB2BGR *****************************************//

		namedWindow("L FINAL PROCESO", CV_WINDOW_AUTOSIZE);
		imshow("L FINAL PROCESO", imagenLabBGR_final);

		// Se transforma la Mat de BGR a RGB, se convierte a Qpixmap y se carga en el label:
		cvMat2QPixmap(imagenLabBGR_final);

/* // GUARDAMOS EL RESULTADO Y LO MOSTRAMOS
		imwrite("C:/Users/Irena/Pictures/Gray_Image2.jpg", imagenLabBGRtoRGB, vector<int>({ CV_IMWRITE_JPEG_QUALITY, 100 }));
		QPixmap pix("C:/Users/Irena/Pictures/Gray_Image.jpg");
		ui.label_pic->setPixmap(pix.scaled(al, an, Qt::KeepAspectRatio)); // KeepAspectRatio KeepAspectRatioByExpanding
		ui.label_pic->repaint();
*/

	}


/*
	// const &mat
	QPixmap mat_to_qimage_cpy(Mat mat,
		QImage::Format format)
	{
	//	return QImage(mat.data, mat.cols, mat.rows,
	//		mat.step, format).copy();
		static QImage QI = QImage(mat.data, mat.cols, mat.rows,
			mat.step, format).copy();
		QPixmap pixmap = QPixmap::fromImage(QI);
		return pixmap;    // 0 es default options  // Qt::AutoColor
	}
*/

	// ************************************************************** //
	// **** FUNCIONES PARA APLICAR SOBRE LA IMAGEN CARGADA **** //

	// Transformamos la dirección de la imagen, de QString a string
	// para que se pueda tranajar con Opencv
	void QtGuiApplication3::direccionEntrada(QString direccion)
	{
		imagenCargada.nombreArchivo = direccion.toUtf8().constData();
		//dirEntrada = direccion.toUtf8().constData();	// dirEntrada es static
	}

	// Se transforma la imagen de entrada (cv::Mat) a QPixmap
	// y se despliega en el Qlabel
	// bool = true es que se va a desplegar un label diferente, a color
	void QtGuiApplication3::cvMat2QPixmap(Mat matrizImagen) {
	
		int matFilas = imagenCargada.imagen.rows;
		int matColumnas = imagenCargada.imagen.cols;

		// Transformar de BGR a RGB y a QPixmap
		Mat imagenLabBGRtoRGB(matFilas, matColumnas, CV_32FC3);			// CV_32FC3   //CV_8UC3
		cvtColor(matrizImagen, imagenLabBGRtoRGB, CV_BGR2RGB);			// Conversion de BGR a RGB

		int al = ui.label_pic->width();
		int an = ui.label_pic->height();

//		cvtColor(imagenLabBGR, imagenLabBGR_final, CV_Lab2RGB);				// Conversion de CIELab a BGR
//		imagenLabBGR_final.convertTo(imagenLabBGR_final, CV_32FC3);			//imagenLabBGR_final = imagenLabBGR_final * 255;

		//QImage() //(unsigned char*)
		QPixmap pixMapFinal(QPixmap::fromImage(QImage((uchar*)imagenLabBGRtoRGB.data,
			imagenLabBGRtoRGB.cols,
			imagenLabBGRtoRGB.rows,
			imagenLabBGRtoRGB.step,
			QImage::Format_RGB888)));   //QImage::Format_RGB888.rgbSwapped() 
										// si le quito el rgbSwapped le coloco es imagenLabBGRtoRGB
										//Qt::AspectRatioMode();

			ui.label_pic->setPixmap(pixMapFinal.scaled(al, an, Qt::KeepAspectRatio)); // KeepAspectRatio KeepAspectRatioByExpanding
			ui.label_pic->repaint();

	}

	void QtGuiApplication3::mostrarOriginal() {

		// Si la imagen no est[a en un QPixmap se debe de hacer una función como:
		// cvMat2QPixmap(imagenCargada.imagen);
		QPixmap pix2(imagenCargada.fileName);

		int al = ui.label_pic_color->width();
		int an = ui.label_pic_color->height();

		ui.label_pic_color->setPixmap(pix2.scaled(al, an, Qt::KeepAspectRatio)); // KeepAspectRatio KeepAspectRatioByExpanding
		ui.label_pic_color->repaint();
		ui.label_pic_color->show();

	}

	void QtGuiApplication3::ocultarOriginal() {
	
		ui.label_pic_color->hide();

	}
