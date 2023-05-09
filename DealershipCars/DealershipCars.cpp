#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<list>
#include <vector>
#include <sstream>
using namespace std;

class IFile
{
	virtual void writeToFile(fstream& f) = 0;//metode virtuale pure
	virtual void readFromFile(fstream& f) = 0;
};

class Masina : public IFile {
	const int id;
	static int contor;
	char* culoare;
	string marca;
	float pret;
	int AnFabricatie;
	string motor;
	int NrDetinatoriAnteriori;
	string* NumeDetinatori;


public:
	Masina() :id(contor++)
	{
		this->culoare = new char[strlen("Necunoscut") + 1];
		strcpy(this->culoare, "Necunoscut");
		this->marca = " ";
		this->pret = 0;
		this->AnFabricatie = NULL;
		this->motor = " ";
		this->NrDetinatoriAnteriori = 0;
		this->NumeDetinatori = NULL;

	}
	Masina(string marca) :id(contor++)
	{
		this->culoare = new char[strlen("Necunoscut") + 1];
		strcpy(this->culoare, "Necunoscut");
		this->marca = marca;
		this->pret = 0;
		this->AnFabricatie = NULL;
		this->motor = " ";
		this->NrDetinatoriAnteriori = 0;
		this->NumeDetinatori = NULL;

	}
	Masina(char* culoare, string marca, float pret, int AnFabricatie, string motor, int NrDetinatoriAnteriori, string* NumeDetinatori) :id(contor++)
	{
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
		this->marca = marca;
		this->pret = pret;
		this->AnFabricatie = AnFabricatie;
		this->motor = motor;
		this->NrDetinatoriAnteriori = NrDetinatoriAnteriori;
		this->NumeDetinatori = new string[this->NrDetinatoriAnteriori];
		for (int i = 0; i < this->NrDetinatoriAnteriori; i++)
			this->NumeDetinatori[i] = NumeDetinatori[i];


	}
	char* getCuloare()
	{
		return this->culoare;
	}
	string getMarca()
	{
		return this->marca;
	}
	float getPret()
	{
		return this->pret;
	}
	int getAnFabricatie() {
		return this->AnFabricatie;
	}
	string getMotor() {
		return this->motor;
	}
	int getNrDetinatoriAnteriori() {
		return this->NrDetinatoriAnteriori;
	}
	string* getNumeDetinatori() {
		return this->NumeDetinatori;
	}

	void setCuloare(char* culoare)
	{
		if (this->culoare != NULL)
		{
			delete[]this->culoare;
		}
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
	}
	void setMarca(string marca) {
		this->marca = marca;
	}
	void setPret(float pret) {
		if (pret > 0)
			this->pret = pret;
		else
			this->pret = 0;
	}
	void setAnFabricatie(int AnFabricatie) {
		if (AnFabricatie > 1000 && AnFabricatie <= 2021)
			this->AnFabricatie = AnFabricatie;
		else
			this->AnFabricatie = 0;
	}
	void setMotor(string motor) {
		this->motor = motor;
	}
	void setNrDetinatoriAnteriori(int NrDetinatoriAnteriori) {
		if (NrDetinatoriAnteriori >= 0)
			this->NrDetinatoriAnteriori = NrDetinatoriAnteriori;
		else
			this->NrDetinatoriAnteriori = 0;
	}

	void setNumeDetinatori(int nrDetinatoriNoi, string* NumeDetinatoriNoi)
	{
		if (this->NumeDetinatori != NULL)
		{
			delete[]this->NumeDetinatori;
		}
		this->NrDetinatoriAnteriori = nrDetinatoriNoi;
		this->NumeDetinatori = new string[this->NrDetinatoriAnteriori];
		for (int i = 0; i < this->NrDetinatoriAnteriori; i++)
		{
			this->NumeDetinatori[i] = NumeDetinatoriNoi[i];
		}
	}
	Masina(const Masina& m) :id(contor++)
	{
		this->culoare = new char[strlen(m.culoare) + 1];
		strcpy(this->culoare, m.culoare);
		this->marca = m.marca;
		this->pret = m.pret;
		this->AnFabricatie = m.AnFabricatie;
		this->motor = m.motor;
		this->NrDetinatoriAnteriori = m.NrDetinatoriAnteriori;
		this->NumeDetinatori = new string[this->NrDetinatoriAnteriori];
		for (int i = 0; i < this->NrDetinatoriAnteriori; i++)
			this->NumeDetinatori[i] = m.NumeDetinatori[i];
	}
	Masina& operator =(const Masina& m)
	{
		if (this != &m)
		{
			if (this->culoare != NULL)
			{
				delete[]this->culoare;
			}
			if (this->NumeDetinatori != NULL)
			{
				delete[]this->NumeDetinatori;
			}
			this->culoare = new char[strlen(m.culoare) + 1];
			strcpy(this->culoare, m.culoare);
			this->marca = m.marca;
			this->pret = m.pret;
			this->AnFabricatie = m.AnFabricatie;
			this->motor = m.motor;
			this->NrDetinatoriAnteriori = m.NrDetinatoriAnteriori;
			this->NumeDetinatori = new string[this->NrDetinatoriAnteriori];
			for (int i = 0; i < this->NrDetinatoriAnteriori; i++)
				this->NumeDetinatori[i] = m.NumeDetinatori[i];
			return *this;
		}
	}

	string& operator[](int index)
	{
		if (index >= 0 && index < this->NrDetinatoriAnteriori)
		{
			return this->NumeDetinatori[index];
		}
		else
		{
			throw new exception("Eroare: nu e buna acea valoare!");
		}
	}

	Masina operator+(float x)
	{
		Masina rez = *this;
		rez.pret += x;

		return rez;
	}


	Masina operator++()
	{
		this->pret++;
		return *this;
	}

	Masina operator++(int)
	{

		Masina rez = *this;
		this->pret++;
		return rez;
	}

	explicit operator string()
	{
		return this->marca;
	}
	Masina& operator!()
	{
		delete[]this->NumeDetinatori;
		this->NumeDetinatori = NULL;
		this->NrDetinatoriAnteriori = 0;
		return *this;

	}

	bool operator >(const Masina& M)
	{
		return this->pret > M.pret;
	}


	bool operator==(const Masina& M)
	{
		return this->culoare == M.culoare;
	}

