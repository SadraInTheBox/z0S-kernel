#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067

double cos(double angle) {
    double radians = angle * PI / 180.0;
    
    double result = 1.0;
    double term = 1.0;
    int i;
    for (i = 1; i <= 10; i++) {
        term *= -1.0 * radians * radians / ((2 * i) * (2 * i - 1));
        result += term;
    }

    return result;
}

double sin(double angle) {
    double radians = angle * PI / 180.0;

    double result = radians;
    double term = radians;
    int i;
    for (i = 1; i <= 10; i++) {
        term *= -1.0 * radians * radians / ((2 * i + 1) * (2 * i));
        result += term;
    }

    return result;
}