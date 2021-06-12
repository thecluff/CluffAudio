#include <cmath>

#ifndef PROCESSING_HPP_
#define PROCESSING_HPP_
const double PI = 4.0 * atan(1.0);


int normalize(double *buffer, int length);

int gain(double *buffer, int length, double gainFac);

int clip(double *buffer, int length, double height);

int reverse(double *inBuf, double *outBuf, int length);

int rectify(double *buffer, int length);

int fadeIn(double *buffer, int SR, int nChnls, double fadeTime);

int fadeOut(double *buffer, int length, int SR, int nChnls, double fadeTime);

int stereoToMono(double *stereoBuf, int length, double *monoBuf);

int ampMod(double *buffer, int length, int SR, double vco);

int panMod(double *inBuf, int length, double *outBuf, int SR, double vco);

int pitchChange(double *buffer, int length, double originalPitch, double newPitch);

int extortion(double *buffer, int length, double height);

int waveShape (double *buffer, int length, double distortionFacPos, double distortionFacNeg);

int invert(double *buffer, int length);

#endif /* PROCESSING.HPP */