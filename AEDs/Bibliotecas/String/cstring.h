/*
 *  ----------------------------------------------------------------------------
 *  Biblioteca para Manipulação de Strings em C - "cstring.h"
 *  ----------------------------------------------------------------------------
*/

// --------------------------- Libs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

// --------------------------- Preprocessor

#ifndef __CSTRING_H__
#define __CSTRING_H__

// --------------------------- Prototypes

/**
 * @anchor flush
 * @brief Limpa o buffer de entrada padrão (stdin).
 */
void flush( void );

/**
 * @anchor str_read
 * @brief Lê uma string da entrada padrão (stdin).
 * 
 * @param _Size Tamanho máximo da string a ser lida.
 * @return Ponteiro para a string lida (alocada dinamicamente) ou NULL se houver um erro de alocação.
 */
char* str_read ( size_t _Size );

/**
 * @anchor str_len
 * @brief Retorna o tamanho da string.
 * 
 * @param _Str String de entrada.
 * @return Tamanho da string (número de caracteres) ou -1 se _Str for NULL.
 */
int str_len ( const char *_Str );

/**
 * @anchor str_charAt
 * @brief Retorna o caractere na posição específica da string.
 * 
 * @param _Str String de entrada.
 * @param _Index Índice do caractere desejado.
 * @return Caractere na posição especificada ou 0 se _Str for NULL ou _Index estiver fora dos limites.
 */
char str_charAt ( const char *_Str, const int _Index );

/**
 * @anchor str_indexOf
 * @brief Retorna o índice da primeira ocorrência de _Char em _Str.
 * 
 * @param _Str String de entrada.
 * @param _Char Caractere a ser procurado.
 * @return Índice da primeira ocorrência de _Char em _Str ou -1 se _Str for NULL ou _Char não for encontrado.
 */
int str_indexOf ( const char *_Str, const char _Char );

/**
 * @anchor str_lastIndexOf
 * @brief Retorna o índice da última ocorrência de _Char em _Str.
 * 
 * @param _Str String de entrada.
 * @param _Char Caractere a ser procurado.
 * @return Índice da última ocorrência de _Char em _Str ou -1 se _Str for NULL ou _Char não for encontrado.
 */
int str_lastIndexOf ( const char *_Str, const char _Char );

/**
 * @anchor str_concat
 * @brief Concatena duas strings _Str1 e _Str2 em uma nova string alocada dinamicamente.
 * 
 * @param _Str1 Primeira string de entrada.
 * @param _Str2 Segunda string de entrada.
 * @return Ponteiro para a string resultante da concatenação ou NULL se houver um erro de alocação.
 */
char* str_concat ( const char *_Str1, const char *_Str2 );

/**
 * @anchor str_substring
 * @brief Retorna uma substring de _Str, começando em _Start até _End (inclusive).
 * 
 * @param _Str String de entrada.
 * @param _Start Índice inicial da substring.
 * @param _End Índice final da substring.
 * @return Ponteiro para a substring alocada dinamicamente ou NULL se _Str for NULL ou houver um erro de alocação.
 */
char* str_substring ( const char *_Str, size_t _Start, size_t _End );

/**
 * @anchor str_trim
 * @brief Remove espaços em branco, tabulações, novas linhas e retorno de carro à direita e à esquerda de _Str.
 * 
 * @param _Str String de entrada e saída.
 * @return Ponteiro para a string resultante da remoção dos espaços em branco ou NULL se _Str for NULL ou houver um erro de alocação.
 */
char* str_trim ( char *_Str );

/**
 * @anchor str_split
 * @brief Divide a string _Str em um array de strings utilizando o caractere delimitador _Delimiter.
 * 
 * @param _Str String a ser dividida.
 * @param _Delimiter Caractere delimitador.
 * @return Array de strings resultante da divisão ou NULL se houver um erro de alocação.
 */
char** str_split ( char *_Str, const char _Delimiter );

/**
 * @anchor str_dup 
 * @brief Retorna uma cópia alocada dinamicamente de _Str.
 * 
 * @param _Str String de entrada.
 * @return Ponteiro para a cópia de _Str ou NULL se _Str for NULL ou houver um erro de alocação.
 */
char* str_dup(const char *_Str);

/**
 * @anchor str_replace_c
 * @brief Substitui todas as ocorrências de _OldChar por _NewChar em _Str.
 * 
 * @param _Str String de entrada e saída.
 * @param _OldChar Caractere a ser substituído.
 * @param _NewChar Caractere substituto.
 * @return Ponteiro para a string resultante da substituição ou NULL se houver um erro de alocação.
 */
char* str_replace_c ( const char *_Str, const char _OldChar, const char _NewChar );

/**
 * @anchor str_replace_c_first
 * @brief Substitui a primeira ocorrência de _OldChar por _NewChar em _Str.
 * 
 * @param _Str String de entrada e saída.
 * @param _OldChar Caractere a ser substituído.
 * @param _NewChar Caractere substituto.
 * @return Ponteiro para a string resultante da substituição ou NULL se houver um erro de alocação.
 */
char* str_replace_c_first ( const char *_Str, const char _OldChar, const char _NewChar );

/**
 * @anchor str_replace_c_last
 * @brief Substitui a última ocorrência de _OldChar por _NewChar em _Str.
 * 
 * @param _Str String de entrada e saída.
 * @param _OldChar Caractere a ser substituído.
 * @param _NewChar Caractere substituto.
 * @return Ponteiro para a string resultante da substituição ou NULL se houver um erro de alocação.
 */
char* str_replace_c_last ( const char *_Str, const char _OldChar, const char _NewChar );

/**
 * @anchor str_contains
 * @brief Verifica se _Str contém a substring _Src.
 * 
 * @param _Str String de entrada.
 * @param _Src Substring a ser procurada.
 * @return true se _Str contém _Src, false caso contrário ou se _Str ou _Src forem NULL.
 */
bool str_contains ( const char *_Str, const char *_Src );

/**
 * @anchor str_equals
 * @brief Compara duas strings _Str1 e _Str2.
 * 
 * @param _Str1 Primeira string de entrada.
 * @param _Str2 Segunda string de entrada.
 * @return true se _Str1 é igual a _Str2, false caso contrário ou se _Str1 ou _Str2 forem NULL.
 */
bool str_equals ( const char *_Str1, const char *_Str2 );

#endif // __CSTRING_H__
