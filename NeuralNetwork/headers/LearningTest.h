//
// Created by alexandre on 17/12/2020.
//

#ifndef OCR_S3_LEARNINGTEST_H
#define OCR_S3_LEARNINGTEST_H

int testOnLetter(NeuralNetwork* network, int letter, int randPolice);
void testAllLetter(NeuralNetwork* network, size_t lowerBound, size_t upperBound);

#endif //OCR_S3_LEARNINGTEST_H
