#include"CompteBancaire.h"

#include<string>
int main() {
    CompteBancaire c1("FR123456", 500.0);
    c1.deposer(200);
    c1.retirer(150);
    c1.afficher();
    // Test du constructeur de copie
    CompteBancaire c2 = c1;
    c2.afficher();
    // Test du déplacement
    CompteBancaire c3 = std::move(c1);
    c3.afficher();
    return 0;
}



