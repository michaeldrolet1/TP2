/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	tousProduits_{ nullptr }
{
}

Rayon::~Rayon()
{

}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

Produit ** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return tousProduits_.size();
}

// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

void Rayon::ajouterProduit(Produit * produit)
{
	if (tousProduits_ != nullptr)
	{
		if (nombreProduits_ >= capaciteProduits_)
		{
			Produit ** temp;
			capaciteProduits_ += 5;
			temp = new Produit*[capaciteProduits_];
			for (int i = 0; i < nombreProduits_; i++)
				temp[i] = tousProduits_[i];
			delete[] tousProduits_;
			tousProduits_ = temp;

		}
		tousProduits_[nombreProduits_++] = produit;
	}
	else
	{
		capaciteProduits_ = 5;
		tousProduits_ = new Produit*[capaciteProduits_];
		tousProduits_[nombreProduits_++] = produit;
	}
}

 ostream& operator<< (ostream& o,const Rayon& rayon)
{
	o << "Le rayon " << rayon.obtenirCategorie() 
		<< " : " 
		<< endl;
	for (int i = 0; i < rayon.tousProduits_.size();i++)
	{
		o << endl
		<< "---->" << rayon.tousProduits_[i]->afficher()
		

		
	}
	return o;
}
