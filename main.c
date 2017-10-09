char * my_strncpy( char * destptr, const char * srcptr, size_t num )
{
    int i=0;

    for (i=0; ((destptr[i] != 0) && (srcptr[i] != 0) && (i<num)); i++)
        (destptr[i])=(srcptr[i]) ;

    destptr[i]=0;

    return destptr;
}
