/*
 * NChooseR.cpp
 *
 *  Created on: Apr 8, 2018
 *      Author: HemantKo
 */

#include "../InterviewBit.h"

uint64_t choose(int n, int r) {
	std::uint64_t ans = 1;
	r = min(r, n - r);

	for (int j = 1; j <= r; j++, n--) {
		// All following do: ans = (ans * n) / j;
		// But the 2 first cases do some simplifications
		// To reduce the possibility of overflow
		if (n % j == 0) {
			ans *= n / j;
		} else if (ans % j == 0) {
			ans = (ans / j) * n;
		} else {
			ans = (ans * n) / j;
		}
	}
	return ans;
}
