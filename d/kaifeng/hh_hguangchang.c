inherit ROOM;

void create()
{
        set("short", "��㳡");
        set("long", @LONG
������Ǻ컨���ܶ��������һ���㳡���㳡�����ϱ�
��һ����ľ�����ȣ�ͨ���������ڡ��������߷ֱ�ͨ���˷���
���ã������컨��Ļ��ڴ������С�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"hh_huayuan",
  		"south" : __DIR__"hh_zoulang8",
  		"east" : __DIR__"hh_xingtang",
  		"west" : __DIR__"hh_zhangfang",
	]));
        set("objects", ([
                __DIR__"npc/honghua1" : 2,
        ]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
