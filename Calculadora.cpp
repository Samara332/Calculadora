#include <iostream>
#include <bits/stdc++.h> //libreria sort
#include <math.h> //Libreria operaciones matematicas
using namespace std;

/*CLASES*/

class OpBasicas //Clase de operaciones fundamentales
{
public:
  double add(int i);
  double sub(int i);
  double mul(int i);
  double pot();
  double div(int i);
};

class Geometrico: public OpBasicas //Clase de operaciones geometricas
{
  double ancho;
  double largo;
  double profundidad;
  double base;
  double altura;
  float radio;

public:
  void setAncho(); //Mutadores
  void setLargo();
  void setProfundidad();
  void setBase();
  void setAltura();
  void setRadio();

  double areaRec();
  double perimetroRec();
  double volumenRec();
  double areaTria();
  double perimetroTria();
  double volumenTria();
  double areaCir();
  double perimetroCir();
  double volumenCir();
};

class Matrices: public Geometrico //Clase de operaciones matriciales
{
  double A[50][50] = {0}; //matriz de usuario 1
  double B[50][50] = {0}; //matriz de usuario 2
  double C[50][50] = {0}; //transpuesta de 1
  double D[50][50] = {0}; //transpuesta de 2
  double R[50][50] = {0}; //matriz resultado

public:
  void setData(int sizex, int sizey);
  void sumaM(int sizex, int sizey);
  void restaM(int sizex, int sizey);
  void multM(int sizex, int sizey);
  void transM(int sizex, int sizey);
  void printR(int sizex, int sizey);
};

class Vectoriales: public Matrices //Clase de operaciones vectoriales
{
  int x3,x4;
  int y3,y4;
  int z3,z4;

  public: //publico
  void setx(int x1,int x2);//MUTADORES
  void sety(int y1, int y2);
  void setz (int z1, int z2);

  int getx();//ACCESOS
  int gety();
  int getz();

  void ecuaciones();//OPERACIONES
  void distancia();
  void mvector();
  void sumavectores();
};

class Estadistica: public Vectoriales //Clase de operaciones estadisticas
{
  double A[50] = {0}; // matriz de usuario

public:
  void setData(int i);
  double media(int i);
  double moda(int i);
  double mediana(int i);

};

class Fullcalc: public Estadistica //Clase de calculadora completa
{
public:
  void OpBasic();
  void Geometry();
  void Matrix();
  void Vectorial();
  void Estadisticas();
};

int main() //interfaz de usuario
{
  int menu = 0;
  Fullcalc calculadora; //CREACION DE OBJETO DE CLASE GENERAL

  cout << "1.Basica"
		<< "\n2.Geometrica"
		<< "\n3.Matricial"
    << "\n4.Vectorial"
    << "\n5.Estadistica"
		<< "\n0.SALIR"
		<< "\n" <<endl;

  do {

    cout << "\nINGRESE TIPO DE OPERACION ";
    cin >> menu;

    switch (menu) {
      case 1: // OPERACIONES BASICAS
        calculadora.OpBasic();
      break;
      case 2: // OPERACIONES GEOMETRICAS
        calculadora.Geometry();
      break;
      case 3: // OPERACIONES MATRICIALES
        calculadora.Matrix();
      break;
      case 4: // OPERACIONES VECTORIALES
        calculadora.Vectorial();
      break;
      case 5: // OPERACIONES ESTADISTICAS
        calculadora.Estadisticas();
      break;
    }

  } while (menu>= 1 && menu <= 5);
}

void Fullcalc::OpBasic() //función menú de la calculadora básica
{
  int s = 0, cant = 0;
  OpBasicas calculadora; //creacion de objeto en clase basica

  cout << "1.SUMA"
		<< "\n2.RESTA"
		<< "\n3.MULTIPLICA"
		<< "\n4.DIVIDE"
		<< "\n5.POTENCIA"
		<< "\n0.SALIR"
		<< "\n";

  do {

		cout << "\nINGRESE SU OPERACION: ";
		cin >> s;

		switch (s) {
		case 1: // SUMA
      cout << "\nSUMA, INGRESE CANTIDAD DE NUMEROS: ";
		  cin >> cant;
			cout << calculadora.add(cant) << endl;
			break;
		case 2: // RESTA
      cout << "\nRESTA, INGRESE CANTIDAD DE NUMEROS: ";
      cin >> cant;
			cout << calculadora.sub(cant) << endl;
			break;
		case 3: // MULTIPLICACION
      cout << "\nMULT, INGRESE CANTIDAD DE NUMEROS: ";
      cin >> cant;
			cout << calculadora.mul(cant) << endl;
			break;
		case 4: // DIVISION
      cout << "\nDIV, INGRESE CANTIDAD DE NUMEROS: ";
      cin >> cant;
			cout << calculadora.div(cant) << endl;
			break;
		case 5: // POTENCIA
			cout << calculadora.pot() << endl;
			break;
		}

	} while (s>= 1 && s <= 5);
}

