﻿#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
 public:
  Calculator();

  void CalculateCredit(int credit_sum, double credit_interest_rate,
                       int amount_of_months);

 private:
  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_months_;
};

#endif  // CALCULATOR_H
