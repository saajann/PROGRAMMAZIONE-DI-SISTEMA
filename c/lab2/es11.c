#include <stdio.h>
#include <math.h>

#define SIZE 4

void compute_mean_variance(float *rmean, float *rvariance, float *values, unsigned size) {
    float sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += values[i];
    }
    float mean = sum / size;
    float dev = 0;
    for (unsigned i = 0; i < size; i++) {
        dev += powf(values[i]-mean,2);
    }
    *rmean = mean;
    *rvariance = dev / size;
}

int main () {
    float mean;
    float variance;
    float vals[SIZE] = {3,7,10,4};
    compute_mean_variance(&mean, &variance, vals, SIZE);
    printf("mean: %f\n", mean);
    printf("variance: %f\n", variance);
}