double OpBasicas::add(int i) //OPERADOR SUMA, cantidad de datos
{
  int num = 0, result = 0;
  for (int x = 0; x < i; x++) //ciclo para el total de digitos
  {
      cout << "ingresa numero " << x << ": " << endl;
      cin >> num;
      result += num; //suma a variable resultado
  }
  return result; //regresar suma total
}

double OpBasicas::sub(int i) //OPERADOR RESTA, cantidad de datos
{
  int num = 0, result = 0;
  cout << "ingresa numero 0: "<< endl;
  cin >> num;
  result = num; //valor inical de la resta
  for (int x = 1; x < i; x++) //ciclo para el total de digitos -1
  {
    cout << "ingresa numero " << x << ": " << endl;
    cin >> num;
      result -= num; //resta a variable resultado
  }
  return result; //regresar resta total
}

double OpBasicas::mul(int i) //OPERADOR MUlTIPLICACION, cantidad de datos
{
  int num = 1, result = 1;
  for (int x = 0; x < i; x++) //ciclo para el total de digitos -1
  {
    cout << "ingresa numero " << x << ": " << endl;
    cin >> num;
      result *= num; //multiplicacion a variable resultado
  }
  return result; //regresar mult total
}

double OpBasicas::pot() //OPERADOR POTENCIA, cantidad de datos
{
  int num = 0, power = 0, result = 0;

    cout << "ingresa numero: " << endl;
    cin >> num;
    cout << "ingresa potencia: " << endl;
    cin >> power;

    return pow(num, power); //regresa potencia de los numeros dados por usuario
}

double OpBasicas::div(int i) //OPERADOR DIVISION, cantidad de datos
{
  int num = 1, result = 1;
  cout << "ingresa numero 0: " << endl;
  cin >> num;
  result = num; //primer valor de resultado para la division
  for (int x = 1; x < i; x++) //ciclo para el total de digitos -1
  {
    cout << "ingresa numero " << x << ": " << endl;
    cin >> num;
    if (num == 0){ //si el numero es 0 se tiene un error
      cout << "division entre 0" <<endl;
      return 0;
    } else {
        result /= num; // division al resultado
    }
  }
  return result; // regresar division
}

