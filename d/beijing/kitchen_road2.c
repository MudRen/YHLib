inherit ROOM; 
 
void create ()
{
  set ("short", "С·");
  set ("long", @LONG
һ������������С·��·���̲ݼ�ϡϡ��������˼����¼�������ֻС��
СѼ����������ʳ���������Ǻ�ԺС��԰����ʱ�����������ﻨ�㡣
LONG);

  	set("exits", ([
  		"east" : __DIR__"kitchen",
  		"west" : __DIR__"kitchen_road1",
	]));

  	set("objects", ([
        	__DIR__"npc/hanwenchong": 1,
        ]));

	setup(); 
	replace_program(ROOM); 
} 
