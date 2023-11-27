#include <iostream>

class ArithmeticOperation {
public:
    virtual double calculate(double x, double y) = 0;
    virtual ~ArithmeticOperation() {}
};

class Addition : public ArithmeticOperation {
public:
    double calculate(double x, double y) override {
        return x + y;
    }
};

class Multiplication : public ArithmeticOperation {
public:
    double calculate(double x, double y) override {
        return x * y;
    }
};

int main() {
    ArithmeticOperation* op;

    op = new Addition();
    std::cout << "Addition: 5 + 3 = " << op->calculate(5, 3) << std::endl;
    delete op;

    op = new Multiplication();
    std::cout << "Multiplication: 5 * 3 = " << op->calculate(5, 3) << std::endl;
    delete op;

    return 0;
}
