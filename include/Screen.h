#ifndef SORTING_VISUALIZER_SCREEN_H
#define SORTING_VISUALIZER_SCREEN_H

#if WIN32
#include <windows.h>
#else
#include <CoreGraphics/CGDisplayConfiguration.h>
#endif

#include "Common.h"

class Screen {
private:
    Dimension screen_size_{};
    Dimension window_size_{};

    SDL_Renderer *renderer_{};
    SDL_Window *window_{};

    Colour bar_colour_ = {247,245,242};

    Colour bar_h1_colour_ = {230, 122, 122};
    Colour bar_h2_colour_ = {173, 162, 255};

    Colour correct_colour_ = {136, 164, 124};
//    Colour incorrect_colour_ = {220, 53, 53};

    Colour border_colour_ = {223,223,222};

    Colour background_colour_ = {49, 49, 49};

    void DrawBackground(Colour background_colour);
    void DrawBar(int x_position, int number, Colour bar_colour, Colour border_colour);
    void RenderFrame();
public:
    explicit Screen();

    void DrawFrame(std::vector<int> number_vector);
    void DrawFrame(std::vector<int> number_vector, int x_highlight);
    void DrawFrame(std::vector<int> number_vector, int x1_highlight, int x2_highlight);

    void DrawVerificationFrame(std::vector<int> number_vector, int x_position);

    static void Delay(int ms);
};


#endif
