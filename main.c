char * my_strncat( char * destptr, char * srcptr, size_t num )
{
    size_t len=0, j=0;
    for (len=0; destptr[len]!=0; len++);

    for(j=0; j<num; j++)
        destptr[len+j]=srcptr[j];

    destptr[len+j]=0;

    return destptr;
}
