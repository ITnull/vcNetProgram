#include <stdio.h>
#include <windows.h>
main()
{
  int i=0;
  char ch;
  bool a=true;
	printf("ȷ�ϴ��ʼ��շ�����!(Y/N)\n");
scanf("%c",&ch);
if(ch=='Y'||ch=='y')
{
	printf("�ʼ��շ��������ڴ򿪣����Ժ򡭡�\n");
  while(i<=10)
{
	i+=1;
}
	::ShellExecute(NULL,NULL,"mailto:lymlrl@163.com",NULL,NULL,SW_SHOW);
printf("�ʼ��շ������Ѿ��򿪣���ʹ�ã�\n");
}
else
{printf("ллʹ��!\n");
}
return true;
}
