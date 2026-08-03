/* calculates the inner product of a and b */
double inner_product(const double *a, const double *b, int n)
{
    double *p, *q, inner_product;

    for (p = a, q = b; a < p + n; p++, q++)
        inner_product += *p * *q;
    return inner_product;
}
