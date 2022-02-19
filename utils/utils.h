/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:35:20 by ldatilio          #+#    #+#             */
/*   Updated: 2022/02/17 19:48:57 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

/**	@brief	Set n bytes of s to 0.
 *	@param	s Pointer to the start of the memory location
 *	@param	n Buffer size */
void	ft_bzero(void *s, size_t n);

/**	@brief 	Allocates memory for an array of nmemb elements of size bytes each
 *			and returns a pointer to the allocated memory. The memory
 * 			is set to zero.
 *	@param	nmemb	Number of elements in array
 *	@param	size	Size of bytes for each element
 *	@return	void* Return a pointer to the allocated memory,
 *			which is suitably aligned for any built-in
 * 			type. On error, these functions return NULL. NULL may also
 * 			be returned by a successful call but with size 0. */
void	*ft_calloc(size_t nmemb, size_t size);

/**	@brief	Copies n bytes from memory area src to memory area dest.
 *	@param	dest	Destination pointer of memory area
 *	@param	src		Source pointer of memory area
 *	@param	n		Buffer size in bytes */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**	@brief	fills the first n bytes of the memory
 * 			area pointed to by s with the constant byte c.
 *	@param	s Pointer of memory area
 *	@param	c Constant byte to fill memory area
 *	@param	n Number of bytes to fill
 * 	@return	void* Returns a pointer to the memory area s */
void	*ft_memset(void *s, int c, size_t n);

/**	@brief	Allocates (with malloc(3)) and returns an array of strings
 * 			obtained by splitting ’s’ using the character ’c’ as a delimiter.
 *			The array must be ended by a NULL pointer.
 *	@param	s The string to be split
 *	@param	c The delimiter character
 *	@return char** Returns a matrix of two splitted arrays,
 *			else returns NULL if allocation fails. */
char	**ft_split(char const *s, char c);

/**	@brief	Returns a pointer to a new string
 * 			which is a duplicate of the string s.
 *	@param	s1 Pointer to the start of the string do be copied
 *	@return	char* On success, returns a pointer to the
 * 			duplicated string. It returns NULL if insufficient memory was
 * 			available, with errno set to indicate the cause of the error.*/
char	*ft_strdup(const char *s1);

/**	@brief	Allocates (with malloc(3)) and returns a newstring,
 *			which is the result of the concatenationof ’s1’ and ’s2’.
 *	@param	s1 The prefix string
 *	@param	s2 The suffix string
 *	@return char* Returns the new string or NULL if the allocation fails. */
char	*ft_strjoin(char const *s1, char const *s2);

/**	@brief	Copies up to size - 1 characters from
 * 			the NUL-terminated string src to dest, NUL-terminating the result.
 * @param	dest	Pointer to the destination area of memory
 * @param	src		Pointer to the source area of memory
 * @param	size	Buffer size in bytes
 * @return	size_t Returns the length of src. */
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);

/**	@brief	calculates the length of the string pointed to by s,
 * 			excluding the terminating null byte ('\0').
 *	@param 	s Pointer to the initial area of the string
 *	@return	size_t Returns the number of bytes in the string pointed to by s.*/
size_t	ft_strlen(const char *s);

/**	@brief	Allocates (with malloc(3)) and returns a substring from
 * 			the string ’s’. The substring begins at index ’start’
 * 			and is of maximum size ’len’.
 *	@param	s		The string from which to create the substring.
 *	@param	start	The start index of the substring in the string’s’.
 *	@param	len		The maximum length of the substring.
 *	@return char* Returns the substring. NULL if the allocation fails. */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
