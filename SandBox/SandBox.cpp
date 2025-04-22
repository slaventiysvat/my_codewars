// SandBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#if _MSVC_LANG >= 202002L
//#define CPP_VERSION "C++20"
//#elif _MSVC_LANG >= 201703L
//#define CPP_VERSION "C++17"
//#elif _MSVC_LANG >= 201402L
//#define CPP_VERSION "C++14"
//#else
//#define CPP_VERSION "C++11 or earlier"
//#endif

#include <iostream>
#include <bitset>
#include <iomanip> 
#include <string> 
#include <cstddef>
#include <cstdint>
#if _MSVC_LANG >= 202002L // C++20
    #include <bit>
#endif
#include <type_traits> // For std::enable_if and std::is_unsigned




const unsigned int redBitsMsk = 0xFF000000; 
const unsigned int greenBitsMsk = 0x00FF0000;
const unsigned int blueBitsMsk = 0x0000FF00;
const unsigned int alphaBitsMsk = 0x000000FF;

int show_colorRGBA(std::bitset<32>& valToShow);

// Circular shift function
template <typename T>
//typename std::enable_if<std::is_unsigned<T>::_v, T>::_t circularShift(T value, int shift, bool leftShift = true) {
typename std::enable_if<std::is_unsigned<T>::value, T>::type circularShift(T value, int shift, bool leftShift = true) {
    constexpr int bitSize = sizeof(T) * 8; // Number of bits in the type

    // Normalize the shift value to avoid unnecessary rotations
    shift %= bitSize;
    if (shift < 0) shift += bitSize; // Handle negative shifts

#if _MSVC_LANG >= 202002L // C++20
    if (leftShift) {
        return std::rotl(value, shift); // Use std::rotl for left rotation
    }
    else {
        return std::rotr(value, shift); // Use std::rotr for right rotation
    }
#elif _MSVC_LANG >= 201703L // C++17
    if (leftShift) {
        return (value << shift) | (value >> (bitSize - shift)); // Manual left rotation
    }
    else {
        return (value >> shift) | (value << (bitSize - shift)); // Manual right rotation
    }
#elif _MSVC_LANG >= 201103L // C++11 or C++14
    // Same as C++17, since C++11 and C++14 don't have `std::rotl` or `std::rotr`
    if (leftShift) {
        return (value << shift) | (value >> (bitSize - shift)); // Manual left rotation
    }
    else {
        return (value >> shift) | (value << (bitSize - shift)); // Manual right rotation
    }
#else
    #error "This function requires at least C++11."
    //#error This function requires at least C++11.
#endif
}

int main()
{
    std::cout << "_MSVC_LANG: " << _MSVC_LANG << std::endl;

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


    unsigned int value = 0b10110011101100111011001110110011; // Example value
    int shift = 3;                  // Number of positions to shift

    //// Circular left shift
    unsigned int leftShifted = circularShift(value, shift, true);
    std::cout << "Original: " << std::bitset<32>(value) << std::endl;
    std::cout << "Left Shifted: " << std::bitset<32>(leftShifted) << std::endl;

    // Circular right shift
    unsigned int rightShifted = circularShift(value, shift, false);
    std::cout << "Right Shifted: " << std::bitset<32>(rightShifted) << std::endl;


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
