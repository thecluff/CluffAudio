#include <iostream>
#include <cmath>
#include <cstdlib>
#include "processing.hpp"

int normalize(double *buffer, int length)
{
    double highestAmp = 0;
    for (int ndx = 0; ndx < length; ndx++)
    {
        if (fabs(buffer[ndx]) > highestAmp)
        {
            highestAmp = fabs(buffer[ndx]);
        }
    }
    // The normFac is 1.0/highestAmp
    double normFac = 1.0 / highestAmp;
    for (int ndx = 0; ndx < length; ndx++)
    {
        buffer[ndx] *= normFac;
    }
    return 0;
}

int gain(double *buffer, int length, double gainFac)
{
    for (int ndx = 0; ndx < length; ndx++)
    {
        buffer[ndx] *= gainFac;
    }
    return 0;
}

int clip(double *buffer, int length, double height)
{
    for (int ndx = 0; ndx < length; ndx++)
    {
        if (fabs(buffer[ndx]) > height)
        {
            if (buffer[ndx] < 0.0)
            {
                buffer[ndx] = -1.0 * height;
            }
            else
            {
                buffer[ndx] = height;
            }
        }
    }
    return 0;
}

int reverse(double *inBuf, double *outBuf, int length)
{
    // Copy from one buffer to the other and reverse
    for (int ndx = 0; ndx < length; ndx++)
    {
        outBuf[length - 1 - ndx] = inBuf[ndx];
    }
    return 0;
}

// This function will distort the output somewhat
int rectify(double *buffer, int length)
{
    // Force all negative sample values to be positive
    for (int ndx = 0; ndx < length; ndx++)
    {
        if (buffer[ndx] < 0)
        {
            buffer[ndx] *= 1.0;
        }
    }
    return 0;
}

int fadeIn(double *buffer, int SR, int nChnls, double fadeTime)
{
    int nSamps = SR * nChnls * fadeTime;

    for (int ndx = 0; ndx < nSamps; ndx++)
    {
        buffer[ndx] *= double(ndx) / nSamps;
    }
    return nSamps;
}

int fadeOut(double *buffer, int length, int SR, int nChnls, double fadeTime)
{
    int nSamps = SR * nChnls * fadeTime;

    for (int ndx = 0; ndx < nSamps; ndx++)
    {
        buffer[length - 1 - ndx] *= double(ndx) / nSamps;
    }

    return nSamps;
}

int stereoToMono(double *stereoBuf, int length, double *monoBuf) {
    // Mix a 2-channel signal down to one
    for(int ndx=0; ndx<length/2; ndx++) {
        monoBuf[ndx] = stereoBuf[ndx*2] * 0.5 + stereoBuf[ndx*2+1] * 0.5;
    }
    return 0;
}

int panMod(double *inBuf, int length, double *outBuf, int SR, double vco){
    // This only works with a mono signal
    // Make sure that outBuf is twice the length of inBuf
    // Cause the mono signal to periodically alternate between the two stereo channels
    // Smooth transition
    // This requires a vco or lfo
    double amp = 1.0, freq, phase = 0.0;
    double tr;

    freq = vco;
    for (int ndx = 0; ndx < length; ndx++)
    {
        freq = vco * ndx / length;
        tr = 0.5 + (amp * sin(freq * ndx * 2.0 * PI / SR + phase));
        // The even numbered samples are in one channel
        // One channels amplitudes go from 0-1
        outBuf[ndx * 2] = inBuf[ndx] * tr;
        // The odd numbered samples are in the other channel
        // The other channels amplitudes go from 1-0
        outBuf[ndx * 2 - 1] = inBuf[ndx] * (1.0 - tr);
    }

    return 0;
}

int ampMod(double *buffer, int length, int SR, double vco)
{
    double amp = 1.0, freq, phase = 0.0;
    double tr;
    for (int ndx = 0; ndx < length; ndx++)
    {
        freq = vco * ndx / length;
        // freq = vco;
        tr = amp * sin(freq * ndx * 2.0 * PI / SR + phase);
        buffer[ndx] = buffer[ndx] * tr;
    }
    return 0;
}

int pitchChange(double *buffer, int length, double originalPitch, double newPitch) {
    double resamplingRatio = newPitch / originalPitch;
    double *tempBuf;
    int counter = 0;
    const int tempBufLength = ((int) length/resamplingRatio+1);

    tempBuf = new double[tempBufLength];

    for(double ndx=0.0;ndx<length;ndx+=resamplingRatio) {
        tempBuf[counter++] = buffer[(int) ndx];
    }
    for(int ndx=0;ndx<length;ndx++) {
        if(ndx<counter) {
            buffer[ndx] = tempBuf[ndx];
        }
        else {
            buffer[ndx] = 0.0;
        }
    }
    return 0;
}

int extortion(double *buffer, int length, double height) {
    // Apply extreme gain
    gain(buffer, length, 30.0);
    // Clip if back to 0-1 range
    clip(buffer, length, height);
    return 0;
}

int waveShape (double *buffer, int length, double distortionFacPos, double distortionFacNeg) {
    // Distortion factors (range 0.2 - 5)
    for(int ndx=0;ndx<length; ndx++) {
        if(buffer[ndx]>=0.0) {
            // Positive sample values only
            buffer[ndx] = tanh(distortionFacPos*buffer[ndx]/tanh(distortionFacPos));
        }
        else {
            // Negative sample values only
            buffer[ndx] = tanh(distortionFacNeg*buffer[ndx]/tanh(distortionFacNeg));            
            }
        }
    return 0;
}

// Invert signal polarity (positive to negative, negative to positive)
int invert(double *buffer, int length)
{
    for (int ndx = 0; ndx < length; ndx++)
    {
        buffer[ndx] *= -1.0;
    }
    return 0;
}