	~Masina()
	{
		if (this->culoare != NULL)
		{
			delete[]this->culoare;
		}
		if (this->NumeDetinatori != NULL)
		{
			delete[]this->NumeDetinatori;
		}

	}
	void writeToFile(fstream& f)
	{
		int lg = strlen(this->culoare) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->culoare, lg);
		lg = 0;
		lg = this->marca.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->marca.data(), lg);
		f.write((char*)&this->pret, sizeof(float));
		f.write((char*)&this->AnFabricatie, sizeof(int));
		lg = this->motor.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->motor.data(), lg);
		f.write((char*)&this->NrDetinatoriAnteriori, sizeof(int));
		for (int i = 0; i < this->NrDetinatoriAnteriori; i++) {
			lg = this->NumeDetinatori[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->NumeDetinatori[i].data(), lg);
		}
	}
	void readFromFile(fstream& f)
	{
		int lg = 0;
		delete[] this->culoare;
		f.read((char*)&lg, sizeof(int));
		this->culoare = new char[lg];
		f.read(this->culoare, lg);
		lg = 0;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->marca = buffer;
		delete[] buffer;
		f.read((char*)&this->pret, sizeof(float));
		f.read((char*)&this->AnFabricatie, sizeof(int));
		f.read((char*)&lg, sizeof(int));
		char* buffer2 = new char[lg];
		f.read(buffer2, lg);
		this->motor = buffer2;
		delete[] buffer2;
		f.read((char*)&this->NrDetinatoriAnteriori, sizeof(int));
		if (this->NrDetinatoriAnteriori > 0)
		{
			this->NumeDetinatori = new string[this->NrDetinatoriAnteriori];
			for (int i = 0; i < this->NrDetinatoriAnteriori; i++) {
				lg = 0;
				f.read((char*)&lg, sizeof(int));
				char* buffer = new char[lg];
				//citire sir de caractere
				f.read(buffer, lg);
				this->NumeDetinatori[i] = buffer;
				delete[] buffer;
			}

		}
		else
		{
			this->NrDetinatoriAnteriori = 0;
			this->NumeDetinatori = NULL;
		}

	}
	friend istream& operator>>(istream& in, Masina& M);
	friend ostream& operator<<(ostream& out, const Masina& M);
	friend ofstream& operator<<(ofstream& out, const Masina& M);
	friend ifstream& operator>>(ifstream& in, Masina& M);
};
int Masina::contor = 1;
ifstream& operator>>(ifstream& in, Masina& M)
{

	in >> M.marca;

	if (M.culoare != NULL)
	{
		delete[]M.culoare;
	}
	in >> ws;
	char aux[250];
	in.getline(aux, 249);
	M.culoare = new char[strlen(aux) + 1];
	strcpy(M.culoare, aux);

	in >> M.pret;

	in >> M.AnFabricatie;

	in >> M.motor;

	in >> M.NrDetinatoriAnteriori;
	if (M.NumeDetinatori != NULL)
	{
		delete[]M.NumeDetinatori;
	}
	if (M.NrDetinatoriAnteriori > 0)
	{
		M.NumeDetinatori = new string[M.NrDetinatoriAnteriori];

		for (int i = 0; i < M.NrDetinatoriAnteriori; i++)
			in >> M.NumeDetinatori[i];
	}
	else
		M.NumeDetinatori = NULL;
	return in;
}

//ofstream& operator<<(ofstream& out, const Masina& M)
//{
//	out << M.culoare << M.id   << M.pret << M.AnFabricatie <<  M.motor <<  M.NrDetinatoriAnteriori << endl;
//	out <<  endl;
//	if (M.NumeDetinatori != NULL)
//		for (int i = 0; i < M.NrDetinatoriAnteriori; i++)
//			out << M.NumeDetinatori[i] << " ";
//	
//	out << endl;
//	return out;
//}
istream& operator>>(istream& in, Masina& M)
{
	cout << "Introduceti numele marcii: ";
	in >> M.marca;
	cout << "Introduceti culoarea masinii: ";
	if (M.culoare != NULL)
	{
		delete[]M.culoare;
	}
	in >> ws;
	char aux[250];
	in.getline(aux, 249);
	M.culoare = new char[strlen(aux) + 1];
	strcpy(M.culoare, aux);
	cout << "Introduceti pretul masinii: ";
	in >> M.pret;
	cout << "Introduceti anul fabricatiei: ";
	in >> M.AnFabricatie;
	cout << "Introduceti motorul masinii: ";
	in >> M.motor;
	cout << "Introduceti numarul de detinatori anteriori: ";
	in >> M.NrDetinatoriAnteriori;
	if (M.NumeDetinatori != NULL)
	{
		delete[]M.NumeDetinatori;
	}
	if (M.NrDetinatoriAnteriori > 0)
	{
		M.NumeDetinatori = new string[M.NrDetinatoriAnteriori];
		cout << "Introduceti numele pentru fiecare detinator: ";
		for (int i = 0; i < M.NrDetinatoriAnteriori; i++)
			in >> M.NumeDetinatori[i];
	}
	else
		M.NumeDetinatori = NULL;
	return in;
}
ostream& operator<<(ostream& out, const Masina& M)
{
	out << "Masina cu culoarea: " << M.culoare << " cu id: " << M.id << " ,cu marca: " << M.marca << " ,pretul: " << M.pret << " ,cu anul fabricatiei: " << M.AnFabricatie << " ,cu motor" << M.motor << " ,cu nr detinatori anteriori:" << M.NrDetinatoriAnteriori << endl;
	out << "Numele fiecarui detinator:" << endl;
	if (M.NumeDetinatori != NULL)
		for (int i = 0; i < M.NrDetinatoriAnteriori; i++)
			out << M.NumeDetinatori[i] << " ";
	else out << "Nu se cunoaste numele detinatorilor";
	out << endl;
	return out;
}

