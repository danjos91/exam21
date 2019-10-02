#include <unistd.h>
// tenemos un int *tab que contiene varios numeros, lo que tenemos que hacer es
// escribir la memoria que ocupan asi como en el ejemplo, para cada cifra hay 8 bytes,
//y 4 simbolos que se pueden escribir, si el numero no corresponde a un simbolo, entonces
// ponemos un punto.
/*
 * ft_hex usamos para transformar en hexadecimal
 */
void ft_putchar(char c)//lo uso para no estar escribiendo write a cada momento
{
    write(1, &c, 1) ;
}

void print_hex(int c)
{
    char hex[] = "0123456789abcdef";
    ft_putchar(hex[c / 16]);
    ft_putchar( hex[c % 16]);//transformamos un numero decimal en hexadecimal
}

void	print_char(int c)//se imprime . si el numero no corresponde a ningun simbolo en la tabla decimal ascii
{
    if (c >= 32 && c <= 126)
        ft_putchar(c);
    else
        ft_putchar('.');
}

void print_memory(const void *addr, size_t size)
{
    size_t i;
    size_t j;
    unsigned char *ptr;

    i = 0;
    ptr = (unsigned char *)addr;
    while (i < size)//i va recorriendo cada uno de los 4 bytes que tiene un int, size nos da el numero completo de bytes
    {
        j = 0; //siempre haces que j sea igual a cero
        while (j < 16 && j + i < size)// si j + i ya es igual a size significa que ya pasamos por todos los bytes
        {
            print_hex(ptr[j + i]);
            if (j % 2)
                ft_putchar(' ');
            j++;//aunmentamos j en cada ciclo de 16 y son 2 ciclos principales. hex y char
        }
        while (j < 16)//aquie escribimos los espacios faltantes en caso de que sea necesario si en el codigo anterior j no llego a 16
        {
            write(1, "  ", 2);
            if (j % 2)
                ft_putchar(' ');
            j++;
        }
        j = 0;
        while (j < 16 && j + i < size)//despues de cada ciclo de 16, repetimos otro ciclo para los simbolos tambien de 16
        {
            print_char(ptr[j + i]);//imprime un punto si el numero no corresponde a ningun simbolo
            j++;
        }
        i += 16;//i indica el numero de bytes, ya pasamos 16, necesitamos continuar con los 16 siguientes
        ft_putchar('\n');// luego de los 2 ciclos de 16, insertamos una nueva linea
    }
}

int	main(void)
{
    int	tab[10] = {0, 23, 150, 255,
                      12, 16,  21, 42};

    print_memory(tab, sizeof(tab));
    return (0);
}
