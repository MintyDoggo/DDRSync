#include <vector>

class CircularBuffer {
public:
    CircularBuffer();
    void write(float sample);
    float read(float rate);
    void setSizeSeconds(float seconds);
    void reset();

    std::vector<float> buffer;
private:
    size_t writePosition;
    float readPosition;
};