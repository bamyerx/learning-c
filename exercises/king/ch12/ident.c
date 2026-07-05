#define N 10

int main(void)
{
    double ident[N][N], *p;
    int zeros = N;
    
    for (p = *ident; p <= *ident + N + N; p++) {
        if (zeros == N) {
            *p = 1.0;
            zeros = 0;
        } else {
            *p = 0.0;
            zeros++;
    }
}
