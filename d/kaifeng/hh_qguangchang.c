inherit ROOM;

void create()
{
        set("short", "ǰ�㳡");
        set("long", @LONG
������Ǻ컨����ܶ��ˣ�ֻ���㳡ǰ���ż�չ���죬��
ӭ������š�ǰ����һ����ǽ���ߵĴ�լ���ſڷ�����ͷʯʨ
�ӣ���������׳�ۡ��㳡վ�ż����컨��Ļ��ڣ�����������
��ǰ����һ���컨���������ࡣ
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"hh_damen",
  		"west" : __DIR__"eroad3",
	]));
        set("objects", ([
                __DIR__"npc/honghua1" : 2,
        ]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
