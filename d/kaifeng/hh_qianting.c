inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
�����Ǻ컨���ܶ��ڵ�ǰ���������൱�Ŀ�����������
��ǽ���������˸������˵��漣������վ�ż����컨��Ļ���
������������ǰ����һ���컨���������ࡣ������������
���ȣ�����ͨ���������ڡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"hh_zoulang2",
  		"east" : __DIR__"hh_zoulang3",
  		"north" : __DIR__"hh_zhengting",
  		"south" : __DIR__"hh_zoulang1",
	]));
        set("objects", ([
                __DIR__"npc/honghua1" : 4,
        ]));
        setup();
        replace_program(ROOM);
}
