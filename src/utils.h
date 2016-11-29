/*
 * utils.h
 *
 *  Created on: 29 lis 2016
 *      Author: Artur Kucia
 */

#ifndef UTILS_H_
#define UTILS_H_

/**	generates random variable x from distribution:
 * 	B(x) = 0.5 N1(1,sqrt(1/3)) + 0.5 N2(-1,sqrt(1/3)) *
 * @return x random number from B(x)
 */
double getMixGaussian();

/** generates sample dataset using getMixGaussian()
 * 	saves the histogram in pdf file
 * @param sampleSize number of samples
 * @param filename output file with plotted histogram
 */
void generateSample(const int sampleSize, const char* filename);

#endif /* UTILS_H_ */
