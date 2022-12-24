#include "../include/Screen.h"

Screen::Screen() {
#if WIN32
    screen_size_.width = (int) GetSystemMetrics(SM_CXSCREEN);
    screen_size_.length = (int) GetSystemMetrics(SM_CYSCREEN);
#else
    screen_size_.width = (int) CGDisplayPixelsWide(CGMainDisplayID());
    screen_size_.length = (int) CGDisplayPixelsHigh(CGMainDisplayID());
#endif

    int window_width = BAR_WIDTH * VECTOR_SIZE;
    int window_length;

    if (screen_size_.length > 250) {
        window_length = screen_size_.length - 150;
    }
    else {
        window_length = screen_size_.length;
    }

    if (window_width > screen_size_.width) {
        throw std::invalid_argument("Computer screen size is too small!");
    }

    window_size_.width = window_width;
    window_size_.length = window_length;

    window_ = SDL_CreateWindow("Sorting Visualizer",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               window_size_.width, window_size_.length, SDL_WINDOW_SHOWN);

    renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_PRESENTVSYNC);
}

void Screen::DrawBackground(Colour background_colour) {
    SDL_Rect background;

    background.x = 0;
    background.y = 0;

    background.w = screen_size_.width;
    background.h = screen_size_.length;

    SDL_SetRenderDrawColor( renderer_, background_colour.r, background_colour.g,
                            background_colour.b, 255);

    SDL_RenderDrawRect(renderer_, &background);
    SDL_RenderFillRect( renderer_, &background);
}

void Screen::RenderFrame() {
    SDL_RenderPresent(renderer_);
}

void Screen::DrawBar(int x_position, int number, Colour bar_colour, Colour border_colour) {
    double multiplier = (double) window_size_.length / MAXIMUM_RANGE;

    SDL_Rect bar;

    bar.x = x_position * BAR_WIDTH;
    bar.y = window_size_.length - (int) (number * multiplier);

    bar.w = BAR_WIDTH;
    bar.h = (int) (number * multiplier);

    SDL_SetRenderDrawColor( renderer_, bar_colour.r, bar_colour.g,bar_colour.b, 255);
    SDL_RenderFillRect(renderer_, &bar);

    SDL_SetRenderDrawColor( renderer_, border_colour.r, border_colour.g, border_colour.b, 255);
    SDL_RenderDrawRect(renderer_, &bar);
}

void Screen::DrawFrame(std::vector<int> number_vector) {
    DrawBackground(background_colour_);

    for (int i = 0; i < number_vector.size(); i++) {
        DrawBar(i, number_vector[i], bar_colour_, border_colour_);
    }

    RenderFrame();
}

void Screen::DrawFrame(std::vector<int> number_vector, int x_highlight) {
    DrawBackground(background_colour_);

    for (int i = 0; i < number_vector.size(); i++) {
        if (i == x_highlight) {
            DrawBar(i, number_vector[i], bar_h1_colour_, bar_h1_colour_);
        }
        else {
            DrawBar(i, number_vector[i], bar_colour_, border_colour_);
        }
    }

    RenderFrame();
}

void Screen::DrawFrame(std::vector<int> number_vector, int x1_highlight, int x2_highlight) {
    DrawBackground(background_colour_);

    for (int i = 0; i < number_vector.size(); i++) {
        if (i == x1_highlight) {
            DrawBar(i, number_vector[i], bar_h1_colour_, bar_h1_colour_);
        }
        else if (i == x2_highlight) {
            DrawBar(i, number_vector[i], bar_h2_colour_, bar_h2_colour_);
        }
        else {
            DrawBar(i, number_vector[i], bar_colour_, border_colour_);
        }
    }

    RenderFrame();
}

void Screen::Delay(int ms) {
    SDL_Delay(ms);
}

void Screen::DrawVerificationFrame(std::vector<int> number_vector, int x_position) {
    DrawBackground(background_colour_);

    for (int i = 0; i < number_vector.size(); i++) {
        if (i <= x_position) {
            DrawBar(i, number_vector[i], correct_colour_, correct_colour_);
        }
        else {
            DrawBar(i, number_vector[i], bar_colour_, border_colour_);
        }
    }

    RenderFrame();
}