void Fullcalc::Geometry() //función menú de la calculadora geometrica
{
  int menu1 = 0, menu2 = 0;
  Geometrico calculadora; //creacion de objeto en clase geometrica

  cout << "1.RECTANGULO"
		<< "\n2.TRIANGULO"
		<< "\n3.CIRCULO"
		<< "\n0.SALIR"
		<< "\n" <<endl;

  do {

    cout << "\nINGRESE SU FIGURA ";
    cin >> menu1;

    switch (menu1) { //PRIMER SWITCH CASE PARA DETERMINAR LA FIGURA
      case 1: // RECTANGULO
        cout << "1.PERIMETRO"
      		<< "\n2.AREA"
      		<< "\n3.VOLUMEN"
      		<< "\n0.SALIR"
      		<< "\n" <<endl;
        cout << "\nINGRESE SU OPERACION ";
        cin >> menu2;

        switch (menu2) { //SEGUNDO SWITCH CASE PARA DETERMINAR LA OPERACION
          case 1: // PERIMETRO
            calculadora.setAncho();
            calculadora.setLargo();
            cout << "RESULTADO: " << calculadora.perimetroRec() << endl;
          break;
          case 2: // AREA
            calculadora.setAncho();
            calculadora.setLargo();
            cout << "RESULTADO: " << calculadora.areaRec() << endl;
          break;
          case 3: // VOLUMEN
            calculadora.setAncho();
            calculadora.setLargo();
            calculadora.setProfundidad();
            cout << "RESULTADO: " << calculadora.volumenRec() << endl;
          break;
      }
      break;

      case 2: // TRIANGULO
        cout << "1.PERIMETRO"
          << "\n2.AREA"
          << "\n3.VOLUMEN"
          << "\n0.SALIR"
          << "\n" <<endl;
        cout << "\nINGRESE SU OPERACION ";
        cin >> menu2;

        switch (menu2) { //SEGUNDO SWITCH CASE PARA DETERMINAR LA OPERACION
        case 1: // PERIMETRO
          calculadora.setBase();
          cout << "RESULTADO: " << calculadora.perimetroTria() << endl;
          break;
        case 2: // AREA
          calculadora.setBase();
          calculadora.setAltura();
          cout << "RESULTADO: " << calculadora.areaTria() << endl;
          break;
        case 3: // VOLUMEN
          calculadora.setBase();
          calculadora.setAltura();
          cout << "RESULTADO: " << calculadora.volumenTria() << endl;
          break;
        }
        break;

        case 3: //CIRCULO
          cout << "1.PERIMETRO"
            << "\n2.AREA"
            << "\n3.VOLUMEN"
            << "\n0.SALIR"
            << "\n" <<endl;
          cout << "\nINGRESE SU OPERACION ";
          cin >> menu2;

          switch (menu2) { //SEGUNDO SWITCH CASE PARA DETERMINAR LA OPERACION
          case 1:
            calculadora.setRadio(); // PERIMETRO
            cout << "RESULTADO: " << calculadora.perimetroCir() << endl;
            break;
          case 2:
            calculadora.setRadio(); // AREA
            cout << "RESULTADO: " << calculadora.areaCir() << endl;
            break;
          case 3: // VOLUMEN
            calculadora.setRadio();
            cout << "RESULTADO: " << calculadora.volumenCir() << endl;
            break;
          }
          break;
      }

  } while (menu1>= 1 && menu1 <= 3);
}

/*FUNCIONES PARA OBTENER DATOS*/

void Geometrico::setAncho()
{
  int A;
  cout << "ingrese ancho: "<<endl;
  cin >> A;
  if(A<0) // si el valor ingresado es negativo, convertirlo
    A=A*-1;
  ancho = A;
}

void Geometrico::setLargo()
{
  int L;
  cout << "ingrese largo: "<<endl;
  cin >> L;
  if(L<0) // si el valor ingresado es negativo, convertirlo
    L=L*-1;
  largo = L;
}

void Geometrico::setProfundidad()
{
  int P;
  cout << "ingrese profundidad: "<<endl;
  cin >> P;
  if(P<0) // si el valor ingresado es negativo, convertirlo
    P=P*-1;
  profundidad = P;
}

void Geometrico::setBase()
{
  int B;
  cout << "ingrese base: "<<endl;
  cin >> B;
  if(B<0) // si el valor ingresado es negativo, convertirlo
    B=B*-1;
  base = B;
}

void Geometrico::setAltura()
{
  int H;
  cout << "ingrese altura: "<<endl;
  cin >> H;
  if(H<0) // si el valor ingresado es negativo, convertirlo
    H=H*-1;
  altura = H;
}

void Geometrico::setRadio()
{
  int R;
  cout << "ingrese radio: "<<endl;
  cin >> R;
  if(R<0) // si el valor ingresado es negativo, convertirlo
    R=R*-1;
  radio = R;
}

/* OPERADORES */
double Geometrico::areaRec() //AREA RECTANGULO
{
  return ancho*largo;
}

double Geometrico::perimetroRec() //PERIMETRO RECTANGULO
{
  return (ancho+largo)*2;
}

double Geometrico::volumenRec() // VOLUMEN RECTANGULO
{
  return(ancho*largo*profundidad);
}

double Geometrico::areaTria() //AREA TRIANGULO
{
  return (base*altura)/2;
}

double Geometrico::perimetroTria() // PERIMETRO TRIANGULO
{
  return base*3;
}

double Geometrico::volumenTria() //VOLUMEN TRIANGULO
{
  return((sqrt(3)/4)*(base*base)*altura);
}

double Geometrico::areaCir() //AREA CIRCULO
{

  return (3.1416*(radio*radio));
}

double Geometrico::perimetroCir() //PERIMETRO CIRCULO
{
  return ((2 * 3.1416) * radio);
}

