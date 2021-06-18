#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int		main(void)
{
	uid_t			id;		// unistd.h
	struct	passwd	*pw;	// pwd.h
	char			*name;	// unistd.h
	   
	id = getuid();
	pw = getpwuid(id);

	name = getlogin();
	pw = getpwnam(name);

	printf("===========================\n");
	printf("사용자id : %d\n", id);
	printf("--------------------------\n");
	printf("사용자명 : %s\n", pw->pw_name);
	printf("사용자 id : %d\n", pw->pw_uid);
	printf("그룹 id : %d\n", pw->pw_gid);
	printf("홈 디렉토리 : %s\n", pw->pw_dir);
	printf("===========================\n");
	printf("사용자명 :%s\n", name);
	printf("---------------------------\n");
	printf("사용자명 : %s\n", pw->pw_name);
	printf("사용자 id : %d\n", pw->pw_uid);
	printf("그룹 id : %d\n", pw->pw_gid);
	printf("홈 디렉토리 : %s\n", pw->pw_dir);
	printf("===========================\n");
	return (0);
}