class StocDealership : public IFile
{
	const int id;
	static int contor;
	char* nume;
	string locatie;
	int nrMasini;
	Masina* listaMasini;
	string* numeMasini;
	float* preturiMasini;
public:
	StocDealership() :id(contor++)
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->locatie = "Necunoscut";
		this->nrMasini = 0;
		this->numeMasini = NULL;
		this->preturiMasini = NULL;
		this->numeMasini = NULL;

	}
	StocDealership(string locatie) :id(contor++)
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->locatie = locatie;
		this->nrMasini = 0;
		this->numeMasini = NULL;
		this->preturiMasini = NULL;
		this->numeMasini = NULL;

	}
	StocDealership(char* nume, string locatie, int nrMasini, string* numeMasini, float* preturiMasini, Masina* listaMasini) :id(contor++)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->locatie = locatie;
		this->nrMasini = nrMasini;
		this->numeMasini = new string[this->nrMasini];
		this->preturiMasini = new float[this->nrMasini];
		this->listaMasini = new Masina[this->nrMasini];
		for (int i = 0; i < this->nrMasini; i++) {
			this->numeMasini[i] = numeMasini[i];
			this->preturiMasini[i] = preturiMasini[i];
			this->listaMasini[i] = listaMasini[i];
		}

	}
	char* getNume()
	{
		return this->nume;
	}
	string getLocatie()
	{
		return this->locatie;
	}
	int getNrMasini()
	{
		return this->nrMasini;
	}
	string* getNumeMasini()
	{
		return this->numeMasini;
	}
	float* getpreturiMasini() {
		return this->preturiMasini;
	}
	void setNume(char* nume)
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	void setLocatie(string locatie) {
		this->locatie = locatie;
	}
	void setNrMasini(int nrMasini) {
		if (nrMasini > 3)
			this->nrMasini = nrMasini;
		else
			this->nrMasini = 0;
	}
	void setPreturiMasini(int nrMasininoi, float* preturimasiniNoi)
	{
		if (this->preturiMasini != NULL)
		{
			delete[]this->preturiMasini;
		}
		this->nrMasini = nrMasininoi;
		this->preturiMasini = new float[this->nrMasini];
		for (int i = 0; i < this->nrMasini; i++)
		{
			this->preturiMasini[i] = preturimasiniNoi[i];
		}
	}
	void setNumeMasini(int nrMasininoi, string* NumeMasiniNoi)
	{
		if (this->numeMasini != NULL)
		{
			delete[]this->numeMasini;
		}
		this->nrMasini = nrMasininoi;
		this->numeMasini = new string[this->nrMasini];
		for (int i = 0; i < this->nrMasini; i++)
		{
			this->numeMasini[i] = NumeMasiniNoi[i];
		}
	}
	StocDealership(const StocDealership& s) :id(contor++)
	{
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
		this->locatie = s.locatie;
		this->nrMasini = s.nrMasini;
		this->numeMasini = new string[this->nrMasini];
		this->preturiMasini = new float[this->nrMasini];
		this->listaMasini = new Masina[this->nrMasini];
		for (int i = 0; i < this->nrMasini; i++) {
			this->numeMasini[i] = s.numeMasini[i];
			this->preturiMasini[i] = s.preturiMasini[i];
			this->listaMasini[i] = s.listaMasini[i];
		}
	}
	StocDealership& operator =(const StocDealership& s)
	{
		if (this != &s)
		{
			if (this->nume != NULL)
			{
				delete[]this->nume;
			}
			if (this->numeMasini != NULL)
			{
				delete[]this->numeMasini;
			}
			if (this->preturiMasini != NULL)
			{
				delete[]this->preturiMasini;
			}
			if (this->listaMasini != NULL) {
				delete[]this->listaMasini;
			}
			this->nume = new char[strlen(s.nume) + 1];
			strcpy(this->nume, s.nume);
			this->locatie = s.locatie;
			this->nrMasini = s.nrMasini;
			this->numeMasini = new string[this->nrMasini];
			this->preturiMasini = new float[this->nrMasini];
			this->listaMasini = new Masina[this->nrMasini];
			for (int i = 0; i < this->nrMasini; i++) {
				this->numeMasini[i] = s.numeMasini[i];
				this->preturiMasini[i] = s.preturiMasini[i];
				this->listaMasini[i] = s.listaMasini[i];
			}
			return *this;
		}
	}

	string& operator[](int index)
	{
		if (index >= 0 && index < this->nrMasini)
		{
			return this->numeMasini[index];
		}
		else
		{
			throw new exception("Eroare: nu e buna acea valoare!");
		}
	}
	StocDealership operator*(float x)
	{
		StocDealership rez = *this;
		for (int i = 0; i < rez.nrMasini; i++)
			rez.preturiMasini[i] *= x;
		return rez;
	}


	StocDealership& operator++()
	{
		for (int i = 0; i < this->nrMasini; i++)
		{
			++this->preturiMasini[i];
		}
		return *this;
	}

	StocDealership operator++(int)
	{
		StocDealership copie = *this;
		for (int i = 0; i < this->nrMasini; i++)
		{
			this->preturiMasini[i]++;
		}
		return copie;
	}

	explicit operator string()
	{
		return this->locatie;
	}
	StocDealership& operator!()
	{
		delete[]this->numeMasini;
		this->numeMasini = NULL;
		this->nrMasini = 0;
		return *this;

	}
	bool operator <(const StocDealership& S)
	{
		return this->nrMasini < S.nrMasini;
	}


	bool operator==(const StocDealership& s)
	{
		return (this->locatie == s.locatie && this->nrMasini == s.nrMasini);
	}

	~StocDealership()
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		if (this->numeMasini != NULL)
		{
			delete[]this->numeMasini;
		}
		if (this->preturiMasini != NULL)
		{
			delete[]this->preturiMasini;
		}
		if (this->listaMasini != NULL) {
			delete[]this->listaMasini;
		}
	}
	friend istream& operator>>(istream& in, StocDealership& S);
	friend ostream& operator<<(ostream& out, const StocDealership& S);
	friend ofstream& operator<<(ofstream& out, const StocDealership& S);
	friend ifstream& operator>>(ifstream& in, StocDealership& S);
	void writeToFile(fstream& f)
	{
		int lg = strlen(this->nume) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume, lg);
		lg = 0;
		lg = this->locatie.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->locatie.data(), lg);
		f.write((char*)&this->nrMasini, sizeof(int));
		for (int i = 0; i < this->nrMasini; i++)
			f.write((char*)&this->preturiMasini[i], sizeof(float));
		for (int i = 0; i < this->nrMasini; i++) {
			lg = this->numeMasini[i].length() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->numeMasini[i].data(), lg);
		}
	}
	void readFromFile(fstream& f)
	{
		int lg = 0;
		delete[] this->nume;
		f.read((char*)&lg, sizeof(int));
		this->nume = new char[lg];
		f.read(this->nume, lg);
		lg = 0;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		//citire sir de caractere
		f.read(buffer, lg);
		this->locatie = buffer;
		delete[] buffer;
		f.read((char*)&this->nrMasini, sizeof(int));
		if (this->nrMasini > 0)
		{
			this->preturiMasini = new float[this->nrMasini];
			for (int i = 0; i < this->nrMasini; i++)
				f.read((char*)&this->preturiMasini[i], sizeof(float));
		}
		else
		{
			this->nrMasini = 0;
			this->preturiMasini = NULL;
		}
		if (this->nrMasini > 0)
		{
			this->numeMasini = new string[this->nrMasini];
			for (int i = 0; i < this->nrMasini; i++) {
				lg = 0;
				f.read((char*)&lg, sizeof(int));
				char* buffer = new char[lg];
				//citire sir de caractere
				f.read(buffer, lg);
				this->numeMasini[i] = buffer;
				delete[] buffer;
			}

		}
		else
		{
			this->nrMasini = 0;
			this->preturiMasini = NULL;
		}
	}

};

int StocDealership::contor = 1;
ifstream& operator>>(ifstream& in, StocDealership& S)
{

	in >> S.locatie;

	if (S.nume != NULL)
	{
		delete[]S.nume;
	}
	in >> ws;
	char aux[250];
	in.getline(aux, 249);
	S.nume = new char[strlen(aux) + 1];
	strcpy(S.nume, aux);

	in >> S.nrMasini;
	if (S.numeMasini != NULL)
	{
		delete[]S.numeMasini;
	}
	if (S.preturiMasini != NULL)
	{
		delete[]S.preturiMasini;
	}
	if (S.nrMasini > 0)
	{
		S.numeMasini = new string[S.nrMasini];

		for (int i = 0; i < S.nrMasini; i++)
			in >> S.numeMasini[i];
	}
	else
		S.numeMasini = NULL;
	if (S.nrMasini > 0)
	{
		S.preturiMasini = new float[S.nrMasini];

		for (int i = 0; i < S.nrMasini; i++)
			in >> S.preturiMasini[i];
	}
	else
		S.preturiMasini = NULL;

	return in;
}
//ofstream& operator<<(ofstream& out, const StocDealership& S)
//{
//	out << S.nume<< endl;
//	out << S.locatie << endl;
//	out << S.nrMasini << endl;
//	for (int i = 0; i < S.nrMasini; i++)
//		out << S.preturiMasini[i] << " ";
//	for (int i = 0; i < S.nrMasini; i++)
//		out << S.numeMasini[i] << " ";
//	return out;
//}

istream& operator>>(istream& in, StocDealership& S)
{
	cout << "Introduceti locatia dealership-ului: ";
	in >> S.locatie;
	cout << "Introduceti numele dealership-ului: ";
	if (S.nume != NULL)
	{
		delete[]S.nume;
	}
	in >> ws;
	char aux[250];
	in.getline(aux, 249);
	S.nume = new char[strlen(aux) + 1];
	strcpy(S.nume, aux);
	cout << "Introduceti numarul de masini de pe stoc: ";
	in >> S.nrMasini;
	if (S.numeMasini != NULL)
	{
		delete[]S.numeMasini;
	}
	if (S.preturiMasini != NULL)
	{
		delete[]S.preturiMasini;
	}
	if (S.nrMasini > 0)
	{
		S.numeMasini = new string[S.nrMasini];
		cout << "Introduceti numele pentru fiecare masina: ";
		for (int i = 0; i < S.nrMasini; i++)
			in >> S.numeMasini[i];
	}
	else
		S.numeMasini = NULL;
	if (S.nrMasini > 0)
	{
		S.preturiMasini = new float[S.nrMasini];
		cout << "Introduceti pretul pentru fiecare masina: ";
		for (int i = 0; i < S.nrMasini; i++)
			in >> S.preturiMasini[i];
	}
	else
		S.preturiMasini = NULL;

	return in;
}
ostream& operator<<(ostream& out, const StocDealership& S)
{
	out << "Dealership-ul cu numele: " << S.nume << " cu id: " << S.id << " ,cu locatia: " << S.locatie << " ,cu nr de masini: " << S.nrMasini << endl;
	out << "Numele fiecarei masini:" << endl;
	if (S.numeMasini != NULL)
		for (int i = 0; i < S.nrMasini; i++)
			out << S.numeMasini[i] << " ";
	else out << "Nu se cunoaste numele masinilor";
	out << "Pretul fiecarei masini:" << endl;
	if (S.preturiMasini != NULL)
		for (int i = 0; i < S.nrMasini; i++)
			out << S.preturiMasini[i] << " ";
	else out << "Nu se cunoaste pretul masinilor";
	if (S.listaMasini != NULL)
		for (int i = 0; i < S.nrMasini; i++)
			out << S.listaMasini[i] << " ";
	else out << "Nu se cunoaste pretul masinilor";

	out << endl;
	return out;
}


