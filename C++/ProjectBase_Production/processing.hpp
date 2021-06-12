#include <iostream>
#include <cmath>
#include <cstdlib>

#ifndef PROCESSING_HPP_
#define PROCESSING_HPP_
const double PI = 4.0 * atan(1.0);

int gain(double *buffer, int length, double gainFac);

int normalize(double *buffer, int length);

int rectify(double *buffer, int length);

int reverse(double *inBuf, double *outBuf, int length);

int invert(double *inBuf, double *outBuf, int length);

int clip(double *buffer, int length, double height);

int fadeIn(double *buffer, int SR, int nChnls, double fadeTime);

int fadeIn(double *buffer, int length, int SR, int nChnls, double fadeTime);

int ampMod(double *buffer, int length, int SR, double vco);

int panMod(double *inBuf, int length, double *outBuf, int SR, double vco);

int stereoToMono(double *stereoBuf, int length, double *monoBuf);

#endif /* PROCESSING.HPP */