double Geometrico::volumenCir() //VOLUMEN CIRCULO
{
  return ((4/3)*3.1416)*(pow(radio,3));
}

void Fullcalc::Matrix() //función menú de la calculadora matricial
{
  int menu = 0, sizex = 0, sizey = 0;
  Matrices calculadora; //creacion de objeto en clase matricial

  cout << "1.SUMA"
		<< "\n2.RESTA"
		<< "\n3.MULTIPLICACION"
    << "\n4.TRANSPOSICION"
		<< "\n0.SALIR"
		<< "\n" <<endl;

    do {
    		cout << "\nINGRESE SU OPERACION ";
    		cin >> menu;

    		switch (menu) {
      		case 1: // SUMA
            cout << "tamaño de matrices: "<<endl;
            cin >> sizex;
            sizey = sizex;
            calculadora.setData(sizex, sizey); //llenado de matriz
      			calculadora.sumaM(sizex, sizey); // Suma de matriz
            calculadora.printR(sizex, sizey); // impresion de matriz
      			break;
      		case 2: // RESTA
            cout << "tamaño de matrices: "<<endl;
            cin >> sizex;
            sizey = sizex;
            calculadora.setData(sizex, sizey); //llenado de matriz
      			calculadora.restaM(sizex, sizey); // Suma de matriz
            calculadora.printR(sizex, sizey); // impresion de matriz
      			break;
      		case 3: // MULTIPLICACION
            cout << "tamaño de matrices: "<<endl;
            cin >> sizex;
            sizey = sizex;
            calculadora.setData(sizex, sizey); //llenado de matriz
      			calculadora.multM(sizex, sizey); // Suma de matriz
            calculadora.printR(sizex, sizey); // impresion de matriz
      			break;
          case 4: // TRANSPOSICION
            cout << "tamaño de matrices: "<<endl;
            cin >> sizex;
            sizey = sizex;
            calculadora.setData(sizex, sizey); //llenado de matriz
        		calculadora.transM(sizex, sizey); // Suma de matriz
            calculadora.printR(sizex, sizey); // impresion de matriz
        		break;
    		}

    	} while (menu>= 1 && menu <= 4);
}

/*FUNCIONES PARA OBTENER DATOS*/

void Matrices::setData(int sizex, int sizey) // tamaño en x, tamaño en y
{
  cout << "MATRIZ A: " <<endl;
  for (int x=0; x<sizex; x++){ //llenado de las matrices
    for (int i=0; i<sizey; i++){
          cout << "Fila: " << x << " columna: " << i <<endl;
          cin >> A[i][x];
      }
  }

  cout << "MATRIZ B: " <<endl;
  for (int x=0; x<sizex; x++){ //llenado de las matrices
    for (int i=0; i<sizey; i++){
          cout << "Fila: " << x << " columna: " << i <<endl;
          cin >> B[i][x];
      }
  }
}

/* OPERADORES */

void Matrices::sumaM(int sizex, int sizey) //SUMA, tamaño en x, tamaño en y
{
  for (int x=0; x<sizex; x++){ //SUMA MATRICIAL
    for (int i=0; i<sizey; i++){
          R[i][x] = A[i][x] + B [i][x];
      }
  }
}

void Matrices::restaM(int sizex, int sizey) //RESTA, tamaño en x, tamaño en y
{
  for (int x=0; x<sizex; x++){ //RESTA MATRICIAL
    for (int i=0; i<sizey; i++){
          R[i][x] = A[i][x] - B [i][x];
      }
  }
}

void Matrices::multM(int sizex, int sizey) //MULTIPLCACION, tamaño en x, tamaño en y
{
  for (int x=0; x<sizex; x++){ //MUlTIPLICACION MATRICIAL
    for (int i=0; i<sizey; i++){
          R[i][x] = A[i][x] * B [i][x];
      }
  }
}

void Matrices::transM(int sizex, int sizey) //TRANSPUESTA, tamaño en x, tamaño en y
{
  int i,j,aux1,aux2;
  for (int x=0; x<sizex; x++) {
      for(int i=0; i<sizey; i++) {
        //matriz1 cambio de posición
        aux1 = A[x][i]; //variable temporal para guardado
        C[x][i] = A[i][x];
        A[i][x] = aux1;
        //matriz2 cambio de posición
        aux2 = B[x][i]; //variable temporal para guardado
        D[x][i] = B[i][x];
        B[i][x] = aux2;
      }
  }
}

