#include <iostream>
#include <thread>
#include <mutex>

std:: mutex outputMtx;

void countUp() {
	for (int count = 1; count<= 20; ++count) {
		std::lock_guard<std::mutex> lock(outputMtx);
		std::cout <<"Counting ascending: " << count << '\n';
	}
}

void countDown() {
	for (int count = 20; count>= 0; --count) {
		std::lock_guard<std::mutex> lock(outputMtx);
		std::cout <<"Counting descending: " << count <<'\n';
	}
}

int main() {
	std::thread threadA(countUp);
	threadA.join();

	std::thread threadB(countDown);
	threadB.join();

	std::cout << "Thread A and B have completed.\n";
	return 0;
}