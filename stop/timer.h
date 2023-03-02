#pragma once
#include <chrono>
// MY ADDITONAL HEADERS
#include <iostream>
#include <iomanip>
class Timer {
public:
    Timer() {
        _start_time = _current_time = _last_delta_tick = std::chrono::system_clock::now();
        _delta_time = std::chrono::duration<float>(0);
    }
    // restarts the start time to now, which basically resets the elapsed time count
    void Restart() {
        _start_time = _current_time = _last_delta_tick = std::chrono::system_clock::now();
    }
    // returns the amount of time since the last call to this function
    float GetDeltaTime() {
        _current_time = std::chrono::system_clock::now();
        _delta_time = _current_time - _last_delta_tick;
        _last_delta_tick = _current_time;
        return _delta_time.count();
    }  
    // returns the amount of time since last Restart
    float GetElapsedTime() {
        _current_time = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed_time = _current_time - _start_time;
        return elapsed_time.count();
    }
    // MY ADDITIONAL FUNCTIONS -----------------------------------------------------------
    void PrintTimeStamp(){
        std::cout << std::setw(5) << std::setprecision(5) << GetElapsedHours() << " : ";
        std::cout << std::setw(5) << std::setprecision(5) << GetElapsedMinutes() << " : ";
        std::cout << std::setw(5) << std::setprecision(5) << GetElapsedTime() << std::endl;
    }
    float GetElapsedMinutes (){
        float fl, fract, interger;
        fl = GetElapsedTime();
        fract = fl - (int)fl;
        interger = fl - fract; 
        return interger;
    }
    float GetElapsedHours (){
        return GetElapsedMinutes() / 60.0; 
    }
private:
    std::chrono::system_clock::time_point _start_time, _current_time, _last_delta_tick;
    std::chrono::duration<float> _delta_time;
    // MY ADDITIONAL VARIABLES -----------------------------------------------------------
};
