#### путь текущего каталога
	char *dir = NULL;
	dir = getcwd(NULL, 0);
	ft_putendl_fd(dir, 1);


#### поменять директорию
	if (chdir("sd") == 0)
	{
		getcwd(dir, NULL);
		ft_putendl_fd(dir, 1);
	}
	else
		ft_putendl_fd("no such file or directory:", 1);


#### копировать файл дискиптор fd в STDOUT_FILENO и сохранить в fd2
	fd2 = dup2(fd, STDOUT_FILENO);


#### execve - выполняет программу, заданную первым параметром. второй параметр - это массив строк, аргументов новой программы. третий параметр - это массив строк в формате key=value
	char *newargv[] = { "ping", "-c", "1", "google.com", NULL};
	if (execve("/sbin/ping", newargv, NULL) == -1)
	{
	 	ft_putendl_fd(strerror(errno), STDOUT_FILENO);
	 	return (2);
	}


#### подождать дочерний процесс и в зависимости от возвращенного значения вывести надпись
	int wstatus;
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			ft_putendl_fd("success", 1);
		else
			ft_putendl_fd("failure", 1);
	}

#### прервать дочерний процесс
	kill(pid, SIGKILL);
#### остановить дочерний процесс
	kill(pid, SIGSTOP);
#### продолжить дочерний процесс
	kill(pid, SIGCONT);

####  stat, lstat, fstat возвращают информацию об указанном файле stat возвращает информацию о файле file_name и заполняет буфер buf. lstat идентична stat, но в случае символьных сылок она возвращает информацию о самой ссылке, а не о файле, на который она указывает. fstat идентична stat, только возвращается информация об открытом файле, на который указывает filedes (возвращаемый open(2)), а не о file_name.
	struct stat buff;
	stat("includes/minishell.h", &buff);
	ft_putnbr_fd(buff.st_mode, 1); // выведет режим доступа

	int fd = open("includes/minishell.h", O_RDWR);
	fstat(fd, &buff);
	ft_putnbr_fd(buff.st_mode, 1); // выведет режим доступа

#### Нажатие Ctrl + C заставляет терминал послать сигнал SIGINT процессу, который на данный момент его контролирует. Когда foreground-программа получает сигнал SIGINT, она обязана прервать свою работу. Нажатие Ctrl + D говорит терминалу, что надо зарегистрировать так называемый EOF (end of file – конец файла), то есть поток ввода окончен. Bash интерпретирует это как желание выйти из программы. Пример перехвата сигнала Ctrl + C
	void handler_sigint(int sig)
	{
		(void)sig;
		ft_putendl_fd(" Ctrl + C not allowed", STDOUT_FILENO);
	}

	int	main(void)
	{
		signal(SIGINT, handler_sigint);

		char letter;
		read(STDIN_FILENO, &letter, 1);
		return (0);
	}

#### Коммуникация между процессами, используя сигналы (Если не вводить число, то через 3 секунды появится подсказка)
	int x = 0;

	void handler_sigusr1(int sig)
	{
		(void)sig;
		if (x == 0)
			puts("\n(HINT) Remember that multiplication is repetitive addition");
	}

	int main(void)
	{
			int pid = fork();
			if (pid == - 1)
				return (1);
			if (pid == 0)
			{
					sleep(3);
					kill(getppid(), SIGUSR1);
			}
			else
			{
					signal(SIGUSR1, handler_sigusr1);
					printf("What is the rusult of 3 * 5: ");
					scanf("%d", &x);
					if (x == 15)
						printf("Right\n");
					else
						printf("Wrong\n");
					wait(NULL);
			}
			return (0);
	}

#### Создание каналов для ввода и вывода (fd[0] - чтение, fd[1] - запись)
	int fd[2];
	if (pipe(fd) == -1)
		return (1);

#### Пересылка целочисленного массива от дочернего процесса родительскому с помощью pipe
	int	main(void)
	{
		int fd[2];
		if (pipe(fd) == -1)
			return (1);
		int pid = fork();
		if (pid == -1)
			return (2);
		if (pid == 0)
		{
			close(fd[0]);
			int n, i;
			int arr[10];
			srand(time(NULL));
			n = rand() % 10 + 1;
			printf("Generated: ");
			for (i = 0; i < n; i++)
			{
				arr[i] = rand() % 11;
				printf("%d ", arr[i]);
			}
			if (write(fd[1], &n, sizeof(int)) < 0)
				return (4);
			if (write(fd[1], arr, sizeof(int) * n) < 0)
				return (3);
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			int arr[10];
			int n, i;
			if (read(fd[0], &n, sizeof(int)) < 0)
				return (5);
			if (read(fd[0], arr, sizeof(int) *  n) < 0)
				return (6);
			close(fd[0]);
			int sum = 0;
			for (i = 0; i < n; i++)
			{
				sum += arr[i];
			}
			printf("\nSum = %d\n", sum);
			wait(NULL);
		}
		return (0);
	}

#### Пересылка строки от дочернего процесса родительскому с помощью pipe
	int fd[2];
	if (pipe(fd) == -1)
		return (1);
	int pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		close(fd[0]);
		char str[200];
		int len;
		printf("Input str: ");
		fgets(str, 200, stdin);
		len = ft_strlen(str);
		str[len - 1] = 0;
		if (write(fd[1], &len, sizeof(int)) < 0)
			return (3);
		if (write(fd[1], str,  sizeof(char) * (len + 1)) < 0)
			return (4);
		close(fd[1]);
		printf("Sent str: %s\n", str);
	}
	else
	{
		close(fd[1]);
		char str[200];
		int len;
		if (read(fd[0], &len, sizeof(int)) < 0)
			return (5);
		if (read(fd[0], str, sizeof(char) * (len + 1)) < 0)
			return (6);
		close(fd[0]);
		printf("Recived str: %s\n", str);
	}

#### Выполнение ping -c 3 google.com | grep round
	int fd[2];
	if (pipe(fd) == -1)
		return (1);

	int pid1 = fork();
	if (pid1 == -1)
		return (2);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		char *newargv[] = { "ping", "-c", "3", "google.com", NULL};
		close(fd[0]);
		if (execve("/sbin/ping", newargv, NULL) == -1)
		{
			ft_putendl_fd(strerror(errno), STDOUT_FILENO);
			return (3);
		}
		close(fd[1]);
	}

	int pid2 = fork();
	if (pid2 == -1)
		return (4);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		char *newargv[] = { "grep", "round", NULL};
		if (execve("/usr/bin/grep", newargv, NULL) == -1)
		{
			ft_putendl_fd(strerror(errno), STDOUT_FILENO);
			return (3);
		}
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
