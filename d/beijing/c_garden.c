// Room: /d/zhenyuan/c_garden.c
// created by agah 
 
inherit ROOM; 
 
void create ()
{
  	set ("short", "��԰");
  	set ("long", @LONG
������һ��С��԰����Ȼ�Ȳ��ϸ�����Ժ�������ǧ�죬��ȴҲ���õþ�
�¿��ˡ���Զ�ھ�����Ȼ��������֮ʿ���������һ�ʢ�������ճ�����ɻ���
�������ջ����ޣ���������һƬ��ѩ����
LONG);

  	set("exits", ([
  		"east" : __DIR__"e_garden",
  		"west" : __DIR__"w_garden",
  		"south" : __DIR__"zhengting",
  		"north" : __DIR__"stone_road",
	]));

	setup(); 
	replace_program(ROOM); 
} 
