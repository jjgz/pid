#include "pid.h"

void pid_start(Pid *pid) {
    pid->accumulator = 0.0;
    pid->was_last = false;
}

double pid_output(Pid *pid, double feedback, double kp, double ki, double kd) {
    pid->accumulator += feedback;
    if (pid->was_last) {
        double out = feedback * kp + pid->accumulator * ki + (feedback - pid->last) * kd;
        pid->last = feedback;
        return out;
    } else {
        double out = feedback * kp + pid->accumulator * ki;
        pid->last = feedback;
        pid->was_last = true;
        return out;
    }
}
