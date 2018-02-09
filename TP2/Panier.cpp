/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Panier.h"

Panier::Panier(int capacite) :
	capaciteContenu_{ capacite },
	nombreContenu_{ 0 },
	contenuPanier_{ new Produit *[capaciteContenu_] },
	totalAPayer_{ 0 }
{
}

Panier::~Panier()
{
}

// methodes d'accès
Produit **  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return nombreContenu_;
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

// méthodes de modification

// autres méthodes
void Panier::ajouter(Produit * prod)
{
	contenuPanier_.push_back(prod);
	totalAPayer_ += prod->obtenirPrix();

}

void Panier::livrer()
{
	for (int i = 0; i < contenuPanier_.size(); i++)
		contenuPanier_.pop_back();
	totalAPayer_ = 0;
	
}

Produit * Panier::trouverProduitPlusCher()
{
	// TODO: Implementez la methode
}

void Panier::afficher() const
{
	for (int i = 0; i < nombreContenu_; i++)
		contenuPanier_[i]->afficher();

	cout << "----> total a payer : " << totalAPayer_ << endl;
}
