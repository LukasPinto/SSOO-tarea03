#include <global.hh>

#include <unistd.h>

void signal_handler(int signal_num)
{
	std::cout<<"Detención no permitida"<<std::endl;
	/* función  que atrapa las señales*/
}

int main(int argc, char *argv[])
{
	int count = 0;
	pid_t pid = fork();

	// register the signals and the signal handler
	std::signal(SIGTERM, signal_handler);
	std::signal(SIGINT, signal_handler);
	std::signal(SIGTSTP, signal_handler);
	std::signal(SIGQUIT, signal_handler);

	while (++count)
	{
		if (pid == 0)
		{ //numeros impar
			//std::cout << "soy el proce hijo :" << getpid() << std::endl;
			if (count % 2 != 0)
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "Valor Impar: " << count <<" - PID = "<<getpid()<< std::endl;
			}
			else
			{
				/*no hacer nada*/
			}
		}
		else if (pid != 0)
		{
			int x = 0, y = 1, z = 1;
			//fibonacci
			if (count == 0)
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << " Valor Fibonacci: 1 - PPDIDE = "<<getpid()<<std::endl;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				for (int i = 0; i < count; i++)
				{
					z=x+y;
					x=y;
					y=z;
				}
				std::cout << "Valor Fibonacci: "<<z<<" - PPDIDE = "<<getpid()<<std::endl;
			}

			//std::cout << "soy el proce padre :" << getpid() << std::endl;
		}
		
		//std::cout << "Hello ... PID=" << getpid() << std::endl;
		if (count == 50)// condicion de termino 
		{
			std::raise(SIGTERM);// señal de termino para el programa
		}
	}

	return EXIT_SUCCESS;
}
