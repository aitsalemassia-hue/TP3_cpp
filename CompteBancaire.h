
#ifndef COMPTEBANCAIRE_H_
#define COMPTEBANCAIRE_H

#include <iostream>
#include <string>

class CompteBancaire {
private:
    std::string numero;
    double solde;
    std::string* historique;
    std::size_t capacite;
    std::size_t nbOps;

    void agrandirHistorique();
    void ajouterOperation(const std::string& op);

public:
    // Constructeur par défaut
    CompteBancaire();

    // Constructeur paramétré
    CompteBancaire(const std::string& num, double s);

    // Constructeur de copie
    CompteBancaire(const CompteBancaire& other);

    // Constructeur de déplacement
    CompteBancaire(CompteBancaire&& other) noexcept;

    // Destructeur
    ~CompteBancaire();

    // Opérations bancaires
    void deposer(double montant);
    void retirer(double montant);

    // Affichage
    void afficher() const;
};

#endif // COMPTEBANCAIRE_H_
