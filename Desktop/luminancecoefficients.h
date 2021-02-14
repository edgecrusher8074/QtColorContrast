#pragma once

class LuminanceCoefficients {
public:

    static double Red() { return 0.2126; }
    static double Green() { return 0.7152; }
    static double Blue() { return 0.0722; }

private:
    LuminanceCoefficients() {}
    ~LuminanceCoefficients() {}
};
