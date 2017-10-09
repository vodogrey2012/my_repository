char* my_strtok( char * string, const char * delim )
{
    static char *current;
    int i=0, j=0;
    if (string!=NULL)
        current=string;

    char* ret=current;
    for (i=0; current[i]!='\0'; i++)
    {
        for (j=0; delim[j]!='\0'; j++)
        {
            if (current[i]==delim[j])
            {
                current[i]='\0';
                current=current +i+1;
                return ret;
            }
        }
    }
    return NULL;
}
