inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����۷������������ư��硣ʼ����Ԫ̫�����꣬ԭ��Ϊ
�����ۣ�Ϊ���������ȫ��̴�ʼ�������ڴ˴��̲������ڴ�
���޽������������꣬��������ۡ�  
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"sanqing",
  		"east" : __DIR__"wroad2",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
