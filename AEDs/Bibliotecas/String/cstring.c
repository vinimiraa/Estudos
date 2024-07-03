#include "cstring.h"

int main ( void ) 
{
    char* s0 = NULL;
    char* s1 = "Vinicius Miranda Araujo";
    char* s2 = ", Vulgo Show";
    char** s3 = NULL;
    char* s4 = "9e3f7ce4-b9a7-4244-b709-dae5c1f1d4a8;Harry Potter;['The Boy Who Lived', 'The Chosen One', 'Undesirable No. 1', 'Potty'];Gryffindor;half-blood;human;stag;FALSO;VERDADEIRO;Daniel Radcliffe;VERDADEIRO;[];31-07-1980;1980;green;male;black;VERDADEIRO";
    char* s5 = "\r\t\n\t\r ABCDEFGH \n\r\t\n\r";
    char* s6 = "O rato roeu a roupa do rei de Roma.";

    printf("\n%s\n", "// -------------------- CSTRING TESTE -------------------- //");

    printf( "\n// --------------- STRINGS:\n" );

    printf( "\ns0 = \"%s\"", s0 );
    printf( "\ns1 = \"%s\"", s1 );
    printf( "\ns2 = \"%s\"", s2 );
    printf( "\ns4 = \"%s\"", s4 );
    printf( "\ns5 = \"%s\"", s5 );
    printf( "\ns6 = \"%s\"\n", s6 );

    printf( "\n// --------------- FUNCOES:\n" );

    printf( "\n%s\n", "Aperte ENTER para continuar!"); getchar( );

    printf("\nstr_len(s0) = %d\n", str_len(s0)); getchar( );
    printf("\nstr_len(s1) = %d\n", str_len(s1)); getchar( );

    printf("\nstr_charAt(s1, 5) = %c\n", str_charAt(s1, 5) ); getchar( );

    printf("\nstr_indexOf(s1, 'a') = %d\n", str_indexOf(s1, 'a') ); getchar( );

    printf("\nstr_lastIndexOf(s1, 'a') = %d\n", str_lastIndexOf(s1, 'a') ); getchar( );

    printf("\nstr_concat(s1, s2) = %s\n", str_concat(s1, s2) ); getchar( );

    printf("\nstr_substring(s1, 0, 10) = %s\n", str_substring(s1, 0, 10) ); getchar( );

    printf("\nstr_trim(s5) = %s\n", str_trim(s5) ); getchar( );

    printf("\nstr_replace_first(s6, 'o', '0') = %s\n", str_replace_c_first(s6, 'o', '0') ); getchar( );

    printf("\nstr_replace_last(s6, 'o', '0') = %s\n", str_replace_c_last(s6, 'o', '0')) ; getchar( );

    printf("\nstr_replace(s6, 'o', '0') = %s\n", str_replace_c(s6, 'o', '0') ); getchar( );

    s3 = str_split(s4, ';');

    printf("\ns3 = str_split(s4) :\n"); getchar( );
    int i = 0; 
    while( *(s3 + i) ) {
        printf("s3[%2d] = \"%s\"\n", i, s3[i]);
        i++;
    } // end while

    printf("\nstr_contains(s1, \"Miranda\") = %s\n", str_contains(s1, "Miranda") == true ? "true" : "false" ); getchar( );

    printf("\nstr_equals(s1, \"Vinicius Miranda Araujo\") = %s\n", str_equals(s1, "Vinicius Miranda Araujo") == true ? "true" : "false" ); getchar( );

    printf("\n%s\n", "// ---------------------- FIM TESTE ---------------------- //"); getchar( );

    return ( 0 );
} // end main ( )
