const char* Log(const char* message)
{
    return message;
}

int Multiply(int a, int b)
{
    Log("Multiply");
    return a*b;
}
//logmath.s   syntax-- g++ -S logmath.cpp
//logmath1.s  syntax-- g++ -S -O0 -g -masm=intel logmath.cpp -o logmath1.s
//logmath2.s  syntax-- g++ -S -masm=intel logmath.cpp -o logmath2.s