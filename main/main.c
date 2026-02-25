/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 4;
const int BTN_PIN = 28;

const int MOTOR_A = 18;
const int MOTOR_B = 19;
const int MOTOR_C = 20;
const int MOTOR_D = 21;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(MOTOR_A);
    gpio_set_dir(MOTOR_A, GPIO_OUT);
    gpio_init(MOTOR_B);
    gpio_set_dir(MOTOR_B, GPIO_OUT);
    gpio_init(MOTOR_C);
    gpio_set_dir(MOTOR_C, GPIO_OUT);
    gpio_init(MOTOR_D);
    gpio_set_dir(MOTOR_D, GPIO_OUT);

    
    while (true) {
        if (!gpio_get(BTN_PIN)) {
            gpio_put(LED_PIN, 1);

            for (int i = 0; i < 512; i++) {

            gpio_put(MOTOR_D, 1);
            sleep_ms(5);
            gpio_put(MOTOR_D, 0);

            gpio_put(MOTOR_C, 1);
            sleep_ms(5);
            gpio_put(MOTOR_C, 0);

            gpio_put(MOTOR_B, 1);
            sleep_ms(5);
            gpio_put(MOTOR_B, 0);

            gpio_put(MOTOR_A, 1);
            sleep_ms(5);
            gpio_put(MOTOR_A, 0);

            }
            gpio_put(LED_PIN, 0);
            
    }
}
}
