#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"

int main() {
    Worker a(0,0,0,2,10);
    Worker b(1,1,1,3,30);

    Shovel s1(3);
    Hammer h1(4);

    a.addTool(s1);
    a.addTool(h1);
    a.useAllTools();

    b.addTool(s1); // transfert shovel

    Workshop forge("Forge");
    Workshop mine("Mine");

    forge.registerWorker(a);
    forge.registerWorker(b);
    mine.registerWorker(b);

    forge.executeWorkDay();
    mine.executeWorkDay();

    forge.releaseWorker(a);
    forge.executeWorkDay();

    return 0;
}
