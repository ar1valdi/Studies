<<<<<<< HEAD
#include <iostream>
#include "Prostokat.h"
#include "Trojkat.h"
#include "Kolo.h"
#include "Prostopadl.h"
using namespace std;

void pokazVirtual() {
	FiguraPlaska* wskazniki[6];
	wskazniki[0] = new Trojkat(1, 2, 3);
	wskazniki[1] = new Trojkat(4, 5, 6);
	wskazniki[2] = new Prostokat(7, 8);
	wskazniki[3] = new Prostokat(9, 10);
	wskazniki[4] = new Kolo(11);
	wskazniki[5] = new Kolo(12);

	for (int i = 0; i < 6; i++) {
		cout << "Figura nr " << i << ":\n";
		cout << "Obwod: " << wskazniki[i]->Obwod() << endl;
		cout << "Pole: " << wskazniki[i]->Pole() << endl;
	}

	for (int i = 0; i < 6; i++) {
		delete wskazniki[i];
	}
}

double poleOverload(double a, double b) {
	cout << "(funckja z double)";
	return a * b;
}

int poleOverload(int a, int b) {
	cout << "(funckja z int)";
	return a * b;
}

int main() {
	//konstrutkory
	cout << "---Konstruktory---" << endl;
	Prostokat p1(3,4);
	Trojkat t1(3, 4, 5);
	Kolo k1(3);

	Prostokat* p2 = new Prostokat(6, 7);
	Trojkat* t2 = new Trojkat(6, 7, 8);
	Kolo* k2 = new Kolo(6);

	//funkcje set
	cout << endl << endl << "---Funkcje Set (dzialaja bez wypisywania)---" << endl;
	p1.SetA(10);
	p1.SetB(10);
	p2->SetA(12);
	p2->SetB(12);
	t1.SetA(10);
	t1.SetB(11);
	t1.SetC(12);
	t2->SetA(13);
	t2->SetB(14);
	t2->SetC(15);
	k1.SetR(1);
	k2->SetR(2);

	//funkcje get
	cout << endl << endl << "---Funkcje Get---" << endl;
	cout << "p1: " << p1.GetA() << " " << p1.GetB() << endl;
	cout << "p2: " << p2->GetA() << " " << p2->GetB() << endl;
	cout << "t1: " << t1.GetA() << " " << t1.GetB() << " " << t1.GetC() << endl;
	cout << "t2: " << t2->GetA() << " " << t2->GetB() << " " << t2->GetC() << endl;
	cout << "k1: " << k1.GetR() << endl;
	cout << "k2: " << k2->GetR() << endl;

	//obwody
	cout << endl << endl << "---Obwody---" << endl;
	cout << "p1: " << p1.Obwod() << endl;
	cout << "p2: " << p2->Obwod() << endl;
	cout << "t1: " << t1.Obwod() << endl;
	cout << "t2: " << t2->Obwod() << endl;
	cout << "k1: " << k1.Obwod() << endl;
	cout << "k2: " << k2->Obwod() << endl;

	//pola
	cout << endl << endl << "---Pola---" << endl;
	cout << "p1: " << p1.Pole() << endl;
	cout << "p2: " << p2->Pole() << endl;
	cout << "t1: " << t1.Pole() << endl;
	cout << "t2: " << t2->Pole() << endl;
	cout << "k1: " << k1.Pole() << endl;
	cout << "k2: " << k2->Pole() << endl;

	//virtual
	cout << endl << endl << "---Virtual---" << endl;
	pokazVirtual();

	//roznice
	cout << endl << endl << "---Roznice overload override---" << endl;
	cout << "1. override:\n";
	cout << "Funkcja pole wywolana dla trzech roznych obiektow:\n";
	cout << p1.Pole() << " " << t1.Pole() << " " << k1.Pole() << endl;
	cout << "Funkcja poleOverload wywolana dla roznych argumentow (1 - double, 2 - int):\n";
	cout << poleOverload(5.5, 6.5) << " ";
	cout << poleOverload(5, 6);

	//demo prostopadl
	cout << endl << endl << "---Demo prostopadl---" << endl;
	Prostopadl pr1(2,3,4);
	Prostopadl* pr2 = new Prostopadl(5, 6, 7);
	cout << pr1.PoleCal() << " " << pr1.PoleBocz() << " " << pr1.Objetosc() << endl;
	cout << pr2->PoleCal() << " " << pr2->PoleBocz() << " " << pr2->Objetosc() << endl;
	delete pr2;

	//destruktory
		//obiekty stworzone lokalnie usuna sie same 
		//pod koniec dzialania programu
	cout << endl << endl << "---Destruktory---" << endl;
	delete p2;
	delete t2;
	delete k2;
=======
#include <iostream>
#include "Prostokat.h"
#include "Trojkat.h"
#include "Kolo.h"
#include "Prostopadl.h"
using namespace std;

void pokazVirtual() {
	FiguraPlaska* wskazniki[6];
	wskazniki[0] = new Trojkat(1, 2, 3);
	wskazniki[1] = new Trojkat(4, 5, 6);
	wskazniki[2] = new Prostokat(7, 8);
	wskazniki[3] = new Prostokat(9, 10);
	wskazniki[4] = new Kolo(11);
	wskazniki[5] = new Kolo(12);

	for (int i = 0; i < 6; i++) {
		cout << "Figura nr " << i << ":\n";
		cout << "Obwod: " << wskazniki[i]->Obwod() << endl;
		cout << "Pole: " << wskazniki[i]->Pole() << endl;
	}

	for (int i = 0; i < 6; i++) {
		delete wskazniki[i];
	}
}

double poleOverload(double a, double b) {
	cout << "(funckja z double)";
	return a * b;
}

int poleOverload(int a, int b) {
	cout << "(funckja z int)";
	return a * b;
}

int main() {
	//konstrutkory
	cout << "---Konstruktory---" << endl;
	Prostokat p1(3,4);
	Trojkat t1(3, 4, 5);
	Kolo k1(3);

	Prostokat* p2 = new Prostokat(6, 7);
	Trojkat* t2 = new Trojkat(6, 7, 8);
	Kolo* k2 = new Kolo(6);

	//funkcje set
	cout << endl << endl << "---Funkcje Set (dzialaja bez wypisywania)---" << endl;
	p1.SetA(10);
	p1.SetB(10);
	p2->SetA(12);
	p2->SetB(12);
	t1.SetA(10);
	t1.SetB(11);
	t1.SetC(12);
	t2->SetA(13);
	t2->SetB(14);
	t2->SetC(15);
	k1.SetR(1);
	k2->SetR(2);

	//funkcje get
	cout << endl << endl << "---Funkcje Get---" << endl;
	cout << "p1: " << p1.GetA() << " " << p1.GetB() << endl;
	cout << "p2: " << p2->GetA() << " " << p2->GetB() << endl;
	cout << "t1: " << t1.GetA() << " " << t1.GetB() << " " << t1.GetC() << endl;
	cout << "t2: " << t2->GetA() << " " << t2->GetB() << " " << t2->GetC() << endl;
	cout << "k1: " << k1.GetR() << endl;
	cout << "k2: " << k2->GetR() << endl;

	//obwody
	cout << endl << endl << "---Obwody---" << endl;
	cout << "p1: " << p1.Obwod() << endl;
	cout << "p2: " << p2->Obwod() << endl;
	cout << "t1: " << t1.Obwod() << endl;
	cout << "t2: " << t2->Obwod() << endl;
	cout << "k1: " << k1.Obwod() << endl;
	cout << "k2: " << k2->Obwod() << endl;

	//pola
	cout << endl << endl << "---Pola---" << endl;
	cout << "p1: " << p1.Pole() << endl;
	cout << "p2: " << p2->Pole() << endl;
	cout << "t1: " << t1.Pole() << endl;
	cout << "t2: " << t2->Pole() << endl;
	cout << "k1: " << k1.Pole() << endl;
	cout << "k2: " << k2->Pole() << endl;

	//virtual
	cout << endl << endl << "---Virtual---" << endl;
	pokazVirtual();

	//roznice
	cout << endl << endl << "---Roznice overload override---" << endl;
	cout << "1. override:\n";
	cout << "Funkcja pole wywolana dla trzech roznych obiektow:\n";
	cout << p1.Pole() << " " << t1.Pole() << " " << k1.Pole() << endl;
	cout << "Funkcja poleOverload wywolana dla roznych argumentow (1 - double, 2 - int):\n";
	cout << poleOverload(5.5, 6.5) << " ";
	cout << poleOverload(5, 6);

	//demo prostopadl
	cout << endl << endl << "---Demo prostopadl---" << endl;
	Prostopadl pr1(2,3,4);
	Prostopadl* pr2 = new Prostopadl(5, 6, 7);
	cout << pr1.PoleCal() << " " << pr1.PoleBocz() << " " << pr1.Objetosc() << endl;
	cout << pr2->PoleCal() << " " << pr2->PoleBocz() << " " << pr2->Objetosc() << endl;
	delete pr2;

	//destruktory
		//obiekty stworzone lokalnie usuna sie same 
		//pod koniec dzialania programu
	cout << endl << endl << "---Destruktory---" << endl;
	delete p2;
	delete t2;
	delete k2;
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}