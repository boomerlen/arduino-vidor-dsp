// hello_world.c
//
// Test program to ensure we are able to communicate with the Arduino MKR Vidor SAMD21 chip
//
// File created: 1/1/2024 by HS

int main() {
    int total = 0;
    for (int i = 0; i < 2000; i++) {
        total += i;
    }

    return 0;
}