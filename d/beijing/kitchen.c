// Room: /d/zhenyuan/kitchen.c
// created by agah 
 
inherit ROOM; 
 
void create ()
{
  	set ("short", "����");
  	set ("long", @LONG
�������ɨ�ĺܸɾ������ڴ����ð���������������˴������Ρ�����Ѿ
��������ʰ�߲ˡ�һ��С�ܼ������ػص��ܣ�����ڴ����֡�
LONG);

  	set("exits", ([
  		"west" : __DIR__"kitchen_road2",
	]));

	setup(); 
	replace_program(ROOM); 
} 
