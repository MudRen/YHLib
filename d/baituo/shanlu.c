inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ǰ���ɽׯ�㳡���ߵ�һ��С·��Ѱ������ƽʱ����
��������С·��ɽ��
LONG);
        set("exits", ([
                "north" : __DIR__"shanlu1",
                "east"  : __DIR__"guangchang",
        ]));
        set("outdoors", "baituo");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
