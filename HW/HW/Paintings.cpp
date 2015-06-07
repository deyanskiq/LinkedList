#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Painting
{
private:
	string title;
	string artistName;
	int prize;
public:
	Painting();
	Painting(string, string, int);
	~Painting();
	int getPrize();
	void setPrice(int);
	string getTitle();
	void setTitle(string);
	string getArtistName();
	void setArtistName(string);
	virtual int value() = 0;
	virtual void Input() = 0;
};

Painting::Painting()
{
	cout << "Creating a painting" << endl;
}

Painting::Painting(string title, string artistName, int prize)
{
	this->title = title;
	this->artistName = artistName;
	this->prize = prize;
}

Painting::~Painting()
{
	cout << "Destroy a painting" << endl;
}

string Painting::getArtistName()
{
	return artistName;
}

string Painting::getTitle()
{
	return title;
}

int Painting::getPrize()
{
	return prize;
}

void Painting::setPrice(int price)
{
	this->prize = price;
}

void Painting::setTitle(string title)
{
	this->title = title;
}

void Painting::setArtistName(string artistName)
{
	this->artistName = artistName;
}

class OilPainting : public Painting
{
public:
	OilPainting();
	OilPainting(string, string, int);
	int value() override;
	void Input() override;
};

class FamousPainting : public Painting
{
public:
	FamousPainting();
	FamousPainting(string, string, int);
	int value() override;
	void Input() override;
};

class PensilPainting : public Painting
{
public:
	PensilPainting();
	PensilPainting(string, string, int);
	int value() override;
	void Input() override;
};

OilPainting::OilPainting()
{
	this->setPrice(0);
	this->setArtistName("None");
	this->setTitle("None");
}

OilPainting::OilPainting(string title, string artistName, int prize) :Painting(title, artistName, prize)
{}

void OilPainting::Input()
{
	int price;
	string artistName, title;
	cout << "Enter artist name: ";
	cin >> artistName;
	this->setArtistName(artistName);
	cout << "Enter painting title: ";
	cin >> title;
	this->setTitle(title);
	cout << "Enter price: ";
	cin >> price;
	this->setPrice(price);
}

FamousPainting::FamousPainting()
{
	this->setPrice(0);
	this->setArtistName("None");
	this->setTitle("None");
}

FamousPainting::FamousPainting(string title, string artistName, int prize) : Painting(title, artistName, prize)
{}

void FamousPainting::Input()
{
	int price;
	string artistName, title;
	cout << "Enter artist name: ";
	cin >> artistName;
	this->setArtistName(artistName);
	cout << "Enter painting title: ";
	cin >> title;
	this->setTitle(title);
	cout << "Enter price: ";
	cin >> price;
	this->setPrice(price);
}

PensilPainting::PensilPainting()
{
	this->setPrice(0);
	this->setArtistName("None");
	this->setTitle("None");
}
PensilPainting::PensilPainting(string title, string artistName, int prize) : Painting(title, artistName, prize)
{}

void PensilPainting::Input()
{
	int price;
	string artistName, title;
	cout << "Enter artist name: ";
	cin >> artistName;
	this->setArtistName(artistName);
	cout << "Enter painting title: ";
	cin >> title;
	this->setTitle(title);
	cout << "Enter price: ";
	cin >> price;
	this->setPrice(price);
}

int OilPainting::value(){
	return this->getPrize();
}

int FamousPainting::value(){
	return this->getPrize();
}

int PensilPainting::value(){
	return this->getPrize();
}

typedef std::vector<Painting*> PAINTVECTOR;

Painting* CreatePainting()
{
	int choice;

	std::cout <<
		"What do you want to enter?\n"
		"  1 - Oil Painting\n"
		"  2 - Famous Painting\n"
		"  3 - Pencil Painting\n"
		"Your choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		return new OilPainting();

	case 2:
		return new FamousPainting();

	case 3:
		return new PensilPainting();

	default:
		throw std::exception("Wrong input");
	}
}

int main()
{
	/*FamousPainting a("La Gioconda", "Leonardo da Vinci", 30000000);
	OilPainting b("x", "Monet", 2000000);
	PensilPainting c("y", "Dega", 1000000);
	cout << b.getArtistName() << endl;
	cout << a.value() << endl;
	cout << b.value() << endl;
	cout << c.value() << endl;*/

	PAINTVECTOR paintings;
	char choice;

	do
	{
		try {
			Painting* pPainting = CreatePainting();
			pPainting->Input();
			paintings.push_back(pPainting);
		}
		catch (std::bad_alloc& e)
		{
			std::cerr << "ERROR: Allocation failed! (reason: " << e.what() << ")\n";
			break;
		}
		catch (std::exception& e)
		{
			std::cerr << "ERROR: Operation failed! (reason: " << e.what() << ")\n";
		}

		std::cout << "Enter another painting (y/n): ";
		std::cin >> choice;

	} while (choice == 'y' || choice == 'Y');

	int price = 0;

	for (size_t i = 0; i < paintings.size(); i++)
	{
		price += paintings.at(i)->value();
	}

	cout << "Total amount of the paintings is " << price << endl;

	for (size_t i = 0; i < paintings.size(); i++)
	{
		delete paintings.at(i);
	}

	system("pause");
	return 0;
}