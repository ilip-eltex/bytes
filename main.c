#include <stdio.h>

const int bytes = sizeof(int);
const int bits = bytes * 8;


int get_bit (const int value, const int position) {
    return ((value & (1 << position)) != 0);
}

int set_bit (const int value, const int position, const int bit) {
    switch (bit) 
    {
	case 1: return (value | (1 << position));
	case 0: return (value & ~(1 << position));
	default: return -1;	
    }
}

void print_bin (int x) { // for byte only
	for (int i=7; i >= 0; i--)
		printf ("%d", get_bit (x, i) );
}

void print_bytes (int x) {
	int tmp_byte = 0, // current byte getting from X
            current_xbit = 0, // current bit getting from X
            tmp_bit_counter = 0,  // bit counter in current byte
            current_byte = 4,
            i = 0; // bit counter in X
        for ( ; i < bits; i++)
                {

                        current_xbit = get_bit (x, i);
                        tmp_byte = set_bit (tmp_byte, tmp_bit_counter++, current_xbit);
                        if (tmp_bit_counter == 8)
                        {
                                printf ("\t[");
                                print_bin (tmp_byte);
                                printf ("] Byte #%d: %x\n", current_byte--, tmp_byte);
                                tmp_byte = 0;
                                tmp_bit_counter = 0;

                        }
                }
}


int main () 
{
	int x = 0;

	printf ("Size of INT: %d bytes (%d bits)\nPlease enter number: ", bytes, bits);
	scanf ("%d", &x);
	
	
	print_bytes (x);
	
	int third;
	printf ("\nPlease enter byte (number in range 0..255) I will paste 3rd in X: ");
	scanf ("%d", &third); 
       	
	for (int i = 8, third_counter = 0; i != 16; i++)
		x = set_bit (x, i, get_bit (third, third_counter++) );

	print_bytes (x);

		
	return 0;
}
