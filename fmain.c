int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;
	asm ("mov %1, %0\n\t"
	 "add $3, %0"
	 : "=r" (fd)
	 : "r" (fd));
	switch (ac)
	{
	case 2:
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
		switch (errno)
		{
			case EACCES:
			exit(126);
			case ENOENT:
			_eputs(av[0]);
			_eputs(": 0: Can't open ");
			_eputs(av[1]);
			_eputchar('\n');
			_eputchar(BUF_FLUSH);
			exit(127);
			default:
			return (EXIT_FAILURE);
		}
		}
		info->read_fd = fd;
		break;
	}
	default:
		break;
	}
	generate_env_list(info);
	read_hist(info);
	loop_hsh(info, av);
	return (EXIT_SUCCESS);
}

