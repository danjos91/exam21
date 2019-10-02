//
// Created by danny on 03.10.2019.
//
#include <unistd.h>

int start(char c)//reconocemos los simbolos que abren
{
    if (c == '(' || c == '[' ||c == '{')
        return (1);
    return (0);
}

int end(char c)//reconocemos los simbolos que cierran
{
    if (c == ')' || c == ']' || c == '}')
        return (1);
    return (0);
}

int test(char s1, char s2)// reconocemos que cuando se encuentra un simbolo de cierre, el ultimo guardado debe ser su correspondiente que abre
{
    if ((s1 == '(' && s2 == ')') || (s1 == '[' && s2 == ']') || (s1 == '{' && s2 == '}'))
        return (1);
    return (0);
}

int brackets(char *s)//aqui pasa la magia
{
    int i;
    int j;
    char top[512];//este programa acepta hasta 512 posibles variantes a evaluar

    i = 0;
    j = -1;//menos uno porque usamos aumento inmediato, eso quiere decir que el primer elemento usado sera 0 y no -1
    while (s[i] != '\0')//pasamos por cada elemento del string
    {
        if (start(s[i]))//si encontramos un simbolo que abre
        {
            top[++j] = s[i];//lo guardamos en top
        }
        else if (end(s[i]))//si no encontramos un simbolo que abre, revisamos si es simbolo que cierra
        {
            if (!test(top[j], s[i]))//si es simbolo que cierra, revisamos si corresponde al ultimo simbolo que abre con la ayuda de test
                return (0);//si no corresponte regresamos 0
            else
                j--;//y si corresponde regresamos un puesto en top, ya que acabamos de revisar el actual
        }
        i++;//todo ese procedimiento fue para un simbolo, pero tenemos que evaluar cada uno
    }
    if (j != -1)//al final de todo j deberia volver a su valor original de -1 si todo esta bien
        return (0);// y si no ha vuelto a su valor original, entonces regresamos cero
    return (1);//al final si todo el proceso se completo y j es -1, quiere decir que todo esta bien, y regresamos 1
}

int main(int ac, char **ag)
{
    int i;

    i = 1;
    if (ac == 1)
        write(1, "\n", 1);
    else
    {
        while (i < ac)//usamos todos los argumentos excluyendo al primero y el ultimo
        {
            if (brackets(ag[i]))//si existe, osea iugal a 1, es OK, y si no existe, osea es 0, regresamos Error
            {
                write(1, "OK\n", 3);
            }
            else
                write(1, "Error\n", 6);
            i++;//y asi para cada elemento en ag
        }
    }
    return (0);
}