class PersManagementDealership {
protected:
	int salariu;
	const int id;
	static int contor;
	char* functie;
	int varsta;
	string nume;
	int NrFosteFunctii;
	string* NumeFunctii;
public:
	PersManagementDealership() :id(contor++)
	{
		this->functie = new char[strlen("Necunoscut") + 1];
		strcpy(this->functie, "Necunoscut");
		this->varsta = 0;
		this->nume = " ";
		this->salariu = 0;
		this->NrFosteFunctii = 0;
		this->NumeFunctii = NULL;

	}
	PersManagementDealership(string nume) :id(contor++)
	{
		this->functie = new char[strlen("Necunoscut") + 1];
		strcpy(this->functie, "Necunoscut");
		this->varsta = 0;
		this->salariu = 0;
		this->nume = nume;
		this->NrFosteFunctii = 0;
		this->NumeFunctii = NULL;
	}
	PersManagementDealership(char* functie, int varsta, int salariu, string nume, int nrFosteFunctii, string* NumeFunctii) :id(contor++)
	{
		this->functie = new char[strlen(functie) + 1];
		strcpy(this->functie, functie);
		this->varsta = varsta;
		this->salariu = salariu;
		this->nume = nume;
		this->NrFosteFunctii = nrFosteFunctii;
		this->NumeFunctii = new string[this->NrFosteFunctii];
		for (int i = 0; i < this->NrFosteFunctii; i++)
			this->NumeFunctii[i] = NumeFunctii[i];


	}
	char* getFunctie()
	{
		return this->functie;
	}
	int getVarsta() {
		return this->varsta;
	}
	string getnume()
	{
		return this->nume;
	}

	int getNrFosteFunctii() {
		return this->NrFosteFunctii;
	}

	string* getNumeFunctii() {
		return this->NumeFunctii;
	}

	void setFunctie(char* functie)
	{
		if (this->functie != NULL)
		{
			delete[]this->functie;
		}
		this->functie = new char[strlen(functie) + 1];
		strcpy(this->functie, functie);
	}
	void setVarsta(int varsta) {
		if (varsta >= 18)
			this->varsta = varsta;
		else
			this->varsta = 0;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setNrFosteFunctii(int NrFosteFunctii) {
		if (NrFosteFunctii >= 0)
			this->NrFosteFunctii = NrFosteFunctii;
		else
			this->NrFosteFunctii = 0;
	}

	void setNumeFunctii(int nrFosteFunctiiNoi, string* NumeFunctiiNoi)
	{
		if (this->NumeFunctii != NULL)
		{
			delete[]this->NumeFunctii;
		}
		this->NrFosteFunctii = nrFosteFunctiiNoi;
		this->NumeFunctii = new string[this->NrFosteFunctii];
		for (int i = 0; i < this->NrFosteFunctii; i++)
		{
			this->NumeFunctii[i] = NumeFunctiiNoi[i];
		}
	}
	PersManagementDealership(const PersManagementDealership& p) :id(contor++)
	{
		this->functie = new char[strlen(p.functie) + 1];
		strcpy(this->functie, p.functie);
		this->varsta = p.varsta;
		this->salariu = p.salariu;
		this->nume = p.nume;
		this->NrFosteFunctii = p.NrFosteFunctii;
		this->NumeFunctii = new string[this->NrFosteFunctii];
		for (int i = 0; i < this->NrFosteFunctii; i++)
			this->NumeFunctii[i] = p.NumeFunctii[i];
	}
	PersManagementDealership& operator =(const PersManagementDealership& p)
	{
		if (this != &p)
		{
			if (this->functie != NULL)
			{
				delete[]this->functie;
			}
			if (this->NumeFunctii != NULL)
			{
				delete[]this->NumeFunctii;
			}
			this->functie = new char[strlen(p.functie) + 1];
			strcpy(this->functie, p.functie);
			this->varsta = p.varsta;
			this->nume = p.nume;
			this->salariu = p.salariu;
			this->NrFosteFunctii = p.NrFosteFunctii;
			this->NumeFunctii = new string[this->NrFosteFunctii];
			for (int i = 0; i < this->NrFosteFunctii; i++)
				this->NumeFunctii[i] = p.NumeFunctii[i];
			return *this;
		}
	}
	string& operator[](int index)
	{
		if (index >= 0 && index < this->NrFosteFunctii)
		{
			return this->NumeFunctii[index];
		}
		else
		{
			throw new exception("Eroare: nu e buna acea valoare!");
		}
	}

	PersManagementDealership operator+(int x)
	{
		PersManagementDealership rez = *this;
		rez.varsta += x;

		return rez;
	}
	PersManagementDealership operator++()
	{
		this->varsta++;
		return *this;
	}

	PersManagementDealership operator++(int)
	{

		PersManagementDealership rez = *this;
		this->varsta++;
		return rez;
	}
	explicit operator string()
	{
		return this->functie;
	}
	PersManagementDealership& operator!()
	{
		delete[]this->NumeFunctii;
		this->NumeFunctii = NULL;
		this->NrFosteFunctii = 0;
		return *this;

	}
	virtual float calculSalariu()
	{
		return this->salariu;
	}
	bool operator <=(const PersManagementDealership& P)
	{
		return this->varsta <= P.varsta;
	}


	bool operator==(const PersManagementDealership& P)
	{
		return this->functie == P.functie;
	}
	~PersManagementDealership()
	{
		if (this->functie != NULL)
		{
			delete[]this->functie;
		}
		if (this->NumeFunctii != NULL)
		{
			delete[]this->NumeFunctii;
		}

	}
	friend istream& operator>>(istream& in, PersManagementDealership& P);
	friend ostream& operator<<(ostream& out, const PersManagementDealership& P);
};
int PersManagementDealership::contor = 1;
istream& operator>>(istream& in, PersManagementDealership& P)
{
	cout << "Introduceti numele persoanei: ";
	in >> P.nume;
	cout << "Introduceti functia ocupata: ";
	if (P.functie != NULL)
	{
		delete[]P.functie;
	}
	in >> ws;
	char aux[250];
	in.getline(aux, 249);
	P.functie = new char[strlen(aux) + 1];
	strcpy(P.functie, aux);
	cout << "Introduceti varsta: ";
	in >> P.varsta;
	cout << "Introduceti salariul: ";
	in >> P.salariu;
	cout << "Introduceti numarul de functii anterioare: ";
	in >> P.NrFosteFunctii;
	if (P.NumeFunctii != NULL)
	{
		delete[]P.NumeFunctii;
	}
	if (P.NrFosteFunctii > 0)
	{
		P.NumeFunctii = new string[P.NrFosteFunctii];
		cout << "Introduceti numele pentru fiecare functie: ";
		for (int i = 0; i < P.NrFosteFunctii; i++)
			in >> P.NumeFunctii[i];
	}
	else
		P.NumeFunctii = NULL;
	return in;
}
ostream& operator<<(ostream& out, const PersManagementDealership& P)
{
	out << "Persoana cu numele: " << P.nume << " cu id: " << P.id << " ,cu functia: " << P.functie << " ,cu varsta: " << P.varsta << " ,cu salariul " << P.salariu << " ,cu nr functii anterioare:" << P.NrFosteFunctii << endl;
	out << "Numele fiecarei functii:" << endl;
	if (P.NumeFunctii != NULL)
		for (int i = 0; i < P.NrFosteFunctii; i++)
			out << P.NumeFunctii[i] << " ";
	else out << "Nu se cunoaste numele functiilor";
	out << endl;
	return out;
}

class vanzator {
	const int id;
	static int contor;
	char* sex;
	string nume;
	int varsta;
	int NrMasiniVandute;
	string* MasiniVandute;
public:
	vanzator() :id(contor++)
	{
		this->sex = new char[strlen("Necunoscut") + 1];
		strcpy(this->sex, "Necunoscut");
		this->nume = " ";
		this->varsta = 0;
		this->NrMasiniVandute = 0;
		this->MasiniVandute = NULL;

	}
	vanzator(string nume) :id(contor++)
	{
		this->sex = new char[strlen("Necunoscut") + 1];
		strcpy(this->sex, "Necunoscut");
		this->nume = nume;
		this->varsta = 0;
		this->NrMasiniVandute = 0;
		this->MasiniVandute = NULL;

	}
	vanzator(char* sex, string nume, int varsta, int NrMasiniVandute, string* MasiniVandute) :id(contor++)
	{
		this->sex = new char[strlen(sex) + 1];
		strcpy(this->sex, sex);
		this->varsta = varsta;
		this->nume = nume;
		this->NrMasiniVandute = NrMasiniVandute;
		this->MasiniVandute = new string[this->NrMasiniVandute];
		for (int i = 0; i < this->NrMasiniVandute; i++)
			this->MasiniVandute[i] = MasiniVandute[i];


	}
	char* getSex()
	{
		return this->sex;
	}
	int getVarsta() {
		return this->varsta;
	}
	string getnume()
	{
		return this->nume;
	}

