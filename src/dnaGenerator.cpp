#include <cstdlib>
#include <ctime>
#include <fstream>

    void generateDna() {
    std::ofstream file("dna.txt");

    const size_t TOTAL = 200 * 1024 * 1024; // 200 MiB
    const size_t CHUNK = 1024 * 1024; // 1 MiB
    std::string buffer;
    buffer.reserve(CHUNK);

    char last = "ATCG"[rand() % 4];
    bool lastIsAssociated = false;

    for (size_t i = 0; i < TOTAL; ++i) { // 200 MiB
        char base = 0;
    
        if (lastIsAssociated) {
            base = "ATCG"[rand() % 4];
            lastIsAssociated = false;
        }
        else {
            if (i == 0) base = last;
            else if (last = 'A') base = 'T';
            else if (last == 'T') base = 'A';
            else if (last == 'G') base = 'C';
            else if (last == 'C') base = 'G';
            lastIsAssociated = true;
        }

        buffer += base;
        last = base;

        if (buffer.size() == CHUNK) {
            file << buffer;
            buffer.clear();
        }
    }

    if (!buffer.empty()) {
        file << buffer;
    }
}