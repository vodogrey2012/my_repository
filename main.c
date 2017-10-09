char * my_strstr( const char * string1, const char * string2 )
{
    size_t len1=0;
    for (len1=0; string1[len1]!=0; len1++);

    size_t len2=0;
    for (len2=0; string2[len2]!='\0'; len2++);

    int i=0, j=0;

    for (i=0; i<=(len1-len2); i++)
    {
        for (j=0; (j<len2) && (string1[j+i]==string2[j]); j++);

        if (j==len2) return string1+i;
    }

    return NULL;
}
