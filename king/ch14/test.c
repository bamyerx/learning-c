#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

IDENT(foo)

int main(void)
{
	return 0;
}
