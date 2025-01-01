#include "File.h"
#include "game.h"
using namespace std;

int main() {
    const string filename = "m_schott.txt";
    CFile fileManager;
    vector<string> screen;

    if (!fileManager.OpenFile(filename, screen)) {
        cerr << "Failed to load file: " << fileManager.GetLastError() << endl;
        return 1;
    }

    if (!fileManager.ValidateLines(screen)) {
        cerr << "Screen data is invalid: " << fileManager.GetLastError() << endl;
        return 1;
    }

    CGame game;
    game.Start();
    return 0;
}
