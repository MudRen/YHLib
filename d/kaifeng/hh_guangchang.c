inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
������Ǻ컨���ܶ�������ǰ��һ���㳡���㳡����ǰ
����һ����ľ�����ȣ�ͨ���������ڡ��������߷ֱ�ͨ������
���ͳ����������컨��Ļ��ڴ������С�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"hh_zoulang1",
  		"south" : __DIR__"hh_lianwu1",
  		"west" : __DIR__"hh_bingqi",
  		"east" : __DIR__"hh_chufang",
	]));
        set("objects", ([
                __DIR__"npc/honghua1" : 2,
        ]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