/*FUNCIONES PARA IMPRESION*/

void Matrices::printR(int sizex, int sizey)
{
  for (int x=0; x<sizex; x++){ //impresion de matriz resultado
    for (int i=0; i<sizey; i++){
          cout << R[i][x] <<" ";
      }
    cout <<endl;
  }
  for (int x=0; x<sizex; x++){ //impresion de matriz transpuesta 1
    for (int i=0; i<sizey; i++){
          cout << C[i][x] <<" ";
      }
    cout <<endl;
  }
  for (int x=0; x<sizex; x++){ //impresion de matriz transpuesta 2
    for (int i=0; i<sizey; i++){
          cout << D[i][x] <<" ";
      }
    cout <<endl;
  }
}

void Fullcalc::Vectorial() //función menú de la calculadora vectorial
{
  int x1=0,x2=0,y1=0,y2=0,s,z1=0,z2=0;
  Vectoriales calculadora; //creacion de objeto en clase vectorial

  cout<< "1.SISTEMA 2X2"
		<< "\n2.DISTANCIA 2 PUNTOS"
		<< "\n3.MAGNITUD VECTOR"
		<< "\n4.SUMA DE VECTORES"
		<< "\n0.SALIR"
		<< "\n";

		do {
		cout << "\nINGRESE SU OPERACION ";
		cin >> s;

		switch (s) {
		case 1: // SISTEMA 2*2
			calculadora.setx(x1,x2); //captura de informacion
      calculadora.sety(y1,y2);//captura de informacion
      calculadora.setz(z1,z2);//captura de informacion
      cout<<"LA SOLUCION AL SISTEMA 2X2 ES:"<<endl;
      calculadora.ecuaciones();
			break;
		case 2: // DISTANCIA ENTRE PUNTOS
			calculadora.setx(x1,x2);//captura de informacion
      calculadora.sety(y1,y2);//captura de informacion
			cout<<"LA DISTANCIA ENTRE DOS PUNTOS ES:"<<endl;
			calculadora.distancia();
			break;
		case 3: // MAGNITUD DE VECTOR
			calculadora.setx(x1,x2);//captura de informacion
      calculadora.sety(y1,y2);//captura de informacion
			cout<<"LA MAGNITUD DEL VECTOR ES:"<<endl;
			calculadora.mvector();
			break;
		case 4: // SUMA DE VECTORES
			calculadora.setx(x1,x2);//captura de informacion
      calculadora.sety(y1,y2);//captura de informacion
			cout<<"LA SUMA DE VECTORES ES:"<<endl;
			calculadora.sumavectores();
			break;
		case 0:
			cout << "SALIR" << endl;
			break;
		}

	} while (s>= 1 && s <= 4);

}

/*FUNCIONES PARA OBTENER DATOS*/

void Vectoriales::setx(int x1, int x2){
	cout<<"INGRESE VALOR DE X1"<<endl;//pide valor al usuario y lo guarda
	cin>>x1;
	x3 = x1;//asigna el valor a una nueva variable
	cout<<"INGRESE VALOR DE X2"<<endl;
	cin>>x2;
	x4 = x2;
}

void Vectoriales::sety (int y1, int y2){
	cout<<"INGRESE VALOR DE y1"<<endl;//pide valor al usuario y lo guarda
	cin>>y1;
	y3= y1;//asigna valor a una nueva variable
	cout<<"INGRESE VALOR DE y2"<<endl;
	cin>>y2;
	y4= y2;
}

void Vectoriales::setz (int z1, int z2){
	cout<<"INGRESE VALOR DE RESULTADO EC1"<<endl;//pide valor al usuario y lo guarda
	cin>>z1;
	z3  = z3;//asigna valor a una nueva variable
	cout<<"INGRESE VALOR DE RESULTADO EC2"<<endl;
	cin>>z2;
	z4  = z2;//resultado
}

int Vectoriales::getx(){//regresa el valor de las nuevas variables
	return x3;
	return x4;
}

int Vectoriales::gety(){//regresa el valor de las nuevas variables
	return y3;
	return y4;
}

int Vectoriales::getz(){//Regresa el valor de las nuevas variables
	return z3;
	return z4;
}

/* OPERADORES */

