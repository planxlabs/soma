#include <stdio.h>
#include <stdbool.h>
#include "thread.h"

int gpio_pin_direct_reg; //0: out, 1: in
int gpio_pin_1_out_value_reg;
int gpio_pin_1_in_value_reg;

void gpio_pin_1_in() 
{ 
    fprintf(stderr, "[IN:%d]", gpio_pin_1_in_value_reg);
}

void gpio_pin_1_out() 
{ 
    fprintf(stderr, "[OUT:%d]", gpio_pin_1_out_value_reg);    
}

void* gpio_pin_1(void* unuse)
{
    while (true) {
         if (gpio_pin_direct_reg) { //in
            gpio_pin_1_in();
         }
         else { //out
            gpio_pin_1_out();
         }
    }
}

int main()
{
    thread_create(gpio_pin_1, 0);
    while (true) {
        int d, n;
        scanf("%d", &d);  //select direction: 0(out), 1(in)
        gpio_pin_direct_reg = d;
        scanf("%d", &n);
        if (d) { //in
            gpio_pin_1_in_value_reg = n;
        }
        else { //out
            gpio_pin_1_out_value_reg = n;
        }
    }
}