#include <unistd.h> // for write function

/**
 * changeDirectory - changes the current directory of the process
 * @shellData: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int changeDirectory(info_t *shellData)
{
    char *currentDir, *newDir, buffer[1024];
    int chdirRet;

    currentDir = getcwd(buffer, 1024);
    if (!currentDir)
        write(STDOUT_FILENO, "TODO: >>getcwd failure emsg here<<\n", 34);
    if (!shellData->argv[1])
    {
        newDir = _getenv(shellData, "HOME=");
        if (!newDir)
            chdirRet = (chdirRet = chdir((newDir = _getenv(shellData, "PWD=")) ? newDir : "/"));
        else
            chdirRet = chdir(newDir);
    }
    else if (_strcmp(shellData->argv[1], "-") == 0)
    {
        if (!_getenv(shellData, "OLDPWD="))
        {
            write(STDOUT_FILENO, currentDir, _strlen(currentDir));
            write(STDOUT_FILENO, "\n", 1);
            return 1;
        }
        write(STDOUT_FILENO, _getenv(shellData, "OLDPWD="), _strlen(_getenv(shellData, "OLDPWD=")));
        write(STDOUT_FILENO, "\n", 1);
        chdirRet = (chdirRet = chdir((newDir = _getenv(shellData, "OLDPWD=")) ? newDir : "/"));
    }
    else
        chdirRet = chdir(shellData->argv[1]);
    if (chdirRet == -1)
    {
        write(STDERR_FILENO, "can't cd to ", 12);
        write(STDERR_FILENO, shellData->argv[1], _strlen(shellData->argv[1]));
        write(STDERR_FILENO, "\n", 1);
    }
    else
    {
        _setenv(shellData, "OLDPWD", _getenv(shellData, "PWD="));
        _setenv(shellData, "PWD", getcwd(buffer, 1024));
    }
    return 0;
}