	int getNrMasiniVandute() {
		return this->NrMasiniVandute;
	}

	string* getMasiniVandute() {
		return this->MasiniVandute;
	}

	void setSex(char* sex)
	{
		if (this->sex != NULL)
		{
			delete[]this->sex;
		}
		this->sex = new char[strlen(sex) + 1];
		strcpy(this->sex, sex);
	}
	void setVarsta(int varsta) {
		if (varsta >= 18)
			this->varsta = varsta;
		else
			this->varsta = 0;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setNrMasiniVandute(int NrMasiniVandute) {
		if (NrMasiniVandute >= 0)
			this->NrMasiniVandute = NrMasiniVandute;
		else
			this->NrMasiniVandute = 0;
	}
	void setNumeFunctii(int nrMasiniVanduteNoi, string* MasiniVanduteNoi)
	{
		if (this->MasiniVandute != NULL)
		{
			delete[]this->MasiniVandute;
		}
		this->NrMasiniVandute = nrMasiniVanduteNoi;
		this->MasiniVandute = new string[this->NrMasiniVandute];
		for (int i = 0; i < this->NrMasiniVandute; i++)
		{
			this->MasiniVandute[i] = MasiniVanduteNoi[i];
		}
	}
	vanzator(const vanzator& v) :id(contor++)
	{
		this->sex = new char[strlen(v.sex) + 1];
		strcpy(this->sex, v.sex);
		this->varsta = v.varsta;
		this->nume = v.nume;
		this->NrMasiniVandute = v.NrMasiniVandute;
		this->MasiniVandute = new string[this->NrMasiniVandute];
		for (int i = 0; i < this->NrMasiniVandute; i++)
			this->MasiniVandute[i] = v.MasiniVandute[i];
	}
	vanzator& operator =(const vanzator& v)
	{
		if (this != &v)
		{
			if (this->sex != NULL)
			{
				delete[]this->sex;
			}
			if (this->MasiniVandute != NULL)
			{
				delete[]this->MasiniVandute;
			}
			this->sex = new char[strlen(v.sex) + 1];
			strcpy(this->sex, v.sex);
			this->varsta = v.varsta;
			this->nume = v.nume;
			this->NrMasiniVandute = v.NrMasiniVandute;
			this->MasiniVandute = new string[this->NrMasiniVandute];
			for (int i = 0; i < this->NrMasiniVandute; i++)
				this->MasiniVandute[i] = v.MasiniVandute[i];
			return *this;
		}
	}
	string& operator[](int index)
	{
		if (index >= 0 && index < this->NrMasiniVandute)
		{
			return this->MasiniVandute[index];
		}
		else
		{
			throw new exception("Eroare: nu e buna acea valoare!");
		}
	}

	vanzator operator+(int x)
	{
		vanzator rez = *this;
		rez.varsta += x;

		return rez;
	}

	vanzator operator++()
	{
		this->varsta++;
		return *this;
	}

	vanzator operator++(int)
	{

		vanzator rez = *this;
		this->varsta++;
		return rez;
	}
	explicit operator string()
	{
		return this->nume;
	}

	vanzator& operator!()
	{
		delete[]this->MasiniVandute;
		this->MasiniVandute = NULL;
		this->NrMasiniVandute = 0;
		return *this;

	}

	bool operator <(const vanzator& V)
	{
		return this->varsta < V.varsta;
	}

	bool operator==(const vanzator& V)
	{
		return this->NrMasiniVandute == V.NrMasiniVandute;
	}

	~vanzator()
	{
		if (this->sex != NULL)
		{
			delete[]this->sex;
		}
		if (this->MasiniVandute != NULL)
		{
			delete[]this->MasiniVandute;
		}

	}
	friend istream& operator>>(istream& in, vanzator& V);
	friend ostream& operator<<(ostream& out, const vanzator& V);

};
int vanzator::contor = 1;

istream& operator>>(istream& in, vanzator& V)
{
	cout << "Introduceti numele vanzatorului: ";
	in >> V.nume;
	cout << "Introduceti sex-ul: ";
	if (V.sex != NULL)
	{
		delete[]V.sex;
	}
	in >> ws;
	char aux[250];
	in.getline(aux, 249);
	V.sex = new char[strlen(aux) + 1];
	strcpy(V.sex, aux);
	cout << "Introduceti varsta: ";
	in >> V.varsta;
	cout << "Introduceti numarul de masini vandute: ";
	in >> V.NrMasiniVandute;
	if (V.MasiniVandute != NULL)
	{
		delete[]V.MasiniVandute;
	}
	if (V.NrMasiniVandute > 0)
	{
		V.MasiniVandute = new string[V.NrMasiniVandute];
		cout << "Introduceti modelele masinilor: ";
		for (int i = 0; i < V.NrMasiniVandute; i++)
			in >> V.MasiniVandute[i];
	}
	else
		V.MasiniVandute = NULL;
	return in;
}
ostream& operator<<(ostream& out, const vanzator& V)
{
	out << "vanzatorul cu numele: " << V.nume << " cu id: " << V.id << " ,cu sexul: " << V.sex << " ,cu varsta: " << V.varsta << " ,cu nr masini vandute:" << V.NrMasiniVandute << endl;
	out << "Numele fiecarei masini:" << endl;
	if (V.MasiniVandute != NULL)
		for (int i = 0; i < V.NrMasiniVandute; i++)
			out << V.MasiniVandute[i] << " ";
	else out << "Nu se cunoaste numele masinilor";
	out << endl;
	return out;
}

class client {
	const int id;
	static int contor;
	char* sex;
	string CUI;
	string CNP;
	string Nume;
	int varsta;
	int NrMasiniDetinuteInPrezent;
	string* ModelMasini;
public:
	client() :id(contor++)
	{
		this->sex = new char[strlen("Necunoscut") + 1];
		strcpy(this->sex, "Necunoscut");
		this->CUI = " ";
		this->CNP = " ";
		this->Nume = " ";
		this->varsta = 0;
		this->NrMasiniDetinuteInPrezent = 0;
		this->ModelMasini = NULL;

	}
	client(string nume) :id(contor++)
	{
		this->sex = new char[strlen("Necunoscut") + 1];
		strcpy(this->sex, "Necunoscut");
		this->CUI = " ";
		this->CNP = " ";
		this->Nume = nume;
		this->varsta = 0;
		this->NrMasiniDetinuteInPrezent = 0;
		this->ModelMasini = NULL;

	}
	client(char* sex, string CUI, string CNP, string nume, int varsta, int NrMasiniDetinuteInPrezent, string* ModelMasini) :id(contor++)
	{
		this->sex = new char[strlen(sex) + 1];
		strcpy(this->sex, sex);
		this->CUI = CUI;
		this->CNP = CNP;
		this->varsta = varsta;
		this->Nume = nume;
		this->NrMasiniDetinuteInPrezent = NrMasiniDetinuteInPrezent;
		this->ModelMasini = new string[this->NrMasiniDetinuteInPrezent];
		for (int i = 0; i < this->NrMasiniDetinuteInPrezent; i++)
			this->ModelMasini[i] = ModelMasini[i];

	}
	char* getSex()
	{
		return this->sex;
	}
	int getVarsta() {
		return this->varsta;
	}
	string getnume()
	{
		return this->Nume;
	}

