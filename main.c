int main(int argc, char **argv)
{
    int fd;
    int ret;
    int line;
    char *buff;

    line = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((ret = get_next_line(fd, &buff)) > 0)
        {
            printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
            free(buff);
        }
        printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
        if (ret == -1)
            printf("-----------\nError\n");
        else if (ret == 0)
            printf("-----------\nEnd of file\n");
        if (close(fd) == -1)
            return (0);
    }
    if (argc == 1)
    {
        while ((ret = get_next_line(0, &buff)) > 0)
            printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
        if (ret == -1)
            printf("-----------\nError\n");
        else if (ret == 0)
            printf("-----------\nEnd of stdin\n");
        if (close(fd) == -1)
            if (close(fd) == -1)
                return (0);
    }
    return (0);
}