void Vectoriales::ecuaciones(){
float y,x,z,xr,yr,zr;//eSolucion de ecuaciones 2x2 por m�toddo de eliminacion
x=-x3*x4;
y=-x4*x3;
z=-x4*x3;

xr=x3*x4;
yr=x3*y4;
zr=x3*z4;

x=x+xr;
y=y+yr;
z=z+zr;
y=z/y;

z=z3-y*y3;
x=z/x3;

cout<<"VALOR DE Y ES:"<<y<<"VALOR DE X ES:"<<x;
}

void Vectoriales::distancia(){//distancia entre puntos por formula
   float a,b,c;
   a = (x4 - x3)*(x4 - x3);
   b = (y4 - y3)*(y4- y3);
   c= sqrt(a+b);
   cout<<"LA DISTANCIA ENTRE PUNTOS ES:"<<c<<endl;

}

void Vectoriales::mvector(){//magnitud vector por formula
   cout<<"COLOCAR VALORES DE X2,Y2=0"<<endl;
   float a,b,c;
   a = x3;
   b = y3;
   c= sqrt((a*a)+(b*b));
   cout<<"LA MAGNITUD DEL VECTOR ES:"<<c<<endl;
}

void Vectoriales::sumavectores(){//suma de vectores por formula
   float a,b;
   a = x3 + x4;
   b = y3 + y4;
   cout<<"VALOR DE X ES:"<<a<<"EL VALOR DE Y ES:"<<b;
}

void Fullcalc::Estadisticas() //función menú de la calculadora estadistica
{
  int menu = 0, n = 0;
  Estadistica calculadora; //creacion de objeto en clase estadistica

  cout << "1.MEDIA"
		<< "\n2.MODA"
		<< "\n3.MEDIANA"
		<< "\n0.SALIR"
		<< "\n" <<endl;

    do {
    		cout << "\nINGRESE SU OPERACION ";
    		cin >> menu;

    		switch (menu) {
      		case 1: // MEDIA
            cout << "numero de digitos: "<<endl;
            cin >> n;
            calculadora.setData(n); //captura de datos
      			cout << "RESULTADO: " << calculadora.media(n) << endl;
      			break;
      		case 2: // MODA
            cout << "numero de digitos: "<<endl;
            cin >> n;
            calculadora.setData(n); //captura de datos
      			cout << "RESULTADO: " << calculadora.moda(n) << endl;
      			break;
      		case 3: // MEDIANA
            cout << "numero de digitos: "<<endl;
            cin >> n;
            calculadora.setData(n); //captura de datos
      			cout << "RESULTADO: " << calculadora.mediana(n) << endl;
      			break;
    		}

    	} while (menu>= 1 && menu <= 3);
}

/*FUNCIONES PARA OBTENER DATOS*/

void Estadistica::setData(int i)
{
  for (int x = 0; x<i; x++){ //LLENADO DE MATRIZ
    cout << "digito " << x << ":"<<endl;
    cin >> A[x];
  }
}

/* OPERADORES */

double Estadistica::media(int i) // tamaño
{
  int result = 0;
  for (int x = 0; x<i; x++){ // SUMA DE TODOS LOS DATOS
    result += A[x];
  }
  return result / i; // DIVISION PARA OBTENER PROMEDIO
}

double Estadistica::moda(int i) // tamaño
{

  sort(A, A+i); // funcion para ordenar la matriz
  int temp = A[0]; // primer valor de la moda
  int moda = temp, contador1 = 1, contador2 = 1;

  for (int x = 1; x<i; x++){

    if (A[x] == temp){ // si el valor del ciclo es igual a la moda original
      contador1++; //sumar uno a contador
    } else{ // si no es igual

      if (contador1 > contador2){ // contador es mas grande que contador 2
        contador2 = contador1; // cambio de valor
        moda = temp; // moda es igual al ultimo valor en temp
      }
      contador1 = 1; // reseteo de contador 1
      temp = A[x]; // temporal es igual a nuevo valor del arreglo
    }
  }

    return moda;
}

double Estadistica::mediana(int i) // tamaño
{

  double mediana = 0;
  sort(A, A + i); // funcion para ordenar matriz

  if (i%2 == 0){ // si es par
    mediana = (A[(i/2)-1] + A[i/2])/2; // se toman los dos valores de en medio y se promedia
  } else { // si es impar
    mediana = A[(i/2)]; // se toma el valor de la mitad
  }

  return mediana;

}