	string getCUI() {
		return this->CUI;
	}

	string getCNP() {
		return this->CNP;
	}

	int getNrMasiniDetinuteInPrezent() {
		return this->NrMasiniDetinuteInPrezent;
	}

	string* getModelMasini() {
		return this->ModelMasini;
	}

	void setSex(char* sex)
	{
		if (this->sex != NULL)
		{
			delete[]this->sex;
		}
		this->sex = new char[strlen(sex) + 1];
		strcpy(this->sex, sex);
	}
	void setVarsta(int varsta) {
		if (varsta >= 18)
			this->varsta = varsta;
		else
			this->varsta = 0;
	}
	void setNume(string nume) {
		this->Nume = nume;
	}

	void setCUI(string CUI) {
		this->CUI = CUI;
	}

	void setCNP(string CNP) {
		if (CNP.size() == 13)
			this->CNP = CNP;
		else
			this->CNP = " ";
	}
	void setMasiniDetinuteInPrezent(int NrMasiniDetinuteInPrezent) {
		if (NrMasiniDetinuteInPrezent >= 0)
			this->NrMasiniDetinuteInPrezent = NrMasiniDetinuteInPrezent;
	}
	void setModelMasini(int NrMasiniDetinuteInPrezentNoi, string* ModelMasiniNoi)
	{
		if (this->ModelMasini != NULL)
		{
			delete[]this->ModelMasini;
		}
		this->NrMasiniDetinuteInPrezent = NrMasiniDetinuteInPrezentNoi;
		this->ModelMasini = new string[this->NrMasiniDetinuteInPrezent];
		for (int i = 0; i < this->NrMasiniDetinuteInPrezent; i++)
		{
			this->ModelMasini[i] = ModelMasiniNoi[i];
		}
	}
	client(const client& c) :id(contor++)
	{
		this->sex = new char[strlen(c.sex) + 1];
		strcpy(this->sex, c.sex);
		this->CUI = c.CUI;
		this->CNP = c.CNP;
		this->varsta = c.varsta;
		this->Nume = c.Nume;
		this->NrMasiniDetinuteInPrezent = c.NrMasiniDetinuteInPrezent;
		this->ModelMasini = new string[this->NrMasiniDetinuteInPrezent];
		for (int i = 0; i < this->NrMasiniDetinuteInPrezent; i++)
			this->ModelMasini[i] = c.ModelMasini[i];
	}
	client& operator =(const client& c)
	{
		if (this != &c)
		{
			if (this->sex != NULL)
			{
				delete[]this->sex;
			}
			if (this->ModelMasini != NULL)
			{
				delete[]this->ModelMasini;
			}
			this->sex = new char[strlen(c.sex) + 1];
			strcpy(this->sex, c.sex);
			this->CUI = c.CUI;
			this->CNP = c.CNP;
			this->varsta = c.varsta;
			this->Nume = c.Nume;
			this->NrMasiniDetinuteInPrezent = c.NrMasiniDetinuteInPrezent;
			this->ModelMasini = new string[this->NrMasiniDetinuteInPrezent];
			for (int i = 0; i < this->NrMasiniDetinuteInPrezent; i++)
				this->ModelMasini[i] = c.ModelMasini[i];
			return *this;
		}
	}
	string& operator[](int index)
	{
		if (index >= 0 && index < this->NrMasiniDetinuteInPrezent)
		{
			return this->ModelMasini[index];
		}
		else
		{
			throw new exception("Eroare: nu e buna acea valoare!");
		}
	}
	client operator+(int x)
	{
		client rez = *this;
		rez.varsta += x;

		return rez;
	}

	client operator++()
	{
		this->varsta++;
		return *this;
	}

	client operator++(int)
	{

		client rez = *this;
		this->varsta++;
		return rez;
	}

	explicit operator string()
	{
		return this->CNP;
	}

	client& operator!()
	{
		delete[]this->ModelMasini;
		this->ModelMasini = NULL;
		this->NrMasiniDetinuteInPrezent = 0;
		return *this;

	}

	bool operator <(const client& C)
	{
		return this->NrMasiniDetinuteInPrezent < C.NrMasiniDetinuteInPrezent;
	}

	bool operator==(const client& C)
	{
		return (this->CUI == C.CUI || this->CNP == C.CNP);
	}
	~client()
	{
		if (this->sex != NULL)
		{
			delete[]this->sex;
		}
		if (this->ModelMasini != NULL)
		{
			delete[]this->ModelMasini;
		}

	}
	friend istream& operator>>(istream& in, client& C);
	friend ostream& operator<<(ostream& out, const client& C);
};
int client::contor = 1;
istream& operator>>(istream& in, client& C)
{
	cout << "Introduceti numele clientului: ";
	in >> C.Nume;
	cout << "Introduceti sexul: ";
	if (C.sex != NULL)
	{
		delete[]C.sex;
	}
	in >> ws;
	char aux[250];
	in.getline(aux, 249);
	C.sex = new char[strlen(aux) + 1];
	strcpy(C.sex, aux);
	cout << "Introduceti varsta: ";
	in >> C.varsta;
	cout << "Introduceti CNP: ";
	in >> C.CNP;
	cout << "Introduceti CUI: ";
	in >> C.CUI;
	cout << "Introduceti numarul de masini detinute: ";
	in >> C.NrMasiniDetinuteInPrezent;
	if (C.ModelMasini != NULL)
	{
		delete[]C.ModelMasini;
	}
	if (C.NrMasiniDetinuteInPrezent > 0)
	{
		C.ModelMasini = new string[C.NrMasiniDetinuteInPrezent];
		cout << "Introduceti numele pentru fiecare detinator: ";
		for (int i = 0; i < C.NrMasiniDetinuteInPrezent; i++)
			in >> C.ModelMasini[i];
	}
	else
		C.ModelMasini = NULL;
	return in;
}
ostream& operator<<(ostream& out, const client& C)
{
	out << "clientul cu numele: " << C.Nume << " cu id: " << C.id << " ,cu sexul: " << C.sex << " ,cu varsta: " << C.varsta << " ,cu CNP: " << C.CNP << " ,cu CUI: " << C.CUI << " ,cu nr masini detinute:" << C.NrMasiniDetinuteInPrezent << endl;
	out << "Numele fiecarei masini:" << endl;
	if (C.ModelMasini != NULL)
		for (int i = 0; i < C.NrMasiniDetinuteInPrezent; i++)
			out << C.ModelMasini[i] << " ";
	else out << "Nu se cunoaste numele masinilor";
	out << endl;
	return out;
}

class portar : public PersManagementDealership {
	string inaltime;
	int nrOreSuplimentare = 0;
	int AniExperientaDomeniu = 0;
public:
	portar() {
		this->inaltime = "Nu se stie";
		this->nrOreSuplimentare = 0;
		this->AniExperientaDomeniu = 0;
	}
	portar(char* functie, int varsta, int salariu, string nume, int nrFosteFunctii, string* NF, string inaltime, int nrOreSuplimentare, int AniExperientaDomeniu) :PersManagementDealership(functie, varsta, salariu, nume, nrFosteFunctii, NF) {
		this->inaltime = inaltime;
		this->nrOreSuplimentare = nrOreSuplimentare;
		this->AniExperientaDomeniu = AniExperientaDomeniu;
	}
	portar(const portar& p) :PersManagementDealership(p) {
		this->inaltime = p.inaltime;
		this->nrOreSuplimentare = p.nrOreSuplimentare;
		this->AniExperientaDomeniu = p.AniExperientaDomeniu;
	}
	portar& operator=(const portar& p) {
		PersManagementDealership::operator=(p);
		this->inaltime = p.inaltime;
		this->nrOreSuplimentare = p.nrOreSuplimentare;
		this->AniExperientaDomeniu = p.AniExperientaDomeniu;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const portar& p)
	{
		out << (PersManagementDealership)p;//cast explicit la Angajat
		out << "\ninaltime: " << p.inaltime;
		out << "\nNr ore suplimetare: " << p.nrOreSuplimentare;
		return out;
	}

