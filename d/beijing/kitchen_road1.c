inherit ROOM; 
 
void create ()
{
  set ("short", "С·");
  set ("long", @LONG
һ������������С·��·���̲ݼ�ϡϡ��������˼����¼�������ֻС��
СѼ����������ʳ���������Ǻ�ԺС��԰����ʱ�����������ﻨ�㡣
LONG);

  	set("exits", ([
  		"east" : __DIR__"kitchen_road2",
  		"west" : __DIR__"dining_room",
  		"northwest" : __DIR__"e_garden",
	]));

	setup(); 
	replace_program(ROOM); 
} 
