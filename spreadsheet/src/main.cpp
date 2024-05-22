#include "../headers/SpreadSheet.h"

int main() {
    SpreadSheet sheet(3, 3);

    for (size_t i = 0; i < sheet.row(); ++i) {
        for (size_t j = 0; j < sheet.col(); ++j) {
            sheet[i][j] =0; 
        }
    }

    std::cout << sheet;

    return 0;
}