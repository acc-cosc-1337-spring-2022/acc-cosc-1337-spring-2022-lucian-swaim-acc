#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "sequence.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Test function get_gc_content") {
	REQUIRE(get_gc_content("AGCTATAG") == .375);
	REQUIRE(get_gc_content("CGCTATAG") == .50);
}

TEST_CASE("Test function reverse_string") {
	REQUIRE(reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(reverse_string("CGCTATAG") == "GATATCGC");
}

TEST_CASE("Test function get_dna_complement") {
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
}

TEST_CASE("Test function validate_dna_string") {
	REQUIRE(validate_dna_string("AAAACCCGGT") == true);
	REQUIRE(validate_dna_string("CCCGGAAAAT") == true);
	REQUIRE(validate_dna_string("AGCTATAG") == true);
	REQUIRE(validate_dna_string("CGCTATAG") == true);
	REQUIRE(validate_dna_string("badAGCTuserTGACinput") == false);
	REQUIRE(validate_dna_string("aaaacccggt") == false);
	REQUIRE(validate_dna_string("cccggaaaat") == false);
	REQUIRE(validate_dna_string("agctatag") == false);
	REQUIRE(validate_dna_string("cgctatag") == false);
}