#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"

int main() {
    std::cout << "=== DEMO: Composition ===\n";
    Worker a(0,0,0,2,10); // Position + Statistic construits inline -> messages
    a.print();
    std::cout << "=== End Composition ===\n\n";

    std::cout << "=== DEMO: Aggregation ===\n";
    Shovel s1(3);
    std::cout << "-> Donne la pelle s1 a 'a'\n";
    a.addTool(s1);          // a devient propriétaire
    a.listTools();
    std::cout << "-> Transfert de s1 a un autre Worker b\n";
    Worker b(1,1,1,3,30);
    b.addTool(s1);          // transfert : retirer de a, ajouter a b
    std::cout << "-> Vérifier que 'a' n'a plus la pelle, 'b' l'a\n";
    a.listTools();
    b.listTools();
    std::cout << "=== End Aggregation ===\n\n";

    std::cout << "=== DEMO: Inheritance (multiple tools) ===\n";
    Hammer h1(4);
    b.addTool(h1);
    std::cout << "-> 'b' utilise tous ses outils (shovel + hammer)\n";
    b.useAllTools();
    std::cout << "-> 'b' utilise encore pour montrer diminution des uses\n";
    b.useAllTools();
    std::cout << "=== End Inheritance ===\n\n";

    std::cout << "=== DEMO: Association (Workshop) ===\n";
    Workshop forge("Forge");
    Workshop mine("Mine");
    std::cout << "-> Inscription de a et b a Forge et Mine (b multiple)\n";
    forge.registerWorker(a);
    forge.registerWorker(b);
    mine.registerWorker(b);
    std::cout << "-> Execution d'une journee de travail a Forge\n";
    forge.executeWorkDay();
    std::cout << "-> Execution d'une journee de travail a Mine\n";
    mine.executeWorkDay();
    std::cout << "-> Release a de Forge et re-execution\n";
    forge.releaseWorker(a);
    forge.executeWorkDay();
    std::cout << "=== End Association ===\n\n";

    std::cout << "=== Cleanup messages expected: destructors ===\n";
    return 0;
}