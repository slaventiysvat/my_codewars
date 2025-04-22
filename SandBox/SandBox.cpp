// SandBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <iomanip> 
#include <string> 
#include <cstddef>

const unsigned int redBitsMsk = 0xFF000000; 
const unsigned int greenBitsMsk = 0x00FF0000;
const unsigned int blueBitsMsk = 0x0000FF00;
const unsigned int alphaBitsMsk = 0x000000FF;

int show_colorRGBA(std::bitset<32>& valToShow);

int main()
{
    std::bitset<32> colorRGBA(static_cast<unsigned long>(redBitsMsk | greenBitsMsk | blueBitsMsk | alphaBitsMsk));

    std::bitset<8> redBits;
    std::bitset<8> greenBits;
    std::bitset<8> blueBits;
    std::bitset<8> alphaBits;

    typedef std::size_t position_t;

	std::cout << "The Default Value of Bits is = 0x" << show_colorRGBA(colorRGBA) << std::endl;

    colorRGBA.reset(position_t(31));
    colorRGBA.reset(position_t(30));

    colorRGBA.reset(position_t(23));
    colorRGBA.reset(position_t(22));

    colorRGBA.reset(position_t(15));
    colorRGBA.reset(position_t(14));

    colorRGBA.reset(position_t(7));
    colorRGBA.reset(position_t(6));

    std::cout << "The Resetted Value of Bits is = 0x" << show_colorRGBA(colorRGBA) << std::endl;

	return 0;

}

int show_colorRGBA(std::bitset<32>& valToShow) {


    const int columnWidth = 8; // Width for each column

    std::bitset<8> redBitsV((valToShow.to_ulong() & redBitsMsk) >> 24);
    std::bitset<8> greenBitV((valToShow.to_ulong() & greenBitsMsk) >> 16);
    std::bitset<8> blueBitsV((valToShow.to_ulong() & blueBitsMsk) >> 8);
    std::bitset<8> alphaBitsV(valToShow.to_ulong() & alphaBitsMsk);


    // Print the header
    std::cout << std::setw(columnWidth) << "R"
        << std::setw(columnWidth) << "G"
        << std::setw(columnWidth) << "B"
        << std::setw(columnWidth) << "A" << std::endl;

    // Print the dashed line
    std::cout << std::string(columnWidth - 1, '-') << "   "
        << std::string(columnWidth - 1, '-') << "   "
        << std::string(columnWidth - 1, '-') << "   "
        << std::string(columnWidth - 1, '-') << std::endl;

    // Print the binary values
    std::cout << std::setw(columnWidth) << redBitsV
        << std::setw(columnWidth) << greenBitV
        << std::setw(columnWidth) << blueBitsV
        << std::setw(columnWidth) << alphaBitsV << std::endl;

    // Print the dashed line again
    std::cout << std::string(columnWidth - 1, '-') << "   "
        << std::string(columnWidth - 1, '-') << "   "
        << std::string(columnWidth - 1, '-') << "   "
        << std::string(columnWidth - 1, '-') << std::endl;

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
