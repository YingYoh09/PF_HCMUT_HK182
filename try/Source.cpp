#include <iostream>
#include <iomanip>

struct temp
{
	int tmp;
};
void st(temp *s)
{
	std::cout << s->tmp;
}

using namespace std;
int main(int argc, char* argv[])
{
	system("pause");
}
