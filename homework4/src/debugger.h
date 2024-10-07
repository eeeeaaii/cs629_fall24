#include <vector>
#include "renderer/frame.h"

class Debugger {
private:
    int currentX;
    int currentY;
    float max;
    float min;
    bool debugged;
    bool found_out_of_range;
    std::vector<std::vector<float>> values;
    void print_value(int x, int y);
public:
    Debugger();
    void set_value(float v);
    void start_debug();
    void start_pixel(int x, int y);
    bool has_debug_info();
    float get_at(int x, int y);
    void print();
    void draw_debug_frame(Frame* frame);
};