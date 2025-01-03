#include "CircularBuffer.h"
#include <cmath>
#include "Utils.h"

CircularBuffer::CircularBuffer()
{
    buffer.resize(secondsToSamples(10));
    writePosition = 0;
    readPosition = 0;
}

void CircularBuffer::setSizeSeconds(float seconds)
{
    buffer.resize(secondsToSamples(seconds));
}

void CircularBuffer::write(float sample) {
    buffer[writePosition] = sample;
    writePosition = (writePosition + 1) % buffer.size();
}

void CircularBuffer::reset()
{
    writePosition = 0;
    readPosition = 0;
    // we could also clear the buffer here, but it's not worth it since read position will always go slower than write position in DDR training.
    // The main reason you don't want to do this is if this reset is called at the end of the buffer loop, it could take too long and cause a pop
}

float CircularBuffer::read(float rate) {
    // Calculate read position based on rate
    readPosition += rate;

    // Wrap read index to buffer size
    double wrappedIndex = wrapReadIndexToBuffer(readPosition, buffer.size());

    // Cast to int for array access
    int pos1 = static_cast<int>(wrappedIndex);
    int pos2 = (pos1 + 1) % buffer.size();

    // Return the sample at the wrapped position
    return buffer[pos1];
}