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
	pid_t pid = fork(); //se crea un proceso hijo asignandole su valor a una variable para luego identificar cual es cual

	// register the signals and the signal handler
	std::signal(SIGINT, signal_handler);/*ctrl+c*/
	std::signal(SIGTSTP, signal_handler);/*ctrl+z*/
	std::signal(SIGQUIT, signal_handler);/*ctrl+\*/

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
				/*no se hace nada ya que es par el numero*/
			}
		}
		else if (pid != 0)
		{
			int x = 0, y = 1, z = 1;
			//fibonacci
			if (count == 0)//si es el primer numero de la sucecion es 1 
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << " Valor Fibonacci: 1 - PPIDE = "<<getpid()<<std::endl;
			}
			else // si no es el primer numero se tiene que calcular el numero
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				for (int i = 0; i < count; i++)
				{
					z=x+y;
					x=y;
					y=z;
				}
				std::cout << "Valor Fibonacci: "<<z<<" - PPIDE = "<<getpid()<<std::endl;
			}
		}
		if (count == 50)// condicion de termino 
		{
			std::raise(SIGTERM);// señal de termino para el programa
		}
	}

	return EXIT_SUCCESS;
}
