/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchadwic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:10:32 by cchadwic          #+#    #+#             */
/*   Updated: 2020/01/28 22:11:27 by cchadwic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H_
# define _FT_LS_H_

# define ERROR error(ls)

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <time.h>

# include <../libft/includes/libft.h>

# define BUFF_SIZE 1024

/*
struct stat {
    dev_t     st_dev;          ID устройства с файлом 
    ino_t     st_ino;          номер inode 
    mode_t    st_mode;         права доступа 
    nlink_t   st_nlink;        кол-во жёстких ссылок 
    uid_t     st_uid;          ID пользователя-владельца 
    gid_t     st_gid;          ID группы-владельца 
    dev_t     st_rdev;         ID устройства (если это спец. файл) 
    off_t     st_size;         полный размер в байтах 
    blksize_t st_blksize;      размер блока ввода-вывода файловой системы 
    blkcnt_t  st_blocks;       кол-во выделенных блоков по 512Б 
     Начиная с Linux 2.6, ядро поддерживает точность до
       наносекунд в следующих полям меток времени.
       Подробней о версиях до Linux 2.6, смотрите ЗАМЕЧАНИЯ. 
    struct timespec st_atim;   время последнего доступа 
    struct timespec st_mtim;   время последнего изменения 
    struct timespec st_ctim;   время последней смены состояния 
#define st_atime st_atim.tv_sec       для обратной совместимости 
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
};
*/


/*
*struct passwd {
*    char   *pw_name;        имя пользователя 
*    char   *pw_passwd;      пароль пользователя 
*    uid_t   pw_uid;         идентификатор пользователя 
*    gid_t   pw_gid;         идентификатор группы 
*    char   *pw_gecos;       информация о пользователе 
*    char   *pw_dir;         домашний каталог 
*    char   *pw_shell;       программная оболочка 
*};
*/


// Структура АНИ!
typedef	struct	s_files
{
	char			*filename; // Здесь название файла или название директории. Используй malloc
	size_t			len; // Длина названия файла или директории, ft_strlen(filename).
	struct s_files	*next; // Здесь указываешь название следующего файла или директории или NULL.
	struct s_files	*deeper; // Если это директория, то нужно уйти вглубь. Если нет, то NULL.
}				t_files;


// Структура АРТЕМА!
typedef struct	s_ls
{
	// 0 or 1
	int             flags;
	int             a;
	int             l;
	int             R;
	int             r;
	int             t;

	char            buffer[BUFF_SIZE];
	int             i;
	unsigned int    total;

	char            **av;
	char            ac;

	struct stat		stats;

	t_files			files;
}				t_ls;


int             main(int ac, char **av);
void            check_flags(t_ls *ls);
t_ls            *init_ls(int ac, char **av);
void            show_dir(t_ls *ls);

void            error(t_ls *ls);

void            put_mode(t_ls *ls);
void			put_link(t_ls *ls);
void			put_size(t_ls *ls);




#endif
