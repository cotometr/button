//
// Created by yura on 22.08.19.
//

#pragma once

#include <functional>
#include <USBAPI.h>

class Button
{
public:
    /**
     * @brief Create object and init pin
     * @param button_pin
     * @param debounce_delay How much time the button should be pressed in ms
     */
    Button(const uint8_t button_pin, const int debounce_delay);

    /**
     * @brief Set button press handle
     * @param handler
     */
    void set_handler(std::function<void()> handler);

    /**
     * @brief Poll in loop
     */
    void poll();

private:
    const uint8_t m_button_pin;

    const int m_debounce_delay;

    // the current reading from the input
    int m_button_state = LOW;

    // the previous reading from the input pin
    int m_last_button_state = LOW;

    // the last time the output pin was toggled
    unsigned long m_last_debounce_time = 0;

    std::function<void()> m_handler;
};