	~portar()
	{

	}

	float calculSalariu()
	{
		return this->salariu + this->nrOreSuplimentare * 20;
	}

};

//o clasa container/colectie
template<class TIP>
class Colectie
{
	int nrObiecte = 0;
	TIP* listaObiecte = NULL;

public:
	Colectie()
	{

	}

	Colectie(int nrObiecte, TIP* listaObiecte)
	{
		if (listaObiecte != NULL && nrObiecte > 0)
		{
			this->nrObiecte = nrObiecte;
			this->listaObiecte = new TIP[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
				this->listaObiecte[i] = listaObiecte[i];
		}
	}

	Colectie(const Colectie& c)
	{
		if (c.listaObiecte != NULL && c.nrObiecte > 0)
		{
			this->nrObiecte = c.nrObiecte;
			this->listaObiecte = new TIP[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
				this->listaObiecte[i] = c.listaObiecte[i];
		}
	}

	Colectie& operator=(const Colectie& c)
	{
		delete[] this->listaObiecte;
		if (c.listaObiecte != NULL && c.nrObiecte > 0)
		{
			this->nrObiecte = c.nrObiecte;
			this->listaObiecte = new TIP[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
				this->listaObiecte[i] = c.listaObiecte[i];
		}
		return *this;
	}

	~Colectie()
	{
		delete[] this->listaObiecte;
	}

	friend ostream& operator<<(ostream& out, const Colectie& c)
	{
		out << "\n------------------------------------";
		out << "\nNr obiecte: " << c.nrObiecte;
		out << "\nLista obiecte: ";
		for (int i = 0; i < c.nrObiecte; i++)
			out << c.listaObiecte[i] << "\n";
		out << "\n------------------------------------";
		return out;
	}
};

int main(int argc, char* argv[]) {
	int nrFisiere = argc; //numarul de argumente primite ca parametru
	string* listaFisiere = new string[argc];
	for (int i = 0; i < argc; i++)
		listaFisiere[i] = argv[i];//incarcarea in vectorul de string-uri a parametrilor primiti la apel

	for (int i = 0; i < argc; i++)
		cout << listaFisiere[i] << endl;
	Masina M1;
	cout << M1 << endl;
	Masina M2("George");
	cout << M2 << endl;
	Masina M3(new char[] {"neagra"}, "BMW", 5.11, 2010, "1.2", 5, new string[]{ "a1","a2","a3","a4","a5" });
	cout << M3 << endl;
	fstream mOut("fisier2.txt", ios::out | ios::binary);
	M3.writeToFile(mOut);
	mOut.close();
	/*Masina M4;
	cin >> M4;
	cout << M4 << endl;*/
	cout << M3.getCuloare() << " " << M3.getMotor() << endl;
	M3.setCuloare(new char[] {"verde"});
	M3.setMotor("1.4");
	cout << M3.getCuloare() << " " << M3.getMotor() << endl;
	Masina M4(M3);
	cout << M4 << endl;
	Masina M5 = M3;
	cout << M5 << endl;
	cout << M3.operator[](3) << endl;
	cout << M3.operator+(200) << endl;
	cout << M3.operator++() << endl;
	cout << M3.operator std::string() << endl;
	cout << M3.operator!() << endl;
	if (M4 == M5)
		cout << "sunt egale";
	else
		cout << "nu sunt egale";
	if (M4.operator>(M5))
		cout << "M4 are pretul mai mare";
	else
		cout << "M5 are pretul mai mare sau sunt egale";

	StocDealership S1;
	cout << S1 << endl;
	StocDealership S2("George");
	cout << S2 << endl;
	float preturiMasini[] = { 11.5,34.2,66.1,128.2,7.3 };
	StocDealership S3(new char[] {"Magazin"}, "Cinema", 5, new string[]{ "masina1","masina2","masina3","masina4","masina5" }, preturiMasini, new Masina[]{ M3,M3,M3,M4,M5 });
	cout << S3 << endl;
	fstream fOut("fisier.txt", ios::out, ios::binary);
	S3.writeToFile(fOut);
	fOut.close();
	/*StocDealership S4;
	cin >> S4;
	cout << S4;*/
	cout << S3.getLocatie() << " " << S3.getNume() << endl;
	S3.setLocatie("Shopping");
	S3.setNume(new char[] {"Bita"});
	cout << S3.getLocatie() << " " << S3.getNume() << endl;
	StocDealership S4(S3);
	cout << S4;
	StocDealership S5 = S4;
	cout << S5;
	cout << S3.operator[](3);
	cout << S3.operator*(10);
	cout << S3.operator++();
	cout << S3.operator std::string();
	cout << S3.operator!();
	if (S4 == S5)
		cout << "sunt egale" << endl;
	else
		cout << "nu sunt egale" << endl;
	if (S3.operator<(S4))
		cout << "S3 are un numar mai mic de masini" << endl;
	else
		cout << "S4 are un numar mai mic de masini sau sunt egale" << endl;


	PersManagementDealership P1;
	cout << P1 << endl;
	PersManagementDealership P2("mangaer");
	cout << P2 << endl;
	PersManagementDealership P3(new char[] {"lider"}, 20, 1400, "George", 5, new string[]{ "f1","f2","f3","f4","f5" });
	cout << P3 << endl;
	/*PersManagementDealership P4;
	cin >> P4;
	cout << P4 << endl;*/
	PersManagementDealership P4 = P3;
	PersManagementDealership P5(P4);
	cout << P4 << endl;
	cout << P5 << endl;
	cout << P3.getFunctie() << " " << P3.getnume() << endl;
	P3.setFunctie(new char[] {"casiera"});
	P3.setNume("Marcela");
	cout << P3.getFunctie() << " " << P3.getnume() << endl;
	cout << P3.operator std::string() << endl;
	cout << P3.operator+(5) << endl;
	cout << P3.operator++() << endl;
	cout << P3.operator!() << endl;
	if (P4 == P5)
		cout << "sunt egale" << endl;
	else
		cout << "nu sunt egale" << endl;
	if (P4.operator<=(P5))
		cout << "P4 are un numar mai mic sau egal de masini" << endl;
	else
		cout << "P5 are un numar mai mic de masini" << endl;
	vanzator V1;
	cout << V1 << endl;
	vanzator V2("Andreea");
	cout << V2 << endl;
	vanzator V3(new char[] {"feminin"}, "Ioana", 23, 5, new string[]{ "v1","v2","v3","v4","v5" });
	cout << V3 << endl;
	/*vanzator V4;
	cin >> V4;
	cout << V4 << endl;*/
	vanzator V4 = V3;
	vanzator V5(V3);
	cout << V4 << endl;
	cout << V5 << endl;
	cout << V3.getnume() << " " << V3.getSex() << endl;
	V3.setNume("Elena");
	V3.setSex(new char[] {"Fem"});
	cout << V3.getnume() << " " << V3.getSex() << endl;
	cout << V3.operator std::string() << endl;
	cout << V3.operator+(5) << endl;
	cout << V3.operator++() << endl;
	cout << V3.operator!() << endl;
	if (V4 == V5)
		cout << "este egal" << endl;
	else
		cout << "nu este egal" << endl;
	if (V3.operator<(V4))
		cout << "V3 este mai mic ca V4";
	else
		cout << "V4 este mai mic ca V3 sau au aceeasi varsta";

	client C1;
	cout << C1 << endl;
	client C2("Marcel");
	cout << C2 << endl;
	client C3(new char[] {"masculin"}, "3124", "6000315025493", "Catalin", 22, 3, new string[]{ "logan","dacie","cielo" });
	cout << C3 << endl;
	//client C4;
	//cin >> C4;
	//cout << C4<<endl;
	client C4(C3);
	cout << C4 << endl;
	client C5 = C4;
	cout << C5 << endl;
	cout << C4.getCNP() << " " << C4.getCUI() << endl;
	C4.setCNP("1234567891234");
	C4.setCUI("4612");
	cout << C4.getCNP() << " " << C4.getCUI() << endl;
	cout << C3.operator+(3) << endl;
	cout << C3.operator++() << endl;
	cout << C3.operator[](2) << endl;
	cout << C3.operator!() << endl;
	if (C3 == C5)
		cout << "sunt egale" << endl;
	else
		cout << "nu sunt egale" << endl;
	if (C3.operator<(C4))
		cout << "varsta clientului C3 este mai mica decat a lui C4";
	else
		cout << "varsta clientului C4 este mai mica sau egala cu a lui C4";

	IFile* pObj;
	pObj = new StocDealership();

	fstream fIn("fisier.txt", ios::in | ios::binary);
	StocDealership S10;
	S10.readFromFile(fIn);
	fIn.close();
	cout << endl;
	cout << S10;

	IFile* pObj2;
	pObj2 = new Masina();

	fstream mIn("fisier2.txt", ios::in | ios::binary);
	Masina M10;
	M10.readFromFile(mIn);
	mIn.close();
	cout << endl;
	cout << M10;

	ifstream f("SD2.txt");
	StocDealership S11;
	f >> S11;
	cout << endl;
	cout << "Testare citire din fisier text: ";
	cout << S11;
	cout << endl;


	ifstream f2("M.txt");
	Masina M12;
	f2 >> M12;
	cout << endl;
	cout << "Testare citire din fisier text: ";
	cout << M12;
	cout << endl;

	portar po1;
	PersManagementDealership P20(new char[] {"lider"}, 20, 1400, "George", 5, new string[]{ "f1","f2","f3","f4","f5" });
	portar po2(new char[] {"portar"}, 10, 1400, "George", 5, new string[]{ "f1","f2","f3","f4","f5" }, "1,5", 5, 15);
	portar po3(new char[] {"portar"}, 15, 1100, "Ion", 5, new string[]{ "f1","f2","f3","f4","f5" }, "1,77", 20, 12);
	cout << po2 << endl;
	cout << "\nTESTARE METODE CALCUL SALARIU";
	cout << endl << P20.calculSalariu();
	cout << endl << po2.calculSalariu();
	cout << endl << po2.PersManagementDealership::calculSalariu();

	PersManagementDealership listaPersonal[] = { P20,po2,po3 };
	int salariuTotal = 0;
	for (int i = 0; i < 3; i++)
	{
		salariuTotal += listaPersonal[i].calculSalariu();
		cout << "\n" << listaPersonal[i].calculSalariu();
	}
	cout << "\nSalariu total= " << salariuTotal;

	//evidentiere Virtualizare
	PersManagementDealership* listaPersonal2[] = { &P20,&po2,&po3 };

	float salariuTotal2 = 0;
	for (int i = 0; i < 3; i++)
	{
		salariuTotal2 += listaPersonal2[i]->calculSalariu();
		cout << "\n" << (*listaPersonal2[i]).calculSalariu();
	}
	cout << "\nSalariu total2= " << salariuTotal2 << endl;

	string listaString[] = { "Cata","Bita","Denisa" };
	Colectie<string> colectieString(3, listaString);
	cout << colectieString;

	cout << endl;

	Masina listaMasina2[] = { M3,M4 };
	Colectie<Masina> colectieMasina(2, listaMasina2);
	cout << colectieMasina;

	cout << "\n----------------LUCRUL CU STL LIST-------------------\n";
	list<float> listFloat;
	listFloat.push_back(12.5f);
	listFloat.push_back(20.5f);
	listFloat.push_front(13.4f);

	list<float>::iterator itLFloat;
	for (itLFloat = listFloat.begin(); itLFloat != listFloat.end(); itLFloat++)
		cout << *itLFloat << " ";

	list<Masina> listEveniment;
	listEveniment.push_back(M3);
	listEveniment.push_front(M4);

	list<Masina>::iterator itLEv;
	for (itLEv = listEveniment.begin(); itLEv != listEveniment.end(); itLEv++)
		cout << *itLEv;

	list<Masina>::reverse_iterator itLEvReverse;
	for (itLEvReverse = listEveniment.rbegin(); itLEvReverse != listEveniment.rend(); itLEvReverse++)
		cout << *itLEvReverse;
	cout << endl;


	cout << "\n----------------LUCRUL CU STL MAP-------------------\n";
	map<int, Masina> mapMasina;//int-ul este cheia iar Eveniment este obj stocat
	mapMasina[0] = M3;
	mapMasina[4] = M4;
	mapMasina[10] = M5;


	map<int, Masina>::iterator itMap;
	for (itMap = mapMasina.begin(); itMap != mapMasina.end(); itMap++)
		cout << itMap->first << " " << itMap->second << endl;


	cout << "Citire din fisier CSV: ";
	cout << "Potentiali clienti care nu sunt inca bagati in baza de date:";

	cout << endl;




	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("Book1.csv", ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout << "Nu am putut deschide fisierul\n";

	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}


	cout << "===================================== \n";
	cout << " \t\tMENIU \t \n ";
	cout << "===================================== \n";
	cout << " 1.Adauga o masina\n";
	cout << " 2.Adauga o persoana din management\n";
	cout << " 3.Adauga un dealership \n";
	cout << " 4.Adauga o vanzatoare \n";
	cout << " 5.Adauga un client \n";

	int alegere2;
	string confirm;
	do {
		cout << "alegeti optiunea: ";

		cin >> alegere2;
		switch (alegere2) {
		case 1: {
			Masina m12;
			cin >> m12;
			break;
		}
		case 2: {
			PersManagementDealership p10;
			cin >> p10;
			break;
		}
		case 3: {
			StocDealership s2;
			cin >> s2;
			break;
		}
		case 4: {
			vanzator v1;
			cin >> v1;
			break;
		}
		case 5: {
			client c1;
			cin >> c1;
			break;
		}
		}
		cout << "Scrieti DA daca doriti sa continuati sau apasati orice alta tasta pentru a inchide meniul: ";

		cin >> confirm;

	} while (confirm == "DA");



}