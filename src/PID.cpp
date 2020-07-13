#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  i_error = 0;
  prevCTE = 0;
}

void PID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;
  d_error = cte - prevCTE;
  prevCTE = cte;
}

double PID::TotalError() {
  double totErr = -Kp * p_error - Ki * i_error - Kd * d_error;
  return totErr;
}