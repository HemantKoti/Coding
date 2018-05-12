/*
 * CommonBitOperations.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: HemantKo
 */

bool checkIfKthBitIsSet(unsigned A, int K) {
	return A & (1 << K - 1);
}

unsigned setKthBit(unsigned A, int K) {
	return A | (1 << K - 1);
}

unsigned clearKthBit(unsigned A, int K) {
	return A & ~(1 << K - 1);
}

unsigned toggleKthBit(unsigned A, int K) {
	return A ^ (1 << K - 1);
}

unsigned getTwosComplement(unsigned A) {
	return ~A + 1;
}

unsigned isolateRightMostOneBit(unsigned A) {
	return A & getTwosComplement(A);
}

unsigned isolateRightMostZeroBit(unsigned A) {
	return ~A & (A + 1);
}

bool checkIfPowerOfTwo(unsigned A) {
	return A == (~A + 1);
}
