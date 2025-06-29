// LEETCODE 190

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Static lookup table to reverse 8-bit values
        static uint8_t lookup[256];
        static bool initialized = false;

        // Initialize the lookup table only once
        if (!initialized) {
            for (int i = 0; i < 256; ++i) {
                lookup[i] = reverseByte(i);
            }
            initialized = true;
        }

        // Split the 32-bit number into 4 bytes, reverse each, and reassemble
        return (lookup[n & 0xFF] << 24) |
               (lookup[(n >> 8) & 0xFF] << 16) |
               (lookup[(n >> 16) & 0xFF] << 8) |
               (lookup[(n >> 24) & 0xFF]);
    }

private:
    // Helper to reverse an 8-bit number
    uint8_t reverseByte(uint8_t b) {
        uint8_t res = 0;
        for (int i = 0; i < 8; ++i) {
            res <<= 1;         // shift result to the left
            res |= (b & 1);    // copy the LSB of b
            b >>= 1;           // shift b to the right
        }
        return res;
    }
};
