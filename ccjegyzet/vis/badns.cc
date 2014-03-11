#include <cstdio>

namespace foo
{
	int v = 0;
	
	namespace quux
	{
		int v = 1;
	}
}

namespace bar
{
	int v = 2;
	
	namespace foo
	{
		int v = 3;
	}
	
	void show()
	{
		// sima foo::quux::v-vel nem fordulna
		std::printf("%d %d %d\n", foo::v, ::foo::v, ::foo::quux::v);
	}
}

int main()
{
	std::printf("%d %d %d\n", foo::v, bar::v, bar::foo::v);
	bar::show();
	return 0;
}
