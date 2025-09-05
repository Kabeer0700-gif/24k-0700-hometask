//Q1.cpp created
#include <iostream>
#include <cstring>
using namespace std;

class ResearchPaper {
    char** authors;
    int count;
public:
    ResearchPaper(int c = 0) {
        count = c;
        if (count > 0) {
            authors = new char*[count];
            for (int i = 0; i < count; i++) {
                authors[i] = new char[20];
                strcpy(authors[i], "Unknown");
            }
        } else authors = nullptr;
    }
    ~ResearchPaper() {
        for (int i = 0; i < count; i++) delete[] authors[i];
        delete[] authors;
    }
    ResearchPaper(const ResearchPaper& other) {
        count = other.count;
        authors = new char*[count];
        for (int i = 0; i < count; i++) {
            authors[i] = new char[strlen(other.authors[i]) + 1];
            strcpy(authors[i], other.authors[i]);
        }
    }
    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this != &other) {
            for (int i = 0; i < count; i++) delete[] authors[i];
            delete[] authors;
            count = other.count;
            authors = new char*[count];
            for (int i = 0; i < count; i++) {
                authors[i] = new char[strlen(other.authors[i]) + 1];
                strcpy(authors[i], other.authors[i]);
            }
        }
        return *this;
    }
    void setAuthor(int i, const char* name) {
        if (i >= 0 && i < count) strcpy(authors[i], name);
    }
    void show() {
        for (int i = 0; i < count; i++) cout << authors[i] << " ";
        cout << endl;
    }
};

int main() {
    ResearchPaper r1(2);
    r1.setAuthor(0, "Kabeer");
    r1.setAuthor(1, "Usman");
    ResearchPaper r2 = r1;
    r2.setAuthor(1, "shamveel");
    r1.show();
    r2.show();
}
