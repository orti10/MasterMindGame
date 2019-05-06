/**
 * A demo program for bull-pgia.
 * 
 * @author Ortal and Tomer
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"}, c1111{"1111"} ,c12{"12"},c21039{"21039"},c1{"1"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"}, g1111{"1111"} ,g12{"12"},g21039{"21039"},g1{"1"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

	//our test
	testcase.setname("victory")
	.CHECK_OUTPUT(calculateBullAndPgia("1010","1010"),"4,0")
	.CHECK_OUTPUT(calculateBullAndPgia("222","222"),"3,0")
	.CHECK_OUTPUT(calculateBullAndPgia("17","17"),"2,0")
	.CHECK_OUTPUT(calculateBullAndPgia("11111","11111"),"5,0")
	.CHECK_OUTPUT(calculateBullAndPgia("3","3"),"1,0")
	.CHECK_OUTPUT(calculateBullAndPgia("123456","123456"),"6,0")
	.CHECK_OUTPUT(calculateBullAndPgia("123456789","123456789"),"9,0")
;
	testcase.setname("same length diffrent numbers")
	.CHECK_OUTPUT(calculateBullAndPgia("1011","1010"),"3,0")
	.CHECK_OUTPUT(calculateBullAndPgia("123","301"),"0,2")
	.CHECK_OUTPUT(calculateBullAndPgia("71","17"),"0,2")
	.CHECK_OUTPUT(calculateBullAndPgia("2341324","9876348"),"1,1")
	.CHECK_OUTPUT(calculateBullAndPgia("5","3"),"0,0")
	.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"),"0,4")
	.CHECK_OUTPUT(calculateBullAndPgia("123456789","195864732"),"2,7")
;
	testcase.setname("Play function")
	.CHECK_EQUAL(play(c1111,g1111,4,10),1)
	.CHECK_EQUAL(play(c1234,g1234,4,100),1)
	.CHECK_EQUAL(play(c12,g12,2,3),1)
	.CHECK_EQUAL(play(c21039,g21039,5,200),1)
	.CHECK_EQUAL(play(c1,g1,1,9),1)

;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<400; ++i) {
			// smarty should always win in at most 10 turns!
			cout <<i<<endl;
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true); 
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}