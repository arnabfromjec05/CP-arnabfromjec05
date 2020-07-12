// Reverse bits of a given 32 bits unsigned integer.
/* ip: 00000010100101000001111010011100
   op: 00111001011110000010100101000000
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
     
        for(uint32_t i=0;i<=15;i++) {
            if(((n&(1<<i))>0?1:0)^((n&(1<<(31-i)))>0?1:0)) {
                n=(n^(1<<i));
                n=(n^(1<<(31-i)));
            }
        }
        return n;
    }
};