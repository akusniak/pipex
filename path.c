#include "pipex.h"

void    ft_path(t_path *path)
{
    path->envp = "/opt/homebrew/bin:/opt/homebrew/sbin:/Library/Frameworks/Python.framework/Versions/3.10/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin:/Users/axelkusniak/opt/anaconda3/bin:/Users/axelkusniak/opt/anaconda3/condabin:/opt/homebrew/bin:/opt/homebrew/sbin:/Library/Frameworks/Python.framework/Versions/3.10/bin/";
    path->clean = ft_split(path->envp, ':');
}