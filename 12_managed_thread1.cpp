// Uses a wrapper class for std::thread
// Ensures safe destruction when an exception is throw
#include <thread>
#include <iostream>

// The object created with this class is move-only object
// So the constructor need to move its argument into this object
class thread_guard{
	std::thread thr;

public:
	// Constructor takes rvalue reference argument (std::thread is move-only)
	explicit thread_guard(std::thread&& thr): thr(std::move(thr)){
	}

	// Destructor - join the thread if necessary
	~thread_guard(){
		if(thr.joinable())
			thr.join();
	}

	// Delete copy operators prevent copying
	thread_guard(const thread_guard&) = delete;
	thread_guard& operator=(const thread_guard&) = delete;

	// The move assignment operator is not synthesized
};

// Callable object - thread entry point
void hello()
{
	std::cout<<"Hello Thread"<<std::endl;
}

int main(){
	try{
		// we have the task function
		// We created the the thread in main
		std::thread thr(hello);

		// and then move it into a thread_guard object
		// So this thread_guard is now responsible for making sure that this thread gets terminated properly
		thread_guard tguard{std::move(thr)};

		//thread_guard rguard{std::thread(hello)};

		// Code which might throw an exception
		throw std::exception();

		// At some point the destructor will be called 
		// The thread_guard destructor will be called first and that will call join() if necessary
		// Then the thread member will be destroyed, and that does not need to call join()		

	}// Calls ~thread_guard followed by ~thread

	catch (std::exception& e){
		std::cout<<"Exception caught: " << e.what()<<std::endl;
	}
}