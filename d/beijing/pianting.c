inherit ROOM; 
 
void create ()
{
  	set ("short", "ƫ��");
  	set ("long", @LONG
ƫ�����õ���Ϊ���ţ�˿��û�������ϵ��������ա�һ�ź�ľ����������
����񣬹�����˸�ʽ�������顣ǽ�Ϲ��ż����ֻ�������������ʱ��������
���Ե��鷿�á�
LONG);

  	set("exits", ([
  		"north" : __DIR__"w_garden",
  		"east" : __DIR__"zhengting",
	]));

	setup(); 
	replace_program(ROOM); 
} 
