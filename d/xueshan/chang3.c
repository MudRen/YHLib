inherit ROOM;

void create()
{
        set("short", "�䳡");
        set("long", @LONG
�����Ǵ����µ�С���䳡�����źö�ľ׮��ɳ����ɮ����
�ճ����ڴ˿̿�ϰ�䡣�����߾��Ǵ����䳡�����ѩɽ������
����������
LONG);
        set("outdoors", "xueshan");

        set("exits", ([
                "north" : __DIR__"houyuan",
                "south" : __DIR__"chang",
        ]));

        setup();
        replace_program(ROOM);
}
