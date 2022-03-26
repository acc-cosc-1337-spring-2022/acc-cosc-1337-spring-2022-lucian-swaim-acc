//write include statements 
#include <string>
using std::string;


/*
Write code for void function display_vector that accepts parameter const reference vector of strings.
The function will iterate through the vector and display a string per line.
*/


/*
Write code for void function update_vector_element that accepts parameter reference vector of strings,
a string vector search_value, and a string replace_value.
The function will iterate through the vector and search for the search_value and if found will
replace the vector element with the replace_value.
*/




// write code for functions get_gc_content, get_reverse_string, and get_dna_complement


double get_gc_content ( const string& dna ) 
{
    double gc_counter = 0.0;

    for (int pos = 0; pos < dna.size(); pos++) {

        if ((dna[pos] == 'G') || (dna[pos] == 'C'))
        {
            gc_counter++;
        }
    }

    return ( gc_counter / dna.size() );
}


string reverse_string ( string dna ) 
{

    string flipped_string = "";

    for (int pos = (dna.size() - 1); pos >= 0; pos--) {
        
        flipped_string += dna[pos];
    }

    return flipped_string;
}


string get_dna_complement ( string dna ) 
{

    string flipdna = reverse_string(dna);


    string complement_dna = "";

    for (int pos = 0; pos < dna.size(); pos++) {

        if      (flipdna[pos] == 'A') {
            complement_dna += "T";
        }
        else if (flipdna[pos] == 'T') {
            complement_dna += "A";
        }
        else if (flipdna[pos] == 'C') {
            complement_dna += "G";
        }
        else if (flipdna[pos] == 'G') {
            complement_dna += "C";
        }
    }

    return complement_dna;

}


// Returns true if the string is acceptable
bool validate_dna_string (const string& dna) {

    bool valid = true;

    for (int pos = 0; pos < dna.size(); pos++)
    {
        if ( (dna[pos] != 'A') && (dna[pos] != 'T') && (dna[pos] != 'G') && (dna[pos] != 'C') )
        {
            valid = false;
        }
    }
    
    return valid;
}
