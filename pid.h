#ifndef PID_H
#define PID_H

#include <stdbool.h>

typedef struct {
    double accumulator;
    double last;
    bool was_last;
    char pad[7];
} Pid;

void pid_start(Pid *pid);
double pid_output(Pid *pid, double feedback, double kp, double ki, double kd);

#endif // PID_H

