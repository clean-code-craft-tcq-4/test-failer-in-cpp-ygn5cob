#include <iostream>
#include <assert.h>

#define THRESHOLD 250

static int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius < THRESHOLD)
    return 200;
    else
    return 500;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount++;
        std::cout << alertFailureCount << " alertFailureCount \n";
    }
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount == 0);
    alertInCelcius(532.6);
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount == 1);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
