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
  		"east" : __DIR__"hh_lianwu1",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/chang1" : 1,
                __DIR__"npc/honghua2" : 2,
        ]));
        set("outdoors", "honghua");
        setup();
        replace_program(ROOM);
}
