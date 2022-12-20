

#include "include/libft.h"
#include "include/ft_printf.h"

int main(void)
{
    int n = 12;
    unsigned int u = -43;
    
    char *s = "tetere";
    char c = 'k';

    printf("%x dklkfughe %i ksdhglhg %s\n", n, u, s);
    ft_printf("%x dklkfughe %i ksdhglhg %c lksejhgkdjsfg %s \n", n, u, c, s);

return (0);
}