#include <stdio.h>
#include <windows.h>
main()
{
  int i=0;
  char ch;
  bool a=true;
	printf("确认打开邮件收发程序!(Y/N)\n");
scanf("%c",&ch);
if(ch=='Y'||ch=='y')
{
	printf("邮件收发程序正在打开！请稍候……\n");
  while(i<=10)
{
	i+=1;
}
	::ShellExecute(NULL,NULL,"mailto:lymlrl@163.com",NULL,NULL,SW_SHOW);
printf("邮件收发程序已经打开，请使用！\n");
}
else
{printf("谢谢使用!\n");
}
return true;
}
