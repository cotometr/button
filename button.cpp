//
// Created by yura on 22.08.19.
//

#include "button.h"

Button::Button(const uint8_t button_pin, const int debounce_delay):
        m_button_pin(button_pin),
        m_debounce_delay(debounce_delay)
{
    pinMode(m_button_pin, INPUT);
}

void Button::set_handler(std::function<void()> handler)
{
    m_handler = handler;
}

void Button::poll()
{
    //read the state of the button
    int reading = digitalRead(m_button_pin);

    if (reading != m_last_button_state)
    {
        m_last_debounce_time = millis();
    }
    m_last_button_state = reading;

    if ((millis() - m_last_debounce_time) > m_debounce_delay )
    {
        if (m_button_state != reading)
        {
            m_button_state = reading;
            if (m_button_state == HIGH)
            {
                m_handler();
            }
        }
    }
}
