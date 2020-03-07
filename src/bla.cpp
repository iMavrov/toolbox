#include "string.h"
#include "stdio.h"

#include "math_constants.hpp"
#include "math_utils.hpp"
#include "vector2d.hpp"
#include "matrix2d.hpp"
#include "sampling_utils.hpp"

using namespace toolbox;

int main(int argc, const char *argv[]) {

	const int BUCKET_COUNT = 512;
	int histogram[BUCKET_COUNT];
	memset(histogram, 0, sizeof(float) * BUCKET_COUNT);

	const int SAMPLE_COUNT = 1000 * 1000;
	SampleGenerator generator(0x20181216);
	for (int i = 0; i < SAMPLE_COUNT; ++i) {
		float normalSample = generator.getNormalSample().x;
		int sampleIndex = static_cast<int>(normalSample * BUCKET_COUNT);
		if (-1 < sampleIndex && sampleIndex < BUCKET_COUNT) {
			++histogram[sampleIndex];
		}
	}

	for (int i = 0; i < BUCKET_COUNT; ++i) {
		printf("%d,%d\n", i, histogram[i]);
	}

	return 0;
}
