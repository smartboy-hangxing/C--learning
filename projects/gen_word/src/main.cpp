#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string filename = "test.docx";
    fs::path filePath = fs::current_path() / filename;

    std::ofstream file(filePath, std::ios::binary);

    // Word file header
    unsigned char header[] = {
        0x50, 0x4B, 0x03, 0x04, 0x14, 0x00, 0x06, 0x00,
        0x08, 0x00, 0x00, 0x00, 0x21, 0x00, 0xD5, 0x43,
        // Rest of the header data...
    };

    // Write the header to the file
    file.write(reinterpret_cast<const char*>(header), sizeof(header));

    // Close the file
    file.close();

    return 0;
}
