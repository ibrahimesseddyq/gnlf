#include <iostream>
#include "config.h"

int main(int argc, char **argv) {
	std::cout << "Hello World" << std::endl;
	std::cout << "Version " << gnl_VERSION_MAJOR << "." << gnl_VERSION_MINOR << std::endl;
	return 0;
}
