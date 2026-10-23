
#include "CompteBancaire.h"
#include <algorithm>
#include <utility>
#include <string>

// Agrandir l'historique lorsque le tableau est plein
void CompteBancaire::agrandirHistorique() {
    std::size_t nouvelleCap = capacite * 2;

    std::string* nouveau = new std::string[nouvelleCap];

    std::copy(historique, historique + nbOps, nouveau);

    delete[] historique;

    historique = nouveau;
    capacite = nouvelleCap;
}

// Ajouter une opération à l'historique
void CompteBancaire::ajouterOperation(const std::string& op) {
    if (nbOps == capacite) {
        agrandirHistorique();
    }

    historique[nbOps++] = op;
}

// Constructeur par défaut
CompteBancaire::CompteBancaire()
    : numero("NON_DEFINI"),
      solde(0.0),
      historique(new std::string[10]),
      capacite(10),
      nbOps(0) {
}

// Constructeur paramétré
CompteBancaire::CompteBancaire(const std::string& num, double s)
    : numero(num),
      solde(s),
      historique(new std::string[10]),
      capacite(10),
      nbOps(0) {

    ajouterOperation(
        "Creation du compte avec solde " + std::to_string(s)
    );
}

// Constructeur de copie : copie profonde
CompteBancaire::CompteBancaire(const CompteBancaire& other)
    : numero(other.numero),
      solde(other.solde),
      historique(new std::string[other.capacite]),
      capacite(other.capacite),
      nbOps(other.nbOps) {

    std::copy(
        other.historique,
        other.historique + nbOps,
        historique
    );
}

// Constructeur de déplacement
CompteBancaire::CompteBancaire(CompteBancaire&& other) noexcept
    : numero(std::move(other.numero)),
      solde(other.solde),
      historique(other.historique),
      capacite(other.capacite),
      nbOps(other.nbOps) {

    other.historique = nullptr;
    other.capacite = 0;
    other.nbOps = 0;
    other.solde = 0.0;
}

// Destructeur
CompteBancaire::~CompteBancaire() {
    delete[] historique;
}

// Dépôt
void CompteBancaire::deposer(double montant) {
    if (montant <= 0) {
        std::cerr << "Montant de depot invalide" << std::endl;
        return;
    }

    solde += montant;

    ajouterOperation(
        "Depot de " + std::to_string(montant)
    );
}

// Retrait
void CompteBancaire::retirer(double montant) {
    if (montant <= 0 || montant > solde) {
        std::cerr << "Retrait impossible" << std::endl;
        return;
    }

    solde -= montant;

    ajouterOperation(
        "Retrait de " + std::to_string(montant)
    );
}

// Afficher le compte et son historique
void CompteBancaire::afficher() const {
    std::cout << "Compte " << numero
              << " - Solde : " << solde << std::endl;

    std::cout << "Historique des operations :" << std::endl;

    for (std::size_t i = 0; i < nbOps; ++i) {
        std::cout << "  " << historique[i] << std::endl;
    }
}
