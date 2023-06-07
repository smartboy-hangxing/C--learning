#include <iostream>
#include <fstream>
#include <string>
#include <docxtemplater.h>

int main() {
    std::string filename = "test.docx";

    try {
        // Create a new document
        DocxTemplater::DocxTemplater docx(filename);

        // Save the document
        docx.saveAs("test.docx");
    }
    catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
        return 1;
    }

    std::cout << "Word document created successfully." << std::endl;

    return 0;
}
