inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����ĳ�����������ϸϸ�Ļ����������ʺ����䡣������
�����컨��ĵ����������䡣���䳡���������ż���ľ׮��ľ
׮��Χ���������ɸ���ɳ�ӡ�����ͨ���ܶ�Ĵ������ڣ��䱸
����ɭ�ϡ����䳡�ı�����ɴ���������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"hh_guangchang",
  		"south" : __DIR__"hh_damen",
  		"west" : __DIR__"hh_lianwu2",
  		"east" : __DIR__"hh_lianwu3",
	]));
        set("objects", ([
                __DIR__"npc/honghua1" : 1,
                __DIR__"npc/honghua2" : 1,
        ]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
