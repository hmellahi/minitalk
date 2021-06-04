#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
typedef char*	t_string;

char	*str_join(char *s1, char s2);
int		ft_strlen(char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char *s1, char *s2, t_string index);
char	*ft_strdup(char *src);

#endif
