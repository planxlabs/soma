# structured programming
**calc_data.h**
```c
#ifndef _CACL_DATA_H_
#define _CACL_DATA_H_

typedef struct _calc_data {
    float opd1;
    char op;
    float opd2;
} calc_data_t;

#endif
```
**input.h**
```c
#ifndef _INPUT_H_
#define _INPUT_H_

#include "calc_data.h"

void input(calc_data_t *cd);

#endif
```

**input.c**
```c
#include <stdio.h>
#include "input.h"

void input(calc_data_t *cd)
{
    scanf("%f %c %f", &cd->opd1, &cd->op, &cd->opd2);
}
```

**process.h**
```c
#ifndef _PROCESS_H_
#define _PROCESS_H_

#include "calc_data.h"

float process(calc_data_t cd);

#endif
```

**process.c**
```c
#include "process.h"

float process(calc_data_t cd)
{
    float result;
    
    switch (cd.op) {
        case '+':
            result = cd.opd1 + cd.opd2;
        break;
        case '-':
            result = cd.opd1 - cd.opd2;       
        break;
        case '*':
            result = cd.opd1 * cd.opd2;               
        break;
        case '/':
            result = cd.opd1 / cd.opd2;               
        break;
    }

    return result;
}
```

**calc.c**
```c
#include "input.h"
#include "process.h"
#include "output.h"
#include "calc_data.h"

int main(void)
{
    calc_data_t cd;
    float result;

    input(&cd);
    result = process(cd);
    output(cd, result);

    return 0;
}
```
